/**
 * \file
 *
 * \brief SAMD10/SAMD11 DMAC Application Note Example for the case 'ADC_DMAC_MEM_MEM_USART'
 *
 * Copyright (C) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
 
 /*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include <string.h>

#if defined(ADC_DMAC_MEM_MEM_USART)

/* FUNCTION PROTOTYPES */

/*! \brief Initializes and enables ADC */
void configure_adc(void);

/*! \brief Initializes and enables SERCOM - USART */
void configure_usart(void);

/*! \brief Initializes and enables PORT */
void configure_port(void);

/*! \brief Initializes and enables System Timer (SysTick) */
void systick_init(void);

/*! This function calculates number of cycles taken from SysTick time stamp */
uint32_t calculate_cycles_taken(uint32_t start_cycle, uint32_t end_cycle);

/*! \brief Initializes and enables DMA Channel */
void configure_dma_resource(struct dma_resource *resource, uint8_t channel_num);

/*! \brief Configure descriptor for DMA channel */
void setup_transfer_descriptor(DmacDescriptor *descriptor, uint8_t descriptor_num);

/*! \brief Initializes and enables DMAC */
void configure_dma(void);

/*! \brief Initializes and enables EVSYS */
void configure_event(void);


/* MACRO Definitions */

/*! Maximum reload value that can be loaded to SysTick */
#define SYSTICK_MAX_VALUE  (SysTick_LOAD_RELOAD_Msk - 1) 

/*! Number of ADC samples to be taken and transferred (for with and without case) */
#define BLOCK_COUNT 1024

/**
 * \name DMA channel ID
 * @{
 */
#define DMAC_CHANNEL0_ID 0
#define DMAC_CHANNEL1_ID 1
#define DMAC_CHANNEL2_ID 2
/** @} */

/**
 * \name DMA descriptor ID
 * @{
 */
#define DMAC_DESCRIPTOR1_ID  1
#define DMAC_DESCRIPTOR2_ID  2
#define DMAC_DESCRIPTOR3_ID  3
/** @} */

/* GLOBAL VARIABLES DECLARATION */

/*! brief Flag to indicate DMA transfer done */
volatile bool adc_dma_transfer_is_done = false;

/*! brief Allocate Event channel resource */
struct events_resource event_resource;

/*! brief Allocate DMA channel resource */
struct dma_resource dmac_adc_channel0,dmac_adc_channel1,dmac_adc_channel2;

/*! brief DMA channel descriptor */
COMPILER_ALIGNED(16)
DmacDescriptor dmac_adc_descriptor1, dmac_adc_descriptor2, dmac_adc_descriptor3;


/*! SysTick variables to take time stamp at different instance */
uint32_t time_stamp1 =0,time_stamp2=0;

/*! brief Contains the number of cycles taken from SysTick time stamp */ 
uint32_t cycles_taken=0, idle_loop_count=0;

/*! brief  buffer tp store ADC result */
uint8_t adc_result[BLOCK_COUNT],adc_result_copy[BLOCK_COUNT];

/*! brief Initialize SysTick reload and overflow counter variable */
static volatile uint32_t systick_reload = 0,systick_counter = 0;

/*! brief  USART module instance */
struct usart_module usart_instance;

/*! brief ADC module instance */
struct adc_module adc_instance;

/*! brief PORT base address */
volatile PortGroup *const port_base = PORT;


/**
 * \name DMA channel call backs
 * @{
 */
 
 /*! \brief DMA Channel0 call back */
static void dmac_calback_channel0( struct dma_resource *resource) 
{

	#if defined (ENABLE_PORT_TOGGLE)
		/* 	 Use oscilloscope to probe the pin. */
		port_base->OUTTGL.reg = (1UL << PIN_PA14 % 32 );
	#endif
	/* Trigger channel1 transfer */
	dma_trigger_transfer(&dmac_adc_channel1);

}


/*! \brief DMA Channel1 call back */
static void dmac_calback_channel1( struct dma_resource *resource) 
{
	/* Enable and start channel2 transfer */
	dma_start_transfer_job(&dmac_adc_channel2);
}

/*! \brief DMA Channel2 call back */
static void dmac_calback_channel2( struct dma_resource *resource) 
{
	/* Indicate DMA transfer has been completed */
	adc_dma_transfer_is_done = true;
	/* Get time stamp */
	time_stamp2 = SysTick->VAL;
}
/* @} */



/**
 * \brief SysTick interrupt handler
 */
void SysTick_Handler(void)
{
	/* Increment the software counter */
	systick_counter++;
}

/**
 * \brief Initialize the SysTick timer
 *
 */
void systick_init ()
{
	/* Calculate the reload value */
	systick_reload = SYSTICK_MAX_VALUE;// Niyas - what is the need of this and what will be the interrupt time interval with this value? 

	/* Initialize software counter */
	systick_counter = 0;

	/* Disable the SYSTICK Counter */
	SysTick->CTRL &= (~SysTick_CTRL_ENABLE_Msk);

	/* set reload register */
	SysTick->LOAD  =  systick_reload;

	/* set Priority for Cortex-M0 System Interrupts */
	NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);

	/* Load the SysTick Counter Value */
	SysTick->VAL  = systick_reload;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
					SysTick_CTRL_TICKINT_Msk   |
					SysTick_CTRL_ENABLE_Msk;

	/* Enable SysTick interrupt */
	NVIC_EnableIRQ(SysTick_IRQn);
}

/**
 * \brief configure and enable SERCOM - USART
 */
void configure_usart(void)
{
	/* USART set up configuration */
	struct usart_config config_usart;

	/* USART base address */
	SercomUsart *const usart_hw	= SERCOM2;
	
	/* Get USART default configuration */
	usart_get_config_defaults(&config_usart);

	/* Configure USART baud rate and pad */
	config_usart.baudrate    = 460800;
	config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	config_usart.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	config_usart.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	config_usart.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	config_usart.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;

	/* Initialize USART */
	while (usart_init(&usart_instance,
	EDBG_CDC_MODULE, &config_usart) != STATUS_OK) {
	}

	/* Enable USART */
	usart_enable(&usart_instance);
	
	/* Enable USART transfer complete interrupt */
	usart_hw->INTENSET.reg	= SERCOM_USART_INTFLAG_TXC;

}



/**
 * \brief Configure each DMA channel
 * \param resource     Channel resource
 * \param channel_num  Channel number to be configured
 */
void configure_dma_resource(struct dma_resource *resource, uint8_t channel_num)
{
	/* DMA config set up */
	struct dma_resource_config config;

	/* Get default DMA configuration */
	dma_get_config_defaults(&config);

	switch (channel_num){

	case DMAC_CHANNEL0_ID:
			/* Trigger is enabled for each beat transfer */
			config.trigger_action = DMA_TRIGGER_ACTON_BEAT;
			/* Peripheral trigger source is ADC result ready */
			config.peripheral_trigger = ADC_DMAC_ID_RESRDY;
			/* Generate event once DMA transfer is done */
			config.event_config.event_output_enable = true;
			break;

	case DMAC_CHANNEL1_ID:
			/*
			 * Retain default configuration for channel 1
			 * I.e Transaction trigger transfer type, software trigger 
			 * source with even output disabled/
			 */
			break;

	case DMAC_CHANNEL2_ID:
			/* Triggers for every beat */
			config.trigger_action = DMA_TRIGGER_ACTON_BEAT;
			/* Peripheral trigger source is USART data register empty */
			config.peripheral_trigger = SERCOM2_DMAC_ID_TX;
			break;
	default:
			Assert(false);
			break;
	}

	/* Configure the DMA channel */
	dma_allocate(resource, &config);
}

/**
 * \brief Configure DMA channel descriptor 
 * \param descriptor      DMA channel descriptor
 * \param descriptor_num  Descriptor to be configured
 */
void setup_transfer_descriptor(DmacDescriptor *descriptor, uint8_t descriptor_num)
{
	/* DMA descriptor configuration setup */
	struct dma_descriptor_config descriptor_config;

	/* Get default configuration */
	dma_descriptor_get_config_defaults(&descriptor_config);

	/* Set beat size as byte */
	descriptor_config.beat_size = DMA_BEAT_SIZE_BYTE;
	/* Set block count as 1024 beats */
	descriptor_config.block_transfer_count = BLOCK_COUNT;
	/* Trigger interrupt once block transfer is complete */
	descriptor_config.block_action = DMA_BLOCK_ACTION_INT;

	switch (descriptor_num){

	case DMAC_DESCRIPTOR1_ID:
		/* Source address is static as it is ADC result register */
		descriptor_config.src_increment_enable = false;
		/*
		 * Enable event for every beat transfer (I.e. byte in this case)
		 * Every byte transfer occurs for each sample from ADC.
		 * I.e. Event is triggered for every ADC result ready.
		 */
		descriptor_config.event_output_selection = DMA_EVENT_OUTPUT_BEAT;

		/* Set source address as ADC RESULT register */
		descriptor_config.source_address = (uint32_t)(&ADC->RESULT.reg);
		/*
		 * Set destination address as adc_result buffer in RAM.
		 * NOTE : destination address increment is true as per default configuration.
		 */
		descriptor_config.destination_address = (uint32_t)(adc_result) + sizeof (adc_result);
		/* Link to next descriptor */
		descriptor_config.next_descriptor_address = (uint32_t)(&dmac_adc_descriptor2);

		break;

	case DMAC_DESCRIPTOR2_ID:
		/*
		 * Set source address as adc_result buffer in RAM.
		 * NOTE: source address increment is true as per default configuration.
		 */
		descriptor_config.source_address = (uint32_t)(adc_result) + sizeof (adc_result);
		/*
		 * Set destination address as adc_result_copy buffer in RAM.
		 * NOTE : destination address increment is true as per default configuration.
		 */
		descriptor_config.destination_address = (uint32_t)(adc_result_copy) + sizeof (adc_result_copy);
		/* Link to other descriptor */
		descriptor_config.next_descriptor_address = (uint32_t)(&dmac_adc_descriptor3);
		break;

	case DMAC_DESCRIPTOR3_ID:
		/* Set destination increment as static as it is USART DATA register */
		descriptor_config.dst_increment_enable = false;
		/*
		 * Set source address as adc_result_copy buffer in RAM.
		 * NOTE: source address increment is true as per default configuration.
		 */
		descriptor_config.source_address = (uint32_t)(adc_result_copy) + sizeof (adc_result_copy);
		/* Set destination address as USART DATA register */
		descriptor_config.destination_address = (uint32_t)(&SERCOM2->USART.DATA.reg);
		break;

	default:
		Assert(false);
		break;

	}

	/* Create descriptor */
	dma_descriptor_create(descriptor, &descriptor_config);

}

/**
 * \brief configure and enable DMA multiple channel (in this case it is 3)
 */
void configure_dma(void)
{
	/* Configure DMA channel 0 */
	configure_dma_resource(&dmac_adc_channel0, DMAC_CHANNEL0_ID);
	/* Configure DMA channel 1 */
	configure_dma_resource(&dmac_adc_channel1, DMAC_CHANNEL1_ID);
	/* Configure DMA channel 2 */
	configure_dma_resource(&dmac_adc_channel2, DMAC_CHANNEL2_ID);


	/* Configure descriptor for channel 1 */
	setup_transfer_descriptor(&dmac_adc_descriptor1, DMAC_DESCRIPTOR1_ID);
	/* Configure descriptor for channel 2 */
	setup_transfer_descriptor(&dmac_adc_descriptor2, DMAC_DESCRIPTOR2_ID);
	/* Configure descriptor for channel 3 */
	setup_transfer_descriptor(&dmac_adc_descriptor3, DMAC_DESCRIPTOR3_ID);


	/* Assign descriptor 1 to DMA channel 0 */
	dma_add_descriptor(&dmac_adc_channel0, &dmac_adc_descriptor1);
	/*
	 * Register call back for DMA channel 0 transfer complete interrupt
	 * which will get triggered for every block transfer (I.e. 1024 beats 
	 * in this case 
	 */
	dma_register_callback(&dmac_adc_channel0, dmac_calback_channel0,
		DMA_CALLBACK_TRANSFER_DONE);
	/* Enable Call back for channel 0 */
	dma_enable_callback(&dmac_adc_channel0, DMA_CALLBACK_TRANSFER_DONE);
	/* Enable DMA channel 0 and its interrupt */
	dma_start_transfer_job(&dmac_adc_channel0);

	/* Assign descriptor 2 to DMA channel 1 */
	dma_add_descriptor(&dmac_adc_channel1, &dmac_adc_descriptor1);
	/*
	* Register call back for DMA channel 1 transfer complete interrupt
	* which will get triggered for every block transfer (i.e. 1024 beats 
	* in this case 
	*/
	dma_register_callback(&dmac_adc_channel1, dmac_calback_channel1,
		DMA_CALLBACK_TRANSFER_DONE);
	/* Enable Call back for channel 1 */
	dma_enable_callback(&dmac_adc_channel1, DMA_CALLBACK_TRANSFER_DONE);
	/* Enable DMA channel 0 and its interrupt */
	dma_start_transfer_job(&dmac_adc_channel1);

	/* Assign descriptor 2 to DMA channel 1 */
	dma_add_descriptor(&dmac_adc_channel2, &dmac_adc_descriptor3);
	/*
	 * Register call back for DMA channel 1 transfer complete interrupt
	 * which will get triggered for every block transfer (I.e. 1024 beats 
	 * in this case 
	 */
	dma_register_callback(&dmac_adc_channel2, dmac_calback_channel2,
		DMA_CALLBACK_TRANSFER_DONE);
	/* Enable Call back for channel 1 */
	dma_enable_callback(&dmac_adc_channel2, DMA_CALLBACK_TRANSFER_DONE);
	/*
	 * NOTE : For this channel, it should be enabled only after channel 
	 * transfer is done. USART data register empty will trigger a transfer 
	 * for this channel and it will be empty by default. So, if it is 
	 * enabled at the beginning, the trigger will get lost even before data 
	 * is ready to be transferred. It is enabled at the DMA channel2 
	 * callback (I.e. after DMA channel transfer is completed).
	 */

}


/**
 * \brief Configure Event System (EVSYS) with DMA transfer done 
 * as source and ADC start conversion as user.
 * So for every beat transfer in channel 0, ADC next 
 * conversion will be triggered via EVSYS.
 * NOTE: DMA Channel 0 is configured for event generation
 *       in this application.
 */
void configure_event(void)
{
	/* Event set up configuration */
	struct events_config config_a;
	/* Get default configuration */
	events_get_config_defaults(&config_a);

	 /* Generator : DMAC Channel 0 */
	config_a.generator = EVSYS_ID_GEN_DMAC_CH_0;
	config_a.path      = EVENTS_PATH_ASYNCHRONOUS;
	config_a.edge_detect = EVENTS_EDGE_DETECT_NONE;

	/* Configure Event generator */
	events_allocate(&event_resource, &config_a);

	/* Configure Event User,. USER : ADC start conversion */
	events_attach_user(&event_resource, EVSYS_ID_USER_ADC_START);

}



/**
 * \brief Configure and enable ADC 
 */
void configure_adc(void)
{
	/* ADC configuration set up */
	struct adc_config config_adc;

	/* Get default ADC configuration */
	adc_get_config_defaults(&config_adc);

	config_adc.gain_factor     = ADC_GAIN_FACTOR_DIV2;
	config_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV64;
	config_adc.reference       = ADC_REFERENCE_INTVCC1;
	config_adc.positive_input  = ADC_POSITIVE_INPUT_PIN0;
	config_adc.resolution      = ADC_RESOLUTION_8BIT;
	config_adc.event_action    = ADC_EVENT_ACTION_START_CONV;

	/* Initialize ADC */
	adc_init(&adc_instance, ADC, &config_adc);

	/* Enable ADC module */
	adc_enable(&adc_instance);

}

/**
 * \brief Calculate number of cycles taken to execute certain number of 
 * instructions from the time stamp taken with system timer (SysTick)
 */
uint32_t calculate_cycles_taken(uint32_t start_cycle, uint32_t end_cycle)
{

	uint32_t total_cycles =0;

	/* Check if counter flow occurs */
	if (systick_counter == 0){
		/* Ensure Start cycle is greater than end cycle */
		if(start_cycle > end_cycle)
			total_cycles = start_cycle - end_cycle;
	}else if (systick_counter > 0){
		total_cycles = start_cycle + ((systick_counter-1) * SYSTICK_MAX_VALUE) 
							+ (SYSTICK_MAX_VALUE - end_cycle);
	}

	return total_cycles;
}

/**
 * \brief Configure port pins PA14 and PA16 as output with zero 
 * as initial out value.
 */
void configure_port(void)// Niyas - why this configuration? Can be conditional if it is for debugging
{
	/* Set PA14 and PA15 as output */
	port_base->DIRSET.reg = (1UL << PIN_PA14 % 32 ) | (1UL << PIN_PA16 % 32 );
	/* Set OUT value to zero */
	port_base->OUT.reg = (0UL << PIN_PA14 % 32 ) | (0UL << PIN_PA16 % 32 );

}


/**
 * \brief Main Application Routine                              \n
 * - Initialize the system clocks                               \n
 * NOTE: The clock should be configured in conf_clock.h         \n
 * - Configure port pins (PA14 and PA16) are used here          \n
 * - Enable Global Interrupt                                    \n
 * - Configure and enable USART                                 \n
 * - Configure and enable ADC                                   \n
 * - Configure and enable DMAC and EVSYS if DMAC mode is chosen \n
 * - Start first ADC conversion                                 \n
 * - Count idle loop count in forever loop                      \n
 */
int main(void)
{

	/* Initialize system clocks */
	system_init();

#if defined(ENABLE_PORT_TOGGLE)
	/* Configure PORT pins PA14 and PA16 are configured here
	 * NOTE: Use oscilloscope to probe the pin.
	 */
	configure_port();
#endif

	/* ENable Global interrupt */
	system_interrupt_enable_global();

	/* Start SysTick Timer */
	systick_init();
 
	/* Configure SERCOM - USART */
	configure_usart();

	/* Configure and enable ADC */
	configure_adc();

	/* Configure and enable EVSYS */
	configure_event();

	/* Configure and enable DMA channel and descriptor */
	configure_dma();


	/* Get the time stamp 1 before starting ADC transfer */
	time_stamp1 = SysTick->VAL;

	/*
	 * Trigger first ADC conversion through software.
	 * NOTE: In case of using DMA, further conversions are triggered through
	 * event generated when previous ADC result is transferred to destination 
	 * (can be USART DATA register [or] RAM buffer).
	 * When DMA is not used, further conversions are triggered via software in 
	 * ADC handler after each result ready.
	 */
	adc_start_conversion(&adc_instance);

	while (1){
		
		#if defined (ENABLE_PORT_TOGGLE)
			/* 	 Use oscilloscope to probe the pin. */
			port_base->OUTTGL.reg = (1UL << PIN_PA16 % 32 );
		#endif
		
		/* Increment idle count whenever application reached while(1) loop */
		idle_loop_count++;

		/*
		 * Check if 1024 bytes transfer is done in either case (I.e. with or without
		 * using DMA.
		 * 'adc_conv_done' flag is set to true in the ADC handler once 
		 * 'adc_sample_count' reaches BLOCK_COUNT.
		 * 'adc_dma_transfer_is_done' is set to true once DMA transfer is done 
		 * in DMA call back for channel zero when 'ADC_DMAC_USART' is chosen.
		 * When choosing ADC_DMAC_MEM_MEM_USART mode, 'adc_dma_transfer_is_done' 
		 * is set to true in DMA channel call back for channel 2.
		 * DMA channel is disabled once reaching BLOCK_COUNT (with DMA cases).
		 * ADC is disabled once reaching BLOBK_COUNT samples (without DMA cases).
		 */
		if (adc_dma_transfer_is_done == true){

			/*
			 * Calculate number of cycles taken from the time stamp 
			 * taken before start of the conversion and after 1024 transfer
			 * is completed.
			 * NOTE: This value in relation to the idle_loop_count is 
			 * used in calculating CPU usage.
			 */
			cycles_taken = calculate_cycles_taken(time_stamp1,time_stamp2);
				
			/* Write the CPU cycles taken on USART */
			usart_write_buffer_wait(&usart_instance, (uint8_t *)&cycles_taken, sizeof(cycles_taken));
			/* Print idle loop count on USART */
			usart_write_buffer_wait(&usart_instance,(uint8_t *)&idle_loop_count, sizeof(idle_loop_count));

			/*
			 * Enter into forever loop as all transfers are completed and 
			 * DMAC/ADC is disabled 
			 */
			while(1);
		}
	}

}//end of main


// Application Documentation
/*! \main page
 * \section intro Introduction
 * This application demonstrates CPU usage when an application is 
 * implemented with and without DMA. Also it demonstrates different 
 * DMA transfer types such as Peripheral to peripheral, Peripheral 
 * to memory, memory to memory and memory to peripheral.
 *
 * ADC is sampled and the result data is sent to USART. This application is 
 * implemented with and without DMAC. These different cases are chosen by 
 * switching compiler options in the file conf_dma.h. 
 * 
 * The CPU cycles taken is calculated for all the cases using 
 * System Timer (SysTick). A variable is also incremented in the while(1) loop
 * which executes whenever CPU is available. The proportion of these two values
 * are used to calculate the CPU usage for the chosen case.
 *
 * For more details about this application, please refer to the Application 
 * note "ATxxxxx : CPU Usage demonstration using DMAC Application" in the 
 * link http://www.atmel.com/devices/ATSAMD11D14A.aspx?tab=documents
 *
 * \section referenceinfo References
 * - SAMD10/11 device data sheet
 * - SAMD11 Xplained Pro board schematics
 * - IO1 Xplained board schematics
 * - ATxxxx Application note
 *
 * \section compinfo Compiler Support
 * This example application supports
 * - GNU GCC for AVR32
 *
 * \section deviceinfo Device support
 * - ATSAMD11/10 Series
 *
 * \author
 * Atmel Corporation : http://www.atmel.com \n
 */
#endif

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
