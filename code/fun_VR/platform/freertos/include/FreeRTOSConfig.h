/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

/* Here is a good place to include header files that are required across
your application. */
#include "bsp.h"
    
#ifdef USE_SONIX_CONFIG
//#include "sonix_config.h"    
    #if (CONFIG_OS_FREERTOS == 0)
        #warning "RTOS has been disabled."
        #undef  CONFIG_FREERTOS_HEAP_SIZE
        #define CONFIG_FREERTOS_HEAP_SIZE           0
    #endif
#else
	#if !defined(CONFIG_FREERTOS_HEAP_SIZE)
	#define CONFIG_FREERTOS_HEAP_SIZE               20
#endif

#endif

#define configUSE_PREEMPTION					1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	0
#define configUSE_TICKLESS_IDLE					0
#define configCPU_CLOCK_HZ						( ( unsigned long ) CONFIG_CPU_CLOCK_MHZ * 1000000 )
#define configTICK_RATE_HZ						( ( portTickType ) 1000 )
#define configMAX_PRIORITIES					( ( unsigned portBASE_TYPE ) 30 )
#define configMINIMAL_STACK_SIZE				( ( unsigned short ) 60 )
#define configTOTAL_HEAP_SIZE					( ( size_t ) ( CONFIG_FREERTOS_HEAP_SIZE * 1024 ) )
#define configMAX_TASK_NAME_LEN					( 16 )
#define configUSE_16_BIT_TICKS					0
#define configIDLE_SHOULD_YIELD					1
#define configUSE_MUTEXES						1
#define configUSE_RECURSIVE_MUTEXES				1
#define configUSE_COUNTING_SEMAPHORES			1
#define configUSE_ALTERNATIVE_API				0
#define configQUEUE_REGISTRY_SIZE				8
#define configUSE_APPLICATION_TASK_TAG			1
#define configUSE_QUEUE_SETS					0
#define configUSE_TIME_SLICING					1
#define configUSE_NEWLIB_REENTRANT				0
#define configSUPPORT_STATIC_ALLOCATION         0
#define configCOMMAND_INT_MAX_OUTPUT_SIZE       1024
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 3

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK						0
#define configUSE_TICK_HOOK						0
#define configCHECK_FOR_STACK_OVERFLOW			1
#define configUSE_MALLOC_FAILED_HOOK			1

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS			0
#define configUSE_TRACE_FACILITY				0
#define configUSE_STATS_FORMATTING_FUNCTIONS	1

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES 					0
#define configMAX_CO_ROUTINE_PRIORITIES 		( 2 )

/* Software timer related definitions. */
#define configUSE_TIMERS						1
#define configTIMER_TASK_PRIORITY				( 2 )
#define configTIMER_QUEUE_LENGTH				5
#define configTIMER_TASK_STACK_DEPTH			( 380 )

/* Interrupt nesting behaviour configuration. */
#define configKERNEL_INTERRUPT_PRIORITY			(7<<5)//[dependent of processor]
#define configMAX_SYSCALL_INTERRUPT_PRIORITY	(3<<5)//[dependent on processor and application]
//#define configMAX_API_CALL_INTERRUPT_PRIORITY	[dependent on processor and application]

/* FreeRTOS MPU specific definitions. */
#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 0

/* Optional functions - most linkers will remove unused functions anyway. */
/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet				1
#define INCLUDE_uxTaskPriorityGet				1
#define INCLUDE_vTaskDelete						1
#define INCLUDE_vTaskCleanUpResources			1
#define INCLUDE_vTaskSuspend					1
#define INCLUDE_xResumeFromISR					0
#define INCLUDE_vTaskDelayUntil					1
#define INCLUDE_vTaskDelay						1
#define INCLUDE_xTaskAbortDelay                 0
#define INCLUDE_xTaskGetSchedulerState			1
#define INCLUDE_xTaskGetCurrentTaskHandle		1
#define INCLUDE_uxTaskGetStackHighWaterMark		1
#define INCLUDE_xTaskGetIdleTaskHandle			1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle	1
#define INCLUDE_pcTaskGetTaskName				1
#define INCLUDE_eTaskGetState					1

/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }


/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names - or at least those used in the unmodified vector table. */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#if configUSE_TRACE_FACILITY
#include "trcKernelPort.h"
//#include "trcRecorder.h"
#endif

#endif /* FREERTOS_CONFIG_H */

