#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>

/* 
Author: Alex R Bucknall
About: CHIP 8 Emulator written in C 
Credit: Inspired by https://github.com/arnsa/Chip-8-Emulator/blob/master/chip8.c
Date: 27/01/2018

Chip 8 Architecture
- 16 general purpose 8-bit registers, Vx, where x is a hex digit (0-F). 
- 16-bit register called I used to store memory addresses, typically only use (rightmost) 12 bits.
- Register VF is used as a flag by programs (DO NOT USE)
- Two special registers for delay and sound timers. When non-zero they decrement at 60 Hz.
- Pseudo-registers, PC (16-Bit Program Counter) and SP (8-Bit Stack Pointer).
- The stack is an array of 16, 16-Bit values that store the address of the return value for when the interpreter finishes a subroutine.
- Chip 8 allows for 16 levels of nested subroutines. 
*/

#undef main
 
#define memsize 4096
#define SCREEN_W 640
#define SCREEN_H 320
#define SCREEN_BPP 32
#define W 64
#define H 32
 
unsigned char chip8_fontset[80] =
{
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};
 
static int keymap[0x10] = {
    SDLK_0,
    SDLK_1,
    SDLK_2,
    SDLK_3,
    SDLK_4,
    SDLK_5,
    SDLK_6,
    SDLK_7,
    SDLK_8,
    SDLK_9,
    SDLK_a,
    SDLK_b,
    SDLK_c,
    SDLK_d,
    SDLK_e,
    SDLK_f
};

typedef struct chip8{
    FILE * game; // loads the game commands into struct
    unsigned short opcode; // current operator code
    unsigned char memory[memsize];
    unsigned char V[0x10];
    unsigned short I;
    unsigned short PC;
    unsigned short SP;
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short stack[0x10];
    unsigned char graphics[64 * 32];
    unsigned char keyboard[0x10];
} C8;

//0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
//0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
//0x200-0xFFF - Program ROM and work RAM

void main(){
    int x = 1;
    printf("press enter");
};