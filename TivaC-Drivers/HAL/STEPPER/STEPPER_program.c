/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  STEPPER_PROGRAM.c
 *        \brief  STEPPER MOTOR Controller Driver
 *
 *      \details  The Driver Implments All Stepper Motor Functionalities 
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Platform_Types.h"
#include "DIO_INTERFACE.h"

#include "STEPPER_interface.h"
#include "STEPPER_cfg.h"
#include "STEPPER_private.h"


/**********************************************************************************************************************
 *  FUNCTIONS IMPLEMENTATION
 *********************************************************************************************************************/

void STEPPER_voidInit ()
{
    /* Configure All pins as Output */
    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelLow);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelLow);
	
}

void STEPPER_voidDeinit ()
{
    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelLow);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelLow);
}

void STEPPER_voidZero ()
{
    uint8 NumberOfSteps = 0;

    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelHigh);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelHigh);
    for ( NumberOfSteps = 0; NumberOfSteps < MAX_STEPS ; NumberOfSteps++)
    {
        STEPPER_voidGoForward();
    }

    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelLow);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelLow);
}

void STEPPER_voidGoForward ()
{
    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelLow);
    _delay_us(2000);

    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelHigh);
    _delay_us(2000);

    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelHigh);
    _delay_us(2000);

    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelLow);
    _delay_us(2000);
}

void STEPPER_voidGoReverse ()
{
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelHigh);

    _delay_us(2000);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelHigh);

    _delay_us(2000);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelLow);


    _delay_us(2000);
    Dio_WriteChannel ( STEPPER_3_PORT   , STEPPER_3_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_4_PORT   , STEPPER_4_PIN  , Dio_LevelLow);
    Dio_WriteChannel ( STEPPER_1_PORT   , STEPPER_1_PIN  , Dio_LevelHigh);
    Dio_WriteChannel ( STEPPER_2_PORT   , STEPPER_2_PIN  , Dio_LevelLow);
    _delay_us(2000);
}

void STEPPER_voidEditPosition (uint16 u16NewPressurePosition)
{
    gOldPosition = (uint8)(u16NewPressurePosition/5.5);
}

uint16 STEPPER_U16_tGetCurrentPosition ()
{
    return (gOldPosition * 5.5);
}

void STEPPER_voidGotoDefinedPosition (uint16 WantedPosition)
{
    uint8 DiffPosition  = 0;
    uint8 NumberOfSteps = 0;


    if (gOldPosition < WantedPosition)
    {
        DiffPosition = WantedPosition - gOldPosition;
        /* not to make action every change */
        if (DiffPosition < 10)
        {
            return;
        }
    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelHigh);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelHigh);

        for (NumberOfSteps =0; NumberOfSteps< DiffPosition ; NumberOfSteps++)
        {
            STEPPER_voidGoReverse ();
        }

    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelLow);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelLow);
    }
    else
    {
        DiffPosition = gOldPosition - WantedPosition;
        /* not to make action every change */
        if (DiffPosition < 10)
        {
            return;
        }
    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelHigh);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelHigh);

        for (NumberOfSteps =0; NumberOfSteps< DiffPosition ; NumberOfSteps++)
        {
           STEPPER_voidGoForward ();
        }

    Dio_WriteChannel ( ENA_A_PORT       , ENA_A_PIN      , Dio_LevelLow);
    Dio_WriteChannel ( ENA_B_PORT       , ENA_B_PIN      , Dio_LevelLow);
    }
    gOldPosition = WantedPosition;
}

void STEPPER_voidPrint (uint16 PressureValue)
{
    /* 50mmhg degree in Gage = 9 steps, so 1mmhg = 1/5.5 step */
    STEPPER_voidGotoDefinedPosition ( (uint16)(PressureValue/5.5));
}

/**********************************************************************************************************************
 *  END OF FILE: STEPPER_PROGRAM.c
 *********************************************************************************************************************/
