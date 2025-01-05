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

void freeList(knoten** start){
    if(*start==NULL){
        printf("Liste zaten bos ");
        return;
    }
    knoten* temp=*start;
    while(temp!=NULL){
        knoten* neutemp =temp;
        temp=temp->nachfolger;
        free(neutemp);
    }
    *start=NULL;    
}