/*
Çok düzeyli bağlantılı listeyi düzleştirme 
Bir sonraki işaretçiye ek olarak, her düğümün ayrı bir listeyi işaret edebilen veya işaret edemeyen bir alt işaretçiye sahip olduğu bağlantılı bir listeler için;
Bu alt listelerin kendilerine ait bir veya daha fazla alt öğesi olabilir ve bu şekilde aşağıdaki şekilde gösterildiği gibi çok düzeyli bir veri yapısı oluşturulabilir.
Listenin ilk seviyesinin başı size verilmiştir.
Tüm düğümlerin tek düzeyli bağlantılı listede görünmesi için listeyi düzleştirin.
Listeyi, birinci seviyedeki tüm düğümlerin önce gelmesi, ardından ikinci seviyedeki düğümlerin vb. gelecek şekilde düzleştirmeniz gerekir.
Resim 'ex4.jpg' olarak paylaşılacak.
Yukarıdaki liste 10->5->12->7->11->4->20->13->17->6->2->16->9->8->3->19->15 şekline dönüşecek.

İlk seviyeden başlanarak, tüm düğümleri tek tek dolaşılacaktır.
Eğer bir düğümün çocuğu varsa, çocuğu listenin sonuna eklenecek.
Yoksa hiçbir şey yapılmayacak.
İlk seviye işlendikten sonra, tüm sonraki seviye düğümleri ilk seviyeden sonra eklenecektir.
Eklenen düğümler için de aynı süreç izlenecek.
*/




#include <stdio.h>
#include <stdlib.h>


struct node {
   int data;
   struct node* next;
   struct node* child;
};
typedef struct node node;




void nodeOlustur(node** newNode, int data) {
   *newNode = (node*)malloc(sizeof(node));
   (*newNode)->data = data;
   (*newNode)->next = NULL;
   (*newNode)->child = NULL;
}




void printList(node* head) {
   node* temp = head;
   while (temp) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}


void sonNodeBul(node* head, node** tail) {
   *tail = NULL;
   if (!head) return;


   while (head->next)
       head = head->next;


   *tail = head;
}


// Listeyi düzleştir
void duzlestir(node* head) {
   node* tail = NULL;
   sonNodeBul(head, &tail);
   node* current = head;


   while (current != NULL) {
       if (current->child) {
           tail->next = current->child;
           sonNodeBul(tail->next, &tail);
       }
       current = current->next;
   }
}


int main() {
   node *head = NULL;


   nodeOlustur(&head, 10);
   nodeOlustur(&head->next, 5);
   nodeOlustur(&head->next->next, 12);
   nodeOlustur(&head->next->next->next, 7);
   nodeOlustur(&head->next->next->next->next, 11);


   nodeOlustur(&head->next->next->child, 4);
   nodeOlustur(&head->next->next->child->next, 20);
   nodeOlustur(&head->next->next->child->next->next, 13);


   nodeOlustur(&head->next->next->child->next->child, 17);
   nodeOlustur(&head->next->next->child->next->child->next, 6);


   nodeOlustur(&head->next->next->child->next->child->next->child, 2);
   nodeOlustur(&head->next->next->child->next->child->next->child->next, 16);




   duzlestir(head);




   printList(head);


   return 0;
}
