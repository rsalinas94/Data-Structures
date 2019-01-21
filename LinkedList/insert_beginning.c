/*
 * Program to implement a linked list and add a number at the beginning of the list
 */

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void insert(int x);
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
    int number;
    printf("Enter numbers to add to the beginning of the list\n");
    while (scanf("%d", &number) != EOF) {
        insert(number);
        print_list();
    }

    return 0;
}

void insert(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
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
