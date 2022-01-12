#include <iostream>
using namespace std;

#define MaxNum 20

template<class DataType>
class Vector
{
private:
    DataType *data;
    int m_size;
    int m_capicity;
public:
//built-up func
    Vector();
    Vector(int num, DataType var);
    Vector(const Vector &v);

//end-up func
    ~Vector();

//interface
    //operator09
    DataType operator [](int index);

    //size
    int size();
    int resize(int change_size);
    //capicity
    int capicity();
    //push_back
    void push_back(DataType a);
    //pop_back
    void pop_back();
    // clear Vector
    void clear();
    void assign(DataType tar[]);
    void assign(const Vector &v1);

};

// built-up func
template <class DataType>
Vector<DataType>::Vector()
{
    this->data = new DataType[MaxNum];
    for (int i = 0; i < MaxNum; i++)
        this->data[i] = 0;
    this->m_size = 0;
    this->m_capicity = MaxNum;
}

template <class DataType>
Vector<DataType>::Vector(int num, DataType var)
{
    this->data = new DataType[2*num];
    for (int i = 0; i < num; i++)
        this->data[i] = var;
    this->m_size = num;
    this->m_capicity = 2*num;
}

template <class DataType>
Vector<DataType>::Vector(const Vector &v)
{
    if (v == nullptr)
    {

    }
    else
    {

    }
}

// end-up func
template <class DataType>
Vector<DataType>::~Vector()
{
    if (this->data != nullptr)
        delete [] this->data;
    this->data = nullptr;
    this->m_size = 0;
    this->m_capicity = 0;
}

// interface
// operator09
template <class DataType>
DataType Vector<DataType>::operator[](int index)
{
    //invalid index
    if (index < 0 || index > size)  return NULL;
    else return this->data[index];
}

// size
template <class DataType>
int Vector<DataType>::size()
{
    return this->m_size;
}
template <class DataType>
int Vector<DataType>::resize(int change_size)
{
    
}
// capicity
template <class DataType>
int Vector<DataType>::capicity()
{
    return this->m_capicity;
}
// push_back
template<class DataType>
void Vector<DataType>::push_back(DataType a)
{
    if (this->m_size < this->m_capicity)
    {
        this->data[this->m_size] = a;
        this->m_size ++;
    }
    else
    {
        this->m_capicity *= 2;
        this->data[this->]
    }
    
}
// pop_back
template <class DataType>
void Vector<DataType>::pop_back()
{

}
// clear Vector
template <class DataType>
void Vector<DataType>::clear()
{

}
//assign
template <class DataType>
void Vector<DataType>::assign(DataType tar[])
{

}
template<class DataType>
void Vector<DataType>::assign(const Vector &v1)
{

}