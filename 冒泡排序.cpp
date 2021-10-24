#include <iostream>
#include <math.h>
using namespace std;
bool maopao(int array[], size_t arrLen) {//定义数组，数组长度 
    if (arrLen < 0) {
        return false;//数组长度小于0，返回错误 
    }
    for (int orderedNum = 0; orderedNum < arrLen; ++orderedNum) {//外层循环，排好N个数据，需要排N-1次，每次循环，排好一个数 
        bool isExchanged = false;
        for (int i = 0; i < arrLen - orderedNum -1; ++i) {//内层循环，排号一个数据，需要比较n-i-1次 
            if (array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;//进行数据交换 
                isExchanged = true;
            }
        }
        if (!isExchanged) {
            break;//所谓发生数据交换，说明数组有序直接跳出 
        }
    }
    return true;
}
bool maopao_Sheng(int array[], size_t arrLen) {
    if (arrLen < 0) {//数组长度小于0，返回值错误 
        return false;
    }
    int orderedNum = 0;
    while (true) {
        bool isExchanged = false;
        for (int i = 0; i < arrLen - orderedNum -1; ++i) {//比较的次数变成n-i-1 
            if (array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp; //进行数据交换 
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
