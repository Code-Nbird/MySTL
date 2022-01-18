#include <iostream>
using namespace std;

#define MaxNum 20

template<class DataType>
class Vector
{
private:
    DataType *arrayData;
    int m_size;
    int m_capacity;
public:
//built-up func
    Vector();
    Vector(int num, DataType var);
    Vector(const Vector &v);

//end-up func
    ~Vector();

//interface
    //operator
    DataType& operator [](int index);
    Vector& operator =(const Vector &v);

    //swap
    void swap(Vector &v);
    //size
    int size();
    void resize(int change_size);
    //capacity
    int capacity();
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
    this->arrayData = new DataType[MaxNum];
    for (int i = 0; i < MaxNum; i++)
        this->arrayData[i] = 0;
    this->m_size = 0;
    this->m_capacity = MaxNum;
}

template <class DataType>
Vector<DataType>::Vector(int num, DataType var)
{
    this->arrayData = new DataType[2*num];
    for (int i = 0; i < num; i++)
        this->arrayData[i] = var;
    this->m_size = num;
    this->m_capacity = 2*num;
}

template <class DataType>
Vector<DataType>::Vector(const Vector &v)
{
    this->m_capacity = v.m_capacity;
    this->m_size = v.m_size;
    this->arrayData = new DataType[this->m_capacity];
    for (int i = 0; i < v.m_size; i++)
        this->arrayData[i] = v->arrayData[i];
    
}

// end-up func
template <class DataType>
Vector<DataType>::~Vector()
{
    if (this->arrayData != nullptr)
        delete [] this->arrayData;
    this->arrayData = nullptr;
    this->m_size = 0;
    this->m_capacity = 0;
}

// interface
// operator
template <class DataType>
DataType& Vector<DataType>::operator[](int index)
{
    //invalid index
   return this->arrayData[index];
}

template <class DataType>
Vector<DataType>& Vector<DataType>::operator=(const Vector &v)
{
    if (this->arrayData != nullptr)
    {
        delete [] this->arrayData;
        this->m_capacity = 0;
        this->m_size = 0;
    }
    this->m_capacity = v.m_capacity;
    this->m_size = v.m_size;
    this->arrayData = new DataType[this->m_capacity];
    for (int i = 0; i < this->size; i++)
        this->arrayData[i] =  v.arrayData[i];
    return *this;
}

// size
template <class DataType>
int Vector<DataType>::size()
{
    return this->m_size;
}
template <class DataType>
void Vector<DataType>::resize(int change_size)
{
    //invalid
    if (change_size < 0 || change_size > 0x1000)    return ;
    //if array exist
    if (this->arrayData == nullptr)
    {
        this->m_capacity = change_size;
        this->size = change_size;
        this->arrayData = new DataType[change_size];
        for (int i = 0; i < this->arrayData; i++)
        {
            this->arrayData[i] = 0;
        }
    }
    else{
        //new_base_array
        if (change_size > this->m_capacity) 
        {
            DataType * new_base = new DataType[change_size];
            for (int i = 0; i < this->m_size; i++)
                new_base[i] = this->arrayData[i];
            delete []this->arrayData;
            this->arrayData = new_base;
        }
        this->m_capacity = change_size;
        this->m_sizee = change_size;
    }
}
// capacity
template <class DataType>
int Vector<DataType>::capacity()
{
    return this->m_capacity;
}
// push_back
template<class DataType>
void Vector<DataType>::push_back(DataType var)
{
    if (this->m_size < this->m_capacity)
    {
        this->arrayData[this->m_size] = var;
        this->m_size ++;
    }
    else
    {
        this->m_capacity *= 2;
        DataType *new_base = new DataType[this->m_capacity];
        for (int i = 0; i < this->m_size; i++)
            new_base[i] = this->arrayData[i];
        delete[] this->arrayData;
        this->arrayData = new_base;
    }
    
}
// pop_back
template <class DataType>
void Vector<DataType>::pop_back()
{
    if (this->m_size > 0)
        this->m_size --;
}
// clear Vector
template <class DataType>
void Vector<DataType>::clear()
{
    if (this->m_size != 0)
    {
        for (int i = 0; i < m_size; i++)
            if (this->arrayData[i] != NULL)
            {
                this->arrayData[i] = NULL;
            }
    }
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