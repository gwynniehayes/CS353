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
		(i - 1)/2;
		return 0;
	}

	int leftChildIndex(int i) {
		2 * i + 1;
		return 0;
	}

	int rightChildIndex(int i) {
		2 * i + 2;
		return 0;
	}

	int getMax() {
		if (size == 0){
			cout << "Heap is empty";
			return -1;
		}
		return heap[0];
	}

	int extractMax() {
    if (size == 0) {
        cout << "Heap is empty; unable to extract max\n";
        return -1;
    }

    int maxValue = heap[0];          
    heap[0] = heap[size - 1];         
    size--;                          

    int current = 0;
    int left = leftChildIndex(current);
    int right = rightChildIndex(current);

    while ((left < size && heap[left] > heap[current]) || 
           (right < size && heap[right] > heap[current])) {

        if (right >= size || heap[left] > heap[right]) {
            swap(heap[current], heap[left]);
            current = left;
        } else {
            swap(heap[current], heap[right]);
            current = right;
        }

        left = leftChildIndex(current);
        right = rightChildIndex(current);
    }

    return maxValue;
}

	void insert(int val) {
    if (size == capacity) { 
        cout << "Heap is full; unable to insert\n"; 
        return; 
    }

    heap[size] = val;  
    size++;

    int current = size - 1;
    int parent = parentIndex(current);

    while (current > 0 && heap[parent] < heap[current]) {
        swap(heap[parent], heap[current]);
        current = parent;
        parent = parentIndex(current);
    }
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
	int heapEntries[] = {7,6,5,4,3,2,1};
	MaxHeap testHeap(heapEntries, 7, 15);

	cout << "The heap entries are:\n";
	testHeap.printHeap();
	cout << endl;

	for (int i = 1; i <= 6; i++) {
		cout << "The parent of index " << i << " is at index " << testHeap.parentIndex(i) << endl;
	}
	for (int i = 0; i <= 2; i++) {
		cout << "The left child of index " << i << " is at index " << testHeap.leftChildIndex(i) << endl;
		cout << "The right child of index " << i << " is at index " << testHeap.rightChildIndex(i) << endl;
	}
	cout << endl;

	cout << "The maximum value in the heap is " << testHeap.getMax() << endl << endl;

	testHeap.insert(10);
	cout << "After inserting 10, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(15);
	cout << "After inserting 15, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(12);
	cout << "After inserting 12, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(9);
	cout << "After inserting 9, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	testHeap.insert(14);
	cout << "After inserting 14, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(18);
	cout << "After inserting 18, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	testHeap.insert(11);
	cout << "After inserting 11, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	testHeap.insert(20);
	cout << "After inserting 20, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();
}