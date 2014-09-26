
/*--------------------------------------------------------------------------------
 * Author:    Ian Kane
 * Date:      Sept. 22, 2014
 * Compiler:  g++ 4.7
 * Command:   g++ binary_search.cpp -o binary
 * File Type: source file (binar_search.cpp)
 * Purpose:   Locate a specific element in an ordered list of elements using 
              binary search method.
 --------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

/*
 * Purpose: search ordered list for element using recursive binary search
 * @param int list[] - array of ordered integers
 * @param const int& item - integer to search for
 * @param int& first - index of array to begin searching at
 * @param int& last - index of array to end search at
 */
int binarySearch(int list[], const int& item, int& first, int& last) {
	
	// If "first" index is greater than "last" index, there are no elements to 
	// compare against and element was not found in the list. Indicate so by
	// returning a negative index.
	if (last < first) {
		return -1;
	}

	int mid = (first+last)/2; // find index of midpoint in sub-list to search
	
	// cout << "first: " << first << ", last: " << last << endl;
	cout << "Comparing against element in slot " << (mid + 1) << endl;
	
	// If middle element is the element searching for, return index of middle element.
	// Else, if element searching for is less than middle element, set the 
	// "last" index to the index before the middle index. This will result in 
	// searching the left hand side elements the next time around. Else, element 
	// is on the right hand side (RHS). To search the RHS next, set "first" index to 
	// index after the middle index.
	if (item == list[mid]) {	
		return mid;
	} else if (item < list[mid]) {
		last = mid - 1;
	} else {
		first = mid + 1;
	}
	
	// initiate next round of searching and return index
	return binarySearch(list, item, first, last);
}
/*
 * Purpose: iterative binary search
 */
int binSearch(int list[], const int& item, int& first, int& last) {

	int mid;
	int idx = -1;

	while (first <= last) {
		mid = (first+last)/2; // find mid-point
		cout << "first: " << first << ", mid: " << mid << ", last: " << last << endl;
		if (item == list[mid]) {	
			idx = mid;
			break;
		} else if (item < list[mid]) {
			last = mid - 1;
		} else if (item > list[mid]) {
			first = mid + 1;
		}
	}

	return idx;
}
//============================ Main ===============================================
int main (int argc, char* argv[]) {
	
	int to_find, n, first, last, idx_location; 

	int list[] = {1,3,5,7,9,11,13,15,17,19}; // sample list
	n          = sizeof(list)/sizeof(*list); // size of list

	first        = 0; // first index of list
	last         = n -1; // last index of list

	cout << "What do you want to look for?: ";
	cin >> to_find; // element value to search for
	
	// find index of element in list using binary search
	idx_location = binarySearch(list, to_find, first, last);
	
	// if index of elemen is -1, element was not found in list
	// else, report index of matching element in list
	if (idx_location == -1) {
	 	cout << "Element not found" << endl;
	} else {
	 	cout << "Found " << to_find << " at position " << (idx_location + 1) << endl;
	}
}
