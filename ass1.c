#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insertElement(int **arr, int *size, int element);
void deleteElement(int **arr, int *size, int element);
int linearSearch(int *arr, int size, int element);
void displayArray(int *arr, int size);

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n------- Menu -------\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear search\n");
        printf("4. Display array\n");
        printf("5. Exit\n");
        printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(&arr, &size, element);
                break;

            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(&arr, &size, element);
                break;

            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                int position = linearSearch(arr, size, element);
                if (position == -1) {
                    printf("Element not found in the array.\n");
                } else {
                    printf("Element found at index %d.\n", position);
                }
                break;

            case 4:
                displayArray(arr, size);
                break;

            case 5:
                // Free dynamically allocated memory before exiting
                free(arr);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void insertElement(int **arr, int *size, int element) {
    (*size)++;
    *arr = (int*)realloc(*arr, (*size) * sizeof(int));
    (*arr)[(*size) - 1] = element;
    printf("Element inserted successfully.\n");
}

void deleteElement(int **arr, int *size, int element) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if ((*arr)[i] == element) {
            for (int j = i; j < (*size) - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*size)--;
            *arr = (int*)realloc(*arr, (*size) * sizeof(int));
            found = 1;
            printf("Element deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}

int linearSearch(int *arr, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

void displayArray(int *arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
