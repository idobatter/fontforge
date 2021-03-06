/* Copyright (C) 2013 by Ben Martin */
/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.

 * The name of the author may not be used to endorse or promote products
 * derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ALREADY_INCLUDED_GNETWORK_H_
#define _ALREADY_INCLUDED_GNETWORK_H_

#include <fontforge-config.h>

#define IPADDRESS_STRING_LENGTH_T 100

/**
 * Get a string that describes this host. It may be something
 * like "foobar" if the user has decided to call their laptop that name.
 * So you might not be able to resolve the returned hostname on a remote
 * computer. Data is copied to outstring and outstring is returned.
 */
char* ff_gethostname( char* outstring, int outstring_sz );


/**
 * Get the network accessible IP address of the local machine.
 *
 * If the machine is multihomed you had better hope that traffic
 * from the network can reach all NICs on the host.
 *
 * The output is copied to outstring which is assumed to be
 * at least ipaddress_string_length_t bytes long. The outstring is
 * also returned.
 */
extern char* getNetworkAddress( char* outstring );

extern char* HostPortPack( char* hostname, int port );
extern char* HostPortUnpack( char* packed, int* port, int port_default );

/**
 * generate a new uuid and stringify it into the target area provided
 * after the call target should contain something like
 * 1b4e28ba-2fa1-11d2-883f-0016d3cca427
 * with the trailing null. Before the call target needs to be at least
 * strlen(1b4e28ba-2fa1-11d2-883f-0016d3cca427) + 1 bytes long.
 * 40 bytes is a good length for target.
 * the 'target' is also the return value.
 */
char* ff_uuid_generate( char* target );

#endif
