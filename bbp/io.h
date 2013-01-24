/**
* @file io.h
* Helper functions for legacy IO operations
*/
#ifndef __io_h
#define __io_h

#include "common.h"

/**
* Write a byte out to the specified port.
* @param port - IO port number
* @param value - byte value
* @return void
*/
void __INLINE outb(uint16 port, uint8 value){
	asm volatile ("outb %1, %0" : : "dN"(port), "a"(value));
}
/**
* Write a word out to the specified port.
* @param port - IO port number
* @param value - word value
* @return void
*/
void __INLINE outw(uint16 port, uint16 value){
	asm volatile ("outw %1, %0" : : "dN"(port), "a"(value));
}
/**
* Read a byte from specified port.
* @param port - IO port number
* @return byte value
*/
uint8 __INLINE inb(uint16 port){
	uint8 ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
	return ret;
}
/**
* Read a word from specified port.
* @param port - IO port number
* @return word value
*/
uint16 __INLINE inw(uint16 port){
	uint16 ret;
	asm volatile("inw %1, %0" : "=a"(ret) : "dN"(port));
	return ret;
}

#endif
