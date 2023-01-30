#include<iostream>
#include <cstring>
#define MAX_SIZE 50
using namespace std;
class my_String{

        public:
                char str[MAX_SIZE] = "";

                my_String(){
                        strcpy(str, "");
                }
                my_String(char val[]){
                        strcpy(str,val);
                }

                bool operator <=(my_String);

};
bool my_String::operator <=(my_String obj)
{
        for(int i = 0; str[i] != '\0'; i++)
        {
                int lhs = (int)(str[i]);
                int rhs = (int)(obj.str[i]);

                if(lhs > rhs)
                        return false;
        }

        return true;
}


int main()
{
        system("clear");
        my_String str1,str2;
        cout<<"Enter a string : ";
        cin>>str1.str;

        cout<<"Enter another string : ";
        cin>>str2.str;

        if(str1 <= str2)
                cout<<str1.str<<" <= "<<str2.str<<endl;
        else
                cout<<str1.str<<" > "<<str2.str<<endl;
        return 0;

}