#include <iostream>
#include <math.h>
using namespace std;
bool insertSort(int array[], size_t arrLen) {
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
bool insertSort_Sen(int array[], size_t arrLen) {
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
bool buckertSort(int array[], size_t arrLen, size_t bucketSize) {//设置函数名，数组长度 
    const int DEFAULT_BUCKET_SIZE = 10;//设置默认值 
    if(arrLen < 2) {
        return true;
    }
    if (bucketSize < 1) {
        bucketSize = DEFAULT_BUCKET_SIZE;//数组长度小于1，返回默认值 
    }
    int min = array[0];
    int max = array[0];//设置最大值最小值 
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }
    int **buckets = new int*[bucketSize]();//建立二维桶，找出第几个桶能存多少数据 
    int *bucketLen = new int[bucketSize]();//当前桶的长度里面存的数据个数 
    int bucketScope = floor((max - min)/bucketSize) + 1;//桶的范围 （区间） 
    for (size_t j = 0; j < bucketSize; j++)
    {
        buckets[j] = new int[arrLen]();//给桶分配数据区间 
    }
    int mapIndex = -1;
    for (size_t k = 0; k < arrLen; ++k)
    {
        mapIndex = floor((array[k] - min)/bucketScope);//找到桶的位置，找到数据在哪一个桶里 
        buckets[mapIndex][bucketLen[mapIndex]++] = array[k];
    }
    int arrayIndex = 0;
    for (size_t l = 0; l < bucketSize; l++)
    {
        if (bucketLen[l] > 0) {
            insertSort(buckets[l], bucketLen[l]);
            for (size_t m = 0; m < bucketLen[l]; ++m) {
                array[arrayIndex++] = buckets[l][m];//把数据放回以前的数组 
            }
        }
        delete [] buckets[l];
        buckets[l] = NULL;
    }
    delete [] buckets;
    delete [] bucketLen;
    return true;
}
int main(){
    int array1[] = {1,0,8,6,3};
    int  arrayLen = sizeof(array1)/sizeof(int);
    printArray(array1, arrayLen);
    buckertSort(array1, arrayLen, 1);
    printArray(array1, arrayLen);
}
