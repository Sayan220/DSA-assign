/*The problem can be solved using a 2D array in the following way:

1. Initialize a 2D boolean array to keep track of the status of each person (whether they are still in the circle or have been executed).

2. Initialize a counter variable to keep track of the number of people skipped.

3. Start iterating through the circle from the specified starting point in the specified direction.

4. At each person, check if they have already been executed. If they have, skip to the next person.

5. If they have not been executed, increment the counter variable.

6. If the counter variable is equal to the specified number of people to be skipped, mark the current person as executed in the boolean array and reset the counter variable to 0.

7. Repeat steps 3-6 until only one person remains in the circle (i.e., all other people have been executed).

8. The remaining person is the one to be freed.*/

#include <stdio.h>
int main() {
    const int N = 10; // number of people in the circle
    int circle[N][N]; // 2D array to keep track of people
    int start = 0; // starting point
    int direction = 1; // direction (1 = clockwise, -1 = counterclockwise)
    int skip = 3; // number of people to skip
    int skipped = 0; // counter variable
    int remaining = N; // number of people remaining in the circle

    // initialize the circle
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            circle[i][j] = 1;
        }
    }

    // iterate through the circle
    while (remaining > 1) {
        int i = start;
        int j = 0;
        while (j < N) {
            if (circle[i][j]) { // check if person is still in circle
                if (++skipped == skip) { // check if person should be executed
                    circle[i][j] = 0; // mark person as executed
                    skipped = 0; // reset counter
                    remaining--; // decrement number of people remaining
                }
            }
            j++;
            i = (i + direction + N) % N; // update index based on direction
        }
        start = i; // update starting point for next iteration
    }

    // find the remaining person
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (circle[i][j]) {
                printf("The person to be freed is at position (%d,%d)\n", i, j);
            }
        }
    }

    return 0;
}


//Note: This implementation assumes that the circle is represented as a 2D array of boolean values,
// where `true` indicates that the person is still in the circle and `false` indicates that they have been executed. 
//The starting point is represented by the row index of the array, and the direction is represented by a variable `direction` that is either 1 (for clockwise) or -1 (for counterclockwise).

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, m, i;
    printf("Enter the number of people standing in the circle: ");
    scanf("%d", &n);
    printf("Enter the number of people to be skipped: ");
    scanf("%d", &m);

    // create circular linked list
    struct node *head, *prev, *current;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = 1;
    prev = head;
    for (i = 2; i <= n; i++) {
        current = (struct node*) malloc(sizeof(struct node));
        current->data = i;
        prev->next = current;
        prev = current;
    }
    current->next = head; // make the list circular

    // execute people until only one person remains
    current = head;
    while (current->next != current) {
        // skip m-1 people
        for (i = 0; i < m-1; i++) {
            prev = current;
            current = current->next;
        }
        // execute the next person and remove them from the list
        prev->next = current->next;
        printf("Person %d has been executed.\n", current->data);
        free(current);
        current = prev->next;
    }
    printf("Person %d is freed.\n", current->data);
    free(current);
    return 0;
}




#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = tail = newnode;
        head->prev = tail;
        tail->next = head;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        tail->next = head;
        head->prev = tail;
    }
}

void delete(struct node *ptr) {
    if (head == NULL) {
        return;
    } else if (head == tail) {
        head = tail = NULL;
    } else if (ptr == head) {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    } else if (ptr == tail) {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
}

void execute(int start, int skip) {
    struct node *current = head;
    int count = 1;
    while (count != start) {
        current = current->next;
        count++;
    }
    while (head != tail) {
        count = 1;
        while (count != skip) {
            current = current->next;
            count++;
        }
        struct node *temp = current;
        current = current->next;
        delete(temp);
    }
    printf("The person to be freed is: %d\n", head->data);
}

int main() {
    int n, i, start, skip;
    printf("Enter the number of people in the circle: ");
    scanf("%d", &n);
    printf("Enter the starting position: ");
    scanf("%d", &start);
    printf("Enter the number of people to skip: ");
    scanf("%d", &skip);
    for (i = 1; i <= n; i++) {
        insert(i);
    }
    execute(start, skip);
    return 0;
}
