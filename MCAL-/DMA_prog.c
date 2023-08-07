/******************************************************************************************/
/******************************************************************************************/

#include "../GENERAL/STD_TYPES.h"
#include "../GENERAL/BIT_MATH.h"
#include "../MCAL-/DMA_private.h"
#include "../MCAL-/DMA_config.h"
#include "../MCAL-/DMA_interface.h"





void ( *DMA_CallBackChannel1 )( void );

void DMA_vInit(u8 Copy_u8SreamID, u8 Mode, u8 DMA_TYPE)
{
     /* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
	/* Use Stream NUM = 0 */
	/* If Enable Bit == 1 */
switch(DMA_TYPE){
	case TYPE_DMA2:

						/*disabling DMA*/
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN0);
							/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
						/*sellecting channel 4*/
						SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN27);
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN26);
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN25);
						/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
						SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN17);
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN16);
						
						/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7) */
						switch(Mode){
							case MEM2MEM :
													SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN7);
													CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN6);
													SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN18); /*double buff mode*/
													SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN19); /**/
													break;
							case MEM2PREPH :
													CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN7);
													SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN6);
													break;
							case PREPH2MEM :
													CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN7);
													CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN6);
													break;	
						}
						
						/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
						/* 	As Byte 8 For Source	*/ 
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN14);
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN13);
						/* 	As Byte 8 For Distination	*/ 
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN12);
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN11);
						
						/* 6- Enable Direct Mode  */
						SET_BIT(DMA_2->StreamID[Copy_u8SreamID].FCR,PIN2);
						
						
						/* 8-SRC & DIS Increament For Both */
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN10);
						CLR_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN9);  
						
						/* 9- EN Interrput Of Transfer Complete */
						SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN4);  
						
						break;
		case TYPE_DMA1:
			/*disabling DMA*/
						CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN0);
							/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
						/*sellecting channel 4*/
						SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN27);
						CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN26);
						CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN25);
						/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
						SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN17);
						CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN16);
						
						/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7) */
						switch(Mode){
							case MEM2MEM :
													SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN7);
													CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN6);
													SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN18); /*double buff mode*/
													SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN19); /**/
													break;
							case MEM2PREPH :
													CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN7);
													SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN6);
													break;
							case PREPH2MEM :
													CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN7);
													CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN6);
													break;	
						}
						
						/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
						/* 	As Word 32 For Source	*/ 
						SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN14);
						CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN13);
						/* 	AAs Word 32 For Distination	*/ 
						SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN12);
						CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN11);
						
						/* 6- enable Direct Mode */
						CLR_BIT(DMA_1->StreamID[Copy_u8SreamID].FCR,PIN2);
						

						
						/* 9- EN Interrput Of Transfer Complete */
						SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN4);  
						
						break;				
					}
}



void DMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID, u8 Mode , u8 DMA_TYPE)
{
		switch(DMA_TYPE){
			case TYPE_DMA2: 
					switch(Mode){
							case MEM2MEM :
														DMA_2->StreamID[Copy_u8SreamID].NDTR = (u16) Copy_u32Size;
														DMA_2->StreamID[Copy_u8SreamID].M0AR = (u32) Ptr_u32SrcAdd;
														DMA_2->StreamID[Copy_u8SreamID].M1AR = (u32) Ptr_u32DistAdd;
													break;
							case MEM2PREPH :
														DMA_2->StreamID[Copy_u8SreamID].NDTR = (u16) Copy_u32Size;
														DMA_2->StreamID[Copy_u8SreamID].M0AR = (u32) Ptr_u32SrcAdd;
														DMA_2->StreamID[Copy_u8SreamID].PAR = (u32) Ptr_u32DistAdd;
													break;
							case PREPH2MEM :
														DMA_2->StreamID[Copy_u8SreamID].NDTR = (u16) Copy_u32Size;
														DMA_2->StreamID[Copy_u8SreamID].PAR = (u32) Ptr_u32SrcAdd;
														DMA_2->StreamID[Copy_u8SreamID].M0AR = (u32) Ptr_u32DistAdd;
													break;	
						}break;
			case TYPE_DMA1: 
					switch(Mode){
							case MEM2MEM :
														DMA_1->StreamID[Copy_u8SreamID].NDTR = (u16) Copy_u32Size;
														DMA_1->StreamID[Copy_u8SreamID].M0AR = (u32) Ptr_u32SrcAdd;
														DMA_1->StreamID[Copy_u8SreamID].M1AR = (u32) Ptr_u32DistAdd;
													break;
							case MEM2PREPH :
														DMA_1->StreamID[Copy_u8SreamID].NDTR = (u16) Copy_u32Size;
														DMA_1->StreamID[Copy_u8SreamID].M0AR = (u32) Ptr_u32SrcAdd;
														DMA_1->StreamID[Copy_u8SreamID].PAR = (u32) Ptr_u32DistAdd;
													break;
							case PREPH2MEM :
														DMA_1->StreamID[Copy_u8SreamID].NDTR = (u16) Copy_u32Size;
														DMA_1->StreamID[Copy_u8SreamID].PAR = (u32) Ptr_u32SrcAdd;
														DMA_1->StreamID[Copy_u8SreamID].M0AR = (u32) Ptr_u32DistAdd;
													break;	
						}break;		
					} 
}

void DMA_vStreamEnable(u8 Copy_u8SreamID , u8 DMA_TYPE)
{
	/* All Flag == 0 or make them =0 */
	switch(DMA_TYPE){
					case TYPE_DMA2: 	
						
						DMA_2->LISR=0xFFFFFFFF;
						DMA_2->HISR=0xFFFFFFFF;
						DMA_2->LIFCR=0xFFFFFFFF;
						DMA_2->HIFCR=0xFFFFFFFF;
					SET_BIT(DMA_2->StreamID[Copy_u8SreamID].CR,PIN0);
						break;
					
					case TYPE_DMA1: 	
					
						DMA_1->LISR=0xFFFF;
						DMA_1->HISR=0xFFFF;
						DMA_1->LIFCR=0xFFFF;
						DMA_1->HIFCR=0xFFFF;
						SET_BIT(DMA_1->StreamID[Copy_u8SreamID].CR,PIN0); 
						break;	
	}
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

