
/*************************************************************************************
*************************************************************************************/ 


#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


/***********************************************************************************
----->STRUCT
*  Register Map :SYSCFG
************************************************************************************/
#include "../GENERAL/STD_TYPES.h"

#define AHB_BASE	  			(0x40020000)

#define DMA1_BASE					(0x40026000)
#define DMA2_BASE					(0x40026400)



typedef struct 
{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
	
}DMA_STREAM_t;


typedef struct 
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	volatile DMA_STREAM_t StreamID[8];
	
}DMA_t;

/***********************************************************************************
	-----> Macros
			*  Base_Address DMA_2       --> 0x4002 6400 	
			*  Base_Address DMA_2       --> 0x4002 6000
************************************************************************************/

#define DMA_1            ((( volatile  DMA_t *) DMA1_BASE))
#define DMA_2            ((( volatile  DMA_t *)	DMA2_BASE))


#endif 
/***********************************************************************************/