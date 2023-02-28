/*
* MODUL 0 SOAL 2 - DYNAMIC ARRAY
* 
* Oleh Fatiya Izzati
* pada 28 Februari 2023
* Struktur Data D
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur ADT DynamicArray
typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi
void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(DynamicArray *darray, unsigned index);
void dArray_clearAll(DynamicArray *darray);
void dArray_printAll(DynamicArray *darray);

// fungsi utama
int main()
{
    // Buat objek DynamicArray
    DynamicArray myArray;
    //inisiasi
    dArray_init(&myArray);
    //input
    int big;
    printf("How much data to input> ");
    scanf("%d", &big);
    int a;
    printf("Input the data> ");
    for (int i=0; i<big; i++){
        scanf("%d", &a);
        dArray_pushBack(&myArray, a);
    }

    dArray_printAll(&myArray);
    //insert 10 pada indeks 3
    dArray_insertAt(&myArray, 3, 10);
    dArray_printAll(&myArray);
    //remove data di indeks ke 4
    dArray_removeAt(&myArray, 4);
    dArray_printAll(&myArray);
    //free array
    dArray_clearAll(&myArray);
    dArray_printAll(&myArray);
    return 0;
}

//fungsi inisiasi dynamic array
void dArray_init(DynamicArray *darray){
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

//fungsi cek apakah array kosong
bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}
//input data dalam array
void dArray_pushBack(DynamicArray *darray, int value){
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; it++)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}
//memasukkan data dalam indeks tertentu
void dArray_insertAt(DynamicArray *darray, unsigned index, int value){
    if (!dArray_isEmpty(darray)) {
        int *newArr;
        unsigned it;
        if (index > darray->_size)
            dArray_pushBack(darray, value);
        else{
            if (darray->_size + 1 > darray->_capacity)
                darray->_capacity *= 2;
            newArr = (int*) malloc(sizeof(int) * darray->_capacity);
            darray->_size++;
            for (it=0; it < darray->_size; it++){
                if(it == index) {
                    newArr[it]=value;
                    for(int h=it+1; h<darray->_capacity; h++){
                        newArr[h] = darray->_arr[h-1];
                    }
                    break;
                }
                newArr[it] = darray->_arr[it];
            }
            int *oldArray = darray->_arr;
            darray->_arr = newArr;
            free(oldArray);
        }
    }
}
//menghapus data pada indeks ke
void dArray_removeAt(DynamicArray *darray, unsigned index){   
    int *newArr=(int*) malloc(sizeof(int) * darray->_capacity);
    unsigned it;
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size) darray->_size--;
        else{
            for (it=0; it < darray->_size; it++){
                if(it == index) {
                    for(int h=it; h<darray->_capacity; h++){
                        newArr[h] = darray->_arr[h+1];
                    }
                    break;
                }
                newArr[it] = darray->_arr[it];
            }
            int *oldArray = darray->_arr;
            darray->_arr = newArr;
            free(oldArray);
            darray->_size--;
        }
    }
}
//bersih-bersih
void dArray_clearAll(DynamicArray *darray){
    free(darray->_arr);
    darray->_capacity=0;
    darray->_size=0;
}
//fungsi printing
void dArray_printAll(DynamicArray *darray){
    for (int i=0; i < darray->_size; i++) {
        printf("%d ", darray->_arr[i]);
    }
    if(!dArray_isEmpty(darray))printf("\n");
}