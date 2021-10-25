#include <iostream>
#include <math.h>
using namespace std;
bool charu(int array[], size_t arrLen) {
    if (arrLen < 0) {
        return false;
    }

    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];
        int orderedIndex = orderedNum - 1;
        for (; orderedIndex >= 0; --orderedIndex) {
            if (insertValue < array[orderedIndex]) {
                array[orderedIndex + 1] = array[orderedIndex];
            }
            else {
                break;
            }
        }
        array[orderedIndex+1] = insertValue;
    }
    return true;
}

bool charu_Sen(int array[], size_t arrLen) {
     if (arrLen < 0) {
        return false;
    }
    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];
        int orderedIndex = orderedNum - 1;
        while(orderedIndex >=0 && array[orderedIndex] > insertValue) {
           array[orderedIndex + 1] = array[orderedIndex];
           --orderedIndex;
        }
        array[orderedIndex+1] = insertValue;
    }
    return true;
}
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main(){
    int array1[] = {1,4,7,3,5,2};
    int arrayLen = sizeof(array1)/sizeof(int);
    printArray(array1, arrayLen);
    charu_Sen(array1, arrayLen);
    printArray(array1, arrayLen);
}

