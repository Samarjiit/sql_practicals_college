#include<iostream>
#include<fstream>
using namespace std;


class file_e_d{

    protected:
    string filename;
    string filexten;

    public:
    void input(){
        cout<<"enter the file name:\t";
        cin>>filename;
        cout<<"\nenter the file extension:\t";
        cin>>filexten;
        filename+=filexten;
        cout<<endl;
    }

    void validate(){
        string text;
        cout<<filexten<<endl;
         if (filexten == ".txt" || filexten == ".dat"){
            fstream opfile;
            opfile.open(filename);
            cout<<"\n enter multiline sentences end with $\n";
            getline(cin, text, '$');
            opfile<<text;
            opfile.close();
         }else{
            cout<<"file invalid!!!!";
         }

        }
    };


    class credentials:public file_e_d{

        protected:
        int key_value;
        char ch;

        public:
        void encrypt(){
            cout<<"\nenter the key value:\t";
            cin>>key_value;
            validate();
            fstream myfile(filename,ios::in);
            ofstream enfile;
            
            enfile.open("file_en.txt");
            if(!myfile){
                cout<<"cannot open the file";
            }
            else{
                do {
                    myfile.get(ch);
                    if(ch==' '){
                        enfile<<"$";
                    }
                    else{
                        enfile<<(char(int(ch)+key_value));
                    }
                    
                }while(!myfile.eof());
            }
            myfile.close();
            enfile.close();
        }


        void decrypt(){
            fstream myfile;
            myfile.open("file_en.txt",ios::in);
            fstream dfile;
            dfile.open("file_d.txt",ios::out);
            do{
                myfile.get(ch);
                if(ch=='$'){
                    dfile<<" ";
                }
                else{
                    dfile<<(char(int(ch)-key_value));
                }
            }while(!myfile.eof());

            myfile.close();
            dfile.close();
        }
        

    };


    int main(){
        credentials f;
        f.input();
        f.encrypt();
        f.decrypt();
        return 0;
    }