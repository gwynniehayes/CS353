#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;
using namespace std::chrono;

// Set up random number generator
random_device rd;										//seed random number generator
mt19937 gen(rd());										//use Mersenne-Twister
uniform_int_distribution<> distrib(-1000, 1000);		//random number generator gives random integer between -1000 and 1000

// FUNCTIONS FOR SORTING //////////////////////////////////////////////////////////////////////////////////////

int min_index(int arr[], int size) {
	// helper function for sort
	// arguments: (nonempty) array of integers (arr), number of items in array (size)
	// returns: the index of the minimum value in the array

	int i = 0;
	for (int j = 1; j < size; j++){
		if (arr[j] < arr[i])
			i = j;
	}
	return i;
}

void remove_by_index(int arr[], int i, int size) {
	// helper function for sort
	// arguments: array of integers (arr), index (i), and the number of items in array (size)
	// state change: removes the index i item from the array;
	//	index i of the array is replaced with the value from index i+1,
	//	index i+1 of the array is replaced with the value from index i+2,
	//	and so on until we get to the end of the array.
	// returns: none

	for (int index = i+1; index < size; index++)
		arr[index - 1] = arr[index];
	return;
}

void selection_sort(int arr[], int n) {
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the remaining unsorted array
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[min], arr[i]);
    }
}

// FUNCTIONS FOR TESTING //////////////////////////////////////////////////////////////////////////////////////

bool array_equals(int arr1[], int n1, int arr2[], int n2){
	//helper function: takes two arrays, and returns true if they have the exact same items, otherwise returns false
	if (n1 != n2)
		return false;
	for (int i = 0; i < n1; i++){
		if (arr1[i] != arr2[i]){
			return false;
		}
	}
	return true;
}

void test(void (*func)(int*, int)){		//note that this takes a function (intended to be your sorting function) as an argument
	bool pass = true;

	int test1[5] = {1, 4, 2, 3, 5};
	int test1_ans[5] = {1, 2, 3, 4, 5};
	func(test1, 5);
	if (!array_equals(test1, 5, test1_ans, 5)) {
		cout << "Test 1 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 1 passed" << endl;

	// TODO: more tests here
	int test2[5] = {3, 72, 8, 27, 94};
	int test2_ans[5] = {3, 8, 27, 72, 94};
	func(test2, 5);
	if (!array_equals(test2, 5, test2_ans, 5)) {
		cout << "Test 2 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 2 passed" << endl;

	int test3[5] = {67, 82, 44, 3, 52};
	int test3_ans[5] = {3, 44, 52, 67, 82};
	func(test3, 5);
	if (!array_equals(test3, 5, test3_ans, 5)) {
		cout << "Test 3 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 3 passed" << endl;

	int test4[5] = {9, 7, 3, 0, 1};
	int test4_ans[5] = {0, 1, 3, 7, 9};
	func(test4, 5);
	if (!array_equals(test1, 5, test1_ans, 5)) {
		cout << "Test 4 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 4 passed" << endl;

	int test5[5] = {73, 1431, 8, 0, 603};
	int test5_ans[5] = {0, 8, 73, 603, 1431};
	func(test5, 5);
	if (!array_equals(test5, 5, test5_ans, 5)) {
		cout << "Test 5 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 5 passed" << endl;

	int test6[5] = {4, 4, 4, -4, 4};
	int test6_ans[5] = {-4, 4, 4, 4, 4};
	func(test6, 5);
	if (!array_equals(test6, 5, test6_ans, 5)) {
		cout << "Test 6 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 6 passed" << endl;

	int test7[5] = {16, 22, 51, 1, 12};
	int test7_ans[5] = {1, 12, 16, 22, 51};
	func(test7, 5);
	if (!array_equals(test7, 5, test7_ans, 5)) {
		cout << "Test 7 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 7 passed" << endl;

	int test8[5] = {6, 8, 200, 3331, 66};
	int test8_ans[5] = {6, 8, 66, 200, 3331};
	func(test7, 5);
	if (!array_equals(test8, 5, test8_ans, 5)) {
		cout << "Test 8 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 8 passed" << endl;

	int test9[5] = {1, 27, 99, 12844, 1};
	int test9_ans[5] = {1, 1, 27, 99, 12844};
	func(test9, 5);
	if (!array_equals(test9, 5, test9_ans, 5)) {
		cout << "Test 9 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 9 passed" << endl;

	int test10[5] = {6470, 50, 77, -1234, 129};
	int test10_ans[5] = {-1234, 50, 77, 129, 6470};
	func(test10, 5);
	if (!array_equals(test10, 5, test10_ans, 5)) {
		cout << "Test 10 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 10 passed" << endl;

	if (pass) {
		cout << "All tests passed!" << endl;
	}
	return;
}

// FUNCTIONS FOR TIMING EXPERIMENT //////////////////////////////////////////////////////////////////////////////////////

int* make_array(int size){
	// helper function for timing experiment
	// argument: an integer (size)
	// returns: an array with number of items given by size. Contains random numbers.	
    
    int* array = new int[size];
    for (int i = 0; i < size; i++) 
    	array[i] = distrib(gen);			// use random number generator to assign array items
    return array;
}

int time(int arr[], int size, void (*func)(int*, int)){
	// helper function for timing experiment
	// arguments: array of integers (arr), number of items in array (size), pointer to a function that takes the array and size
	// calls the function (intended for sort) on the array and size, and returns the time taken by this function call (in nanoseconds)

    auto start = high_resolution_clock::now();		//note: if this isn't working for you, try steady_clock instead.
    func(arr, size);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(stop - start);
	return duration.count();
}

int avg_time(int size, void (*func)(int*, int), int trials){
	// helper function for timing experiment
	// arguments: integer (size), function to time (intended for sort), integer for number of trials (trials)
    // times the function called on arrays of given size, averages over number of trials given by trials.

    int total_time = 0;
    for (int i = 0; i < trials; i++){			// repeat for number of trials
        int* arr = make_array(size);			// make array to sort
        total_time += time(arr, size, func);  	// time call on array, add to total time
        delete [] arr;							
    }
    
    return total_time / trials;
}

// MAIN //////////////////////////////////////////////////////////////////////////////////////

int main() {
	// Call the test function
	cout << "Running tests:" << endl;
	test(selection_sort);

	// these variable determine what sizes of arrays we test, and the number of trials
	int max_size = 1000;
    int interval = 10;
    int num_trials = 1000;

    // results of timing are written to the file sort_runtimes.csv
    ofstream my_file;
    my_file.open("sortinplace_runtimes.csv");
    my_file << "size, time\n";			// header for csv file: column names are size, time

    for (int size = 0; size < max_size; size += interval){		// for each size
        int time = avg_time(size, selection_sort, num_trials);			// compute average time for function call on array of that size
        my_file << size << "," << time << "\n";					// write result to the csv file
        cout << "Time taken by function on array size " << size << ": "
         << time << " nanoseconds" << endl;						// print the result as well
    }

    my_file.close();

    return 0;
}