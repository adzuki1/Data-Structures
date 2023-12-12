#include <iostream>
using namespace std;

void swap(int &a, int &b);
void bubbleSort(int arr[], int len);

int main()
{
  int arr[] = {4, 3, 5, 6, 2};
  int len = sizeof(arr) / sizeof(arr[0]);

  cout << "original array: ";
  for(int i = 0; i < len; ++i)
  {
    cout << arr[i] << ' ';
  }
  cout << "\n";

  bubbleSort(arr, len);

  cout << "sorted: ";
  for(int j = 0; j < len; ++j)
  {
    cout << arr[j] << ' ';
  }
  
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int arr[], int len)
{
  for(int i = 0; i < len-1; ++i)
  {
    for(int j = i+1; j < len; ++j)
    {
      if(arr[i] > arr[j])
      {
        swap(arr[i], arr[j]);
      }
    }
  }
}
