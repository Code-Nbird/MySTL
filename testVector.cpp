#include <iostream>
#include <vector>
#include "Vector.hpp"

using namespace std;

void test()
{
    vector<int> int_array_stl;
    Vector<int> int_array_my;

    vector<char> char_array_stl;
    Vector<char> char_array_my;
    
    for (int i = 0; i < 10; i++)
    {
        int_array_stl.push_back(i);
        int_array_my.push_back(i);
    }
    printf("int_array_stl.size() = %d, int_array_stl.capacity() = %d\n", int_array_stl.size(), int_array_stl.capacity());
    printf("int_array_my.size() = %d, int_array_my.capacity() = %d\n", int_array_my.size(), int_array_my.capacity());
    for (int i = 0; i < 10 ;i++)
    {
        cout << "int_array_stl[" << i << "]:" << int_array_stl[i] << endl;
        cout << "int_array_my[" << i << "]:" << int_array_my[i] << endl;
    }

}

int main()
{
    test();
    return 0;
}