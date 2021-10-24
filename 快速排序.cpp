#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int partition(int array[], size_t arrStart, size_t pivot, size_t arrEnd) {
   int arrayLen = arrEnd - arrStart;//���鳤�� 
   if ( arrayLen < 1 || pivot < arrStart || pivot >= arrEnd) {
       return false; //���鳤��С��0�����ش��� 
   }
   int pivotValue = array[pivot]; // ����һ����Ϊ�Ƚ϶��� 
   array[pivot] = array[arrEnd - 1];//�������������һ������Ϊ����� 
   int pivotPos = arrStart;
   int temp;
   for (int i = arrStart; i < arrEnd - 1; ++i)
   {
       if (array[i] < pivotValue) {//�������е�����������õ���бȽ� 
          temp = array[pivotPos];
          array[pivotPos] = array[i];
          array[i] = temp;//���С�ڸõ㣬��������ݽ��� 
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

    srand(array[array[arrStart] + arrLen + array[arrEnd - 1]]);//������ֶ� 
    int pivot = arrStart + floor(((arrLen - 1) + (size_t)rand()) % (arrLen - 1));// �������������е�λ�� 
    int pivotPos = partition(array, arrStart, pivot, arrEnd);//������ 
    kuaisu(array, arrStart, pivotPos);//ǰһ���ֽ������� 
    kuaisu(array, pivotPos+1, arrEnd);//��һ���ֽ������� 
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
