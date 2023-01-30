#include<iostream>
#include<String.h>
using namespace std;

class Sets{
    public:

    int set[50];
    int size;
    Sets():size(0){}
    Sets(int s):size(s){}


    void input(){
        cout<<"\nenter "<<size<<"elements :";
        for(int i=0;i<size;i++){
            cin>>set[i];
        }
    }

    void output(){

        cout<<"\n {";
        for(int i=0;i<size;i++){
            cout<<set[i]<<",";
        }
        cout<<"}";
    }

     Sets operator +(Sets s2);
     Sets operator -(Sets s2);

};



Sets Sets:: operator + (Sets s2){
     Sets C;
     //int k=0;
     for (int i=0; i<size;i++)
     { 
       C.set[C.size]=set[i];
       C.size++;
       
         
     }
    for(int i=0;i<s2.size;i++){
        int contain=0;
        for(int j=0;j<C.size;j++){
            if(s2.set[i]== C.set[j]){
                contain=1;
                break;
            }
        }

        if(contain==0){
            C.set[C.size]=s2.set[i];
            C.size++;
        }
    }

    return C;


}

Sets Sets :: operator - (Sets s2){

    Sets res;
    for(int i=0;i<size;i++){
        int contain=0;
        for(int j=0;j<s2.size;j++){
            if(s2.set[j]==set[i]){
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


int main(){
    Sets s1,s2,s3,s4;
    cout<<"enter size of s1: ";
    cin>>s1.size;
    cout<<"enter the size of s2 :";
    cin>>s2.size;
    s1.input();
    s2.input();
    s1.output();
    s2.output();
    s3=s1+s2;
    s4=s1-s2;
    s3.output();
    s4.output();

    return 0;
}