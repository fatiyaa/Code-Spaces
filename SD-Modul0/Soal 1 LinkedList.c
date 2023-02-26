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
void printList(SinglyList *list);
void printRev(SinglyList *list, int m);
void multiply(SinglyList *list);
int sumAll(SinglyList *list);
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
    printList(&myList);
    multiply(&myList);
    printList(&myList);
    printRev(&myList, big);
    printf("%d\n",sumAll(&myList));
    clean(&myList);

    return 0;
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

// fungsi print
void printList(SinglyList *list){
    SinglyList prnt = *list;
    while(!slist_isEmpty(&prnt)){
        printf("%d ", prnt._head->a);
        prnt._head=prnt._head->next;
    }
    printf("\n");
}

// fungsi print terbalik
void printRev(SinglyList *list, int m){
    SinglyList prnt = *list;
    int forp[m], n=m;
    while(!slist_isEmpty(&prnt)){
        m--;
        forp[m]=prnt._head->a;
        prnt._head=prnt._head->next;
    }
    for(int i=0; i<n; i++){
        printf("%d ", forp[i]);
    }
    printf("\n");
}

//fungsi untuk kali dua
void multiply(SinglyList *list){
    SinglyList mltp=*list;
    while(!slist_isEmpty(&mltp)){
        mltp._head->a*=2;
        mltp._head=mltp._head->next;
    }
}

//fungsi menjumlahkan
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
