#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *node2, *head2;

void create(){ 
    struct node *temp;           // function of creation
    head = 0;
    int ch = 1;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nenter data  ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
            head = temp = newnode;
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("\ndo you want to continue(1 to continue or 0 to stop)?  ");
        scanf("%d", &ch);
    }
}

void display(struct node *head){ 
    struct node *temp;          // function to display
    int count = 0;
    temp = head;
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    printf("\ndisplay : ");
    while (temp != 0)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\ntotal number of nodes: %d", count);
}

void beg_insert(){                                                           // insertion at  the start
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter data  ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void end_insert()
{
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter data  ");                  // insertion at the end
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertK(int data, int pos)
{
    struct node *temp;
    int i;
    temp = head;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nEnd of List reached!!Can't Insert at %d", pos);
            return;
        }
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertAfterValue(int data, int val)
{
    struct node *temp;
    int i;
    temp = head;
    while (temp->data != val)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nValue does not exist in List!!");
            return;
        }
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertBeforeK(int data, int pos)
{
    struct node *temp;
    if (pos == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        return;
    }
    int i;
    temp = head;
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nEnd of List reached!!Can't Insert at %d", pos);
            return;
        }
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertBeforeValue(int dat, int val)
{
    struct node *temp;
    int i;
    if (temp->data == val){
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = dat;
        newnode->next=head;
        head=newnode;
        return;
    }
    temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
        if (temp->next == NULL){
            printf("\nValue does not exist in List!!");
            return;
        }
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = dat;
    newnode->next = temp->next;
    temp->next = newnode;
}









void beg_del()
{ 
    struct node *temp;        // deletion from beginning
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void end_del(){
    struct node *temp, *prev; // deletion from end
    if (head == NULL){
        printf("\nEmpty List!!");
        return;
    }
    temp = head;
    while (temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = 0;
    }
    else{
        prev->next = 0;
    }
    free(temp);
}

void delAftK(int k)
{
    struct node *t, *temp;
    int i;
    if (head == NULL){
        printf("\nEmpty List!!");
        return;
    }
    temp = head;
    for (i = 1; i < k; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nPosition does not exist in List!");
            return;
        }
    }
    if (temp->next == NULL)
    {
        printf("\nReached End Of List!!");
        return;
    }
    t = temp->next;
    temp->next = t->next;
    t->next = NULL;
    free(t);
}

void delBefK(int k)
{
    struct node *t, *temp;
    int i;
    k--;
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    if (k == 1)
    {
        beg_del();
        return;
    }
    else if (k <= 0)
    {
        printf("\nPosition statrs from 1!");
        return;
    }
    temp = head;
    for (i = 1; i < k - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nPosition does not exist in List!");
            return;
        }
    }
    t = temp->next;
    temp->next = t->next;
    t->next = NULL;
    free(t);
}

void delK(int k)
{
    struct node *temp, *t;
    int i;
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    if (k == 1)
    {
        beg_del();
        return;
    }
    temp = head;
    for (i = 1; i < k - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nPosition does not exist in List!");
            return;
        }
    }
    t = temp->next;
    temp->next = t->next;
    t->next = NULL;
    free(t);
}

void delVal(int val)
{
    struct node *prev, *end;
    end = head;
    prev = NULL;
    if (head == NULL)
    {
        printf("\nList Empty!!");
        return;
    }
    while (end)
    {
        if (end->data == val)
            break;
        prev = end;
        end = end->next;
    }
    if (end == NULL)
    {
        printf("\n%d not present in List!", val);
        return;
    }
    if (prev == NULL)
    {
        prev = head;
        head = head->next;
        prev->next = NULL;
        free(prev);
    }
    else
    {
        prev->next = end->next;
        end->next = NULL;
        free(end);
    }
}

void reverse()
{
    struct node *prev, *current, *nextnode; // reverse the linked list
    prev = 0;
    current = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
}

void sort(struct node *head)
{ 
    struct node *temp;     // sort
    int t;
    temp = head;
    struct node *index = NULL;
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    while (temp != NULL)
    {
        index = temp->next;
        while (index != NULL)
        {
            if (temp->data > index->data)
            {
                t = temp->data;
                temp->data = index->data;
                index->data = t;
            }
            index = index->next;
        }
        temp = temp->next;
    }
}

void search()
{
    struct node *temp;
    int item;
    printf("\nenter the element to be searched: ");
    scanf("%d", &item);
    if (head == NULL)
    {
        printf("\nList Empty!!");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("\nfound");
            return;
        }
        temp = temp->next;
    }
    printf("\nnot found");
}

void create_2(){ 
    struct node *temp;           
    head2 = 0;
    int ch = 1;
    while (ch)
    {
        node2 = (struct node *)malloc(sizeof(struct node));
        printf("\nenter data  ");
        scanf("%d", &node2->data);
        node2->next = 0;
        if (head2 == 0)
            head2 = temp = node2;
        else
        {
            temp->next = node2;
            temp = node2;
        }
        printf("\ndo you want to continue(1 to continue or 0 to stop)?  ");
        scanf("%d", &ch);
    }
}

struct node* merge(struct node* list1, struct node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1->data < list2->data) {
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else {
        list2->next = merge(list1, list2->next);
        return list2;
    }
}

void concat(){
    create_2();
    struct node *temp;
    temp=head;
    if(head==NULL){
        display(head2);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
}

int areListsEqual(struct node* list1, struct node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data) {
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == NULL && list2 == NULL);
}

int main()
{
    int choice, val, pos, k;
    while (1)
    {
        printf("\nmenu....\nenter 1 for create\nenter 2 for display\nenter 3 to insert at the beginning\nenter 4 to insert at the end\nenter 5 to insert after the kth node\n");
        printf("enter 6 to insert after the node\nenter 7 to insert before the kth node\nenter 8 to insert before a node\nenter 9 to delete at start\nenter 10 to delete at end\n");
        printf("enter 11 to delete a node after the kth node\nenter 12 to delete a node before the kth node\nenter 13 to delete the kth node\nenter 14 to delete a node containing a secified position\nenter 15 to reverse\n");
        printf("enter 16 to sort\nenter 17 to search\nenter 18 to merge\nenter 19 to concat\nenter 20 to check for equality\nenter enter 0 for exit.\n\nenter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display(head);
            break;
        case 3:
            beg_insert();
            break;
        case 4:
            end_insert();
            break;
        case 5:
            printf("\nEnter position after which to insert: ");
            scanf("%d", &pos);
            printf("\nEnter value to insert after %d: ", pos);
            scanf("%d", &val);
            insertK(val, pos);
            break;
        case 6:
            printf("\nEnter value to be inserted: ");
            scanf("%d", &val);
            printf("\nEnter value after which to insert: ");
            scanf("%d", &k);
            insertAfterValue(val, k);
            break;
        case 7:
            printf("\nEnter position before which to insert: ");
            scanf("%d", &pos);
            printf("\nEnter value to insert: ");
            scanf("%d", &val);
            insertBeforeK(val, pos);
            break;
        case 8:
            printf("\nEnter value to be inserted: ");
            scanf("%d", &val);
            printf("\nEnter value before which to insert: ");
            scanf("%d", &k);
            insertBeforeValue(val, k);
            break;
        case 9:
            beg_del();
            break;
        case 10:
            end_del();
            break;
        case 11:
            printf("\nEnter position after which to delete: ");
            scanf("%d", &pos);
            delAftK(pos);
            break;
        case 12:
            printf("\nEnter position before which to delete: ");
            scanf("%d", &pos);
            delBefK(pos);
            break;
        case 13:
            printf("\nEnter position to be deleted: ");
            scanf("%d", &pos);
            delK(pos);
            break;
        case 14:
            printf("\nEnter value to be deleted!");
            scanf("%d", &val);
            delVal(val);
            break;
        case 15:
            reverse();
            break;
        case 16:
            sort(head);
            break;
        case 17:
            search();
            break;
        case 18:
            printf("\ncreate the 2nd linked-list: \n");
            create_2();
            struct node *meg_head = merge(head,head2);
            break;
        case 19:
            printf("\ncreate the 2nd linked-list: \n");
            concat();
            break;
        case 20:
            printf("\ncreate the 2nd linked-list: \n");
            create_2();
            int i=areListsEqual(head,head2);
            if(i){
                printf("\n the lists are equal");
            }
            else{
                printf("\n the lists are not equal");
            }
            break;
        case 0:
            printf("\nexit....");
            exit(0);
        default:
            printf("\nwrong choice. Try again.\n");
            break;
        }
    }
    return 0;
}
