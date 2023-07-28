#include <stdio.h>
#include <stdlib.h>

int main() {
    int *my_array = NULL; // Initialize the pointer to NULL
    int array_size = 0;   // Initialize the size of the array

    // Function to print the array
    void printArray() 
    {
        printf("Array: ");
        for (int i = 0; i < array_size; i++) {
            printf("%d ", my_array[i]);
        }
        printf("\n");
    }

    // Function to insert an element into the array
    void insertElement(int element, int position) {
        // Check if position is valid
        if (position < 0 || position > array_size) {
            printf("Invalid position for insertion.\n");
            return;
        }

        // Increase the size of the array
        array_size++;
        my_array = (int *)realloc(my_array, array_size * sizeof(int));

        // Shift elements to the right to make space for the new element
        for (int i = array_size - 1; i > position; i--) {
            my_array[i] = my_array[i - 1];
        }

        // Insert the new element at the specified position
        my_array[position] = element;
        printf("Element %d inserted successfully.\n", element);
    }

    // Function to delete an element from the array
    void deleteElement(int position) {
        // Check if position is valid
        if (position < 0 || position >= array_size) {
            printf("Invalid position for deletion.\n");
            return;
        }

        // Shift elements to the left to remove the element
        for (int i = position; i < array_size - 1; i++) {
            my_array[i] = my_array[i + 1];
        }

        // Decrease the size of the array
        array_size--;
        my_array = (int *)realloc(my_array, array_size * sizeof(int));
        printf("Element at position %d deleted successfully.\n", position);
    }

    // Step 1: Get the size of the array from the user
    printf("Enter the initial size of the array: ");
    scanf("%d", &array_size);

    // Step 2: Create a 1D array (dynamic memory allocation) with user input elements
    my_array = (int *)malloc(array_size * sizeof(int));
    printf("Enter %d elements of the array:\n", array_size);
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &my_array[i]);
    }

    // Step 3: Print the initial array
    printf("Initial ");
    printArray();

    // Step 4: Allow the user to insert elements
    int element_to_insert, position_to_insert;
    printf("Enter the element to insert: ");
    scanf("%d", &element_to_insert);

    printf("Enter the position to insert (0-indexed): ");
    scanf("%d", &position_to_insert);

    insertElement(element_to_insert, position_to_insert);
    printArray();

    // Step 5: Allow the user to delete elements
    int position_to_delete;
    printf("Enter the position to delete (0-indexed): ");
    scanf("%d", &position_to_delete);

    deleteElement(position_to_delete);
    printArray();

    // Step 6: Free dynamically allocated memory
    free(my_array);

    return 0;
}
