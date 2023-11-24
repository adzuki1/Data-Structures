/*
HEAP: lista linear sequencial que obedece a propriedade
em que Vi <= Vfloor(i/2)-1,
para 1 < i <= n
*/
#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(vector<int>& arr, int i){
    int j = i/2;

    if(j >= 0)
        if(arr[i] > arr[j]){
            swap(&arr[i], &arr[j]);
            heapifyUp(arr, j);
        }
}

void heapifyDown(vector<int>& arr, int length, int i){
// Zero-based array
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < length && arr[left] > arr[largest])
        largest = left;

    if(right < length && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapifyDown(arr, length, largest);
    }
}

void insert(vector<int>& arr, int n, int* t){
    *t = *t + 1;
    arr[*t] = n;
    heapifyUp(arr, *t);
}

void remove(vector<int>& arr, int* length){
    arr[0] = arr[*length];
    *length = *length - 1;
    heapifyDown(arr, 0, *length);
}

void heapSort(vector<int>& arr){
    int n = arr.size();

    // Build max heap
    for(int i = n / 2 - 1; i >= 0; --i){
        heapifyDown(arr, n, i);
    }

    // Extract elements from the heap
    for(int i = n - 1; i > 0; --i){
        swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }

    heapSort(arr);

    cout << "\nSorted array: ";
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }

    return 0;
}