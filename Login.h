#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <fstream>
using namespace std;

class Login
{
    private:
        string email;
        string password;

    public:
        Login()
        {
            email=" ";
            password=" ";
        }
        void signup()
        {
            cout<<"\t\t\t\t------------------------------------------"<<endl;
            cout<<"\t\t\t\t               SIGNUP                     "<<endl;
            cout<<"\t\t\t\t------------------------------------------"<<endl;
            cout<<"Enter email id:";
            cin>>email;
            cout<<"Enter password:";
            cin>>password;
            ofstream out("Login.txt",ios::app | ios:: binary);
            out.write(reinterpret_cast <const char *>(this),sizeof(Login));
            out.close();
        }
        bool signin(string mail,string pass)
        {
            if (password==pass)
            {
                return 1;
            }
            return 0;
        }
        void forgotPassword(int place)//fh.tell() then write there
        {
            cout<<"Enter new password:";
            cin>>password;
            ofstream out("Login.txt",ios::app| ios::binary);
            out.seekp(place);
            out.write(reinterpret_cast <const char *>(this),sizeof(Login));
            out.close();
        }
        string getEmail()
        {
            return email;
        }
        ~Login(){cout<<" "<<endl;}
};

#endif // LOGIN_H_INCLUDED
