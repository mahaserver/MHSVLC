/*
* ==============================================================================
*  Name        : gamecontroller.cpp
*  Part of     : MHSVLC
*  Interface   : 
*  Description : Contains the implementations of CGameController
*                & CWsEventReceiver.
*  Version     : 
*
*  Copyright (c) 2007 Nokia Corporation.
*  This material, including documentation and any related 
*  computer programs, is protected by copyright controlled by 
*  Nokia Corporation.
* ==============================================================================
*/
#include "game.h"
#include "gamecontroller.h"
#include <coemain.h> // for CCoeEnv

// -----------------------------------------------------------------------------
// CGameController::NewLC
// The Factory Function for a CGameController object.
// -----------------------------------------------------------------------------
//
CGameController* CGameController::NewLC( EGLDisplay aEglDisplay )
{
    CGameController* self = new (ELeave) CGameController( aEglDisplay );
    
    CleanupStack::PushL( self );
    
    self->ConstructL();

    return self;    
}

// -----------------------------------------------------------------------------
// CGameController::CGameController
// Constructor.
// -----------------------------------------------------------------------------
//
CGameController::CGameController( EGLDisplay aEglDisplay )
                :iEglDisplay( aEglDisplay ),
                 iEglSurface( NULL ),
                 iEglContext( NULL ),
                 iWindow( NULL ),
                 iWsEventReceiver( NULL ),
                 iGame( NULL ),
                 iWsScreenDevice( NULL ),
                 iIsAppInFocus( EFalse ),
                 iIsVisible( ETrue )
{
}

// -----------------------------------------------------------------------------
// CGameController::~CGameController
// Destructor.
// -----------------------------------------------------------------------------
//
CGameController::~CGameController()
{
    // EGL related cleanup.
    eglMakeCurrent( iEglDisplay, EGL_NO_SURFACE, 
                    EGL_NO_SURFACE, EGL_NO_CONTEXT 
                  );
    eglDestroySurface( iEglDisplay, iEglSurface );
    eglDestroyContext( iEglDisplay, iEglContext );
    
    // Destroy the RWindow.
    if( iWindow != NULL )
    {
        iWindow->SetOrdinalPosition( KOrdinalPositionSwitchToOwningWindow );
        iWindow->Close();
        delete iWindow;
        iWindow = NULL;
    }
    
    delete iWsEventReceiver;
}

// -----------------------------------------------------------------------------
// CGameController::ConstructL
// Second phase constructor.
// Initializes EGL.
// -----------------------------------------------------------------------------
//
void CGameController::ConstructL()
{    
    CCoeEnv* env = CCoeEnv::Static();
    if( !env )
    {
        User::Leave( KErrCoeEnvNotInitialized );
    }

    // Get the Windows Server Session, screen device and window group.
    iWsSession = env->WsSession();
    iWsScreenDevice = env->ScreenDevice();
    iWindowGroup = env->RootWin();
    if( !iWsScreenDevice )
    {
        User::Leave( KErrCoeEnvNotInitialized );
    }

    // Intializes iWindow to a full screen window.
    CreateNativeWindowL();
    
    // Choose the buffer size based on the Window's display mode.
    TDisplayMode displayMode = iWindow->DisplayMode();
    TInt bufferSize = 0;

    switch( displayMode )
    {
        case(EColor4K):
            bufferSize = 12;
            break;
        case(EColor64K):
            bufferSize = 16;
            break;
        case(EColor16M):
            bufferSize = 24;
            break;
        case(EColor16MU):
	    case(EColor16MA):
            bufferSize = 32;
            break;
        default:
            break;
    }
             
    // Set the desired properties for the EGLSurface
    const EGLint attributeList[] = { 
                                     EGL_SURFACE_TYPE, EGL_WINDOW_BIT, 
                                     EGL_BUFFER_SIZE, bufferSize, 
                                     EGL_NONE 
                                   };
    EGLConfig bestConfig;
    EGLint numConfigs = 0;

    // Choose the best EGLConfig that matches the desired properties. 
    if( eglChooseConfig( iEglDisplay, attributeList, &bestConfig,
                          1, &numConfigs
                        ) == EGL_FALSE
      )
    {
        User::Leave( KErrConfigFailed );
    }
    
    if( numConfigs == 0 )
    {
    	User::Leave( KErrConfigFailed );
    }
        
    // Create a window surface where the graphics are blitted.
    // Pass the Native Window handle to egl.
    iEglSurface = eglCreateWindowSurface( iEglDisplay, bestConfig, 
                                          (void*)iWindow, NULL 
                                        );
    if( iEglSurface == NULL )
    {
        User::Leave( KErrCreateWindowSurfaceFailed );
    }
        
    // Create a rendering context
    iEglContext = eglCreateContext( iEglDisplay, bestConfig,
                                    EGL_NO_CONTEXT, NULL 
                                  );
    if( iEglContext == NULL )
    {
        User::Leave( KErrCreateContextFailed );    
    }
    
    // Make it the current context.
    if( eglMakeCurrent( iEglDisplay, iEglSurface, 
                         iEglSurface, iEglContext 
                      ) == EGL_FALSE
      )
    {
        User::Leave( KErrSetContextFailed );        
    }
    
    // Creates the Active Object that waits for Windows Server events.
    iWsEventReceiver = CWsEventReceiver::NewL( *this );
}

// -----------------------------------------------------------------------------
// CGameController::StartGameL
// Intializes the Game and Starts the game loop.
// -----------------------------------------------------------------------------
//
void CGameController::StartGameL( CGame& aGame )
{    
    iGame = &aGame;   
    
    // Allow the game to initialize itself.
    // The opengl es state intialization is done here.
    aGame.Initialize( iWindow->Size().iWidth, iWindow->Size().iHeight );
    
    TTime currentTime;
    TTime lastTimeVisited;
    lastTimeVisited.HomeTime();    
        
    while( 1 ) // Loop until the Game wants to exit.
    {       
        // Process any pending tasks.
        // This runs any Active objects that are waiting for 
        // some processing. 
        // The CWsEventReceiver Active Object gets a chance to
        // run here (on a key event for example).
        ProcessBackgroundTasks( EFalse );
                
        // If the application is not in focus or is not visible.
        // Block until it regains focus.
        while( EFalse == iIsAppInFocus || EFalse == iIsVisible )
            ProcessBackgroundTasks( ETrue );
                
        // Get the current time.
        currentTime.HomeTime();       
        TTimeIntervalMicroSeconds dur 
                    = currentTime.MicroSecondsFrom( lastTimeVisited );                        
                
        // The game renders itself using opengl es apis.
        // A return value of EFalse signifies an exit from the game.
        // Pass in the time (in micro secs) elapsed since last call. 
        if( EFalse == aGame.RenderFrame( dur.Int64() ) )
        {
            break;
        }                                

        // Call eglSwapBuffers, which blits the graphics to the window.
        eglSwapBuffers( iEglDisplay, iEglSurface );    

        // To keep the background light on.
        if( !( ( iGame->GetCurrentFrame() )%100 ) )
        {
            User::ResetInactivityTime();
        }
        
        // Store the last time the Game was rendered.
        lastTimeVisited = currentTime;
    }
    
    // Cleanup.
    aGame.Cleanup();    
}

// -----------------------------------------------------------------------------
// CGameController::ProcessBackgroundTasks
// Calls the RunL on all Active Objects which have 
// pending requests.
// If aIsBlocking is ETrue, this API will block till an event occurs.
// -----------------------------------------------------------------------------
//
void CGameController::ProcessBackgroundTasks( TBool aIsBlocking )
{
    RThread thread;    
    TInt error = KErrNone;
    
    if ( aIsBlocking && !thread.RequestCount() )
    {
        // Block for a event.
        User::WaitForAnyRequest();

        // Run the Active Object corresponding to the event
        CActiveScheduler::RunIfReady( error, CActive::EPriorityIdle );
    }

    // Processes all outstanding requests
    while( thread.RequestCount() ) 
    {
        // Processes an event.        
        CActiveScheduler::RunIfReady( error, CActive::EPriorityIdle );
        
        // Decreases thread.RequestCount
        User::WaitForAnyRequest();
    }
}

// -----------------------------------------------------------------------------
// CGameController::CreateNativeWindowL
// Create a full screen RWindow and enables screen size
// change events.
// -----------------------------------------------------------------------------
//
void CGameController::CreateNativeWindowL()
{      
    iWindow = new (ELeave) RWindow( iWsSession );
    
    // Construct the window.
    TInt err = iWindow->Construct( iWindowGroup,
                                   reinterpret_cast<TUint32>( this ) 
                                 );
    User::LeaveIfError( err );

    // Enable the EEventScreenDeviceChanged event.
    iWindowGroup.EnableScreenChangeEvents();                                      
        
    TPixelsTwipsAndRotation pixnrot; 
    iWsScreenDevice->GetScreenModeSizeAndRotation( 
                                iWsScreenDevice->CurrentScreenMode(),
                                pixnrot );
        
    //Can be set to anything
    // Set size of the window (cover the entire screen)
    iWindow->SetExtent( TPoint( 0, 0 ),
                        pixnrot.iPixelSize
                      );
                       
    iWindow->SetRequiredDisplayMode( iWsScreenDevice->DisplayMode() );
    
    // Activate window and bring it to the foreground
    iWindow->Activate();
    iWindow->SetVisible( ETrue );
    iWindow->SetNonFading( ETrue ); 
    iWindow->SetShadowDisabled( ETrue ); 
    iWindow->EnableRedrawStore( EFalse ); 
    iWindow->EnableVisibilityChangeEvents();
    iWindow->SetNonTransparent(); 
    iWindow->SetBackgroundColor(); 
    iWindow->SetOrdinalPosition( 0 );    
}

// -----------------------------------------------------------------------------
// CGameController::HandleWsEvent
// This function is called by the CWsEventReceiver 
// Active Object, whenever it receives a Windows Server
// event.
// -----------------------------------------------------------------------------
//
void CGameController::HandleWsEvent( const TWsEvent& aWsEvent )
{
    TInt eventType = aWsEvent.Type();
     
    // Handle Key and Screen Size change Events.
    switch( eventType )
    {
        case EEventKeyDown:
        {
            if( iGame )
                iGame->HandleKeyEvent( aWsEvent.Key()->iScanCode, EFalse );
            
            break;            
        }
        case EEventKeyUp:
        {
            if( iGame )
                iGame->HandleKeyEvent( aWsEvent.Key()->iScanCode, ETrue );
            
            break;            
        }        
        case( EEventScreenDeviceChanged ): // The screen size has changed.
        {
            TPixelsTwipsAndRotation pixnrot; 
            iWsScreenDevice->GetScreenModeSizeAndRotation( 
                                  iWsScreenDevice->CurrentScreenMode(),
                                  pixnrot 
                                                         );       
            if( pixnrot.iPixelSize != iWindow->Size() )
            {
                 
                // Update the window.
                iWindow->SetExtent( TPoint( 0, 0 ),
                                    pixnrot.iPixelSize
                                  );                
                                        
                // If a game is running, notify it about the change.
                if( iGame )
                {
                    iGame->SetScreenSize( pixnrot.iPixelSize.iWidth,
                                          pixnrot.iPixelSize.iHeight 
                                        );                    
                    
                    // Call eglSwapBuffers after the window size has changed.
                    // This updates the window size used by egl. 
                    eglSwapBuffers( iEglDisplay, iEglSurface );                                        
                }                
                                
            }                    
            break;            
        }
        case EEventFocusLost: 
        {
            iIsAppInFocus = EFalse;
            break;
        }
        case EEventFocusGained:
        {
            iIsAppInFocus = ETrue;
            break;
        }
        case EEventWindowVisibilityChanged:
        {
            // Check if the event is for the iWindow
            if( aWsEvent.Handle() ==
                        reinterpret_cast<TUint32>( this )
                  
              )
            {
                if( aWsEvent.VisibilityChanged()->iFlags &
                    TWsVisibilityChangedEvent::ECanBeSeen 
                )                
                {
                      iIsVisible = ETrue;
                }
                else
                      iIsVisible = EFalse;
                
            }                            
            break;
        }
        case EEventNull:
        case EEventKey:        
        case EEventUser:                                
        case EEventWindowGroupListChanged:
        case EEventModifiersChanged:
        case EEventSwitchOn:
        case EEventPassword:
        case EEventWindowGroupsChanged:
        case EEventErrorMessage:
        case EEventPointer:
        case EEventPointerEnter:
        case EEventPointerExit:
        case EEventPointerBufferReady:
        case EEventDragDrop:
            break;
        default:
            break;
    }        
}

////////////////////////////////////////////////////////////////////////////////
//              Windows Server Event Receiver Implementation                  //
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// CWsEventReceiver::CWsEventReceiver
// Constructor.
// -----------------------------------------------------------------------------
//
CWsEventReceiver::CWsEventReceiver()
                 :CActive( CActive::EPriorityStandard ),
                  iParent( NULL )
{                      
}

// -----------------------------------------------------------------------------
// CWsEventReceiver::~CWsEventReceiver
// Destructor.
// -----------------------------------------------------------------------------
//
CWsEventReceiver::~CWsEventReceiver()
{
    Cancel();
}

// -----------------------------------------------------------------------------
// CWsEventReceiver::NewL
// Factory Function.
// -----------------------------------------------------------------------------
//
CWsEventReceiver* CWsEventReceiver::NewL( CGameController& aParent )
{
    CWsEventReceiver* self = new (ELeave) CWsEventReceiver;
    
    CleanupStack::PushL( self );
    
    self->ConstructL( aParent );
    
    CleanupStack::Pop( self );
    
    return self;    
}

// -----------------------------------------------------------------------------
// CWsEventReceiver::ConstructL
// Second phase constructor.
// Add itself to the Active Scheduler.
// -----------------------------------------------------------------------------
//
void CWsEventReceiver::ConstructL( CGameController& aParent )
{
    if( !CCoeEnv::Static() )
        User::Leave( KErrCoeEnvNotCreated );
    
    iParent = &aParent;
     
    // Register with the Windows Server for events.
    iWsSession = CCoeEnv::Static()->WsSession();
    
    iWsSession.EventReady( &iStatus );
    
    CActiveScheduler::Add( this );
    
    SetActive();
}

// -----------------------------------------------------------------------------
// CWsEventReceiver::RunL
// Is called by the Active Scheduler when a Windows
// Server event is pending.
// NOTE: This API does not leave, so RunError is not
//       implemented.
// -----------------------------------------------------------------------------
//
void CWsEventReceiver::RunL()
{
    TWsEvent wsEvent;
    iWsSession.GetEvent( wsEvent );
    
    // Pass the event on to the Game Controller.
    iParent->HandleWsEvent( wsEvent );
    
    // Request for more events.
    iWsSession.EventReady( &iStatus );
    
    SetActive();
}

// -----------------------------------------------------------------------------
// CWsEventReceiver::DoCancel
// Cancels any pending Windows Server event requests.
// -----------------------------------------------------------------------------
//
void CWsEventReceiver::DoCancel()
{
    iWsSession.EventReadyCancel();
}

// eof
