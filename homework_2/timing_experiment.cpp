#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

#include "selection_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "stooge_sort.h"

using namespace std;
using namespace std::chrono;

// Set up random number generator
random_device rd;										//seed random number generator
mt19937 gen(rd());										//use Mersenne-Twister
uniform_int_distribution<> distrib(-1000, 1000);		//random number generator gives random integer between -1000 and 1000

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

	int test2[0] = {};
	int test2_ans[0] = {};
	func(test2, 0);
	if (!array_equals(test2, 0, test2_ans, 0)) {
		cout << "Test 2 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 2 passed" << endl;

	int test3[1] = {5};
	int test3_ans[1] = {5};
	func(test3, 1);
	if (!array_equals(test3, 1, test3_ans, 1)) {
		cout << "Test 3 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 3 passed" << endl;

	int test4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int test4_ans[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	func(test4, 10);
	if (!array_equals(test4, 10, test4_ans, 10)) {
		cout << "Test 4 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 4 passed" << endl;

	int test5[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int test5_ans[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	func(test5, 10);
	if (!array_equals(test5, 10, test5_ans, 10)) {
		cout << "Test 5 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 5 passed" << endl;

	int test6[10] = {9, 10, 7, 8, 5, 6, 3, 4, 1, 2};
	int test6_ans[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	func(test6, 10);
	if (!array_equals(test6, 10, test6_ans, 10)) {
		cout << "Test 6 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 6 passed" << endl;

	int test7[20] = {80, 5, 27, 49, 12, 94, 63, 1, 88, 32, 57, 10, 75, 41, 68, 2, 99, 19, 53, 24};
	int test7_ans[20] = {1, 2, 5, 10, 12, 19, 24, 27, 32, 41, 49, 53, 57, 63, 68, 75, 80, 88, 94, 99};
	func(test7, 20);
	if (!array_equals(test7, 20, test7_ans, 20)) {
		cout << "Test 7 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 7 passed" << endl;

	int test8[17] = {166, 575, 826, 932, 620, 889, 103, 347, 546, 599, 679, 639, 801, 523, 8, 816, 141};
	int test8_ans[17] = {8, 103, 141, 166, 347, 523, 546, 575, 599, 620, 639, 679, 801, 816, 826, 889, 932};
	func(test8, 17);
	if (!array_equals(test8, 17, test8_ans, 17)) {
		cout << "Test 8 failed" << endl;
		pass = false;
	}
	else
		cout << "Test 8 passed" << endl;



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
	test(stooge_sort);

	// these variable determine what sizes of arrays we test, and the number of trials
	int max_size = 600;
    int interval = 10;
    int num_trials = 50;

    // results of timing are written to the file sort_runtimes.csv
    ofstream my_file;
    my_file.open("stooge_runtimes.csv");
    my_file << "size, time\n";			// header for csv file: column names are size, time

    for (int size = 0; size < max_size; size += interval){		// for each size
        int time = avg_time(size, stooge_sort, num_trials);			// compute average time for function call on array of that size
        my_file << size << "," << time << "\n";					// write result to the csv file
        cout << "Time taken by function on array size " << size << ": "
         << time << " nanoseconds" << endl;						// print the result as well
    }

    my_file.close();

    return 0;
}