#include <iostream>

void quadProbe(int arr[], int arrSize, int ht[], int htSize, int m) {
    for (int i = 0; i < arrSize; i++) {
        int hv = arr[i] % m; // compute the hash value
        if (ht[hv] == -1)
            // no collision, insert into ht
            ht[hv] = arr[i];
        else {
            // collision occurred, insert into hv
            // using quad prob hv2 value
            for (int j = 1; j < htSize; j++) {
                int hv2 = (hv + (j * j)) % m;
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
    int arr[] = { 76,40,48,5,55}, arrSize =5 ;
    int ht[7], htSize = 7;
    int m = 7;
    // Initializing the hash table
    for (int i = 0; i < htSize; i++) {
        ht[i] = -1;
    }
    // Function call
    quadProbe(arr, arrSize, ht, htSize, m);
    // Print result
    for (int i = 0; i < htSize; i++) {
        std::cout << ht[i] << " ";
    }
    return 0;
}