/**
 * \file
 *
 * \brief Blood Pressure Sensor Application
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel
 *Support</a>
 */

/****************************************************************************************
*							        Includes											 *
****************************************************************************************/
#include <asf.h>
#include "platform.h"
#include "at_ble_api.h"
#include "console_serial.h"
#include "timer_hw.h"
#include "conf_extint.h"
#include "ble_manager.h"
#include "ble_utils.h"
#include "blp_sensor_app.h"
#include "blp_sensor.h"
/****************************************************************************************
*							        Globals												*
****************************************************************************************/
volatile bool button_pressed = false;

bool indication_sent = true;

bool notification_sent = true;

bool units = APP_DEFAULT_VAL;
/** flag to send notifications */
bool notification_flag = APP_DEFAULT_VAL;
/** flag to send indication */
bool indication_flag = APP_DEFAULT_VAL;
/** Flag to identify user request for indication and notification*/
bool user_request_flag =  APP_DEFAULT_VAL;
/** Counter to maintain interval of indication*/
volatile uint8_t timer_count = APP_DEFAULT_VAL;
/** flag to send one notification for one second*/
bool notify = 0;

bool app_state;

/** flags for reversing the direction of characteristic*
	 change for indication*/
bool incrementer_flag[7] = {1,1,1,1,1,1,1};

/** flags for reversing the direction of characteristic*
	 change for notification*/
bool notification_increment_flag[2] = {1,1};

/* Blood Pressure Measurement Current*
* Characteristic values for indication*/

/** Current systolic value  in mmhg*/
uint16_t systolic_val_mmhg = SYSTOLIC_MIN_MMHG;

/** Current diastolic value in mmhg*/
uint16_t diastolic_val_mmhg = DIASTOLIC_MIN_MMHG;

/** Current map value in mmhg*/
uint16_t map_val_mmhg = MAP_MIN_MMHG;

/** Current systolic in kpa*/
uint16_t systolic_val_kpa = SYSTOLIC_MIN_KPA;

/** current diastolic value in kpa*/
uint16_t diastolic_val_kpa = DIASTOLIC_MIN_KPA;

/** current map value in kpa*/
uint16_t map_val_kpa = MAP_MIN_KPA;

/** Current pulse rate value in kpa*/
uint16_t pulse_rate_val = PULSE_RATE_MIN;

/** Current time stamp */
uint8_t time_stamp[7];

/** Current year*/
uint16_t year_value = YEAR;

/* Intermediate Cuff Pressure Values for notificaiton */
uint16_t interim_diastolic_mmhg = DIASTOLIC_MIN_MMHG;

uint16_t interim_diastolic_kpa = DIASTOLIC_MIN_KPA; 

uint16_t interim_systolic_mmhg = SYSTOLIC_MIN_MMHG;

uint16_t interim_systolic_kpa = SYSTOLIC_MIN_KPA;

uint16_t interim_map_mmhg = MAP_MIN_MMHG;

uint16_t interim_map_kpa = MAP_MIN_KPA;

/****************************************************************************************
*							        Functions											*
****************************************************************************************/
/**
 * @brief app_connected_state profile notifies the application about state
 * @param[in] connected
 */
void app_connected_state(bool connected)
{
	app_state = connected;
	if (app_state == false)
	{
		//Resetting all the simulated values
		
		interim_diastolic_mmhg = DIASTOLIC_MIN_MMHG;
		interim_diastolic_kpa = DIASTOLIC_MIN_KPA;	
		interim_systolic_mmhg = SYSTOLIC_MIN_MMHG;
		interim_systolic_kpa = SYSTOLIC_MIN_KPA;
		interim_map_mmhg = MAP_MIN_MMHG;
		interim_map_kpa = MAP_MIN_KPA;
		systolic_val_mmhg = SYSTOLIC_MIN_MMHG;
		diastolic_val_mmhg = DIASTOLIC_MIN_MMHG;
		 map_val_mmhg = MAP_MIN_MMHG;
		 systolic_val_kpa = SYSTOLIC_MIN_KPA;
		 diastolic_val_kpa = DIASTOLIC_MIN_KPA;
		 map_val_kpa = MAP_MIN_KPA;
		pulse_rate_val = PULSE_RATE_MIN;
		units = ~units;
	} 
}

/** @brief Updating the time stamp
 *
 */
void update_time_stamp(void)
{
	if (time_stamp[6] == SECOND_MAX)
	{
		time_stamp[6] = SECONDS;
		if (time_stamp[5] == MINUTE_MAX)
		{
			time_stamp[5] = MINUTES;
			if (time_stamp[4] == HOUR_MAX)
			{
				time_stamp[4] = HOURS;
				if (time_stamp[3] == DAY_MAX)
				{
					time_stamp[3] = DAY;
					if (time_stamp[2] == MONTH_MAX)
					{
						time_stamp[2] = MONTH;
						if (time_stamp[0] == YEAR_MAX)
						{
							year_value = YEAR;
							 memcpy(&time_stamp[0],&year_value,2);
 						} else
						 {
							 year_value++;
							 memcpy(&time_stamp[0],&year_value,2);
						 }
					} else{
						time_stamp[2]++;
					}
				} else {
					time_stamp[3]++;
				}
			} else{
				time_stamp[4]++;
			}
		} else {
			time_stamp[5]++;
		}
	} else {
		time_stamp[6]++;
	}
	
}

/** @brief initializes the time stamp with default time stamp
 *
 */
void time_stamp_init(void)
{
	uint8_t idx = 0;
	uint16_t year_t = YEAR;
	memcpy(time_stamp,&year_t,2);
	idx += 2;
	
	time_stamp[idx++] = MONTH;
	time_stamp[idx++] = DAY;
	time_stamp[idx++] = HOURS;
	time_stamp[idx++] = MINUTES;
	time_stamp[idx++] = SECONDS;
}

/** @brief blp_notification_confirmation_handler called by ble manager 
 *	to give the status of notification sent
 *  @param[in] at_ble_cmd_complete_event_t address of the cmd completion
 */	
void app_notification_confirmation_handler(at_ble_cmd_complete_event_t *params)
{
	if (params->status == AT_BLE_SUCCESS)
	{
		DBG_LOG_DEV("App Notification Successfully sent over the air");
		notification_sent = true;
	} else {
		DBG_LOG_DEV("Sending Notification over the air failed");
		notification_sent = false;
	}
}

/** @brief blp_indication_confirmation_handler called by ble manager 
 *	to give the status of notification sent
 *  @param[in] at_ble_cmd_complete_event_t address of the cmd completion
 */	
void app_indication_confirmation_handler(at_ble_indication_confirmed_t *params)
{
	if (params->status == AT_BLE_SUCCESS)
	{
		DBG_LOG_DEV("App Indication successfully sent over the air");
		indication_sent = true;
	} else {
		DBG_LOG_DEV("Sending Notification over the air failed");
		indication_sent = false;
	}
}

/** @brief sends the characteristic data for the profile to send indication
 *
 */
void blp_char_indication(void)
{
	uint8_t blp_data[BLP_DATA_LEN];
	uint8_t idx = 0;
	
	DBG_LOG("\n\n");
	
	DBG_LOG("The Blood Pressure Values are:");
	/* initializing flags to zero*/
	blp_data[0] = 0;
	/** Blood pressure measurement flags */
	if (units)
	{
		/** Units in mmhg*/
			blp_data[idx] |= (0x1)  & ~(BLOOD_PRESSURE_UNITS_FLAG_MASK);
	} else {
		/** Units in kpa*/
		    blp_data[idx] |= (0x1)  | BLOOD_PRESSURE_UNITS_FLAG_MASK ;
	} 
	
	/** Appending the flags for time stamp , pulse rate, user id , mm status */
	blp_data[idx]	|= BLOOD_PRESSURE_TIME_FLAG_MASK;
	blp_data[idx]	|= BLOOD_PRESSURE_PULSE_FLAG_MASK;
	blp_data[idx]	|= BLOOD_PRESSURE_USERID_FLAG_MASK;
	blp_data[idx++] |= BLOOD_PRESSURE_MMT_STATUS_FLAG_MASK;

	/** Appending systolic value */
	if (units)
	{
		/** Appending systolic */
		if (incrementer_flag[0])
		{	if (systolic_val_mmhg <= SYSTOLIC_MAX_MMHG )
			{
				systolic_val_mmhg++;
				memcpy(&blp_data[idx],&systolic_val_mmhg,2);
				idx += 2;	
				DBG_LOG("%-12s","Systolic");
				DBG_LOG_CONT("   %d mmhg",systolic_val_mmhg);
			} 
			if (systolic_val_mmhg == SYSTOLIC_MAX_MMHG)
			{
				incrementer_flag[0] = false;
			}
		} else {
			if (systolic_val_mmhg >= SYSTOLIC_MIN_MMHG)
			{
				systolic_val_mmhg--;
				memcpy(&blp_data[idx],&systolic_val_mmhg,2);
				idx += 2;
				DBG_LOG("%-12s","Systolic");
				DBG_LOG_CONT("   %d mmhg",systolic_val_mmhg);
			}
			
			if (systolic_val_mmhg == SYSTOLIC_MIN_MMHG)
			{
				incrementer_flag[0] = true;
			}
		}
		
		/** Appending diastolic in mmhg */
		if (incrementer_flag[1])
		{	if (diastolic_val_mmhg <= DIASTOLIC_MAX_MMHG )
			{
				diastolic_val_mmhg++;
				memcpy(&blp_data[idx],&diastolic_val_mmhg,2);
				idx += 2;
				DBG_LOG("%-12s","Diastolic");
				DBG_LOG_CONT("   %d mmhg",diastolic_val_mmhg);
			}
			if (diastolic_val_mmhg == DIASTOLIC_MAX_MMHG)
			{
				incrementer_flag[1] = false;
			}
		} else {
			if (diastolic_val_mmhg >= DIASTOLIC_MIN_MMHG)
			{
				diastolic_val_mmhg--;
				memcpy(&blp_data[idx],&diastolic_val_mmhg,2);
				idx += 2;
				DBG_LOG("%-12s","Diastolic");
				DBG_LOG_CONT("   %d mmhg",diastolic_val_mmhg);
			}
			
			if (diastolic_val_mmhg == DIASTOLIC_MIN_MMHG)
			{
				incrementer_flag[1] = true;
			}
		} 
		
		/** Appending map in mmhg */
		if (incrementer_flag[2])
		{	if (map_val_mmhg <= MAP_MAX_MMHG )
			{
				map_val_mmhg++;
				memcpy(&blp_data[idx],&map_val_mmhg,2);
				idx += 2;
				DBG_LOG("%-12s","Map");
				DBG_LOG_CONT("   %d mmhg",map_val_mmhg);	
			}
			if (map_val_mmhg == MAP_MAX_MMHG)
			{
				incrementer_flag[2] = false;
			}
			} else {
			if (map_val_mmhg >= MAP_MIN_MMHG)
			{
				map_val_mmhg--;
				memcpy(&blp_data[idx],&map_val_mmhg,2);
				idx += 2;
				DBG_LOG("%-12s","Map");
				DBG_LOG_CONT("   %d mmhg",map_val_mmhg);		
			}
			
			if (map_val_mmhg == MAP_MIN_MMHG)
			{
				incrementer_flag[2] = true;
			}
		}
		
	} else
	{
		/** Appending systolic in kpa*/
		if (incrementer_flag[3])
		{	if (systolic_val_kpa <= SYSTOLIC_MAX_KPA )
			{
				systolic_val_kpa++;
				memcpy(&blp_data[idx],&systolic_val_kpa,2);
				idx += 2;
				DBG_LOG("%-12s","Systolic");
				DBG_LOG_CONT("   %02d kpa",systolic_val_kpa);				
			}
			if (systolic_val_kpa == SYSTOLIC_MAX_KPA)
			{
				incrementer_flag[3] = false;
			}
			} else {
			if (systolic_val_kpa >= SYSTOLIC_MIN_KPA)
			{
				systolic_val_kpa--;
				memcpy(&blp_data[idx],&systolic_val_kpa,2);
				idx += 2;
				DBG_LOG("%-12s","Systolic");
				DBG_LOG_CONT("   %02d kpa",systolic_val_kpa);
			}
			
			if (systolic_val_kpa == SYSTOLIC_MIN_KPA)
			{
				incrementer_flag[3] = true;
			}
		}
		
		/** Appending diastolic in kpa */
		if (incrementer_flag[4])
		{	if (diastolic_val_kpa <= DIASTOLIC_MAX_KPA )
			{
				diastolic_val_kpa++;
				memcpy(&blp_data[idx],&diastolic_val_kpa,2);
				idx += 2;
				DBG_LOG("%-12s","Diastolic");
				DBG_LOG_CONT("   %02d kpa",diastolic_val_kpa);
			}
			if (diastolic_val_kpa == DIASTOLIC_MAX_KPA)
			{
				incrementer_flag[4] = false;
			}
			} else {
			if (DIASTOLIC_MAX_KPA >= DIASTOLIC_MIN_KPA)
			{
				diastolic_val_kpa--;
				memcpy(&blp_data[idx],&diastolic_val_kpa,2);
				idx += 2;
				DBG_LOG("%-12s","Diastolic");
				DBG_LOG_CONT("   %02d kpa",diastolic_val_kpa);
			}
			
			if (diastolic_val_kpa == DIASTOLIC_MIN_KPA)
			{
				incrementer_flag[4] = true;
			}
		}
		
		/** Appending map in kpa */
		if (incrementer_flag[5])
		{	if (map_val_kpa <= MAP_MAX_KPA)
			{
				map_val_kpa++;
				memcpy(&blp_data[idx],&map_val_kpa,2);
				idx += 2;
			DBG_LOG("%-12s","Map");
			DBG_LOG_CONT("   %02d kpa",map_val_kpa);	
			}
			if (map_val_kpa == MAP_MAX_KPA)
			{
				incrementer_flag[5] = false;
			}
			} else {
			if (map_val_kpa >= MAP_MIN_KPA)
			{
				map_val_kpa--;
				memcpy(&blp_data[idx],&map_val_kpa,2);
				idx += 2;	
					DBG_LOG("%-12s","Map");
					DBG_LOG_CONT("   %02d kpa",map_val_kpa);
			}
			
			if (map_val_kpa == MAP_MIN_KPA)
			{
				incrementer_flag[5] = true;
			}
		}
	}
	
	/** Appending time stamp */	
	memcpy(&blp_data[idx],time_stamp,sizeof(time_stamp));
	idx += sizeof(time_stamp);
		
	/** Appending pulse rate */
	if (incrementer_flag[6])
	{
		if (pulse_rate_val <= PULSE_RATE_MAX)	
		{
			pulse_rate_val++;
			memcpy(&blp_data[idx],&pulse_rate_val,2);
			idx += 2;
		
			DBG_LOG("%-12s","Pulserate");
			DBG_LOG_CONT("   %d bpm",pulse_rate_val);
		} 
		if (pulse_rate_val == PULSE_RATE_MAX) 
		{
			incrementer_flag[6] = false;
		}
	} else {
		if (pulse_rate_val >= PULSE_RATE_MIN)
		{
			
			pulse_rate_val--;
			memcpy(&blp_data[idx],&pulse_rate_val,2);
			idx += 2;
			DBG_LOG("%-12s","Pulserate");
			DBG_LOG_CONT("   %d bpm",pulse_rate_val);
			
		}
		if (pulse_rate_val == PULSE_RATE_MIN)
		{
			incrementer_flag[6] = true;
		}
	}
	
		//DBG_LOG("Time: %d : %02d : %02d : %02d : %02d : %02d ",year,month,day
		//,hour,min,sec);
		//DBG_LOG("\n\n");
	/** Appending User id */	
	if (units)
	{
		blp_data[idx++] = USERID_1;
	} else {
		blp_data[idx++] = USERID_2;
	}
	
	/** Appending Measurement status field */
	blp_data[idx++] = 0xf;
	blp_data[idx++] = 0xf;			
	blp_sensor_send_indication(blp_data,idx);	
}

/** @brief sends the characteristic data for profile to send notification
 *
 */
void blp_char_notification(void)
{
	uint8_t blp_data[BLP_DATA_LEN];	
	uint8_t idx = 0;
	blp_data[0] = 0;
	
	/** Blood pressure measurement flags */
	if (units)
	{
		/** Units in mmhg*/
		blp_data[idx++] |= (0x1)  & ~(BLOOD_PRESSURE_UNITS_FLAG_MASK);
		blp_data[0] = blp_data[0] & 1;
		
		/** Appending systolic in mmhg*/
		if (notification_increment_flag[0])
		{	if (interim_systolic_mmhg <= SYSTOLIC_MAX_MMHG )
			{
				DBG_LOG("Cuff pressure  %d mmhg",interim_systolic_mmhg);
				memcpy(&blp_data[idx],&interim_systolic_mmhg,2);
				idx += 2;
				interim_systolic_mmhg++;
			}
			if (interim_systolic_mmhg == SYSTOLIC_MAX_MMHG)
			{
				notification_increment_flag[0] = false;
			}
		} else {
			if (interim_systolic_mmhg >= SYSTOLIC_MIN_MMHG)
			{
				DBG_LOG("Cuff pressure  %d mmhg",interim_systolic_mmhg);
				memcpy(&blp_data[idx],&interim_systolic_mmhg,2);
				idx += 2;
				interim_systolic_mmhg--;
			}
			
			if (interim_systolic_mmhg == SYSTOLIC_MIN_MMHG)
			{
				notification_increment_flag[0] = true;
			}
		}
			/**Appending the diastolic */
				blp_data[idx++] = 0;
				blp_data[idx++] = 0;
			/**Appending the map */
				blp_data[idx++] = 0;
				blp_data[idx++] = 0;
		} else {
		/** Units in kpa*/
		blp_data[idx++] |=  (0x1)  | BLOOD_PRESSURE_UNITS_FLAG_MASK;
		blp_data[0] = blp_data[0] & 1;
		
		/** Appending systolic in kpa*/
		if (notification_increment_flag[1])
		{	if (interim_systolic_kpa <= SYSTOLIC_MAX_KPA )
			{
				DBG_LOG("Cuff pressure  %02d kpa",interim_systolic_kpa);
				memcpy(&blp_data[idx],&interim_systolic_kpa,2);
				idx += 2;
				interim_systolic_kpa++;
			}
			if (interim_systolic_kpa == SYSTOLIC_MAX_KPA)
			{
				notification_increment_flag[1] = false;
			}
		} else {
			if (interim_systolic_kpa >= SYSTOLIC_MIN_KPA)
			{
				DBG_LOG("Cuff pressure  %02d kpa",interim_systolic_kpa);
				memcpy(&blp_data[idx],&interim_systolic_kpa,2);
				idx += 2;
				interim_systolic_kpa--;
			}
			
			if (interim_systolic_kpa == SYSTOLIC_MIN_KPA)
			{
				notification_increment_flag[1] = true;
			}
		}
		/** Appending diastolic in kpa*/
		blp_data[idx++] = 0;
		blp_data[idx++] = 0;
		
		/** Appending map in kpa */
		blp_data[idx++] = 0;
		blp_data[idx++] = 0;
		
		
	}
	blp_sensor_send_notification(blp_data,idx);
}
/** @brief notification handler function called by the profile
 *	@param[in] enable will give weather notification has to enabled
 *  or disabled.
 */
void app_notification_handler(bool enable)
{
	notification_flag = enable;
	
	if (notification_flag)
	{
		DBG_LOG("Notifications enabled by the remote device for interim cuff pressure");
		
	} else{
		DBG_LOG("Disabled notifications by the remote device for interim cuff pressure");
	}
}

/** @brief indication handler function called by the profile
 *	@param[in] enable will give weather indication has to enabled
 *  or disabled.
 */
void app_indication_handler(bool enable)
{
	uint8_t blp_data[BLP_DATA_LEN];
	uint8_t idx = 0;	 
	indication_flag = enable;

	if (indication_flag)
	{
		DBG_LOG("Indications enabled by the remote device for blood pressure\n ");
		if (units)
		{
			blp_data[idx++] = 0;
			DBG_LOG("Systolic       %02d mmhg",systolic_val_mmhg);
			memcpy(&blp_data[idx],&systolic_val_mmhg,2);
			idx += 2;
			DBG_LOG("Diastolic      %02d mmhg",diastolic_val_mmhg);
			memcpy(&blp_data[idx],&diastolic_val_mmhg,2);
			idx += 2;
			DBG_LOG("Map            %02d mmhg",map_val_mmhg);
			memcpy(&blp_data[idx],&map_val_mmhg,2);
			idx += 2;
		} else {
			blp_data[idx++] = 0x1;
			memcpy(&blp_data[idx],&systolic_val_kpa,2);
			idx += 2;
			DBG_LOG("Systolic       %02d kpa",systolic_val_kpa);
			memcpy(&blp_data[idx],&diastolic_val_kpa,2);
			idx += 2;
			DBG_LOG("Diastolic      %02d kpa",diastolic_val_kpa);
			memcpy(&blp_data[idx],&map_val_kpa,2);
			idx += 2;
			DBG_LOG("Map            %02d kpa",map_val_kpa);
		}
		
		blp_data[0]	|= BLOOD_PRESSURE_PULSE_FLAG_MASK;
			DBG_LOG("Pulse rate     %d bpm",pulse_rate_val);
		memcpy(&blp_data[idx],&pulse_rate_val,2);
		idx += 2;
		//DBG_LOG("Flags are %d and length is %d",blp_data[0],idx);
		
		/* Sending the default notification for the first time */
		blp_sensor_send_indication(blp_data,idx);	
	} else {
		DBG_LOG("Disabled indication by the remote server for blood pressure");
	}
}


/**
 * @brief Button Press Callback
 */
void button_cb(void)
{
	if (button_pressed == false)
	{
		button_pressed = true;
		return;
	}
	
	if (app_state)
	{
	
		if (user_request_flag == false)
		{
			if (indication_flag)
			{
				/** For changing the units for each button press*/
				units = !units;
		
				/** To trigger the blood pressure indication */
				user_request_flag = true;
		
				timer_count = 0;
				if (notification_flag)
				{
					/*start the timer and enable notifications and send indication and then stop the timer*/
					DBG_LOG("\r\nStarted sending Interim Cuff Pressure Values");
				}	
			}
		}
	}
	
}

/**
 * \brief Timer callback handler called on timer expiry
 */
void timer_callback_handler(void)
{
	if (user_request_flag)
	{
		timer_count++;	
		notify = true;
	} 
	update_time_stamp();
}

/**
 * \brief Heart Rate Sensor Application main function
 */
int main(void)
{
	#if SAMG55
	/* Initialize the SAM system. */
	sysclk_init();
	board_init();
	#elif SAM0
	system_init();
	#endif

	/* Initialize the button */
	button_init();

	/* Initialize serial console */
	serial_console_init();

	/* Initialize the hardware timer */
	hw_timer_init();

	/* Register the callback */
	hw_timer_register_callback(timer_callback_handler);
	
	/** Initializing the application time stamp*/
	time_stamp_init();
	
	/** Start the timer */
	hw_timer_start(TIMER_INTERVAL);
	
	DBG_LOG("Initializing Blood Pressure Sensor Application");

	/* Registering the app_notification_handler with the profile */
	register_blp_notification_handler(app_notification_handler);
	
	/* Registering the app_indication_handler with the profile */
	register_blp_indication_handler(app_indication_handler);
	
	/* Register the connected call back with the profile */
	register_connected_callback(app_connected_state);
	
	/* Register the notification confirmed call back with ble manager */
	register_ble_notification_confirmed_cb(app_notification_confirmation_handler);
	
	/* Register the indication confirmed call back with ble manager */
	register_ble_indication_confirmed_cb(app_indication_confirmation_handler);
	
	/* initialize the ble chip  and Set the device mac address */
	ble_device_init(NULL);

	/* Capturing the events  */
	while (1) {
		ble_event_task();
	
		if (user_request_flag )
		{
			if (indication_flag)
			{
				
				if (timer_count < INDICATION_TIMER_VAL )
				{
					
					if (notification_flag)
					{
						if (notify)
						{
							/* send a notification */
							if (notification_sent)
							{
								blp_char_notification();
							}
							notify = 0;
						}	
					}
				}
				
				if (timer_count == INDICATION_TIMER_VAL)
				{
					if (indication_sent)
					{
						/* Send a indication */
						blp_char_indication();
						user_request_flag = 0;
						timer_count = 0;
					}
				}
			}	
		}
	}
	return 0;
}

