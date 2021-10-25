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
bool buckertSort(int array[], size_t arrLen, size_t bucketSize) {//���ú����������鳤�� 
    const int DEFAULT_BUCKET_SIZE = 10;//����Ĭ��ֵ 
    if(arrLen < 2) {
        return true;
    }
    if (bucketSize < 1) {
        bucketSize = DEFAULT_BUCKET_SIZE;//���鳤��С��1������Ĭ��ֵ 
    }
    int min = array[0];
    int max = array[0];//�������ֵ��Сֵ 
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }
    int **buckets = new int*[bucketSize]();//������άͰ���ҳ��ڼ���Ͱ�ܴ�������� 
    int *bucketLen = new int[bucketSize]();//��ǰͰ�ĳ������������ݸ��� 
    int bucketScope = floor((max - min)/bucketSize) + 1;//Ͱ�ķ�Χ �����䣩 
    for (size_t j = 0; j < bucketSize; j++)
    {
        buckets[j] = new int[arrLen]();//��Ͱ������������ 
    }
    int mapIndex = -1;
    for (size_t k = 0; k < arrLen; ++k)
    {
        mapIndex = floor((array[k] - min)/bucketScope);//�ҵ�Ͱ��λ�ã��ҵ���������һ��Ͱ�� 
        buckets[mapIndex][bucketLen[mapIndex]++] = array[k];
    }
    int arrayIndex = 0;
    for (size_t l = 0; l < bucketSize; l++)
    {
        if (bucketLen[l] > 0) {
            insertSort(buckets[l], bucketLen[l]);
            for (size_t m = 0; m < bucketLen[l]; ++m) {
                array[arrayIndex++] = buckets[l][m];//�����ݷŻ���ǰ������ 
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
