/*
 * Buttons.c
 *
 *  Created on: Apr 19, 2016
 *      Author: Adrian
 */

#include "derivative.h"
#include "Buttons.h"
#include "Player_Fsm.h"


#define GPIO_PIN_MASK            0x1Fu
#define GPIO_PIN(x)              (((1)<<(x & GPIO_PIN_MASK)))
/*IRQ_NONE	
0x0. no documentation

IRQ_DMA_RISING	
0x1. no documentation

IRQ_DMA_FALLING	
0x2. no documentation

IRQ_DMA_EITHER	
0x3. no documentation

IRQ_ZERO	
0x8. no documentation

IRQ_RISING	
0x9. no documentation

IRQ_FALLING	
0xa. no documentation

IRQ_EITHER	
0xb. no documentation

IRQ_ONE	
0xc. no documentation

 * 
 * 
 * 
 * */
void InitButtons(void){
	/* Configure pin as input */
	/* GPIOB_PDDR: PDD&=~0x0100 */ //Port 8
	/* GPIOB_PDDR: PDD&=~0x0200 */ //Port 9
	  GPIOB_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(
			  GPIO_PIN(9)| 
			  GPIO_PIN(8)| 
			  GPIO_PIN(10) | 
			  GPIO_PIN(11)));
	  
	  /* Initialization of Port Control register */
	  /* PORTB_PCR8: ISF=0,MUX=1 */
	  PORTB_PCR8 = (uint32_t)((PORTB_PCR8 & (uint32_t)~(uint32_t)(
			  PORT_PCR_ISF_MASK |
			  PORT_PCR_MUX(0x06)
	  )) | (uint32_t)(
			  PORT_PCR_MUX(0x01)
	  ));
	  PORTB_PCR9 = (uint32_t)((PORTB_PCR9 & (uint32_t)~(uint32_t)(
			  PORT_PCR_ISF_MASK |
			  PORT_PCR_MUX(0x06)
	  )) | (uint32_t)(
			  PORT_PCR_MUX(0x01)
	  ));
	  PORTB_PCR10 = (uint32_t)((PORTB_PCR10 & (uint32_t)~(uint32_t)(
			  PORT_PCR_ISF_MASK |
			  PORT_PCR_MUX(0x06)
	  )) | (uint32_t)(
			  PORT_PCR_MUX(0x01)
	  ));
	  PORTB_PCR11 = (uint32_t)((PORTB_PCR11 & (uint32_t)~(uint32_t)(
			  PORT_PCR_ISF_MASK |
			  PORT_PCR_MUX(0x06)
	  )) | (uint32_t)(
			  PORT_PCR_MUX(0x01)
	  )) | PORT_PCR_IRQC(0xA);
}
/*
 * Play Button: PORT B PIN 8
 * */
T_BOOL PlayButtonState(void){
	return (T_BOOL)((GPIOB_PDIR & GPIO_PDIR_PDI(GPIO_PIN(8)))==0);
}

/*
 * Play Button: PORT B PIN 9
 * */
T_BOOL StopButtonState(void){
	return (T_BOOL)((GPIOB_PDIR & GPIO_PDIR_PDI(GPIO_PIN(9)))==0);
}

/*
 * Play Button: PORT B PIN 10
 * */
T_BOOL VolUpButtonState(void){
	return (T_BOOL)((GPIOB_PDIR & GPIO_PDIR_PDI(GPIO_PIN(10)))==0);
}

/*
 * Play Button: PORT B PIN 11
 * */
T_BOOL VolDownButtonState(void){
	return (T_BOOL)((GPIOB_PDIR & GPIO_PDIR_PDI(GPIO_PIN(11)))==0);
}

