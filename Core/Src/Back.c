#include "main.h"
#include "stm32_ub_vga_screen.h"

API_clearscreen(VGA_COL_CYAN)


// Functie voor het invoegen van teskt
int API_draw_text(int x_lup, int y_lup, int color, char *text, char *fontname, int fontsize, int fontstyle, int reserved)
{

}

int API_draw_line(int x_1, int y_1, int x_2, y_2, int color, int weight, int reserved)
{
    rc = (y_2-y_1/x_2-x_1)
    
}

int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved, int reserved)
{

}

int API_draw_bitmap(int x_lup, int y_lup, int bm_nr)
{

}

int API_clearscreen(int color)
{
    UB_VGA_FillScreen(uint8_t color)
}