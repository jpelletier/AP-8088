/*---------------------------------------------------------------------------*
 * menus.c                                                               *
 * Copyright (C) 2022  Jacques Pelletier                                     *
 *                                                                           *
 * This program is free software; you can redistribute it and *or            *
 * modify it under the terms of the GNU General Public License               *
 * as published by the Free Software Foundation; either version 2            *
 * of the License, or (at your option) any later version.                    *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License for more details.                              *
 *                                                                           *
 * You should have received a copy of the GNU General Public License         *
 * along with this program; if not, write to the Free Software Foundation,   *
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.           *
 *---------------------------------------------------------------------------*/
#include <target_probe.h>

void mainMenu(void)
{
	char c;

	//Turns on software flow control
	Uart_sendstring("\021\033[2JXT Bus Alien probe\r\n\n");
	Uart_sendstring(
			"A: Test control lines\r\n"
			"B: Test data lines\r\n"
			"C: Test address lines\r\n"
			"D: Bus transactions\r\n"
			"E: Bus repeated transactions\r\n"
			"F: Memory operations\r\n"
			);
	c = toupper(serial_getchar());
	switch(c)
	{
		case 'A':
			ControlLinesMenu();
			break;
		case 'B':
			DataLinesMenu();
			break;
		case 'C':
			AddressLinesMenu();
			break;
		case 'D':
			BusTransactionsMenu();
			break;
		case 'E':
			BusRepeatTransactionsMenu();
			break;
		case 'F':
			MemoryOperationsMenu();
			break;
		default:
			;
	}
}

void ControlLinesMenu(void)
{
	char c;

	//INACTIVE
	GPIOC->ODR = 0xFF00;

	AnsiSaveCursorPosition();

/*
BIT_RD		C8
BIT_S2		C9
BIT_S1		C10
BIT_S0	 	C11
BIT_LOCK	C12
BIT_INTA	C13
BIT_SSO		D4

BIT_RESET	E1
BIT_NMI		E2
BIT_INTR	E3
BIT_READY	E4
BIT_CLK		E5
BIT_TEST	E6
BIT_MN_MX	E7
BIT_RQGT0	E8
BIT_RQGT1	E9
*/
	do
	{
		Uart_sendstring("\033[2JTest Control Lines\r\n\n");
		Uart_sendstring("RD S2 S1 S0 LOCK INTA SSO\r\n");
		serial_printf(  " %1d  %1d  %1d  %1d  %1d    %1d    %1d\r\n\n",
				getBit(BIT_RD,GPIOC->ODR),
				getBit(BIT_S2,GPIOC->ODR),
				getBit(BIT_S1,GPIOC->ODR),
				getBit(BIT_S0,GPIOC->ODR),
				getBit(BIT_LOCK,GPIOC->ODR),
				getBit(BIT_INTA,GPIOC->ODR),
				getBit(BIT_SSO,GPIOD->ODR));

		Uart_sendstring("RESET NMI INTR READY TEST MN_MX RQGT1 RQGT0\r\n");
		serial_printf(  "  %1d    %1d   %1d     %1d    %1d     %1d     %1d     %1d\r\n\n",
				getBit(BIT_RESET,GPIOE->IDR),
				getBit(BIT_NMI,GPIOE->IDR),
				getBit(BIT_INTR,GPIOE->IDR),
				getBit(BIT_READY,GPIOE->IDR),
				getBit(BIT_TEST,GPIOE->IDR),
				getBit(BIT_MN_MX,GPIOE->IDR),
				getBit(BIT_RQGT1,GPIOE->IDR),
				getBit(BIT_RQGT0,GPIOE->IDR));

		Uart_sendstring(
				"A: toggle RD\r\n"
				"B: toggle S2\r\n"
				"C: toggle S1\r\n"
				"D: toggle S0\r\n"
				"E: toggle LOCK\r\n"
				"F: toggle INTA\r\n"
				"G: toggle SSO\r\n"
				"ESC: return to previous menu\r\n"
				);
		c = toupper(serial_getchar());
		switch(c)
		{
			case 'A':
				GPIOC->ODR ^= MASK_RD;
				break;
			case 'B':
				GPIOC->ODR ^= MASK_S2;
				break;
			case 'C':
				GPIOC->ODR ^= MASK_S1;
				break;
			case 'D':
				GPIOC->ODR ^= MASK_S0;
				break;
			case 'E':
				GPIOC->ODR ^= MASK_LOCK;
				break;
			case 'F':
				GPIOC->ODR ^= MASK_INTA;
				break;
			case 'G':
				GPIOD->ODR ^= MASK_SSO;
				break;

			case ESC:
				return;
			default:
				;
		}

		AnsiRestoreCursorPosition();

	} while (true);
}

/* We toggle AD lines regardless of the multiplexing */
void DataLinesMenu(void)
{
	char c;

	//INACTIVE
	GPIOC->ODR = 0xFF00;

	AnsiSaveCursorPosition();

	do
	{
		Uart_sendstring("\033[2JTest Data Lines\r\n\n");
		Uart_sendstring("D7 D6 D5 D4 D3 D2 D1 D0\r\n");
		serial_printf(" %1d  %1d  %1d  %1d  %1d  %1d  %1d  %1d\r\n\n",
				getBit(7,GPIOC->ODR),
				getBit(6,GPIOC->ODR),
				getBit(5,GPIOC->ODR),
				getBit(4,GPIOC->ODR),
				getBit(3,GPIOC->ODR),
				getBit(2,GPIOC->ODR),
				getBit(1,GPIOC->ODR),
				getBit(0,GPIOC->ODR));

		Uart_sendstring("D7 D6 D5 D4 D3 D2 D1 D0\r\n");
		serial_printf(" %1d  %1d  %1d  %1d  %1d  %1d  %1d  %1d\r\n\n",
				getBit(7,GPIOC->IDR),
				getBit(6,GPIOC->IDR),
				getBit(5,GPIOC->IDR),
				getBit(4,GPIOC->IDR),
				getBit(3,GPIOC->IDR),
				getBit(2,GPIOC->IDR),
				getBit(1,GPIOC->IDR),
				getBit(0,GPIOC->IDR));

		Uart_sendstring(
				"A: toggle AD7\r\n"
				"B: toggle AD6\r\n"
				"C: toggle AD5\r\n"
				"D: toggle AD4\r\n"
				"E: toggle AD3\r\n"
				"F: toggle AD2\r\n"
				"G: toggle AD1\r\n"
				"H: toggle AD0\r\n"
				"I: direction input\r\n"
				"O: direction output\r\n"
				"ESC: return to previous menu\r\n"
				);
		c = toupper(serial_getchar());
		switch(c)
		{
			case 'A':
				GPIOC->ODR ^= 0x80;
				break;
			case 'B':
				GPIOC->ODR ^= 0x40;
				break;
			case 'C':
				GPIOC->ODR ^= 0x20;
				break;
			case 'D':
				GPIOC->ODR ^= 0x10;
				break;
			case 'E':
				GPIOC->ODR ^= 0x08;
				break;
			case 'F':
				GPIOC->ODR ^= 0x04;
				break;
			case 'G':
				GPIOC->ODR ^= 0x02;
				break;
			case 'H':
				GPIOC->ODR ^= 0x01;
				break;
			case 'I':
				//set data direction in
				GPIOC->MODER = 0x55550000;
				break;
			case 'O':
				//set data direction out
				GPIOC->MODER = 0x55555555;
				break;
			case ESC:
				return;
			default:
				;
		}

		AnsiRestoreCursorPosition();

	} while (true);
}

void AddressLinesMenu(void)
{
	char c;

	//INACTIVE
	GPIOC->ODR = 0xFF00;

	AnsiSaveCursorPosition();

	do
	{
		Uart_sendstring("\033[2JTest Address Lines\r\n\n");
		Uart_sendstring("A19 A18 A17 A16 A15 A14 A13 A12 A11 A10 A9 A8\r\n");
		serial_printf("  %1d   %1d   %1d   %1d   %1d   %1d   %1d   %1d   %1d   %1d  %1d  %1d\r\n\n",
				getBit(3,GPIOD->ODR),	//A19
				getBit(2,GPIOD->ODR),	//A18
				getBit(1,GPIOD->ODR),	//A17
				getBit(0,GPIOD->ODR),	//A16
				getBit(15,GPIOD->ODR),
				getBit(14,GPIOD->ODR),
				getBit(13,GPIOD->ODR),
				getBit(12,GPIOD->ODR),
				getBit(11,GPIOD->ODR),
				getBit(10,GPIOD->ODR),
				getBit( 9,GPIOD->ODR),
				getBit( 8,GPIOD->ODR));

		Uart_sendstring(
				"A: toggle A19\r\n"
				"B: toggle A18\r\n"
				"C: toggle A17\r\n"
				"D: toggle A16\r\n"
				"E: toggle A15\r\n"
				"F: toggle A14\r\n"
				"G: toggle A13\r\n"
				"H: toggle A12\r\n"
				"I: toggle A11\r\n"
				"J: toggle A10\r\n"
				"K: toggle A9\r\n"
				"L: toggle A8\r\n"
				"ESC: return to previous menu\r\n"
				);
		c = toupper(serial_getchar());
		switch(c)
		{
			case 'A':
				GPIOD->ODR ^= 0x0008;
				break;
			case 'B':
				GPIOD->ODR ^= 0x0004;
				break;
			case 'C':
				GPIOD->ODR ^= 0x0002;
				break;
			case 'D':
				GPIOD->ODR ^= 0x0001;
				break;
			case 'E':
				GPIOD->ODR ^= 0x8000;
				break;
			case 'F':
				GPIOD->ODR ^= 0x4000;
				break;
			case 'G':
				GPIOD->ODR ^= 0x2000;
				break;
			case 'H':
				GPIOD->ODR ^= 0x1000;
				break;
			case 'I':
				GPIOD->ODR ^= 0x0800;
				break;
			case 'J':
				GPIOD->ODR ^= 0x0400;
				break;
			case 'K':
				GPIOD->ODR ^= 0x0200;
				break;
			case 'L':
				GPIOD->ODR ^= 0x0100;
				break;
			case ESC:
				return;
			default:
				;
		}

		AnsiRestoreCursorPosition();

	} while (true);
}

void BusTransactionsMenu(void)
{
	char c;
	uint16_t segment, address;
	uint8_t data_byte;

	AnsiSaveCursorPosition();

	do
	{
		Uart_sendstring("\033[2JBus transactions\r\n\n");
		Uart_sendstring(
				"A: set address\r\n"
				"B: set data\r\n"
				"C: set segment\r\n"
				"D: do 1 memory read cycle\r\n"
				"E: do 1 memory write cycle\r\n"
				"F: do 1 IO port read cycle\r\n"
				"G: do 1 IO port write cycle\r\n"
				"ESC: quit\r\n\n"
				);
		c = toupper(serial_getchar());
		switch(c)
		{
			case 'A':
				setaddress(&address);
				break;
			case 'B':
				setdatabyte(&data_byte);
				break;
			case 'C':
				setsegment(&segment);
				break;
			case 'D':
				serial_printf("Mem read at [%04X:%04X] %02X\r\n", segment, address, TargetMemRd(0, segment, address));
				break;
			case 'E':
				serial_printf("Mem write at [%04X:%04X] %02X\r\n", segment, address, data_byte);
				TargetMemWr(0,segment,address,data_byte);
				break;
			case 'F':
				serial_printf("IO read at %04X: %02X\r\n", address, TargetIoRd(0,address));
				break;
			case 'G':
				serial_printf("IO write at %04X: %02X\r\n", address, data_byte);
				TargetIoWr(0,address, data_byte);
				break;
			case ESC:
				return;
		}

		AnsiRestoreCursorPosition();

	} while (true);
}

/* hardware diag with scope */
void BusRepeatTransactionsMenu(void)
{
	char c;
	uint16_t segment, address;
	uint8_t data_byte;

	Uart_sendstring("\033[2JBus transaction loops\r\n\n");
	Uart_sendstring(
			"A: set address\r\n"
			"B: set data\r\n"
			"C: set segment\r\n"
			"D: memory read cycles\r\n"
			"E: memory write cycles\r\n"
			"F: IO port read cycles\r\n"
			"G: IO port write cycles\r\n"
			"ESC: quit\r\n\n"
			);
	c = toupper(serial_getchar());
	switch(c)
	{
		case 'A':
			setaddress(&address);
			break;
		case 'B':
			setdatabyte(&data_byte);
			break;
		case 'C':
			setsegment(&segment);
			break;
		case 'D':
			AnsiSaveCursorPosition();
			do
			{
				serial_printf("Mem read at [%04X:%04X] %02X\r\n", segment, address, TargetMemRd(0, segment, address));
				AnsiRestoreCursorPosition();
			} while (!IsDataAvailable());
			break;
		case 'E':
			AnsiSaveCursorPosition();
			do
			{
				serial_printf("Mem write at [%04X:%04X] %02X\r\n", segment, address, data_byte);
				TargetMemWr(0, segment, address, data_byte);
				AnsiRestoreCursorPosition();
			} while (!IsDataAvailable());
			break;
		case 'F':
			AnsiSaveCursorPosition();
			do
			{
				serial_printf("IO read at %04X: %02X\r\n", address, TargetIoRd(0,address));
				AnsiRestoreCursorPosition();
			} while (!IsDataAvailable());
			break;
		case 'G':
			AnsiSaveCursorPosition();
			do
			{
				serial_printf("IO write at %04X: %02X\r\n", address, data_byte);
				TargetIoWr(0,address, data_byte);
				AnsiRestoreCursorPosition();
			} while (!IsDataAvailable());
			break;

		default:
			;
	}
}

void MemoryOperationsMenu(void)
{
	char c;
	uint8_t data_byte;
	uint8_t port;

	AnsiSaveCursorPosition();

	do
	{
		Uart_sendstring("\033[2JMemory operations\r\n\n");
		Uart_sendstring(
				"E: edit memory\r\n"
//				"L: load Intel hex file\r\n"
				"F: fill memory\r\n"
				"M: move memory\r\n"
				"I: input\r\n"
				"O: output\r\n"
				"Q: quit\r\n\n"
				);
		c = toupper(serial_getchar());
		switch(c)
		{
			case 'E':
				binary_ed(0,0);
				break;
//			case 'L':
//				loadIntelHex();
//				GetAnyKey();
//				break;
			case 'F':
				fillMemory();
				break;
			case 'M':
				moveMemory();
				break;
			case 'I':
				Uart_sendstring("Input port: ");
				c = setdatabyte(&port);
				if (c != 'Q')
				{
					data_byte = TargetIoRd(0, port);
					serial_printf(" %02X\r\n",data_byte);
				}
				break;
			case 'O':
				Uart_sendstring("Output port: ");
				c = setdatabyte(&port);
				if (c != 'Q')
				{
					putchar(' ');
					c = setdatabyte(&data_byte);
					if (c != 'Q')
					{
						TargetIoWr(0,port, data_byte);
						Uart_sendstring("\r\n");
					}
				}
				break;
			case 'Q':
				return;
		}

		AnsiRestoreCursorPosition();

	} while (true);
}
