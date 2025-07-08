/* Bağlı listelerle ilgili;
Arama, ekleme, silme ve ekrana yazdırma algoritmalarına ait fonksiyonları hazırlayınız ve main() fonksiyon tarafından çalışmalarını test ediniz.
Ders isimli özel tanımlı bir tip tanımlayınız. Ders tipi değişkenin Ad, Ders Kodu, Kredi, AKTS, Ders Hocasının Ad Soyad değişkenleri olmalı.  Ders Kodu her bir ders için farklı ve eşsiz-tekil (unique) bir numara olmalıdır.
main() fonksiyon; Arama, Ekleme, Listeleme ve Silme işlemlerinin tümünü yapabilmelidir.
Yukarıda yer alan işlemler için hazır kütüphane kullanmayınız. Main fonksiyonda hazırlanacak ders listesi yukarıda açıklanan tüm işlemler için main fonksiyonda kodladığınız program parçaları çağrılmalıdır. Test için main fonksiyonda her bir bağlı liste türü  için  en az 4 adet ders bilgisi tutulmalıdır.


Her bir bağlı liste türü  için: parametre olarak girilen indeks değerinden sonrasına eleman ekleme fonksiyonunu gerçekleştiriniz.
Her bir bağlı liste türü  için: parametre olarak girilen Ders Kodu değerinden sonrasına eleman ekleme fonksiyonunu gerçekleştiriniz.
Her bir bağlı liste türü  için: iki listeyi birleştirme işlemi yapan fonksiyonu hazırlayınız 
*/



#include <iostream>



using namespace std;


//struct tanımı
struct ders {
   string ad;
   int dersKodu;
   int akts;
   int kredi;
   string hocaAdSoyad;
   ders* next;
};


class DersListesi {
private:
   ders* head;


public:
   DersListesi() : head(nullptr) {}


   void dersEkle(const string ad, int dersKodu, int kredi, int akts, const string hocaAdSoyad) {
       ders* yeniDers = new ders{ad, dersKodu, kredi, akts, hocaAdSoyad, nullptr};
       if (!head) {
           head = yeniDers;
       } else {
           ders* temp = head;
           while (temp->next) {
               temp = temp->next;
           }
           temp->next = yeniDers;
       }
   }
   //dersSil fonk tanımı
   void dersSil(int dersKodu) {
       ders* temp = head;
       ders* onceki = nullptr;
       while (temp && temp->dersKodu != dersKodu) {
           onceki = temp;
           temp = temp->next;
       }
       if (!temp) {
           cout << "Ders bulunamadi\n";
           return;
       }
       if (!onceki) {
           head = temp->next;
       } else {
           onceki->next = temp->next;
       }
       delete temp;
   }
   //dersAra fonk tanımı
   void dersAra(int dersKodu) {
       ders* temp = head;
       while (temp) {
           if (temp->dersKodu == dersKodu) {
               cout << "Ders Bulundu: " << temp->ad << "\n";
               return;
           }
           temp = temp->next;
       }
       cout << "Ders bulunamadi\n";
   }
   //listele fonk tanımı
   void listele() {
       ders* temp = head;
       while (temp) {
           cout << "Ders Adi: " << temp->ad
                << ", Ders Kodu: " << temp->dersKodu
                << ", Kredi: " << temp->kredi
                << ", AKTS: " << temp->akts
                << ", Hoca: " << temp->hocaAdSoyad << "\n";
           temp = temp->next;
       }
   }
   //İndekstenSonraEkle fonk tanımı
   void indekstenSonraEkle(int indeks, const string ad, int dersKodu, int kredi, int akts, const string hocaAdSoyad) {
       ders* yeniDers = new ders{ad, dersKodu, kredi, akts, hocaAdSoyad, nullptr};
       if (!head) {
           head = yeniDers;
           return;
       }


       ders* temp = head;
       int sayac = 0;


       while (temp && sayac < indeks) {
           temp = temp->next;
           sayac++;
       }


       if (!temp) {
           cout << "Indeks bulunamadi, ekleme yapilamadi.\n";
           delete yeniDers;
           return;
       }


       yeniDers->next = temp->next;
       temp->next = yeniDers;
   }
};
//Main fonk
int main() {
   DersListesi liste1;
   liste1.dersEkle("Biyokimya", 101, 4, 6, "Fecir Duran");
   liste1.dersEkle("Nesne Yönelimli", 102, 3, 5, "Ayberk Şencan");
   liste1.dersEkle("Diferansiyel", 103, 2, 4, "Oğuzhan Sezer");
   liste1.dersEkle("Elektronik", 104, 3, 5, "Yavuz Selim Kaya");


   cout << "Liste 1:\n";
   liste1.listele();


   liste1.dersAra(102);
   liste1.dersSil(103);
   cout << "Liste 1 (Diferansiyel silindikten sonra)\n";
   liste1.listele();


   liste1.indekstenSonraEkle(1, "Ayrık Mat", 105, 3, 5, "Fatih Terim");
   cout << "Liste 1 (Indeks 1'den sonra Ayrık Mat eklendi)\n";
   liste1.listele();


   DersListesi liste2;
   liste2.dersEkle("Veri", 201, 3, 5, "Adem Tekerek");
   liste2.dersEkle("Yapi", 202, 2, 3, "Büşra Duygu");


   cout << "Liste 2\n";
   liste2.listele();


   return 0;
}
