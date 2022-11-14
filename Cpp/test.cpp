#include <iostream>
using std::cout;
using std::endl;
int main() {
    int myArray[50]; // 배열 선언 사이즈 50개
    int element = 0; // 아이템 개수
    int search; // 검색할 숫자
    // 배열에 삽입한다
    myArray[0] = 142;
    myArray[1] = 256;
    myArray[2] = 311;
    myArray[3] = 777;
    myArray[4] = 999;
    myArray[5] = 175;
    myArray[6] = 595;
    element = 7; // 7개 요소를 사용
    // --------------------------------------
    // 배열에 저장한 요소를 출력
    for (int i = 0; i < element; i++)
    {
        cout << myArray[i] << ", ";
    }
    cout << endl;
    // --------------------------------------
    // 이 숫자를 검색한다
    search = 311;
    for (int i = 0; i < element; i++)
    {
        if (myArray[i] == search) {
            cout << search << "를 찾았습니다. 인덱스 넘버:" << i << endl;
            break;
        }
    }
    // --------------------------------------
    // 이 숫자를 삭제한다
    search = 999;
    int index = 0; // 삭제할 인덱스를 저장
    cout << endl << search << "를 삭제하겠습니다." << endl;
    for (int i = 0; i < element; i++)
    {
        if (myArray[i] == search) {
            cout << "찾았습니다. 인덱스 넘버: " << i << endl;
            index = i;
            break;
        }
    }
    // --------------------------------------
    // 삭제로 인한 구멍을 메꿔준다
    for (int k = index; k < element; k++)
    {
        myArray[k] = myArray[k + 1];
    }
    element--;
    // --------------------------------------
    // 배열에 저장한 요소를 출력
    for (int i = 0; i < element; i++)
    {
        cout << myArray[i] << ", ";
    }
    cout << endl;
    return 0;
}