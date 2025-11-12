#include <stdio.h>

int main() {
    int arr[100], n, i, pos;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Elements after the Insertion");
    for (i = 0; i < n; i++) {
          printf("%d", arr[i]);
   }
   printf("\n");    
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
    } else {
        
        for (i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; 

        
        printf("Array after deletion oparation : ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
