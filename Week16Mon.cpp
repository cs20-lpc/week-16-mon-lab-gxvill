#include <iostream>
#include "MinHeap.hpp"
using namespace std;

// Use a MinHeap to sort ascending
template <typename T>
void heapsort(vector<T>& arr) {
    MinHeap<T> h;

    // TODO: Insert all elements into heap using sift-down insert from lecture
	
	// insert elements as is
	for(T e : arr){
		h.insert(e);
	}

	for(int i = (h.size()/2) - 1; i >= 0; i--){
		h.siftDown(i);
	}

	arr.clear();
	
    // TODO: Repeatedly remove root and store back into array
	while(h.size() > 0){
		arr.push_back(h.removeRoot());
	}
}

int main() {
    vector<int> arr = {100, 5, 1, 70, 9, 21, 12, 18, 3, 7, 4, 10, 2, 11, 22, 0, 50};

	cout << "Initial Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    heapsort(arr);

	cout << "Heap Sorted Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
