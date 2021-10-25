#include <iostream>
#include <math.h>
using namespace std;
bool merge(int array[], size_t arrStart, size_t arrMiddle, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;//���鳤�� 
    if (arrLen < 2) {  
        return false;
    }
    int *temp = new int(arrLen);
    int i = arrStart;
    int j = arrMiddle;
    int tempIndex = 0;//����һ�������飬iΪ�����ǰһ���֣�jΪ������м䲿�� 
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
    int middle = arrStart + floor(arrLen / 2);//�������м䲿�ֵ�λ�� 
    mergeSort(array, arrStart, middle);//��������ǰһ���ֺ��м䲿�ֽ��бȽ� 
    mergeSort(array, middle, arrEnd);//���������м䲿�ֺͺ�һ���ֽ��бȽ� 
    return merge(array, arrStart, middle, arrEnd);//�ϲ������飬�������� 
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
