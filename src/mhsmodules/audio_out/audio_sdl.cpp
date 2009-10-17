


#define MODULE_NAME aout_sdl
#define MODULE_PATH aout_sdl
#define MODULE_STRING "aout_sdl"
#define __BUILTIN__

#include <aknnotewrappers.h>    // for CAknInformationNote
#include <eikenv.h>             // for CEikonEnv
#include <eikdef.h>
#include <e32math.h>

extern "C" {
              

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc_common.h>
#include <vlc_plugin.h>
#include <vlc_aout.h>

}


#include <mda\common\audio.h>
#include <Mda\Client\Utility.h>
#include <MdaAudioOutputStream.h>
#if !defined(__MDA_COMMON_RESOURCE_H__)
#include <Mda\Common\Resource.h>
#endif

#define FRAME_SIZE 12442
#define BUFFERSIZE 12442


struct aout_sys_t
{
    mtime_t next_date;
    mtime_t buffer_time;
};

typedef struct pk_AudioSpec {
	int freq;	
	TUint16 format;		
	TUint8  channels;	
	TUint8  silence;	
	TUint16 samples;		
	TUint16 padding;	
	TUint32 size;		

	void ( *callback)(void *userdata, short int *stream,unsigned int len);
	void  *userdata;
} pk_AudioSpec;

static int  Open        ( vlc_object_t * );
static void Close       ( vlc_object_t * );
static void Play        ( aout_instance_t * );
static void SDLCallback ( void *, short int *,unsigned int );
void *createdevice(void * arg);

vlc_module_begin();
    set_description( _("Simple DirectMedia Layer audio output") );
    set_capability( "audio output", 40 );
    add_shortcut( "sdl" );
    set_callbacks( Open, Close );
vlc_module_end();



class MySound : public MMdaAudioOutputStreamCallback {
// callback functions for MMdaAudioOutputStreamCallback
public:
	static int v_freq,v_channels;
	static aout_instance_t *v_p_aout;
void construct();
 void Open(); // opens the stream
 void sclose();
void setvol(int ivol);

public:
 virtual void MaoscOpenComplete(TInt aError);
 virtual void MaoscBufferCopied(TInt aError, const TDesC8& aBuffer);
 virtual void MaoscPlayComplete(TInt aError);

protected:
 // this method fills the buffer and writes it into the stream
 void UpdateBuffer();
 // this methoed needs to implemented by YOU
 void FillBuffer(aout_instance_t *v_p_aout,TInt16* buffer, TUint len);

// we will also need these...
protected:
 CMdaAudioOutputStream* iStream; // handle to the stream
 TMdaAudioDataSettings iSettings; // stream settings
 TInt16* iSoundData; // sound buffer
 TPtr8* iSoundBuf; // descriptor for using our soundbuffer
};

////////////////////////////////////////////////
pthread_t tid;
MySound pksound;
int MySound::v_freq;
int MySound::v_channels;						//////////////////Global WSD

extern "C"{
extern int ivol;
extern int devinit=0;
extern int vclosed=0;
extern int is_playing=0;							///////audioserver once started will not stop.So this varibale will decide whether 
}
aout_instance_t* MySound::v_p_aout;
///////////////////////////////////////////////////

void MySound::sclose()
	{
	
	//iStream->Stop();
	//delete iStream;
	
	}


void MySound::FillBuffer(aout_instance_t *v_p_aout,TInt16* buffer, TUint len)
	{

	SDLCallback(v_p_aout,buffer,len);
	}
void MySound::setvol(int fvol)
	{
	
	float qvol,svol;
	qvol=fvol;
	if(qvol<0){qvol=0;}
	if(qvol>360){qvol=360;}
	svol=iStream->MaxVolume();
	qvol=svol*(qvol/360);
	iStream->SetVolume(qvol);
	
	}
	

 void MySound::construct() {
 
 iStream = CMdaAudioOutputStream::NewL(*this);
 iSoundData = new TInt16[BUFFERSIZE];
 iSoundBuf = new TPtr8((TUint8*)iSoundData, BUFFERSIZE*2, BUFFERSIZE*2);
}
void MySound::Open() {

 iStream->Open(&iSettings);
}

void MySound::MaoscOpenComplete(TInt aError) {

 if (aError==KErrNone) {
   // set stream properties to 16bit,16KHz mono
 if(v_channels==1)
	 {
	 switch(v_freq)
		 {
		 case 8000:
	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate8000Hz, TMdaAudioDataSettings::EChannelsMono);
	     break;
		 case 11025:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate11025Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 12000:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate12000Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 16000:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate16000Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 22050:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate22050Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 24000:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate24000Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 32000:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate32000Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 44100:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate44100Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 48000:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate48000Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 64000:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate64000Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 case 96000:
		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate96000Hz, TMdaAudioDataSettings::EChannelsMono);
		 break;
		 }
	 }
 else
	 {
	 
	 switch(v_freq)
	 		 {
	 		 case 8000:
	 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate8000Hz, TMdaAudioDataSettings::EChannelsMono);
	 	     break;
	 		 case 11025:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate11025Hz, TMdaAudioDataSettings::EChannelsMono);
	 		 break;
	 		 case 12000:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate12000Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 16000:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate16000Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 22050:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate22050Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 24000:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate24000Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 32000:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate32000Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 44100:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate44100Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 48000:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate48000Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 64000:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate64000Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 case 96000:
	 		 	     iStream->SetAudioPropertiesL(TMdaAudioDataSettings::ESampleRate96000Hz, TMdaAudioDataSettings::EChannelsStereo);
	 		 break;
	 		 }	 
	 	 }
   
   // note that MaxVolume() is different in the emulator and the real device!
   iStream->SetVolume(iStream->MaxVolume()/2);        
   iStream->SetPriority(EPriorityMuchMore, EMdaPriorityPreferenceNone);

   // Fill first buffer and write it to the stream
   UpdateBuffer();
}
// CActiveScheduler::Stop();
 }

void MySound::UpdateBuffer() {
  // calculate the contents of the buffer

 
setvol(ivol);

if (is_playing){
FillBuffer(v_p_aout,iSoundData, BUFFERSIZE);
}
else
{
vlc_memset(iSoundData,0,2*BUFFERSIZE);
}
// call WriteL with a descriptor pointing at iSoundData
iStream->WriteL(*iSoundBuf);
 }
 
 void MySound::MaoscBufferCopied(TInt aError, const TDesC8& ) {

  if (aError==KErrNone) {
   UpdateBuffer();
  }else
	  {
	  printf("buffer copy error");
	  }
 }
 void MySound::MaoscPlayComplete(TInt aError) {
 
 // we only want to restart in case of an underflow
 // if aError!=KErrUnderflow the stream probably was stopped manually
 
 //iStream->Stop();
 

 
  if (aError==KErrUnderflow) {
     UpdateBuffer();
  }
 }




static int Open ( vlc_object_t *p_this )
{

    aout_instance_t *p_aout = (aout_instance_t *)p_this;
    
    pk_AudioSpec desired, obtained;
   int i_nb_channels,ret;

   void * arg;
    vlc_value_t val, text;
    
   i_nb_channels = aout_FormatNbChannels( &p_aout->output.output );
    
   if(i_nb_channels<1){printf("less than one channel detected");}
   else if(i_nb_channels==1){p_aout->output.output.i_physical_channels = AOUT_CHAN_CENTER;}
   else if(i_nb_channels==2){p_aout->output.output.i_physical_channels = AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT;}
   else  if ( i_nb_channels > 2 )
    {i_nb_channels = 2;
     p_aout->output.output.i_physical_channels= AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT;
    }
    desired.freq       = p_aout->output.output.i_rate;
    desired.format     = 1;
    desired.channels   = i_nb_channels;
    //desired.callback   = SDLCallback;//to be supplied to the cstreamplayer  epoc in this case
    desired.userdata   = p_aout;
    desired.samples    = FRAME_SIZE;
obtained.channels=desired.channels;
    p_aout->output.output.i_format = VLC_FOURCC('s','1','6','l'); 
    p_aout->output.i_nb_samples = FRAME_SIZE;
    p_aout->output.pf_play = Play;
    MySound::v_freq=desired.freq;
	MySound::v_channels=desired.channels;
	MySound::v_p_aout=p_aout;
    while (
    		(desired.freq != 8000) &&
    		(desired.freq != 11025) &&
    		(desired.freq != 12000) &&
    		(desired.freq != 16000) &&
    		(desired.freq != 22050) &&
    		(desired.freq != 24000) &&
    		(desired.freq != 32000) &&
    		(desired.freq != 44100) &&
    		(desired.freq != 48000) &&
    		(desired.freq != 64000) &&
    		(desired.freq != 96000) &&
    		(desired.freq >96000)
    		
    ){desired.freq++;}
    if(desired.freq>96000){desired.freq=96000;}
    p_aout->output.output.i_rate = desired.freq;
    
 
if(devinit==0){
devinit=1;
ret=pthread_create(&tid,NULL,createdevice,arg);
}
// Volume is entirely done in software. 
    
    aout_VolumeSoftInit( p_aout );
  

    if ( obtained.channels != i_nb_channels )
    {
        p_aout->output.output.i_physical_channels = (obtained.channels == 2 ?
                                            AOUT_CHAN_LEFT | AOUT_CHAN_RIGHT :
                                            AOUT_CHAN_CENTER);

        if ( var_Type( p_aout, "audio-device" ) == 0 )
        {
            var_Create( p_aout, "audio-device",
                        VLC_VAR_INTEGER | VLC_VAR_HASCHOICE );
            text.psz_string = _("Audio device");
            var_Change( p_aout, "audio-device", VLC_VAR_SETTEXT, &text, NULL );

            val.i_int = (obtained.channels == 2) ? AOUT_VAR_STEREO :
                        AOUT_VAR_MONO;
            text.psz_string = (obtained.channels == 2) ? (char*)N_("Stereo") :(char*)
                              N_("Mono");
            var_Change( p_aout, "audio-device",
                        VLC_VAR_ADDCHOICE, &val, &text );
            var_AddCallback( p_aout, "audio-device", aout_ChannelsRestart,
                             NULL );
        }
    }
    else if ( var_Type( p_aout, "audio-device" ) == 0 )
    {
        // First launch. 
        var_Create( p_aout, "audio-device",
                    VLC_VAR_INTEGER | VLC_VAR_HASCHOICE );
        text.psz_string = _("Audio device");
        var_Change( p_aout, "audio-device", VLC_VAR_SETTEXT, &text, NULL );

        val.i_int = AOUT_VAR_STEREO;
        text.psz_string = N_("Stereo");
        var_Change( p_aout, "audio-device", VLC_VAR_ADDCHOICE, &val, &text );
        val.i_int = AOUT_VAR_MONO;
        text.psz_string = N_("Mono");
        var_Change( p_aout, "audio-device", VLC_VAR_ADDCHOICE, &val, &text );
        if ( i_nb_channels == 2 )
        {
            val.i_int = AOUT_VAR_STEREO;
        }
        else
        {
            val.i_int = AOUT_VAR_MONO;
        }
        var_Change( p_aout, "audio-device", VLC_VAR_SETDEFAULT, &val, NULL );
        var_AddCallback( p_aout, "audio-device", aout_ChannelsRestart, NULL );
    }

    val.b_bool = true;
    var_Set( p_aout, "intf-change", val );

 

    return VLC_SUCCESS;
    

}


static void Play( aout_instance_t * p_aout )
{
is_playing=1;
}


static void Close ( vlc_object_t *p_this )
{
is_playing=0;

}

static void SDLCallback( void * _p_aout, short int * p_stream,unsigned int i_len )
{

//int i;
//FILE* pkf;
//pkf=fopen("c:\\data\\sounds\\sound1.pcm","ab");
    aout_instance_t * p_aout = (aout_instance_t *)_p_aout;
    aout_buffer_t *   p_buffer;



    vlc_mutex_lock( &p_aout->output_fifo_lock );
    p_buffer = aout_FifoPop( p_aout, &p_aout->output.fifo );
    vlc_mutex_unlock( &p_aout->output_fifo_lock );

    if ( p_buffer != NULL )
    {
    vlc_memcpy( p_stream, p_buffer->p_buffer, 2*i_len );
       // memset(p_stream,0,2*i_len);
   // TUint32 intVal;    
   //     TInt len = aDescBuf.Length();    
   //     for(TInt i=0; i<len; i+=2)
   //         {
            
   //         WriteToBuf(aDescBuf,i,intVal);
   //         }
    
    
//       if(pkf!=NULL){
//        fwrite(p_stream,sizeof(*p_stream),i_len,pkf);
//       }
        aout_BufferFree( p_buffer );
    }
    else
    {
    vlc_memset( p_stream, 0,2*i_len );
    }
//fclose(pkf);
//usleep(30000);
}

void *createdevice(void * arg)
	{
	
		

    if (!CActiveScheduler::Current())
    {
       CActiveScheduler* scheduler=new(ELeave) CActiveScheduler;
       CActiveScheduler::Install(scheduler);
    }

   
pksound.construct();   
pksound.Open();
CActiveScheduler::Start();
	
	}


inline void WriteToBuf(TDes8& aDescBuf, TInt aOffset, TInt aValue)
    {
    
    aDescBuf[aOffset] = (TUint8)(aValue & 0x00ff); 
    aDescBuf[aOffset+1] = (TUint8)((aValue & 0xff00)>>8);
    }


