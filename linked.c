#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;

void create(){                        //function of creation
    head=0;
    int ch=1;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nenter data  ");
        scanf("%d", &newnode->data);
        newnode->next=0;
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\ndo you want to continue(1 to continue or 0 to stop)?  ");
        scanf("%d",&ch);
    }
}
void display(){                     //function to display
    int count=0;
    temp=head;
    printf("\ndisplay : ");
    while (temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\ntotal number of nodes: %d",count);
}
void beg_insert(){                                        //insertion at  the start
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter data  ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
}
void end_insert(){      
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter data  ");                               //insertion at the end
    scanf("%d", &newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
}
void beg_del(){              //deletion from beginning
    temp=head;
    head=head->next;
    free(temp);
}
void end_del(){                   
    struct node *prev;             //deletion from end
    temp=head;
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;
    }
    if(temp==head){ head=0;}
    else{  prev->next=0;}
    free(temp);
}
void reverse(){
    struct node *prev,*current,*nextnode;  //reverse the linked list
    prev=0;
    current=nextnode=head;
    while(nextnode!=0){
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev;
}
void sort(){
    int t;
    temp=head;
    struct node *index=NULL;
    while(temp != NULL) {
        index=temp->next;           
        while(index != NULL) {  
             if(temp->data > index->data) {  
             t=temp->data;  
             temp->data = index->data;  
             index->data = t;  
            }  
         index=index->next;  
        }  
        temp=temp->next; 
    }
}

int main()
{
    int choice;
    while(1){
        printf("\nmenu....\nenter 1 for create\nenter 2 for display\nenter 3 to insert at the beginning\nenter 4 to insert at the end\nenter 5 to delete at start\nenter 6 to delete at end\n");
        printf("enter 7 to reverse\nenter 8 to sort\nenter enter 0 for exit.\n\nenter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: create();
              break;
            case 2: display();
              break;
            case 3: beg_insert();
              break;
            case 4: end_insert();
              break;
            case 5: beg_del();
              break;
            case 6: end_del();
              break;
            case 7: reverse();
              break;
            case 8: sort();
              break;             
            case 0: printf("\nexit...."); 
              exit(0);
            default: printf("\nwrong choice. Try again.\n");
              break;   
        }
    }
    return 0;
}

