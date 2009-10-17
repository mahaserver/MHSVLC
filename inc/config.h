/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
#undef AC_APPLE_UNIVERSAL_BUILD

/* Define to 1 to allow runing VLC as root (uid 0). */
#define ALLOW_RUN_AS_ROOT 1

/* Maximum supported data alignment */
#undef ATTRIBUTE_ALIGNED_MAX

/* "Define if struct caca_event is opaque and must not be accessed directly"
   */
#undef CACA_EVENT_OPAQUE

/* Define to 1 if 3D Now! inline assembly is available. */
#undef CAN_COMPILE_3DNOW

/* Define to 1 if AltiVec inline assembly is available. */
#undef CAN_COMPILE_ALTIVEC

/* Define to 1 if C AltiVec extensions are available. */
#undef CAN_COMPILE_C_ALTIVEC

/* Define to 1 inline MMX assembly is available. */
#undef CAN_COMPILE_MMX

/* Define to 1 if MMX EXT inline assembly is available. */
#undef CAN_COMPILE_MMXEXT

/* Define to 1 if SSE inline assembly is available. */
#undef CAN_COMPILE_SSE

/* Define to 1 if SSE2 inline assembly is available. */
#undef CAN_COMPILE_SSE2

/* The ./configure command line */
#undef CONFIGURE_LINE

/* Copyright string */
#define COPYRIGHT_MESSAGE "MHSVLC"

/* The copyright years */
#define COPYRIGHT_YEARS "2009"

/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP
   systems. This function is required for `alloca.c' support on those systems.
   */
#undef CRAY_STACKSEG_END

/* Define to 1 if using `alloca.c'. */
#undef C_ALLOCA

/* Binary specific version */
#define DISTRO_VERSION "1.0.0"

/* Define if <X11/extensions/dpms.h> defines DPMSInfo. */
#undef DPMSINFO_IN_DPMS_H

/* Define if you want the HTTP dameon support */
#define ENABLE_HTTPD 1

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#undef ENABLE_NLS

/* Define to 1 for stream output support. */
#define ENABLE_SOUT 1

/* Define if you want the VideoLAN manager support */
#define ENABLE_VLM

/* Define to 1 if you have the <a52dec/a52.h> header file. */
#undef HAVE_A52DEC_A52_H

/* Define to 1 if <netdb.h> defines `struct addrinfo'. */
#define HAVE_ADDRINFO 1

/* Define to 1 if you have `alloca', as a function or macro. */
#undef HAVE_ALLOCA

/* Define to 1 if you have <alloca.h> and it should be used (not on Ultrix).
   */
#undef HAVE_ALLOCA_H

/* Define if ALSA is present. */
#undef HAVE_ALSA

/* Define if ALSA is at least rc4 */
#undef HAVE_ALSA_NEW_API

/* Define to 1 if you have the <altivec.h> header file. */
#undef HAVE_ALTIVEC_H

/* Define to 1 if you have the <ApplicationServices/ApplicationServices.h>
   header file. */
#undef HAVE_APPLICATIONSERVICES_APPLICATIONSERVICES_H

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the `asprintf' function. */
#define HAVE_ASPRINTF 1

/* Define to 1 if you have the `atof' function. */
#define HAVE_ATOF 1

/* Define to 1 if you have the `atoll' function. */
#define HAVE_ATOLL 1

/* Support for __attribute__((packed)) for structs */
#undef HAVE_ATTRIBUTE_PACKED

/* Define if you have avahi-client 0.6 or greater */
#undef HAVE_AVAHI_06

/* Define if you have the avahi-client library */
#undef HAVE_AVAHI_CLIENT

/* Define to 1 if you have the `backtrace' function. */
#undef HAVE_BACKTRACE

/* Define to 1 if you have the `bsearch' function. */
#undef HAVE_BSEARCH

/* Define to 1 if you have the <Carbon/Carbon.h> header file. */
#undef HAVE_CARBON_CARBON_H

/* Define to 1 if you have the <cascade/graphics/CascadeBitmap.h> header file.
   */
#undef HAVE_CASCADE_GRAPHICS_CASCADEBITMAP_H

/* Define to 1 if you have the <cascade/graphics/CascadeScreen.h> header file.
   */
#undef HAVE_CASCADE_GRAPHICS_CASCADESCREEN_H

/* Define for the audio CD plugin using libcdio */
#undef HAVE_CDDAX

/* Define to 1 if you have the MacOS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
#undef HAVE_CFLOCALECOPYCURRENT

/* Define to 1 if you have the MacOS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
#undef HAVE_CFPREFERENCESCOPYAPPVALUE

/* Define to 1 if you have clock_nanosleep. */
#undef HAVE_CLOCK_NANOSLEEP

/* Define to 1 if you have the `connect' function. */
#define HAVE_CONNECT 1

/* Define to 1 if you have the <CoreAudio/CoreAudio.h> header file. */
#undef HAVE_COREAUDIO_COREAUDIO_H

/* Define to 1 if you have the `ctime_r' function. */
#define HAVE_CTIME_R 1

/* Define to 1 if you have the <cybergarage/upnp/MediaServer.h> header file.
   */
#undef HAVE_CYBERGARAGE_UPNP_MEDIASERVER_H

/* Define to 1 if you have the <d3d9.h> header file. */
#undef HAVE_D3D9_H

/* Define to 1 if you have the `daemon' function. */
#undef HAVE_DAEMON

/* Define if you have the D-BUS library */
#undef HAVE_DBUS

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
#undef HAVE_DCGETTEXT

/* Define to 1 if you have the <ddraw.h> header file. */
#undef HAVE_DDRAW_H

/* Define if <time.h> defines nanosleep. */
#define HAVE_DECL_NANOSLEEP 1

/* Define to 1 if you have the
   <deschutes/libraries/hdmachinex225/PCMAudioPlayer.h> header file. */
#undef HAVE_DESCHUTES_LIBRARIES_HDMACHINEX225_PCMAUDIOPLAYER_H

/* Define to 1 if you have the <dirent.h> header file. */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define if you have the BeOS dl */
#undef HAVE_DL_BEOS

/* Define if you have the GNU dld library */
#undef HAVE_DL_DLD_LINK

/* Define if you have the dlopen API */
#define HAVE_DL_DLOPEN 1

/* Define if you have the Darwin dyld API */
#undef HAVE_DL_DYLD

/* Define to 1 if you have the <dl.h> header file. */
#undef HAVE_DL_H

/* Define if you have the shl_load API */
#undef HAVE_DL_SHL_LOAD

/* Define if you have Windows' LoadLibrary */
#undef HAVE_DL_WINDOWS

/* Define to 1 if you have the <dshow.h> header file. */
#undef HAVE_DSHOW_H

/* Define to 1 if you have the <dvbpsi/dr.h> header file. */
#undef HAVE_DVBPSI_DR_H

/* Define if you have dvbpsi_GenSDTSections. */
#undef HAVE_DVBPSI_SDT

/* Define to 1 if you have the <dvdread/dvd_reader.h> header file. */
#undef HAVE_DVDREAD_DVD_READER_H

/* Define if we have support for dynamic plugins */
#define HAVE_DYNAMIC_PLUGINS 1

/* Define to 1 if you have the <ebml/EbmlVersion.h> header file. */
#undef HAVE_EBML_EBMLVERSION_H

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <execinfo.h> header file. */
#undef HAVE_EXECINFO_H

/* Define to 1 if you have the <faad.h> header file. */
#undef HAVE_FAAD_H

/* Define to 1 if you have the `fcntl' function. */
#define HAVE_FCNTL 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <ffmpeg/avcodec.h> header file. */
#undef HAVE_FFMPEG_AVCODEC_H

/* Define to 1 if you have the <ffmpeg/avformat.h> header file. */
#undef HAVE_FFMPEG_AVFORMAT_H

/* Define to 1 if you have the <ffmpeg/avutil.h> header file. */
#undef HAVE_FFMPEG_AVUTIL_H

/* Define to 1 if you have the <ffmpeg/swscale.h> header file. */
#undef HAVE_FFMPEG_SWSCALE_H

/* Define to 1 if you have the <FLAC/stream_decoder.h> header file. */
#undef HAVE_FLAC_STREAM_DECODER_H

/* Define to 1 if you have the <fontconfig/fontconfig.h> header file. */
#undef HAVE_FONTCONFIG_FONTCONFIG_H

/* Define to 1 if you have the `fork' function. */
#undef HAVE_FORK

/* Define to 1 if you have the `gai_strerror' function. */
#define HAVE_GAI_STRERROR 1

/* Define to 1 if you have the `getaddrinfo' function. */
#define HAVE_GETADDRINFO 1

/* Define to 1 if you have the `getenv' function. */
#define HAVE_GETENV 1

/* Define to 1 if you have the `gethostbyname' function. */
#define HAVE_GETHOSTBYNAME 1

/* Define to 1 if you have the `getnameinfo' function. */
#define HAVE_GETNAMEINFO 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* getopt support */
#define HAVE_GETOPT_LONG 1

/* Define to 1 if you have the `getpwuid_r' function. */
#define HAVE_GETPWUID_R 1

/* Define if the GNU gettext() function is already present or preinstalled. */
#undef HAVE_GETTEXT

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the <GL/glu.h> header file. */
#undef HAVE_GL_GLU_H

/* Define to 1 if you have the <GL/glx.h> header file. */
#undef HAVE_GL_GLX_H

/* Define to 1 if you have the <GL/gl.h> header file. */
#undef HAVE_GL_GL_H

/* Define to 1 if you have the `gmtime_r' function. */
#undef HAVE_GMTIME_R

/* Define to 1 if you have the <goom/goom.h> header file. */
#undef HAVE_GOOM_GOOM_H

/* Define to 1 if you have the <Growl/GrowlDefines.h> header file. */
#undef HAVE_GROWL_GROWLDEFINES_H

/* Define if you have the HAL library */
#undef HAVE_HAL

/* Define if you have the iconv() function and it works. */
#define HAVE_ICONV 1

/* Define to 1 if you have the <id3tag.h> header file. */
#define HAVE_ID3TAG_H 1

/* Define to 1 if you have the `if_nametoindex' function. */
#define HAVE_IF_NAMETOINDEX 1

/* Define to 1 if you have the <image.h> header file. */
#undef HAVE_IMAGE_H

/* Define to 1 if you have the `inet_aton' function. */
#define HAVE_INET_ATON 1

/* Define to 1 if you have inet_ntop(). */
#define HAVE_INET_NTOP 1

/* Define to 1 if you have inet_pton(). */
#define HAVE_INET_PTON 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* For FreeBSD VCD support */
#undef HAVE_IOC_TOC_HEADER_IN_SYS_CDIO_H

/* Define to 1 if you have the `isatty' function. */
#define HAVE_ISATTY 1

/* Define to 1 if you have the <jack/jack.h> header file. */
#undef HAVE_JACK_JACK_H

/* Define to 1 if you have the <jpeglib.h> header file. */
#undef HAVE_JPEGLIB_H

/* Define to 1 if you have the <kate/kate.h> header file. */
#undef HAVE_KATE_KATE_H

/* Define to 1 if you have the <kernel/OS.h> header file. */
#undef HAVE_KERNEL_OS_H

/* Define to 1 if you have the <kernel/scheduler.h> header file. */
#undef HAVE_KERNEL_SCHEDULER_H

/* Define if you have <langinfo.h> and nl_langinfo(CODESET). */
#define HAVE_LANGINFO_CODESET 1

/* Define to 1 if you have the <langinfo.h> header file. */
#define HAVE_LANGINFO_H 1

/* Define to 1 if you have the <lauxlib.h> header file. */
#undef HAVE_LAUXLIB_H

/* Define to 1 if you have the <libavc1394/avc1394.h> header file. */
#undef HAVE_LIBAVC1394_AVC1394_H

/* Define to 1 if you have the <libavcodec/avcodec.h> header file. */
#undef HAVE_LIBAVCODEC_AVCODEC_H

/* Define to 1 if you have the <libavformat/avformat.h> header file. */
#undef HAVE_LIBAVFORMAT_AVFORMAT_H

/* Define to 1 if you have the <libavutil/avutil.h> header file. */
#undef HAVE_LIBAVUTIL_AVUTIL_H

/* Define this if you have libcddb installed */
#undef HAVE_LIBCDDB

/* Define if you have libcdio 0.78.2 or greater installed */
#undef HAVE_LIBCDIO

/* Define to 1 if you have the <libdc1394/dc1394_control.h> header file. */
#undef HAVE_LIBDC1394_DC1394_CONTROL_H

/* Define to 1 if you have the <libdvdread/dvd_reader.h> header file. */
#undef HAVE_LIBDVDREAD_DVD_READER_H

/* Define to 1 if you have the `mingw32' library (-lmingw32). */
#undef HAVE_LIBMINGW32

/* Define to 1 if you have the <libmodplug/modplug.h> header file. */
#undef HAVE_LIBMODPLUG_MODPLUG_H

/* Define to 1 if you have the `ncurses' library (-lncurses). */
#undef HAVE_LIBNCURSES

/* Define to 1 if you have the `ncursesw' library (-lncursesw). */
#undef HAVE_LIBNCURSESW

/* Define if you have the PNG library: libpng */
#undef HAVE_LIBPNG

/* Define to 1 if you have the <libpostproc/postproc.h> header file. */
#undef HAVE_LIBPOSTPROC_POSTPROC_H

/* Define to 1 if you have the <libraw1394/raw1394.h> header file. */
#undef HAVE_LIBRAW1394_RAW1394_H

/* Define to 1 if you have the <libsmbclient.h> header file. */
#undef HAVE_LIBSMBCLIENT_H

/* Define to 1 if you have the <libswscale/swscale.h> header file. */
#undef HAVE_LIBSWSCALE_SWSCALE_H

/* Define to 1 if you have the <libtar.h> header file. */
#undef HAVE_LIBTAR_H

/* Define if libv4l is available */
#undef HAVE_LIBV4L2

/* Define to 1 if you have the <linux/dccp.h> header file. */
#undef HAVE_LINUX_DCCP_H

/* Define to 1 if you have the <linux/dvb/frontend.h> header file. */
#undef HAVE_LINUX_DVB_FRONTEND_H

/* Define to 1 if you have the <linux/dvb/version.h> header file. */
#undef HAVE_LINUX_DVB_VERSION_H

/* Define to 1 if you have the <linux/fb.h> header file. */
#undef HAVE_LINUX_FB_H

/* Define to 1 if you have the <linux/version.h> header file. */
#undef HAVE_LINUX_VERSION_H

/* Define to 1 if you have the <linux/videodev2.h> header file. */
#undef HAVE_LINUX_VIDEODEV2_H

/* Define to 1 if you have the <linux/videodev.h> header file. */
#undef HAVE_LINUX_VIDEODEV_H

/* Define to 1 if you have the <liveMedia.hh> header file. */
#undef HAVE_LIVEMEDIA_HH

/* Define to 1 if you have the <liveMedia_version.hh> header file. */
#undef HAVE_LIVEMEDIA_VERSION_HH

/* Define to 1 if you have the `lldiv' function. */
#define HAVE_LLDIV 1

/* Define to 1 if you have the `load_add_on' function. */
#undef HAVE_LOAD_ADD_ON

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the `localtime_r' function. */
#define HAVE_LOCALTIME_R 1
 
/* Define to 1 if you have the `lrintf' function. */
#undef HAVE_LRINTF

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define if you have the lua library */
#undef HAVE_LUA

/* Define to 1 if you have the <lualib.h> header file. */
#undef HAVE_LUALIB_H

/* Define to 1 if you have the <lua.h> header file. */
#undef HAVE_LUA_H

/* Define to 1 if you have the <machine/param.h> header file. */
#define HAVE_MACHINE_PARAM_H 1

/* Define to 1 if you have the <machine/soundcard.h> header file. */
#undef HAVE_MACHINE_SOUNDCARD_H

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
#undef HAVE_MACH_O_DYLD_H

/* Define to 1 if you have the <mad.h> header file. */
#define HAVE_MAD_H 1

/* Define to 1 if you have the <matroska/KaxAttachments.h> header file. */
#undef HAVE_MATROSKA_KAXATTACHMENTS_H

/* Define to 1 if you have the <matroska/KaxVersion.h> header file. */
#undef HAVE_MATROSKA_KAXVERSION_H

/* Define to 1 if you have the `memalign' function. */
#undef HAVE_MEMALIGN

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `mmap' function. */
#define HAVE_MMAP 1

/* Define to 1 if MMX intrinsics are available. */
#undef HAVE_MMX_INTRINSICS

/* Define to 1 if you have the <mozilla-config.h> header file. */
#undef HAVE_MOZILLA_CONFIG_H

/* Define to 1 if you have the <mpcdec/mpcdec.h> header file. */
#undef HAVE_MPCDEC_MPCDEC_H

/* Define if nanosleep is available. */ 
#define HAVE_NANOSLEEP 1

/* Define to 1 if you have libncursesw. */
#undef HAVE_NCURSESW

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <netinet/udplite.h> header file. */
#undef HAVE_NETINET_UDPLITE_H

/* Define to 1 if you have the <net/if.h> header file. */
#define HAVE_NET_IF_H 1

/* Define if new linux/videodev2.h present */
#undef HAVE_NEW_LINUX_VIDEODEV2_H

/* Define to 1 if you have the `nl_langinfo' function. */
#define HAVE_NL_LANGINFO 1

/* Define to 1 if you have the <npapi.h> header file. */
#undef HAVE_NPAPI_H

/* Define to 1 if you have the <npruntime.h> header file. */
#undef HAVE_NPRUNTIME_H

/* Define to 1 if you have the `NSLinkModule' function. */
#undef HAVE_NSLINKMODULE

/* Define to 1 if you have the <objsafe.h> header file. */
#undef HAVE_OBJSAFE_H

/* Define to 1 if you have the <ogg/ogg.h> header file. */
#undef HAVE_OGG_OGG_H

/* Define to 1 if you have the <ole2.h> header file. */
#undef HAVE_OLE2_H

/* Define to 1 if you have the <olectl.h> header file. */
#undef HAVE_OLECTL_H

/* Define to 1 if you have the <OpenGL/gl.h> header file. */
#undef HAVE_OPENGL_GL_H

/* Define to 1 if you have the <Ph.h> header file. */
#undef HAVE_PH_H

/* Define to 1 if you have the <png.h> header file. */
#undef HAVE_PNG_H

/* Define to 1 if the OS is usabl... err, has poll(). */
#undef HAVE_POLL

/* Define to 1 if you have the `posix_fadvise' function. */
#undef HAVE_POSIX_FADVISE

/* Define to 1 if you have the `posix_madvise' function. */
#undef HAVE_POSIX_MADVISE

/* Define to 1 if you have the `posix_memalign' function. */
#undef HAVE_POSIX_MEMALIGN

/* Define to 1 if you have the <postproc/postprocess.h> header file. */
#undef HAVE_POSTPROC_POSTPROCESS_H

/* Define to 1 if you have the <proxy.h> header file. */
#undef HAVE_PROXY_H

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the `pthread_mutex_lock' function. */
#define HAVE_PTHREAD_MUTEX_LOCK 1

/* Define to 1 if you have the `putenv' function. */
#define HAVE_PUTENV 1

/* Define to 1 if you have QT4 library. */
#undef HAVE_QT4

/* Define to 1 if you have the <qt.h> header file. */
#undef HAVE_QT_H

/* Define to 1 if you have the <QuickTime/QuickTime.h> header file. */
#undef HAVE_QUICKTIME_QUICKTIME_H

/* Define to 1 if you have the `scandir' function. */
#undef HAVE_SCANDIR

/* For NetBSD VCD support */
#undef HAVE_SCSIREQ_IN_SYS_SCSIIO_H

/* Define to 1 if you have the <SDL.h> header file. */
#undef HAVE_SDL_H

/* Define to 1 if you have the <SDL_image.h> header file. */
#undef HAVE_SDL_IMAGE_H

/* Define to 1 if you have the `send' function. */
#undef HAVE_SEND

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define if you have the libshout library */
#undef HAVE_SHOUT

/* Define to 1 if you have the <signal.h> header file. */
#undef HAVE_SIGNAL_H

/* Define to 1 if you have the `sigrelse' function. */
#undef HAVE_SIGRELSE

/* Define to 1 if you have the <soundcard.h> header file. */
#undef HAVE_SOUNDCARD_H

/* Define to 1 if you have the <speex/speex.h> header file. */
#undef HAVE_SPEEX_SPEEX_H

/* Define to 1 if SSE2 intrinsics are available. */
#undef HAVE_SSE2_INTRINSICS

/* Define to 1 if you have the <stdbool.h> header file. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strcasestr' function. */
#define HAVE_STRCASESTR 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the `stricmp' function. */
#define HAVE_STRICMP 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `stristr' function. */
#define HAVE_STRISTR 1

/* Define to 1 if you have the `strlcpy' function. */
#define HAVE_STRLCPY 1

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strndup' function. */
#define HAVE_STRNDUP 1

/* Define to 1 if you have the `strnicmp' function. */
#define HAVE_STRNICMP 1

/* Define to 1 if you have the `strnlen' function. */
#define HAVE_STRNLEN 1

/* Define to 1 if you have the `strsep' function. */
#define HAVE_STRSEP define

/* Define to 1 if you have the `strtod' function. */
#define HAVE_STRTOD 1

/* Define to 1 if you have the `strtof' function. */
#define HAVE_STRTOF 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if you have the `strtoull' function. */
#define HAVE_STRTOULL 1

/* Define to 1 if the system has the type `struct addrinfo'. */
#define HAVE_STRUCT_ADDRINFO 1

/* Define if <sys/time.h> defines struct timespec. */
#define HAVE_STRUCT_TIMESPEC 1

/* Define to 1 if you have the `swab' function. */
#define HAVE_SWAB 1

/* Define to 1 if you have the <sysfs/libsysfs.h> header file. */
#undef HAVE_SYSFS_LIBSYSFS_H

/* Define to 1 if you have the <syslog.h> header file. */
#undef HAVE_SYSLOG_H

/* Define to 1 if you have the <sys/dl.h> header file. */
#undef HAVE_SYS_DL_H

/* Define to 1 if you have the <sys/int_types.h> header file. */
#undef HAVE_SYS_INT_TYPES_H

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/shm.h> header file. */
#define HAVE_SYS_SHM_H 1

/* Define to 1 if you have the <sys/sockio.h> header file. */
#define HAVE_SYS_SOCKIO_H 1

/* Define to 1 if you have the <sys/soundcard.h> header file. */
#undef HAVE_SYS_SOUNDCARD_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/times.h> header file. */
#define HAVE_SYS_TIMES_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define if you have taglib plugin built */
#undef HAVE_TAGLIB

/* Define to 1 if you have the <theora/theora.h> header file. */
#undef HAVE_THEORA_THEORA_H

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if you have the <tremor/ivorbiscodec.h> header file. */
#undef HAVE_TREMOR_IVORBISCODEC_H

/* Define to 1 if you have the <twolame.h> header file. */
#undef HAVE_TWOLAME_H

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `uselocale' function. */
#undef HAVE_USELOCALE

/* Define to 1 if you have the `vasprintf' function. */
#define HAVE_VASPRINTF 1

/* Define if <stdarg.h> defines va_copy. */
#define HAVE_VA_COPY 1

/* Define if you have libvcdinfo 0.7.22 or greater installed */
#undef HAVE_VCDINFO

/* Define for the VCD plugin using libcdio/libvcdinfo */
#undef HAVE_VCDX

/* Define to 1 if you have the <vorbis/codec.h> header file. */
#undef HAVE_VORBIS_CODEC_H

/* Define to 1 if you have the <vorbis/vorbisenc.h> header file. */
#undef HAVE_VORBIS_VORBISENC_H

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define to 1 if you have the <X11/extensions/dpms.h> header file. */
#undef HAVE_X11_EXTENSIONS_DPMS_H

/* Define to 1 if you have the <X11/extensions/vldXvMC.h> header file. */
#undef HAVE_X11_EXTENSIONS_VLDXVMC_H

/* Define to 1 if you have the <X11/extensions/xf86vmode.h> header file. */
#undef HAVE_X11_EXTENSIONS_XF86VMODE_H

/* Define to 1 if you have the <X11/extensions/Xinerama.h> header file. */
#undef HAVE_X11_EXTENSIONS_XINERAMA_H

/* Define to 1 if you have the <X11/extensions/Xv.h> header file. */
#undef HAVE_X11_EXTENSIONS_XV_H

/* Define to 1 if you have the <X11/Xlib.h> header file. */
#undef HAVE_X11_XLIB_H

/* Define to 1 if you have the <X11/xpm.h> header file. */
#undef HAVE_X11_XPM_H

/* Define this if you have libXxf86vm installed */
#undef HAVE_XF86VIDMODE

/* Define this if you have libXinerama installed */
#undef HAVE_XINERAMA

/* Define to 1 if you have the <xlocale.h> header file. */
#undef HAVE_XLOCALE_H

/* Define if <xosd.h> is pre-1.0.0 */
#undef HAVE_XOSD_VERSION_0

/* Define if <xosd.h> is 1.0.x */
#undef HAVE_XOSD_VERSION_1

/* Define if <xosd.h> is 2.0.x */
#undef HAVE_XOSD_VERSION_2

/* Define to 1 if you have the <zlib.h> header file. */
#define HAVE_ZLIB_H 1

/* Define if samba has _SMBCCTX.close_fn */
#undef HAVE__SMBCCTX_CLOSE_FN

/* Define if <stdarg.h> defines __va_copy. */
#define HAVE___VA_COPY 1

/* Define as const if the declaration of iconv() needs const. */
#undef ICONV_CONST

/* Dynamic object extension */
#undef LIBEXT

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#undef LT_OBJDIR

/* Define to 1 if debug code should NOT be compiled */
#undef NDEBUG

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
#undef NO_MINUS_C_MINUS_O

/* Define if <sys/param.h> defines ntohl. */
#define NTOHL_IN_SYS_PARAM_H 1

/* Define if you want to optimize memory usage over performance */
#define OPTIMIZE_MEMORY

#define PACKAGE "MHSVLC"

/* Define to the full name of this package. */
#define PACKAGE_NAME "MHSVLC"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "MHSVLC"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "MHSVLC"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.0.0"

/* version minor number */
#define PACKAGE_VERSION_EXTRA "0"

/* version major number */
#define PACKAGE_VERSION_MAJOR "1"

/* version minor number */
#define PACKAGE_VERSION_MINOR "0"

/* version minor number */
#define PACKAGE_VERSION_REVISION "0"

/* Define as the return type of signal handlers (`int' or `void'). */
#undef RETSIGTYPE

/* As a last resort we also test for SDL_image.h presence */
#undef SDL_IMAGE_INCLUDE_FILE

/* As a last resort we also test for SDL.h presence */
#undef SDL_INCLUDE_FILE

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
#define STACK_DIRECTION 1

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define if <strings.h> defines strncasecmp. */
#define STRNCASECMP_IN_STRINGS_H 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define if you want to use the VLC update mechanism */
#undef UPDATE_CHECK

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# undef _ALL_SOURCE
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# undef _GNU_SOURCE
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# undef _POSIX_PTHREAD_SEMANTICS
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# undef _TANDEM_SOURCE
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# undef __EXTENSIONS__
#endif


/* Version number of package */
#define VERSION "1.0.0"

/* Simple version string */
#define VERSION_MESSAGE "MHSVLC"

/* Location of videodev2.h */
#undef VIDEODEV2_H_FILE

#ifdef MHSVLC
//#define MODULE_STRING ""
#define CONFIGURE_LINE ""
#endif

/* compiler */
#define VLC_COMPILER "WINSCW/GCCE"

/* user who ran configure */
#define VLC_COMPILE_BY "MHSVLC"

/* domain of the host which ran configure */
#define VLC_COMPILE_DOMAIN "www.mahaserver.com"

/* host which ran configure */
#define VLC_COMPILE_HOST "admin.mahaserver.com"

#define PATH_MAX 256
#define SYSCONFDIR "c:\\data"
#define DATA_PATH "c:\\data"
//#define _SC_GETPW_R_SIZE_MAX 200

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
#  undef WORDS_BIGENDIAN
# endif
#endif

/* Define to 1 if the X Window System is missing or not being used. */
#define X_DISPLAY_MISSING 1

/* Define if the zvbi module is built */
#undef ZVBI_COMPILED

/* Define to '2' to get glibc warnings. */
#undef _FORTIFY_SOURCE

/* Define to 1 if on MINIX. */
#undef _MINIX

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
#undef _POSIX_1_SOURCE

/* Define to 1 if you need to in order for `stat' and other things to work. */
#undef _POSIX_SOURCE

/* Define to '0x0500' for Windows 2000 APIs. */
#undef _WIN32_WINNT

/* Define to empty if `const' does not conform to ANSI C. */
#undef const

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#undef inline
#endif

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
#undef restrict
/* Work around a bug in Sun C++: it does not support _Restrict, even
   though the corresponding Sun C compiler does, which causes
   "#define restrict _Restrict" in the previous line.  Perhaps some future
   version of Sun C++ will work with _Restrict; if so, it'll probably
   define __RESTRICT, just as Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
#endif

/* Define to `sockaddr' if <sys/socket.h> does not define. */
#undef sockaddr_storage

/* Define to `int' if <sys/socket.h> does not define. */
#undef socklen_t

/* Define to `sa_family' if <sys/socket.h> does not define. */
#undef ss_family

/* Define to `int' if <stddef.h> does not define. */
#undef ssize_t

#include <vlc_fixups.h>
