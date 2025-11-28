

//#define KEYPAD_CC
#include "stdtypes.h"
#include "KeyPad.h"
#include "Converter.h"
#include "LCD.h"
#define F_CPU 8000000
#include <util/delay.h>





void Converter(void)
{
	static u8 flag=0,flag1=0,flag2=0,x_2=0,i=0,flag3=0,flag4=0;
	static u32 num=0;
	u16 x;
	
	x=KEYPAD_GetKey();
	   
	if(flag==0)
	{
		LCD_SetCursor(0,1);
		LCD_WriteString("HELLO CONVERTER");
		_delay_ms(1000);
		LCD_SetCursor(0,0);
		LCD_WriteString("                  ");
		flag=1;
	}
	if(flag1==0)
	{
		LCD_SetCursor(0,2);
		LCD_WriteString("CONVERT FROM:");
		LCD_SetCursor(1,0);
		LCD_WriteString("1des");
		LCD_SetCursor(1,6);
		LCD_WriteString("2bin");
		LCD_SetCursor(1,12);
		LCD_WriteString("3hx");
		flag1=1;
	}
	
	if(x!=NO_KEY)
	{
		//_delay_ms(1000);
		if(flag4=='=')
		{
			LCD_SetCursor(0,2);
			LCD_WriteString("                 ");
			LCD_SetCursor(1,2);
			LCD_WriteString("                 ");
			num=0;
			flag4=0;
		}
		if(x=='1'&&x_2==0)
		{
			x_2=x;
			LCD_SetCursor(0,2);
			LCD_WriteString("                ");
			LCD_SetCursor(0,2);
			LCD_WriteString("CONVERT TO:");
			LCD_SetCursor(1,0);
			LCD_WriteString("                 ");
			LCD_SetCursor(1,1);
			LCD_WriteString("1_Bin");
			LCD_SetCursor(1,9);
			LCD_WriteString("2_Hex");
			
		}
		else if(x=='2'&&x_2==0)
		{
			x_2=x;
			LCD_SetCursor(0,2);
			LCD_WriteString("                ");
			LCD_SetCursor(0,2);
			LCD_WriteString("CONVERT TO:");
			LCD_SetCursor(1,0);
			LCD_WriteString("                 ");
			LCD_SetCursor(1,1);
			LCD_WriteString("1_Des");
			LCD_SetCursor(1,9);
			LCD_WriteString("2_Hex");
			
		}
		else if(x=='3'&&x_2==0)
		{
			x_2=x;
			LCD_SetCursor(0,2);
			LCD_WriteString("                ");
			LCD_SetCursor(0,2);
			LCD_WriteString("CONVERT TO:");
			LCD_SetCursor(1,0);
			LCD_WriteString("                 ");
			LCD_SetCursor(1,1);
			LCD_WriteString("1_Des");
			LCD_SetCursor(1,9);
			LCD_WriteString("2_Bin");
			
		}
		/*========================================================================
		 =========================================================================*/    
		else if(x_2=='1' && (x=='1'||x=='2')&&flag2==0)
		{
			if(x=='1')
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("                ");
				LCD_SetCursor(0,0);
				LCD_WriteString("D:");
				LCD_SetCursor(1,0);
				LCD_WriteString("                ");
				LCD_SetCursor(1,0);
				LCD_WriteString("B:");
				flag2=1;
				
			}
			if(x=='2')
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("                ");
				LCD_SetCursor(0,0);
				LCD_WriteString("D:");
				LCD_SetCursor(1,0);
				LCD_WriteString("                ");
				LCD_SetCursor(1,0);
				LCD_WriteString("H:");
				flag2=2;
				
			}
		}
		else if(x_2=='2' && (x=='1'||x=='2')&&flag2==0)
		{
			if(x=='1')
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("                ");
				LCD_SetCursor(0,0);
				LCD_WriteString("B:");
				LCD_SetCursor(1,0);
				LCD_WriteString("                ");
				LCD_SetCursor(1,0);
				LCD_WriteString("D:");
				flag2=1;
				
			}
			if(x=='2')
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("                ");
				LCD_SetCursor(0,0);
				LCD_WriteString("B:");
				LCD_SetCursor(1,0);
				LCD_WriteString("                ");
				LCD_SetCursor(1,0);
				LCD_WriteString("H:");
				flag2=2;
				
			}
		}
		else if(x_2=='3' && (x=='1'||x=='2')&&flag2==0)
		{
			if(x=='1')
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("                ");
				LCD_SetCursor(0,0);
				LCD_WriteString("H:");
				LCD_SetCursor(1,0);
				LCD_WriteString("                ");
				LCD_SetCursor(1,0);
				LCD_WriteString("D:");
				flag2=1;
				
			}
			else if(x=='2')
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("                ");
				LCD_SetCursor(0,0);
				LCD_WriteString("H:");
				LCD_SetCursor(1,0);
				LCD_WriteString("                ");
				LCD_SetCursor(1,0);
				LCD_WriteString("B:");
				flag2=2;
				
			}
		}
		/*========================================================================
		 =========================================================================*/  //for typing
		
		else if(x_2=='1'&&flag2&&x!='='&&x!='c')
		{
				if(x>='0'&&x<='9')
				{
					num=num*10+(x-'0');
					i=2;
					LCD_SetCursor(0,i);
					i++;
					LCD_WriteNumber(num);
					flag3=1;
				}
		}
		else if(x_2=='2'&&flag2&&x!='='&&x!='c')
		{
				if(x=='0'||x=='1')
				{
					num=num*2+(x-'0');
					i=2;
					LCD_SetCursor(0,i);
					i++;
					LCD_WriteBinary(num);
					flag3=2;
				}
		}
		else if(x_2=='3'&&flag2&&x!='='&&x!='c')
		{
				if(x=='A'||x=='B'||x=='E'||x=='F')
				{
					num=(num*16+(x-'0'))-7;
					i=2;
					LCD_SetCursor(0,i);
					i++;
					LCD_WriteHex(num);
					flag3=3;
				}
		}
		
		/*========================================================================
		 =========================================================================*/  //for print on LCD
		else if(x_2=='1'&&flag3&&x=='=')
		{
			if(flag2==1)
			{
				i=2;
				LCD_SetCursor(1,i);
				i++;
				LCD_WriteBinary(num);
				flag4=x;
			}
			if(flag2==2)
			{
				i=2;
				LCD_SetCursor(1,i);
				i++;
				LCD_WriteHex(num);
				flag4=x;
			}
		}
		else if(x_2=='2'&&flag3&&x=='=')
		{
			if(flag2==1)
			{
				i=2;
				LCD_SetCursor(1,i);
				i++;
				LCD_WriteNumber(num);
				flag4=x;
			}
			if(flag2==2)
			{
				i=2;
				LCD_SetCursor(1,i);
				i++;
				LCD_WriteHex(num);
				flag4=x;
			}
		}
		else if(x_2=='3'&&flag3&&x=='=')
		{
			if(flag2==1)
			{
				i=2;
				LCD_SetCursor(1,i);   
				i++;
				LCD_WriteNumber(num);
				flag4=x;
				
			}
			if(flag2==2)
			{
				i=2;
				LCD_SetCursor(1,i);
				i++;
				LCD_WriteBinary(num);
				flag4=x;
			}
		}
		else if(((x!='1'&&x!='2'&&x!='3')&&x_2==0&&x!='c')   ||  (x_2&&(x!='1'||x!='2')&&flag2==0))
		{
			LCD_SetCursor(0,0);
			LCD_WriteString("                  ");
			LCD_SetCursor(1,0);
			LCD_WriteString("                  ");
			LCD_SetCursor(0,2);
			LCD_WriteString("WRONG ENTRY!!");
			_delay_ms(500);
			flag1=0;
			
		}
		else if(x=='c')
		{
			//flag=0;
			flag1=0;
			flag2=0;
			x_2=0;
			i=0;
			flag3=0;
			flag4=0;
			num=0;
			LCD_SetCursor(0,0);
			LCD_WriteString("                  ");
			LCD_SetCursor(1,0);
			LCD_WriteString("                  ");
			 
		}
		
	}
	
	
	
	
	
	
}