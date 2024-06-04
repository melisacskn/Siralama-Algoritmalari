#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALFABE_BOYUTU 26


struct TrieDugum {
    struct TrieDugum *cocuklar[ALFABE_BOYUTU];
    bool kelimeSonu;
};

struct TrieDugum *yeniDugum(void) {
    struct TrieDugum *dugum = (struct TrieDugum *)malloc(sizeof(struct TrieDugum));
    dugum->kelimeSonu = false;

    for (int i = 0; i < ALFABE_BOYUTU; i++) {
        dugum->cocuklar[i] = NULL;
    }

    return dugum;
}


void ekle(struct TrieDugum *kok, const char *anahtar) {
    struct TrieDugum *dugum = kok;

    for (int seviye = 0; anahtar[seviye] != '\0'; seviye++) {
        int indeks = anahtar[seviye] - 'a';
        if (!dugum->cocuklar[indeks]) {
            dugum->cocuklar[indeks] = yeniDugum();
        }
        dugum = dugum->cocuklar[indeks];
    }

    dugum->kelimeSonu = true;
}


bool ara(struct TrieDugum *kok, const char *anahtar) {
    struct TrieDugum *dugum = kok;

    for (int seviye = 0; anahtar[seviye] != '\0'; seviye++) {
        int indeks = anahtar[seviye] - 'a';
        if (!dugum->cocuklar[indeks]) {
            return false;
        }
        dugum = dugum->cocuklar[indeks];
    }

    return (dugum != NULL && dugum->kelimeSonu);
}

int main() {

    char anahtarlar[][8] = {"ev", "elma", "ekmek", "araba", "anne", "okul", "oda", "otobus"};
    int n = sizeof(anahtarlar) / sizeof(anahtarlar[0]);

    struct TrieDugum *kok = yeniDugum();

    for (int i = 0; i < n; i++) {
        ekle(kok, anahtarlar[i]);
    }

    ara(kok, "ev") ? printf("ev ---> Var\n") : printf("ev ---> Yok\n");
    ara(kok, "araba") ? printf("araba ---> Var\n") : printf("araba ---> Yok\n");
    ara(kok, "okul") ? printf("okul ---> Var\n") : printf("okul ---> Yok\n");
    ara(kok, "ekmek") ? printf("ekmek ---> Var\n") : printf("ekmek ---> Yok\n");
    ara(kok, "otobus") ? printf("otobus ---> Var\n") : printf("otobus ---> Yok\n");

    return 0;
}
