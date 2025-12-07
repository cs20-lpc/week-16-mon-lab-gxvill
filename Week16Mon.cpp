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
    vector<int> arr = {5, 1, 9, 3, 7, 4};

    heapsort(arr);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
