/*****************************************************************************
 * modules_builtin.h: built-in modules list
 *****************************************************************************
 * Copyright (C) 2001 the VideoLAN team
 *
 * Authors: Samuel Hocevar <sam@zoy.org>
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

#define ALLOCATE_BUILTIN( NAME ) \
    AllocateBuiltinModule( p_this, vlc_entry__ ## NAME );

/* We also consider the main program as a module (useful for config stuff) */
int vlc_entry__main( module_t* );
int vlc_entry__rc( module_t* );
int vlc_entry__access_file( module_t* );
int vlc_entry__mpga( module_t* );
int vlc_entry__mpeg_audio( module_t* );
int vlc_entry__id3tag( module_t* );
int vlc_entry__mpgatofixed32( module_t* );

int vlc_entry__converter_fixed( module_t* );
int vlc_entry__converter_float( module_t* );
int vlc_entry__float32_mixer( module_t* );
int vlc_entry__spdif_mixer( module_t* );
int vlc_entry__trivial_mixer( module_t* );
int vlc_entry__mono( module_t* );
int vlc_entry__trivial_channel_mixer( module_t* );
int vlc_entry__simple_channel_mixer( module_t* );
int vlc_entry__headphone_channel_mixer( module_t* );
int vlc_entry__dolby_surround_decoder( module_t* );
int vlc_entry__bandlimited_resampler( module_t* );
int vlc_entry__ugly_resampler( module_t* );
int vlc_entry__linear_resampler( module_t* );
int vlc_entry__trivial_resampler( module_t* );
int vlc_entry__mhsopengl( module_t* );


#ifndef NOCAPABILITY
int vlc_entry__aout_sdl( module_t* );
#endif
/* Add stuff here */
