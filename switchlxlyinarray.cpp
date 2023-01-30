/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
using namespace std;
void minswap(double x[], double y[]);

int main(){
    double x[]={14.6,5.5,6.7,7.4,8.2};
    double y[]={6.8,7.7,1.3,7.2,3.4};


    cout<<"value of x before min swap \n";
    
        for(int i=0;i<5;i++)
        cout<<x[i]<<" ";
        
        cout<<endl;

        cout<<"value of y before min swap \n";
    
        for(int i=0;i<5;i++)
        cout<<y[i]<<" ";
        cout<<endl;

        cout<<"value of x and y after swap \n";
        minswap(x,y);

        return 0;
    
    }

void minswap(double x[], double y[]){

double low_x=x[0],low_y=y[0];
    int i,x1=0,y1=0;
    for(i=0;i<5;i++){
        if(x[i]<low_x){
            low_x=x[i];
            x1=i;
        }

        if(y[i]<low_y){

            low_y=y[i];
            y1=i;

        }
    }

    y[y1]=low_x;
    x[x1]=low_y;
for(i=0;i<5;i++){
    cout<<x[i]<<" ";
}
cout<<endl;

for(i=0;i<5;i++){
    cout<<y[i]<<" ";
}


}