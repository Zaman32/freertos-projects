/*
 * FreeRTOSConfig.h
 * Target: STM32F767ZI (ARM Cortex-M7, 216 MHz)
 * FreeRTOS version: 10.x
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* ─── Scheduler ─────────────────────────────────────────────────────────── */
#define configUSE_PREEMPTION                    1
#define configUSE_TIME_SLICING                  1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1   /* Cortex-M7 CLZ support */
#define configUSE_TICKLESS_IDLE                 0   /* set 1 for low-power */

/* ─── Clock ──────────────────────────────────────────────────────────────── */
#define configCPU_CLOCK_HZ                      ( ( unsigned long ) 216000000 )
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )        /* 1 ms tick */

/* ─── Task / memory ──────────────────────────────────────────────────────── */
#define configMAX_PRIORITIES                    7
#define configMINIMAL_STACK_SIZE                ( ( uint16_t ) 128 )   /* words */
#define configMAX_TASK_NAME_LEN                 16
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) ( 75 * 1024 ) )  /* 75 KB */
#define configAPPLICATION_ALLOCATED_HEAP        0

/* ─── Heap allocator ─────────────────────────────────────────────────────── */
/* heap_4.c is a good default (coalescing, no fragmentation growth) */
/* Include FreeRTOS/Source/portable/MemMang/heap_4.c in your build  */

/* ─── Features ───────────────────────────────────────────────────────────── */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configUSE_MALLOC_FAILED_HOOK            1
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0
#define configCHECK_FOR_STACK_OVERFLOW          0   /* method 2: pattern check */
#define configGENERATE_RUN_TIME_STATS           0
#define configUSE_TRACE_FACILITY                0
#define configUSE_STATS_FORMATTING_FUNCTIONS    0

/* ─── Co-routines (rarely needed) ───────────────────────────────────────── */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         2

/* ─── Timers ─────────────────────────────────────────────────────────────── */
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               ( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            ( configMINIMAL_STACK_SIZE * 2 )

/* ─── IPC primitives ─────────────────────────────────────────────────────── */
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_QUEUE_SETS                    0
#define configQUEUE_REGISTRY_SIZE               8

/* ─── Notifications ──────────────────────────────────────────────────────── */
#define configUSE_TASK_NOTIFICATIONS            1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES   1

/* ─── Cortex-M interrupt priority configuration ─────────────────────────── */
/*
 * On Cortex-M7 with 4 priority bits (NVIC_PRIO_BITS = 4):
 *   Usable range for FreeRTOS ISRs: priorities 5–15 (0–4 are reserved for
 *   truly time-critical ISRs that must NOT call FreeRTOS API functions).
 */
#define configPRIO_BITS                         4   /* STM32F7 uses 4 bits */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY     5

/* Derived — do not change these two lines */
#define configKERNEL_INTERRUPT_PRIORITY  \
    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* ─── Assert ─────────────────────────────────────────────────────────────── */
#define configASSERT( x )  \
    if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* ─── API function inclusions ────────────────────────────────────────────── */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_xResumeFromISR                  1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_xTaskGetCurrentTaskHandle       1
#define INCLUDE_uxTaskGetStackHighWaterMark     1
#define INCLUDE_xTaskGetIdleTaskHandle          1
#define INCLUDE_eTaskGetState                   1
#define INCLUDE_xTimerPendFunctionCall          1
#define INCLUDE_xTaskAbortDelay                 1
#define INCLUDE_xTaskGetHandle                  1
#define INCLUDE_xTaskResumeFromISR              1

/* ─── Cortex-M port hook (required by FreeRTOS ARM_CM7 port) ────────────── */
#define vPortSVCHandler     SVC_Handler
#define xPortPendSVHandler  PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#define configUSE_16_BIT_TICKS    0

#endif /* FREERTOS_CONFIG_H */
