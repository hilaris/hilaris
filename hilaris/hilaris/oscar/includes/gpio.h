/*	Oscar, a hardware abstraction framework for the LeanXcam and IndXcam.
	Copyright (C) 2008 Supercomputing Systems AG
	
	This library is free software; you can redistribute it and/or modify it
	under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation; either version 2.1 of the License, or (at
	your option) any later version.
	
	This library is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
	General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License
	along with this library; if not, write to the Free Software Foundation,
	Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*! @file
 * @brief Public GPIO module definition
 *
 * Contains the public definitions of the GPIO module.
 *
 */
#ifndef GPIO_PUB_H_
#define GPIO_PUB_H_

extern struct OscModule OscModule_gpio;

/*! @brief The GPIO pins that can be accessed from the application.
 * 
 * This is a list of all the GPIO names on all the supported hardware
 * platforms. Not all listed here may be available on your platform.
 * These are assigned to the same identifier as the corresponding pflags pin
 * driving them. */
#ifdef TARGET_TYPE_LEANXCAM
enum EnGpios
{
	GPIO_IN1 = 4,
	GPIO_IN2 = 7,
	GPIO_OUT1 = 2,
	GPIO_OUT2 = 6
};
#endif /* #ifdef TARGET_TYPE_LEANXCAM */

#ifdef TARGET_TYPE_LEANXRADIO
enum EnGpios
{
	GPIO_DCLK =	25,			/* PG9 */
	GPIO_DATA = 26,			/* PG10 */
	GPIO_CONFIG_N = 27,		/* PG11 */
	GPIO_STATUS_N = 28,		/* PG12 */
	GPIO_CONFDONE_N = 29 	/* GP13 */
};
#endif /* TARGET_TYPE_LEANXRADIO */

/*! @brief Defines whether the image trigger of the camera sensor is activated
 * internally from the camera module or from externally over an input
 * 
 * leanXcam only */
enum EnTriggerConfig
{
	/*! @brief Default: Internal triggering. */
	TRIGGER_INTERNAL,
	/*! @brief Trigger from external input2 (leanXcam) */
	TRIGGER_EXTERNAL_IN2
};


/*======================== API functions ===============================*/

/*********************************************************************//*!
 * @brief Set the state of an output
 * 
 * @param enGpio Identifier of the GPIO to be set.
 * @param bState Active state if true, inactive otherwise.
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioWrite(enum EnGpios enGpio, bool bState);

/*********************************************************************//*!
 * @brief Read the state of an input
 * 
 * @param enGpio Identifier of the GPIO to be read.
 * @param pbState GPIO input state will be written to this pointer.
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioRead(enum EnGpios enGpio, bool *pbState);

/*********************************************************************//*!
 * @brief Set the output/input polarity of a GPIO
 * 
 * The polarity in this sense is defined not as the polarity of the DSP
 * pin driving a GPIO, but rather as the polarity of the input/output of
 * the board after opto-couplers etc.
 * 
 * @param enGpio Identifier of the GPIO to be configured.
 * @param bLowActive True if pin is to be low-active, false otherwise.
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioSetupPolarity(enum EnGpios enGpio, bool bLowActive);

/*********************************************************************//*!
 * @brief Turn the onboard test-led on and off.
 * 
 * @param bOn TRUE turns LED on, FALSE turns it off.
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioSetTestLed(bool bOn);

/*********************************************************************//*!
 * @brief Toggle the onboard test led.
 * 
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioToggleTestLed();

/*********************************************************************//*!
 * @brief Trigger a new image with the internal trigger.
 * 
 * Both Gpio module and camera module must be configured to use
 * the internal image trigger.
 * @see OscGpioConfigImageTrigger
 * @see OscCamConfigImageTrigger
 * 
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioTriggerImage();

/*********************************************************************//*!
 * @brief Set the input for the image trigger of the camera sensor.
 * 
 * The default trigger input is set to internal triggering. Depending on the
 * hardware, external trigger inputs can be selected.
 * 
 * leanXcam only.
 * 
 * @param enConfig Trigger select.
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioConfigImageTrigger(enum EnTriggerConfig enConfig);

/*********************************************************************//*!
 * @brief Configure whether the LED_OUT pin from the image sensor is routed
 * to OUT2 or whether it can be used as a GPIO.
 * 
 * On the leanXcam hardware, the output OUT2 is a logical OR between the
 * corresponding DSP pin and the LED_OUT pin from the image sensor. This
 * means that if one wants to use it as a GPIO, the LED_OUT from the
 * sensor has to be disabled (done by OscCamConfigSensorLedOut) and in the
 * opposite case, where OUT2 should be assigned to LED_OUT, the DSP pin
 * has to be wired to zero (done by this function).
 * 
 * ! Must also call OscCamConfigSensorLedOut !
 * 
 * @see OscCamConfigSensorLedOut
 * 
 * leanXcam only.
 * 
 * @param bSensorLedOut If TRUE, the sensor LED out is routed to OUT2 and
 * it cannot be used as GPIO anymore.
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioConfigSensorLedOut(bool bSensorLedOut);

/*********************************************************************//*!
 * @brief Set the color of the onboard test led.
 * 
 * The leanXcam features a 2-color test led with a green and a red
 * channel that can be controlled separately.
 * 
 * Smooth color transitions are not supported yet.
 * 
 * leanXcam only.
 * 
 * @param red Brightness of the red channel.
 * @param green Brighntess of the green channel.
 * @return SUCCESS or an appropriate error code.
 *//*********************************************************************/
OSC_ERR OscGpioSetTestLedColor(uint8 red, uint8 green);


#endif /* GPIO_PUB_H_ */

