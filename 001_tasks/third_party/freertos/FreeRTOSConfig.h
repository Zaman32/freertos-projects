/*
 * FreeRTOSConfig.h
 * Target: STM32F767ZI (Nucleo-144)
 * Core:   ARM Cortex-M7 @ 216 MHz
 * Docs:   https://www.freertos.org/a00110.html
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------
 * Application-specific definitions
 * ----------------------------------------------------------------------- */

/* Scheduler behaviour */
#define configUSE_PREEMPTION                    1
#define configUSE_TIME_SLICING                  1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1   /* Use Cortex-M CLZ instruction */

/* Tick / clock */
#define configUSE_TICKLESS_IDLE                 0
#define configCPU_CLOCK_HZ                      ( ( unsigned long ) 216000000 )
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )        /* 1 ms tick */
#define configSYSTICK_CLOCK_HZ                  configCPU_CLOCK_HZ             /* SysTick runs at core clock */

/* Task priorities and stack */
#define configMAX_PRIORITIES                    ( 7 )
#define configMINIMAL_STACK_SIZE                ( ( unsigned short ) 256 )     /* words (×4 = bytes) */
#define configMAX_TASK_NAME_LEN                 ( 16 )

/* Memory allocation */
#define configSUPPORT_STATIC_ALLOCATION         0
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) ( 64 * 1024 ) )   /* 64 KB – adjust as needed */
#define configAPPLICATION_ALLOCATED_HEAP        0

/* Idle task */
#define configIDLE_SHOULD_YIELD                 1

/* -----------------------------------------------------------------------
 * Feature enable / disable
 * ----------------------------------------------------------------------- */

#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configUSE_MALLOC_FAILED_HOOK            0
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0

#define configCHECK_FOR_STACK_OVERFLOW          0   /* Method 2: pattern + watermark check */

#define configUSE_TRACE_FACILITY                1
#define configUSE_STATS_FORMATTING_FUNCTIONS    1
#define configGENERATE_RUN_TIME_STATS           0

#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )

#define INCLUDE_xTaskGetIleTaskHandle	1
#define INCLUDE_pxTaskGetStackStart 1

#define INCLUDE_xTaskGetCurrentTaskHandle 1
#define configUSE_APPLICATION_TASK_TAG 1

/* -----------------------------------------------------------------------
 * Software timers
 * ----------------------------------------------------------------------- */

#define configUSE_TIMERS                        0
#define configTIMER_TASK_PRIORITY               ( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            ( configMINIMAL_STACK_SIZE * 2 )

/* -----------------------------------------------------------------------
 * Queue / synchronisation
 * ----------------------------------------------------------------------- */

#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_QUEUE_SETS                    0
#define configQUEUE_REGISTRY_SIZE               8

/* -----------------------------------------------------------------------
 * Cortex-M interrupt priority configuration
 *
 * STM32F767ZI uses 4 NVIC priority bits (0–15).
 * FreeRTOS kernel interrupts must have a NUMERICAL priority ≥
 * configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY so they are masked
 * during critical sections. Driver ISRs that call "FromISR" APIs must
 * also respect this boundary.
 * ----------------------------------------------------------------------- */

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5

/* Derived values – do NOT change */
#define configKERNEL_INTERRUPT_PRIORITY \
    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* Number of priority bits implemented by the hardware */
#define configPRIO_BITS                         4

/* -----------------------------------------------------------------------
 * Assert
 * ----------------------------------------------------------------------- */

/* Trap FreeRTOS assertion failures – replace with your debug mechanism */
#define configASSERT( x )   \
    if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* -----------------------------------------------------------------------
 * Optional / task notification
 * ----------------------------------------------------------------------- */

#define configUSE_TASK_NOTIFICATIONS            1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES   1

/* -----------------------------------------------------------------------
 * Map FreeRTOS port interrupt handlers to CMSIS / STM32 HAL names
 * (required when using STM32CubeIDE / HAL)
 * ----------------------------------------------------------------------- */

#define vPortSVCHandler     SVC_Handler
#define xPortPendSVHandler  PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

/* -----------------------------------------------------------------------
 * Type definitions (required by FreeRTOS portable layer)
 * ----------------------------------------------------------------------- */

#define configUSE_16_BIT_TICKS  0   /* TickType_t = uint32_t */

#include "SEGGER_SYSVIEW_FreeRTOS.h"

#ifdef __cplusplus
}
#endif

#endif /* FREERTOS_CONFIG_H */
