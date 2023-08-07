/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "../GENERAL/STD_TYPES.h"
		 #include "../GENERAL/BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "RCC_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/





/************************************ Start_FUNCTION  ************************************/
/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
				- If not used send 0
 */
 void RCC_voidInitSysClock( ClkSrcName_t ClkSrc , HSESrcName_t HSESrc , PllSrcName_t PLLSrc  , AHBPreName_t AHB_Prescaler , APB1PreName_t APB1_Prescaler  , APB2PreName_t APB2_Prescaler ) 
 {
		switch(ClkSrc)
		{
			/*HSE*/
			case HSE_CLK 	: 
				switch (HSESrc)
				{	/* HSE CRYSTAL */
					case  HSE_Crystal : SET_BIT(RCC_CR,HSE_ON); 
															CLR_BIT(RCC_CR,HSE_BYP); 
					break; 
					/* HSE RC*/
					case  HSE_RC :SET_BIT(RCC_CR,HSE_ON); 
												SET_BIT(RCC_CR,HSE_BYP);
					break;
					
					/*default		:  break;*/
						
						
					}
			
		  break ;
			 /*******************************************************************************/ 
			 /* HSI  */
			case HSI_CLK	: SET_BIT(RCC_CR,HSION);
				
			 break; 
			/*********************************************************************************/
			/* PLL */
			case PLL_CLK 	:
				 switch(PLLSrc)
				 {
					 /* PLL HSE */
					 case PLL_HSE : SET_BIT(RCC_CR,HSE_ON); 
													SET_BIT(RCC_CR,PLL_ON);
													SET_BIT(RCC_PLLCFGR,PLL_SRC);
					 break ;
					 /* PLL HSI*/
					 case PLL_HSI : SET_BIT(RCC_CR,HSION);
													SET_BIT(RCC_CR,PLL_ON);
												  CLR_BIT(RCC_PLLCFGR,PLL_SRC);
					 break ;
					 
					 	/*default		:  break;*/
					 
				 }
			
			break; 
		/*default		:  break;*/
			
			 }
			/****************************************************************************************/
				/*
	 ABP1_Pre1
	 ABP1_Pre2
	 ABP1_Pre4
	 ABP1_Pre8
	 ABP1_Pre16
	
	*/
	switch (APB1_Prescaler)
	{
		case ABP1_Pre1: (RCC_PLLCFGR|=(APB_PRESCALER_0<<APB1_LOC));
			
		break; 
		case ABP1_Pre2: (RCC_PLLCFGR|=(APB_PRESCALER_2<<APB1_LOC));
			
		break;
		case ABP1_Pre4: (RCC_PLLCFGR|=(APB_PRESCALER_4<<APB1_LOC));
			
		break;
		case ABP1_Pre8: (RCC_PLLCFGR|=(APB_PRESCALER_8<<APB1_LOC));
			
		break;
		case ABP1_Pre16: (RCC_PLLCFGR|=(APB_PRESCALER_16<<APB1_LOC));
			
		break;
			/*default		:  break;*/
		
		
	}
/**************************************************************************************************/	
		/*
		* APB2_Prescaller 
		ABP2_Pre1
		ABP2_Pre2
		ABP2_Pre4
		ABP2_Pre8
		ABP2_Pre16
		13 , 14 ,15
		*/
		switch (APB2_Prescaler)
		{
			case  ABP2_Pre1 : (RCC_PLLCFGR|=(APB_PRESCALER_0<<APB2_LOC));
				
			break;
			case  ABP2_Pre2 :	(RCC_PLLCFGR|=(APB_PRESCALER_2<<APB2_LOC));
				
			break;
			case  ABP2_Pre4 :	(RCC_PLLCFGR|=(APB_PRESCALER_4<<APB2_LOC));
				
			break;
			case  ABP2_Pre8 :	(RCC_PLLCFGR|=(APB_PRESCALER_8<<APB2_LOC));
				
			break;
			case  ABP2_Pre16 :	(RCC_PLLCFGR|=(APB_PRESCALER_16<<APB2_LOC));
				
			break;
			
			/*default		:  break;*/
			
		}
	
			
			/*
					AHB_Pre1
					AHB_Pre2
					AHB_Pre4
					AHB_Pre8
					AHB_Pre16
					AHB_Pre32
					AHB_Pre64
					AHB_Pre128
					AHB_Pre256
					AHB_Pre512
			
			*/
			switch (AHB_Prescaler)
			{
				case AHB_Pre1 : (RCC_PLLCFGR|=(AHB_PRESCALER_0<<AHB_LOC));
						
				break ;                 
				/***********/           
				case AHB_Pre2 :  (RCC_PLLCFGR|=(AHB_PRESCALER_2<<AHB_LOC));       
						
				break ;                 
				/***********/           
				case AHB_Pre4 :   (RCC_PLLCFGR|=(AHB_PRESCALER_4<<AHB_LOC));      
						
				break ;                 
				/***********/           
				case AHB_Pre8 :  (RCC_PLLCFGR|=(AHB_PRESCALER_8<<AHB_LOC));     
					
						
				break ;                 
				/***********/     
				/* case AHB_Pre32 : */
				/***********/   
				case AHB_Pre16 :  (RCC_PLLCFGR|=(AHB_PRESCALER_16<<AHB_LOC));      
						
				break ;                 
				/***********/           
				case AHB_Pre64 :   (RCC_PLLCFGR|=(AHB_PRESCALER_64<<AHB_LOC));     
						
				break ;                 
				/***********/           
				case AHB_Pre128 :  (RCC_PLLCFGR|=(AHB_PRESCALER_128<<AHB_LOC));     
						
				break ;                 
				/***********/ 
				case AHB_Pre256 :  (RCC_PLLCFGR|=(AHB_PRESCALER_256<<AHB_LOC));     
						
				break ;                 
				/***********/ 
				case AHB_Pre512 :  (RCC_PLLCFGR|=(AHB_PRESCALER_512<<AHB_LOC));     
						
				break ;
				/***********/
					/*default		:  break;*/ 
				
			}
		 
 }



/*********************************************************** END_ FUNCTION   ***********************************************************/



\
/************************************ Start_FUNCTION  ************************************/

 void RCC_voidEnableClock (BusName_t BusName ,u8 Copy_u8PerName  )
 {
	 switch(BusName) 
	 {
		 case AHB1_BUS :
			SET_BIT(RCC_AHB1ENR , Copy_u8PerName  ) ;
		 break ; 
		 
		 case AHB2_BUS  :
			SET_BIT(RCC_AHB2ENR , Copy_u8PerName  ) ;
		 break ;
		 
		/* case AHB3_BUS  :
			 SET_BIT(RCC_AHB3ENR , Copy_u8PerName  ) ;
		 break ;*/
		 
		 case APB1_BUS  :
			SET_BIT(RCC_APB1LPENR , Copy_u8PerName  ) ;	
		 break ;
		 
		 case APB2_BUS  :
			SET_BIT(RCC_APB2LPENR , Copy_u8PerName  ) ;	
		 break ;
		 
			/*default		:  break;*/
		 
		 
	 }
 }

 
