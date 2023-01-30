#include<iostream>
#include<fstream>
#include<string.h>
#define max 50
using namespace std;

int main(){

    int n,mcount=0,gcount=0;
    cout<<"enter the no of mails\n";
    cin>>n;
    fstream file,mfile,gfile;
    file.open("email_ids.txt",ios::out);
    cout<<"\n n"<<"emails \n";
    for(int i=0;i<n;i++){
        char ch[max];
        cin>>ch;
        file<<ch<<endl;
    }

    file.close();
    file.open("email_ids.txt",ios::in);
    mfile.open("manipal_ids.txt",ios::out);
    gfile.open("gmail_id.txt",ios::out);
    while(1){
        char st[70];
        file.getline(st,75);
        if(file.eof()){
            break;
            }

        if(strstr(st,"manipal.edu")){
            mfile<<st<<endl;
            mcount++;
        }    
        else if(strstr(st,"gmail.com")){
            gfile<<st<<endl;
            gcount++;
        }

    }

file.close();
mfile.close();
gfile.close();

cout<<"\n enter no of maile of manipal.edu"<<mcount;
cout<<"\n enter no of mails of gmailom"<<gcount;
}