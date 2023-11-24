/*
HEAP: lista linear sequencial que obedece a propriedade
em que Vi <= Vfloor(i/2)-1,
para 1 < i <= n
*/
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();

    // Build max heap
    for(int i = n / 2 - 1; i >= 0; --i){
        heapify(arr, n, i);
    }

    // Extract elements from the heap
    for(int i = n - 1; i > 0; --i){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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