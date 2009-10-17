/*****************************************************************************
 * cpu.c: CPU detection code
 *****************************************************************************
 * Copyright (C) 1998-2004 the VideoLAN team
 * $Id$
 *
 * Authors: Samuel Hocevar <sam@zoy.org>
 *          Christophe Massiot <massiot@via.ecp.fr>
 *          Eugenio Jarosiewicz <ej0@cise.ufl.eduEujenio>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/*****************************************************************************
 * Preamble
 *****************************************************************************/
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc_common.h>

#ifdef HAVE_SIGNAL_H
#   include <signal.h>                            /* SIGHUP, SIGINT, SIGKILL */
#   include <setjmp.h>                                    /* longjmp, setjmp */
#endif

#include "../libvlc.h"

#if defined(__APPLE__) && (defined(__ppc__) || defined(__ppc64__))
#include <sys/sysctl.h>
#endif

/*****************************************************************************
 * Local prototypes
 *****************************************************************************/
#ifdef HAVE_SIGNAL_H
static void SigHandler   ( int );
#endif

/*****************************************************************************
 * Global variables - they're needed for signal handling
 *****************************************************************************/
#ifdef HAVE_SIGNAL_H
static jmp_buf env;
static int     i_illegal;
#if defined( __i386__ ) || defined( __x86_64__ )
static const char *psz_capability;
#endif
#endif

/*****************************************************************************
 * CPUCapabilities: get the CPU capabilities
 *****************************************************************************
 * This function is called to list extensions the CPU may have.
 *****************************************************************************/
uint32_t CPUCapabilities( void )
{
    volatile uint32_t i_capabilities = CPU_CAPABILITY_NONE;

    /* default behaviour */
    return i_capabilities;


}

/*****************************************************************************
 * SigHandler: system signal handler
 *****************************************************************************
 * This function is called when an illegal instruction signal is received by
 * the program. We use this function to test OS and CPU capabilities
 *****************************************************************************/
#if defined( HAVE_SIGNAL_H )
static void SigHandler( int i_signal )
{
    /* Acknowledge the signal received */
    i_illegal = 1;

#ifdef HAVE_SIGRELSE
    sigrelse( i_signal );
#else
    VLC_UNUSED( i_signal );
#endif

#if defined( __i386__ )
    fprintf( stderr, "warning: your CPU has %s instructions, but not your "
                     "operating system.\n", psz_capability );
    fprintf( stderr, "         some optimizations will be disabled unless "
                     "you upgrade your OS\n" );
#   if defined( __linux__ )
    fprintf( stderr, "         (for instance Linux kernel 2.4.x or later)\n" );
#   endif
#endif

    longjmp( env, 1 );
}
#endif


uint32_t cpu_flags = 0;


/*****************************************************************************
 * vlc_CPU: get pre-computed CPU capability flags
 ****************************************************************************/
unsigned vlc_CPU (void)
{
    return cpu_flags;
}

static vlc_memcpy_t pf_vlc_memcpy = memcpy;
static vlc_memset_t pf_vlc_memset = memset;

void vlc_fastmem_register (vlc_memcpy_t cpy, vlc_memset_t set)
{
    if (cpy)
        pf_vlc_memcpy = cpy;
    if (set)
        pf_vlc_memset = set;
}

/**
 * vlc_memcpy: fast CPU-dependent memcpy
 */
void *vlc_memcpy (void *tgt, const void *src, size_t n)
{
    return pf_vlc_memcpy (tgt, src, n);
}

/**
 * vlc_memset: fast CPU-dependent memset
 */
void *vlc_memset (void *tgt, int c, size_t n)
{
    return pf_vlc_memset (tgt, c, n);
}
