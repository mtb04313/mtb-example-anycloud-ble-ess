/*******************************************************************************
 * File Name: rtconfig.c
 *
 * Description: This file contains functions needed to start RT-Thread OS.
 *
 * Related Document: See README.md
 *
 *
 *********************************************************************************
 Copyright 2020-2021, Cypress Semiconductor Corporation (an Infineon company) or
 an affiliate of Cypress Semiconductor Corporation.  All rights reserved.

 This software, including source code, documentation and related
 materials ("Software") is owned by Cypress Semiconductor Corporation
 or one of its affiliates ("Cypress") and is protected by and subject to
 worldwide patent protection (United States and foreign),
 United States copyright laws and international treaty provisions.
 Therefore, you may use this Software only as provided in the license
 agreement accompanying the software package from which you
 obtained this Software ("EULA").
 If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 non-transferable license to copy, modify, and compile the Software
 source code solely for use in connection with Cypress's
 integrated circuit products.  Any reproduction, modification, translation,
 compilation, or representation of this Software except as specified
 above is prohibited without the express written permission of Cypress.

 Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 reserves the right to make changes to the Software without notice. Cypress
 does not assume any liability arising out of the application or use of the
 Software or any product or circuit described in the Software. Cypress does
 not authorize its products for use in any products where a malfunction or
 failure of the Cypress product may reasonably be expected to result in
 significant property damage, injury or death ("High Risk Product"). By
 including Cypress's product in a High Risk Product, the manufacturer
 of such system or application assumes all risk of such use and in doing
 so agrees to indemnify Cypress against all liability.
 *******************************************************************************/


/*******************************************************************************
 *        Header Files
 *******************************************************************************/
#include "cybsp.h"
#include "cyabs_rtos.h"


/*******************************************************************************
 *        Variable Definitions
 *******************************************************************************/

#ifdef COMPONENT_RTTHREAD
//#include <rthw.h>

/* Allocate the memory for the heap. */
ALIGN(RT_ALIGN_SIZE)
static uint8_t ucHeap[ configTOTAL_HEAP_SIZE ];


/******************************************************************************
 *                          Function Definitions
 ******************************************************************************/

static void SysTick_Handler_CB(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

void rt_hw_board_init()
{
    if (CY_RSLT_SUCCESS != cybsp_init()) {
        CY_ASSERT(0);
    }

    SystemCoreClockUpdate();

    Cy_SysTick_Init(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU, SystemCoreClock/RT_TICK_PER_SECOND);
    Cy_SysTick_SetCallback(0, SysTick_Handler_CB);
    Cy_SysTick_EnableInterrupt();

    rt_system_heap_init((void*)ucHeap, (void*)(ucHeap + sizeof(ucHeap)));

    /* initialize UART device */
    //rt_hw_uart_init();

#ifdef RT_USING_CONSOLE
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif
}

#endif

/* [] END OF FILE */
