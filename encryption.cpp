#include <iostream>
#include <fstream>
using namespace std;
class file_base
{
protected:
    string file_name;
    string file_extension;

public:
    void input()
    {
        cout << "enter the file name:" << endl;
        cin >> file_name;
        cout << "Enter the extension:" << endl;
        cin >> file_extension;
        file_name += file_extension;
    }
    void validate_extension()
    {
        string text;
        cout << file_extension << endl;
        if (file_extension == ".txt" || file_extension == ".dat")
        {
            ofstream wfile;
            wfile.open(file_name);
            cout << "Enter the multiline string to be inserted end with $:" << endl;
            getline(cin, text, '$');
            wfile << text;
            wfile.close();
        }
        else
        {
            cout << "invalid" << endl;
        }
    }
};
class file_credential : public file_base
{
protected:
    int key_value;
    char ch;

public:
    void encrypt()
    {
        cout << "enter the key value:" << endl;
        cin >> key_value;
        validate_extension();
        fstream myfile(file_name, ios::in);
        ofstream opfile;

        opfile.open("filename_e.txt");
        if (!myfile)
        {
            cout << "Cannot open the file" << endl;
        }
        else
        {
            do
            {
                myfile.get(ch);
                if (ch == ' ')
                {
                    opfile << "$";
                }
                else
                {
                    opfile << (char(int(ch) + key_value));
                }
            } while (!myfile.eof());
        }
    }
    void decrypt()
    {
        fstream myfile;
        myfile.open("filename_e.txt", ios::in);
        fstream dfile;
        dfile.open("filename_d.txt", ios::out);
        do
        {
            myfile.get(ch);
            if (ch == '$')
            {
                dfile << " ";
            }
            else
            {
                dfile << (char(int(ch) - key_value));
            }
        } while (!myfile.eof());
    }
};
int main()
{
    file_credential f;
    f.input();
    f.encrypt();
    f.decrypt();
    return 0;
}