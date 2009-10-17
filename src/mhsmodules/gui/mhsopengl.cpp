#define MODULE_NAME mhsopengl
#define MODULE_PATH mhsopengl
#define MODULE_STRING "mhsopengl"
#define __BUILTIN__

extern "C"
	{
# include "config.h"

#include <vlc_common.h>
#include <vlc_plugin.h>
	}

static int  Open         ( vlc_object_t * );
static void Close        ( vlc_object_t * );
static void Run          ( intf_thread_t * );


#ifndef GUI
vlc_module_begin();
    set_shortname( "Qt" );
    set_description( N_("Qt interface") );
    set_category( CAT_INTERFACE ) ;
    set_subcategory( SUBCAT_INTERFACE_MAIN );

 set_capability( "interface", 10 );

   
    set_callbacks( Open, Close );

    add_shortcut("qt");

    
vlc_module_end();
#else
vlc_module_begin();
    set_shortname( "Qt" );
    set_description( N_("Qt interface") );
    set_category( CAT_INTERFACE ) ;
    set_subcategory( SUBCAT_INTERFACE_MAIN );

 set_capability( "interface", 30 );

   
    set_callbacks( Open, Close );

    add_shortcut("qt");

    
vlc_module_end();
#endif

/*****************************************************************************
 * Module callbacks
 *****************************************************************************/


static void Close( vlc_object_t *p_this )
{
  
}


static void Run( intf_thread_t *p_intf )
{

}







/*
* ==============================================================================
*  Name        : MHSVLC.cpp
*  Part of     : MHSVLC
*  Interface   : 
*  Description : The main entry point to the application is implemented here.
*  Version     : 
*
*  Copyright (c) 2007 Nokia Corporation.
*  This material, including documentation and any related 
*  computer programs, is protected by copyright controlled by 
*  Nokia Corporation.
* ==============================================================================
*/

#include <stdio.h> // for printf

#include <e32base.h> // for Symbian classes.
#include <coemain.h> // for CCoeEnv.
#include "game.h"    // for the CGame class
#include "gamecontroller.h" // for the CGameController class.

// Error codes
const TInt KErrDisplayNotCreated = -5001;
const TInt KErrDisplayNotInitialized = -5002;

// Function prototypes

// Creates the Game, Game Controller and starts the Game loop.
void StartGameL( EGLDisplay aEglDisplay );



// -----------------------------------------------------------------------------
// main()
// 
// The main entry point to the application.
// -----------------------------------------------------------------------------
//
static int Open(vlc_object_t *p_this )
{
    __UHEAP_MARK; 
       
    TInt result = KErrNone;

    // Create the control environment.cone created
    //{{{{//
    CCoeEnv* environment = new (ELeave) CCoeEnv();    
    
    TRAPD( err, environment->ConstructL( ETrue, 0 ) );
    ///}}}}//
    if( err != KErrNone )
    {
        printf( "Unable to create a CCoeEnv!\n" );
        getchar();
            
        result = KErrCoeEnvNotInitialized;        
    }
    else
    {        
        // Get the default display for rendering on to.
        EGLDisplay eglDisplay = eglGetDisplay( EGL_DEFAULT_DISPLAY );
        if( eglDisplay != NULL )
        {            
           // Initialize EGL.
            if( eglInitialize( eglDisplay, NULL, NULL ) == EGL_FALSE )
            {            
                printf( "EGL Initialize failed!\n" );
                getchar();
                
                result = KErrDisplayNotInitialized;
            }    
            else
            {            
                // Start the Game.
                // This has to be called inside a TRAPD, as eglInitialize
                // internally creates a Trap Handler. 
                TRAPD( result, StartGameL( eglDisplay ) );        
            
                if( KErrNone != result )
                {
                    printf( "StartGameL failed with result = %d!\n", result );
                    getchar();
                }
                         
                // EGL related cleanup.
                eglTerminate( eglDisplay );       
            }
        }
        else
        {
            printf( "EGL Get Display failed!\n" );
            getchar();
            
            result = KErrDisplayNotCreated;        
        }        
    }
    
    // Close the stdout & stdin, else printf / getchar causes a memory leak.
    fclose( stdout );
    fclose( stdin );
    
    // Cleanup
    CCoeEnv::Static()->DestroyEnvironment();
    delete CCoeEnv::Static();
       
    __UHEAP_MARKEND;
       
    var_Create( p_this, "window_widget", VLC_VAR_ADDRESS );
    return VLC_SUCCESS;
}

// -----------------------------------------------------------------------------
// StartGameL
// 
// Initializes the Game, the GameController and starts off the game loop.
// This will return only if either the Game Exits or if an error occurs.
// -----------------------------------------------------------------------------
//
void StartGameL( EGLDisplay aEglDisplay )
{   
    // The CCoeEnv creates certain Active Objects that are not needed
    // for the current application.
    
    // So delete the current Active Scheduler and create your own.
    delete CActiveScheduler::Current();            
    CActiveScheduler* actScheduler = new (ELeave) CActiveScheduler();    
    CActiveScheduler::Install( actScheduler );
    CleanupStack::PushL( actScheduler );

    // Create the Game Controller.
    // The Game controller creates the window & initializes the egl context.
    CGameController* gameController = CGameController::NewLC( aEglDisplay );
    
    // Create the Game.
    // The game will take care of rendering using opengl es calls.
    CGame* game = CGame::NewLC();

    // Start the game loop.
    gameController->StartGameL( *game );    
    
    // The game has completed so destroy
    // the game controller, the game and the actScheduler.
    CleanupStack::PopAndDestroy( 3 );
}

// eof
