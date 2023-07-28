#include <stdio.h>
#include <stdlib.h>

int main() {

    int array_size;
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    
    int* my_array = (int*)malloc(array_size * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &my_array[i]);
    }


    int element_to_delete;
    printf("Enter the element to delete: ");
    scanf("%d", &element_to_delete);

   
    int index_to_delete = -1;
    for (int i = 0; i < array_size; i++) {
        if (my_array[i] == element_to_delete) {
            index_to_delete = i;
            break;
        }
    }

    
    if (index_to_delete != -1) {
        for (int i = index_to_delete; i < array_size - 1; i++) {
            my_array[i] = my_array[i + 1];
        }
        array_size--; 
        printf("Element %d is deleted from the array.\n", element_to_delete);
    } else {
        printf("Element %d is not found in the array.\n", element_to_delete);
    }


    printf("Updated Array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }

    free(my_array);

    return 0;
}
