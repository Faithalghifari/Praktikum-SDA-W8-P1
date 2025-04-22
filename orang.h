#ifndef ORANG_H
#define ORANG_H

typedef struct orang {
    char nama[50];
    struct orang* lanjut;
} orang;

void tambahOrang(orang** kepala, char nama[]);
void hapusSemuaOrang(orang** kepala);
void tampilOrang(orang* kepala);

#endif