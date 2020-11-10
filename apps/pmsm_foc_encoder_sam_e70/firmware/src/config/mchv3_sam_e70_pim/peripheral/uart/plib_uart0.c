/*******************************************************************************
  UART0 PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_uart0.c

  Summary:
    UART0 PLIB Implementation File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "device.h"
#include "plib_uart0.h"

// *****************************************************************************
// *****************************************************************************
// Section: UART0 Implementation
// *****************************************************************************
// *****************************************************************************

static void UART0_ErrorClear( void )
{
    uint8_t dummyData = 0u;

    UART0_REGS->UART_CR = UART_CR_RSTSTA_Msk;

    /* Flush existing error bytes from the RX FIFO */
    while( UART_SR_RXRDY_Msk == (UART0_REGS->UART_SR & UART_SR_RXRDY_Msk) )
    {
        dummyData = (UART0_REGS->UART_RHR & UART_RHR_RXCHR_Msk);
    }

    /* Ignore the warning */
    (void)dummyData;
}

void UART0_Initialize( void )
{
    /* Reset UART0 */
    UART0_REGS->UART_CR = (UART_CR_RSTRX_Msk | UART_CR_RSTTX_Msk | UART_CR_RSTSTA_Msk);

    /* Enable UART0 */
    UART0_REGS->UART_CR = (UART_CR_TXEN_Msk | UART_CR_RXEN_Msk);

    /* Configure UART0 mode */
    UART0_REGS->UART_MR = ((UART_MR_BRSRCCK_PERIPH_CLK) | (UART_MR_PAR_NO) | (0 << UART_MR_FILTER_Pos));

    /* Configure UART0 Baud Rate */
    UART0_REGS->UART_BRGR = UART_BRGR_CD(81);
}

UART_ERROR UART0_ErrorGet( void )
{
    UART_ERROR errors = UART_ERROR_NONE;
    uint32_t status = UART0_REGS->UART_SR;

    errors = (UART_ERROR)(status & (UART_SR_OVRE_Msk | UART_SR_PARE_Msk | UART_SR_FRAME_Msk));

    if(errors != UART_ERROR_NONE)
    {
        UART0_ErrorClear();
    }

    /* All errors are cleared, but send the previous error state */
    return errors;
}

bool UART0_SerialSetup( UART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    bool status = false;
    uint32_t baud = setup->baudRate;
    uint32_t brgVal = 0;
    uint32_t uartMode;

    if (setup != NULL)
    {
        if(srcClkFreq == 0)
        {
            srcClkFreq = UART0_FrequencyGet();
        }

        /* Calculate BRG value */
        brgVal = srcClkFreq / (16 * baud);

        /* If the target baud rate is acheivable using this clock */
        if (brgVal <= 65535)
        {
            /* Configure UART0 mode */
            uartMode = UART0_REGS->UART_MR;
            uartMode &= ~UART_MR_PAR_Msk;
            UART0_REGS->UART_MR = uartMode | setup->parity ;

            /* Configure UART0 Baud Rate */
            UART0_REGS->UART_BRGR = UART_BRGR_CD(brgVal);

            status = true;
        }
    }

    return status;
}

bool UART0_Read( void *buffer, const size_t size )
{
    bool status = false;
    uint32_t errorStatus = 0;
    size_t processedSize = 0;

    uint8_t * lBuffer = (uint8_t *)buffer;

    if(NULL != lBuffer)
    {
        /* Clear errors before submitting the request.
         * ErrorGet clears errors internally. */
        UART0_ErrorGet();

        while( size > processedSize )
        {
            /* Error status */
            errorStatus = (UART0_REGS->UART_SR & (UART_SR_OVRE_Msk | UART_SR_FRAME_Msk | UART_SR_PARE_Msk));

            if(errorStatus != 0)
            {
                break;
            }

            if(UART_SR_RXRDY_Msk == (UART0_REGS->UART_SR & UART_SR_RXRDY_Msk))
            {
                *lBuffer++ = (UART0_REGS->UART_RHR& UART_RHR_RXCHR_Msk);
                processedSize++;
            }
        }

        if(size == processedSize)
        {
            status = true;
        }
    }

    return status;
}

bool UART0_Write( void *buffer, const size_t size )
{
    bool status = false;
    size_t processedSize = 0;
    uint8_t * lBuffer = (uint8_t *)buffer;

    if(NULL != lBuffer)
    {
        while( size > processedSize )
        {
            if(UART_SR_TXRDY_Msk == (UART0_REGS->UART_SR & UART_SR_TXRDY_Msk))
            {
                UART0_REGS->UART_THR = (UART_THR_TXCHR(*lBuffer++) & UART_THR_TXCHR_Msk);
                processedSize++;
            }
        }

        status = true;
    }

    return status;
}

int UART0_ReadByte(void)
{
    return(UART0_REGS->UART_RHR& UART_RHR_RXCHR_Msk);
}

void UART0_WriteByte( int data )
{
    while ((UART_SR_TXRDY_Msk == (UART0_REGS->UART_SR & UART_SR_TXRDY_Msk)) == 0);

    UART0_REGS->UART_THR = (UART_THR_TXCHR(data) & UART_THR_TXCHR_Msk);
}

bool UART0_TransmitterIsReady( void )
{
    bool status = false;

    if(UART_SR_TXRDY_Msk == (UART0_REGS->UART_SR & UART_SR_TXRDY_Msk))
    {
        status = true;
    }

    return status;
}

bool UART0_TransmitComplete( void )
{
    bool status = false;

    if(UART_SR_TXEMPTY_Msk == (UART0_REGS->UART_SR & UART_SR_TXEMPTY_Msk))
    {
        status = true;
    }

    return status;
}

bool UART0_ReceiverIsReady( void )
{
    bool status = false;

    if(UART_SR_RXRDY_Msk == (UART0_REGS->UART_SR & UART_SR_RXRDY_Msk))
    {
        status = true;
    }

    return status;
}

