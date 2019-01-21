/*
 * Program to create a doubly linked list, and print it from the head first, then from tail
 */

#include <stdio.h>
#include <stdlib.h>

//function prototypes
struct Node* get_node(int x);
void insert_head(int x);
void print_list(void);
void reverse_print(void);

// struct for the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

int main(void)
{
    // test functions that print the list
    insert_head(1);
    insert_head(2);
    insert_head(3);
    insert_head(4);
    insert_head(5);
    insert_head(6);
    print_list();
    reverse_print();
}

struct Node* get_node(int x)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_head(int x)
{
    struct Node* new_node = get_node(x);
    if (head == NULL) {
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void print_list(void)
{
    struct Node* temp = head;
    printf("forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_print(void)
{
    struct Node* temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
    printf("backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
