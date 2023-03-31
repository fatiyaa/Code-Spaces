/*
* MODUL 0 SOAL 1 - LINKED LIST
* 
* Oleh Fatiya Izzati
* pada 27 Februari 2023
* Struktur Data D
*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// membuat node berisi data angka
typedef struct snode_t {
    int a;
    struct snode_t *next;
} SListNode;

// struct pointer
typedef struct slist_t {
    SListNode *_head;
} SinglyList;

// prototype fungsi
void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pour(SinglyList *list, int *value, int m);
void forEachElement(SinglyList *list, void (*func)(int *));
void Rev(SinglyList *list);
void multiply2(int *elem);
void printElement(int *elem);
int sumAll(SinglyList *list);
void reserveEach(int *data);
void sumDig(int *data);
void clean(SinglyList *list);

// fungsi utama
int main(){
    SinglyList myList;
    int big;

    printf("How much data to input> ");
    scanf("%d", &big);
    int dataa[big];
    for (int i=0; i<big; i++)
        scanf("%d", &dataa[i]);

    slist_init(&myList);
    slist_pour(&myList, dataa, big);

    forEachElement(&myList,printElement);

    forEachElement(&myList,reserveEach);
    
    forEachElement(&myList,printElement);
    
    forEachElement(&myList,sumDig);
    
    forEachElement(&myList,printElement);
    
    forEachElement(&myList,multiply2);
    
    forEachElement(&myList,printElement);
    
    Rev(&myList);
    forEachElement(&myList,printElement);
    printf("%d\n",sumAll(&myList));
    clean(&myList);
    return 0;
}

//operasi untuk tiap node
void forEachElement(SinglyList *list, void (*func)(int *)){
    SListNode *temp = list->_head;
    while (temp != NULL){
        func(&temp->a);
        temp = temp->next;
    }
    if (func==printElement)printf("\n");
}

//untuk print
void printElement(int *elem) {
    printf("%d ", *elem);
}

//untuk kali 2
void multiply2(int *elem) {
    *elem *= 2;
}

//inisiasi struct pointer head
void slist_init(SinglyList *list){
    list->_head = NULL;
}

//cek apakah linked list kosong
bool slist_isEmpty(SinglyList *list){
    return (list->_head == NULL);
}

// memasukkan array input ke dalam linked list
void slist_pour(SinglyList *list, int *value, int m){
    for(int i=0; i<m; i++){
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            newNode->a = value[i];
            newNode->next = NULL;
            
            if (slist_isEmpty(list)) 
                list->_head = newNode;
            
            else {
                SListNode *temp = list->_head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }
}

//fungsi membalik digit data dalam node
void reserveEach(int *data){
    int temp=*data;
    int rev=0;
    while(temp){
        rev=(rev*10)+temp%10;
        temp/=10;
    }
    *data = rev;
}

// fungsi menjumlahkan digit tiap node
void sumDig(int *data){
    int temp=*data, sum=0;
    while(temp){
        sum+=temp%10;
        temp/=10;
    }
    *data=sum;
}

// membalik linkedlist
void Rev(SinglyList *list){
    SListNode * prev = NULL;
    SListNode * curr = list->_head;
    SListNode * aft = NULL;

    while (curr != NULL) {
        aft = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aft;
    }
    list->_head = prev;
}


//fungsi menjumlahkan semua node
int sumAll(SinglyList *list){
    SinglyList sum =*list;
    int val=0;
    while(!slist_isEmpty(&sum)){
        val+=sum._head->a;
        sum._head=sum._head->next;
    }
    return val;
}

//fungsi membersihkan linkedlist
void clean(SinglyList *list){
    while(!slist_isEmpty(list)){
        SListNode *temp= list->_head;
        list->_head = list->_head->next;
        free(temp);
    }
}