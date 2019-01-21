/*
 * Program to implement a circular linked list
 */

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void insert(int x);
void print_list(void);
void circular_list(void);
void print_circular(void);
void insert_end(int x);
void insert_beginning(int x);

// struct for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head;
struct Node* last;

int main(void)
{
    head = NULL;
    int number;
    printf("Enter numbers to add to the beginning of the list\n");
    while (scanf("%d", &number) != EOF) {
        insert(number);
        print_list();
    }

    circular_list();
    printf("\n");
    printf("%d\n", last->data);
    int x = -21;
    insert_end(x);
    insert_beginning(-12);
    print_circular();

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

void circular_list(void)
{
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    last = temp;
}

void print_circular(void)
{
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

}

void insert_end(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = last->next;
    last->next = temp;
    last = temp;
}

void insert_beginning(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = last->next;
    last->next = temp;
    head = temp;
}
