#include <iostream>
#include <math.h>
using namespace std;
bool maopao(int array[], size_t arrLen) {//�������飬���鳤�� 
    if (arrLen < 0) {
        return false;//���鳤��С��0�����ش��� 
    }
    for (int orderedNum = 0; orderedNum < arrLen; ++orderedNum) {//���ѭ�����ź�N�����ݣ���Ҫ��N-1�Σ�ÿ��ѭ�����ź�һ���� 
        bool isExchanged = false;
        for (int i = 0; i < arrLen - orderedNum -1; ++i) {//�ڲ�ѭ�����ź�һ�����ݣ���Ҫ�Ƚ�n-i-1�� 
            if (array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;//�������ݽ��� 
                isExchanged = true;
            }
        }
        if (!isExchanged) {
            break;//��ν�������ݽ�����˵����������ֱ������ 
        }
    }
    return true;
}
bool maopao_Sheng(int array[], size_t arrLen) {
    if (arrLen < 0) {//���鳤��С��0������ֵ���� 
        return false;
    }
    int orderedNum = 0;
    while (true) {
        bool isExchanged = false;
        for (int i = 0; i < arrLen - orderedNum -1; ++i) {//�ȽϵĴ������n-i-1 
            if (array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp; //�������ݽ��� 
                isExchanged = true;
            }
        }
        if (!isExchanged) {
            break;
        }

        ++orderedNum;
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

    int array1[] = {2,1,6,4,3,8};
    int arrayLen = sizeof(array1)/sizeof(int);
    printArray(array1, arrayLen);
    maopao(array1, arrayLen);
    printArray(array1, arrayLen);
}
