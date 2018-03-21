#include "sys.h"
#include "delay.h"
#include "led.h"

int a=0;

int main(void)
{ 
	delay_init(168);
	LED_Init();
	
	while(1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		a++;
		if(a >= 3 ){
			GPIO_ResetBits(GPIOA,GPIO_Pin_7);
			a=0;
		}
		delay_ms(500);
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		delay_ms(500);
	}
}
