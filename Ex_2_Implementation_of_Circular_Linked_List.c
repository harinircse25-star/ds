#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} CircularLinkedList;

void initCircularLinkedList(CircularLinkedList *list) {
    list->head = NULL;
}

void addCircular(CircularLinkedList *list, int element) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = element;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        new_node->next = list->head;
    } else {
        Node *current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = list->head;
    }
}

void removeCircular(CircularLinkedList *list, int element) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *current = list->head;
    Node *prev = NULL;
    do {
        if (current->data == element) {
            if (current == list->head && current->next == list->head) {
                list->head = NULL;
                free(current);
                return;
            }
            if (current == list->head) {
                Node *last = list->head;
                while (last->next != list->head)
                    last = last->next;
                list->head = current->next;
                last->next = list->head;
                free(current);
                return;
            }
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != list->head);
    printf("Element not found\n");
}

void displayCircular(CircularLinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *current = list->head;
    printf("Circular List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

int main() {
    CircularLinkedList list;
    initCircularLinkedList(&list);
    int choice, element;
    while (1) {
        printf("\n1. Add\n2. Remove\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                addCircular(&list, element);
                break;
            case 2:
                printf("Enter element to remove: ");
                scanf("%d", &element);
                removeCircular(&list, element);
                break;
            case 3:
                displayCircular(&list);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
