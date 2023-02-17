/***********************************/
/****** Author 	: Mayar Saber ******/
/****** Date	: 30/12/2022  ******/
/****** SWC		: RTO - AVR   ******/
/****** Version : 01		  ******/
/***********************************/

/*LIB*/
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

/*MCAL*/
#include	"TIMERS_interface.h"

/*Service*/
#include	"RTO_interface.h"
#include	"RTO_private.h"
#include	"RTO_config.h"

/*Array of TCBs*/
RTO_TCB		RTO_AstrTasks[RTO_u8_MAX_NUMBER_OF_TASKS];


void	RTO_voidInit(void)
/*Used to initiate the timer we use inside the RTO*/
{
	/*Set call back function of Timer0 CTC mode  to call schedular function*/
	/*and to set the counter value to 5 overflows*/
	TIMER0_u8SetCallBack_CTC(5, &RTO_voidSchedular);
	
	/*Set OCR0 value from calculations = 199*/
	TIMER0_voidSetCompareMatchValue(199);
	
	/*Initiate Timer0*/
	TIMER0_voidInit();
}

//-------------------------------------------------------------------------------------------------------------

u8		RTO_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay , void(*Copy_pf)(void))
/*Used to create a task given its priority (Highest priority = 0), periodicity, first delay and a pointer to the function that needs to be executed in that task*/
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8Priority < RTO_u8_MAX_NUMBER_OF_TASKS) && (Copy_pf != NULL))
	{
		RTO_AstrTasks[Copy_u8Priority].Periodicity  = Copy_u16Periodicity;
		RTO_AstrTasks[Copy_u8Priority].FirstDelay   = Copy_u16FirstDelay;
		RTO_AstrTasks[Copy_u8Priority].pf 			= Copy_pf;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}

//-------------------------------------------------------------------------------------------------------------

static void	RTO_voidSchedular(void)
/*Used to do the job of a schedular and a dispatcher*/
{
	u8 Local_u8Counter;
	/*For loop to loop on the ready tasks*/
	for(Local_u8Counter = 0 ; Local_u8Counter < RTO_u8_MAX_NUMBER_OF_TASKS ; Local_u8Counter++)
	{
		if(RTO_AstrTasks[Local_u8Counter].FirstDelay == 0)
		{
			/*Call Task*/
			RTO_AstrTasks[Local_u8Counter].pf();
			/*Reload the FirstDelay value with the periodicity value - 1*/
			RTO_AstrTasks[Local_u8Counter].FirstDelay = RTO_AstrTasks[Local_u8Counter].Periodicity - 1;
		}

		else
		{
			RTO_AstrTasks[Local_u8Counter].FirstDelay--;
		}
	}
}






































