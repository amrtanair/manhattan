//==============================================================================
// Brief   : Standard C definitions
// Authors : Carlos Guimaraes <cguimaraes@av.it.pt>
//------------------------------------------------------------------------------
// ODTONE - Open Dot Twenty One
//
// Copyright (C) 2009-2012 Universidade Aveiro
// Copyright (C) 2009-2012 Instituto de Telecomunicações - Pólo Aveiro
//
// This software is distributed under a license. The full license
// agreement can be found in the file LICENSE in this distribution.
// This software may not be copied, modified, sold or distributed
// other than expressed in the named license agreement.
//
// This software is distributed without any warranty.
//==============================================================================

/*
 * Copyright (c) 1995 RadioMail Corporation.  All rights reserved.
 * Copyright (c) 2004,2009 by Internet Systems Consortium, Inc. ("ISC")
 * Copyright (c) 1996-2003 by Internet Software Consortium
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 *   Internet Systems Consortium, Inc.
 *   950 Charter Street
 *   Redwood City, CA 94063
 *   <info@isc.org>
 *   https://www.isc.org/
 *
 * This software was written for RadioMail Corporation by Ted Lemon
 * under a contract with Vixie Enterprises.   Further modifications have
 * been made for Internet Systems Consortium under a contract
 * with Vixie Laboratories.
 */

#if !defined (__ISC_DHCP_CDEFS_H__)
#define __ISC_DHCP_CDEFS_H__
/* Delete attributes if not gcc or not the right version of gcc. */
#if !defined(__GNUC__) || __GNUC__ < 2 || \
        (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || defined (darwin)
#define __attribute__(x)
#endif

#if (defined (__GNUC__) || defined (__STDC__)) && !defined (BROKEN_ANSI)
#define PROTO(x)	x
#define KandR(x)
#define ANSI_DECL(x)	x
#if defined (__GNUC__)
#define INLINE		inline
#else
#define INLINE
#endif /* __GNUC__ */
#else
#define PROTO(x)	()
#define KandR(x)	x
#define ANSI_DECL(x)
#define INLINE
#endif /* __GNUC__ || __STDC__ */

/* The following macro handles the case of unwanted return values.  In
 * GCC one can specify an attribute for a function to generate a warning
 * if the return value of the function is ignored and one can't dispose of
 * the warning by the use of void.  In conjunction with the use of -Werror
 * these warnings prohibit the compilation of the package.  This macro
 * allows us to assign the return value to a variable and then ignore it.
 */
#if !defined(__GNUC__) || (__GNUC__ < 4) || \
	((__GNUC__ == 4) && (__GNUC_MINOR__ < 3))
#define IGNORE_RET(x) (void) x
#else
#define IGNORE_RET(x)			\
	do {				\
		int ignore_return;	\
		ignore_return = x;	\
	} while (0)
#endif

#endif /* __ISC_DHCP_CDEFS_H__ */
