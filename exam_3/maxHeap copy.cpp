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

    	// TO DO: implement insert
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
	// TO DO: test extractMAx or insert
}