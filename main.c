#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orang.h"

#define MAKS_KOTA 5

typedef struct {
    char kota[50];
    orang* isi;
} kota;

kota data[MAKS_KOTA];
int jml_kota = 0;

void masukinKota(char kt[]) {
    if (jml_kota >= MAKS_KOTA) {
        printf("kota udah penuh bro\n"); return;
    }
    strcpy(data[jml_kota].kota, kt);
    data[jml_kota].isi = NULL;
    jml_kota++;
}

int cariKota(char kt[]) {
    for (int i = 0; i < jml_kota; i++) {
        if (strcmp(data[i].kota, kt) == 0) return i;
    }
    return -1;
}

void masukinNama(char kt[], char nm[]) {
    int idx = cariKota(kt);
    if (idx == -1) {
        printf("kota ga ketemu\n"); return;
    }
    tambahOrang(&data[idx].isi, nm);
}

void hapusKota(char kt[]) {
    int idx = cariKota(kt);
    if (idx == -1) {
        printf("ga ada kota nya\n"); return;
    }
    hapusSemuaOrang(&data[idx].isi);
    for (int i = idx; i < jml_kota - 1; i++) {
        data[i] = data[i+1];
    }
    jml_kota--;
    printf("kota %s udah kehapus\n", kt);
}

void tampilSemua() {
    for (int i = 0; i < jml_kota; i++) {
        printf("Kota: %s\n", data[i].kota);
        tampilOrang(data[i].isi);
    }
}

void tampilKota(char kt[]) {
    int idx = cariKota(kt);
    if (idx == -1) {
        printf("ga ada kota nya\n"); return;
    }
    printf("Kota: %s\n", data[idx].kota);
    tampilOrang(data[idx].isi);
}

int main() {
    int pil;
    char kt[50], nm[50];
    do {
        printf("\n1. Tambah Kota\n2. Tambah Nama\n3. Hapus Kota\n4. Tampil Semua\n5. Tampil Kota\n6. Keluar\nPilih: ");
        scanf("%d", &pil); getchar();
        switch(pil) {
            case 1:
                printf("Nama Kota: "); gets(kt);
                masukinKota(kt); break;
            case 2:
                printf("Kota tujuan: "); gets(kt);
                printf("Nama orang: "); gets(nm);
                masukinNama(kt, nm); break;
            case 3:
                printf("Kota yg mau dihapus: "); gets(kt);
                hapusKota(kt); break;
            case 4:
                tampilSemua(); break;
            case 5:
                printf("Kota mana: "); gets(kt);
                tampilKota(kt); break;
        }
    } while(pil != 6);
    return 0;
}