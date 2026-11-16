#include "main.h"
#include "stm32_ub_vga_screen.h"
#include "math.h"
#include <stdlib.h>

// Functie voor het invoegen van teskt
int API_draw_text(int x_lup, int y_lup, int color, char *text, char *fontname, int fontsize, int fontstyle, int reserved)
{

}

void API_draw_line(int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
    float y_float = y_1;
    float x_float = x_1;
    int xp, yp;

    if (abs(y_2-y_1) < abs(x_2-x_1))
    {
        float rc = 1.0f*(y_2-y_1)/(x_2-x_1);
        for(xp=x_1; xp<=x_2; xp++)
        {
            yp = round(y_float);
            UB_VGA_SetPixel(xp, yp, color);
            y_float = (y_float + rc);
        }
    }
    else
    {
        
        float rc = 1.0f*(x_2-x_1)/(y_2-y_1);
        for(yp=y_1; yp<=y_2; yp++)
        {
            xp = round(x_float);
            UB_VGA_SetPixel(xp, yp, color);
            x_float = (x_float + rc);
        }
    }

}

int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved, int reserved1)
{

}

int API_draw_bitmap(int x_lup, int y_lup, int bm_nr)
{

}

int API_clearscreen(int color)
{
    UB_VGA_FillScreen(color);
}