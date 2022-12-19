#include <deque>
#include <iostream>

int main()
{
    using namespace std;
    deque <int> A;

//push добавления элемента в конец
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    
    cout << "A = ";
    for (int i : A)
        cout << i << ", ";
    cout << endl;
    
//pop удаления элемента из начала
    A.pop_front();
    
    cout << "A - удаления элемента из начала: ";
    for (int i : A)
        cout << i << ", ";
    cout << endl;

//front получения первого элемента
    int& a = A.front();
    cout << "первый элемент A: " << a;
    cout << endl;

//back получения последнего элемента
    int& z = A.back();
    cout << "последный элемент A: " << z;
    cout << endl;
    
//size получения размера очереди
    cout << "размера A: " << A.size();
    cout << endl;

}
