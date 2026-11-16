/*
Author: Job Calis
Date: 16-11-2026

(c) Job Calis (All rights reserved)
Opdracht: SOFTON
-- Overdracht data tot functies
*/

#include "Middle.h"
#include "Back.h"
#include "Structure.h"

//automatisch teogevoegd door VS code:
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <sys/_intsup.h>
#include <stdarg.h>


int getPackage(PACKAGE* pdata)
{
    int errorMessage = 0;

    switch (pdata->func) 
    {
    case LINE:
        //check for valid input
        if(checkUndefined(6, pdata->x0, pdata->y0, pdata->x1, pdata->y1, pdata->kleur, pdata->dikte)) return 1;
        //call API (Back-end)
        /*errorMessage = */API_draw_line(pdata->x0, pdata->y0, pdata->x1, pdata->y1, pdata->kleur, pdata->dikte, 0);
        break;

    case RECTANGLE:
        //check for valid input
        if(checkUndefined(6, pdata->x0, pdata->y0, pdata->breedte, pdata->hoogte, pdata->kleur, pdata->gevuld)) return 1;
        //call API (Back-end)
        errorMessage = API_draw_rectangle(pdata->x0, pdata->y0, pdata->breedte, pdata->hoogte, pdata->kleur, pdata->gevuld, 0, 0);
        break;

    case TEXT:
        //check for valid input
        if(checkUndefined(6, pdata->x0, pdata->y0, pdata->kleur, pdata->y1, pdata->fontSize, pdata->fontStyle)) return 1;
        //call API (Back-end)
        errorMessage = API_draw_text(pdata->x0, pdata->y0, pdata->kleur, pdata->tekst, pdata->fontNaam, pdata->fontSize, pdata->fontStyle, 0);
        break;

    case BITMAP:
        //check for valid input
        if(checkUndefined(3, pdata->x0, pdata->y0, pdata->bitNmr)) return 1;
        //call API (Back-end)
        errorMessage = API_draw_bitmap(pdata->x0, pdata->y0, pdata->bitNmr); 
        break;

    case CLEARSCREEN:
        //check for valid input
        if(checkUndefined(1, pdata->kleur)) return 1;
        //call API (Back-end)
        errorMessage = API_clearscreen(pdata->kleur);
        break;

    case WAIT:
        //check for valid input
        if(checkUndefined(1, pdata->time)) return 1;
        //wacht voor "time" miliseconde
        HAL_Delay(pdata->time);
        break;

    case REPEAT:
        //check for valid input
        if(checkUndefined(2, pdata->aantal, pdata->herhalingen)) return 1;
        //call API (Back-end)
        errorMessage = API_repeat_commands(pdata->aantal, pdata->herhalingen, 0); //TODO: huidige struct moet nog verwerkt
        break;

    case CIRCLE:
        //check for valid input
        if(checkUndefined(4, pdata->x0, pdata->y0, pdata->Radius, pdata->kleur)) return 1;
        //call API (Back-end)
        errorMessage = API_draw_circle(pdata->x0, pdata->y0, pdata->Radius, pdata->kleur, 0);
        break;

    case FIGURE:
        //check for valid input
        if(checkUndefined(6, pdata->x0, pdata->y0, pdata->x1, pdata->y2, pdata->x3, pdata->y3, pdata->x4, pdata->y4, pdata->kleur)) return 1;
        //call API (Back-end)
        errorMessage = API_draw_figure(pdata->x0, pdata->y0, pdata->x1, pdata->y1, pdata->x2, pdata->y2, pdata->x3, pdata->y3, pdata->x4, pdata->y4, pdata->kleur, 0);
        break;
        
    default:
        return 1;
    }

    if(errorMessage) return errorMessage;

    return 0;//goed
}



//black magic, hoeveelheid argumenten is variabel. documentatie voor ARGS is hier: https://www.geeksforgeeks.org/c/variadic-functions-in-c/
int checkUndefined(int a, ...)
{
    va_list args;
    va_start(args, a);

    for(int i = 0; i < a; i++)
    {
        if(va_arg(args, int) == UNDEFINED) return 1;
    }

    return 0;
    va_end(args);
}

