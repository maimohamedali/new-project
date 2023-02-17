/*LIB*/
#include 	"STD_TYPES.h"
#include	"BIT_MATH.h"

/*MCAL*/
#include    "DIO_interface.h"
#include	"GI_interface.h"

/*Service*/
#include	"RTO_interface.h"

void App_voidTask1(void);
void App_voidTask2(void);
void App_voidTask3(void);

int main(void)
{

	DIO_voidInit();
	GI_voidEnable();

	/*First- we've to create the tasks we want*/
	RTO_u8CreateTask(0 , 1000 , 6000 , &App_voidTask1);
	RTO_u8CreateTask(1 , 2000 , 0    , &App_voidTask2);
	RTO_u8CreateTask(2 , 5000 , 0    , &App_voidTask3);

	/*Second- Initiate the RTO*/
	RTO_voidInit();

	while(1)
	{

	}
	return 0;
}

void App_voidTask1(void)
{
	volatile u8 Local_u8Flag=0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA , DIO_u8_PIN0 , DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA , DIO_u8_PIN0 , DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}

void App_voidTask2(void)
{
	volatile u8 Local_u8Flag=0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA , DIO_u8_PIN1 , DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA , DIO_u8_PIN1 , DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}

void App_voidTask3(void)
{
	volatile u8 Local_u8Flag=0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA , DIO_u8_PIN2 , DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA , DIO_u8_PIN2 , DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}
