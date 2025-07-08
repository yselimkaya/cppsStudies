//Tek yönlü bağlantılı liste üzerinde işlemler gerçekleştirecek bir C++ programı yazmak.

#include <iostream>


using namespace std;


//Dugum tanimlanmasi
struct Node
{
   int data;
   Node *pointer;
};


Node *head = nullptr;


// Basa dugum ekleme fonksiyonu
void addHead(int sayi)
{
   Node *willbeadded = new Node();
   willbeadded->data = sayi;
   willbeadded->pointer = head;
   head = willbeadded;
}


// Sona dugum eklemenin fonksiyonu
void addFoot(int sayi)
{
   Node *willbeadded = new Node();
   willbeadded->data = sayi;
   willbeadded->pointer = nullptr;


   if (head == nullptr)
   {
       head = willbeadded;
   }
   else
   {
       Node *temp = head;
       while (temp->pointer != nullptr)
       {
           temp = temp->pointer;
       }
       temp->pointer = willbeadded;
   }
}


// Araya ekleme metodu
void addBetween(int n, int sayi)
{
   Node *willbeadded = new Node();
   willbeadded->data = sayi;


   Node *temp = head;


   while (temp != nullptr && temp->data != n)
   {
       temp = temp->pointer;
   }


   if (temp == nullptr)
   {
       cout << "deger bulunamadi" << endl;
       delete willbeadded;
       return;
   }


   willbeadded->pointer = temp->pointer;
   temp->pointer = willbeadded;
}


// ilk dugumu silen fonk
void deleteHead()
{
   if (head == nullptr)
   {
       cout << "liste bos" << endl;
       return;
   }


   Node *temp = head;
   head = head->pointer;
   delete temp;
}


// son dugumu silen fonk
void deleteFoot()
{
   if (head == nullptr)
   {
       cout << "liste bos" << endl;
       return;
   }


   if (head->pointer == nullptr)
   {
       delete head;
       head = nullptr;
       return;
   }


   Node *temp = head;
   while (temp->pointer->pointer != nullptr)
   {
       temp = temp->pointer;
   }


   delete temp->pointer;
   temp->pointer = nullptr;
}


// secilen dugumu silen fonksiyon
void deleteChosen(int value)
{
   if (head == nullptr)
   {
       cout << "liste bos" << endl;
       return;
   }


   if (head->data == value)
   {
       Node *temp = head;
       head = head->pointer;
       delete temp;
       return;
   }


   Node *temp = head;
   while (temp->pointer != nullptr && temp->pointer->data != value)
   {
       temp = temp->pointer;
   }


   if (temp->pointer == nullptr)
   {
       cout << "liste bos" << endl;
       return;
   }


   Node *nodeToDelete = temp->pointer;
   temp->pointer = temp->pointer->pointer;
   delete nodeToDelete;
}


// ekrana yazdirma fonksşyonu
void yazdir()
{
   if (head == nullptr)
   {
       cout << "liste bos" << endl;
       return;
   }


   Node *temp = head;
   while (temp != nullptr)
   {
       cout << temp->data << " -> ";
       temp = temp->pointer;
   }
   cout << "NULL" << endl;
}


// arama fonksiyonu
void search(int value)
{
   Node *temp = head;
   while (temp != nullptr)
   {
       if (temp->data == value)
       {
           cout << "aranan dugum bulundu " << value << endl;
           return;
       }
       temp = temp->pointer;
   }
   cout << "bulunamadi" << endl;
}


// main
int main()
{
   addHead(10);
   addHead(20);
   addFoot(30);
   addBetween(10, 25);


   cout << "Liste: ";
   yazdir();


   deleteHead();
   cout << "Ilk dugum silindikten sonra: ";
   yazdir();


   deleteFoot();
   cout << "Son dugum silindikten sonra: ";
   yazdir();


   deleteChosen(25);
   cout << "25 degeri silindikten sonra: ";
   yazdir();


   search(10);
   search(50);


   return 0;
}
