#ifndef BACK_H
#define BACK_H

// Tekst invoegen
int API_draw_text(int x_lup, int y_lup, int color, char *text, char *fontname, int fontsize, int fontstyle, int reserved);

// Lijn tekenen
void API_draw_line(int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved);

// Rechthoek tekenen
int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved, int reserved1);

// Bitmap tekenen
int API_draw_bitmap(int x_lup, int y_lup, int bm_nr);

// Scherm leegmaken
int API_clearscreen(int color);

// Wachten
int API_wait(int msecs);

// Commando's herhalen
int API_repeat_commands(int nr_previous_commands, int iterations, int reserved);

// Cirkel tekenen
int API_draw_circle(int x, int y, int radius, int color, int reserved);

// Figuur tekenen
int API_draw_figure(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4, int x_5, int y_5, int color, int reserved);

#endif 