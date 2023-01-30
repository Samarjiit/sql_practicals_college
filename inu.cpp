#include<iostream>
#include<String.h>
using namespace std;

class Sets{
    public:

    int ch[50];
    int size;
    Sets():size(0){}
    Sets(int s):size(s){}


    void input(){
        cout<<"\nenter "<<size<<"elements :";
        for(int i=0;i<size;i++){
            cin>>ch[i];
        }
    }

    void output(){

        cout<<"\n {";
        for(int i=0;i<size;i++){
            cout<<ch[i]<<",";
        }
        cout<<"}";
    }

    friend Sets operator +(Sets&, Sets&);
    friend Sets operator -(Sets&,Sets&);

};



Sets operator + (Sets& s1, Sets& s2){
    Sets res=s1;
    for(int i=0;i<s2.size;i++){
        int contain=0;
        for(int j=0;j<res.size;j++){
            if(s2.ch[i]==res.ch[j]){
                contain=1;
                break;
            }
        }

        if(contain==0){
            res.ch[res.size]=s2.ch[i];
            res.size++;
        }
    }

    return res;


}

Sets operator - (Sets& s1, Sets&s2){

    Sets res;
    for(int i=0;i<s1.size;i++){
        int contain=0;
        for(int j=0;j<s2.size;j++){
            if(s2.ch[j]==s1.ch[i]){
                    contain =1;
                    break;
             }
        }

        if(contain==1){
            res.ch[res.size]=s1.ch[i];
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