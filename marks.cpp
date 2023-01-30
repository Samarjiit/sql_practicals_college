#include<iostream>
using namespace std;

int compute_result(int M[][5],int nos){
    int maxm=0,regno;

    for(int i=0;i<nos;i++){
        M[i][4]+=M[i][1]+M[i][2]+M[i][3];

        if(M[i][4]>maxm){
            maxm=M[i][4];
            regno = M[i][0];
        }
    }

    return regno;
}


void display_std(int M[][5],int nos,int regno){
    cout<<"\n the student with highest total marks:\n";
    cout<<"\nregno   sub1   sub2   sub3   totatmarks: \n";
    for(int i=0;i<nos;i++){
        if( M[i][0]==regno){
            cout<<M[i][0]<<"      "<<M[i][1]<<"      "<<M[i][2]<<"      "<<M[i][3]<<"     "<<M[i][4];
            return;
        }
    }
}


int main(){
    int marks[10][5],nos;
    int regno;
    cout<<"enter the no of stud : ";
    cin>>nos;
    for(int i=0;i<nos;i++){
        cout<<"student -"<<i+1<<"\n";
        for(int j=0;j<4;j++){
            cin>>marks[i][j];
        }
        marks[i][4]=0;
    }

    for(int i=0;i<nos;i++){
        cout<<"student -"<<i+1<<"\t";
        for(int j=0;j<5;j++){
            cout<<marks[i][j]<<"\t";
            
    }
    cout<<endl;
    }
    regno=compute_result(marks,nos);
    display_std(marks,nos,regno);


}