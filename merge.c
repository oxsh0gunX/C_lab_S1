#include <stdio.h>

int main() {
    int arr1[] = {1, 5, 7};
    int arr2[] = {2, 4, 6};
    int n1 = 3, n2 = 3;
    int merged[6];
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while(j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    for(int m = 0; m < n1 + n2; m++) {
        printf("%d ", merged[m]);
    }

    return 0;
}
