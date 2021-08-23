/*******************************************************************************
* Copyright 2020-2021, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* RT-Thread Project Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX                       16
#define RT_ALIGN_SIZE                     4
#define RT_THREAD_PRIORITY_               32
#define RT_THREAD_PRIORITY_MAX            32
#define RT_TICK_PER_SECOND                100
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE            4
#define IDLE_THREAD_STACK_SIZE            1024
//#define RT_USING_TIMER_SOFT
//#define RT_TIMER_THREAD_PRIO            4
//#define RT_TIMER_THREAD_STACK_SIZE      512
#define RT_DEBUG

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE
//#define RT_USING_SIGNALS

/* Memory Management */

#define RT_USING_MEMPOOL
//#define RT_USING_MEMHEAP
#define RT_USING_SMALL_MEM
//#define RT_USING_MEMTRACE
#define RT_USING_HEAP

/* added */
#define configTOTAL_HEAP_SIZE             (20*1024)
#define HAVE_SIGVAL
#define HAVE_SIGINFO
#define HAVE_SIGEVENT

/* RT-Thread Components */

#define RT_USING_USER_MAIN
//#define RT_USING_COMPONENTS_INIT
//#define RT_MAIN_THREAD_STACK_SIZE       2048
//#define RT_MAIN_THREAD_PRIORITY         10

/* Kernel Device Object */

//#define RT_USING_DEVICE
//#define RT_USING_CONSOLE
//#define RT_CONSOLEBUF_SIZE              256
//#define RT_CONSOLE_DEVICE_NAME          "uart0"
//#define RT_VER_NUM                      0x40000

/* Command shell */

//#define RT_USING_FINSH
//#define FINSH_THREAD_NAME               "tshell"
//#define FINSH_USING_HISTORY
//#define FINSH_HISTORY_LINES             5
//#define FINSH_USING_SYMTAB
//#define FINSH_USING_DESCRIPTION
//#define FINSH_THREAD_PRIORITY           20
//#define FINSH_THREAD_STACK_SIZE         4096
//#define FINSH_CMD_SIZE                  80
//#define FINSH_USING_MSH
//#define FINSH_USING_MSH_DEFAULT
//#define FINSH_ARG_MAX                   10

/* Device Drivers */

//#define RT_USING_DEVICE_IPC
//#define RT_PIPE_BUFSZ                   512
//#define RT_USING_SERIAL
//#define RT_SERIAL_USING_DMA
//#define RT_USING_PIN
//#define RT_USING_UART0

#endif
