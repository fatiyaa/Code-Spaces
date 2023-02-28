/*
Modifikasilah kode Dynamic Array dan 
Linked List (SinglyList) yang ada pada 
github agar menyimpan tipe string (asumsikan 
panjang string maks. adalah 100 karakter).
*/

/*
* MODUL 0 SOAL 3 - LINKED LIST FOR STRING
* 
* Oleh Fatiya Izzati
* pada 27 Februari 2023
* Struktur Data D
*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// membuat node berisi data angka
typedef struct snode_t {
    char word[101];
    struct snode_t *next;
} SListNode;

// struct pointer
typedef struct slist_t {
    SListNode *_head;
} SinglyList;

// prototype fungsi
void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pour(SinglyList *list, char *value);
void forEachElement(SinglyList *list, void (*func)(char *));
void printElement(char *elem);
void clean(SinglyList *list);

// fungsi utama
int main(){
    SinglyList myList;
    int big;

    //input
    printf("How much word(s) to input> ");
    scanf("%d", &big);
    char dataa[100];
    slist_init(&myList);
    for (int i=0; i<big; i++){
        scanf("%s", dataa);
        slist_pour(&myList, dataa);
    }
    forEachElement(&myList,printElement);
    clean(&myList);

    return 0;
}

void forEachElement(SinglyList *list, void (*func)(char *)){
    SListNode *temp = list->_head;
    while (temp != NULL){
        func(temp->word);
        temp = temp->next;
    }
    if (func==printElement)printf("\n");
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
void slist_pour(SinglyList *list, char value[]){
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            strcpy(newNode->word, value);
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

// fungsi print
void printElement(char *elem){
    char x[50];
    strcpy(x,elem);
    printf("%s ", x);
}

//fungsi membersihkan linkedlist
void clean(SinglyList *list){
    while(!slist_isEmpty(list)){
        SListNode *temp= list->_head;
        list->_head = list->_head->next;
        free(temp);
    }
}
