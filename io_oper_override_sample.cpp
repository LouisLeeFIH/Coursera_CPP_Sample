/*
this sample try iostream operator <<, >> override 
via using complex class 

*/

#include <iostream>
#include <string>
#include <cstring>
//#include <cstdlib>

using namespace std;


class Complex
{
    double real, img;

    friend ostream& operator<<(ostream& o, const Complex& c);
    friend istream& operator>>(istream& i, Complex& c);
public:
    Complex(){real = 0; img = 0;};
    Complex(double r, double i):real(r), img(i){};
};

ostream & operator<<(ostream& o, const Complex& c)
{
    o<<c.real<<"+"<<c.img<<"i,";
    return o;
}

istream& operator>>(istream& i, Complex& c)
{
    string strLine, subString;

    i>>strLine;

    int pos = strLine.find('+');
    subString = strLine.substr(0, pos);
    c.real = atof(subString.c_str());

    subString = strLine.substr(pos+1, strLine.length()-pos-2);
    c.img = atof(subString.c_str());
}


main()
{
    Complex comp;

    cin >> comp;
    cout << comp;
    cout <<endl<<"Hello world"<<endl;

}