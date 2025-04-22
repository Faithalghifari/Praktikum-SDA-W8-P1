#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orang.h"

void tambahOrang(orang** kepala, char nama[]) {
    orang* baru = (orang*) malloc(sizeof(orang));
    strcpy(baru->nama, nama);
    baru->lanjut = NULL;
    if (*kepala == NULL) {
        *kepala = baru;
    } else {
        orang* tmp = *kepala;
        while (tmp->lanjut != NULL) tmp = tmp->lanjut;
        tmp->lanjut = baru;
    }
}

void hapusSemuaOrang(orang** kepala) {
    orang* tmp = *kepala;
    while (tmp != NULL) {
        orang* hps = tmp;
        tmp = tmp->lanjut;
        free(hps);
    }
    *kepala = NULL;
}

void tampilOrang(orang* kepala) {
    orang* tmp = kepala;
    while (tmp != NULL) {
        printf("  - %s\n", tmp->nama);
        tmp = tmp->lanjut;
    }
}