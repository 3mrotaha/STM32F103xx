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


#endif /* LIB_MATH_H_ */
