#ifndef LCD_H
#define LCD_H

#include "stm32f4xx.h"
#include "initialize.h"

void InitializeLCD(void);

void SendCommand(uint8_t);
void WriteChar(const char);
void WriteString(char*);

void SetCursor(uint8_t, uint8_t);
void ClearDisplay(void);

#endif
