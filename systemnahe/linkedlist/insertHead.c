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

void insertAtHead(knoten** start,int zahl){
    knoten* neu = ersteller(zahl);
    neu->nachfolger=*start;
    *start=neu;
}

int main(){
    knoten* start =NULL;
    insertAtHead(&start,10);
}