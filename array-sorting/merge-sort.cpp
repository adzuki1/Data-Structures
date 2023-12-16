#include <iostream>
#include <cstdio>
using namespace std;

void merge(int arr[], int lft, int mid, int rgt);
void mergeSort(int arr[], int start, int end);

int main(){
    int len;
    
    cout << "Array length: ";
    cin >> len;

    int arr[len];

    cout << "\nInsert list elements: " << endl;
    for(int i = 0; i < len; ++i)
        cin >> arr[i];

    cout << "Original array: " << endl;
    for(int i = 0; i < len; ++i)
        cout << arr[i] << " ";

    mergeSort(arr, 0, len);
    
    cout << "\nSorted array: " << endl;
    for(int i = 0; i < len; i ++)
        cout << arr[i] << " ";

    return 0;
    return 0;
}

void merge(int arr[], int lft, int mid, int rgt) {   
    // indexes
    int i, j, k;
    int n1 = mid - lft + 1;
    int n2 = rgt - mid;

    // auxilliary arrays
    int A_aux[n1], B_aux[n2];

    for(i = 0; i < n1; ++i)
    {
        A_aux[i] = arr[lft+i];
    }
    for(j = 0; j < n2; ++j)
    {
        B_aux[j] = arr[mid+1+j];
    }

    i = 0, j = 0;
    k = lft;

    while(i < n1 && j < n2)
    {
        if(A_aux[i] <= B_aux[j])
        {
            arr[k] = A_aux[i];
            ++i;
        }
        else{
            arr[k] = B_aux[j];
            ++j;}
        ++k;
    }
    while(i < n1)
    {
        arr[k] = A_aux[i];
        ++i, ++k;
    }
    while(j < n2)
    {
        arr[k] = B_aux[j];
        ++j, ++k;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if( start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
    return;
}