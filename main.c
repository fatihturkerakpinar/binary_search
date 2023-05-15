#include <stdio.h>

int insortion_sort(int dizi[], int boyut) {
    for (int i = 1; i < boyut; i++) {
        int anahtar = dizi[i];
        int j = i - 1;
        while (j >= 0 && dizi[j] > anahtar) {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = anahtar;
    }
    //insortion sort ile once diziyi artan sirali bir diziye cevirdim
}

int indeks_bul(int dizi[], int boyut, int aranan) {
    int alt_sinir = 0;
    int ust_sinir = boyut - 1;
    while (alt_sinir <= ust_sinir) {
        int orta = alt_sinir + (ust_sinir - alt_sinir) / 2;

        if (dizi[orta] == aranan) {
            return orta;
        }

        if (dizi[orta] < aranan) {
            alt_sinir = orta + 1;
        } else {
            ust_sinir = orta - 1;
        }
      //sirali olan dizinin indeksini buldum  
    }

    return -1;
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);
    int aranan;

    // Diziyi insortion sort ile siraladim
   insortion_sort(dizi, boyut);

    printf("Aranacak elemani giriniz: ");
    scanf("%d", &aranan);
	//bulunmasi istenen elemani kullanicidan istedim
    int indeks = indeks_bul(dizi, boyut, aranan);

    if (indeks != -1) {
        printf("Dizideki sirasi: %d\n", indeks+1);
        //dizilerde indexler 0 dan basladigi icin normal siralamada sayma sayilarini kullanip indexe 1 ekleyip ekrana yazdirdim
    } else {
        printf("Aranilan eleman dizide bulunamadi.\n");
    }

    return 0;
}

