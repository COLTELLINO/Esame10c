#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Funzione per inserire un punto di interesse in coda alla lista
void inserisciPunto(PuntoInteresse** testa, float latitudine, float longitudine, char* descrizione) {
    PuntoInteresse* nuovoPunto = (PuntoInteresse*)malloc(sizeof(PuntoInteresse));
    if (nuovoPunto == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria\n");
        return;
    }

    nuovoPunto->latitudine = latitudine;
    nuovoPunto->longitudine = longitudine;
    strcpy(nuovoPunto->descrizione, descrizione);
    nuovoPunto->next = NULL;

    if (*testa == NULL) {
        *testa = nuovoPunto;
    }
    else {
        PuntoInteresse* temp = *testa;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuovoPunto;
    }
}

// Funzione per rimuovere un punto di interesse dalla lista
void rimuoviPunto(PuntoInteresse** testa, char* descrizione) {
    PuntoInteresse* temp = *testa, * prev = NULL;
    while (temp != NULL && strcmp(temp->descrizione, descrizione) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) {
        *testa = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
}

// Funzione per cercare un punto di interesse nella lista
void cercaPunto(PuntoInteresse* testa, char* descrizione) {
    PuntoInteresse* temp = testa;
    while (temp != NULL) {
        if (strcmp(temp->descrizione, descrizione) == 0) {
            printf("Punto trovato: %f, %f\n", temp->latitudine, temp->longitudine);
            return;
        }
        temp = temp->next;
    }
    printf("Punto non trovato.\n");
}

// Funzione per stampare tutti i punti di interesse nella lista
void stampaLista(PuntoInteresse* testa) {
    PuntoInteresse* temp = testa;
    while (temp != NULL) {
        printf("Descrizione: %s, Latitudine: %f, Longitudine: %f\n", temp->descrizione, temp->latitudine, temp->longitudine);
        temp = temp->next;
    }
}
