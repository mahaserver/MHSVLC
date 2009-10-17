///////backg_up_square1 is the upper rectangular area in orientation1
///////backg_up_square2 is the lower rectangular area in orientation 1
///////0-23 vertices are of rotating cube
///////25-29 vertices are of backgupsquare1
///////30-35 vertices are of backgupsquare2
///////backg_dwn_square1 is the upper rectangular area in orientation 2
///////backg_dwn_square2 is the lower rectangular area in orientation 2



#ifndef __GAME_CLASS__
#define __GAME_CLASS__

#include <e32base.h> // for CBase
#include <gles/gl.h> // for opengl es types 
#include <e32keys.h> // for TStdScanCode
#include <e32base.h> // for CBase definition
#include <GLES/gl.h> // OpenGL ES header file
#include "../eglutils/Utils3d.h" // Utilities (texmanager, textures etc.)
#include "../eglutils/Glutils.h" // Misc GLU and GLUT functions

// MACROS
#define TEX_WIDTH     256 // Texture size must be power of two and max size
#define TEX_HEIGHT    256 // for textures is 256 x 256

#define FRUSTUM_LEFT    -1.f  //left vertical clipping plane
#define FRUSTUM_RIGHT    1.f  //right vertical clipping plane
#define FRUSTUM_BOTTOM  -1.f  //bottom horizontal clipping plane
#define FRUSTUM_TOP      1.f  //top horizontal clipping plane
#define FRUSTUM_NEAR     3.f  //near depth clipping plane
#define FRUSTUM_FAR   1000.f  //far depth clipping plane
// CONSTANTS

// The number of microseconds that can be spent on one frame.
// 10000000 microseconds = 1 second
// Frame rate = 25 fps.
const TInt timeForOneFrame = 1000000 / 25;




static const GLbyte vertices[48 * 3] =
{
    /* top */
    -1,  1,  1,
    1,  1,  1,
    1, -1,  1,
    -1, -1,  1,

    /* front */
    1,  1,  1,
    1,  1, -1,
    1, -1, -1,
    1, -1,  1,

    /* right */
    -1,  1,  1,
    -1,  1, -1,
    1,  1, -1,
    1,  1,  1,

    /* left */
    1, -1,  1,
    1, -1, -1,
    -1, -1, -1,
    -1, -1,  1,

    /* back */
    -1, -1,  1,
    -1, -1, -1,
    -1,  1, -1,
    -1,  1,  1,

    /* bottom */
    -1,  1, -1,
    1,  1, -1,
    1, -1, -1,
    -1, -1, -1,
   
    
    
   
    //////////////background up  square1

	3,-4, -1.2,
	3,-2, -1.2,
	-3,-4, -1.2,
	
	-3,-4, -1.2,
	3,-2, -1.2,
	-3,-2, -1.2,
	
    //////////////background up  square2
	3,4, -1.2,
	-3,4, -1.2,
	-3,2, -1.2,
	
	3,2, -1.2,
	3,4, -1.2,
	-3,2, -1.2,
	////////////backg_dwn_square1
	4,-3, -1.2,
	4,-2, -1.2,
	-4,-3, -1.2,
	
	-4,-3, -1.2,
	4,-2, -1.2,
	-4,-2, -1.2,
	///////////backg_dwn_square2
	4,3, -1.2,
	-4,3, -1.2,
	-4,2, -1.2,
	
	4,2, -1.2,
	4,3, -1.2,
	-4,2, -1.2,

};


/*
// Vertice coordinates for the cube. 
static const GLbyte vertices[8 * 3] =
     {
     -1,  1,  1,
      1,  1,  1,
      1, -1,  1,
     -1, -1,  1,

     -1,  1, -1,
      1,  1, -1,
      1, -1, -1,
     -1, -1, -1
     };

// Colors for vertices (Red, Green, Blue, Alpha). 

static const GLubyte colors[8 * 4] =
    {
    0  ,255,  0,255,
    0  ,  0,255,255,
    0  ,255,  0,255,
    255,  0,  0,255,

    0  ,  0,255,255,
    255,  0,  0,255,
    0  ,  0,255,255,
    0  ,255,  0,255
    };
*/
static const GLubyte colors[8 * 4] =
    {
    255  ,0,0,255,
    0  ,255,0,255,
    0  ,0,255,255,
    255	 ,0,0,255,

    0  ,255,0,255,
    0  ,0,255  ,255,
    255  ,0,0  ,255,
    0  ,255,0  ,255
    };


static const GLubyte backg_up_square1[2*3]=
{
		24,25,26,27,28,29
		
	};
static const GLubyte backg_up_square2[2*3]=
{
		30,31,32,33,34,35
	};
static const GLubyte backg_dwn_square1[2*3]=
{
		36,37,38,39,40,41
		
	};
static const GLubyte backg_dwn_square2[2*3]=
{
		42,43,44,45,46,47
	};



// Indices for drawing the triangles.
static const GLubyte triangles[12 * 3] =
{
    /* top */
     1,0,3,
     1,3,2,

     /* front */
     5,4,7,
     5,7,6,

     /* right */
     9,8,11,
     9,11,10,

     /* left */
     13,12,15,
     13,15,14,

     /* back */
     17,16,19,
     17,19,18,
     /*bottom*/
     21,22,23,
     21,23,20
};
    
#define tex(u,v) (GLbyte)( (u) - 128 ) , (GLbyte)( (v) - 128 )
static const GLbyte nokTexCoords[52 * 2] =
{
    /* top, whole texture nasa_hubble.h */
    tex(0,0),
    tex(255,0),
    tex(255,255),
    tex(0,255),

    /* front, spiral with tail */
    tex(0,0),
    tex(255,0),
    tex(255,255),
    tex(0,255),

    /* right, red nebulae */
    tex(0,0),
    tex(255,0),
    tex(255,255),
    tex(0,255),

    /* left, plasma cloud */
    tex(0,0),
    tex(255,0),
    tex(255,255),
    tex(0,255),

    /* back, 2 spirals */
    tex(0,0),
    tex(255,0),
    tex(255,255),
    tex(0,255),

    /* bottom, whole texture ogles.jpg */
    tex(0,0),
    tex(255,0),
    tex(255,255),
    tex(0,255),
    ////////////////////////////backg_up_square1
    
    tex(255,0),
    tex(255,127),
    tex(0,0),
    
    tex(0,0),
    tex(255,127),
    tex(0,127),
    ////////////////////////////backg_up_square2
    tex(255,255),
    tex(0,255),
    tex(0,127),

    tex(255,127),
    tex(255,255),
    tex(0,127),
    
    ////////////////////////////backg_dwn_square1
    
    tex(255,0),
    tex(255,127),
    tex(0,0),
    
    tex(0,0),
    tex(255,127),
    tex(0,127),
    ////////////////////////////backg_dwn_square2
    tex(255,255),
    tex(0,255),
    tex(0,127),

    tex(255,127),
    tex(255,255),
    tex(0,127),

};
static const GLbyte normals[24 * 3] =
{
    /* top */
    0,0,1,
    0,0,1,
    0,0,1,
    0,0,1,

    /* front */
    1,0,0,
    1,0,0,
    1,0,0,
    1,0,0,

    /* right */
    0,1,0,
    0,1,0,
    0,1,0,
    0,1,0,

    /* left */
    0,-1,0,
    0,-1,0,
    0,-1,0,
    0,-1,0,

    /* back */
    -1,0,0,
    -1,0,0,
    -1,0,0,
    -1,0,0,

    /* bottom */
    0,0,-1,
    0,0,-1,
    0,0,-1,
    0,0,-1
};


// MACROS
// Used for specifying the viewing frustum.
#define FRUSTUM_LEFT   -1.f     //left vertical clipping plane
#define FRUSTUM_RIGHT   1.f     //right vertical clipping plane
#define FRUSTUM_BOTTOM -1.f     //bottom horizontal clipping plane
#define FRUSTUM_TOP     1.f     //top horizontal clipping plane
#define FRUSTUM_NEAR    3.f     //near depth clipping plane
#define FRUSTUM_FAR  1000.f     //far depth clipping plane

// CLASS DECLARATION

/**
 * Class that does the actual OpenGL ES rendering.
 */
class CGame :public CFiniteStateMachine, public MTextureLoadingListener
{
public: // Static Constructor and destructor.
    /**
     * Factory method for creating a new CGame object.
     */
    static CGame* NewLC();

    /**
     * Destructor.
     */    
    ~CGame();
protected: // Constructors
    /**
     * Standard constructor that must never Leave.
     */ 
    CGame();
    
    /**
     * Second phase contructor. 
     */    
    void ConstructL();
public:
    /**
     * Intializes the Game.
     *
     * @param aScreenWidth Width of the screen.
     * @param aScreenHeight Height of the screen.
     */
    void Initialize( TUint aScreenWidth, TUint aScreenHeight );
    
    /**
     * Renders the next frame using opengl es calls.
     *
     * @param aDurationSinceLastVisit The time (in microseconds) since
     *        the function was last visited.
     */    
    TBool RenderFrame( TInt64 aDurationSinceLastVisit );
    
    /**
     * Cleanups any resources.
     */        
    void Cleanup();
    
    /**
     * Handles a Key up / down event.
     *
     * @param aKey The TStdScanCode of the key.
     * @param aIsKeyUp ETrue if the Key is released, else EFalse.
     */    
    void HandleKeyEvent( TUint32 aKey, TBool aIsKeyUp );
    
    /**
     * Handle screen size changes.
     *
     * @param aScreenWidth Width of the screen.
     * @param aScreenHeight Height of the screen.
     */
    void SetScreenSize( TUint aScreenWidth, TUint aScreenHeight );

    /**
     * Get the current frame number.
     *
     */
    TUint GetCurrentFrame() const
    {
        return iFrame;
    }
    
	/**
	 * Called when the finite state machine enters a new state.
	 * Does nothing in this implementation.
	 * @param aState State that is about to be entered.
	 */
	void OnEnterStateL( TInt aState );

	/**
	 * Called when texture manager starts loading the textures.
	 * Sets the current state to "loading textures".
	 */
	void OnStartLoadingTexturesL();

	/**
	 * Called when texture manager has completed texture loading.
	 * Changes the current state to "running".
	 */
	void OnEndLoadingTexturesL();
   
public:
	enum
	    		{
	    		ELoadingTextures,
	    		ERunning
	    		};
    
    
private: // Data
    /** Width of the screen */
    TInt iScreenWidth;    
    
    CTextureManager * iTextureManager;
    TTexture icubetex;
    
    /** Height of the screen */
    TInt iScreenHeight;
    
    /** Flags if the game needs to exit */
    TBool iGameOver;
    
    /** The z co-ordinate of the cube */
    TInt iZPos;
    
    /** Flags if the up key is pressed */
    TBool iIsUpPressed;
    
    /** Flags if the down key is pressed */
    TBool iIsDownPressed;
    
    /** The current frame being rendered */
    TUint iFrame;    
}; // CGame









#endif //__GAME_CLASS__
