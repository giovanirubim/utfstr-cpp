#ifndef UTFSTR_CPP
#define UTFSTR_CPP

#include "utfstr.hpp"

unsigned char utfstr::state_map[7][256] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
	,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0},{0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
	,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
	,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
	,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	,0,0,0,0,0,0,0,0,0,0,0,0}
};

// AUTOMATON DESCRIPTION
// state 0: finished / error
// state 1: expects any char except for body char and end of string
// state 2: expects one more body char
// state 3: expects two more body chars
// state 4: just read a two byte header
// state 5: just read a three byte header
// state 6: just read a four byte header
// void fill_map() {
// 	for (int i=0; i<256; ++i) {
// 		if (i && i < 128) { // ASCII char
// 			state_map[1][i] = 1;
// 		}
// 		if ((i & 0b11100000) == 0b11000000) { // 2-byte header
// 			state_map[1][i] = 4;
// 		}
// 		if ((i & 0b11110000) == 0b11100000) { // 3-byte header
// 			state_map[1][i] = 5;
// 		}
// 		if ((i & 0b11111000) == 0b11110000) { // 4-byte header
// 			state_map[1][i] = 6;
// 		}
// 		if ((i & 0b11000000) == 0b10000000) { // body byte
// 			state_map[2][i] = 1;
// 			state_map[3][i] = 2;
// 			state_map[4][i] = 1;
// 			state_map[5][i] = 2;
// 			state_map[6][i] = 3;
// 		}
// 	}
// }

long long unsigned utfstr::length(const char* src) {
	long int length = 0;
	unsigned char byte, state = 1, last;
	for (;;) {
		byte = *src++;
		last = state;
		state = state_map[state][byte];
		if (!state) break;
		if (state == 1) ++ length;
	}
	return (src[-1] || last != 1)? -1: length;
}

long long unsigned utfstr::length(const char16_t* src) {
	if (sizeof(char16_t) == sizeof(wchar_t)) {
		return wcslen((const wchar_t*) src);
	}
	const char16_t* ptr = src;
	while (*ptr) {
		++ptr;
	}
	return ptr - src;
}

char16_t* utfstr::copy(char16_t* dst, const char* src) {
	char16_t* ptr = dst;
	unsigned char byte, state = 1, last;
	unsigned long int buffer;
	for (;;) {
		byte = *src++;
		last = state;
		state = state_map[state][byte];
		if (!state) break;
		switch (state) {
			case 1:
				if (last == 1) {
					*ptr++ = byte;
				} else {
					buffer <<= 6;
					buffer |= byte & 0b00111111;
					*ptr++ = buffer;
				}
			break;
			case 2:
			case 3:
				buffer <<= 6;
				buffer |= byte & 0b00111111;
			break;
			case 4:
				buffer = byte & 0b00011111;
			break;
			case 5:
				buffer = byte & 0b00001111;
			break;
			case 6:
				buffer = byte & 0b00000111;
			break;
		}
	}
	*ptr++ = 0;
	if (src[-1] || last != 1) {
		*dst = 0;
		return nullptr;
	}
	return dst;
}

char* utfstr::copy(char* dst, const char16_t* src) {
	char* ptr = dst;
	unsigned short chr;
	while ((chr = *src++)) {
		if (chr < (1 << 7)) {
			*ptr++ = chr;
			continue;
		}
		if (chr < (1 << 11)) {
			ptr[1] = 0b10000000 | chr & 0b00111111;
			ptr[0] = 0b11000000 | (chr >> 6) & 0b00011111;
			ptr += 2;
			continue;
		}
		ptr[2] = 0b10000000 | chr & 0b00111111;
		ptr[1] = 0b10000000 | (chr >> 6) & 0b00111111;
		ptr[0] = 0b11100000 | (chr >> 12) & 0b00001111;
		ptr += 3;
	}
	*ptr = 0;
	return dst;
}

char16_t* utfstr::copy(char16_t* dst, const wchar_t* src) {
	if (sizeof(char16_t) == sizeof(wchar_t)) {
		wcscpy((wchar_t*)dst, src);
		return dst;
	}
	char16_t* ptr = dst;
	while (*src) *ptr++ = (char16_t) *src++;
	*ptr = '\0';
	return dst;
}

wchar_t* utfstr::copy(wchar_t* dst, const char16_t* src) {
	if (sizeof(char16_t) == sizeof(wchar_t)) {
		wcscpy(dst, (const wchar_t*)src);
		return dst;
	}
	wchar_t* ptr = dst;
	while (*src) *ptr++ = (wchar_t) *src++;
	*ptr = '\0';
	return dst;
}

bool utfstr::copy(std::u16string &dst, const char* src) {
	dst = std::u16string();
	unsigned char byte, state = 1, last;
	unsigned long int buffer;
	for (;;) {
		byte = *src++;
		last = state;
		state = state_map[state][byte];
		if (!state) break;
		switch (state) {
			case 1:
				if (last == 1) {
					dst += (char16_t) byte;
				} else {
					buffer <<= 6;
					buffer |= byte & 0b00111111;
					dst += (char16_t) buffer;
				}
			break;
			case 2:
			case 3:
				buffer <<= 6;
				buffer |= byte & 0b00111111;
			break;
			case 4:
				buffer = byte & 0b00011111;
			break;
			case 5:
				buffer = byte & 0b00001111;
			break;
			case 6:
				buffer = byte & 0b00000111;
			break;
		}
	}
	if (src[-1] || last != 1) {
		dst = std::u16string();
		return false;
	}
	return true;
}

void utfstr::print(const char16_t* src) {
	if (sizeof(char16_t) == sizeof(wchar_t)) {
		printf("%ls", (const wchar_t*) src);
		return;
	}
	while (*src) {
		printf("%lc", (wchar_t) *src++);
	}
}

void utfstr::puts(const char16_t* src) {
	if (sizeof(char16_t) == sizeof(wchar_t)) {
		printf("%ls\n", (const wchar_t*) src);
		return;
	}
	while (*src) {
		printf("%lc", (wchar_t) *src++);
	}
	putchar('\n');
}

void utfstr::print(FILE* file, const char16_t* src) {
	if (sizeof(char16_t) == sizeof(wchar_t)) {
		fprintf(file, "%ls", (const wchar_t*) src);
		return;
	}
	while (*src) {
		fprintf(file, "%lc", (wchar_t) *src++);
	}
}

void utfstr::puts(FILE* file, const char16_t* src) {
	if (sizeof(char16_t) == sizeof(wchar_t)) {
		fprintf(file, "%ls\n", (const wchar_t*) src);
		return;
	}
	while (*src) {
		fprintf(file, "%lc", (wchar_t) *src++);
	}
	fputc('\n', file);
}

#endif