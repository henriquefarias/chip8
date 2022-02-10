/*  This is a simple chip-8 emulador built for learning purposes.
    Most references used while writing this software were taken from the excellent "Cowgod's Chip-8 Technical Reference v1.0", which can be found at:

    http://devernay.free.fr/hacks/chip8/C8TECH10.HTM */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Boolean types to help make code more readable. */
#define TRUE (!NULL)
#define FALSE NULL

#define SCREEN_W 64
#define SCREEN_H 32

#define MEM_SIZE 4096
#define REG_SIZE 16

/* =============== GLOBAL VARIABLES =============== */

/* Main memory. The chip-8 has 4096 bytes of RAM. The first 512 bytes are reserved for the interpreter, so chip-8 programs usually start at byte 512 (0x200). */
unsigned char MEM[MEM_SIZE];

/* General purpose registers. The chip-8 has 16 of those, each capable of storing 1 byte. */
unsigned char REG[REG_SIZE];

/*  The original chip-8 display is 64 pixels wide by 32 pixels tall. Subsequent versions had different resolutions.
    Coordinates go from top left (0,0) to bottom right (31,63).
    Since the chip-8 display is monocromatic, it's possible to use a simple matrix of on/off values to store the state of each pixel. */
unsigned char SCREEN_BUFFER[SCREEN_H][SCREEN_W];

/* =============== FUNCTION PROTOTYPES =============== */

void clear_screen(void);
void draw_screen(void);

/* =============== HELPER FUNCTIONS =============== */

/* Render the screen buffer to the console. */
void draw_screen(void)
{
    int line, column;

    system("mode con: cols=65 lines=32");

    for (line = 0; line < SCREEN_H; line++)
    {
        for (column = 0; column < SCREEN_W; column++)
        {
            if (SCREEN_BUFFER[line][column] == TRUE)
                printf("*");

            else
                printf(" ");
        }

        /* Prevents printing an extra line at the bottom.  */
        if (line != SCREEN_H - 1)
            printf("\n");
    }
}

/* =============== CHIP-8 INSTRUCTIONS =============== */

/* Clear screen. This is mapped to opcode 00E0 - CLS. */
void clear_screen(void)
{
    int line, column;

    for (line = 0; line < SCREEN_H; line++)
    {
        for (column = 0; column < SCREEN_W; column++)
            SCREEN_BUFFER[line][column] = 0;
    }

    draw_screen();
}
