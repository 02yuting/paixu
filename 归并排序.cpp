#include <iostream>
#include <math.h>
using namespace std;
bool merge(int array[], size_t arrStart, size_t arrMiddle, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;//数组长度 
    if (arrLen < 2) {  
        return false;
    }
    int *temp = new int(arrLen);
    int i = arrStart;
    int j = arrMiddle;
    int tempIndex = 0;//建立一个新数组，i为数组的前一部分，j为数组的中间部分 
    while (i < arrMiddle && j < arrEnd) {
        if (array[i] > array[j]) {
            temp[tempIndex] = array[j];
            ++j;
        }
        else {
            temp[tempIndex] = array[i];
            ++i;
        }
        ++tempIndex;
    }
    while (i < arrMiddle) {
        temp[tempIndex++] = array[i++];
    }
    while (j < arrEnd) {
        temp[tempIndex++] = array[j++];
    }
    for ((tempIndex = 0, i = arrStart); (tempIndex < arrLen && i < arrEnd); (++tempIndex, ++i)) {
        array[i] = temp[tempIndex];
    }
    delete []temp;
    temp = NULL;
    return true;
}
bool mergeSort(int array[], size_t arrStart, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;
    if (arrLen < 0) {
        return false;
    }
    if (arrLen == 0 || arrLen == 1) {
        return true;
    } 
    int middle = arrStart + floor(arrLen / 2);//新数组中间部分的位置 
    mergeSort(array, arrStart, middle);//将新数组前一部分和中间部分进行比较 
    mergeSort(array, middle, arrEnd);//将新数组中间部分和后一部分进行比较 
    return merge(array, arrStart, middle, arrEnd);//合并新数组，数组有序 
}
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main(){
    int array1[] = {9, 12, 8, 7, 3};
    int arrayLen = sizeof(array1)/sizeof(int);
    printArray(array1, arrayLen);
    mergeSort(array1, 0, arrayLen);
    printArray(array1, arrayLen);
}
