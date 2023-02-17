/***********************************/
/****** Author 	: Mayar Saber ******/
/****** Date	: 30/12/2022  ******/
/****** SWC		: RTO - AVR   ******/
/****** Version : 01		  ******/
/***********************************/

#ifndef		_RTO_PRIVATE_H
#define 	_RTO_PRIVATE_H

typedef  struct
{
	u16	 Periodicity;
	u16	 FirstDelay;
	void (*pf)(void);
	
}RTO_TCB;

static void	RTO_voidSchedular(void);	//Used to do the job of a schedular and a dispatcher -- In private file because it's called by the timer

#endif
