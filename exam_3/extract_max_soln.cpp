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

		int max = heap[0];          // will return this at the end
		heap[0] = heap[size-1];     // replace max with last item in the heap
		size--;
		
		// bubble down to fix heap property
		int current = 0;
		int left = leftChildIndex(current);
		int right = rightChildIndex(current);
		int temp;
		while (left < size) {
		    if (right < size) {
		        if (heap[left] > heap[right] && heap[current] < heap[left]) {
		            temp = heap[current];
		            heap[current] = heap[left];
		            heap[left] = temp;
		            current = left;
		        }
		        else if (heap[current] < heap[right]) {
		            temp = heap[current];
		            heap[current] = heap[right];
		            heap[right] = temp;
		            current = right;
		        }
		        else { break; }
		    }
		    else {
		        if (heap[current] < heap[left]) {
		            temp = heap[current];
		            heap[current] = heap[left];
		            heap[left] = temp;
		            current = left;
		        }
		        else { break; }
		    }
		    left = leftChildIndex(current);
		    right = rightChildIndex(current);
		}
		return max;
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
	// test extractMax
	
	int heapEntries1[] = {7};
	MaxHeap heap1(heapEntries1, 1, 8);
	heap1.printHeap();      // heap is just 7
	cout << heap1.extractMax() << endl;     // returns 7
	heap1.printHeap();         // heap is empty
	
	int heapEntries2[] = {10,9,8,7,6,5,4,3,2,1};
	MaxHeap heap2(heapEntries2, 10, 15);
	heap2.printHeap();                 // heap has root 10, 10 has children 9 and 8, 9 has children 7 and 6
	                                    // 8 has children 5 and 4, 7 has children 3 and 2, 6 has child 1
	cout << heap2.extractMax() << endl;     // returns 10
	heap2.printHeap();                  // heap has root 9, 9 has children 7 and 8, 7 has children 3 and 6,
	                                    // 8 has children 5 and 4, 3 has children 1 and 2
	
	int heapEntries3[] = {7,6,5,1,2,3,4};
	MaxHeap heap3(heapEntries3, 7, 7);
	heap3.printHeap();                 // heap has root 7, 7 has children 6 and 5, 6 has children 1 and 2,
	                                    // 5 has children 3 and 4
	cout << heap3.extractMax() << endl;     // returns 7
	heap3.printHeap();                 //heap has root 6, 6 has children 4 and 5, 4 has children 1 and 2,
	                                    // 5 has child 3
}