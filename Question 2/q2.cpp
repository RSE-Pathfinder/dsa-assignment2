/**
 * @file q2.cpp
 * @author Derek Lim (2101597@sit.singaporetech.edu.sg)
 * @brief
 * 		Rectification of previous quadProbe() function to perform
 ^      actual quadratic probing algorithm
 *
 * 		Inserts element into a hashtable based on their hash value.
 * 		If there is already an existing element with the same hash
 * 		value, then a quadratic formula will be applied to find the
 * 		next hash value.
 *
 * 		This program outputs the sequence of elements using the 
 *      quadratic probing algorithm.
 *
 * @version 0.1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

 /**
  * @brief Finds a unoccupied space in an array to place the element.
  *
  * @param arr      The array of elements to be placed into the hashtable.
  * @param arrSize  The number of elements to be placed into the hashtable.
  * @param ht       The array of hashtable.
  * @param htSize   The number of space(array slots) in the hashtable.
  * @return void
  */
void quadProbe(int arr[], int arrSize, int ht[], int htSize) {
    for (int i = 0; i < arrSize; i++) {
        int hv = arr[i] % htSize; // compute the hash value
        if (ht[hv] == -1)
            // no collision, insert into ht
            ht[hv] = arr[i];
        else {
            // collision occurred, insert into hv
            // using quad prob hv2 value
            for (int j = 1; j < htSize; j++) {
                int hv2 = (hv + (j * j)) % htSize;
                if (ht[hv2] == -1) {
                    // insert into hv if there's no collision
                    ht[hv2] = arr[i];
                    break;
                }
            }
        }
    }
}

/**
 * @brief   Driver to insert element into an array through quadratic
 *          probe algorithm
 *
 * @return int
 */
int main() {
    int arr[] = {77, 94, 74, 90, 55, 51, 54, 76, 103}, arrSize = sizeof(arr)/sizeof(arr[0]);
    int ht[13], htSize = sizeof(ht)/sizeof(ht[0]);
    // Initializing the hash table
    for (int i = 0; i < htSize; i++) {
        ht[i] = -1;
    }
    // Function call
    quadProbe(arr, arrSize, ht, htSize);
    // Print result
    for (int i = 0; i < htSize; i++) {
        std::cout << ht[i] << " ";
    }
    return 0;
}