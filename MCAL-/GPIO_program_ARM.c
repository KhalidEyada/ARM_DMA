/*********************************************************************************************/
/*********************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "../../GENERAL/STD_TYPES.h"
		 #include "../../GENERAL/BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "GPIO_private.h"
		#include "GPIO_interface.h"
		#include "GPIO_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function Set Enable port clock	

									GPIO PORT	

*/

void DIO_voidEnablePortClock(u32 copy_u32PORT) 
 {
	        switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;
					  case GPIOB_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;
					  case GPIOC_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;
					  case GPIOD_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;
					  case GPIOE_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;
					  /*case GPIOF_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;
					  case GPIOG_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;*/
					  case GPIOH_PORT: RCC_AHB1ENR |=(u32)  (HIGH << (copy_u32PORT)); break;		
					  default: break;		
		     }
	 
 }

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function Set The Mode Of Pin Mode Take 2Bits	

									MODE_INPUT
									MODE_OUTPUT
									MODE_ALTF
									MODE_ANALOG	

*/
 void DIO_voidSetPinMode(u32 copy_u32PORT ,u32 copy_u32PIN,u32 copy_u32MODE) 
 {
	 RCC_AHB1ENR |= (1u << 0);
	        switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: GPIOA_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN*2)); break;
					  case GPIOB_PORT: GPIOB_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN*2)); break;
					  case GPIOC_PORT: GPIOC_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN*2)); break;
					  case GPIOD_PORT: GPIOD_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN*2)); break;
					  case GPIOE_PORT: GPIOE_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN*2)); break;
					  /*case GPIOF_PORT: GPIOF_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN)); break;
					  case GPIOG_PORT: GPIOG_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN)); break;*/
					  case GPIOH_PORT: GPIOH_MODER |=(u32)  (copy_u32MODE << (copy_u32PIN*2)); break;		
					  default: break;		
		     }
	 
 }
				

/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
/*				Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)

								OUTPUT_TYPE_PUSH_PULL
								OUTPUT_TYPE_OPEN_DRAIN	

						*/
void DIO_voidSetOutType(u32 copy_u32PORT ,u32 copy_u32PIN,u32 copy_u32Type) 
{
		      switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: GPIOA_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;
					  case GPIOB_PORT: GPIOB_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;
					  case GPIOC_PORT: GPIOC_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;
					  case GPIOD_PORT: GPIOD_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;
					  case GPIOE_PORT: GPIOE_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;
					  /*case GPIOF_PORT: GPIOF_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;
					  case GPIOG_PORT: GPIOG_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;*/
					  case GPIOH_PORT: GPIOH_OTYPER |=(u32)  (copy_u32Type << (copy_u32PIN)); break;		
					  default: break;		
		     }
}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*						Function Set The Speed (LOW , Meduim , High ,VeryHaigh		
							
							OUTPUT_LOW_SPEED
							OUTPUT_MEDUIM_SPEED
							OUTPUT_HIGH_SPEED
							OUTPUT_VERY_HIGH_SPEED
							
							

						*/
	void DIO_voidSetOutSpeed(u32 copy_u32PORT ,u32 copy_u32PIN,u32 copy_u32Speed)  
{
		      
				switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: GPIOA_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;
					  case GPIOB_PORT: GPIOB_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;
					  case GPIOC_PORT: GPIOC_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;
					  case GPIOD_PORT: GPIOD_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;
					  case GPIOE_PORT: GPIOE_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;
					  /*case GPIOF_PORT: GPIOF_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;
					  case GPIOG_PORT: GPIOG_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;*/
					  case GPIOH_PORT: GPIOH_OSPEEDR |=(u32)  (copy_u32Speed << (copy_u32PIN)); break;		
					  default: break;		
		     }
}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
	/*		Function Set The PULL :
								
					PULL_OFF
					PULL_UP
					PULL_DOWN
	
	
		*/
	void DIO_voidSetPull(u32 copy_u32PORT ,u32 copy_u32PIN,u32 copy_u32PULL_TYPE)  
{
		   switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: GPIOA_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;
					  case GPIOB_PORT: GPIOB_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;
					  case GPIOC_PORT: GPIOC_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;
					  case GPIOD_PORT: GPIOD_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;
					  case GPIOE_PORT: GPIOE_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;
					  /*case GPIOF_PORT: GPIOF_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;
					  case GPIOG_PORT: GPIOG_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;*/
					  case GPIOH_PORT: GPIOH_PUPDR |=(u32)  (copy_u32PULL_TYPE << (copy_u32PIN)); break;		
					  default: break;		
		     }  
}


/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
		/*		Function To Read Data From IDR		*/
		u32 DIO_u32ReadData(u32 copy_u32PORT ,u32 copy_u32PIN)
{
		u32 u32Local_Data = 0 ;
		if(copy_u32PIN <= MAX_PINS){
				
		  switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: u32Local_Data = (u32) ((GPIOA_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;
					  case GPIOB_PORT: u32Local_Data = (u32) ((GPIOB_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;
					  case GPIOC_PORT: u32Local_Data = (u32) ((GPIOC_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;
					  case GPIOD_PORT: u32Local_Data = (u32) ((GPIOD_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;
					  case GPIOE_PORT: u32Local_Data = (u32) ((GPIOE_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;
					  /*case GPIOA_PORT: u32Local_Data = (u32) ((GPIOA_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;
					  case GPIOA_PORT: u32Local_Data = (u32) ((GPIOA_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;*/
					  case GPIOH_PORT: u32Local_Data = (u32) ((GPIOH_IDR >>copy_u32PIN)& INPUT_DATA_MASK); break;
					  default: break;		
		     } 
		}			
		return u32Local_Data ; 
}


/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
	/*		
			* Function To Write Data At ODR	Value :
									 high 
									 low	
	*/
	void DIO_voidWriteDataOdr(u32 copy_u32PORT ,u32 copy_u32PIN , u32 copy_u32Value )
 {
	
	 if(copy_u32PIN <= MAX_PINS){
				
		  switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: GPIOA_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  case GPIOB_PORT: GPIOB_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  case GPIOC_PORT: GPIOC_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  case GPIOD_PORT: GPIOD_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  case GPIOE_PORT: GPIOE_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  /*case GPIOF_PORT: GPIOF_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  case GPIOG_PORT: GPIOG_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;*/
					  case GPIOH_PORT: GPIOH_ODR |=(u32)  (copy_u32Value << (copy_u32PIN)); break;		
					  default: break;		
		     } 
		}
	
}


/*********************************************************** END_ FUNCTION   ***********************************************************/
	

/*		Function Set The AltFn		: Every Pin Need 4 Bits SO We Have High AND Low			*/
void DIO_voidPinSetAltFn(u32 copy_u32PORT ,u32 copy_u32PIN,u32 copy_u32AlT)

{
	/* From 0 To  7 */
if(copy_u32PIN <= AIT_LOW){	
	switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: GPIOA_AFRL |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOB_PORT: GPIOB_AFRL |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOC_PORT: GPIOC_AFRL |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOD_PORT: GPIOD_AFRL |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOE_PORT: GPIOE_AFRL |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  /*case GPIOF_PORT: GPIOF_AFRL |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  case GPIOG_PORT: GPIOG_AFRL |=(u32)  (copy_u32Value << (copy_u32PIN)); break;*/
					  case GPIOH_PORT: GPIOH_AFRL |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;		
					  default: break;		
		     } 
		}

	/* From 8 To  15 */

else if(copy_u32PIN <= AIT_HIGH){
	   switch (copy_u32PORT)
	        {
	  	      case GPIOA_PORT: GPIOA_AFRH |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOB_PORT: GPIOB_AFRH |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOC_PORT: GPIOC_AFRH |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOD_PORT: GPIOD_AFRH |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  case GPIOE_PORT: GPIOE_AFRH |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;
					  /*case GPIOF_PORT: GPIOF_AFRH |=(u32)  (copy_u32Value << (copy_u32PIN)); break;
					  case GPIOG_PORT: GPIOG_AFRH |=(u32)  (copy_u32Value << (copy_u32PIN)); break;*/
					  case GPIOH_PORT: GPIOH_AFRH |=(u32)  (copy_u32AlT << (copy_u32PIN)); break;		
					  default: break;		
		     } 
		}
}



