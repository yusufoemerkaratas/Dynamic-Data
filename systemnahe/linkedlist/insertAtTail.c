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

    void insertAtTail(knoten** start,int data){
        knoten* neu=ersteller(data);

        if(*start==NULL){
            *start=neu;
            return;
        }

        knoten* temp=*start;
        
        while(temp->nachfolger!=NULL){
            temp=temp->nachfolger;
        }
        temp->nachfolger=neu;
    }
    void schreiber(knoten* start){
        if(start==NULL){
            printf("Liste bos\n");
            return;
        }

            printf("Listenin elemanlari:\n ");
            knoten* temp=start;
            while(temp!=NULL){
                printf("%d ->", temp->data);
                temp=temp->nachfolger;
            }
            printf("Null\n");
    }

    int main(){
        knoten* start=NULL;

        printf("Elemanlar listeye yükleniyor\n");
        insertAtTail(&start,10);
        insertAtTail(&start,20);
        insertAtTail(&start,30);
        insertAtTail(&start,40);

        printf("Liste durumu : \n");
        schreiber(start);
        return 0;
        
    }
