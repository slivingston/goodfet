/* -*- mode: c; c-basic-offset: 8; indent-tabs-mode: t -*- */
/* SCL; 8 Jul 2015 */

#include "platform.h"
#include "command.h"

#include "strobe.h"

void strobe_handle_fn( uint8_t const app,
					   uint8_t const verb,
					   uint32_t const len );

app_t const strobe_app = {

		/* app number */
		STROBE,

		/* handle fn */
		strobe_handle_fn,

		/* name */
		"STROBE",

		/* desc */
		"\tThe STROBE app provides routines for square waves\n"
		"\tfrom the breakout GPIO leads.\n"
};


void strobe_handle_fn( uint8_t const app,
					   uint8_t const verb,
					   uint32_t const len )
{
		unsigned char i;
		int j;
		P4DIR = 0xff;
		switch (verb) {

		case STROBE_ALLHI:
				P4OUT = 0xff;
				txdata( app, verb, 0 );
				break;

		case STROBE_ALLLO:
				P4OUT = 0;
				txdata( app, verb, 0 );
				break;

		case STROBE_PATTERN:
				prep_timer();
				for (i = 0; i < *(cmddata+1); i++) {
						for (j = 0; j < len-2; j++) {
								P4OUT = *(cmddata+2+j);
								delay_ms( 10*(*cmddata) );
						}
				}
				txdata( app, verb, 0 );
				break;

		default:
				debugstr( "Verb unimplemented in STROBE application." );
				txdata( app, NOK, 0 );
				break;

		}
}
