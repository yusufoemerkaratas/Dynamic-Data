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

void deleteTail(knoten** start){
    if(*start==NULL){
        printf("Liste bos");
        return;
        }

    if((*start)->nachfolger==NULL){
        free(*start);
        *start=NULL;
        printf("Liste bosaltildi");
        return;
    }
            knoten* temp=*start;

    while(temp->nachfolger->nachfolger!=NULL){
        temp=temp->nachfolger;
    }
    free(temp->nachfolger);
    temp->nachfolger=NULL;
}
