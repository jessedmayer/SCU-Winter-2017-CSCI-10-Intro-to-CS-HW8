#include <iostream>

using namespace std;

//defining struct Fraction
struct Fraction{
int num;
int den;
};

//outputs fraction
void printFraction (Fraction f){
cout<<f.num<<"/"<<f.den<<endl;
}

//multiplies two fractions and returns as fraction
Fraction mult(Fraction f1, Fraction f2){
    Fraction m;
    m.num=(f1.num*f2.num);
    m.den=(f1.den*f2.den);
    return m;
}

//adds two fractions and returns as fraction
Fraction add(Fraction f1, Fraction f2){
    Fraction a;
    a.num=((f1.num*f2.den)+(f2.num*f1.den));
    a.den=(f1.den*f2.den);
    return a;
}

int main()
{

    return 0;
}
