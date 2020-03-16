/*
 * This is a part of PolyORB-HI-C distribution, a minimal
 * middleware written for generated code from AADL models.
 * You should use it with the Ocarina toolsuite.
 *
 * For more informations, please visit http://taste.tuxfamily.org/wiki
 *
 * Copyright (C) 2007-2009 Telecom ParisTech, 2010-2020 ESA & ISAE.
 */

#ifndef __PO_HI_DEBUG_H__

#include <po_hi_config.h>
#include <po_hi_time.h>


#define __PO_HI_DEBUG_LEVEL_INFO     12
#define __PO_HI_DEBUG_LEVEL_DEBUG    10
#define __PO_HI_DEBUG_LEVEL_WARNING  6
#define __PO_HI_DEBUG_LEVEL_CRITICAL 4
#define __PO_HI_DEBUG_LEVEL_NONE     0

#ifndef __PO_HI_DEBUG_LEVEL
   #define __PO_HI_DEBUG_LEVEL __PO_HI_DEBUG_LEVEL_CRITICAL
#endif


#if __PO_HI_DEBUG_LEVEL > __PO_HI_DEBUG_LEVEL_NONE
   #include <stdio.h>
#endif

/* Some OS do not define stderr, print directly on stdout */
#ifdef AIR_HYPERVISOR
#define __PO_HI_PRINTF(s, args...) printf(s, ##args)
#else
#define __PO_HI_PRINTF(s, args...) fprintf(stderr, s, ##args); fflush(stdout)
#endif

#if __PO_HI_DEBUG_LEVEL >= __PO_HI_DEBUG_LEVEL_CRITICAL
   #define __PO_HI_DEBUG_CRITICAL(s, args...) __PO_HI_PRINTF(s, ##args)
#else
   #define __PO_HI_DEBUG_CRITICAL(s, args...)
#endif

#if __PO_HI_DEBUG_LEVEL >= __PO_HI_DEBUG_LEVEL_WARNING
   #define __PO_HI_DEBUG_WARNING(s, args...) __PO_HI_PRINTF(s, ##args)
#else
   #define __PO_HI_DEBUG_WARNING(s, args...)
#endif

#if __PO_HI_DEBUG_LEVEL >= __PO_HI_DEBUG_LEVEL_DEBUG
   #define __PO_HI_DEBUG_DEBUG(s, args...) __PO_HI_PRINTF(s, ##args)
#else
   #define __PO_HI_DEBUG_DEBUG(s, args...)
#endif

#if __PO_HI_DEBUG_LEVEL >= __PO_HI_DEBUG_LEVEL_INFO
   #define __PO_HI_DEBUG_INFO(s, args...) __PO_HI_PRINTF(s, ##args)
   #define __DEBUGMSG(s, args...) __PO_HI_PRINTF(s, ##args)
#else
   #define __PO_HI_DEBUG_INFO(s, args...)
   #define __DEBUGMSG(s, args...)
#endif

#endif	/* __DEBUG_H__ */
