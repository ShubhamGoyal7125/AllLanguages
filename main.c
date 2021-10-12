#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int l, int m, int r)
{
    //Create L ← A[l..m] and M ← A[m+1..r]
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], M[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        M[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of M[], if there are any
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r){
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}

void printArray(int A[], int Size){//Prints the array
    int i;
    for (i = 0; i < Size; i++)printf("%d ", A[i]);
    printf("\n");
}

int main(void)
{
    int n;
    printf("Write value of n : ");
    scanf("%d",&n);
    int arr[n];
    printf("Write some numbers to be sorted \n");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    printf("Array before sorting: \n");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}
