#include<stdio.h>
#define MAX_SIZE 100

void createArray(int arr[], int *size) {
    printf("Enter number of elements: ");
    scanf("%d", size);
    if (*size > MAX_SIZE) {
        printf("Size exceeds maximum\n");
        *size = 0;
        return;
    }
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++)
        scanf("%d", &arr[i]);
    printf("Array created successfully\n");
}

void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = *size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = element;
    (*size)++;
    printf("Element inserted\n");
}

int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;
    return -1;
}

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
    printf("Element deleted\n");
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, result;
    while (1) {
        printf("\nArray Operation Menu:\n");
        printf("1. Create Array\n");
        printf("2. Insert Element\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                result = searchElement(arr, size, element);
                if (result != -1)
                    printf("Element found at position: %d\n", result);
                else
                    printf("Element not found in the array\n");
                break;
            case 4:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 5:
                displayArray(arr, size);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
