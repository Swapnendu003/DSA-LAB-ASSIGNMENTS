#include <stdio.h>
#include <stdlib.h>

int main() {
    int array_size;

   
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    
    int* my_array = (int*)malloc(array_size * sizeof(int));

    
    if (my_array == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;
    }

    // Step 4: Input the elements for the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &my_array[i]);
    }

 
    printf("Array elements:\n");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");


    free(my_array);

    return 0;
}
