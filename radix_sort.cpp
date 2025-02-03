#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get the maximum element in the array
int getMax( vector<int>& arr ){
    return *max_element( arr.begin(), arr.end() );
}

// Counting Sort used in Radix Sort
void countingSort( vector<int>& arr, int exp ){
    int n = arr.size();
    vector<int> output( n );
    int count[10] = { 0 };

    for( int i = 0 ; i < n ; i++ )
        count[( arr[i] / exp ) % 10]++;

    for( int i = 1 ; i < 10 ; i++ )
        count[i] += count[i - 1];

    for( int i = n - 1 ; i >= 0 ; i-- ){
        output[count[( arr[i] / exp ) % 10] - 1] = arr[i];
        count[( arr[i] / exp ) % 10]--;
    }

    for( int i = 0 ; i < n ; i++ )
        arr[i] = output[i];
}

// Radix Sort function
void radixSort( vector<int>& arr ){
    int maxNum = getMax( arr );

    for( int exp = 1 ; maxNum / exp > 0 ; exp *= 10 )
        countingSort( arr, exp );
}

// Driver Code
int main(){
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    radixSort( arr );

    cout << "Sorted Array: ";
    for( int num : arr )
        cout << num << " ";
    cout << endl;

    return 0;
}
