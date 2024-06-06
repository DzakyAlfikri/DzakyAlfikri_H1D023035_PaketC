#include<stdio.h>
#include<stdlib.h>
#define maxqueue 5

typedef struct{
    int count;
    int front; 
    int rear;
    int item[maxqueue]; 
}queue;

queue antrean;

void inisiasi(queue*q){
    q->count=0;
    q->front=0;
    q->rear=0;
}

int isEmpty(queue *q){
    int hasil=0;
    if(q->count==0){
        hasil=1;
    }
    return hasil;
}

int isFull(queue *q){
    int hasil=0;
    if(q->count==maxqueue){
        hasil=1;
    }
    return hasil;
}

void insert(queue *q, int data){
    if (isFull(q)==1){ 
        printf("maaf sudah full");
        }else{ 
            q->item[q->rear]=data;
            q->rear=(q->rear+1)%maxqueue;
            ++(q->count);
    }
}

void hapus(queue*q){
    if (isEmpty(q)) {
        printf("Antrean kosong");
    } else {
        printf("Menghapus: %d\n", q->item[q->front]); // Mengubah item menjadi data
        q->front = (q->front + 1) % maxqueue;
        --(q->count);
    }
}

void printqueue(queue *q){ 
    if (isEmpty(q)) {
        printf("Antrean kosong\n");
    } else {
        printf("Isi antrean: ");
        int i;
        int index = q->front;
        for (i = 0; i < q->count; i++) {
            printf("%d ", q->item[index]);
            index = (index + 1) % maxqueue;
        }
        printf("\n");
    }
}

int main(){
    inisiasi(&antrean);
    printf("masukkan 17\n");
    insert(&antrean, 17);
    printqueue(&antrean);
    printf("masukkan 45\n");
    insert(&antrean, 45);
    printqueue(&antrean);
    printf("masukkan 77\n");
    insert(&antrean, 77);
    printqueue(&antrean);
    hapus(&antrean);
    printf("masukkan 15\n");
    insert(&antrean, 15);
    printqueue(&antrean);
    return 0;
}
