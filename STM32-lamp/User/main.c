#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include "Key.h"
#include "LED.h"
#include "PWM.h"
uint16_t AD1;
uint8_t KeyNum = 0;
int main(void)
{   
	AD_Init();
    Key_Init();
	LED_Init();
	PWM_Init();
	OLED_I2C_Init();
	OLED_Clear();

	
	OLED_ShowString(2, 1, "menu:");
	
	while (1)
	{
		
		KeyNum = Key_GetNum();
		
		if(KeyNum == 1)
		{
		PWM_SetCompare1(50);
		Delay_ms(10);
		PWM_SetCompare(50);
		Delay_ms(10);
			
		OLED_Clear();	
		OLED_ShowString(2, 1, "set light");
		  while(1)
		  {
			KeyNum = Key_GetNum();
			  
		    if(KeyNum == 1)
		    {
		     PWM_SetCompare1(50);
		     Delay_ms(10);
			 PWM_SetCompare(50);
		     Delay_ms(10);
			}
			if(KeyNum == 2)
		    {
		     PWM_SetCompare1(10);
		     PWM_SetCompare(10);
		     Delay_ms(10);
			}
			if(KeyNum == 3)
		    {
		     PWM_SetCompare1(1);
		     PWM_SetCompare(1);
		     Delay_ms(10);
		    }	
		    if(KeyNum == 4)
		    {
		     PWM_SetCompare1(0);
		     PWM_SetCompare(0);
			 OLED_Clear();
			 OLED_ShowString(1, 1, "menu");
		     Delay_ms(10);
			 break;
		    }
		  }
		}
		
		
		
		if(KeyNum == 2)
		{
		
		PWM_SetCompare1(0);
		PWM_SetCompare(0);
		Delay_ms(10);
		OLED_Clear();	
		OLED_ShowString(2, 1, "auto light");
			
		  while(1)
		  {
		  KeyNum = Key_GetNum();
		  OLED_ShowString(3, 1, "cd");	
		  AD1 = AD_GetValue(ADC_Channel_4);
		  OLED_ShowNum(3, 7, AD1, 4);
		  Delay_ms(100);
		if(KeyNum != 4){
			if(AD1 <= 1500)
		    {
			 PWM_SetCompare1(0);
		     PWM_SetCompare(0);
			 Delay_ms(100);
		    }			  
			if(AD1 <= 2000&&AD1>=1500)
		    {
			 PWM_SetCompare1(1);
		     PWM_SetCompare(1);
			 Delay_ms(100);
		    }		  
		    if(AD1 >= 2000&&AD1 <= 3000)
		    {
			 PWM_SetCompare1(10);
		     PWM_SetCompare(10);
			 Delay_ms(100);
		    }
		    if(AD1 >= 3000)
		    {
			 PWM_SetCompare1(50);
		     PWM_SetCompare(50);
			 Delay_ms(100);
		    }
		}
		    if(KeyNum == 4)
		    {
		     PWM_SetCompare1(0);
		     PWM_SetCompare(0);
			 OLED_Clear();
			 OLED_ShowString(1, 1, "menu");
		     Delay_ms(10);
			 break;
		    }		
			
		  }
		}
		if(KeyNum == 3)
		{
		PWM_SetCompare1(1);
		PWM_SetCompare(1);
		Delay_ms(10);
		}		
		if(KeyNum == 4)
		{
		PWM_SetCompare1(0);
		PWM_SetCompare(0);
		Delay_ms(10);
		}		
		
		
		

	}
}
