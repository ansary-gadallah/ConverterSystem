/*
 * KeyPad_cfg.h
 *
 * Created: 05/12/2022 11:19:04
 *  Author: Kimo Store
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define  COLS    4
#define  ROWS    4

#ifdef KEYPAD_C 
  const u8 KeysArray[ROWS][COLS]={  {'7','8','9','/'},
                                    {'4','5','6','*'},
                                    {'1','2','3','-'},
                                    {'c','0','=','+'} };
#endif

/*
#ifdef KEYPAD_CC
const u8 KeysArray[ROWS][COLS]={  {'7','8','9','A'},
                                  {'4','5','6','B'},
                                  {'1','2','3','E'},
                                  {'c','0','=','F'} };
#endif*/

#define  NO_KEY   'T'

#define  FIRST_OUTPUT PINB4   
#define  FIRST_INPUT  PIND2





#endif /* KEYPAD_CFG_H_ */