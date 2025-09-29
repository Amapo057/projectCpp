#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;
    int sum;
    
    cout << "첫번쨰 숫자 입력: ";
    cin >> num1;
    cout << "두번쨰 숫자 입력: ";
    cin >> num2;
    sum = num1 + num2;
    cout << "두 수의 합" << sum << endl;
    cout << num1;
    return 0;
}