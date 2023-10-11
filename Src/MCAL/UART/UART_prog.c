/*
 * USART_prog.c
 *
 *  Created on: Oct 4, 2023
 *      Author: amrmo
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Math.h"
#include "../../../Inc/LIB/Error_States.h"

#include "../../../Inc/MCAL/RCC/RCC_interface.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../../../Inc/MCAL/AFIO/AFIO_interface.h"
#include "../../../Inc/MCAL/NVIC/NVIC_interface.h"

#include "../../../Inc/MCAL/UART/UART_private.h"
#include "../../../Inc/MCAL/UART/UART_config.h"

static volatile void (*UART1_InterruptHandlers[9]) (void*) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
static volatile void* UART1_InterruptParameters[9] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

static volatile void (*UART2_InterruptHandlers[9]) (void*) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
static volatile void* UART2_InterruptParameters[9] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

static volatile void (*UART3_InterruptHandlers[9]) (void*) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
static volatile void* UART3_InterruptParameters[9] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

ErrorStates_t UART_enuInit(uint8_t Copy_u8UartId){
    volatile ST_UART_Regs_t *UARTx_Regs;
    uint32_t UartClk;
    switch (Copy_u8UartId){
        case _UART_1_:
            // enable uart 1 clock
            RCC_enuEnablePeripheralClock(APB_2_ID, UART_1_ID);
            // remap uart 1
            AFIO_enuUartMap(_UART_1_, SET_UART1_REMAP);
            // get uart 1 registers base address
            UARTx_Regs = UART1_Regs;
            // enable uart 
            SET_BIT(UARTx_Regs->CR[0], 13);
            // uart word length
            UARTx_Regs->CR[0] |= (SET_UART1_WORD_LENGTH << 12);
            // uart parity control
            UARTx_Regs->CR[0] |= (SET_UART1_PARITY << 9);
            // stop bits
            UARTx_Regs->CR[1] |= (SET_UART1_STOP_BITS << 12);
            // flow control
            UARTx_Regs->CR[2] |= (SET_UART1_FLOW_CONTROL << 8);
            // get uart 1 clock frequancy
            RCC_enuGetPLCK2(&UartClk);
            // set baudrate
            UARTx_Regs->BRR = UART_BUAD_RATE(UartClk, SET_UART1_BAUDRATE);
            // set send and receive enable
            UARTx_Regs->CR[0] |= (SET_UART1_SEND_RECEIVE_ENABLE << 2);
            // enable uart 1
            SET_BIT(UARTx_Regs->CR[0], 13);
            #if SET_UART3_INTERRUPT == _UART_INT_ENABLE_
                NVIC_enuEnableInterrupt(INT_NUM_37);
            #endif            
            break;
        case _UART_2_:
            // enable uart 1 clock
            RCC_enuEnablePeripheralClock(APB_1_ID, UART_2_ID);
            AFIO_enuUartMap(_UART_2_, SET_UART2_REMAP);
            // get uart 2 registers base address
            UARTx_Regs = UART2_Regs;
            // enable uart 
            SET_BIT(UARTx_Regs->CR[0], 13);
            // uart word length
            UARTx_Regs->CR[0] |= (SET_UART2_WORD_LENGTH << 12);
            // uart parity control
            UARTx_Regs->CR[0] |= (SET_UART2_PARITY << 9);
            // stop bits
            UARTx_Regs->CR[1] |= (SET_UART2_STOP_BITS << 12);
            // flow control
            UARTx_Regs->CR[2] |= (SET_UART2_FLOW_CONTROL << 8);
            // get uart 2 clock frequancy
            RCC_enuGetPLCK1(&UartClk);
            // set baudrate
            UARTx_Regs->BRR = UART_BUAD_RATE(UartClk, SET_UART2_BAUDRATE);
            // set send and receive enable
            UARTx_Regs->CR[0] |= (SET_UART1_SEND_RECEIVE_ENABLE << 2);
            // enable uart 1
            SET_BIT(UARTx_Regs->CR[0], 13);            
            #if SET_UART2_INTERRUPT == _UART_INT_ENABLE_
                NVIC_enuEnableInterrupt(INT_NUM_38);
            #endif
            break;
        case _UART_3_:
            // enable uart 1 clock
            RCC_enuEnablePeripheralClock(APB_1_ID, UART_3_ID);
            AFIO_enuUartMap(_UART_3_, SET_UART3_REMAP);
            // get uart 3 registers base address
            UARTx_Regs = UART3_Regs;
            // enable uart 
            SET_BIT(UARTx_Regs->CR[0], 13);
            // uart send and receive enable
            UARTx_Regs->CR[0] |= (SET_UART3_SEND_RECEIVE_ENABLE << 2);
            // uart word length
            UARTx_Regs->CR[0] |= (SET_UART3_WORD_LENGTH << 12);
            // uart parity control
            UARTx_Regs->CR[0] |= (SET_UART3_PARITY << 9);
            // stop bits
            UARTx_Regs->CR[1] |= (SET_UART3_STOP_BITS << 12);
            // flow control
            UARTx_Regs->CR[2] |= (SET_UART3_FLOW_CONTROL << 8);
            // get uart 1 clock frequancy
            RCC_enuGetPLCK1(&UartClk);
            // set baudrate
            UARTx_Regs->BRR = UART_BUAD_RATE(UartClk, SET_UART3_BAUDRATE);
            // set send and receive enable
            UARTx_Regs->CR[0] |= (SET_UART1_SEND_RECEIVE_ENABLE << 2);
            // enable uart 1
            SET_BIT(UARTx_Regs->CR[0], 13);            
            #if SET_UART3_INTERRUPT == _UART_INT_ENABLE_
                NVIC_enuEnableInterrupt(INT_NUM_39);
            #endif
            break;
        default:
            return ES_OUT_OF_RANGE;
    }

    return ES_OK;
}

ErrorStates_t UART_enuDeInit(uint8_t Copy_u8UartId){
    switch (Copy_u8UartId)
    {
        case _UART_1_:
            // reset uart 1 registers
            RCC_enuResetPeripheral(APB_2_ID, UART_1_ID);
            // disable uart 1 clock
            RCC_enuDisablePeripheralClock(APB_2_ID, UART_1_ID);
            break;
        case _UART_2_:
            // reset uart 2 registers
            RCC_enuResetPeripheral(APB_1_ID, UART_2_ID);
            // disable uart 2 clock
            RCC_enuDisablePeripheralClock(APB_1_ID, UART_2_ID);
            break;
        case _UART_3_:
            // reset uart 3 registers
            RCC_enuResetPeripheral(APB_1_ID, UART_3_ID);
            // disable uart 3 clock
            RCC_enuDisablePeripheralClock(APB_1_ID, UART_3_ID);
            break;
        default:
            return ES_OUT_OF_RANGE;
    }
    return ES_OK;
}

ErrorStates_t UART_enuSetConfiguration(uint8_t Copy_u8UartId, ST_UART_Config_t *Copy_pstUartConfig){
    if(Copy_pstUartConfig != NULL){
        volatile ST_UART_Regs_t *UARTx_Regs;
        uint32_t uartClk;        
        switch (Copy_u8UartId)
        {
            case _UART_1_:
                UARTx_Regs = UART1_Regs;
                AFIO_enuUartMap(_UART_1_, SET_UART1_REMAP);
                RCC_enuEnablePeripheralClock(APB_2_ID, UART_1_ID);
                RCC_enuGetPLCK2(&uartClk);
                if(Copy_pstUartConfig->IRQ_Enable == _UART_INT_ENABLE_){
                    NVIC_enuEnableInterrupt(INT_NUM_37);
                }
                break;
            case _UART_2_:
                UARTx_Regs = UART2_Regs;
                AFIO_enuUartMap(_UART_2_, SET_UART2_REMAP);
                RCC_enuEnablePeripheralClock(APB_1_ID, UART_2_ID);
                RCC_enuGetPLCK1(&uartClk);
                if(Copy_pstUartConfig->IRQ_Enable == _UART_INT_ENABLE_){
                    NVIC_enuEnableInterrupt(INT_NUM_38);
                }            
                break;
            case _UART_3_:
                UARTx_Regs = UART3_Regs;
                AFIO_enuUartMap(_UART_3_, SET_UART3_REMAP);
                RCC_enuEnablePeripheralClock(APB_1_ID, UART_3_ID);
                RCC_enuGetPLCK1(&uartClk);
                if(Copy_pstUartConfig->IRQ_Enable == _UART_INT_ENABLE_){
                    NVIC_enuEnableInterrupt(INT_NUM_39);
                }         
                break;   
            default:
                return ES_OUT_OF_RANGE;
        }
        // disable uart
        CLEAR_BIT(UARTx_Regs->CR[0], 13);
        // set word length
        UARTx_Regs->CR[0] &= ~(0x1 << 12);
        UARTx_Regs->CR[0] |= (Copy_pstUartConfig->WordLength << 12);
        // set parity
        UARTx_Regs->CR[0] &= ~(0x3 << 9);
        UARTx_Regs->CR[0] |= (Copy_pstUartConfig->Parity << 9);
        // set stop bits
        UARTx_Regs->CR[1] &= ~(0x3 << 12);
        UARTx_Regs->CR[1] |= (Copy_pstUartConfig->StopBits << 12);
        // set flow control
        UARTx_Regs->CR[2] &= ~(0x3 << 8);
        UARTx_Regs->CR[2] |= (Copy_pstUartConfig->FlowControl << 8);
        // set baudrate
        UARTx_Regs->BRR = UART_BUAD_RATE(uartClk, Copy_pstUartConfig->BaudRate);
        // enable send and receive
        UARTx_Regs->CR[0] &= ~(0x3 << 2);
        UARTx_Regs->CR[0] |= (Copy_pstUartConfig->SendRecvEnable << 2);
        // enable uart
        SET_BIT(UARTx_Regs->CR[0], 13);
        return ES_OK;
    }else{
        return ES_NULL_POINTER;
    }
}

ErrorStates_t UART_enuTransmitByte(uint8_t Copy_u8UartId, PollingEn_t Copy_u8PollingEn, uint8_t Copy_u8Data){
    if(Copy_u8UartId >= _UART_1_ && Copy_u8UartId <= _UART_2_){
        volatile ST_UART_Regs_t* UARTx_Regs;
        switch (Copy_u8UartId)
        {
            case _UART_1_:
                UARTx_Regs = UART1_Regs;
                break;
            case _UART_2_:
                UARTx_Regs = UART2_Regs;
                break;
            case _UART_3_:
                UARTx_Regs = UART3_Regs;   
                break;   
            default:
                return ES_NOK;
        }
        // WAIT On the flag if the polling is enabled
        if(Copy_u8PollingEn == _UART_POLLING_ENABLE_)
            while(!GET_BIT(UARTx_Regs->SR, 7)); // wait until tdr is empty

        UARTx_Regs->DR = Copy_u8Data; // this write clears the TXE

        if(Copy_u8PollingEn == _UART_POLLING_ENABLE_){
            while (!GET_BIT(UARTx_Regs->SR, 6)); // wait until tc is set
            CLEAR_BIT(UARTx_Regs->SR, 6);
        }
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t UART_enuReceiveByte(uint8_t Copy_u8UartId, PollingEn_t Copy_u8PollingEn, uint8_t *Copy_pu8Data){
    if(Copy_u8UartId >= _UART_1_ && Copy_u8UartId <= _UART_2_){
        volatile ST_UART_Regs_t* UARTx_Regs;
        switch (Copy_u8UartId)
        {
            case _UART_1_:
                UARTx_Regs = UART1_Regs;
                break;
            case _UART_2_:
                UARTx_Regs = UART2_Regs;
                break;
            case _UART_3_:
                UARTx_Regs = UART3_Regs;   
                break;   
            default:
                return ES_NOK;
        }
        // WAIT On the flag if the polling is enabled
        if(Copy_u8PollingEn == _UART_POLLING_ENABLE_)
            while(!GET_BIT(UARTx_Regs->SR, 5)); // wait until rxne is set

        *Copy_pu8Data = UARTx_Regs->DR & 0xff; // this read clears the RXNETRMT

        CLEAR_BIT(UARTx_Regs->SR, 5);
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t UART_enuTransmitString(uint8_t Copy_u8UartId, PollingEn_t Copy_u8PollingEn, uint8_t *Copy_pu8Data){
    if(Copy_pu8Data != NULL){
        uint8_t dataLen = 0;
        ErrorStates_t localerr = ES_OK;
        do{
            // send byte
            localerr = UART_enuTransmitByte(Copy_u8UartId, Copy_u8PollingEn, Copy_pu8Data[dataLen]);
            dataLen++; // increment index            
        }while(Copy_pu8Data[dataLen] != '\0');

        return localerr;
    }else{
        return ES_NULL_POINTER;
    }
}

ErrorStates_t UART_enuReceiveString(uint8_t Copy_u8UartId, PollingEn_t Copy_u8PollingEn, uint8_t *Copy_pu8Data){
    if(Copy_pu8Data != NULL){
        uint8_t dataLen = 0;
        ErrorStates_t localerr = ES_OK;
        do{
            // receive byte
            localerr = UART_enuReceiveByte(Copy_u8UartId, Copy_u8PollingEn, &Copy_pu8Data[dataLen]);
            dataLen++; // increment index            
        }while(Copy_pu8Data[dataLen - 1] != '\r' && Copy_pu8Data[dataLen - 1] != '\n');

        Copy_pu8Data[dataLen - 1] = '\0'; // add null terminator
        
        return localerr;
    }else{
        return ES_NULL_POINTER;
    }
}

ErrorStates_t UART_enuEnableInterrupt(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType){
    if(Copy_u8UartId >= _UART_1_ && Copy_u8UartId <= _UART_2_){
        volatile ST_UART_Regs_t* UARTx_Regs;
        switch (Copy_u8UartId)
        {
            case _UART_1_:
                UARTx_Regs = UART1_Regs;
                NVIC_enuEnableInterrupt(INT_NUM_37);
                break;
            case _UART_2_:
                UARTx_Regs = UART2_Regs;
                NVIC_enuEnableInterrupt(INT_NUM_38);
                break;
            case _UART_3_:
                UARTx_Regs = UART3_Regs;   
                NVIC_enuEnableInterrupt(INT_NUM_39);
                break;   
            default:
                return ES_NOK;
        }        
        switch (Copy_u8InterruptType)
        {
            case _UART_PARITY_ERROR_INTERRUPT_:
                SET_BIT(UARTx_Regs->CR[0], 8);
                break;
            case _UART_TDR_EMPTY_INTERRUPT_:
                SET_BIT(UARTx_Regs->CR[0], 7);
                break;
            case _UART_TX_COMPLETE_INTERRUPT_:
                SET_BIT(UARTx_Regs->CR[0], 6);
                break;
            case _UART_RX_READY_INTERRUPT_:
                SET_BIT(UARTx_Regs->CR[0], 5);
                break;
            case _UART_IDLE_INTERRUPT_:
                SET_BIT(UARTx_Regs->CR[0], 4);
                break;
            case _UART_CTS_INTERRUPT_:
                SET_BIT(UARTx_Regs->CR[3], 10);
                break;
            case _UART_FRAMING_ERROR_INTERRUPT_:
            case _UART_NOISE_ERROR_INTERRUPT_:
            case _UART_OVERRUN_ERROR_INTERRUPT_:
                SET_BIT(UARTx_Regs->CR[2], 0);
                break;
            default:
                return ES_OUT_OF_RANGE;
        }        
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t UART_enuDisableInterrupt(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType){
    if(Copy_u8UartId >= _UART_1_ && Copy_u8UartId <= _UART_2_){
        volatile ST_UART_Regs_t* UARTx_Regs;
        switch (Copy_u8UartId)
        {
            case _UART_1_:
                UARTx_Regs = UART1_Regs;
                NVIC_enuDisableInterrupt(INT_NUM_37);
                break;
            case _UART_2_:
                UARTx_Regs = UART2_Regs;
                NVIC_enuDisableInterrupt(INT_NUM_38);
                break;
            case _UART_3_:
                UARTx_Regs = UART3_Regs;   
                NVIC_enuDisableInterrupt(INT_NUM_39);
                break;   
            default:
                return ES_NOK;
        }        
        switch (Copy_u8InterruptType)
        {
            case _UART_PARITY_ERROR_INTERRUPT_:
                CLEAR_BIT(UARTx_Regs->CR[0], 8);
                break;
            case _UART_TDR_EMPTY_INTERRUPT_:
                CLEAR_BIT(UARTx_Regs->CR[0], 7);
                break;
            case _UART_TX_COMPLETE_INTERRUPT_:
                CLEAR_BIT(UARTx_Regs->CR[0], 6);
                break;
            case _UART_RX_READY_INTERRUPT_:
                CLEAR_BIT(UARTx_Regs->CR[0], 5);
                break;
            case _UART_IDLE_INTERRUPT_:
                CLEAR_BIT(UARTx_Regs->CR[0], 4);
                break;
            case _UART_CTS_INTERRUPT_:
                CLEAR_BIT(UARTx_Regs->CR[3], 10);
                break;
            case _UART_FRAMING_ERROR_INTERRUPT_:
            case _UART_NOISE_ERROR_INTERRUPT_:
            case _UART_OVERRUN_ERROR_INTERRUPT_:
                CLEAR_BIT(UARTx_Regs->CR[2], 0);
                break;
            default:
                return ES_OUT_OF_RANGE;
        }        
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t UART_enuSetCallBack(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType, void (*Copy_fpvCallBack)(void), void* Copy_pvParameter){
    if(Copy_fpvCallBack != NULL && Copy_pvParameter != NULL){
        switch (Copy_u8UartId)
        {
            case _UART_1_:
                UART1_InterruptHandlers[Copy_u8InterruptType] = Copy_fpvCallBack;
                UART1_InterruptParameters[Copy_u8InterruptType] = Copy_pvParameter;
                break;
            case _UART_2_:
                UART2_InterruptHandlers[Copy_u8InterruptType] = Copy_fpvCallBack;
                UART2_InterruptParameters[Copy_u8InterruptType] = Copy_pvParameter;
                break;
            case _UART_3_:
                UART3_InterruptHandlers[Copy_u8InterruptType] = Copy_fpvCallBack;
                UART3_InterruptParameters[Copy_u8InterruptType] = Copy_pvParameter;
                break;
            default:
                return ES_OUT_OF_RANGE;
        }
        return ES_OK;
    }else{
        return ES_NULL_POINTER;
    }
}

void USART1_IRQHandler(void){
    if(GET_BIT(UART1_Regs->CR[0], 9)){
        if(UART1_InterruptHandlers[_UART_CTS_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_CTS_INTERRUPT_](UART1_InterruptParameters[_UART_CTS_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART1_Regs->SR, 7)){
        if(UART1_InterruptHandlers[_UART_TDR_EMPTY_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_TDR_EMPTY_INTERRUPT_](UART1_InterruptParameters[_UART_TDR_EMPTY_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART1_Regs->SR, 6)){
        if(UART1_InterruptHandlers[_UART_TX_COMPLETE_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_TX_COMPLETE_INTERRUPT_](UART1_InterruptParameters[_UART_TX_COMPLETE_INTERRUPT_]);
            CLEAR_BIT(UART1_Regs->SR, 6);
        }
    }

    if(GET_BIT(UART1_Regs->SR, 5)){
        if(UART1_InterruptHandlers[_UART_RX_READY_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_RX_READY_INTERRUPT_](UART1_InterruptParameters[_UART_RX_READY_INTERRUPT_]);
            CLEAR_BIT(UART1_Regs->SR, 5);
        }
    }

    if(GET_BIT(UART1_Regs->SR, 4)){
        if(UART1_InterruptHandlers[_UART_IDLE_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_IDLE_INTERRUPT_](UART1_InterruptParameters[_UART_IDLE_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART1_Regs->SR, 3)){
        if(UART1_InterruptHandlers[_UART_OVERRUN_ERROR_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_OVERRUN_ERROR_INTERRUPT_](UART1_InterruptParameters[_UART_OVERRUN_ERROR_INTERRUPT_]);
        }
    }


    if(GET_BIT(UART1_Regs->SR, 2)){
        if(UART1_InterruptHandlers[_UART_NOISE_ERROR_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_NOISE_ERROR_INTERRUPT_](UART1_InterruptParameters[_UART_NOISE_ERROR_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART1_Regs->SR, 1)){
        if(UART1_InterruptHandlers[_UART_FRAMING_ERROR_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_FRAMING_ERROR_INTERRUPT_](UART1_InterruptParameters[_UART_FRAMING_ERROR_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART1_Regs->SR, 0)){
        if(UART1_InterruptHandlers[_UART_PARITY_ERROR_INTERRUPT_] != NULL){
            UART1_InterruptHandlers[_UART_PARITY_ERROR_INTERRUPT_](UART1_InterruptParameters[_UART_PARITY_ERROR_INTERRUPT_]);
        }
    }
}


void USART2_IRQHandler(void){
    if(GET_BIT(UART2_Regs->CR[0], 9)){
        if(UART2_InterruptHandlers[_UART_CTS_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_CTS_INTERRUPT_](UART2_InterruptParameters[_UART_CTS_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART2_Regs->SR, 7)){
        if(UART2_InterruptHandlers[_UART_TDR_EMPTY_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_TDR_EMPTY_INTERRUPT_](UART2_InterruptParameters[_UART_TDR_EMPTY_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART2_Regs->SR, 6)){
        if(UART2_InterruptHandlers[_UART_TX_COMPLETE_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_TX_COMPLETE_INTERRUPT_](UART2_InterruptParameters[_UART_TX_COMPLETE_INTERRUPT_]);
            CLEAR_BIT(UART2_Regs->SR, 6);
        }
    }

    if(GET_BIT(UART2_Regs->SR, 5)){
        if(UART2_InterruptHandlers[_UART_RX_READY_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_RX_READY_INTERRUPT_](UART2_InterruptParameters[_UART_RX_READY_INTERRUPT_]);
            CLEAR_BIT(UART2_Regs->SR, 5);
        }
    }

    if(GET_BIT(UART2_Regs->SR, 4)){
        if(UART2_InterruptHandlers[_UART_IDLE_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_IDLE_INTERRUPT_](UART2_InterruptParameters[_UART_IDLE_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART2_Regs->SR, 3)){
        if(UART2_InterruptHandlers[_UART_OVERRUN_ERROR_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_OVERRUN_ERROR_INTERRUPT_](UART2_InterruptParameters[_UART_OVERRUN_ERROR_INTERRUPT_]);
        }
    }


    if(GET_BIT(UART2_Regs->SR, 2)){
        if(UART2_InterruptHandlers[_UART_NOISE_ERROR_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_NOISE_ERROR_INTERRUPT_](UART2_InterruptParameters[_UART_NOISE_ERROR_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART2_Regs->SR, 1)){
        if(UART2_InterruptHandlers[_UART_FRAMING_ERROR_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_FRAMING_ERROR_INTERRUPT_](UART2_InterruptParameters[_UART_FRAMING_ERROR_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART2_Regs->SR, 0)){
        if(UART2_InterruptHandlers[_UART_PARITY_ERROR_INTERRUPT_] != NULL){
            UART2_InterruptHandlers[_UART_PARITY_ERROR_INTERRUPT_](UART2_InterruptParameters[_UART_PARITY_ERROR_INTERRUPT_]);
        }
    }
}

void USART3_IRQHandler(void){
    if(GET_BIT(UART3_Regs->CR[0], 9)){
        if(UART3_InterruptHandlers[_UART_CTS_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_CTS_INTERRUPT_](UART3_InterruptParameters[_UART_CTS_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART3_Regs->SR, 7)){
        if(UART3_InterruptHandlers[_UART_TDR_EMPTY_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_TDR_EMPTY_INTERRUPT_](UART3_InterruptParameters[_UART_TDR_EMPTY_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART3_Regs->SR, 6)){
        if(UART3_InterruptHandlers[_UART_TX_COMPLETE_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_TX_COMPLETE_INTERRUPT_](UART3_InterruptParameters[_UART_TX_COMPLETE_INTERRUPT_]);
            CLEAR_BIT(UART3_Regs->SR, 6);
        }
    }

    if(GET_BIT(UART3_Regs->SR, 5)){
        if(UART3_InterruptHandlers[_UART_RX_READY_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_RX_READY_INTERRUPT_](UART3_InterruptParameters[_UART_RX_READY_INTERRUPT_]);
            CLEAR_BIT(UART3_Regs->SR, 5);
        }
    }

    if(GET_BIT(UART3_Regs->SR, 4)){
        if(UART3_InterruptHandlers[_UART_IDLE_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_IDLE_INTERRUPT_](UART3_InterruptParameters[_UART_IDLE_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART3_Regs->SR, 3)){
        if(UART3_InterruptHandlers[_UART_OVERRUN_ERROR_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_OVERRUN_ERROR_INTERRUPT_](UART3_InterruptParameters[_UART_OVERRUN_ERROR_INTERRUPT_]);
        }
    }


    if(GET_BIT(UART3_Regs->SR, 2)){
        if(UART3_InterruptHandlers[_UART_NOISE_ERROR_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_NOISE_ERROR_INTERRUPT_](UART3_InterruptParameters[_UART_NOISE_ERROR_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART3_Regs->SR, 1)){
        if(UART3_InterruptHandlers[_UART_FRAMING_ERROR_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_FRAMING_ERROR_INTERRUPT_](UART3_InterruptParameters[_UART_FRAMING_ERROR_INTERRUPT_]);
        }
    }

    if(GET_BIT(UART3_Regs->SR, 0)){
        if(UART3_InterruptHandlers[_UART_PARITY_ERROR_INTERRUPT_] != NULL){
            UART3_InterruptHandlers[_UART_PARITY_ERROR_INTERRUPT_](UART3_InterruptParameters[_UART_PARITY_ERROR_INTERRUPT_]);
        }
    }
}
