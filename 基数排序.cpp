#include <iostream>

using namespace std;

unsigned int getRadixValue(unsigned int value, unsigned int radix, unsigned int radixCount) {
    int radixValue = value;
    for (size_t i = 0; i < radixCount; ++i)
    {
        radixValue=radixValue/radix;
    }
    radixValue = radixValue % radix;
    return radixValue;   
}
bool radixSort(unsigned int array[], unsigned int arrLen, unsigned int radix) {
    if (arrLen <= 1) {
        return true;
    }

    //Find maximum and minimal value
    int max = array[0];

    for (unsigned int i = 1; i < arrLen; ++i)
    {
         if (max < array[i]) {
            max = array[i];
        }
    }

    int radixCount = 0;
    while ((max/=radix) > 0) {
        ++radixCount;
    }

    // Create counting buckets
    int *countingRadixBuckets = new int[radix]();
    int *tempArray = new int[arrLen]();

    for (size_t radixIndex = 0; radixIndex <= radixCount; ++radixIndex)
    {
        // Count number of values in array
        for (size_t j = 0; j < arrLen; ++j)
        {
            ++countingRadixBuckets[getRadixValue(array[j], radix, radixIndex)];
        }

        // Accumulate coutingBuckets to find the last ordered location of value in array
        for (size_t k = 1; k < radix; ++k)
        {
            countingRadixBuckets[k] += countingRadixBuckets[k-1];
        }

        //Traverse the array in reversed order
        for (int l = arrLen - 1; l >= 0; --l)
        {
            tempArray[--countingRadixBuckets[getRadixValue(array[l], radix, radixIndex)]] = array[l];
        }

        for (size_t m = 0; m < arrLen; ++m)
        {
            array[m] = tempArray[m];
        }

        for (size_t n = 0; n < radix; ++n)
        {
            countingRadixBuckets[n] = 0;
        }
        
    }
    
    delete [] countingRadixBuckets;
    delete [] tempArray;
    
    return true;
}

void printArray(unsigned int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){

    unsigned int array1[] = {1,89,55,45,12,0,8,27};
    unsigned int arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    radixSort(array1, arrayLen, 10);
    printArray(array1, arrayLen);

}
