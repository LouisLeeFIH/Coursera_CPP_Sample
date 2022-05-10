/*
this sample doing a++ , --a operation override
also int() type override

using CDemo while its content only be one int

*/

#include <iostream>

using namespace std;

class CDemo
{
private:
    int value;

public:
    CDemo(CDemo& src):value(src.value){}
    CDemo(int i):value(i){}
    CDemo operator++();
    CDemo operator++(int i);

    operator int();
    friend CDemo operator--(CDemo& d);
    friend CDemo operator--(CDemo& d, int dummy);

    friend ostream& operator<<(ostream &o, CDemo d);
};

CDemo CDemo::operator++()
{
    value++;
    return *this;
}

CDemo CDemo::operator++(int dummy)
{
    CDemo tmp(*this);

    value ++;
    return tmp;
}

//this for --a => setted value
CDemo operator--(CDemo& d)
{
    d.value--;
    return d;
}

// this for a--(dummy)
CDemo operator--(CDemo& d, int dummy)
{
    CDemo tmp(d);

    d.value--;
    return tmp;
}

CDemo::operator int()
{
    return value;
}

ostream& operator<<(ostream &o, CDemo d)
{
    o<<int(d);
    return o;
}


main()
{
    CDemo a(5);

    cout<<a++<<",";
    cout<<a<<",";
    cout<<++a<<",";
    cout<<a<<endl;

    cout<<a--<<",";
    cout<<a<<",";
    cout<<--a<<",";
    cout<<a<<endl;

}