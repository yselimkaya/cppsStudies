#include <iostream>
using namespace std;

int main(){
    int dizi[5];
    int toplam = 0;
    
    for(int i=0; i<5; i++){
        int sayi=0;
        cout << "5 elemanli dizinin "<< i <<".elemanini giriniz." << endl;
        cin >> sayi;
        dizi[i] = sayi;
        toplam = toplam + dizi[i];
        
        }
        
    float ortalama = 0.00;
    ortalama = toplam/5;
    cout <<"dizideki sayilarin ortalamasi" << ortalama << endl;
        
}    
