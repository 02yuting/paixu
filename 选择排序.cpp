#include <iostream>
#include <math.h>
using namespace std;
bool xuanze(int array[], size_t arrLen) {
    if (arrLen < 0) {
        return false;//���鳤��С��0�����ش���  
    }
    for (int orderedNum = 0; orderedNum < arrLen; ++orderedNum) {//�趨һ���㣬�õ������鷶Χ�ڣ��������� 
        int minIndex = orderedNum;//����һ����Сֵ 
        for (int i = orderedNum + 1; i < arrLen; ++i) {
            if (array[i] < array[minIndex]) {
                minIndex = i;//����õ�С����Сֵ������СֵΪ�õ� 
            }
        }
        if (minIndex != orderedNum){
            int temp = array[orderedNum];
            array[orderedNum] = array[minIndex];
            array[minIndex] = temp;//�����СֵС�ڸõ㣬�������ݽ��� 
        }
    }
    return true;
}
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";//�����ϱߺ���ֱ������ 
    }
    cout << endl;
}
int main(){
    int array1[] = {9,4,7,2,6,0};
    int arrayLen = sizeof(array1)/sizeof(int);
    printArray(array1, arrayLen);
    xuanze(array1, arrayLen);
    printArray(array1, arrayLen);

}
