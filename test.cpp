#include <iostream>
#include <fstream>

using namespace std;

class Customer{
    public:
    int code;
    char category;
    float water_bill;

    static int nextCode;


    friend void operator >> (istream&, Customer &);
    friend void operator << (ostream&, Customer &);
    

    // void get_data(){
    //     code = lastCode++;
    //     if(code < 1 || code > 100){
    //         cout<<"Error! Code should 1-100"<<endl;
    //         exit(0);
    //     }

    //     cout<<"\nCustomer-" << code<<endl;
    //     cout<<"Enter the category (I or C):";
    //     cin>>category;

    //     if(category != 'I' && category != 'C'){
    //         cout<<"Error! Category should be either I or C"<<endl;
    //         exit(0);
    //     }
        

    //     cout<<"Enter the water bill:";
    //     cin>>water_bill;

    //     if(category == 'C'){
    //         water_bill -= water_bill*.10;
    //     }

    // }

    // void show_data()
    // {
    //     cout<<"\nCode: "<<code<<endl;
    //     cout<<"Category: "<<category<<endl;
    //     cout<<"Water bill: "<<water_bill<<endl;

    // }

    friend void Display(Customer&);
};

int Customer::nextCode = 1;

void operator >> (istream& in, Customer &c){
        c.code = Customer::nextCode++;
        if(c.code < 1 || c.code > 100){
            cout<<"Error! Code should 1-100"<<endl;
            exit(0);
        }

        cout<<"\nCustomer-" << c.code<<endl;
        cout<<"Enter the category (I or C):";
        in>>c.category;

        if(c.category != 'I' && c.category != 'C'){
            cout<<"Error! Category should be either I or C"<<endl;
            exit(0);
        }
        

        cout<<"Enter the water bill:";
        cin>>c.water_bill;

        if(c.category == 'C'){
            c.water_bill -= c.water_bill*.10;
        }

}

void operator << (ostream & out, Customer & c){
        out<<"\nCode: "<<c.code<<endl;
        out<<"Category: "<<c.category<<endl;
        out<<"Water bill: "<<c.water_bill<<endl;
}

void Display(Customer &c)
{
    if(c.water_bill > 750){
       cout<<"\nHigh water usage!"<<endl; 

    }
    else if(c.water_bill > 250){
       cout<<"\nModerate water usage!"<<endl; 

    }
    else{
       cout<<"\nCongrats! You used less water"<<endl; 
    }
}

int main()
{
    int opt;
    

    char path[] = "water_bill.txt";
    fstream file;

    file.open(path,ios::in);
    file.seekg(0,ios::end);
    int count = file.tellg() / sizeof(Customer);
    Customer::nextCode = count+1;
    file.close();

    do{
        cout<<"\n1. Add\n2. Display\n3. Total water bill\n4. Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>opt;

        switch (opt)
        {
        case 1:
           {
             // Create an object
            Customer c;
            // Enter that data from obj
            // c.get_data();
            cin >> c;  
            // Add that to file
            file.open(path,ios::app);
            file.write((char *)&c,sizeof(Customer));
            file.close();
            break;
           }
        
        case 2:
            {
                // Get an id from user
            int id;
            cout<<"\nEnter an id: ";
            cin>>id;


            // Get object with that id from file
            
            id--; // To adjust the id to start from 0

            if( id > count){
                cout<<"No data found!"<<endl;
                break;
            }

            file.open(path, ios::in);
            file.seekg(id*sizeof(Customer));
            Customer c;
            file.read((char *)&c,sizeof(Customer));
            file.close();

            
            // show_data
            // c.show_data();
            cout<<c;
            // Display
            Display(c);
            break;
        
            }
        case 3:
            {
                float sum = 0;
                file.open(path,ios::in);
                while(1){
                    Customer c;
                    file.read((char *)&c, sizeof(Customer));
                    if(file.eof()){
                        break;
                    }

                    sum += c.water_bill;
                    // c.show_data();
                    cout<<c;

                    
                }

                cout<<"\nTotal Bill: "<<sum<<endl;
                file.close();

                break;
            }

        
        case 4:
            cout<<"Exiting.."<<endl;
            break;
        
        default:
            cout<<"Invalid option!"<<endl;
            break;
        }
    }while(opt!=4);
}