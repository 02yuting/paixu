#include <iostream>
#include <math.h>
using namespace std;
bool coutingSort(int array[], size_t arrLen) {
    if (arrLen < 2) {
        return true;
    }
    int max = array[0];
    int min = array[0];//设定最大值最小值 
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }
    int *countingBuckets = new int[max - min + 1]();//建立一个新桶，桶的的范围时最大之间最小值加一 
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];//每个值出现的次数增
    }
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];//做累加 
    }
    int *tempArray =new int[arrLen](); 
    for (int l = arrLen - 1; l >= 0; --l)
    {
        tempArray[--countingBuckets[array[l] - min]] = array[l];//把数据放入没目标数组里 
    }

    for (size_t m = 0; m < arrLen; ++m)
    {
        array[m] = tempArray[m];//拷回原来数组，数组变为有序 
    }
    delete [] countingBuckets;
    delete [] tempArray;
    return true;
}
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main(){
    int array1[] = {9,5,0,8,2,1};
    int arrayLen = sizeof(array1)/sizeof(int);
    printArray(array1, arrayLen);
    coutingSort(array1, arrayLen);
    printArray(array1, arrayLen);
}
