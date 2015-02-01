/**************************************************************************/
/*!
    @file     PCF8574.h
    @author  PLF (PACABOT)
    @date
    @version  0.0

    Driver for expander PCF8574
 */
/**************************************************************************/
#ifndef __PCF8574_H__
#define __PCF8574_H__

#include "stdbool.h"

void Expander_Led_State(char led, char val);

void ExpanderSetbit(char pin, char val);
char ExpanderGetbit(char pin);
void ExpanderReset(void);

#endif
