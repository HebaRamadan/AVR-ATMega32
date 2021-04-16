/*
 * WDT.Private.h
 *
 *  Created on: Dec 21, 2020
 *      Author: zas
 */

#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define WDTCR   (*(volatile u8 *)0x41)

#define WDTOE  	4
#define WDE 	3
#define WDP2 	2
#define WDP1 	1
#define WDP0	0


#endif /* WDT_PRIVATE_H_ */
