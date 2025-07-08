/*
Kullanıcının girdiği n adet sayıyı stack'e ekleyip, sonra hepsini çıkararak ters sırada ekrana yazdıran bir program yazınız.
Stack kullanarak girilen bir ifadenin parantez dengesini kontrol eden bir program yazınız.
Örnek: "((a+b)*c)" → DENGELİ, "((a+b)" → DENGESİZ
Recursive bir fonksiyon kullanmadan stack ile faktöriyel hesaplayınız.

*/


//1-Cevap)
#include <iostream>
#include <stack>

using namespace std;

int main(){

stack<int> yigin;

int i=0;
while(true){
    cout<<"Yigine eklenecek sayiyi giriniz.Cikmak icin -1 giriniz."<<endl;
    cin >> i;
    if(i ==-1){
        break;
        }
    yigin.push(i);
    };

    while (!yigin.empty()) {
        cout << yigin.top() << " ";
        yigin.pop();
    }

    cout << endl;
    return 0;    
}
#include <iostream>
#include <stack>

using namespace std;

int main(){

stack<int> yigin;

int i=0;
while(true){
    cout<<"Yigine eklenecek sayiyi giriniz.Cikmak icin -1 giriniz."<<endl;
    cin >> i;
    if(i ==-1){
        break;
        }
    yigin.push(i);
    };

    while (!yigin.empty()) {
        cout << yigin.top() << " ";
        yigin.pop();
    }

    cout << endl;
    return 0;    
}

//2.Cevap

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool parantezKontrol(const string& ifade) {
    stack<char> yigin;

    for (char ch : ifade) {
        if (ch == '(' || ch == '{' || ch == '[') {
            yigin.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (yigin.empty())
                return false;

            char ust = yigin.top();
            yigin.pop();

            if ((ch == ')' && ust != '(') ||
                (ch == '}' && ust != '{') ||
                (ch == ']' && ust != '[')) {
                return false;
            }
        }
    }

    return yigin.empty();
}

int main() {
    string ifade;
    cout << "Ifade giriniz";
    getline(cin, ifade);  // 

    if (parantezKontrol(ifade)) {
        cout << "pareantezler dengeli" << endl;
    } else
        cout << "parantezler dengesiz" << endl;
        
}


//Cevap3

#include <iostream>
#include <stack>
using namespace std;


int main(){
    stack<int> faktoriyel;
    int secim;
    int sonuc=1;
    cout << "hesaplanacak faktoriyeli giriniz" << endl;
    cin >> secim;
    for(int i=1; i<=secim;i++){
        faktoriyel.push(i);
        }
     while (!faktoriyel.empty()) {
        sonuc *= faktoriyel.top();
        faktoriyel.pop();
    }
    cout << sonuc << endl;
    
    
    }
    


