#include <iostream>
using namespace std;

class MaxHeap {
private:
	int* heap;
	int size;
	int capacity;
public:
	MaxHeap(int inputCapacity) {
		capacity = inputCapacity;
		size = 0;
		heap = new int[capacity];
	}

	MaxHeap(int* inputHeap, int inputSize, int inputCapacity) {
		capacity = inputCapacity;
		size = inputSize;
		heap = new int[capacity];
		for (int i = 0; i < inputSize; i++) {
			heap[i] = inputHeap[i];
		}
	}

	int getSize() {return size;}

	int getCapacity() {return capacity;}

	int parentIndex(int i) {
		return (i-1)/2;
	}

	int leftChildIndex(int i) {
		return (2*i+1);
	}

	int rightChildIndex(int i) {
		return (2*i+2);
	}

	int getMax() {
		return heap[0];
	}

	int extractMax() {
		if (size == 0) {
			cout << "Heap is empty; unable to extract max\n";
			return -1;
		}

		// TO DO: implement extractMax
	}

	void insert(int val) {
		if (capacity == size) { 
        	cout << "Heap is full; unable to insert\n"; 
        	return; 
    	}

    	heap[size] = val;       // insert at next available position
    	size++;
    	
    	//bubble up to fix heap property
    	int current = size-1;
    	int parent = parentIndex(current);
    	int temp;
    	while (current > 0 && heap[current] > heap[parent]) {
    	    temp = heap[current];
    	    heap[current] = heap[parent];
    	    heap[parent] = temp;
    	    current = parent;
    	    parent = parentIndex(current);
    	}
    	return;
	}

	void printHeap() {
		int level = 1;
		int levelCount = 1;
		for (int i=0; i < size; i++) {
			cout << heap[i] << " ";
			if (levelCount == level) {
				cout << endl;
				level *= 2;
				levelCount = 1;
			}
			else {
				levelCount++;
			}
		}
		cout << endl;
	}
};

int main() {
	// testing insert
	
	MaxHeap heap1(7);           //heap is empty
	heap1.insert(5);
	heap1.printHeap();          // heap contains only 5
	
	int heapEntries2[] = {10,9,8,7,6,5,4,3,2,1};
	MaxHeap heap2(heapEntries2, 10, 15);
	heap2.printHeap();                 // heap has root 10, 10 has children 9 and 8, 9 has children 7 and 6
	                                    // 8 has children 5 and 4, 7 has children 3 and 2, 6 has child 1
	heap2.insert(11);
	heap2.printHeap();                 // heap has root 11, 11 has children 10 and 8, 10 has children 7 and 9,
	                                    // 8 has children 5 and 4, 7 has children 3 and 2, 9 has children 1 and 6
	                                    
	int heapEntries3[] = {10,9,8,6,5,4,3,2,1};
	MaxHeap heap3(heapEntries3, 9, 15);
	heap3.printHeap();                 // heap has root 10, 10 has children 9 and 8, 9 has children 6 and 5
	                                    // 8 has children 4 and 3, 6 has children 2 and 1
	heap3.insert(7);
	heap3.printHeap();                  // heap has root 10, 10 has children 9 and 8, 9 has children 6 and 7
	                                    // 8 has children 4 and 3, 6 has children 2 and 1, 7 has child 5
	                                    
	int heapEntries4[] = {10,7,8,6,5,4,3,2,1};
	MaxHeap heap4(heapEntries4, 9, 15);
	heap4.printHeap();                 // heap has root 10, 10 has children 7 and 8, 7 has children 6 and 5
	                                    // 8 has children 4 and 3, 6 has children 2 and 1
	heap4.insert(9);
	heap4.printHeap();                  // heap has root 10, 10 has children 9 and 8, 9 has children 6 and 7
	                                    // 8 has children 4 and 3, 6 has children 2 and 1, 7 has child 5
	                                    
    int heapEntries5[] = {3,2,1};
	MaxHeap heap5(heapEntries5, 3, 15);
	heap5.printHeap();                  // heap has root 3, 3 has children 2 and 1
	heap5.insert(10);
	heap5.printHeap();                  //heap has root 10, 10 has children 3 and 1, 3 has child 2
	
}