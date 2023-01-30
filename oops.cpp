#include<iostream>
#include<fstream>
using namespace std;

class Customer{
        public:
        int code;
        char category;
        static int nextCode;
        float bill_amount;
        friend void operator>>(istream&,Customer &);
        friend void operator<<(ostream&,Customer &);
        friend void Display( Customer &);
        };

        int Customer::nextCode=1;

        void operator >>(istream& in, Customer &c){
                c.code=Customer::nextCode++;
                if(c.code<1 || c.code>100){
                        cout<<"error! code should be 1-100"<<endl;
                        exit(0);
                }

                cout<<"\nCustomer -"<<c.code<<endl;
                cout<<"\nenter category(C or I):";
                in>>c.category;
                if(c.category !='I' && c.category !='C'){
                        cout<<"error! category should be I or C";
                        exit(0);
                }

                cout<<"enter waterbill: ";
                in>>c.bill_amount;

                if(c.category=='C'){
                        c.bill_amount-=c.bill_amount*0.10;

                }
        }

        void operator<<(ostream &out,Customer &c){
                out<<"\nCode : "<<c.code<<endl;
                out<<"\ncategory : "<<c.category<<endl;
                out<<"water bill :"<<c.bill_amount<<endl;
        }

        void Display(Customer &c){
                if(c.bill_amount>750){
                        cout<<"\nhigh water usage!"<<endl;}
                else if(c.bill_amount>250){
                        cout<<"\nmoderate water usage!"<<endl;}
                else{
                        cout<<"congrats! u saved less water"<<endl;

                }
                }

        int main(){
                int opt;
                char path[]="myfile.txt";
                fstream file;
                file.open(path,ios::in);
                file.seekg(0,ios::end);
                int count=file.tellg()/sizeof(Customer);
                Customer::nextCode=count+1;
                file.close();

                do {
                        cout<<"\n1.ADD\n2.DISPLAY\n3.TOTAL_WATER_BILL\n4.EXIT\n";
                        cout<<"choose an option: ";
                        cin>>opt;
                        switch(opt){
                                case 1:
                                 {
                                   Customer c;
                                   cin>>c;
                                   file.open(path,ios::app);
                                   file.write((char*)&c,sizeof(Customer));
                                   file.close();
                                   break;
                                 }
                                 case 2:
                                 {
                                   int id;
                                   cout<<"\nenter an id:";
                                   cin>>id;
                                   id--;
                                   if(id>count){
                                           cout<<"no data found!"<<endl;
                                           break;
                                   }
                                   file.open(path,ios::in);
                                   file.seekg(id*sizeof(Customer));
                                   Customer c;
                                   file.read((char*)&c,sizeof(Customer));
                                   file.close();
                                   cout<<c;
                                   Display(c);
                                   break;
                                 }
                                case 3:
                                 {
                                   float sum=0;
                                   file.open(path,ios::in);
                                   while(1){
                                           Customer c;
                                           file.read((char*)&c,sizeof(Customer));
                                           if(file.eof()){
                                                   break;
                                           }
                                           sum+=c.bill_amount;
                                           cout<<c;
                                   }
                                   cout<<"\ntotal bill:"<<sum;
                                   break;
                                 }
                                case 4:
                                 cout<<"exit...."<<endl;
                                 break;
                                default:
                                 cout<<"\ninvalid option";
                        }
                }while(opt!=4);

        }
