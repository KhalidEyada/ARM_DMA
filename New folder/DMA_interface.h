
/*************************************************************************************
*************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


/* DMA init */
void DMA_vInit(void);
/* Function to set source and distination */
void DMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size );
/* Func To enable DMA */
void DMA_vEnable(u8 Copy_u8DMAID);



#endif 
/*************************************************************************************/