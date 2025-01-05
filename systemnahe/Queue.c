#include <stdio.h>
#include <stdlib.h>

// Node yapısı
typedef struct Node { 
    int data;
    struct Node* next;
} Node;

// Kuyruğun başlangıcı ve sonu
Node* front = NULL;  // Kuyruğun başını işaret eder
Node* rear = NULL;   // Kuyruğun sonunu işaret eder

// Kuyruğa eleman ekle
void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  // Kuyruk boşsa
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Kuyruğa eklendi: %d\n", value);
}

// Kuyruktan eleman çıkar
int dequeue() {
    if (front == NULL) {  // Kuyruk boşsa
        printf("Kuyruk boş! Eleman çıkarılamıyor.\n");
        return -1;
    }

    Node* temp = front;         // Çıkarılacak düğümü işaret et
    int value = temp->data;     // Veriyi al
    front = front->next;        // Kuyruğun başını güncelle

    if (front == NULL) {        // Eğer kuyruk tamamen boşaldıysa
        rear = NULL;
    }

    free(temp);  // Belleği serbest bırak
    printf("Kuyruktan çıkarıldı: %d\n", value);
    return value;
}

// Kuyruğu yazdır
void displayQueue() {
    if (front == NULL) {
        printf("Kuyruk boş!\n");
        return;
    }

    Node* temp = front;
    printf("Kuyruk: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();

    dequeue();
    displayQueue();

    enqueue(40);
    enqueue(50);
    displayQueue();

    dequeue();
    dequeue();
    displayQueue();

    return 0;
}
