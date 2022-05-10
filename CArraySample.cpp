/*
this sample doing operator = [] override test, 
via using CArray class (like vector)
*/
#include <iostream>

using namespace std;

class CArray
{
    int size = 0;
    int* ptr = NULL;

public:
    void push_back(int additem);
    int length(){return size;};
    
    CArray(){size = 0, ptr = NULL;};
    CArray(CArray& src)
    {
        if(src.ptr == NULL)
        {
            delete []ptr;
            ptr = NULL;
            size = 0;
            return;        
        }

        size = src.size;
        ptr = new int[size];
        memcpy(ptr, src.ptr, sizeof(int)*size);
    }

    ~CArray()
    {
        if(ptr)
        {
            delete [] ptr;
            ptr = NULL;
            size = 0;
        }
    }


    CArray& operator =(const CArray& src);
    int& operator[](int index);

};

void CArray::push_back(int a)
{  
    if(size == 0)
    {
        ptr = new int[1];
        ptr[0] = a;
    }else
    {
        int* tmp_ptr = new int[size+1];
        memcpy(tmp_ptr, ptr, sizeof(int)*size);
        delete ptr;
        tmp_ptr[size] = a;
        ptr = tmp_ptr;
    }
    size += 1;
    
    return;
}

CArray& CArray::operator=(const CArray& src)
{
    //if src == original CArray a=a case
    if(src == this)
        return *this;

    // empty case
    if(srcsize == 0)
    {
        if(ptr) delete [] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }

    //remove original ptr
    if(ptr)
    {
        delete [] ptr;
        ptr = NULL;
        size = 0;
    }

    size = src.size;
    ptr = new int [size];
    memcpy(ptr, src.ptr, sizeof(int)*size);

    return *this;
}

int& CArray::operator[](int index)
{
    return ptr[index];
}

main()
{
    cout <<"hello world"<< endl;

    CArray A, B;
    int i;

    for(i=0; i<5; i++){
        A.push_back(i);
        cout<<"len:"<<A.length()<<" val:"<<A[i]<<endl;
    }

    for(i=0; i<5; i++){
        cout <<A[i]<<","<<i<<endl;
    }

    B=A;
    //cout <<B<<endl;

    A[3] = 100;
    CArray C(A);

    for(i=0; i<5; i++){
        cout <<"B:"<<B[i]<<","<<i<<endl;
    }
    for(i=0; i<5; i++){
        cout <<"C:"<<C[i]<<","<<i<<endl;
    }    
    //cout << C<<endl;


}

/*class CArray
{
    int size;
    int* ptr;

    CArray()
}*/