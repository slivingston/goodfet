/* SCL; 8 Jul 2015 */

#ifndef STROBE_H
#define STROBE_H

#include "app.h"

#define STROBE 0x33


//Command codes
#define STROBE_PATTERN 0x81
#define STROBE_ALLHI   0x82
#define STROBE_ALLLO   0x83


extern app_t const strobe_app;

#endif // STROBE_H
