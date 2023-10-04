/*
 * SEVSEG_private.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_SEVEN_SEGMENT_SEVSEG_PRIVATE_H_
#define HAL_SEVEN_SEGMENT_SEVSEG_PRIVATE_H_

#define _COM_CATHODE_   0
#define _COM_ANODE_     1
#define _DOT_ENABLED_   1
#define _DOT_DISABLED_   0
#define _COM_CONNECTED_  11
#define _COM_DISCONNECTED_  12
// seven-segment values
#define SEVEN_SEGMENT_VALUES    { \
    0x3f,\
    0x06,\
    0x5B,\
    0x4F,\
    0x66,\
    0x6D,\
    0x7D,\
    0x07,\
    0x7F,\
    0x67,\
}   
// g, f, e, d, c, b, a
// 0  1  1  1  1  1  1  -> 0x3f
// 0  0  0  0  1  1  0  -> 0x06
// 1  0  1  1  0  1  1  -> 0x5B
// 1  0  0  1  1  1  1  -> 0x4F
// 1  1  0  0  1  1  0  -> 0x66
// 1  1  0  1  1  0  1  -> 0x6D
// 1  1  1  1  1  0  1  -> 0x7D
// 0  0  0  0  1  1  1  -> 0x07
// 1  1  1  1  1  1  1  -> 0x7F
// 1  1  0  0  1  1  1  -> 0x67

//  ----a---  
// |        | 
// f        b 
// |        | 
//  ----g---- 
// |        | 
// e        c 
// |        | 
//  ----d---  
#endif /* HAL_SEVEN_SEGMENT_SEVSEG_PRIVATE_H_ */
