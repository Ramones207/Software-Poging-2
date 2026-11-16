/*
Author: Collin Crooy, Job Calis
Date: 16-11-2026

(c) Collin Crooy & Job Calis (All rights reserved)
Opdracht: SOFTON
-- Uitlijning data structuur tussen lagen
*/


#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#define UNDEFINED 999

#define Line 1 
#define Rectangle 2
#define Text 3
#define BitMap 4
#define ClearScreen 5
#define Wait 6 
#define Repeat 7
#define Circle 8
#define Figure 9
//#define 10 //Eigen Functie toevoegen


struct package
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

    //Overig (E.g. bitmap; wacht)
    int bitNmr;
    int time;
    int aantal;
    int herhalingen;

    int READY; //state front-end
};

#endif /* __STRUCTURE_H__ */