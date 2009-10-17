/*
* ==============================================================================
*  Name        : game.cpp
*  Part of     : MHSVLC
*  Interface   : 
*  Description : Contains the implementation of the CGame class.
*  Version     : 
*
*  Copyright (c) 2007 Nokia Corporation.
*  This material, including documentation and any related 
*  computer programs, is protected by copyright controlled by 
*  Nokia Corporation.
* ==============================================================================
*/
#include "game.h"
#include <e32base.h>
#include <gles/gl.h> // for opengl es functions.
#include <unistd.h>  // for usleep.

// -----------------------------------------------------------------------------
// CGame::NewLC
// The factory function.
// -----------------------------------------------------------------------------
//
CGame* CGame::NewLC()
{
    CGame* self = new (ELeave) CGame;
    
    CleanupStack::PushL( self );
    
    self->ConstructL();

    return self;    
}

// -----------------------------------------------------------------------------
// CGame::CGame
// Constructor.
// -----------------------------------------------------------------------------
//
CGame::CGame()
      :iScreenWidth( 0 ),
       iScreenHeight( 0 ),
       iGameOver( EFalse ),
       iZPos( -100 ),
       iIsUpPressed( EFalse ),
       iIsDownPressed( EFalse ),
       iFrame( 0 )
{

}

// -----------------------------------------------------------------------------
// CGame::~CGame
// Destructor.
// -----------------------------------------------------------------------------
//
CGame::~CGame()
{
    Cleanup();
}

// -----------------------------------------------------------------------------
// CGame::Cleanup
// Perform any cleanup here.
// (does nothing)
// -----------------------------------------------------------------------------
//
void CGame::Cleanup()
{

}

// -----------------------------------------------------------------------------
// CGame::ConstructL
// Second phase contructor.
// (Does nothing)
// -----------------------------------------------------------------------------
//
void CGame::ConstructL()
{

}

// -----------------------------------------------------------------------------
// CGame::Initialize
// Initializes the opengl es state, based on the screen height and width.
// -----------------------------------------------------------------------------
//
void CGame::Initialize( TUint aScreenWidth, TUint aScreenHeight )
{
    iScreenWidth = aScreenWidth;
    iScreenHeight = aScreenHeight;
    ////////////code by pk
    iTextureManager = CTextureManager::NewL ( iScreenWidth, iScreenHeight,
                                                  FRUSTUM_TOP, FRUSTUM_BOTTOM, FRUSTUM_RIGHT, FRUSTUM_LEFT, FRUSTUM_NEAR,
                                                  this );
    //////
    _LIT(Kicecubetex, "icubetexor.jpg");
    iTextureManager->RequestToLoad(Kicecubetex, &icubetex );
    
    iTextureManager->DoLoadL();
    glClearColor( 0.f, 0.f, 2.f, 1.f );
    glEnable( GL_CULL_FACE  );
    glEnable( GL_TEXTURE_2D );
    //glEnable( GL_NORMALIZE  );
    glMatrixMode( GL_TEXTURE );
    //////////////////neutralizes any current matrix as many opengl implementations multiply current matrix automatically
    glLoadIdentity();
    glScalef(     1.0f/255.0f, 1.0f/255.0f, 1.0f );///////////////////scaling texture
    glTranslatef( 128.0f,      128.0f,      0.0f );
    //////////now all operations will be on model and view
    glMatrixMode( GL_MODELVIEW );
    ////////////////enable telling vertices using an array
    glEnableClientState( GL_VERTEX_ARRAY        );
    ////////////////enable telling textures using an array
    glEnableClientState( GL_TEXTURE_COORD_ARRAY );
    //glEnableClientState( GL_NORMAL_ARRAY        );
    glVertexPointer(   3, GL_BYTE, 0, vertices     );
 
    glTexCoordPointer( 2, GL_BYTE, 0, nokTexCoords );
    //glNormalPointer(   GL_BYTE, 0, normals         );
    glShadeModel( GL_FLAT );
    glBlendFunc( GL_ONE, GL_ONE );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST );

    //glViewport( 0, 0, iScreenWidth, iScreenHeight );
    glMatrixMode( GL_PROJECTION );
    //glLoadIdentity();
    
    // Calculate the view frustrum
    GLfloat aspectRatio = (GLfloat)(iScreenWidth) / (GLfloat)(iScreenHeight);
   
   // glFrustumf( FRUSTUM_LEFT * aspectRatio, FRUSTUM_RIGHT * aspectRatio,
   //             FRUSTUM_BOTTOM, FRUSTUM_TOP,
   //             FRUSTUM_NEAR, FRUSTUM_FAR );

    if (iScreenWidth <= iScreenHeight)
    glOrthof (-1.5f, 1.5f, -1.5f*(GLfloat)iScreenHeight/(GLfloat)iScreenWidth,
    1.5f*(GLfloat)iScreenHeight/(GLfloat)iScreenWidth, 3.f, 1000.f);
    else
    glOrthof (-1.5f*(GLfloat)iScreenWidth/(GLfloat)iScreenHeight,
    1.5f*(GLfloat)iScreenWidth/(GLfloat)iScreenHeight, -1.5f, 1.5f, 3.f, 1000.f);
    
    
    glMatrixMode( GL_MODELVIEW );
    
    
 

}
// -----------------------------------------------------------------------------
// CGame::SetScreenSize
// Initialize the opengl viewport based on the screen width and height.
// This is called by the Game Controller when the screen size changes.
// -----------------------------------------------------------------------------
//
void CGame::SetScreenSize( TUint aScreenWidth, TUint aScreenHeight )
{    
    iScreenWidth = aScreenWidth;
    iScreenHeight = aScreenHeight;
    
    // Initialize the viewport and projection. 
    glViewport( 0, 0, iScreenWidth, iScreenHeight );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    // Calculate the view frustrum
    GLfloat aspectRatio = (GLfloat)(iScreenWidth) / (GLfloat)(iScreenHeight);
   // glFrustumf( FRUSTUM_LEFT * aspectRatio, FRUSTUM_RIGHT * aspectRatio,
    //            FRUSTUM_BOTTOM, FRUSTUM_TOP,
    //            FRUSTUM_NEAR, FRUSTUM_FAR );

    if (iScreenWidth <= iScreenHeight)
    glOrthof (-1.5f, 1.5f, -1.5f*(GLfloat)iScreenHeight/(GLfloat)iScreenWidth,
    1.5f*(GLfloat)iScreenHeight/(GLfloat)iScreenWidth, 3.f, 1000.f);
    else
    glOrthof (-1.5f*(GLfloat)iScreenWidth/(GLfloat)iScreenHeight,
    1.5f*(GLfloat)iScreenWidth/(GLfloat)iScreenHeight, -1.5f, 1.5f, 3.f, 1000.f);
    
    glMatrixMode( GL_MODELVIEW );    
}

// -----------------------------------------------------------------------------
// CGame::RenderFrame
// Renders a game frame using opengl es apis.
// It returns EFalse, if the game has ended.
// -----------------------------------------------------------------------------
//
TBool CGame::RenderFrame( TInt64 aMicrosSinceLastVisit )
{      
    if( iGameOver ) // If the game has ended, return EFalse to exit.
        return EFalse;

    // Ensure that the desired fps is maintained by sleeping 
    // for the rest of the time.   
    if( aMicrosSinceLastVisit < timeForOneFrame )
    {
        usleep( timeForOneFrame - aMicrosSinceLastVisit );    
    }
    
    // Clear the buffer.
    glClear( GL_COLOR_BUFFER_BIT );
        
    glLoadIdentity();////////////resetting modelview matrix

    ////////////////////////////////////////moving drawings to be made here
    // Move the Cube.
    glTranslatex( 0 , 0 , iZPos << 16 );
    
    // Rotate the cube.
    
  


    /* Scale the cube coordinates to fit the screen. */
    glScalef( 50.0f/iZPos, 50.0f/iZPos, 50.0f/iZPos );

/////////////////////////one type of orientation
    if(iScreenWidth<iScreenHeight)
    	{
    ///////////////////bind vlc images to texture
////static drawings
    glBindTexture(  GL_TEXTURE_2D, icubetex.iID );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glDrawElements( GL_TRIANGLES, 2 * 3, GL_UNSIGNED_BYTE, backg_up_square1 );
    glDrawElements( GL_TRIANGLES, 2 * 3, GL_UNSIGNED_BYTE, backg_up_square2 );
/////moving drawings
    glRotatex( iFrame << 16, 1 << 16,    0   ,    0    );
    glRotatex( iFrame << 15,    0   , 1 << 16,    0    );
    glRotatex( iFrame << 14,    0   ,    0   , 1 << 16 );

    glDrawElements( GL_TRIANGLES, 12 * 3, GL_UNSIGNED_BYTE, triangles );
    	}
    else
    	{
    	/////////////////in other orientation
        glBindTexture(  GL_TEXTURE_2D, icubetex.iID );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
        glDrawElements( GL_TRIANGLES, 2 * 3, GL_UNSIGNED_BYTE, backg_dwn_square1 );
        glDrawElements( GL_TRIANGLES, 2 * 3, GL_UNSIGNED_BYTE, backg_dwn_square2 );
    /////moving drawings
        glRotatex( iFrame << 16, 1 << 16,    0   ,    0    );
        glRotatex( iFrame << 15,    0   , 1 << 16,    0    );
        glRotatex( iFrame << 14,    0   ,    0   , 1 << 16 );

        glDrawElements( GL_TRIANGLES, 12 * 3, GL_UNSIGNED_BYTE, triangles );
    	}
    
    
    
   iFrame+=2;////////////// ++iFrame;/////hack by pk
    
    // Move the cube if the up/down keys are pressed, but not released.
    // If the up/down keys are not released, then continuously move
    // cube.
    if( iIsUpPressed )
        --iZPos;
    
    if( iIsDownPressed )
        ++iZPos;
    
    return ETrue;
}

// -----------------------------------------------------------------------------
// CGame::HandleKeyEvent
// Handle a Key Event. This called by the Game Controller, when a key up/down
// event occurs.
// -----------------------------------------------------------------------------
//
void CGame::HandleKeyEvent( TUint32 aKey, TBool aIsKeyUp )
{
   // Handle key events
   if( EFalse == aIsKeyUp )
   {
        switch( aKey )
        {
            case( EStdKeyUpArrow ):
            {
                // Move the cube farther from the screen.
                --iZPos;
                iIsUpPressed = ETrue;
                break;
            }
            case( EStdKeyDownArrow ): 
            {
                // Move the cube closer.
                ++iZPos;
                iIsDownPressed = ETrue;
                break;
            }
            case( EStdKeyDevice1 ): 
            {
                // Exit on Right Soft Key press.
                iGameOver = ETrue;
                break;
            }
            default:                
                break;
        }
   }
   else
   {
        // On a key release, reset the flags.
        switch( aKey )
        {
            case( EStdKeyUpArrow ):
            {                
                iIsUpPressed = EFalse;
                break;
            }
            case( EStdKeyDownArrow ):
            {
                iIsDownPressed = EFalse;
                break;
            }
            default:
                break;
        }       
   }
}


// eof

void CGame::OnStartLoadingTexturesL()
	{
    SetStateL( ELoadingTextures );
	}

// ------------------------------------------------------------------------------------------------------------
// CBillboard::OnEndLoadingTextures()
// Called for a MTextureLoadingListener by the texture manager when texture loading operation is completed
// ------------------------------------------------------------------------------------------------------------
void CGame::OnEndLoadingTexturesL()
	{
	if ( GetState() == ELoadingTextures )
		{
		SetStateL( ERunning );
		}
	}

// ---------------------------------------------------------
// CBillboard::OnEnterState( TInt aState )
// Called by TFiniteStateMachine when the f.s.m enters a new state
// ---------------------------------------------------------

void CGame::OnEnterStateL( TInt /*aState*/ )
	{
	    // Nothing to do here...
	}
