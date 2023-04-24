#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct varll
{
     char var;
     int power;
     struct varll *next;
} VarLL;

typedef struct node
{
     int data;
     VarLL *varll;
     struct node *next;
} Node;

VarLL *createVariableNode(char var, int power)
{
     VarLL *new = (VarLL *)malloc(sizeof(VarLL));
     new->var = var;
     new->power = power;
     new->next = NULL;
     return new;
}

VarLL *createVariableinkedList(int n)
{
     VarLL *temp = NULL;
     VarLL *head = NULL;
     int power;
     char var;
     for (int i = 1; i <= n; i++)
     {
          printf("\nEnter variable and its power: ");
          scanf(" %c %d", &var, &power);

          if (temp)
          {
               temp->next = createVariableNode(var, power);
               temp = temp->next;
          }
          else
          {
               head = createVariableNode(var, power);
               temp = head;
          }
     }

     return head;
}

Node *createNode(int data, VarLL *varll)
{
     Node *node = (Node *)malloc(sizeof(Node));
     node->data = data;
     node->varll = varll;
     node->next = NULL;
     return node;
}

Node *createLinkedList()
{
     Node *temp = NULL;
     Node *head = NULL;
     int data, n;
     VarLL *varll;
     do
     {
          char *var = (char *)malloc(sizeof(char) * 10);
          printf("Enter element coeff: ");
          scanf("%d", &data);
          if (data == -1)
               break;

          printf("Enter number of variables: ");
          scanf("%d", &n);
          varll = createVariableinkedList(n);

          if (temp)
          {
               temp->next = createNode(data, varll);
               temp = temp->next;
          }
          else
          {
               head = createNode(data, varll);
               temp = head;
          }
     } while (1);

     return head;
}

VarLL *CopyVarll(VarLL *varll)
{
     VarLL *varll3 = NULL;
     VarLL *ptr = NULL;
     while (varll != NULL)
     {
          VarLL *new = createVariableNode(varll->var, varll->power);
          varll = varll->next;
          if (varll3 == NULL)
          {
               varll3 = new;
               ptr = new;
          }
          else
          {
               ptr->next = new;
               ptr = ptr->next;
          }
     }
     return varll3;
}

int varLLEqual(VarLL *varll1, VarLL *varll2)
{
     while (varll1 != NULL && varll2 != NULL)
     {
          if (varll1->var != varll2->var || varll1->power != varll2->power)
          {
               return 0;
          }
          varll1 = varll1->next;
          varll2 = varll2->next;
     }
     return 1;
}

Node *CopytoPoly3(Node *poly2)
{
     Node *poly3 = NULL;
     Node *ptr = NULL;
     while (poly2 != NULL)
     {
          VarLL *varll = CopyVarll(poly2->varll);
          Node *new = createNode(poly2->data, varll);
          poly2 = poly2->next;
          if (poly3 == NULL)
          {
               poly3 = new;
               ptr = new;
          }
          else
          {
               ptr->next = new;
               ptr = ptr->next;
          }
     }
     return poly3;
}

void displayVarLL(VarLL *head)
{
     if (head == NULL)
     {
          printf("Empty\n");
          return;
     }
     VarLL *ptr = head;
     printf("\t");
     while (ptr)
     {
          printf("%c%d", ptr->var, ptr->power);
          ptr = ptr->next;
          printf("->");
     }
     printf("NULL\n");
}

void display(Node *head)
{
     if (head == NULL)
     {
          printf("Empty\n");
          return;
     }
     Node *ptr = head;
     printf("\t");
     while (ptr)
     {
          printf("%d", ptr->data);
          VarLL *varptr = ptr->varll;
          while (varptr != NULL)
          {
               printf("%c%d", varptr->var, varptr->power);
               varptr = varptr->next;
          }
          ptr = ptr->next;
          printf("->");
     }
     printf("NULL\n");
}

VarLL *variablemultiply(VarLL *varll1, VarLL *varll2)
{
     VarLL *varll3 = NULL;
     varll3 = CopyVarll(varll1);

     while (varll2 != NULL)
     {
          VarLL *ptr = varll3;
          VarLL *prev = varll3;

          while (ptr != NULL)
          {
               if (varll2->var == ptr->var)
               {
                    ptr->power += varll2->power;
                    break;
               }
               prev = ptr;
               ptr = ptr->next;
          }
          if (ptr == NULL)
          {
               prev->next = createVariableNode(varll2->var, varll2->power);
          }
          varll2 = varll2->next;
     };
     return varll3;
}

void mul(Node *poly1, Node *poly2)
{
     Node *poly3 = NULL;
     Node *poly3ptr = NULL;

     int data;
     VarLL *varll;
     while (poly2 != NULL)
     {
          Node *poly1ptr = poly1;
          while (poly1ptr != NULL)
          {
               data = (poly1ptr->data) * (poly2->data);
               varll = variablemultiply(poly1ptr->varll, poly2->varll);
               Node *new = createNode(data, varll);

               if (poly3 == NULL)
               {
                    poly3 = new;
                    poly3ptr = new;
               }
               else
               {
                    poly3ptr->next = new;
                    poly3ptr = poly3ptr->next;
               }
               poly1ptr = poly1ptr->next;
          }

          poly2 = poly2->next;
     };
     display(poly3);
}

void add(Node *poly1, Node *poly2)
{
     Node *poly3 = CopytoPoly3(poly1);

     int data;
     VarLL *varll;
     while (poly2 != NULL)
     {
          Node *poly3ptr = poly3;
          while (1)
          {
               if (varLLEqual(poly2->varll, poly3ptr->varll))
               {
                    poly3ptr->data += poly2->data;
                    break;
               }
               if (poly3ptr->next == NULL)
               {
                    poly3ptr->next = createNode(poly2->data, poly2->varll);
                    break;
               }
               poly3ptr = poly3ptr->next;
          }

          poly2 = poly2->next;
     };
     display(poly3);
}

void sub(Node *poly1, Node *poly2)
{
     Node *poly3 = CopytoPoly3(poly1);

     int data;
     VarLL *varll;
     while (poly2 != NULL)
     {
          Node *poly3ptr = poly3;
          while (1)
          {
               if (varLLEqual(poly2->varll, poly3ptr->varll))
               {
                    poly3ptr->data -= poly2->data;
                    break;
               }
               if (poly3ptr->next == NULL)
               {
                    poly3ptr->next = createNode(poly2->data, poly2->varll);
                    break;
               }
               poly3ptr = poly3ptr->next;
          }

          poly2 = poly2->next;
     };
     display(poly3);
}

int main()
{
     int n1 = 0, n2 = 0;
     Node *poly1 = createLinkedList();
     Node *poly2 = createLinkedList();
     display(poly1);
     display(poly2);
     printf("Addition------\n");
     add(poly1, poly2);
     printf("Subtraction------\n");
     sub(poly1, poly2);
     printf("Multiplication------\n");
     mul(poly1, poly2);
}
