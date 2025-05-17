/*
Create a program that defines an integer array (e.g., of a fixed size like 5, or by first asking the user for a size within a predefined maximum limit). 
Then, prompt the user to enter values for each element of the array.
After populating the array, calculate and display the sum of all its elements, followed by the average of these elements (which might require a floating-point type for accuracy).
*/
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
