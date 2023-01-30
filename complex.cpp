#include <iostream>
using namespace std;

class Complex
{
        int real, img;

        public:
                Complex():real(0),img(0){}
                Complex(int _real, int _imag):real(_real), img(_imag){}

                Complex operator +(Complex c)
                {
                        return Complex(real + c.real, img + c.img);
                }

                Complex operator -(Complex c)
                {
                        return Complex(real - c.real, img - c.img);
                }

                void Display(){
                        cout<<real<<" + "<<img<<"i"<<endl;
                }

                void Input()
                {
                        cout<<"Enter a complex no. :"<<endl;
                        cout<<"Real:";
                        cin>>real;
                        cout<<"Imaginary:";
                        cin>>img;

                }
};
int main()
{
        system("clear");

        Complex c1, c2, sum, diff;
        c1.Input();
        c2.Input();

        sum = c1 + c2;
        diff = c1 - c2;

        cout<<"C1 = ";
        c1.Display();
        cout<<"C2 = ";
        c2.Display();

        cout<<"Sum = ";
        sum.Display();
        cout<<"Difference = ";
        diff.Display();
        return 0;
}
