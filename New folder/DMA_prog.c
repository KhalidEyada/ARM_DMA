/******************************************************************************************/
/******************************************************************************************/
void ( *DMA_CallBackChannel1 )( void );

void DMA_vInit(u8 Copy_u8SreamID )
{
     /* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
	/* Use Stream NUM = 0 */
	/* If Enable Bit == 1 */
	
  	/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
	
	/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
	
	
	/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7) */
	
	
	/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
	/* 	As Word 32 For Source	*/ 
	
	/* 	As Word 32 For Distination	*/ 
	
	
	/* 6- Disable Direct Mode to used fifo  */
	
	
	/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
	/* Use (1/2)*/
	
	/* 8-SRC & DIS Increament For Both */
    
	/* 9- EN Interrput Of Transfer Complete */
	

}






void DMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID )
{
	


}

void DMA_vStreamEnable(u8 Copy_u8SreamID )
{
	/* All Flag == 0 or make them =0 */
	
}


void DMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel1();

}
/******************************************************************************************/

/********************************
DMA STEPS
*********************************
	/*Enable clock access to DMA*/

	/*Disable DMA1 Stream6*/ //CR

    /*Wait until DMA1 Stream 6 is disabled */ //CR

	/*Clear all interrupt flags of Stream6*/ //HIFCR

	/*Set the destination buffer*/  //PAR

	/*Set the source buffer*/  //M0AR

	/*Set length*/  //NDTR

	/*Select Stream6 CH4*/ //CR

	/*Enable memory increment*/  //CR

	/*Configure transfer direction*/  //CR

	/*Enable DMA transfer complete interrupt*/  //CR

	/*Enable direct mode and disable FIFO*/  //FCR

	/*Enable DMA1 Stream6*/  //CR

	/*Enable UART2 transmitter DMA*/  // UART DMA

	/*DMA Interrupt enable in NVIC*/// NVIC_EnableIRQ(DMA1_Stream6_IRQn);

/*******************************/

