#include <iostream>

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