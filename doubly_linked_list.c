#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next; 
};
struct node *head, *newnode, *head2, *node2;
void create() {
    struct node *temp;
    head = NULL;
    int ch = 1;
    while (ch) {
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("\nDo you want to continue (1 to continue or 0 to stop)? ");
        scanf("%d", &ch);
    }
}

void display(struct node *head) {
    struct node *temp;
    int count = 0;
    temp = head;
    if (head == NULL) {
        printf("\nEmpty List!!");
        return;
    }
    printf("\nDisplay: ");
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nTotal number of nodes: %d", count);
}

void beg_insert() {                                                 // insertion at  the start
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}

void end_insert() {                                                 // insertion at the end
    struct node *temp;
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertK(int data, int pos) {
    struct node *temp;
    int i;
    temp = head;
    for (i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("\nEnd of List reached!!Can't Insert at %d", pos);
            return;
        }
    }
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void insertAfterValue(int data, int val) {
    struct node *temp;
    int i;
    temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nValue does not exist in List!!");
        return;
    }
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void insertBeforeK(int data, int pos)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (pos == 1)
    {
        if(head == NULL) {
            head = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
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
    newnode->prev = temp;
    newnode->next = temp->next;
    if(temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void insertBeforeValue(int val)
{
    struct node *t,*x;
    int data,i;
    if(head==NULL){
        printf("\nempty list");
        return;
    }
    x=head;
    while(x->data != val){
        if(x->next==NULL){
            printf("\nvalue not found");
            return;
        }
        x=x->next;
    }
    printf("\nenter data: ");
    scanf("%d",&data);
    t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
    t->prev=NULL;
    if(x->prev==NULL){
        t->next=x;
        x->prev=t;
        head=t;
        return;
    }
    t->prev=x;
    x->prev->next=t;
    t->next=x;
    x->prev=t;
}

void beg_del()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void end_del()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
    }
    else
    {
        temp->prev->next = NULL;
    }
    free(temp);
}

void delAftK(int k)
{
    struct node *temp;
    int i;
    if (head == NULL)
    {
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
    struct node *t = temp->next;
    temp->next = t->next;
    if (t->next != NULL)
    {
        t->next->prev = temp;
    }
    free(t);
}

void delBefK(int k)
{
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    if (k <= 1)
    {
        printf("\nPosition starts from 2!");
        return;
    }
    struct node *temp, *t;
    temp = head;
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nPosition does not exist in List!");
            return;
        }
    }
    if (temp->prev == NULL)
    {
        beg_del();
        return;
    }
    t = temp->prev;
    t->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = t;
    }
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
}

void delK(int k)
{
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
    struct node *temp, *t;
    temp = head;
    for (int i = 1; i < k; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nPosition does not exist in List!");
            return;
        }
    }
    if (temp->prev == NULL)
    {
        beg_del();
        return;
    }
    t = temp->prev;
    t->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = t;
    }
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
}

void delVal(int val)
{
    if (head == NULL)
    {
        printf("\nList Empty!!");
        return;
    }
    struct node *temp;
    temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            if (temp->prev == NULL)
            {
                beg_del();
                return;
            }
            temp->prev->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            temp->next = NULL;
            temp->prev = NULL;
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("\n%d not present in List!", val);
}

void reverse()
{
    struct node *temp = NULL, *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}

void sort(struct node *head)
{
    struct node *temp1, *temp2;
    int tempData;
    if (head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    for (temp1 = head; temp1->next != NULL; temp1 = temp1->next)
    {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp1->data > temp2->data)
            {
                tempData = temp1->data;
                temp1->data = temp2->data;
                temp2->data = tempData;
            }
        }
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

void create_2() {
    struct node *temp;
    head2 = 0;
    int ch = 1;
    while (ch)
    {
        node2 = (struct node *)malloc(sizeof(struct node));
        printf("\nenter data  ");
        scanf("%d", &node2->data);
        node2->prev = node2->next = 0;
        if (head2 == 0)
            head2 = temp = node2;
        else
        {
            temp->next = node2;
            node2->prev = temp;
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
        list1->next->prev = list1;
        list1->prev = NULL;
        return list1;
    }
    else {
        list2->next = merge(list1, list2->next);
        list2->next->prev = list2;
        list2->prev = NULL;
        return list2;
    }
}

void concat() {
    create_2();
    struct node *temp;
    temp = head;
    if (head == NULL) {
        head = head2;
        head->prev = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    head2->prev = temp;
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
            printf("\nEnter value before which to insert: ");
            scanf("%d", &val);
            insertBeforeValue(val);
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

