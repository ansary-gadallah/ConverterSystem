/*
 * LCD.h
 *
 * Created: 26/11/2022 10:27:59
 *  Author: Kimo Store
 */ 


#ifndef LCD_H_
#define LCD_H_

#define _4_BIT   1
#define _8_BIT   2


#define  LCD_MODE   _4_BIT   

#define RS  PINA1
#define EN  PINA2
#define LCD_PORT  PA
#define PORT_VALUE  0X38 //FOR Function writePort


#define D7   PINA6
#define D6   PINA5
#define D5   PINA4
#define D4   PINA3








void LCD_Init(void);
void LCD_Clear(void);
void LCD_WriteNumber(s32 num);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(c8*str);
static void WriteIns(u8 ins);
static void WriteData(u8 data);
void LCD_WriteBinary(u32 num);
void LCD_WriteHex(u32 num); 
void LCD_SetCursor(u8 line ,u8 cell);
void LCD_SetCursorString(u8 line,u8 cell,u8*str); 
void LCD_WriteNumber_4D(u16 num);
u8 string_len(char*str);
void LCD_ClearCell(u8 line,u8 cell,u8 num);
void LCD_shift_right();
void LCD_shift_left();
void LCD_CG_Ram(u8 add);
void LCD_move_string(s8*str,u8 size);

void LCD_START(s8 *str,u8 size,u8 line);

#endif /* LCD_H_ */