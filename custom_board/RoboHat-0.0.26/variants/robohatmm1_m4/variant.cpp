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

#include "variant.h"

/*
 * Pins descriptions
 */

// TCC0 IOSET6
// TCC1 IOSET1
// TCC2 IOSET1
const PinDescription g_APinDescription[]=
{
  // 0..13 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1) - for RPi
  { PORTA,  17, PIO_SERCOM, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH1, TC2_CH1, EXTERNAL_INT_1 }, // SERCOM 1.1 [RX]
  { PORTA,  16, PIO_SERCOM, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH0, TC2_CH0, EXTERNAL_INT_0 }, // SERCOM 1.0 [TX]

  // 2..9 - SERVO
  { PORTA,  18, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH2, TC3_CH0, EXTERNAL_INT_2 }, //SERVO1
  { PORTA,  19, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH3, TC3_CH1, EXTERNAL_INT_3 }, //SERVO2
  { PORTA,  20, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH0, NOT_ON_TIMER, EXTERNAL_INT_4 }, //SERVO3
  { PORTA,  21, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH1, NOT_ON_TIMER, EXTERNAL_INT_5 }, //SERVO4
  { PORTA,  11, PIO_DIGITAL, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_F), ADC_Channel11, TCC0_CH3, TC1_CH1, EXTERNAL_INT_11 }, //SERVO5
  { PORTA,  10, PIO_DIGITAL, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_F), ADC_Channel10, TCC0_CH2, TC1_CH0, EXTERNAL_INT_10 }, //SERVO6
  { PORTA,  9, PIO_DIGITAL, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_F), ADC_Channel9, TCC0_CH1, TC0_CH1, EXTERNAL_INT_9 }, //SERVO7
  { PORTA,  8, PIO_DIGITAL, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_F), ADC_Channel8, TCC0_CH0, TC0_CH0, EXTERNAL_INT_NMI }, //SERVO8

  // 10 - BUTTON
  { PORTA,  27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, //BUTTON
  // 11 - NeoPixel
  { PORTB,  23, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // NeoPixel
  // 12 - BATTERY
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // BATTERY

  // 13 (LED)
  { PORTB, 22, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 },  // Red LED

  // 14..17 - A0..A3 RC_CH
  { PORTA,  7, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel7, NOT_ON_PWM, TC1_CH1, EXTERNAL_INT_7 },  // D2
  { PORTA,  6, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel6, NOT_ON_PWM, TC1_CH0, EXTERNAL_INT_6 },
  { PORTA,  5, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel5, NOT_ON_PWM, TC0_CH1, EXTERNAL_INT_5 },
  { PORTA,  4, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel4, NOT_ON_PWM, TC0_CH0, EXTERNAL_INT_4 },

  // 18 - POWER_OFF
  { PORTA, 3, PIO_DIGITAL, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_F), ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // DAC/VREFP
  // 19 - GPIO 24 SWDIO
  { PORTA, 31, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC2_CH0, NOT_ON_TIMER, EXTERNAL_INT_NMI },
  // 20 - GPIO 25 SWDCLK
  { PORTA, 30, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC2_CH1, NOT_ON_TIMER, EXTERNAL_INT_NMI },

  // 21..22 - I2C pins (SDA/SCL)
  // ----------------------
  { PORTA, 22, PIO_SERCOM, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH2, TC3_CH1, EXTERNAL_INT_6 }, // SDA: SERCOM3/PAD[0]
  { PORTA, 23, PIO_SERCOM, PIN_ATTR_PWM_G, No_ADC_Channel, TCC0_CH3, TC3_CH0, EXTERNAL_INT_7 }, // SCL: SERCOM3/PAD[1]

  // 23..25 - Secondary SPI (SPI Flash)
  // ----------------------
  { PORTA, 14, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 },  // SPI Flash MISO: SERCOM2/PAD[2]
  { PORTA, 12, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 },  // SPI Flash MOSI: SERCOM2/PAD[0]
  { PORTA, 13, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 },  // SPI Flash SCK : SERCOM2/PAD[1]

  // 26..28 - USB
  // --------------------
  { PORTA, 27, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // USB Host enable
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, // USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // USB/DP

  // 29 DAC/VREFP
  { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // DAC/VREFP

  // 30 Alternate use of A0 and A1 (DAC output)
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VOUT0
  { PORTA,  5, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // DAC/VOUT[1]

  // 32..33 - Secondary I2C pins (SDA1/SCL1)
  // ----------------------
  { PORTA,  0, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH0, TC2_CH0, EXTERNAL_INT_0 }, // SDA: SERCOM1/PAD[0]
  { PORTA,  1, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH1, TC2_CH1, EXTERNAL_INT_1 }, // SCL: SERCOM1/PAD[1]

  // 34..35 - Slave Select
  { PORTA,  15, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC2_CH1, TC3_CH1, EXTERNAL_INT_15 }, // Flash SS
  { PORTB, 10, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 },   // SPI PORT SS1 SERCOM4:PAD[2] Red

  // 36..38 - Secondary SPI (SPI Flash)
  // ----------------------
  { PORTB, 11, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 },   // SPI PORT MISO1  SERCOM4:PAD[3] White
  { PORTB,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel2, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 },    // SPI PORT MOSI1 SERCOM4:PAD[0] Black
  { PORTB,  9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, ADC_Channel3, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },         // SPI PORT SCLK SERCOM4:PAD[1] Grey

  // 39..40 - GPS Serial (GPS)
  { PORTB,  3, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // SERCOM 5.1
  { PORTB,  2, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // SERCOM 5.0

  // 41..42 - Grove Analog
  { PORTA, 9, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_F), ADC_Channel10, TCC0_CH1, TC0_CH1, EXTERNAL_INT_9 },
  { PORTA, 8, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_F), ADC_Channel11, TCC0_CH0, TC0_CH0, EXTERNAL_INT_NMI },
  //43..44 - Grove I2C
  { PORTA, 8, PIO_SERCOM, PIN_ATTR_DIGITAL, ADC_Channel11, TCC0_CH0, TC0_CH0, EXTERNAL_INT_NMI }, // SDA: SERCOM0/PAD[0]
  { PORTA, 9, PIO_SERCOM, PIN_ATTR_DIGITAL, ADC_Channel10, TCC0_CH1, TC0_CH1, EXTERNAL_INT_9 },   // SCL: SERCOM0/PAD[1]

  //45..46 - Grove UART
  { PORTA, 9, PIO_SERCOM, PIN_ATTR_DIGITAL, ADC_Channel10, TCC0_CH1, TC0_CH1, EXTERNAL_INT_9 }, //SERCOM 0.1 [RX]
  { PORTA, 8, PIO_SERCOM, PIN_ATTR_DIGITAL, ADC_Channel11, TCC0_CH0, TC0_CH0, EXTERNAL_INT_NMI }, //SERCOM 0.0 [TX]


} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC0, TC1, TC2, TC3 } ;
const uint32_t GCLK_CLKCTRL_IDs[TCC_INST_NUM+TC_INST_NUM] = { TCC0_GCLK_ID, TCC1_GCLK_ID, TCC2_GCLK_ID, TC0_GCLK_ID, TC1_GCLK_ID, TC2_GCLK_ID, TC3_GCLK_ID } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1(&sercom1, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ); // RPI (1)
Uart Serial2(&sercom5, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ); // GPS (5)
Uart Serial3(&sercom0, PIN_SERIAL3_RX, PIN_SERIAL3_TX, PAD_SERIAL3_RX, PAD_SERIAL3_TX ); // GROVE (0)

void SERCOM0_0_Handler()
{
  Serial3.IrqHandler();
}
void SERCOM0_1_Handler()
{
  Serial3.IrqHandler();
}
void SERCOM0_2_Handler()
{
  Serial3.IrqHandler();
}
void SERCOM0_3_Handler()
{
  Serial3.IrqHandler();
}

void SERCOM1_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM1_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM1_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM1_3_Handler()
{
  Serial1.IrqHandler();
}

void SERCOM5_0_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM5_1_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM5_2_Handler()
{
  Serial2.IrqHandler();
}
void SERCOM5_3_Handler()
{
  Serial2.IrqHandler();
}