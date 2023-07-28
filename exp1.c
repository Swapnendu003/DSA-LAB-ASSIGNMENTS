#include <stdio.h>

int main() {
    // Step 1: Get the size of the array from the user
    int array_size;
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    // Step 2: Create a fixed-size 1D array with user input elements
    int my_array[array_size];

    printf("Enter %d elements of the array:\n", array_size);
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &my_array[i]);
    }

    // Step 3: Insert a new element at a specific position in the array
    int element_to_insert, position_to_insert;
    printf("Enter the element to insert: ");
    scanf("%d", &element_to_insert);

    printf("Enter the position to insert (0-indexed): ");
    scanf("%d", &position_to_insert);

    // Shift elements to the right to make space for the new element
    for (int i = array_size - 1; i > position_to_insert; i--) {
        my_array[i] = my_array[i - 1];
    }

    // Insert the new element at the specified position
    my_array[position_to_insert] = element_to_insert;

    // Update the array size after insertion
    array_size++;

    // Print the updated array
    printf("Updated Array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }

    return 0;
}
