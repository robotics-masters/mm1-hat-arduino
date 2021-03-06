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

#ifndef _VARIANT_ROBOHATMM1_MM1_M4_
#define _VARIANT_ROBOHATMM1_MM1_M4_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK        (F_CPU)

#define VARIANT_GCLK0_FREQ (F_CPU)
#define VARIANT_GCLK1_FREQ (48000000UL)
#define VARIANT_GCLK2_FREQ (100000000UL)

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
#define PINS_COUNT           (46u)
#define NUM_DIGITAL_PINS     (27u)
#define NUM_ANALOG_INPUTS    (7u)
#define NUM_ANALOG_OUTPUTS   (2u)
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + PIN_A0 : -1)

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
//other pins
#define BUTTON               (10u)
#define PIN_NEOPIXEL         (11u)
#define BATTERY              (12u)
#define POWER_OFF            (18u)
#define GPIO24               (19u)
#define GPIO25               (20u)

/*
 * PWM pins
 */
#define PIN_SERVO1               (2ul)
#define PIN_SERVO2               (PIN_SERVO1 + 1)
#define PIN_SERVO3               (PIN_SERVO1 + 2)
#define PIN_SERVO4               (PIN_SERVO1 + 3)
#define PIN_SERVO5               (PIN_SERVO1 + 4)
#define PIN_SERVO6               (PIN_SERVO1 + 5)
#define PIN_SERVO7               (PIN_SERVO1 + 6)
#define PIN_SERVO8               (PIN_SERVO1 + 7)
  
static const uint8_t SERVO1 = PIN_SERVO1;
static const uint8_t SERVO2 = PIN_SERVO2;
static const uint8_t SERVO3 = PIN_SERVO3;
static const uint8_t SERVO4 = PIN_SERVO4;
static const uint8_t SERVO5 = PIN_SERVO5;  
static const uint8_t SERVO6 = PIN_SERVO6;
static const uint8_t SERVO7 = PIN_SERVO7;
static const uint8_t SERVO8 = PIN_SERVO8;
  
/*
 * Analog pins
 */
#define PIN_A0               (14ul)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;

static const uint8_t RCC1  = PIN_A0;
static const uint8_t RCC2  = PIN_A1;
static const uint8_t RCC3  = PIN_A2;
static const uint8_t RCC4  = PIN_A3;

#define PIN_DAC0             (30ul)
static const uint8_t DAC0 = PIN_DAC0;
#define PIN_DAC1             (31ul)
static const uint8_t DAC1 = PIN_DAC1;

#define ADC_RESOLUTION		12


// Other pins
#define PIN_ATN              (26ul)
static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */
// Serial1 (SERCOM1 - RPi)
#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL1_TX       (UART_TX_PAD_0)

// Serial2 (SERCOM5 - GPS)
#define PIN_SERIAL2_RX       (39ul)
#define PIN_SERIAL2_TX       (40ul)
#define PAD_SERIAL2_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL2_TX       (UART_TX_PAD_0)

// SerialGrove (SERCOM0 - Grove)
#define PIN_SERIAL3_RX       (45ul)
#define PIN_SERIAL3_TX       (46ul)
#define PAD_SERIAL3_RX       (SERCOM_RX_PAD_1)
#define PAD_SERIAL3_TX       (UART_TX_PAD_0)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2

/* SPI PORT */
#define PIN_SPI_MISO         (36u)
#define PIN_SPI_MOSI         (37u)
#define PIN_SPI_SCK          (38u)
#define PERIPH_SPI           sercom4
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_3

static const uint8_t SS   = 35 ;	// HW SS isn't used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/* SPI FLASH */
#define PIN_SPI1_MISO         (12u)
#define PIN_SPI1_MOSI         (10u)
#define PIN_SPI1_SCK          (11u)
#define PERIPH_SPI1           sercom2
#define PAD_SPI1_TX           SPI_PAD_0_SCK_1
#define PAD_SPI1_RX           SERCOM_RX_PAD_2

static const uint8_t SS1   = 34 ;	// HW SS isn't used. Set here only for reference.
static const uint8_t MOSI1 = PIN_SPI1_MOSI ;
static const uint8_t MISO1 = PIN_SPI1_MISO ;
static const uint8_t SCK1  = PIN_SPI1_SCK ;


/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 3

#define PIN_WIRE_SDA         (21u)
#define PIN_WIRE_SCL         (22u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_WIRE1_SDA         (32u)
#define PIN_WIRE1_SCL         (33u)
#define PERIPH_WIRE1          sercom1
#define WIRE1_IT_HANDLER      SERCOM1_Handler

static const uint8_t SDA1 = PIN_WIRE1_SDA;
static const uint8_t SCL1 = PIN_WIRE1_SCL;

#define PIN_WIRE2_SDA         (43u)
#define PIN_WIRE2_SCL         (44u)
#define PERIPH_WIRE2          sercom0
#define WIRE2_IT_HANDLER      SERCOM0_Handler

static const uint8_t GROVE_SDA = PIN_WIRE2_SDA;
static const uint8_t GROVE_SCL = PIN_WIRE2_SCL;


/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (26ul)
#define PIN_USB_DM          (27ul)
#define PIN_USB_DP          (28ul)

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 0

#define I2S_DEVICE          0
// no I2S on G19!

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

extern Uart Serial1; //RPI
extern Uart Serial2; //GPS
extern Uart Serial3; //GROVE

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
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_ROBOHATMM1_MM1_ */
