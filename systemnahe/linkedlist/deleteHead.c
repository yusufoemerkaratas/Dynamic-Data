#include<stdio.h>
#include<stdlib.h>

typedef struct Knoten{
    int data;
    struct Knoten* nachfolger;
}knoten;



knoten* ersteller(int data){
    knoten* neu  =(knoten*)malloc(sizeof(knoten));  
    neu->data=data;
    neu->nachfolger=NULL;
    return neu;
}



void schreib(knoten* start){
    if(start==NULL){
        printf("Liste bos.\n");
        return;
    }
    knoten* temp=start;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->nachfolger;
    }
}



void insertAtPosition(knoten** start,int position,int data){
        knoten* neu=ersteller(data);
        if(position==0){
            neu->nachfolger=*start;
            *start=neu;
            return ;
        }
        knoten* temp=*start;
      for (int i = 1; i < position; i++) {
        temp = temp->nachfolger;
    }
        if (temp == NULL) {
        printf("Pozisyon gecersiz!\n");
        free(neu);
        return;
        }
            neu->nachfolger=temp->nachfolger;
            temp->nachfolger=neu;
    }

    

void deleteHead(knoten** start){
    if(*start==NULL){
        printf("Liste bos silinecek eleman yok\n");
        return;
    }
    knoten* copy=*start;
    *start=(*start)->nachfolger;
    free(copy);
    printf("Listeniin basindaki eleman silindi\n");
}

int main(){

    knoten* start = NULL;

    insertAtPosition(&start, 0, 10); // 0. pozisyon: Başa ekle
    insertAtPosition(&start, 1, 20); // 1. pozisyon: Sona ekle
    insertAtPosition(&start, 2, 15); // 1. pozisyon: Ortaya ekle

    // Listeyi yazdır
    printf("\nListe durumu:\n");
    schreib(start);

    // Listenin başını sil
    printf("\nListenin basindaki dugum siliniyor...\n");
    deleteHead(&start);

    // Listeyi tekrar yazdır
    printf("\nListe durumu:\n");
    schreib(start);

    // Listenin başını tekrar sil
    printf("\nListenin basindaki dugum siliniyor...\n");
    deleteHead(&start);

    // Listeyi tekrar yazdır
    printf("\nListe durumu:\n");
    schreib(start);

    return 0;
}


