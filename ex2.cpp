/* Bağlı listelerle ilgili;
Arama, ekleme ve ekrana yazdırma  algoritmalarına ait fonksiyonları hazırlayınız ve main() fonksiyon tarafından çalışmalarını test ediniz.
Personel isimli özel tanımlı bir tip tanımlayınız. Personel  tipi değişkenin Adı-Soyadı, Sicil numarası ve maaşı üye değişkenleri olmalı.  Personelin sicil numarası her bir personel için farklı ve eşsiz-tekil (unique) bir numara olmalıdır.
main() fonksiyon; Arama(basit, sıralı, ikili arama-Sicil numarasına göre, Ad-soyada göre) Ekleme, Listeleme(Artan sırada ve Sırasız) işlemlerinin tümünü yapabilmelidir.
Personel Arama İşlemlerini hem sicil numarasına göre hem de ad-soyada göre yapabilmelidir. Sicil numarası tekildir. Ancak Ad-soyad tekil olmayabilir. Bu nedenle aynı ad soyada sahip birden fazla Personel varsa aynı olan tüm personel ekrana listelenebilir olmalıdır.
Ekleme işlemi yeni Personelin tüm bilgilerini içerecek şekilde klavyeden okutarak bağlı listeye eklenmelidir. Ekleme işlemini sonrasında güncellenmiş liste ekrana yazdırılmalıdır.
Yukarıda açıklanan tüm işlemler için main fonksiyonda kodladığınız program parçaları çağrılmalıdır. Test için main fonksiyonda en az 4 adet personel bilgisi bir listede tutulmalıdır.
*/

#include <iostream>
#include <string>
using namespace std;


struct Personel {
   string adSoyad;
   int sicilNo;
   double maas;
   Personel* next;
};


class BagliListe {
private:
   Personel* head;


public:
   BagliListe() { head = nullptr; }


   void ekle(string adSoyad, int sicilNo, double maas) {
       Personel* yeni = new Personel{adSoyad, sicilNo, maas, nullptr};
       if (!head || head->sicilNo > sicilNo) {
           yeni->next = head;
           head = yeni;
       } else {
           Personel* tmp = head;
           while (tmp->next && tmp->next->sicilNo < sicilNo) {
               tmp = tmp->next;
           }
           yeni->next = tmp->next;
           tmp->next = yeni;
       }
   }


   Personel* araSicil(int sicilNo) {
       Personel* tmp = head;
       while (tmp) {
           if (tmp->sicilNo == sicilNo)
               return tmp;
           tmp = tmp->next;
       }
       return nullptr;
   }


   void araAdSoyad(string adSoyad) {
       Personel* tmp = head;
       bool bulundu = false;
       while (tmp) {
           if (tmp->adSoyad == adSoyad) {
               cout << "Ad Soyad " << tmp->adSoyad << ", Sicil No " << tmp->sicilNo << ", Maas " << tmp->maas << endl;
               bulundu = true;
           }
           tmp = tmp->next;
       }
       if (!bulundu) cout << "Bu isimde personel bulunamadi\n";
   }


   void listele(bool sirali = true) {
       if (!head) {
           cout << "Liste boş\n";
           return;
       }
       Personel* tmp = head;
       while (tmp) {
           cout << "Ad Soyad " << tmp->adSoyad << " Sicil No " << tmp->sicilNo << " Maaş " << tmp->maas << endl;
           tmp = tmp->next;
       }
   }
};


int main() {
   BagliListe liste;
   liste.ekle("Ceren Turan", 102, 5000);
   liste.ekle("Elif Nur Akgün", 101, 6000);
   liste.ekle("Betül Nur Uzan", 104, 5500);
   liste.ekle("Melike Aydın", 103, 5200);


   cout << "\nPersonel Listesi\n";
   liste.listele();


   cout << "\nSicil Numarasına Göre Arama\n";
   Personel* bulunan = liste.araSicil(102);
   if (bulunan) {
       cout << "Ad Soyad " << bulunan->adSoyad << " Sicil No " << bulunan->sicilNo << " Maaş " << bulunan->maas << endl;
   } else {
       cout << "Personel bulunamadı\n";
   }


   cout << "\nAd Soyada Göre Arama (Ceren Turan)\n";
   liste.araAdSoyad("Ceren Turan");


   return 0;
}
