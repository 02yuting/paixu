#include <iostream>
#include <math.h>
using namespace std;
bool xuanze(int array[], size_t arrLen) {
    if (arrLen < 0) {
        return false;//数组长度小于0，返回错误  
    }
    for (int orderedNum = 0; orderedNum < arrLen; ++orderedNum) {//设定一个点，该点在数组范围内，并逐渐增加 
        int minIndex = orderedNum;//定义一个最小值 
        for (int i = orderedNum + 1; i < arrLen; ++i) {
            if (array[i] < array[minIndex]) {
                minIndex = i;//如果该点小于最小值，则最小值为该点 
            }
        }
        if (minIndex != orderedNum){
            int temp = array[orderedNum];
            array[orderedNum] = array[minIndex];
            array[minIndex] = temp;//如果最小值小于该点，进行数据交换 
        }
    }
    return true;
}
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";//引用上边函数直接排序 
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
