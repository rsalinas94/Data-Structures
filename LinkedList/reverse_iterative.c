/*
 * Program to reverse a linked list
 */

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void reverse(void);
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
    printf("Enter how many numbers to add to the end of the list, followed by the numbers themselves.\n");

    int length, number;
    scanf("%d", &length);
    int i = 0;
    while (i < length){
        scanf("%d", &number);
        insert(number);
        i++;
    }

    printf("List: ");
    print_list();
    printf("Reversed list: ");
    reverse();
    print_list();

    return 0;
}

void reverse(void)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
