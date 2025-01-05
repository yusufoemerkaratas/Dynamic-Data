#include<stdio.h>
#include<stdlib.h>

// Düğüm yapısı
typedef struct Knoten {
    int data;
    struct Knoten* nachfolger;
} knoten;

// Yeni düğüm oluşturma
knoten* ersteller(int data) {
    knoten* neu = (knoten*)malloc(sizeof(knoten));
    neu->data = data;
    neu->nachfolger = NULL;
    return neu;
}

// Stack'e eleman ekleme (Push)
void push(knoten** start, int data) {
    knoten* temp = ersteller(data);
    temp->nachfolger = *start;  // `*start` NULL olsa bile sorun olmaz
    *start = temp;
    printf("Knoten wurde erfolgreich hinzugefügt: %d\n", temp->data);
}

// Stack'ten eleman çıkarma (Pop)
void pop(knoten** start) {
    if (*start == NULL) {  // Stack boşsa
        printf("Stack ist leer!!\n");
        return;
    }
    knoten* nachste = *start;      // İlk düğümü işaret et
    *start = (*start)->nachfolger; // Tepedeki düğümü atla
    printf("Das element wurde entfernt: %d\n", nachste->data);
    free(nachste);  // Belleği serbest bırak
}

// Stack'in elemanlarını yazdırma
void zeigStack(knoten* start) {
    if (start == NULL) {
        printf("Stack ist leer\n");
        return;
    }

    knoten* temp = start;
    while (temp != NULL) {
        printf("------>  %d\n", temp->data);
        temp = temp->nachfolger;
    }
}

// Ana fonksiyon
int main() {
    knoten* start = NULL;  // Boş bir stack başlat

    push(&start, 1);
    push(&start, 4);
    push(&start, 5);
    push(&start, 3);

    zeigStack(start);

    pop(&start);
    zeigStack(start);

    pop(&start);
    zeigStack(start);

    pop(&start);
        zeigStack(start);

    pop(&start);
    zeigStack(start);

    return 0;
}
