/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ROBOHAT_MM1_
#define _VARIANT_ROBOHAT_MM1_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (30u)
#define NUM_DIGITAL_PINS     (26u)
#define NUM_ANALOG_INPUTS    (4u)
#define NUM_ANALOG_OUTPUTS   (1u)

#define analogInputToDigitalPin(p)  ((p < 4u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs
#define PIN_LED_13           (13u)
#define PIN_LED              PIN_LED_13
#define LED_BUILTIN          PIN_LED_13


/* ROBO HAT MM1 pins */
#define ROBOHAT_SERVO1      (4ul)
#define ROBOHAT_SERVO2      (ROBOHAT_SERVO1 + 1)
#define ROBOHAT_SERVO3      (ROBOHAT_SERVO2 + 1)
#define ROBOHAT_SERVO4      (ROBOHAT_SERVO3 + 1)
#define ROBOHAT_SERVO5      (ROBOHAT_SERVO4 + 1)
#define ROBOHAT_SERVO6      (ROBOHAT_SERVO5 + 1)
#define ROBOHAT_SERVO7      (ROBOHAT_SERVO6 + 1)
#define ROBOHAT_SERVO8      (ROBOHAT_SERVO7 + 1)

static const uint8_t D0  = ROBOHAT_SERVO1;
static const uint8_t D1  = ROBOHAT_SERVO2;
static const uint8_t D2  = ROBOHAT_SERVO3;
static const uint8_t D3  = ROBOHAT_SERVO4;
static const uint8_t D4  = ROBOHAT_SERVO5;
static const uint8_t D5  = ROBOHAT_SERVO6;
static const uint8_t D6  = ROBOHAT_SERVO7;
static const uint8_t D7  = ROBOHAT_SERVO8;

#define ROBOHAT_EXTERNAL_NEOPIXEL (12ul)

#define ROBOHAT_RCH1      (14ul)
#define ROBOHAT_RCH2      (ROBOHAT_RCH1 + 1)
#define ROBOHAT_RCH3      (ROBOHAT_RCH2 + 1)
#define ROBOHAT_RCH4      (ROBOHAT_RCH3 + 1)

static const uint8_t A0  = ROBOHAT_RCH1;
static const uint8_t A1  = ROBOHAT_RCH2;
static const uint8_t A2  = ROBOHAT_RCH3;
static const uint8_t A3  = ROBOHAT_RCH4;


#define ADC_RESOLUTION		12

// Other pins
#define PIN_POWER_ENABLE              (37ul)
static const uint8_t POWER_ENABLE = PIN_POWER_ENABLE;
#define PIN_POWER_OFF                 (38ul)
static const uint8_t POWER_OFF = PIN_POWER_OFF;
/*
 * Serial interfaces
 */

// Serial
#define PIN_SERIAL_RX       (32ul)
#define PIN_SERIAL_TX       (33ul)
#define PAD_SERIAL_TX       (UART_TX_PAD_2)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_3)

// Serial1
#define PIN_SERIAL1_TX       (26ul)
#define PIN_SERIAL1_RX       (29ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_2)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_3)

// SerialGPS
#define PIN_SERIAL2_TX       (35ul)
#define PIN_SERIAL2_RX       (36ul)
#define PAD_SERIAL2_TX       (UART_TX_PAD_2)
#define PAD_SERIAL2_RX       (SERCOM_RX_PAD_3)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2

/* External SPI */
#define PIN_SPI_MISO         (18u)
#define PIN_SPI_MOSI         (19u)
#define PIN_SPI_SCK          (20u)
#define PERIPH_SPI           sercom4
#define PAD_SPI_TX    SPI_PAD_0_SCK_1
#define PAD_SPI_RX    SERCOM_RX_PAD_3

static const uint8_t SS   = 21 ;	// HW SS isn't used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/* SPI FLASH */
#define PIN_SPI1_MISO         (22u)
#define PIN_SPI1_MOSI         (23u)
#define PIN_SPI1_SCK          (24u)
#define PERIPH_SPI1          sercom2
#define PAD_SPI1_TX   SPI_PAD_0_SCK_1
#define PAD_SPI1_RX   SERCOM_RX_PAD_3

static const uint8_t SS1   = 25 ;	// HW SS isn't used. Set here only for reference.
static const uint8_t MOSI1 = PIN_SPI1_MOSI ;
static const uint8_t MISO1 = PIN_SPI1_MISO ;
static const uint8_t SCK1  = PIN_SPI1_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

//internal sensors
#define PIN_WIRE_SDA         (0u)
#define PIN_WIRE_SCL         (1u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

//external port
#define PIN_WIRE1_SDA         (2u)
#define PIN_WIRE1_SCL         (3u)
#define PERIPH_WIRE1          sercom1
#define WIRE1_IT_HANDLER      SERCOM1_Handler

static const uint8_t SDA1 = PIN_WIRE1_SDA;
static const uint8_t SCL1 = PIN_WIRE1_SCL;

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (28ul)
#define PIN_USB_DM          (33ul)
#define PIN_USB_DP          (34ul)
/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 0

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;
extern Uart Serial1;
extern Uart SerialGPS;


#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         Serial

#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#define SERIAL_PORT_HARDWARE        SerialGPS
#define SERIAL_PORT_HARDWARE_OPEN   SerialGPS
