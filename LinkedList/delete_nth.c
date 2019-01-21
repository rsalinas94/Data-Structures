/*
 * Program to implement a linked list and delete the nth node
 */

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void insert(int x);
void print_list(void);
void delete(int n);

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
        print_list();
        i++;
    }

    printf("Enter the position of the node you would like to delete until list is empty or EOF\n");

    i = 0;
    while (i < length && scanf("%d", &number) != EOF) {
        delete(number);
        print_list();
        i++;
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

void delete(int n)
{
    struct Node* temp = head;
    if (n == 1) {
        head = temp->next;
        free(temp);
    } else {
        for (int i = 1; i < n - 1; i++)
            temp = temp->next;
        struct Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }

}
