#include<stdio.h>
#include<stdlib.h>

typedef struct Knoten{
    int data;
    struct Knoten* nachfolger;
}knoten;

knoten* ersteller(int data){
    knoten* n=(knoten*)malloc(sizeof(knoten));
    n->data=data;
    n->nachfolger=NULL;
    return n;
}


void schreib(knoten* start) {
    if (start == NULL) {
        printf("Liste bos!\n");
        return;
    }

    knoten* temp = start;
    printf("Liste elemanlari: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->nachfolger;
    }
    printf("NULL\n");
}
knoten* search(knoten* start,int value){
    if(start==NULL){
        printf("Liste bos oldugu icin eleman bulunamadi");
        return NULL;
    }
    knoten* temp=start;
    while(temp!=NULL){
        if(temp->data==value){
            return temp;
        }else{
            temp=temp->nachfolger;
        }
    
    }
}
int main() {
    knoten* start = NULL;

    // Listeye eleman ekle
    start = ersteller(10);
    start->nachfolger = ersteller(20);
    start->nachfolger->nachfolger = ersteller(30);

    printf("\nListe durumu:\n");
    schreib(start);

    // Eleman arama
    knoten* found = search(start, 20);
    if (found != NULL) {
        printf("Bulunan eleman: %d\n", found->data);
    }

    found = search(start, 40);
    if (found == NULL) {
        printf("Aranan eleman listede bulunamadi.\n");
    }

    return 0;
}
