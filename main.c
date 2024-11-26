#include <stdio.h>
#include "lib.h"
#include <string.h>
#include <stdlib.h>

int main() {
    PuntoInteresse* testa = NULL;
    inserisciPunto(&testa, 45.4641, 9.1919, "Duomo di Milano");
    inserisciPunto(&testa, 41.9028, 12.4964, "Colosseo");

    stampaLista(testa);

    printf("Cerca il Colosseo:\n");
    cercaPunto(testa, "Colosseo");

    printf("Rimuovi il Duomo di Milano:\n");
    rimuoviPunto(&testa, "Duomo di Milano");
    stampaLista(testa);

    return 0;
}
