template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
	
	// do not index past the root
	while(parent(i) >= 0){
		// compare node value to parent value
		if(data[i] < data[parent(i)]){			
			// swap values
			swap(data[i], data[parent(i)]);
			// update index
			i = parent(i);
		}
		else{
			return;
		}
	}
	return;
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
	
	int child = -1;
	// only attempt sift down when there is at least a left child (complete tree)
	while(left(i) < data.size()){
		child = (right(i) < data.size() && data.at(left(i)) > data.at(right(i))) ? right(i) : left(i);
		if(data[i] <= data[child]) return;
		else{
			swap(data[i], data[child]);		// swap values
			i = child;
		}
	}
	return;
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
	data.push_back(value); 		// insert to the last value
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.

	rootValue = data.at(0);					// update rootValue
	if(size() == 1){
		data.pop_back();
		return rootValue;
	}
	swap(data[0], data[size() - 1]); 	// swap root and last element
	data.pop_back();					// remove the last heap element
	siftDown(0);						// keep heap property
	return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

	// swap node at index with last leaf node
    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
	siftUp(index);
	siftDown(index);
}
