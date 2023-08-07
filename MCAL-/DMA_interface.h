
/*************************************************************************************
*************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#include "../GENERAL/STD_TYPES.h"
#include "../GENERAL/BIT_MATH.h"

#define MEM2MEM 			0u
#define MEM2PREPH 		1u
#define PREPH2MEM 		2u

#define TYPE_DMA1 		0u
#define TYPE_DMA2 		1u

#define CHANNEL 			7u


/* DMA init */
void DMA_vInit(u8 Copy_u8SreamID, u8 Mode, u8 DMA_TYPE);
/* Function to set source and distination */
void DMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID , u8 Mode, u8 DMA_TYPE);
/* Func To enable DMA */
void DMA_vEnable(u8 Copy_u8DMAID);

void DMA_vStreamEnable(u8 Copy_u8SreamID , u8 DMA_TYPE);
void DMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) );
void DMA1_Channel1_IRQHandler(void);

#endif 
/*************************************************************************************/
