#include<iostream>
using namespace std;



class Complex{
public:
    int real,image;
    Complex(){
        real=0;
        image=0;

    }

    Complex(int x){
        real=x;
        image=0;
    }

    Complex(int x,int y){
        real=x;
        image=y;
    }
    void input(){
        cout<<"enter a complex no.: "<<endl;
        cout<<"\t real : ";
        cin>>real;
        cout<<"\t image: ";
        cin>>image;
    }

    void display(){
        cout<<"("<<real <<" + "<<image<<" i "<<")";
    }

};

Complex add(Complex c1, Complex c2){
    return Complex(c1.real + c2.real, c1.image + c2.image);
}


Complex add(int a, Complex C){
    return add(Complex(a),C);
}
   
int main(){
    Complex c1,c2;
    int n;
    system("clear");
    c1.input();
    c2.input();

    cout<<"enter an integer :";
    cin>> n;

    c1.display();
    cout<<" +" <<n<<" = ";
    add(n,c1).display();
    cout<<endl;

    c1.display(); cout<<" + "; c2.display(); cout<<" = ";
    add(c1,c2).display();
    cout<<endl;
    return 0;
}