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
const PinDescription g_APinDescription[]=
{
  // 0..13 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1) - for GPS
  { PORTB,  3, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, ADC_Channel15, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // SERCOM 5.1
  { PORTB,  2, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // SERCOM 5.0
    
  // 2..9 - SERVO
  { PORTA,  18, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH2, TC3_CH0, EXTERNAL_INT_2 }, //
  { PORTA,  19, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH3, TC3_CH1, EXTERNAL_INT_3 }, // 
   
  { PORTA,  17, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH1, TC2_CH1, EXTERNAL_INT_1 }, // 
  { PORTA,  16, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH0, TC2_CH0, EXTERNAL_INT_0 }, // 
  
  { PORTA, 11, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH3, TC1_CH1, EXTERNAL_INT_11 },
  { PORTA, 10, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH2, TC1_CH0, EXTERNAL_INT_10 },
  { PORTA, 9, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH1, TC0_CH1, EXTERNAL_INT_9 },
  { PORTA, 8, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH0, TC0_CH0, EXTERNAL_INT_NMI },
  
  // 10..12 - SPI pins (MISO,MOSI,SCK)
  // ----------------------
  { PORTB,  8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, // MISO: SERCOM4/PAD[0]
  { PORTB, 10, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10 }, // MOSI: SERCOM4/PAD[2]
  { PORTB, 11, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // SCK: SERCOM4/PAD[3]
  
  // 13 (LED)
  { PORTA, 12, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // Red LED 
  
  // 14..17 - A0..A3 RC_CH
  { PORTA,  7, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel7, TC1_CH1, TC1_CH1, EXTERNAL_INT_7 },  // D2
  { PORTA,  6, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel6, TC1_CH0, TC1_CH0, EXTERNAL_INT_6 },
  { PORTA,  5, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel5, TC0_CH1, TC0_CH1, EXTERNAL_INT_5 },
  { PORTA,  4, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel4, TC0_CH0, TC0_CH0, EXTERNAL_INT_4 },
  
  // 18..19 - A4..A5
  { PORTA,  19, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH3, TC3_CH1, EXTERNAL_INT_3 }, // External NeoPixel
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // battery
  
  // Extra Analog pin #20
  { PORTA,   7, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel7, TC1_CH1, TC1_CH1, EXTERNAL_INT_7 },  // A6 aka A0

  // 21..22 - I2C pins (SDA/SCL)
  // ----------------------
  { PORTA, 22, PIO_SERCOM, PIN_ATTR_PWM_E, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // SDA: SERCOM3/PAD[0]
  { PORTA, 23, PIO_SERCOM, PIN_ATTR_PWM_E, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // SCL: SERCOM3/PAD[1]
  
  // 23..26 - Secondary SPI (SPI Flash)
  // ----------------------
  { PORTA, 14, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 },  // SPI Flash MISO: SERCOM2/PAD[2]
  { PORTA, 12, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 },  // SPI Flash MOSI: SERCOM2/PAD[0]
  { PORTA, 13, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 },  // SPI Flash SCK : SERCOM2/PAD[1]
  
  // 25..27 - USB
  // --------------------
  { PORTA, 27, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11 }, // USB Host enable
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, // USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 }, // USB/DP

  // 29 (AREF)
  { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // DAC/VREFP

  // ----------------------
  // 30 - 31 Alternate use of A0 and A1 (DAC output)
  { PORTA,  2, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // DAC/VOUT[0]
  { PORTA,  5, PIO_ANALOG, PIN_ATTR_ANALOG, DAC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // DAC/VOUT[1]

  // 32..33 - I2C pins for GPS (SDA/SCL)
  // ----------------------
  { PORTA,  1, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH1, TC2_CH1, EXTERNAL_INT_1 }, // SCL: SERCOM1/PAD[1]
  { PORTA,  0, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, No_ADC_Channel, TC2_CH0, TC2_CH0, EXTERNAL_INT_0 }, // SDA: SERCOM1/PAD[0]
  
  // 34..35 - Slave Select
  { PORTA,  15, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC2_CH1, TC3_CH1, EXTERNAL_INT_15 }, // Flash SS
  { PORTB,  9, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel3, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9 },  // SPI SS
  
  // 36..38 - Secondary SPI (SPI Flash)
  // ----------------------
  { PORTA, 14, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14 },  // SPI Flash MISO: SERCOM2/PAD[2]
  { PORTA, 12, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12 },  // SPI Flash MOSI: SERCOM2/PAD[0]
  { PORTA, 13, PIO_SERCOM, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 },  // SPI Flash SCK : SERCOM2/PAD[1]
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

Uart Serial1( &sercom3, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM3_0_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM3_1_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM3_2_Handler()
{
  Serial1.IrqHandler();
}
void SERCOM3_3_Handler()
{
  Serial1.IrqHandler();
}
