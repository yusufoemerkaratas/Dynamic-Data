#include<stdio.h>
#include<stdlib.h>

typedef struct Knoten{
    int data;
    struct Knoten* nachfolger;
}knoten;

knoten* ersteller(int data){
    knoten* neu = (knoten*)malloc(sizeof(knoten));
    neu->data=data;
    neu->nachfolger=NULL;
    return neu;
}

 void push(knoten** start,int data){
    knoten* temp=ersteller(data);

    temp->nachfolger=*start;
    *start=temp;
     printf("Knoten wurde erfolgreich hinzugefügt: %d\n",temp->data);

 }

 void pop(knoten** start){
    if(*start==NULL){
        printf("Stack ist leer!!\n");
        return;
    }
   
    knoten* nachste = *start;
    *start = (*start)->nachfolger;
     printf("Das element wurde entfernt: %d\n",nachste->data);
    free(nachste);
 }

 void zeigStack(knoten* start){
    if(start==NULL){
        printf("Stack ist leer\n");
        return;
    }
    knoten *temp=start;
    while(temp!=NULL){
      
        printf("------>  %d\n",temp->data);
        temp=temp->nachfolger;
    }         
 }

 int main(){
    knoten* start =NULL;
    push(&start,1);
    push(&start,4);
    push(&start,5);
    push(&start,3);

    zeigStack(start);
    
    pop(&start);
    zeigStack(start);
    pop(&start);
    zeigStack(start);
    pop(&start);
        zeigStack(start);

    pop(&start);
    zeigStack(start);
    
 }
