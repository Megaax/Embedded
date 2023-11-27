#include "STD_TYPES_H.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void STK_VoidInit()
{
	STK_CTRL=0x00000003;

}

void STK_voidSetTimer(u32 u32_TIME)
{
	STK_LOAD = u32_TIME;
}

