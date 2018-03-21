/**********************************************************************
 * @Modify: Trìnhđộ
 * @Date: 21/3/2018
 **********************************************************************/
#include "sys.h"
#include "delay.h"
#include "led.h"

int a=0;

int main(void)
{ 
	delay_init(168);
	LED_Init();	//config Output pin
	
	while(1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);	//set PA06 low
		a++;
		if(a >= 3 ){
			GPIO_ResetBits(GPIOA,GPIO_Pin_7);	//set PA07 low
			a=0;
		}
		delay_ms(500);
		GPIO_SetBits(GPIOA, GPIO_Pin_6);	//set PA06 high
		GPIO_SetBits(GPIOA, GPIO_Pin_7);	//set PA07 high
		delay_ms(500);
	}
}
