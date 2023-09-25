#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/STM32F103xx.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/RCC/RCC_config.h"
#include "../../../Inc/MCAL/RCC/RCC_interface.h"

#include "../../../Inc/MCAL/GPIO/GPIO_private.h"
#include "../../../Inc/MCAL/GPIO/GPIO_config.h"


void GPIO_vidInit(void){

    uint32_t lockReg;
    // Initializing porta pin configuration & values
#if GPIOA_ENABLE == ENABLE_PORT
    RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTA_ID); // enable clock for GPIOA
    GPIOA_Regs->CRL = _CR_BITS_(
        PORTA_PIN0_MODE, PORTA_PIN0_CONFIG, PORTA_PIN1_MODE, PORTA_PIN1_CONFIG,
        PORTA_PIN2_MODE, PORTA_PIN2_CONFIG, PORTA_PIN3_MODE, PORTA_PIN3_CONFIG,
        PORTA_PIN4_MODE, PORTA_PIN4_CONFIG, PORTA_PIN5_MODE, PORTA_PIN5_CONFIG,
        PORTA_PIN6_MODE, PORTA_PIN6_CONFIG, PORTA_PIN7_MODE, PORTA_PIN7_CONFIG
    ); // collecting the bits of configuration for CRL

    GPIOA_Regs->CRH = _CR_BITS_(
        PORTA_PIN8_MODE, PORTA_PIN8_CONFIG, PORTA_PIN9_MODE, PORTA_PIN9_CONFIG,
        PORTA_PIN10_MODE, PORTA_PIN10_CONFIG, PORTA_PIN11_MODE, PORTA_PIN11_CONFIG,
        PORTA_PIN12_MODE, PORTA_PIN12_CONFIG, PORTA_PIN13_MODE, PORTA_PIN13_CONFIG,
        PORTA_PIN14_MODE, PORTA_PIN14_CONFIG, PORTA_PIN15_MODE, PORTA_PIN15_CONFIG
    ); // collecting the bits of configuration for CRH

    GPIOA_Regs->ODR = _CONCAT_(
        PORTA_PIN0_VALUE, PORTA_PIN1_VALUE, PORTA_PIN2_VALUE, PORTA_PIN3_VALUE,
        PORTA_PIN4_VALUE, PORTA_PIN5_VALUE, PORTA_PIN6_VALUE, PORTA_PIN7_VALUE,
        PORTA_PIN8_VALUE, PORTA_PIN9_VALUE, PORTA_PIN10_VALUE, PORTA_PIN11_VALUE,
        PORTA_PIN12_VALUE, PORTA_PIN13_VALUE, PORTA_PIN14_VALUE, PORTA_PIN15_VALUE
    ); // Configuring the value of output or the state of input (pullup/pulldown)
    // LOCK PORTA PINS
    lockReg = _CONCAT_(
        PORTA_PIN0_LOCK, PORTA_PIN1_LOCK, PORTA_PIN2_LOCK, PORTA_PIN3_LOCK,
        PORTA_PIN4_LOCK, PORTA_PIN5_LOCK, PORTA_PIN6_LOCK, PORTA_PIN7_LOCK,
        PORTA_PIN8_LOCK, PORTA_PIN9_LOCK, PORTA_PIN10_LOCK, PORTA_PIN11_LOCK,
        PORTA_PIN12_LOCK, PORTA_PIN13_LOCK, PORTA_PIN14_LOCK, PORTA_PIN15_LOCK
    ); // collecting the bits corresponding to the pins to be locked
    // locking sequence
    SET_BIT(lockReg, 16);
    GPIOA_Regs->LCKR = lockReg;
    CLEAR_BIT(GPIOA_Regs->LCKR, 16);
    SET_BIT(GPIOA_Regs->LCKR, 16);
    lockReg = GET_BIT(GPIOA_Regs->LCKR, 16);
#endif

#if GPIOB_ENABLE == ENABLE_PORT
    // Initializing portb pin configuration & values
    RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTB_ID);
    GPIOB_Regs->CRL = _CR_BITS_(
        PORTB_PIN0_MODE, PORTB_PIN0_CONFIG, PORTB_PIN1_MODE, PORTB_PIN1_CONFIG,
        PORTB_PIN2_MODE, PORTB_PIN2_CONFIG, PORTB_PIN3_MODE, PORTB_PIN3_CONFIG,
        PORTB_PIN4_MODE, PORTB_PIN4_CONFIG, PORTB_PIN5_MODE, PORTB_PIN5_CONFIG,
        PORTB_PIN6_MODE, PORTB_PIN6_CONFIG, PORTB_PIN7_MODE, PORTB_PIN7_CONFIG
    ); // collecting the bits of configuration for CRL

    GPIOB_Regs->CRH = _CR_BITS_(
        PORTB_PIN8_MODE, PORTB_PIN8_CONFIG, PORTB_PIN9_MODE, PORTB_PIN9_CONFIG,
        PORTB_PIN10_MODE, PORTB_PIN10_CONFIG, PORTB_PIN11_MODE, PORTB_PIN11_CONFIG,
        PORTB_PIN12_MODE, PORTB_PIN12_CONFIG, PORTB_PIN13_MODE, PORTB_PIN13_CONFIG,
        PORTB_PIN14_MODE, PORTB_PIN14_CONFIG, PORTB_PIN15_MODE, PORTB_PIN15_CONFIG
    ); // collecting the bits of configuration for CRH

    GPIOB_Regs->ODR = _CONCAT_(
        PORTB_PIN0_VALUE, PORTB_PIN1_VALUE, PORTB_PIN2_VALUE, PORTB_PIN3_VALUE,
        PORTB_PIN4_VALUE, PORTB_PIN5_VALUE, PORTB_PIN6_VALUE, PORTB_PIN7_VALUE,
        PORTB_PIN8_VALUE, PORTB_PIN9_VALUE, PORTB_PIN10_VALUE, PORTB_PIN11_VALUE,
        PORTB_PIN12_VALUE, PORTB_PIN13_VALUE, PORTB_PIN14_VALUE, PORTB_PIN15_VALUE
    ); // Configuring the value of output or the state of input (pullup/pulldown)
    // LOCK PORTB PINS
    lockReg = _CONCAT_(
        PORTB_PIN0_LOCK, PORTB_PIN1_LOCK, PORTB_PIN2_LOCK, PORTB_PIN3_LOCK,
        PORTB_PIN4_LOCK, PORTB_PIN5_LOCK, PORTB_PIN6_LOCK, PORTB_PIN7_LOCK,
        PORTB_PIN8_LOCK, PORTB_PIN9_LOCK, PORTB_PIN10_LOCK, PORTB_PIN11_LOCK,
        PORTB_PIN12_LOCK, PORTB_PIN13_LOCK, PORTB_PIN14_LOCK, PORTB_PIN15_LOCK
    ); // collecting the bits corresponding to the pins to be locked
    // locking sequence
    SET_BIT(lockReg, 16);
    GPIOB_Regs->LCKR = lockReg;
    CLEAR_BIT(GPIOB_Regs->LCKR, 16);
    SET_BIT(GPIOB_Regs->LCKR, 16);
    lockReg = GET_BIT(GPIOB_Regs->LCKR, 16);
#endif

#if GPIOC_ENABLE == ENABLE_PORT
    // Initializing portc pin configuration & values
    RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTC_ID); /*Clock enable*/
    GPIOC_Regs->CRL = _CR_BITS_(
        PORTC_PIN0_MODE, PORTC_PIN0_CONFIG, PORTC_PIN1_MODE, PORTC_PIN1_CONFIG,
        PORTC_PIN2_MODE, PORTC_PIN2_CONFIG, PORTC_PIN3_MODE, PORTC_PIN3_CONFIG,
        PORTC_PIN4_MODE, PORTC_PIN4_CONFIG, PORTC_PIN5_MODE, PORTC_PIN5_CONFIG,
        PORTC_PIN6_MODE, PORTC_PIN6_CONFIG, PORTC_PIN7_MODE, PORTC_PIN7_CONFIG
    ); // collecting the bits of configuration for CRL

    GPIOC_Regs->CRH = _CR_BITS_(
        PORTC_PIN8_MODE, PORTC_PIN8_CONFIG, PORTC_PIN9_MODE, PORTC_PIN9_CONFIG,
        PORTC_PIN10_MODE, PORTC_PIN10_CONFIG, PORTC_PIN11_MODE, PORTC_PIN11_CONFIG,
        PORTC_PIN12_MODE, PORTC_PIN12_CONFIG, PORTC_PIN13_MODE, PORTC_PIN13_CONFIG,
        PORTC_PIN14_MODE, PORTC_PIN14_CONFIG, PORTC_PIN15_MODE, PORTC_PIN15_CONFIG
    ); // collecting the bits of configuration for CRH

    GPIOC_Regs->ODR = _CONCAT_(
        PORTC_PIN0_VALUE, PORTC_PIN1_VALUE, PORTC_PIN2_VALUE, PORTC_PIN3_VALUE,
        PORTC_PIN4_VALUE, PORTC_PIN5_VALUE, PORTC_PIN6_VALUE, PORTC_PIN7_VALUE,
        PORTC_PIN8_VALUE, PORTC_PIN9_VALUE, PORTC_PIN10_VALUE, PORTC_PIN11_VALUE,
        PORTC_PIN12_VALUE, PORTC_PIN13_VALUE, PORTC_PIN14_VALUE, PORTC_PIN15_VALUE
    ); // Configuring the value of output or the state of input (pullup/pulldown)
    // LOCK PORTC PINS
    lockReg = _CONCAT_(
        PORTC_PIN0_LOCK, PORTC_PIN1_LOCK, PORTC_PIN2_LOCK, PORTC_PIN3_LOCK,
        PORTC_PIN4_LOCK, PORTC_PIN5_LOCK, PORTC_PIN6_LOCK, PORTC_PIN7_LOCK,
        PORTC_PIN8_LOCK, PORTC_PIN9_LOCK, PORTC_PIN10_LOCK, PORTC_PIN11_LOCK,
        PORTC_PIN12_LOCK, PORTC_PIN13_LOCK, PORTC_PIN14_LOCK, PORTC_PIN15_LOCK
    ); // collecting the bits corresponding to the pins to be locked
    // locking sequence
    SET_BIT(lockReg, 16);
    GPIOC_Regs->LCKR = lockReg;
    CLEAR_BIT(GPIOC_Regs->LCKR, 16);
    SET_BIT(GPIOC_Regs->LCKR, 16);
    lockReg = GET_BIT(GPIOC_Regs->LCKR, 16);
#endif

#if GPIOD_ENABLE == ENABLE_PORT
    // Initializing portd pin configuration & values                      
    RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTD_ID); /*Clock enable*/
    GPIOD_Regs->CRL = _CR_BITS_(
        PORTD_PIN0_MODE, PORTD_PIN0_CONFIG, PORTD_PIN1_MODE, PORTD_PIN1_CONFIG,
        PORTD_PIN2_MODE, PORTD_PIN2_CONFIG, PORTD_PIN3_MODE, PORTD_PIN3_CONFIG,
        PORTD_PIN4_MODE, PORTD_PIN4_CONFIG, PORTD_PIN5_MODE, PORTD_PIN5_CONFIG,
        PORTD_PIN6_MODE, PORTD_PIN6_CONFIG, PORTD_PIN7_MODE, PORTD_PIN7_CONFIG
    ); // collecting the bits of configuration for CRL

    GPIOD_Regs->CRH = _CR_BITS_(
        PORTD_PIN8_MODE, PORTD_PIN8_CONFIG, PORTD_PIN9_MODE, PORTD_PIN9_CONFIG,
        PORTD_PIN10_MODE, PORTD_PIN10_CONFIG, PORTD_PIN11_MODE, PORTD_PIN11_CONFIG,
        PORTD_PIN12_MODE, PORTD_PIN12_CONFIG, PORTD_PIN13_MODE, PORTD_PIN13_CONFIG,
        PORTD_PIN14_MODE, PORTD_PIN14_CONFIG, PORTD_PIN15_MODE, PORTD_PIN15_CONFIG
    ); // collecting the bits of configuration for CRH

    GPIOD_Regs->ODR = _CONCAT_(
        PORTC_PIN0_VALUE, PORTD_PIN1_VALUE, PORTD_PIN2_VALUE, PORTD_PIN3_VALUE,
        PORTD_PIN4_VALUE, PORTD_PIN5_VALUE, PORTD_PIN6_VALUE, PORTD_PIN7_VALUE,
        PORTD_PIN8_VALUE, PORTD_PIN9_VALUE, PORTD_PIN10_VALUE, PORTD_PIN11_VALUE,
        PORTD_PIN12_VALUE, PORTD_PIN13_VALUE, PORTD_PIN14_VALUE, PORTD_PIN15_VALUE
    ); // Configuring the value of output or the state of input (pullup/pulldown)
    // LOCK PORTD PINS
    lockReg = _CONCAT_(
        PORTD_PIN0_LOCK, PORTD_PIN1_LOCK, PORTD_PIN2_LOCK, PORTD_PIN3_LOCK,
        PORTD_PIN4_LOCK, PORTD_PIN5_LOCK, PORTD_PIN6_LOCK, PORTD_PIN7_LOCK,
        PORTD_PIN8_LOCK, PORTD_PIN9_LOCK, PORTD_PIN10_LOCK, PORTD_PIN11_LOCK,
        PORTD_PIN12_LOCK, PORTD_PIN13_LOCK, PORTD_PIN14_LOCK, PORTD_PIN15_LOCK
    ); // collecting the bits corresponding to the pins to be locked
    // locking sequence
    SET_BIT(lockReg, 16);
    GPIOD_Regs->LCKR = lockReg;
    CLEAR_BIT(GPIOD_Regs->LCKR, 16);
    SET_BIT(GPIOD_Regs->LCKR, 16);
    lockReg = GET_BIT(GPIOD_Regs->LCKR, 16);
#endif

#if GPIOE_ENABLE == ENABLE_PORT
    // Initializing porte pin configuration & values          
    RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTE_ID); /*Clock enable for portE*/
    GPIOE_Regs->CRL = _CR_BITS_(
        PORTE_PIN0_MODE, PORTE_PIN0_CONFIG, PORTE_PIN1_MODE, PORTE_PIN1_CONFIG,
        PORTE_PIN2_MODE, PORTE_PIN2_CONFIG, PORTE_PIN3_MODE, PORTE_PIN3_CONFIG,
        PORTE_PIN4_MODE, PORTE_PIN4_CONFIG, PORTE_PIN5_MODE, PORTE_PIN5_CONFIG,
        PORTE_PIN6_MODE, PORTE_PIN6_CONFIG, PORTE_PIN7_MODE, PORTE_PIN7_CONFIG
    ); // collecting the bits of configuration for CRL

    GPIOE_Regs->CRH = _CR_BITS_(
        PORTE_PIN8_MODE, PORTE_PIN8_CONFIG, PORTE_PIN9_MODE, PORTE_PIN9_CONFIG,
        PORTE_PIN10_MODE, PORTE_PIN10_CONFIG, PORTE_PIN11_MODE, PORTE_PIN11_CONFIG,
        PORTE_PIN12_MODE, PORTE_PIN12_CONFIG, PORTE_PIN13_MODE, PORTE_PIN13_CONFIG,
        PORTE_PIN14_MODE, PORTE_PIN14_CONFIG, PORTE_PIN15_MODE, PORTE_PIN15_CONFIG
    ); // collecting the bits of configuration for CRH

    GPIOE_Regs->ODR = _CONCAT_(
        PORTE_PIN0_VALUE, PORTE_PIN1_VALUE, PORTE_PIN2_VALUE, PORTE_PIN3_VALUE,
        PORTE_PIN4_VALUE, PORTE_PIN5_VALUE, PORTE_PIN6_VALUE, PORTE_PIN7_VALUE,
        PORTE_PIN8_VALUE, PORTE_PIN9_VALUE, PORTE_PIN10_VALUE, PORTE_PIN11_VALUE,
        PORTE_PIN12_VALUE, PORTE_PIN13_VALUE, PORTE_PIN14_VALUE, PORTE_PIN15_VALUE
    ); // Configuring the value of output or the state of input (pullup/pulldown)
    // LOCK PORTE PINS
    lockReg = _CONCAT_(
        PORTE_PIN0_LOCK, PORTE_PIN1_LOCK, PORTE_PIN2_LOCK, PORTE_PIN3_LOCK,
        PORTE_PIN4_LOCK, PORTE_PIN5_LOCK, PORTE_PIN6_LOCK, PORTE_PIN7_LOCK,
        PORTE_PIN8_LOCK, PORTE_PIN9_LOCK, PORTE_PIN10_LOCK, PORTE_PIN11_LOCK,
        PORTE_PIN12_LOCK, PORTE_PIN13_LOCK, PORTE_PIN14_LOCK, PORTE_PIN15_LOCK
    ); // collecting the bits corresponding to the pins to be locked
    // locking sequence    
    SET_BIT(lockReg, 16);
    GPIOE_Regs->LCKR = lockReg;
    CLEAR_BIT(GPIOE_Regs->LCKR, 16);
    SET_BIT(GPIOE_Regs->LCKR, 16);
    lockReg = GET_BIT(GPIOE_Regs->LCKR, 16);
#endif
}

ErrorStates_t GPIO_enuSetPinConfiguration(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId, GPIO_PinConfig_t* Copy_pstPinConfig){
    if(Copy_pstPinConfig != NULL){
        if((Copy_u8PortId >= _GPIO_PORTA_ && Copy_u8PortId <= _GPIO_PORTE_) && (Copy_u8PinId >= _GPIO_PIN_0_ && Copy_u8PinId <= _GPIO_PIN_15_)){            
            switch(Copy_u8PortId){
                case _GPIO_PORTA_:                             
                    if(Copy_u8PinId < _GPIO_PIN_8_){
                        // clear the bits to be changed
                        GPIOA_Regs->CRL &= ~(0xfUL << (Copy_u8PinId * 4));
                        // set the configuration value to the configuration register low
                        GPIOA_Regs->CRL |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << (Copy_u8PinId * 4));
                    }else{
                        // clear the bits to be changed
                        GPIOA_Regs->CRH &= ~(0xfUL << ((Copy_u8PinId - 8) * 4));
                        // set the configuration value to the configuration register high
                        GPIOA_Regs->CRH |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << ((Copy_u8PinId - 8) * 4));
                    }
                    // set the pin value or the input type (pull up/down)
                    CLEAR_BIT(GPIOA_Regs->ODR, Copy_u8PinId); // clear position
                    GPIOA_Regs->ODR |= (Copy_pstPinConfig->value << Copy_u8PinId);
                break;
                case _GPIO_PORTB_:
                    if(Copy_u8PinId < _GPIO_PIN_8_){
                        // clear the bits to be changed
                        GPIOB_Regs->CRL &= ~(0xfUL << (Copy_u8PinId * 4));
                        // set the configuration value to the configuration register low
                        GPIOB_Regs->CRL |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << (Copy_u8PinId * 4));
                    }else{
                        // clear the bits to be changed
                        GPIOB_Regs->CRH &= ~(0xfUL << ((Copy_u8PinId - 8) * 4));
                        // set the configuration value to the configuration register high
                        GPIOB_Regs->CRH |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << ((Copy_u8PinId - 8) * 4));
                    }
                    // set the pin value or the input type (pull up/down)
                    CLEAR_BIT(GPIOB_Regs->ODR, Copy_u8PinId); // clear position
                    GPIOB_Regs->ODR |= (Copy_pstPinConfig->value << Copy_u8PinId);
                break;
                case _GPIO_PORTC_:
                    if(Copy_u8PinId < _GPIO_PIN_8_){
                        // clear the bits to be changed
                        GPIOC_Regs->CRL &= ~(0xfUL << (Copy_u8PinId * 4));
                        // set the configuration value to the configuration register low
                        GPIOC_Regs->CRL |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << (Copy_u8PinId * 4));
                    }else{
                        // clear the bits to be changed
                        GPIOC_Regs->CRH &= ~(0xfUL << ((Copy_u8PinId - 8) * 4));
                        // set the configuration value to the configuration register high
                        GPIOC_Regs->CRH |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << ((Copy_u8PinId - 8) * 4));
                    }
                    // set the pin value or the input type (pull up/down)
                    CLEAR_BIT(GPIOC_Regs->ODR, Copy_u8PinId); // clear position
                    GPIOC_Regs->ODR |= (Copy_pstPinConfig->value << Copy_u8PinId);                
                break;                                
                case _GPIO_PORTD_:
                    if(Copy_u8PinId < _GPIO_PIN_8_){
                        // clear the bits to be changed
                        GPIOD_Regs->CRL &= ~(0xfUL << (Copy_u8PinId * 4));
                        // set the configuration value to the configuration register low
                        GPIOD_Regs->CRL |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << (Copy_u8PinId * 4));
                    }else{
                        // clear the bits to be changed
                        GPIOD_Regs->CRH &= ~(0xfUL << ((Copy_u8PinId - 8) * 4));
                        // set the configuration value to the configuration register high
                        GPIOD_Regs->CRH |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << ((Copy_u8PinId - 8) * 4));
                    }
                    // set the pin value or the input type (pull up/down)
                    CLEAR_BIT(GPIOD_Regs->ODR, Copy_u8PinId); // clear position
                    GPIOD_Regs->ODR |= (Copy_pstPinConfig->value << Copy_u8PinId);                        
                break;
                case _GPIO_PORTE_:
                    if(Copy_u8PinId < _GPIO_PIN_8_){
                        // clear the bits to be changed
                        GPIOE_Regs->CRL &= ~(0xfUL << (Copy_u8PinId * 4));
                        // set the configuration value to the configuration register low
                        GPIOE_Regs->CRL |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << (Copy_u8PinId * 4));
                    }else{
                        // clear the bits to be changed
                        GPIOE_Regs->CRH &= ~(0xfUL << ((Copy_u8PinId - 8) * 4));
                        // set the configuration value to the configuration register high
                        GPIOE_Regs->CRH |= ((Copy_pstPinConfig->mode | (Copy_pstPinConfig->config << 2)) << ((Copy_u8PinId - 8) * 4));
                    }
                    // set the pin value or the input type (pull up/down)
                    CLEAR_BIT(GPIOE_Regs->ODR, Copy_u8PinId); // clear position
                    GPIOE_Regs->ODR |= (Copy_pstPinConfig->value << Copy_u8PinId);                        
                break;
                default:
                    return ES_NOK;                             
            }
            return ES_OK;
        }else{
            return ES_OUT_OF_RANGE;
        }
    }else{
        return ES_NULL_POINTER;
    }
}

ErrorStates_t GPIO_enuSetPinValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId, uint8_t Copy_u8PinValue){
    if((Copy_u8PortId >= _GPIO_PORTA_ && Copy_u8PortId <= _GPIO_PORTE_) && (Copy_u8PinId >= _GPIO_PIN_0_ && Copy_u8PinId <= _GPIO_PIN_15_)){
        if(Copy_u8PinValue == _LOW_ || Copy_u8PinValue == _HIGH_){
            switch(Copy_u8PortId){
                case _GPIO_PORTA_:
                    // clear bit
                    GPIOA_Regs->ODR &= ~(BIT_MASK << Copy_u8PinId);
                    // set the bit to the given value
                    GPIOA_Regs->ODR |= (Copy_u8PinValue << Copy_u8PinId);
                break;
                case _GPIO_PORTB_:
                    // clear bit
                    GPIOB_Regs->ODR &= ~(BIT_MASK << Copy_u8PinId);
                    // set the bit to the given value
                    GPIOB_Regs->ODR |= (Copy_u8PinValue << Copy_u8PinId);                
                break;
                case _GPIO_PORTC_:
                    // clear bit
                    GPIOC_Regs->ODR &= ~(BIT_MASK << Copy_u8PinId);
                    // set the bit to the given value
                    GPIOC_Regs->ODR |= (Copy_u8PinValue << Copy_u8PinId);                
                break;
                case _GPIO_PORTD_:
                    // clear bit
                    GPIOD_Regs->ODR &= ~(BIT_MASK << Copy_u8PinId);
                    // set the bit to the given value
                    GPIOD_Regs->ODR |= (Copy_u8PinValue << Copy_u8PinId);                
                break;
                case _GPIO_PORTE_:
                    // clear bit
                    GPIOE_Regs->ODR &= ~(BIT_MASK << Copy_u8PinId);
                    // set the bit to the given value
                    GPIOE_Regs->ODR |= (Copy_u8PinValue << Copy_u8PinId);                
                break;
                default:
                    return ES_NOK;
            }
            return ES_OK;
        }else{
            return ES_NOK;
        }
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t GPIO_enuGetPinValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId, uint8_t *Copy_pu8PinValue){
    if(Copy_pu8PinValue != NULL){
        if((Copy_u8PortId >= _GPIO_PORTA_ && Copy_u8PortId <= _GPIO_PORTE_) && (Copy_u8PinId >= _GPIO_PIN_0_ && Copy_u8PinId <= _GPIO_PIN_15_)){
            switch(Copy_u8PortId){
                case _GPIO_PORTA_:
                    *Copy_pu8PinValue = GET_BIT(GPIOA_Regs->IDR, Copy_u8PinId);
                break;
                case _GPIO_PORTB_:
                    *Copy_pu8PinValue = GET_BIT(GPIOB_Regs->IDR, Copy_u8PinId);
                break;
                case _GPIO_PORTC_:
                    *Copy_pu8PinValue = GET_BIT(GPIOC_Regs->IDR, Copy_u8PinId);
                break;
                case _GPIO_PORTD_:
                    *Copy_pu8PinValue = GET_BIT(GPIOD_Regs->IDR, Copy_u8PinId);
                break;
                case _GPIO_PORTE_:
                    *Copy_pu8PinValue = GET_BIT(GPIOE_Regs->IDR, Copy_u8PinId);
                break;
                default:
                    return ES_NOK;
            }
            return ES_OK;
    }else{
            return ES_OUT_OF_RANGE;
        }
    }else{
        return ES_NULL_POINTER;
    }
}

ErrorStates_t GPIO_enuTogglePinValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId){
    if((Copy_u8PortId >= _GPIO_PORTA_ && Copy_u8PortId <= _GPIO_PORTE_) && (Copy_u8PinId >= _GPIO_PIN_0_ && Copy_u8PinId <= _GPIO_PIN_15_)){
        switch(Copy_u8PortId){
            case _GPIO_PORTA_:
                // toggle bit
                GPIOA_Regs->ODR ^= (BIT_MASK << Copy_u8PinId);
            break;
            case _GPIO_PORTB_:
                // toggle bit
                GPIOB_Regs->ODR ^= (BIT_MASK << Copy_u8PinId);                
            break;
            case _GPIO_PORTC_:
                // toggle bit
                GPIOC_Regs->ODR ^= (BIT_MASK << Copy_u8PinId);                
            break;
            case _GPIO_PORTD_:
                // toggle bit
                GPIOD_Regs->ODR ^= (BIT_MASK << Copy_u8PinId);                
            break;
            case _GPIO_PORTE_:
                // toggle bit
                GPIOE_Regs->ODR ^= (BIT_MASK << Copy_u8PinId);                
            break;
            default:
                return ES_NOK;
        }
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t GPIO_enuSetPortValue(uint8_t Copy_u8PortId, uint16_t Copy_u16PortValue){
    if(Copy_u8PortId >= _GPIO_PORTA_ && Copy_u8PortId <= _GPIO_PORTE_){
        if(Copy_u16PortValue <= 0xffffffff){
            switch(Copy_u8PortId){
                case _GPIO_PORTA_:
                    GPIOA_Regs->ODR = Copy_u16PortValue;
                break;
                case _GPIO_PORTB_:
                    GPIOB_Regs->ODR = Copy_u16PortValue;
                break;
                case _GPIO_PORTC_:
                    GPIOC_Regs->ODR = Copy_u16PortValue;
                break;
                case _GPIO_PORTD_:
                    GPIOD_Regs->ODR = Copy_u16PortValue;
                break;
                case _GPIO_PORTE_:
                    GPIOE_Regs->ODR = Copy_u16PortValue;
                break;
                default:
                    return ES_NOK;
            }
            return ES_OK;
        }else{
            return ES_NOK;
        }
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t GPIO_enuGetPortValue(uint8_t Copy_u8PortId, uint16_t *Copy_pu16PortValue){
    if(Copy_pu16PortValue != NULL){
        if((Copy_u8PortId >= _GPIO_PORTA_ && Copy_u8PortId <= _GPIO_PORTE_)){
            switch(Copy_u8PortId){
                case _GPIO_PORTA_:
                    *Copy_pu16PortValue = GPIOA_Regs->IDR;
                break;
                case _GPIO_PORTB_:
                    *Copy_pu16PortValue = GPIOB_Regs->IDR;
                break;
                case _GPIO_PORTC_:
                    *Copy_pu16PortValue = GPIOC_Regs->IDR;
                break;
                case _GPIO_PORTD_:
                    *Copy_pu16PortValue = GPIOD_Regs->IDR;
                break;
                case _GPIO_PORTE_:
                    *Copy_pu16PortValue = GPIOE_Regs->IDR;
                break;
                default:
                    return ES_NOK;
            }
            return ES_OK;
        }else{
            return ES_OUT_OF_RANGE;
        }
    }else{
        return ES_NULL_POINTER;
    }
}

ErrorStates_t GPIO_enuLockPin(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId){
    if((Copy_u8PortId >= _GPIO_PORTA_ && Copy_u8PortId <= _GPIO_PORTE_) && (Copy_u8PinId >= _GPIO_PIN_0_ && Copy_u8PinId <= _GPIO_PIN_15_)){
        volatile ST_GPIO_Regs *tempRegs;
        // set the address of the selected port to the temp
        switch(Copy_u8PortId){
            case _GPIO_PORTA_:
                tempRegs = GPIOA_Regs;
            break;
            case _GPIO_PORTB_:
                tempRegs = GPIOB_Regs;
            break;
            case _GPIO_PORTC_:
                tempRegs = GPIOC_Regs;
            break;
            case _GPIO_PORTD_:
                tempRegs = GPIOD_Regs;
            break;
            case _GPIO_PORTE_:
                tempRegs = GPIOE_Regs;
            break;
            default:
                return ES_NOK;
        }
        // perform the locking using the locking sequence
        tempRegs->LCKR |= (1 << Copy_u8PinId);
        tempRegs->LCKR |= (1 << 16); // set the lock bit
        tempRegs->LCKR &= ~(1 << 16); // clear the lock bit
        tempRegs->LCKR |= (1 << 16); // set the lock bit
        uint16_t tempVal = tempRegs->LCKR; // read the lock register        
        
        if(!(tempRegs->LCKR >> 16)) // if it reads 0
            return ES_NOK; // locking error happened
        return ES_OK; // return ok if it reads 1, locking successful
    }else{
        return ES_OUT_OF_RANGE;
    }    
}
