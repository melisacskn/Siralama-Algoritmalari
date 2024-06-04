#include <stdio.h>
#include <stdlib.h>


void sirala(int dizi[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (dizi[j] > dizi[j+1]) {
                temp = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
            }
        }
    }
}


void alternatifSirala(int dizi[], int n) {
    int siraliDizi[n];
    int sol = 0;
    int sag = n - 1;
    int index = 0;

    // Diziyi sýraya koy
    sirala(dizi, n);

    // Alternatif sýralama
    while (sol <= sag) {
        if (index % 2 == 0) {
            siraliDizi[index] = dizi[sag];
            sag--;
        } else {
            siraliDizi[index] = dizi[sol];
            sol++;
        }
        index++;
    }

    for (int i = 0; i < n; i++) {
        dizi[i] = siraliDizi[i];
    }
}


void diziYazdir(int dizi[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main() {
    int dizi[] = {62, 31, 12, 95, 617, 132, 666, 777,};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    printf("Orjinal dizi: ");
    diziYazdir(dizi, boyut);

    alternatifSirala(dizi, boyut);

    printf("Alternatif siralanmis dizi: ");
    diziYazdir(dizi, boyut);

    return 0;
}
