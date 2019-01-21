/*
 * Program to implement a linked list and add a number at the nth position
 * of the list
 */

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void insert(int number, int position);
void print_list(void);

// struct for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

int main(void)
{
    head = NULL;
    printf("Enter numbers and position to add to the list:\n");

    int number, position;
    while (scanf("%d %d", &number, &position) == 2) {
        insert(number, position);
        print_list();
    }

    return 0;
}

void insert(int number, int position)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = number;

    if (position == 1) {
        temp->next = head;
        head = temp;
    }
    else {
        struct Node* traverse = head;
        for (int i = 1; i < position - 1; i++) {
            traverse = traverse->next;
        }
        temp->next = traverse->next;
        traverse->next = temp;
    }
}

void print_list(void)
{
    struct Node* temp = head;
    printf("current list: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
