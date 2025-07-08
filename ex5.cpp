/*Problem: Queue kullanarak Banka Kuyruğu Oluşturmak

Problemin Tanımı: 1. Bir bankaya sabahleyin gelmiş olan N kişinin, geliş sıralarına göre kuyruk oluşturduklarını varsayın. Her birinin işleminin 30 saniye ile 300 sn. arasında random bir zaman aldığını varsayın. Her bir banka müşterisine numara vererek ve her birine random birer işlem süresi atayarak N elemanlı bir kuyruk oluşturunuz. Her bir müşterinin işi biterek kuyruktan çıkarıldığında işlem tamamlanma süresini (işlem süresi dâhil ne kadar süre kuyrukta kaldığını) liste halinde yazdırınız. Ayrıca, N adet müşteri için ortalama işlem tamamlanma süresini de hesaplayıp yazdırınız. 
2. Aynı işlemi aynı değerleri kullanarak HEAP-öncelikli kuyruk için tekrarlayınız. Kuyruğu, işlem süresi en kısa olan müşteri ilk (öncelikli) olarak hizmet alacak şekilde tasarlayınız (kuyruk, elemanları küçükten büyüğe sıralı tutacak). Her bir müşteri, işi biterek kuyruktan çıkarıldığında işlem tamamlanma süresini liste halinde yazdırınız. Ayrıca, N müşteri için ortalama işlem tamamlanma süresini de hesaplayıp yazdırınız. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAKS_MUSTERI 1000
#define MIN_SURE 30
#define MAKS_SURE 300


typedef struct {
   int no;
   int islem_suresi;
} Musteri;


typedef struct {
   Musteri kuyruk[MAKS_MUSTERI];
   int bas, son;
} SiraliKuyruk;


void kuyruk_baslat(SiraliKuyruk *k) {
   k->bas = k->son = 0;
}


void kuyruga_ekle(SiraliKuyruk *k, Musteri m) {
   k->kuyruk[k->son++] = m;
}


Musteri kuyruktan_cikar(SiraliKuyruk *k) {
   return k->kuyruk[k->bas++];
}


int kuyruk_bosmu(SiraliKuyruk *k) {
   return k->bas == k->son;
}


typedef struct {
   Musteri dizi[MAKS_MUSTERI];
   int boyut;
} OncelikKuyrugu;


void oncelik_baslat(OncelikKuyrugu *o) {
   o->boyut = 0;
}


void yer_degistir(Musteri *a, Musteri *b) {
   Musteri gecici = *a;
   *a = *b;
   *b = gecici;
}


void yukari_duzenle(OncelikKuyrugu *o, int i) {
   if (i == 0) return;
   int ebeveyn = (i - 1) / 2;
   if (o->dizi[i].islem_suresi < o->dizi[ebeveyn].islem_suresi) {
       yer_degistir(&o->dizi[i], &o->dizi[ebeveyn]);
       yukari_duzenle(o, ebeveyn);
   }
}


void asagi_duzenle(OncelikKuyrugu *o, int i) {
   int kucuk = i;
   int sol = 2 * i + 1;
   int sag = 2 * i + 2;


   if (sol < o->boyut && o->dizi[sol].islem_suresi < o->dizi[kucuk].islem_suresi)
       kucuk = sol;
   if (sag < o->boyut && o->dizi[sag].islem_suresi < o->dizi[kucuk].islem_suresi)
       kucuk = sag;


   if (kucuk != i) {
       yer_degistir(&o->dizi[i], &o->dizi[kucuk]);
       asagi_duzenle(o, kucuk);
   }
}


void oncelik_ekle(OncelikKuyrugu *o, Musteri m) {
   o->dizi[o->boyut] = m;
   yukari_duzenle(o, o->boyut);
   o->boyut++;
}


Musteri oncelikli_al(OncelikKuyrugu *o) {
   Musteri min = o->dizi[0];
   o->dizi[0] = o->dizi[--o->boyut];
   asagi_duzenle(o, 0);
   return min;
}


int oncelik_bosmu(OncelikKuyrugu *o) {
   return o->boyut == 0;
}


void benzetim(int adet) {
   Musteri musteriler[MAKS_MUSTERI];
   SiraliKuyruk sira;
   OncelikKuyrugu oncelik;
   int i;


   srand(time(NULL));


   for (i = 0; i < adet; i++) {
       musteriler[i].no = i + 1;
       musteriler[i].islem_suresi = (rand() % (MAKS_SURE - MIN_SURE + 1)) + MIN_SURE;
   }


   kuyruk_baslat(&sira);
   for (i = 0; i < adet; i++) {
       kuyruga_ekle(&sira, musteriler[i]);
   }


   printf("\n>>> FIFO KUYRUK <<<\n");
   int gecen_sure = 0;
   int toplam_sure = 0;


   while (!kuyruk_bosmu(&sira)) {
       Musteri m = kuyruktan_cikar(&sira);
       gecen_sure += m.islem_suresi;
       toplam_sure += gecen_sure;
       printf("Musteri %d tamamlandi %d sn\n", m.no, gecen_sure);
   }


   printf("Ort Tamamlanma Suresi %.2f sn\n", (float)toplam_sure / adet);


   oncelik_baslat(&oncelik);
   for (i = 0; i < adet; i++) {
       oncelik_ekle(&oncelik, musteriler[i]);
   }


   printf("\n>>> ONCELIKLI KUYRUK <<<\n");
   gecen_sure = 0;
   toplam_sure = 0;


   while (!oncelik_bosmu(&oncelik)) {
       Musteri m = oncelikli_al(&oncelik);
       gecen_sure += m.islem_suresi;
       toplam_sure += gecen_sure;
       printf("Musteri %d tamamlandi %d sn\n", m.no, gecen_sure);
   }


   printf(" Tamamlanma Suresi %.2f sn\n", (float)toplam_sure / adet);
}


int main() {
   int adet;
   printf("Musteri sayisi girin ");
   scanf("%d", &adet);


   if (adet <= 0 || adet > MAKS_MUSTERI) {
       printf("Hatali sayi girdiniz\n");
       return 1;
   }


   benzetim(adet);
   return 0;
}

