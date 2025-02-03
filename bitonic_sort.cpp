#include <iostream>
#include <vector>

using namespace std;

// Function to compare and swap elements
void compareAndSwap( vector<int>& arr, int i, int j, bool ascending ){
    if( ( ascending && arr[i] > arr[j] ) || ( !ascending && arr[i] < arr[j] ) )
        swap(arr[i], arr[j] );
}

// Function to generate a bitonic sequence
void bitonicMerge( vector<int>& arr, int low, int count, bool ascending ){
    if( count > 1 ){
        int mid = count / 2;
        for( int i = low ; i < low + mid ; i++ )
            compareAndSwap( arr, i, i + mid, ascending );

        bitonicMerge( arr, low, mid, ascending );
        bitonicMerge( arr, low + mid, mid, ascending );
    }
}

// Recursive function for Bitonic Sort
void bitonicSort( vector<int>& arr, int low, int count, bool ascending ){
    if( count > 1 ){
        int mid = count / 2;

        bitonicSort( arr, low, mid, true );
        bitonicSort( arr, low + mid, mid, false );

        bitonicMerge( arr, low, count, ascending );
    }
}

// Wrapper function for Bitonic Sort
void bitonicSort( vector<int>& arr ){
    bitonicSort( arr, 0, arr.size(), true );
}

// Driver Code
int main() {
    vector<int> arr = { 3, 7, 4, 8, 6, 2, 1, 5 };  
    bitonicSort( arr );

    cout << "Sorted Array: ";
    for( int num : arr )
        cout << num << " ";
    cout << endl;

    return 0;
}
