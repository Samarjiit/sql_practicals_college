#include<iostream>
using namespace std;


class sets {

    int set[20],size;

    public:
        sets():size(0){}
        sets(int s):size(s){}

        void input(){
            for(int i=0;i<size;i++){
                cin>>set[i];
            }
        }

        void display(){
            for(int i=0;i<size;i++){
                cout<<set[i];
            }
        }

        sets operator +(sets);
        sets operator -(sets);

};

sets sets :: operator + (sets B)
 {
     sets C;
     //int k=0;
     for (int i=0; i<size;i++)
     { 
       C.set[C.size]=set[i];
       C.size++;
       
         
     }
    for (int i=0 ; i<B.size; i++)
    {
        
        int check=0;
        for (int j=0;j<C.size;j++)
        {
            if (B.set[i] == C.set[j])
             check=1;
             break;
        }
        if (check==0)
        {
            C.set[C.size]=B.set[i];
            C.size++;
        }
 }
 return C;
 }

sets sets :: operator - (sets B)

{
     sets res;
    for(int i=0;i<size;i++){
        int contain=0;
        for(int j=0;j<  B.size;j++){
            if(B.set[j]==set[i]){
                    contain =1;
                    break;
             }
        }

        if(contain==1){
            res.set[res.size]=set[i];
            res.size++;
        }
    }

    return res;

}


int main() {
	// your code goes here
	int n1,n2;
	 cin>>n1;
	cin >>n2;
	sets A(n1),B(n2),C,Z;
	A.input();
	B.input();
	Z= A - B;
	C=A + B;
	cout<<"I :" ;
    Z.display();
	cout<<"U :";
    C.display();
	return 0;
}