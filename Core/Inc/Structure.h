/*
Author: Collin Crooy, Job Calis
Date: 16-11-2026

(c) Collin Crooy & Job Calis (All rights reserved)
Opdracht: SOFTON
-- Uitlijning data structuur tussen lagen
*/


#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#define ARRAYLENGTH 50
#define UNDEFINED 999

#define LINE 1 
#define RECTANGLE 2
#define TEXT 3
#define BITMAP 4
#define CLEARSCREEN 5
#define WAIT 6 
#define REPEAT 7
#define CIRCLE 8
#define FIGURE 9
//#define 10 //Eigen Functie toevoegen

typedef struct package
{
    int func;

    // Locatie op het scherm 
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;

    int y0;
    int y1;
    int y2;
    int y3;
    int y4;

    // Vormen
    int kleur;
    int dikte;
    int breedte;
    int hoogte;
    int gevuld;
    int Radius;
    
    //Tekst
    char* tekst;
    char* fontNaam;
    int fontStyle;
    int fontSize;
    struct package* pStructBegin;

    //Overig (E.g. bitmap; wacht)
    int bitNmr;
    int time;
    int aantal;
    int herhalingen;

    int READY; //state front-end
} PACKAGE;

extern PACKAGE Backlog[ARRAYLENGTH];

#endif /* __STRUCTURE_H__ */