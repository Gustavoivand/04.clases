#include <iostream>

char* getSubarray(const char* originalArray, int startIndex, int subarrayLength) {
    // Allocate memory for the subarray
    char* subarray = new char[subarrayLength + 1]; // +1 for the null terminator

    // Copy characters from the original array to the subarray
    for (int i = 0; i < subarrayLength; ++i) {
        subarray[i] = originalArray[startIndex + i];
    }

    // Null terminate the subarray
    subarray[subarrayLength] = '\0';

    return subarray;
}

int main() {
    const char originalArray[] = "Hello, World!";
    int startIndex = 7; // Starting index of the subarray
    int subarrayLength = 5; // Length of the subarray

    char* subarray = getSubarray(originalArray, startIndex, subarrayLength);

    std::cout << "Subarray: " << subarray << std::endl;

    delete[] subarray; // Deallocate the memory

    return 0;
}
