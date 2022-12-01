/**
 * @file q1.cpp
 * @author Derek Lim (2101597@sit.singaporetech.edu.sg)
 * @brief
 * 		Change original code of iterative function, binarySearch(),
 *      to a recursive function, recursiveBinarySearch().
 *
 * 		Looks for the requested element in the array using binary
 *      search algorithm.
 *
 * 		This program outputs the position if the element is found,
 *      otherwise it'll notify that the element is not in the array.
 *
 * @version 0.1
 * @date 2022-11-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

 /**
  * @brief  Performs binary search recursively until element is found,
  *         or until the first element is the last element, in which
  *         the element does not exist in the array.
  *
  * @param arr  The array of elements to find the requested element in.
  * @param item The element to be found.
  * @param beg  The position of first element.
  * @param end  The position of last element.
  * @return int
  */
int recursiveBinarySearch(int arr[], int item, int beg, int end) {
    if(beg > end)
        return -1;
    int midIndex = (beg + end) / 2;
    if (arr[midIndex] == item)
        return midIndex;
    else if (item > arr[midIndex])
        return recursiveBinarySearch(arr, item, midIndex + 1, end);
    else
        return recursiveBinarySearch(arr, item, beg, midIndex - 1);
}

/**
 * @brief Driver to run recursive binary search.
 *
 * @return int
 */
int main() {
int
arr[] = { 13, 45, 65, 89, 117, 182, 190 },
n = sizeof(arr) / sizeof(arr[0]),
search = 191;
int pos;
pos = recursiveBinarySearch(arr, search, 0, n - 1);
if (pos == -1)
printf("Element %i not present\n", search);
else
printf("Number %i is found at position %d\n", search, pos);
std::cout << "press any key to exit..."; std::cin.get();
return 0;
}