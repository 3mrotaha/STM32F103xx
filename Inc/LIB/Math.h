/*
 * Math.h
 *
 *  Created on: Sep 17, 2023
 *      Author: amrmo
 */

#ifndef LIB_MATH_H_
#define LIB_MATH_H_


#define SET_BIT(Reg, b_num)		Reg |= 1 << b_num

#define CLEAR_BIT(Reg, b_num)	Reg &= ~(1 << b_num)

#define TOGGLE_BIT(Reg, b_num)	Reg ^= 1 << b_num

#define GET_BIT(Reg, b_num)		((Reg >> b_num) & 1)

#define _CONCAT_H_(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15) 0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0
#define _CONCAT_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) _CONCAT_H_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)


#endif /* LIB_MATH_H_ */
