#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int partition(int array[], size_t arrStart, size_t pivot, size_t arrEnd) {
   int arrayLen = arrEnd - arrStart;//数组长度 
   if ( arrayLen < 1 || pivot < arrStart || pivot >= arrEnd) {
       return false; //数组长度小于0，返回错误 
   }
   int pivotValue = array[pivot]; // 设立一个点为比较对象 
   array[pivot] = array[arrEnd - 1];//设置数组中最后一个数据为这个店 
   int pivotPos = arrStart;
   int temp;
   for (int i = arrStart; i < arrEnd - 1; ++i)
   {
       if (array[i] < pivotValue) {//把数组中的其他数据与该点进行比较 
          temp = array[pivotPos];
          array[pivotPos] = array[i];
          array[i] = temp;//如果小于该点，则进行数据交换 
          ++pivotPos;
       }
   }
   array[arrEnd - 1] = array[pivotPos];
   array[pivotPos] = pivotValue;

   return pivotPos;
}
bool kuaisu(int array[], size_t arrStart, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;
    if (arrLen < 0) {
        return false;
    }

    if (arrLen == 0 || arrLen == 1) {
        return true;
    } 

    srand(array[array[arrStart] + arrLen + array[arrEnd - 1]]);//把数组分段 
    int pivot = arrStart + floor(((arrLen - 1) + (size_t)rand()) % (arrLen - 1));// 该数据在数组中的位置 
    int pivotPos = partition(array, arrStart, pivot, arrEnd);//新数组 
    kuaisu(array, arrStart, pivotPos);//前一部分进行排序 
    kuaisu(array, pivotPos+1, arrEnd);//后一部分进行排序 
    return true;
}
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main(){
    int array1[] = {1,6,3,7,2,4};
    int arrayLen = sizeof(array1)/sizeof(int);
    printArray(array1, arrayLen);
    kuaisu(array1, 0, arrayLen);
    printArray(array1, arrayLen);

}
