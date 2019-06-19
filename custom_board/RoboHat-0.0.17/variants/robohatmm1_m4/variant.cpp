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
  // 0/1 - SERCOM/UART (Serial1)
  { PORTB,  3, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, ADC_Channel15, TC6_CH1, TC7_CH1, EXTERNAL_INT_3 }, // SERCOM 5.1
  { PORTB,  2, PIO_SERCOM_ALT, PIN_ATTR_PWM_E, ADC_Channel14, TC6_CH0, TC7_CH0, EXTERNAL_INT_2 }, // SERCOM 5.0
    
  // 2..9 - SERVO
  { PORTA,  16, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH0, TC2_CH0, EXTERNAL_INT_0 }, // 
  { PORTA,  17, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH1, TC2_CH1, EXTERNAL_INT_1 }, // 
  { PORTA,  18, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH2, TC3_CH0, EXTERNAL_INT_2 }, // 
  { PORTA,  19, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH3, TC3_CH1, EXTERNAL_INT_3 }, // 
  { PORTA, 11, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH3, TC1_CH1, EXTERNAL_INT_11 },
  { PORTA, 10, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH2, TC1_CH2, EXTERNAL_INT_10 },
  { PORTA, 9, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH1, TC0_CH1, EXTERNAL_INT_9 },
  { PORTA, 8, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC0_CH0, TC0_CH0, EXTERNAL_INT_NMI },
  
  // D10 External NeoPixel
  { PORTA,  19, PIO_DIGITAL, PIN_ATTR_PWM_F, No_ADC_Channel, TCC1_CH3, TC3_CH1, EXTERNAL_INT_3 }, // D9
  
  // RC_CH
  { PORTA,  7, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel7, TC1_CH1, TC1_CH1, EXTERNAL_INT_7 },  // D2
  { PORTA,  6, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel6, TC1_CH0, TC1_CH0, EXTERNAL_INT_6 },
  { PORTA,  5, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel5, TC0_CH1, TC0_CH1, EXTERNAL_INT_5 },
  { PORTA,  4, PIO_ANALOG, (PIN_ATTR_ANALOG|PIN_ATTR_PWM_E), ADC_Channel4, TC0_CH0, TC0_CH0, EXTERNAL_INT_4 },



  // 13 (LED)
  { PORTA, 12, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // Yellow LED next to USB  

  // A0-A8 - Analog signal pins
  // A0 is duplicated since we mark it starting at analog1, so might as well!
  { PORTB,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel10, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },     // signal 1
  { PORTB,  2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel10, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 },     // signal 1
  { PORTB,  3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel11, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 },     // signal 2
  { PORTA,  15, PIO_ANALOG, (PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1, TC3_CH1, EXTERNAL_INT_15 }, // signal 5
  { PORTA,  18, PIO_ANALOG, (PIN_ATTR_PWM|PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH0, TC3_CH0, EXTERNAL_INT_2 }, // signal 6
  //{ PORTB, 22, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER|PIN_ATTR_ANALOG), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // signal 7
  //{ PORTB, 23, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER|PIN_ATTR_ANALOG), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // signal 8
  { PORTA, 2, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel0, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // signal 9
  { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // signal 10
  { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3 }, // signal 10
  
  // A8 IRQ
  { PORTA, 28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8 }, 

  // A9-A12 - 4 Captouch pins (also analog!)
  { PORTA,  4, PIO_ANALOG, 0, ADC_Channel4, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4 }, // Captouch 1
  { PORTA,  5, PIO_ANALOG, 0, ADC_Channel5, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 }, // Captouch 2
  { PORTA,  6, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel6, PWM1_CH0, TCC1_CH0, EXTERNAL_INT_6 }, // Captouch 3
  { PORTA,  7, PIO_ANALOG, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel7, PWM1_CH1, TCC1_CH1, EXTERNAL_INT_7 }, // Captouch 4

  // A13 - VIN sense pin
  { PORTB,  3, PIO_ANALOG, 0, ADC_Channel11, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2 }, // VIN sense divider

  /**************/
  // 28..31 - Secondary SPI
  // ----------------------
  { PORTA, 14, PIO_SERCOM,     (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // SPI Flash MISO SERCOM2.2
  { PORTA,  8, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // SPI Flash MOSI SERCOM2.0
  { PORTA,  9, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // SPI Flash SCK  SERCOM2.1
  { PORTA, 13, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13 }, // SPI Flash SS

  // 32..34 - USB
  // --------------------
  { PORTA, 28, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB Host enable
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP

  // 35..36 - fake sercom 5 serial
  { PORTB, 22, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6 }, // Sercom 5.2 UART RX
  { PORTB, 23, PIO_SERCOM_ALT, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7 }, // Sercom 5.3 UART TX

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
