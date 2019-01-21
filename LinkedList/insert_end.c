/*
 * Program to implement a linked list and add a number at the end of the list
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
    printf("Enter numbers to add to the end of the list\n");

    int number;
    while (scanf("%d", &number) != EOF){
        insert(number);
        print_list();
    }

    return 0;
}

void insert(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct Node* traverse;
        traverse = head;
        while (traverse->next != NULL) {
            traverse = traverse->next;
        }
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
