/*
* ==============================================================================
*  Name        : gamecontroller.h
*  Part of     : MHSVLC
*  Interface   : 
*  Description : Contains the class declarations of CGameController 
*                & CWsEventReceiver.
*  Version     : 
*
*  Copyright (c) 2007 Nokia Corporation.
*  This material, including documentation and any related 
*  computer programs, is protected by copyright controlled by 
*  Nokia Corporation.
* ==============================================================================
*/
#ifndef __GAME_CONTROLLER_CLASS__
#define __GAME_CONTROLLER_CLASS__

#include <gles/egl.h> // for egl functions.
#include <e32base.h>  // for CBase
#include <w32std.h>   // for TWsEvent

// CONSTANTS
const TUint KBufferSize = 32;

// Error constants
const TInt KErrConfigFailed = -6001;
const TInt KErrCreateWindowSurfaceFailed = -6002;
const TInt KErrCreateContextFailed = -6003;
const TInt KErrSetContextFailed = -6004;
const TInt KErrCoeEnvNotCreated = -6005;
const TInt KErrCoeEnvNotInitialized = -6006;

// Forward declarations
class CGame;
class RWindow;
class CWsEventReceiver;

// CLASS DECLARATION

/**
 * The Game Controller class.
 * Controls the intialization of the Game and mediates the 
 * Key Event delivery to the game.
 */
class CGameController : public CBase 
{
public:
    /**
     * Two phase constructor.
     *
     * @param aEglDisplay the egl display to drawn on.
     */
    static CGameController* NewLC( EGLDisplay aEglDisplay );
    
    /**
     * Starts the Game Loop.
     *
     * @param aGame A reference to the game object.
     */    
    void StartGameL( CGame& aGame );    

    /**
     * Handles a Windows Server event.
     * This is called by the CWsEventReciever whenever it has
     * a pending Windows Server Event.
     *
     * @param aEvent A reference to the Windows server event.
     */        
    void HandleWsEvent( const TWsEvent& aEvent );

    /**
     * Destructor.
     */            
    ~CGameController();
    
private: // Constructors.
    /**
     * Constructor.
     *
     * @param aEglDisplay A handle to the egl display.
     */
    CGameController( EGLDisplay aEglDisplay );    
    
    /**
     * Two phase constructor.
     * Intializes the EGL Context and surface.
     */
    void ConstructL();
private: // Helper functions.
    /**
     * Runs the Active Scheduler so that the any pending
     * Active Objects get a chance to run.
     * @param aIsBlocking If ETrue, the API blocks till a asynchronous 
     *                    event occurs.
     */
    void ProcessBackgroundTasks( TBool aIsBlocking );
    
    /**
     * Creates a RWindow and intializes it to cover the full 
     * screen.
     */    
    void CreateNativeWindowL();
private: // Data
    /** Handle to the EGL Display */
    EGLDisplay iEglDisplay;
 
    /** Handle to the EGL Surface */
    EGLSurface iEglSurface;
    
    /** Handle to the EGL Context */    
    EGLContext iEglContext;
    
    /** Handle to Symbian's Window */    
    RWindow* iWindow;

    /** The Active Object that waits for Windows Server Events */    
    CWsEventReceiver* iWsEventReceiver;
    
    /** The Game */
    CGame* iGame;
    
    /** Handle to the Windows Server session */
    RWsSession iWsSession;

    /** Handle to the Window group */
    RWindowGroup iWindowGroup;
    
    /** The Screen device */
    CWsScreenDevice* iWsScreenDevice;
    
    /** Flag for the applications focus state */
    TBool iIsAppInFocus;
    
    /** Flag to check if the Window is visible */
    TBool iIsVisible;

}; // CGameController

/**
 * The Active Object that waits for Windows Server events
 * and passes it on the Game Controller.
 */
class CWsEventReceiver : public CActive
{
public: 
    /**
     * Recieves events from the Windows Server.
     *
     * This function gets called in the 
     * CGameController::ProcessBackgroundTasks() function,
     * when the CActiveScheduler gets a chance to run.
     */
    virtual void RunL();
    
    /**
     * Cancels event request from the Windows Server.
     */    
    virtual void DoCancel();

    /**
     * Static Constructor.
     *
     * @param aParent The Game Controller requesting for the events.
     */    
    static CWsEventReceiver* NewL( CGameController& aParent );
    
    /**
     * Destructor.
     */    
    ~CWsEventReceiver();

private: // Constructors
    /**
     * Constructor.
     */
    CWsEventReceiver();

    /**
     * Two phase Constructor.
     *
     * @param aParent The Game controller which will be notified of
     *                Windows Server events .
     */    
    void ConstructL( CGameController& aParent );                

private: // Data.
    /** The Windows Server Session */
    RWsSession iWsSession;
    
    /** The Game controller */
    CGameController* iParent;    

};

#endif //__GAME_CONTROLLER_CLASS__
