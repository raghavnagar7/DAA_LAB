#include <stdio.h>

int isSubsetSumRec(int arr[], int n, int sum) {
    if (sum == 0) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    if (arr[n - 1] > sum) {
        return isSubsetSumRec(arr, n - 1, sum);
    }
    return isSubsetSumRec(arr, n - 1, sum) || isSubsetSumRec(arr, n - 1, 
sum - arr[n - 1]);
}

int isSubsetSum(int arr[], int n, int sum) {
    return isSubsetSumRec(arr, n, sum);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSubsetSum(arr, n, sum)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}


