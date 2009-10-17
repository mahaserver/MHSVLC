

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc/vlc.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* Explicit HACK */
extern void LocaleFree (const char *);
extern char *FromLocale (const char *);

#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

/*****************************************************************************
 * main: parse command line, start interface and spawn threads.
 *****************************************************************************/
int main( int i_argc, const char *ppsz_argv[] )
{
    int i_ret;
    /*struct timespec ts_delay;int64_t pk1,pk2;
printf("checking clock30 sec of wait\n");
pk1=mdate();
getchar();

msleep((int64_t)30*1000000);
pk2=mdate();

printf("done%d\n",(pk2-pk1));
getchar();*/


    setlocale (LC_ALL, "");



#ifdef HAVE_PUTENV
#   ifndef NDEBUG

    putenv( (char*)"MALLOC_CHECK_=2" );
    putenv( (char *)"GNOME_DISABLE_CRASH_DIALOG=1" );
#   endif
#endif

    static const int sigs[] = {
        SIGINT, SIGHUP, SIGQUIT, SIGTERM,
        SIGPIPE, SIGCHLD
    };

    sigset_t set;
    sigemptyset (&set);
#ifndef MHSUGLY
    for (unsigned i = 0; i < sizeof (sigs) / sizeof (sigs[0]); i++)
        sigaddset (&set, sigs[i]);
    
    pthread_sigmask (SIG_BLOCK, &set, NULL);
#endif

    for (int i = 0; i < i_argc; i++)
        if ((ppsz_argv[i] = FromLocale (ppsz_argv[i])) == NULL)
            return 1; // BOOM!

    libvlc_exception_t ex, dummy;
    libvlc_exception_init (&ex);
    libvlc_exception_init (&dummy);


    int i_argc_real = i_argc ? i_argc - 1 : 0;
    const char **ppsz_argv_real = i_argc ? &ppsz_argv[1] : ppsz_argv;
    libvlc_instance_t *vlc = libvlc_new (i_argc_real, ppsz_argv_real, &ex);

    if (vlc != NULL)
    {
        libvlc_add_intf (vlc, "signals", &dummy);
        //libvlc_add_intf (vlc, NULL, &ex);
        libvlc_playlist_play (vlc, -1, 0, NULL, &dummy);
        libvlc_wait (vlc);
        libvlc_release (vlc);
    }
    i_ret = libvlc_exception_raised (&ex);
    if( i_ret )
        fprintf( stderr, "%s\n", libvlc_exception_get_message( &ex));

    libvlc_exception_clear (&ex);
    libvlc_exception_clear (&dummy);

    for (int i = 0; i < i_argc; i++)
        LocaleFree (ppsz_argv[i]);
 
    return i_ret;
}
