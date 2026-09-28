#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 3

struct node {
    int data;
    struct node *next;
};

struct node *head[TABLE_SIZE] = {NULL};

void insert(int val) {
    int i = val % TABLE_SIZE;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->data = val;
    newnode->next = NULL;
    if (head[i] == NULL) {
        head[i] = newnode;
    }
    else {
        struct node *c = head[i];
        while (c->next != NULL) {
            c = c->next;
        }
        c->next = newnode;
    }
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("\nBucket %d: ", i);
        struct node *c = head[i];
        while (c != NULL) {
            printf("%d -> ", c->data);
            c = c->next;
        }
        printf("NULL");
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
