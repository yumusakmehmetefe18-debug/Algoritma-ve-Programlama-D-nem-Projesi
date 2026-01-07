#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265
#endif

const char *Gezegen_isimleri[] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};
const int Gezegen_sayisi = 8;

void Menuyu_Goster();
void Serbest_Dusme(double *g_dizisi, int *boyut);
void Yukari_Atis(double *g_dizisi, int *boyut);
void Agirlik_Hesapla(double *g_dizisi, int *boyut);
void Potansiyel_Enerji(double *g_dizisi, int *boyut);
void Hidrostatik_Basinc(double *g_dizisi, int *boyut);
void Arsimet_Kaldirma(double *g_dizisi, int *boyut);
void Basit_Sarkac(double *g_dizisi, int *boyut);
void Ip_Gerilmesi(double *g_dizisi, int *boyut);
void Asansor_Deneyi(double *g_dizisi, int *boyut);

int main() {
    double yercekimi_ivmeleri[] = {3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};  //"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"
    int boyut = Gezegen_sayisi;
    char bilim_insani[51];
    int secim = 0;

    printf("--- UZAY SIMULASYONU ---\n");
    printf("Bilim Insanin Adi Soyadi: ");
    fgets(bilim_insani, 51, stdin);
    bilim_insani[strcspn(bilim_insani, "\n")] = 0;

    printf("\nHosgeldiniz, Sayin %s.\n", bilim_insani);

    while (1) {
        Menuyu_Goster();
        printf("\nSeciminiz (Cikis icin -1): ");
        scanf("%d", &secim);

        if (secim == -1) {
            printf("Simulasyon sonlandiriliyor. Iyi gunler Sayin %s.\n", bilim_insani);
            break;
        }

        switch (secim) {
            case 1: Serbest_Dusme(yercekimi_ivmeleri, &boyut); break;
            case 2: Yukari_Atis(yercekimi_ivmeleri, &boyut); break;
            case 3: Agirlik_Hesapla(yercekimi_ivmeleri, &boyut); break;
            case 4: Potansiyel_Enerji(yercekimi_ivmeleri, &boyut); break;
            case 5: Hidrostatik_Basinc(yercekimi_ivmeleri, &boyut); break;
            case 6: Arsimet_Kaldirma(yercekimi_ivmeleri, &boyut); break;
            case 7: Basit_Sarkac(yercekimi_ivmeleri, &boyut); break;
            case 8: Ip_Gerilmesi(yercekimi_ivmeleri, &boyut); break;
            case 9: Asansor_Deneyi(yercekimi_ivmeleri, &boyut); break;
            default: printf("Gecersiz secim! Lutfen tekrar deneyin.\n"); break;
        }
        printf("\n--------------------------------------------------\n");
    }

    return 0;
}

void Menuyu_Goster() {
    printf("\n--- DENEY LISTESI ---\n");
    printf("1. Serbest Dusme Deneyi\n");
    printf("2. Yukari Atis Deneyi\n");
    printf("3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basinc Deneyi\n");
    printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Periyodu Deneyi\n");
    printf("8. Sabit Ip Gerilmesi Deneyi\n");
    printf("9. Asansor Deneyi\n");
}

void Serbest_Dusme(double *g_dizisi, int *boyut) {
    double t, h;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Sureyi giriniz (saniye): ");
    scanf("%lf", &t);

    t = (t < 0) ? -t : t;
    printf("Isleme alinan sure (mutlak deger): %.2f s\n\n", t);

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        h = 0.5 * g * t * t;
        printf("%-8s icin dusulen mesafe (h): %.2f m\n", *(Gezegen_isimleri + i), h);
    }
}

void Yukari_Atis(double *g_dizisi, int *boyut) {
    double v0, h_max;
    printf("\n--- Yukari Atis Deneyi ---\n");
    printf("Firlatma hizini giriniz (m/s): ");
    scanf("%lf", &v0);

    v0 = (v0 < 0) ? -v0 : v0;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        h_max = (v0 * v0) / (2 * g);
        printf("%-8s icin Maks. Yukseklik (h_max): %.2f m\n", *(Gezegen_isimleri + i), h_max);
    }
}

void Agirlik_Hesapla(double *g_dizisi, int *boyut) {
    double m, G;
    printf("\n--- Agirlik Deneyi ---\n");
    printf("Kutleyi giriniz (kg): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        G = m * g;
        printf("%-8s icin Agirlik (G): %.2f N\n", *(Gezegen_isimleri + i), G);
    }
}

void Potansiyel_Enerji(double *g_dizisi, int *boyut) {
    double m, h, Ep;
    printf("\n--- Kutlecekimsel Potansiyel Enerji Deneyi ---\n");
    printf("Kutleyi giriniz (kg): ");
    scanf("%lf", &m);
    printf("Yuksekligi giriniz (m): ");
    scanf("%lf", &h);

    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        Ep = m * g * h;
        printf("%-8s icin Potansiyel Enerji (Ep): %.2f J\n", *(Gezegen_isimleri + i), Ep);
    }
}

void Hidrostatik_Basinc(double *g_dizisi, int *boyut) {
    double rho, h, P;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    printf("Sivinin yogunlugunu giriniz (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Derinligi giriniz (m): ");
    scanf("%lf", &h);

    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        P = rho * g * h;
        printf("%-8s icin Hidrostatik Basinc (P): %.2f Pa\n", *(Gezegen_isimleri + i), P);
    }
}

void Arsimet_Kaldirma(double *g_dizisi, int *boyut) {
    double rho, V, Fk;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivinin yogunlugunu giriniz (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Batan hacmi giriniz (m^3): ");
    scanf("%lf", &V);

    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        Fk = rho * g * V;
        printf("%-8s icin Kaldirma Kuvveti (Fk): %.2f N\n", *(Gezegen_isimleri + i), Fk);
    }
}

void Basit_Sarkac(double *g_dizisi, int *boyut) {
    double L, T;
    printf("\n--- Basit Sarkac Periyodu Deneyi ---\n");
    printf("Sarkac uzunlugunu giriniz (m): ");
    scanf("%lf", &L);

    L = (L < 0) ? -L : L;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        T = 2 * M_PI * sqrt(L / g);
        printf("%-8s icin Periyot (T): %.2f s\n", *(Gezegen_isimleri + i), T);
    }
}

void Ip_Gerilmesi(double *g_dizisi, int *boyut) {
    double m, T;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("Kutleyi giriniz (kg): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);
        T = m * g;
        printf("%-8s icin Ip Gerilmesi (T): %.2f N\n", *(Gezegen_isimleri + i), T);
    }
}

void Asansor_Deneyi(double *g_dizisi, int *boyut) {
    double m, a, N;
    int durum;
    printf("\n--- Asansor Deneyi ---\n");
    printf("Kutleyi giriniz (kg): ");
    scanf("%lf", &m);
    printf("Asansor ivmesini giriniz (m/s^2): ");
    scanf("%lf", &a);

    printf("Durum Seciniz:\n");
    printf("1. Yukari Hizlanan veya Asagi Yavaslayan (g + a)\n");
    printf("2. Asagi Hizlanan veya Yukari Yavaslayan (g - a)\n");
    printf("Secim: ");
    scanf("%d", &durum);

    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    int i;
    for (i = 0; i < *boyut; i++) {
        double g = *(g_dizisi + i);

        if (durum == 1) {
             N = m * (g + a);
        } else {
             N = m * (g - a);

             if (N < 0) N = 0;
        }

        printf("%-8s icin Etkin Agirlik (N): %.2f N\n", *(Gezegen_isimleri + i), N);
    }
}
