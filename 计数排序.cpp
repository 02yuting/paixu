#include <iostream>
#include <math.h>
using namespace std;
bool coutingSort(int array[], size_t arrLen) {
    if (arrLen < 2) {
        return true;
    }
    int max = array[0];
    int min = array[0];//�趨���ֵ��Сֵ 
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }
    int *countingBuckets = new int[max - min + 1]();//����һ����Ͱ��Ͱ�ĵķ�Χʱ���֮����Сֵ��һ 
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];//ÿ��ֵ���ֵĴ�����
    }
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];//���ۼ� 
    }
    int *tempArray =new int[arrLen](); 
    for (int l = arrLen - 1; l >= 0; --l)
    {
        tempArray[--countingBuckets[array[l] - min]] = array[l];//�����ݷ���ûĿ�������� 
    }

    for (size_t m = 0; m < arrLen; ++m)
    {
        array[m] = tempArray[m];//����ԭ�����飬�����Ϊ���� 
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
