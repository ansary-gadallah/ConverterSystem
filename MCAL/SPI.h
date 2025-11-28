


#ifndef SPI_H_
#define SPI_H_

typedef enum{
	MASTER,
	SLAVE
	
}SPIMode_type;




void SPI_Init(SPIMode_type mode);

u8 SPI_SendReceive(u8 data);
u8 SPI_ReceivePerodic(u8*pdata);
void SPI_SendNoBlock(u8 data);
u8 SPI_ReceiveNoBlock(void);
void SPI_InterruptEnable(void);
void SPI_InterruptDisable(void);
void SPI_SetCallBack(void (*LocalFptr)(void));



#endif /* SPI_H_ */