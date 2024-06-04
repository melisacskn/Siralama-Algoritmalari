#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 500


void birlestirmeliSirala(int dizi[], int n) {
    int i, anahtar, j;
    for (i = 1; i < n; i++) {
        anahtar = dizi[i];
        j = i - 1;

        while (j >= 0 && dizi[j] > anahtar) {
            dizi[j + 1] = dizi[j];
            j = j - 1;
        }
        dizi[j + 1] = anahtar;
    }
}


void secmeliSirala(int dizi[], int n) {
    int i, j, min_indeks, temp;
    for (i = 0; i < n-1; i++) {
        min_indeks = i;
        for (j = i+1; j < n; j++)
            if (dizi[j] < dizi[min_indeks])
                min_indeks = j;

        temp = dizi[min_indeks];
        dizi[min_indeks] = dizi[i];
        dizi[i] = temp;
    }
}


void rastgeleDiziOlustur(int dizi[], int n) {
    for (int i = 0; i < n; i++) {
        dizi[i] = rand() % 1001; 
    }
}


void diziKopyala(int kaynak[], int hedef[], int n) {
    for (int i = 0; i < n; i++) {
        hedef[i] = kaynak[i];
    }
}


void diziYazdir(int dizi[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main() {
    int dizi[BOYUT];
    int dizi1[BOYUT], dizi2[BOYUT];
    clock_t baslangic, bitis;
    double gecen_sure;

    // Rastgele sayý üreticiyi baþlat
    srand(time(0));

    // Rastgele dizi oluþtur
    rastgeleDiziOlustur(dizi, BOYUT);


    diziKopyala(dizi, dizi1, BOYUT);
    diziKopyala(dizi, dizi2, BOYUT);


    baslangic = clock();
    birlestirmeliSirala(dizi1, BOYUT);
    bitis = clock();
    gecen_sure = ((double) (bitis - baslangic)) / CLOCKS_PER_SEC;
    printf("Birlestirmeli Siralama suresi: %f saniye\n", gecen_sure);


    printf("Birlestirmeli Siralama sonrasi dizi: ");
    diziYazdir(dizi1, BOYUT);


    baslangic = clock();
    secmeliSirala(dizi2, BOYUT);
    bitis = clock();
    gecen_sure = ((double) (bitis - baslangic)) / CLOCKS_PER_SEC;
    printf("Secmeli Siralama suresi: %f saniye\n", gecen_sure);


    printf("Secmeli Siralama sonrasi dizi: ");
    diziYazdir(dizi2, BOYUT);

    return 0;
}
