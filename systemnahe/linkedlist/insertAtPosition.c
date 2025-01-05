#include<stdio.h>
 #include<stdlib.h>

    typedef struct Knoten{
        int data;
        struct Knoten* nachfolger;
    }knoten;

    knoten*  ersteller(int data){
        knoten* neu=(knoten*)malloc(sizeof(knoten));
        neu->data=data;
        neu->nachfolger=NULL;
        return neu;
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
     if(temp== NULL){
            printf("Pozisyon gecersizq");
            free(neu);
            return;
        }   

            neu->nachfolger=temp->nachfolger;
            temp->nachfolger=neu;
    }
    void write(knoten* start) {
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
int main() {
    knoten* start = ersteller(10); 
    insertAtPosition(&start,0,100);
    insertAtPosition(&start, 1, 20); 
    insertAtPosition(&start, 1, 15); 
    insertAtPosition(&start, 3, 25); 
    insertAtPosition(&start, 5, 30); 

    printf("\nListe durumu:\n");
    write(start);

    return 0;
}
