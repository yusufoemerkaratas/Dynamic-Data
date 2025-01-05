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

void deleteValue(knoten** start,int value){
    if(*start==NULL){
        printf("Liste bos\n");
        return;
    }
    
    if((*start)->data==value){
        knoten *temp=*start;
        *start=(*start)->nachfolger;
        free(temp);
        printf("Deger silnidi %d\n",value);
        return;
    }
    knoten* temp=*start;
    while(temp->nachfolger!=NULL&& temp->nachfolger->data!=value){
        temp=temp->nachfolger;
        }
        
        if(temp->nachfolger==NULL){
            printf("Listede böyle bir deger bulunamadi");
            return;
        }
        knoten* neutemp=temp->nachfolger->nachfolger;
    
        free(temp->nachfolger);
        temp->nachfolger=neutemp;
        printf("Bu deger silindi %d",value);
        return;
}
int main() {
    knoten* start = NULL;

    // Listeye eleman ekle
    start = ersteller(10);
    start->nachfolger = ersteller(20);
    start->nachfolger->nachfolger = ersteller(30);

    printf("\nListe durumu:\n");
    schreib(start);

    // Değer silme işlemleri
    printf("\nDeger siliniyor: 20\n");
    deleteValue(&start, 20);

    printf("\nListe durumu:\n");
    schreib(start);

    printf("\nDeger siliniyor: 10\n");
    deleteValue(&start, 10);

    printf("\nListe durumu:\n");
    schreib(start);

    printf("\nDeger siliniyor: 30\n");
    deleteValue(&start, 30);

    printf("\nListe durumu:\n");
    schreib(start);

    printf("\nDeger siliniyor: 40 (olmayan bir deger)\n");
    deleteValue(&start, 40);

    return 0;
}
