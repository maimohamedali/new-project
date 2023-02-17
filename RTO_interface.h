/***********************************/
/****** Author 	: Mayar Saber ******/
/****** Date	: 30/12/2022  ******/
/****** SWC		: RTO - AVR   ******/
/****** Version : 01		  ******/
/***********************************/

#ifndef		_RTO_INTERFACE_H
#define 	_RTO_INTERFACE_H

void	RTO_voidInit(void); 																					    	//Used to initiate the timer we use inside the RTO
u8		RTO_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay , void(*Copy_pf)(void));	//Used to create a task given its priority, periodicity, first delay and a pointer to the function that needs to be executed in that task

#endif
