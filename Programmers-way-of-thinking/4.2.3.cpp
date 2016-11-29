#include <iostream>
using namespace std;

void refParamFunction(int &x){
    x = 10;
}

int anotherFunction(const int &x){
    return x * x;
}

int main()
{
    int number = 5;
    refParamFunction(number);
    int twice = anotherFunction(number);
    cout << number << "\n";
    cout << twice << "\n";
    return 0;
}
