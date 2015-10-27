/* 
 * File:   A36926_001.h
 * Author: hwanetick
 *
 * Created on October 22, 2015, 11:04 AM
 */

#ifndef __A36926_001_H
#define	__A36926_001_H


#include <xc.h>
#include <libpic30.h>
#include <adc12.h>
#include <timer.h>
#include "ETM.h"
#include "P1395_CAN_SLAVE.h"
#include "A36926_001_SETTINGS.h"

#define FCY_CLK     10000000

extern ETMCanSyncMessage    etm_can_master_sync_message;


#define _SYNC_CONTROL_WORD                    *(unsigned int*)&etm_can_master_sync_message.sync_0_control_word

/*
  Hardware Module Resource Usage

  CAN1   - Used/Configured by ETM CAN
  Timer4 - Used/Configured by ETM CAN - Used to Time sending of messages (status update / logging data and such)
  Timer5 - Used/Configured by ETM CAN - Used for detecting error on can bus

  SPI2   - Used/Configured by LTC265X Module    -----> change to bus 2 in code
  I2C    - Used/Configured by EEPROM Module

  Timer3 - Used for 10msTicToc   -----> change to 3 in code

  ADC Module - See Below For Specifics

*/

// ---------- BASE A36926 I/O CONFIGURATION ----------------- //

#define PIC_DIG_IN_1      _RD8      //used  Temp
#define PIC_DIG_IN_2      _RD9      //used  Crwbr
#define PIC_DIG_IN_3      _RD10     //used  Htr OV OK
#define PIC_DIG_IN_4      _RD11
#define PIC_DIG_IN_5      _RD12
#define PIC_DIG_IN_6      _RD13
#define PIC_DIG_IN_7      _RD14
#define PIC_DIG_IN_8      _RD15

#define AUTO_INHIBIT_DETECT          _RA14   // This is INT3
#define RESET_DETECT                 _RG14



#define PIC_RELAY_OUT                _LATD3
#define PIC_OUTPUT_LAMBDA_SELECT     _LATD2
#define PIC_DIGITAL_OUT_2_NOT        _LATD1
#define PIC_DIGITAL_OUT_1_NOT        _LATD0
#define PIC_15V_SUPPLY_ENABLE        _LATA6

#define TEST_POINT_A                 _LATF6
#define TEST_POINT_B                 _LATF7
#define TEST_POINT_C                 _LATF8
#define TEST_POINT_D                 _LATF2
#define TEST_POINT_E                 _LATF3
#define TEST_POINT_F                 _LATB14


#define LED_OPERATIONAL              _LATA7
#define LED_A_RED                    _LATG12
#define LED_B_GREEN                  _LATG13



/*
  BASE ANALOG CONFIGURATION
  PIC_ADC_AN1  is on AN2
  PIC_ADC_AN2  is on AN3
  PIC_ADC_AN3  is on AN4
  PIC_ADC_AN4  is on AN5

  PIC_ADC_+15V_MON is on AN6
  PIC_ADC_-15V_MON is on AN7
  PIC_ADC_5V_MON   is on AN8
  PIC_ADC_TEST_DAC is on AN9
*/


// Pins that must be configured as outputs
/*
  A6,A7
  B14
  C
  D0,D1,D2,D3
  F2,F3,F6,F7,F8
  G12,G13
*/

#define A36926_TRISA_VALUE 0b1111111110111111
#define A36926_TRISB_VALUE 0b1011111111111111
#define A36926_TRISC_VALUE 0b1111111111111111
#define A36926_TRISD_VALUE 0b1111111111110000
#define A36926_TRISF_VALUE 0b1111111100110011
#define A36926_TRISG_VALUE 0b1100111111111111


//original code here

// ----------------- IO PIN CONFIGURATION -------------------- //
// All unused pins will be set to outputs and logic zero
// LAT values default to 0 at startup so they do not need to be manually set

// ----------------- DIGITAL INPUT PINS --------------- //
/*


  RD8  - Digital Input 1 - (unused)
  RD9  - Digital Input 2 - (unused)
  RD10 - Digital Input 3 - (unused)
  RD11 - Digital Input 4 - (unused)
  RD12 - Digital Input 5 - PIC INPUT FLOW PWM 5
  RD13 - Digital Input 6 - PIN INPUT TEMPERATURE OK
  RD14 - Digital Input 7 - PIC INPUT HEATER OV OK
  RD15 - Digital Input 8 - PIC INPUT CROWBAR UP

  RG14 - (unused) Reset Detect
  RA14 - (unused) Auto Inhibit Detect

  Analog Input Pins


  Pins that are overidden by a hardware module and should be left as inputs during port configuration
  RA9  ADC VREF-
  RA10 ADC VREF+

  RB0 PROGRAM
  RB1 PROGRAM
  RB2  - Analog Input - PIC ADC MAGNET IMON
  RB3  - Analog Input - PIC ADC HEATER IMON
  RB4  - Analog Input - PIC ADC MAGNET VMON
  RB5  - Analog Input - PIC ADC HEATER VMON
  RB6 -  Analog Input - PIC_ADC_+15V_MON
  RB7 -  Analog Input - PIC_ADC_-15V_MON
  RB8 -  Analog Input - PIC_ADC_5V_MON
  RB9 -  Analog Input - PIC_ADC_TEST_DAC
  RB10 -  Analog Input - unused
  RB11 -  Analog Input - unused
  RB12 -  Analog Input - unused
  RB13 -  Analog Input - unused
  RB14 -  Digital Output - TEST_POINT_F
  RB15 -  Analog Input - unused
 

  RF0 CAN 1
  RF1 CAN 1

  RG6 SPI 2
  RG7 SPI 2
  RG8 SPI 2

  RG2 I2C
  RG3 I2C

  Pins that are configured by other software modules and should be left as inputs during port configuration
  RC1  (DAC LDAC)
  RG15 (DAC CS/LD)


*/

//   ------------------  Digital Output Pins ---------------
/*

  RD0  - #PIC Digital Out 1 - (unused) Lambda Inhibit
  RD1  - #PIC Digital Out 2 - (unused)
  RD2  - Lamdba Voltage Select - (unused)
  RD3  - HEATER MAGNET DISABLE (PIC RELAY OUT)

  RA6  - Enable 15V Supply
  RA7  - LED Operational
  RG12 - LED A RED
  RG13 - LED B GREEN

  RF2  - Test Point D
  RF3  - Test Point E
  RF6  - Test Point A
  RF7  - Test Point B
  RF8  - Test Point C
  RB14 - Test Point F
*/
  
//   ------------------  Unconnected Pins ---------------
/*
  RA12
  RA13
  RA15

  RB10
  RB11
  RB12
  RB13
  RB15

  RC2
  RC3
  RC4
  RC13
  RC14

  RD4
  RD5
  RD6
  RD7

  RF4
  RF5
 
  RG0               
  RG1
  RG9
*/
// x -> not connected  n -> connected not used  o-> used outputs  i-> used inputs  h-> hw module  s-> sw module

#define A36926_001_TRISA_VALUE 0b1111111100111111
#define A36926_001_TRISB_VALUE 0b1011111111111111
#define A36926_001_TRISC_VALUE 0b0111111111111111
#define A36926_001_TRISD_VALUE 0b1111111111110111
#define A36926_001_TRISF_VALUE 0b1111111000110011
#define A36926_001_TRISG_VALUE 0b1100111111111111

//#define A36926_001_TRISA_VALUE 0bxnxx yhhy ooyy yyyy
//#define A36926_001_TRISB_VALUE 0bxoxx xxii iiii iihh
//#define A36926_001_TRISC_VALUE 0boxxy yyyy yyyx xxsy
//#define A36926_001_TRISD_VALUE 0biiii nnnn xxxx 0nnn
//#define A36926_001_TRISF_VALUE 0byyyy yyyo ooxx oohh
//#define A36926_001_TRISG_VALUE 0bsnoo yyxh hhyy hhxx
//
//#define A36926_TRISA_VALUE 0b1111111110111111
//#define A36926_TRISB_VALUE 0b1011111111111111
//#define A36926_TRISC_VALUE 0b1111111111111111
//#define A36926_TRISD_VALUE 0b1111111111110000
//#define A36926_TRISF_VALUE 0b1111111100110011
//#define A36926_TRISG_VALUE 0b1100111111111111


// -------- Digital Input Pins ----------//
#define PIN_PIC_FLOW_PWM_5                    PIC_DIG_IN_5  //What is this input for? -hkw
#define PIN_PIC_INPUT_TEMPERATURE_OK          PIC_DIG_IN_6
#define PIN_PIC_INPUT_HEATER_OV_OK            PIC_DIG_IN_7
#define PIN_PIC_INPUT_CROWBAR_UP              PIC_DIG_IN_8


#define PIN_RESET_DETECT                      RESET_DETECT

#define ILL_HEATER_OV                         1
#define ILL_TEMP_SWITCH_FAULT                 0
#define ILL_RELAY_OPEN                        1
#define ILL_ENERGY_SELECT_WATER_FLOW_OK       1



// ------- Digital Output Pins ---------//

#define PIN_HEATER_MAGNET_DISABLE             PIC_RELAY_OUT //now pin 63
#define PIN_SELECT_DAC_C_D                    PIC_OUTPUT_LAMBDA_SELECT // now pin 62
#define PIN_15V_ENABLE                        PIC_15V_SUPPLY_ENABLE

#define PIN_LED_OPERATIONAL_GREEN             LED_OPERATIONAL
#define PIN_LED_A_RED                         LED_A_RED
#define PIN_LED_B_GREEN                       LED_B_GREEN  // This is is configured by the CAN module to flash on CAN Bus activity
#define PIN_OUT_TP_A                          TEST_POINT_A
#define PIN_OUT_TP_B                          TEST_POINT_B
#define PIN_OUT_TP_C                          TEST_POINT_C
#define PIN_OUT_TP_D                          TEST_POINT_D
#define PIN_OUT_TP_E                          TEST_POINT_E
#define PIN_OUT_TP_F                          TEST_POINT_F

#define OLL_LED_ON                            0
#define OLL_CLOSE_RELAY                       0
#define OLL_SELECT_DAC_C                      1


//change below hkw
// ------------------------ CONFIGURE ADC MODULE ------------------- //

// ----------------- ANALOG INPUT PINS ---------------- //
/*
  BASE ANALOG CONFIGURATION
  PIC_ADC_AN1  is on AN2
  PIC_ADC_AN2  is on AN3
  PIC_ADC_AN3  is on AN4
  PIC_ADC_AN4  is on AN5

  PIC_ADC_+15V_MON is on AN6
  PIC_ADC_-15V_MON is on AN7
  PIC_ADC_5V_MON   is on AN8
  PIC_ADC_TEST_DAC is on AN9
*/

/*
  PIC_ADC_AN1  - PIC ADC MAGNET IMON
  PIC_ADC_AN2  - PIC ADC HEATER IMON
  PIC_ADC_AN3  - PIC ADC MAGNET VMON
  PIC_ADC_AN4  - PIC ADC HEATER VMON

*/

/*
  This sets up the ADC to work as following
  AUTO Sampling
  External Vref+/Vref-
  With 10MHz System Clock, ADC Clock is 450ns, Sample Time is 4 ADC Clock so total sample time is 8.1uS
  Conversion rate of 123.46KHz (15.432 Khz per Channel), 154 Samples per 10mS interrupt
  8 Samples per Interrupt, use alternating buffers
  Scan Through Selected Inputs

*/

//New Version

#define ADCON1_SETTING          (ADC_MODULE_OFF & ADC_IDLE_STOP & ADC_FORMAT_INTG & ADC_CLK_AUTO & ADC_AUTO_SAMPLING_ON)
#define ADCON2_SETTING          (ADC_VREF_EXT_EXT & ADC_SCAN_ON & ADC_SAMPLES_PER_INT_8 & ADC_ALT_BUF_ON & ADC_ALT_INPUT_OFF)
#define ADCHS_SETTING           (ADC_CH0_POS_SAMPLEA_AN2 & ADC_CH0_NEG_SAMPLEA_VREFN & ADC_CH0_POS_SAMPLEB_AN2 & ADC_CH0_NEG_SAMPLEB_VREFN)
#define ADPCFG_SETTING          (ENABLE_AN2_ANA & ENABLE_AN3_ANA & ENABLE_AN4_ANA & ENABLE_AN5_ANA & ENABLE_AN6_ANA & ENABLE_AN7_ANA & ENABLE_AN8_ANA & ENABLE_AN9_ANA)

#define ADCSSL_SETTING          (SKIP_SCAN_AN0 & SKIP_SCAN_AN1 & SKIP_SCAN_AN10 & SKIP_SCAN_AN11 & SKIP_SCAN_AN12 & SKIP_SCAN_AN13 & SKIP_SCAN_AN14 & SKIP_SCAN_AN15)
#define ADCON3_SETTING          (ADC_SAMPLE_TIME_4 & ADC_CONV_CLK_SYSTEM & ADC_CONV_CLK_9Tcy2)


/*
   TMR3 Configuration
   Timer3 - Used for 10msTicToc
   Period should be set to 10mS
   With 10Mhz Clock, x8 multiplier will yield max period of 17.7mS, 2.71uS per tick
*/

#define T3CON_VALUE                    (T3_ON & T3_IDLE_CON & T3_GATE_OFF & T3_PS_1_8 & T3_SOURCE_INT)
#define PR3_PERIOD_US                  10000   // 10mS
#define PR3_VALUE_10_MILLISECONDS      12500   //(FCY_CLK_MHZ*PR3_PERIOD_US/8)


typedef struct {
  // all currents are scaled to 1mA per lsb
  // all voltages are scaled to 1mV per lsb

  AnalogInput analog_input_heater_voltage;
  AnalogInput analog_input_heater_current;
  AnalogInput analog_input_electromagnet_voltage;
  AnalogInput analog_input_electromagnet_current;

  AnalogInput analog_input_5v_mon;                    // 1mV per LSB
  AnalogInput analog_input_15v_mon;                   // 1mV per LSB
  AnalogInput analog_input_neg_15v_mon;               // 1mV per LSB
  AnalogInput analog_input_pic_adc_test_dac;          // 62.5uV per LSB

  AnalogOutput analog_output_heater_current;
  AnalogOutput analog_output_electromagnet_current;

  unsigned int  accumulator_counter;

  unsigned int  adc_ignore_current_sample;

  unsigned int startup_count;
  unsigned int fault_active;
  unsigned int power_up_test_timer;

  unsigned int control_state;

} HeaterMagnetControlData;


extern HeaterMagnetControlData global_data_A36926_001;



#define _STATUS_MAGNET_OFF_READBACK                     _WARNING_0     //Should these be warnings? HKW
#define _STATUS_HEATER_OFF_READBACK                     _WARNING_1
#define _STATUS_OUTPUT_RELAY_OPEN                       _NOT_LOGGED_0
#define _STATUS_PERMA_FAULTED                           _NOT_LOGGED_1


#define _FAULT_HEATER_OVER_CURRENT_ABSOLUTE             _FAULT_0
#define _FAULT_HEATER_UNDER_CURRENT_ABSOLUTE            _FAULT_1
#define _FAULT_HEATER_OVER_CURRENT_RELATIVE             _FAULT_2
#define _FAULT_HEATER_UNDER_CURRENT_RELATIVE            _FAULT_3
#define _FAULT_HEATER_OVER_VOLTAGE_ABSOLUTE             _FAULT_4
#define _FAULT_HEATER_UNDER_VOLTAGE_RELATIVE            _FAULT_5


#define _FAULT_MAGNET_OVER_CURRENT_ABSOLUTE             _FAULT_6
#define _FAULT_MAGNET_UNDER_CURRENT_ABSOLUTE            _FAULT_7
#define _FAULT_MAGNET_OVER_CURRENT_RELATIVE             _FAULT_8
#define _FAULT_MAGNET_UNDER_CURRENT_RELATIVE            _FAULT_9
#define _FAULT_MAGNET_OVER_VOLTAGE_ABSOLUTE             _FAULT_A
#define _FAULT_MAGNET_UNDER_VOLTAGE_RELATIVE            _FAULT_B

#define _FAULT_HW_HEATER_OVER_VOLTAGE                   _FAULT_C
#define _FAULT_HW_TEMPERATURE_SWITCH                    _FAULT_D
#define _FAULT_COOLANT_FAULT                            _FAULT_E
#define _FAULT_CAN_COMMUNICATION_LATCHED                _FAULT_F



#endif	/* A36926_001_H */

