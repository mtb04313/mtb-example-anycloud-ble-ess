/*******************************************************************************
* File Name: cy_debug.h
*
* Description: This file includes the macros, enumerations, and function
* prototypes used in cy_debug.c
*
* Related Document: See README.md
*
*
*******************************************************************************
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

/*******************************************************************************
 *  Include guard
 ******************************************************************************/
#ifndef SOURCE_CY_DEBUG_H_
#define SOURCE_CY_DEBUG_H_

/*******************************************************************************
 * Header file includes
 ******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#ifdef __cplusplus
extern "C"
{
#endif


/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/
void file_line_printf(const char* file,
                      int line,
                      const char *format, ...);

void assert_printf( const char* file,
                    int line,
                    const char *exp);
 
void print_bytes( const char* str,
                  const uint8_t *p_ubArray,
                  int size);

void print_bytes_noCR(const char* str, 
                      const uint8_t *p_ubArray,
                      int size);

void print_address_bytes( const char* str,
                          unsigned int address,
                          const uint8_t *p_ubArray,
                          int size);

void tag_printf(int level,
                const char* tag,
                const char *format, ...);


/*******************************************************************************
 * Enumerations
 ******************************************************************************/
typedef enum {
    CY_LOG_NONE,
    CY_LOG_ERROR,
    CY_LOG_WARN,
    CY_LOG_INFO,
    CY_LOG_DEBUG,
    CY_LOG_VERBOSE
} cy_log_level_t;


/*******************************************************************************
 * Macros
 ******************************************************************************/
#define DEBUG_LOG_ENABLED    1  /* 1=enable, 0=disable */

#if (DEBUG_LOG_ENABLED == 1)
    #define DEBUG_PRINT(x)          printf x
    #define DEBUG_FL_PRINT(x)       file_line_printf(__FILE__, __LINE__, x)
    #define DEBUG_FL2_PRINT(f,l,x)  file_line_printf(f, l, x)
    #define FUNC_NAME               __FUNCTION__

#else
    #define DEBUG_PRINT(x)          ((void)0)
    #define DEBUG_FL_PRINT(x)       ((void)0)
    #define DEBUG_FL2_PRINT(f,l,x)  ((void)0)
    #define FUNC_NAME               NULL
#endif


#define DEFAULT_LOG_LEVEL    ((int)CY_LOG_VERBOSE)

#define CY_LOGE(tag, format, ...) tag_printf(CY_LOG_ERROR,   tag, format, ##__VA_ARGS__)
#define CY_LOGW(tag, format, ...) tag_printf(CY_LOG_WARN,    tag, format, ##__VA_ARGS__)
#define CY_LOGI(tag, format, ...) tag_printf(CY_LOG_INFO,    tag, format, ##__VA_ARGS__)
#define CY_LOGD(tag, format, ...) tag_printf(CY_LOG_DEBUG,   tag, format, ##__VA_ARGS__)
#define CY_LOGV(tag, format, ...) tag_printf(CY_LOG_VERBOSE, tag, format, ##__VA_ARGS__)


#define ASSERTION_ENABLED       1

#if (ASSERTION_ENABLED)
    #define DEBUG_ASSERT(exp)   ((exp)? (void)0 : assert_printf(__FILE__, __LINE__, #exp))
#else
    #define DEBUG_ASSERT(exp)   ((void)0)
#endif

#define ReturnAssert(exp, retvalue) \
    DEBUG_ASSERT((exp)); \
    if (!(exp)) \
        return (retvalue);

#define VoidAssert(exp) \
    DEBUG_ASSERT((exp)); \
    if (!(exp)) \
        return ;

#ifdef __cplusplus
}
#endif

#endif // SOURCE_CY_DEBUG_H_


/* [] END OF FILE */
