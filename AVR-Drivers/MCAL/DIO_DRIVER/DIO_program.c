/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HOME
 */
#include "STD_TYPES_H.h"
#include "DIO_interface.h"


void DIO_VoidInitializaion(void)
{
	u8 i= ZERO;
	u8 volatile* REG=DDRD;
	for(i=0;i<=PORT_A;i++)
	{
		REG=DDRD+(DIO_REG_OFSET*i);
				*REG=ZERO;
	}
			REG=PORTD;
	for(i=0;i<=PORT_A;i++)
		{
			REG=PORTD+(DIO_REG_OFSET*i);
					*REG=ZERO;
		}
	REG=PIND;
	for(i=0;i<=PORT_A;i++)
		{
			REG=PIND+(DIO_REG_OFSET*i);
					*REG=ZERO;
		}

}
STD_ERROR DIO_SetPinDir(u8 PORT_,u8 P_,u8 DIO_DIR)
{
	STD_ERROR LOC_ERROR=OK;

	if(P_>=0 && P_<=7)
	{
		if(PORT_>PORT_D && PORT_<PORT_A)
		{
			u8 volatile* REG =DDRD;
			if (DIO_DIR == DIO__DIR_INPUT)
			{
				REG=DDRD+(DIO_REG_OFSET*PORT_);

				*REG &=~(1<<P_);
			}
			else if (DIO_DIR == DIO__DIR_OUTPUT)
			{
				REG=DDRD+(DIO_REG_OFSET*PORT_);

				*REG |=(1<<P_);
			}
			else
			{
				LOC_ERROR=NOT_OK;
			}
		 }
		return(LOC_ERROR);
	}

	}
	STD_ERROR DIO_SetPinValue(u8 PORT_, u8 P_, u8 DIO_VALUE_)
	{
		STD_ERROR LOC_ERROR=OK;
		if(P_>=0 && P_<=7)
			{
				if(PORT_>PORT_D && PORT_<PORT_A)
				{
					u8 volatile * REG =PORTD;

					REG=PORTD+(DIO_REG_OFSET*PORT_);

					if(DIO_VALUE_ ==DIO_VALUE_HIGH)
					{
						*REG |=(1<<P_);
					}
					else if(DIO_VALUE_ ==DIO_VALUE_LOW)
										{
											*REG  &=~(1<<P_);
										}
					else
									{
										LOC_ERROR=NOT_OK;
									}

				}
				else
				{
					LOC_ERROR=NOT_OK;
				}
			}

 return (LOC_ERROR);
}
	STD_ERROR  DIO_SetPortValue(u8 PORT_,  u8 DIO_VALUE_)
	{
		STD_ERROR LOC_ERROR =OK;


			u8 volatile*REG=PORT_D;

			if (PORT_ >PORT_D && PORT_ < PORT_A)
			{
				REG=PORT_D+(DIO_REG_OFSET*PORT_);
				*REG=DIO_VALUE_;
			}
			else
			{
				LOC_ERROR=NOT_OK;

			}



		return(LOC_ERROR);
	}
	STD_ERROR DIO_SetPortDir(u8 PORT_, u8 DIO_DIR_)
	{
		STD_ERROR LOC_ERROR =OK;

		u8 volatile*REG=DDRD;

					if (PORT_ >PORT_D && PORT_ < PORT_A)
					{
						REG=DDRD+(DIO_REG_OFSET*PORT_);
						*REG=DIO_DIR_;
					}
					else
					{
						LOC_ERROR=NOT_OK;

					}


		return(LOC_ERROR);
	}

	STD_ERROR  DIO_GetPinValue(u8 PORT_, u8 P_,u8 * Pin_Value )
	{
		STD_ERROR LOC_ERROR=OK;
		u8 volatile* REG =PIND;

		if(P_>7||P_<0)
		{
			LOC_ERROR=NOT_OK;
		}
		else if (P_<=0 && P_>=7)
		{
			if (PORT_ > PORT_A || PORT_< PORT_D )
			{
				LOC_ERROR=NOT_OK;

			}
			else if(PORT_ <= PORT_A  &&  PORT_ >= PORT_D )
			{
				REG = PIND+(DIO_REG_OFSET*P_);
				*Pin_Value=(* (REG) &(1<<P_))>>(P_);

			}



		}
		return(LOC_ERROR);
	}



































