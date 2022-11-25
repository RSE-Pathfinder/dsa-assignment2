#include <iostream>

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