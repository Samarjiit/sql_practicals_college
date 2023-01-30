#include<iostream>
#include<string.h>
using namespace std;

class Sets {
 int set[50];
        int size;

    public:
       

    Sets():size(0){}
    Sets(int n):size(n){}

    void input(){
        int i;
        for(i=0;i<size;i++ ){
            cin>>set[i];
        }
                cout<<endl;

    }

    void display(){
        int i;
        for(i=0;i<size;i++){
            cout<<set[i];
        }
        cout<<endl;
    }

    Sets operator +(Sets s2){
        Sets res;
        for(int i=0;i<size;i++){
            res.set[res.size]=set[i];
            res.size++;
        }

        for(int i=0;i<s2.size;i++){
            int contain=0;
            for(int j=0;j<res.size;j++){
                if(s2.set[i]==res.set[j])
                contain=1;
                break;
            }
            if(contain==0){
                res.set[res.size]=s2.set[i];
                res.size++;
            }
        }

        return res;
    }


    Sets operator-(Sets s2){
        Sets res;
        for(int i=0;i<size;i++){
            int contain=0;
            for(int j=0;j<s2.size;j++){
                if(s2.set[j]==set[i]){
                contain=1;
                break;
            }}

            if(contain==1){
                res.set[res.size]=set[i];
                res.size++;
            }
        }
        return res;
    }



};


int main(){
    int m,n;
    cout<<"enter no of element in set 1and set 2\n";
    cin>>m>>n;
    Sets s1(m),s2(n),s3,s4;
    s1.input();
    s2.input();
    s3=s1+s2;
    s4=s1-s2;
    cout<<"u :";
    s3.display();
    cout<<"I :";
    s4.display();

    return 0;
}