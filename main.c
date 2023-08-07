#include "../MCAL-/DMA_interface.h"
#include "../MCAL-/RCC_interface.h"
#include "../MCAL-/GPIO_interface.h"

#define ADDR 	((u32*)(0x40011000+0x04)) /*USART Address*/

int main(void){
	u32 LED_ON = 0x04;
	
	RCC_voidInitSysClock(HSI_CLK,0,0,AHB_Pre1,ABP1_Pre1,ABP1_Pre2);
	RCC_voidEnableClock(AHB1_BUS,DAM2_ON);
	RCC_voidEnableClock(APB2,USART1);
	
	/*DIO_voidSetPinMode(GPIOA_PORT,PIN5,MODE_OUTPUT);*/
	
	DMA_vInit(CHANNEL,MEM2PREPH,TYPE_DMA2);
	DMA_vSetAddress(&LED_ON, ADDR, 1,CHANNEL,MEM2PREPH, TYPE_DMA2);
	DMA_vStreamEnable(CHANNEL,TYPE_DMA2);
	DMA_vSetAddress(&LED_ON, ADDR, 1,CHANNEL,MEM2PREPH, TYPE_DMA2);
	while(1);
}
