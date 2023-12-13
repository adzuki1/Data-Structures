#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int len);

int main()
{
    int len;
    
    cout << "Vector length: ";
    cin >> len;

    vector<int> arr(len);

    cout << "\nInsert list elements: " << endl;
    for(int i = 0; i < len; i++)
        cin >> arr[i];

    cout << "Original array: " << endl;
    for(int i = 0; i < len; i ++)
        cout << arr[i] << " ";

    selectionSort(arr, len);
    
    cout << "\nSorted array: " << endl;
    for(int i = 0; i < len; i ++)
        cout << arr[i] << " ";

    return 0;
}

void selectionSort(vector<int>& arr, int len)
{
  for(int i = 0; i < len-1; i++)
    {
      int min = i;
      for(int j = i+1; j < len; j++)
        {
          if(arr[min] > arr[j])
            min = j;
        }
      // swap 
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
}
