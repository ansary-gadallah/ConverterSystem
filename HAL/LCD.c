
#include "stdtypes.h"
#include "DIO_interface.h"
#include "LCD.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "Utils.h"


#if LCD_MODE==_8_BIT



static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x3c);  //8 BIT 16 LINE
	WriteIns(0x0C);//0x0e,0x0f cursor
	WriteIns(0x01);  // clear screen
	_delay_ms(1);
	WriteIns(0x06); // For increment
}


#elif LCD_MODE==_4_BIT
static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);

   DIO_WritePin(D7,READ_BIT(ins,3));
   DIO_WritePin(D6,READ_BIT(ins,2));
   DIO_WritePin(D5,READ_BIT(ins,1));
   DIO_WritePin(D4,READ_BIT(ins,0));
   DIO_WritePin(EN,HIGH);
   _delay_ms(1);
   DIO_WritePin(EN,LOW);
   _delay_ms(1);
	
	
}

static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);

	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);  //4 BIT 16 LINE
	WriteIns(0x28);
	WriteIns(0x0c);//0x0e,0x0f cursor
	WriteIns(0x01);  // clear screen
	_delay_ms(1);
	WriteIns(0x06); // For increment
	
	
	
}
#endif
void LCD_Clear(void)
{
	WriteIns(0x01);  // clear screen
	_delay_ms(1);
}
void LCD_WriteChar(u8 ch)
{
	WriteData(ch);    //c8
}
void LCD_WriteNumber(s32 num)
{
	u8 rem,str[16],i=0;
	s8 j;
	
	if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	
	if(num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
	
	}
	while(num)
	{
		str[i]=num%10+'0';
		num=num/10;
		i++;
	}
    for(j=i-1;j>=0;j--)
 	{      
		
		LCD_WriteChar(str[j]);
	}  
}

void LCD_WriteString(c8*str)
{
	u8 i;
	for(i=0;str[i];i++)   
	{
		LCD_WriteChar(str[i]);
	}
}


void LCD_WriteBinary(u32 num)  
{
	u8 str [16];
		s32 i=0,j;
		if(num==0)
		{
			LCD_WriteChar('0');
			return;
		}
    while(num)
	{
		str[i]=num%2+'0';
		num=num/2;
		i++;
	}
	 for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
}
void LCD_WriteHex(u32 num)   //255==> 1111  1111    1010
{
	
	u8 x=0,res1=0,j=0,res2=0 ,str[32],k=0;      //  0011 0011>>4
	s8 i;
	for(i=0;i<4;i++)     //101
	{
		x=READ_BIT(num,i);      //0011 1110 1000
		while(j<i&&x)
		{
			x=x*2;
			j++;
		}
		res1=x;
		res2=res2+res1;
		j=0;
		if(i==3)
		{
			
			str[k]=res2;
			k++;
			//LCD_WriteChar(res2+'0');     
			
			//LCD_WriteChar(str[k-1]);
			i=-1;
			res2=0;
			num=num>>4;
			if(num==0)
			{
				break;
			}
		}
	} 
	for(i=k-1;i>=0;i--)    // 1000   11 1110 1000    3E8
	{
		if(str[i]==10)
		{
			LCD_WriteChar('A');
		}
		else if(str[i]==11)
		{
			LCD_WriteChar('B');
		}
		else if(str[i]==12)
		{
			LCD_WriteChar('C');
		}
		else if(str[i]==13)
		{
			LCD_WriteChar('D');
		}
		else if(str[i]==14)
		{
			LCD_WriteChar('E');
		}
		else if(str[i]==15)
		{
			LCD_WriteChar('F');
		}
		else
		{
			LCD_WriteChar(str[i]+'0');
		}
		
		
	}       
}

void LCD_SetCursor(u8 line ,u8 cell)
{
       if(line==0)
	   {
		  cell =(cell)|(1<<7);
		   WriteIns(cell);
		   
	   }
	   else if(line==1)
	   {
		    cell =(cell+0x40)|(1<<7);
		   WriteIns(cell);                 
	   }
}


void LCD_WriteNumber_4D(u16 num)
{
	/*u8  arr[4]={0};
		s8 i;
	for(i=3;i>=0;i--)      
	{
		arr[i]=num%10;
		num=num/10;
	}
	for(i=0;i<4;i++)
	{
		LCD_WriteChar(arr[i]+'0');
	}*/
	u16 i,x;
	for(i=1000;i>0;i=i/10)
	{
		x=((num/i)%10)+'0';
		LCD_WriteChar(x);
		
	}
	

}
void LCD_SetCursorString(u8 line,u8 cell,u8*str)
{
	
	 if(line==0)
	 {
		 cell =(cell)|(1<<7);
		 WriteIns(cell);
		 LCD_WriteString(str);
		 
	 }
	 else if(line==1)
	 {
		 cell =(cell+0x40)|(1<<7);
		 WriteIns(cell);
		 		 LCD_WriteString(str);
	 }
	
	
	
	
}
u8 string_len(char*str)
{
	u8 i;
	for(i=0; str[i]; i++)
	{

	}
	return i;
}

void LCD_ClearCell(u8 line,u8 cell,u8 num)
{
	LCD_SetCursor(line,cell);
	u8 i;
         for(i=0;i<num;i++)
		 {
			 LCD_WriteChar(' ');
			 
		 }
	
	
}

void LCD_move_string(s8*str,u8 size)
{            
	static n=0,n2=0,y;
     u8 i;
	 LCD_Clear();
	
	if((n+size)<=15)
	{
		LCD_SetCursor(0,n);
		LCD_WriteString(str);
		
	}
	else if((n+size)>15)
	{
		LCD_SetCursor(0,n);
		y=(n+(size-1))-15;
		LCD_SetCursor(1,5);
		/*LCD_WriteNumber(y);
		_delay_ms(2000);*/
		for(i=0; i<(size-y+1) ;i++)
		{
			LCD_WriteChar(str[i]);
		}
		//n=0;
		LCD_SetCursor(1,n2);
		for(i=y;str[i];i++)
		{
			LCD_WriteChar(str[i]);
		}
		n2++;
	}
	n++;
	if(n>15)
	{
		
	}
	_delay_ms(200);
	
}

/*void LCD_move_string(s8*str,u8 size)
{
	//LCD_SETCURSOR(1,1);
	LCD_START(str,size,1);
	for(u8 i=0;i<16;i++){
		LCD_shift_right();
		_delay_ms(400);
	}
	
	LCD_CLEAR();
	
	//LCD_SETCURSOR(2,1);
	LCD_START(str,size,2);
	for(u8 i=0;i<16;i++){
		LCD_shift_right();
		_delay_ms(400);
	}
	LCD_CLEAR();
}*/


/*void LCD_shift_right()
{
	WriteIns(28);
}
void LCD_shift_left()
{
	WriteIns(0x18);
}*/

  
/*
void LCD_START(s8 *str,u8 size,u8 line)
   {                                      
	
	for(u8 i=size;i>0;i--){
		LCD_SETCURSOR(line,1);
		for(u8 k=0;k<size-(i-1);k++){
			LCD_WRITEchare(str[(i-1)+(k)]);     //ANSARY   6
	  }
		_delay_ms(400);
		
	}
}

void LCD_move_string(s8*str,u8 size){
	//LCD_SETCURSOR(1,1);
	LCD_START(str,size,1);
	for(u8 i=0;i<16;i++){
		LCD_shift_right();
		_delay_ms(400);
	}
	
	LCD_CLEAR();
	
	//LCD_SETCURSOR(2,1);
	LCD_START(str,size,2);
	for(u8 i=0;i<16;i++){
		LCD_shift_right();
		_delay_ms(400);
	}
	LCD_CLEAR();
}




void LCD_shift_right(){
	LCD_write_instruction(28);
	
	
	
	
	
	
	
	u8 arrow_pattern[]={0x00,0x04,0x02,0x1f,0x02,0x04,0x00,0x00};

	u8 man_pattern[]={0x04,0x0a,0x04,0x0e,0x15,0x04,0x0a,0x0a};
	
	u8 man_with_arrow_pattern[]={0x04,0x0e,0x06,0x1f,0x17,0x04,0x0a,0x0a};
	
	u8 dead_man_pattern1[]={0x00,0x00,0x08,0x06,0x01,0x06,0x08,0x00};
	
	u8 dead_man_pattern2[]={0x00,0x00,0x10,0x0a,0x0d,0x0a,0x10,0x00};
}*/