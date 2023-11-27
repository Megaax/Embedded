/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO_PROGRAM.c
 *        \brief  Digital Input Output Controller Driver
 *
 *      \details  The Driver Configure All MCU Ports
 *
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "ADC_PRIVATE.h"




/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATION
 *********************************************************************************************************************/



#define  ADC_CHANNELS_NUM	 3


ADC_CONFIG_t static ADC_CONFIG[ADC_CHANNELS_NUM]= {

					{.channel=0,
					 .group_id=0,
					 .group_pri=0,
					 .group_mode=SINGLE_MODE,
					 .Streaming_num_samples=100
					}
					,
					{.channel=1,
					 .group_id=0,
					 .group_pri=0,
					 .group_mode=SINGLE_MODE,
					 .Streaming_num_samples=100
					},
					{.channel=2,
					 .group_id=0,
					 .group_pri=0,
					 .group_mode=SINGLE_MODE,
					 .Streaming_num_samples=100
					}
						};












/**********************************************************************************************************************
 *  END OF FILE: DIO_PROGRAM.c
 *********************************************************************************************************************/
