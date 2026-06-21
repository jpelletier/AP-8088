#ifndef UTILS_H_
#define UTILS_H_

void serial_gets(char *buffer);
char serial_getchar(void);
int serial_printf(char *format, ...);

void removeStringTrailingNewline(char *str);
void GetAnyKey(void);

void AnsiClearDisplay(void);
void AnsiSaveCursorPosition(void);
void AnsiRestoreCursorPosition(void);

int getBit(int bit, int value);
uint8_t revert_bits(uint8_t in);
uint16_t revert_word(uint16_t in);

char in_b_k(uint8_t *data);
char setdatabyte(uint8_t *data);
char setaddress(uint16_t *address);
char setsegment(uint16_t *segment);

bool Ascii2Hex(char *c);
bool SerialGetAsciiuint8_t(uint8_t *data);
bool SerialGetAsciiWord(uint16_t *addr);

#endif /* UTILS_H_ */
