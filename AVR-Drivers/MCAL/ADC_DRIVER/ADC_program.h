/*
 * ADC_program.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */

#ifndef ADC_PROGRAM_H_
#define ADC_PROGRAM_H_
// kol ma b3d el * bywasaf l pointer
#define ADC_u8_ADMUXREG   *( (u8 volatile*const)0x27 )
#define ADC_u8_ADCSRA_REG *( (u8 volatile*const)0x26 )
#define ADC_u8_SFIOR_REG  *( (u8 volatile*const)0x50 )
#define MCU_u8_SREG  	  *( (u8 volatile*const)0x5f )

#define ADC_u8_START_CONV_MUSK  (u8)0x40
#define ADC_u8_INT_FLAG_MUSK  (u8)0x10

#define ADC_u8_ADCH_REG (u8)0x24
#define ADC_u8_ADCl_REG (u8)0x25

// FOR ADCMUX
#define ADC_u8ref     ADC_u8_vcc
#define ADC_u8ADJUST   ADC_u8_LEFT
#define ADC_u8_ChannelConfig	ADC_u8_channel0

//FOR ADCREF
#define ADC_u8_vcc       (u8)0x40
#define ADC_u8_Vinternal (u8)0x
#define ADC_u8_Vexternal (u8)0x00

//FOR ADJUST
#define ADC_u8_LEFT  (u8)0x20
#define ADC_u8_RIGHT  (u8)0x00

//Available channels
#define ADC_u8_channel0    (u8)0x00
#define ADC_u8_channel1    (u8)0x01
#define ADC_u8_channel2    (u8)0x02
#define ADC_u8_channel3    (u8)0x03
#define ADC_u8_channel4    (u8)0x04
#define ADC_u8_channel5    (u8)0x05
#define ADC_u8_channel6    (u8)0x06
#define ADC_u8_channel7    (u8)0x07


#define ADC_u8_PERI_STATE 	ADC_u8_PREF_ENABLE
#define ADC_u8_AutoTRIG		ADC_u8_SINGLE_CONV
#define ADC_u8_INT_STATE		ADC_u8_INT_DISABLE
#define ADC_u8_PRESCALER	ADC_u8_PRES128

//for perfiral state
#define ADC_u8_PREF_ENABLE	    (u8)0x80
#define ADC_u8_PREF_DISABLE     (u8)0x00

//type of triggering
#define ADC_u8_SINGLE_CONV 		0x00
#define ADC_u8_TRIGGERED      		0x20

#define ADC_u8_INT_ENABLE	    (u8)0x10
#define ADC_u8_INT_DISABLE		(u8)0x00

 #define ADC_u8_PRES2	 (u8)0x00
 #define ADC_u8_PRES4    (u8)0x02
 #define ADC_u8_PRES8    (u8)0x03
 #define ADC_u8_PRES16   (u8)0x04
 #define ADC_u8_PRES32   (u8)0x05
 #define ADC_u8_PRES64   (u8)0x06
 #define ADC_u8_PRES128  (u8)0x06

// setting trigger source
#define ADC_u8_TRIGGER_SRC	 ADC_u8_FREERUN_TRIG

//Y5LS L CONVERSION YBD2 L CONVERSION L B3DO
 #define ADC_u8_FREERUN_TRIG        				(u8)0x00
// DIFF +VE TRIGGER -VE TRIGGER
 #define ADC_u8_COMP_TRIG                        	(u8)0x20
//EXTERNAL INTRUPT
 #define ADC_u8_EXTI_TRIG                               (u8)0x40
 #define ADC_u8_T0CM_TRIG                               (u8)0x60
 #define ADC_u8_T0OVF                                   (u8)0x80
 #define ADC_u8_T1CMB_TRIG                              (u8)0xa0
 #define ADC_u8_T1OVF_TRIG                              (u8)0xc0
 #define ADC_u8_T1IC_TRIG                               (u8)0xe0

//interrupt
#define ADC_u8_GIE		MCU_GI_DISABLE

#define MCU_GI_ENABLE 		0x80
#define MCU_GI_DISABLE 	0x00



void ADC_VoidInitialize(void);
void ADC_u8StartConversion(u8 ADC_Channel);
u8 ADC_u8ReadDigital(void);


#endif /* ADC_PROGRAM_H_ */
