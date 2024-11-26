#ifndef LIB_H
#define LIB_H

// Definizione della struttura PuntoInteresse
typedef struct PuntoInteresse {
    float latitudine;
    float longitudine;
    char descrizione[100];
    struct PuntoInteresse* next;
} PuntoInteresse;

// Dichiarazione delle funzioni che manipolano la lista di PuntiInteresse
void inserisciPunto(PuntoInteresse** testa, float latitudine, float longitudine, char* descrizione);
void rimuoviPunto(PuntoInteresse** testa, char* descrizione);
void cercaPunto(PuntoInteresse* testa, char* descrizione);
void stampaLista(PuntoInteresse* testa);


#endif
#pragma once
