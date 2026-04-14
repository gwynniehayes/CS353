#include <iostream>
using namespace std;

class MaxHeap {
private:
	int* heap;
	int size;
	int capacity;

	void heapifyUp(int index) {
		while (index > 0) {
			int parent = parentIndex(index);
			if (heap[index] > heap[parent]) {
				swap(heap[index], heap[parent]);
				index = parent;
			} else {
				break;
			}
		}
	}

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

	int getSize() { return size; }

	int getCapacity() { return capacity; }

	int parentIndex(int i) { return (i - 1) / 2; }

	int leftChildIndex(int i) { return (2 * i + 1); }

	int rightChildIndex(int i) { return (2 * i + 2); }

	int getMax() { return heap[0]; }

	void insert(int val) {
		if (size == capacity) {
			cout << "Heap is full; unable to insert\n";
			return;
		}

		// Step 1: Add at the end
		heap[size] = val;
		size++;

		// Step 2: Bubble up
		heapifyUp(size - 1);
	}

	void printHeap() {
		int level = 1;
		int levelCount = 1;
		for (int i = 0; i < size; i++) {
			cout << heap[i] << " ";
			if (levelCount == level) {
				cout << endl;
				level *= 2;
				levelCount = 1;
			} else {
				levelCount++;
			}
		}
		cout << endl;
	}
};

int main() {
	// ================================
	// Test 1: Insert into empty heap
	// Before: []
	// After: [10]
	MaxHeap heap1(10);
	cout << "Test 1: Insert 10 into empty heap\n";
	heap1.insert(10);
	heap1.printHeap();

	// ================================
	// Test 2: Insert into heap with 10+ items
	int arr2[10] = {50, 30, 40, 10, 20, 35, 25, 5, 8, 15};
	MaxHeap heap2(arr2, 10, 15);
	cout << "Test 2: Before inserting 28 into heap with 10 items\n";
	heap2.printHeap();
	heap2.insert(28);
	// After: 28 should bubble up appropriately, max remains 50
	cout << "After inserting 28:\n";
	heap2.printHeap();

	// ================================
	// Test 3: Insert bigger than current max
	// Before: [50,...]
	// Insert: 60
	// After: 60 should become new max
	cout << "Test 3: Insert 60, bigger than current max\n";
	heap2.insert(60);
	heap2.printHeap();

	// ================================
	// Test 4: Insert smaller than current max
	// Before: max=60
	// Insert: 12
	// After: max=60 still, 12 placed appropriately
	cout << "Test 4: Insert 12, smaller than current max\n";
	heap2.insert(12);
	heap2.printHeap();

	// ================================
	// Test 5: Insert at the end to trigger bubbling up partially
	// Insert: 45
	cout << "Test 5: Insert 45\n";
	heap2.insert(45);
	heap2.printHeap();
}