#include <iostream>
#include "Login.h"
#include "Student.h"
#include <fstream>
#include "Admission.h"

using namespace std;

int main()
{
    int ch=-1,f;
        cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
        cout<<"\t\t\t\t            COLLEGE ADMISSION SYSTEM                  "<<endl;
        cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
        cout<<endl<<endl;
        cout<<"1 - LOGIN \n2 - COURSE DETAILS\n0 - EXIT\nEnter your choice:";
        cin>>ch;
        if (ch==1)
        {
            string email,pass;
            Login l,b;
            int flag=0;
            cout<<"Enter email:";
            cin>>email;
            cout<<"Enter password:";
            cin>>pass;
            ifstream in("Login.txt",ios::in | ios:: binary);
            try
            {
                if(in.is_open())
                {
                    while(!in.eof())
                    {
                        in.read(reinterpret_cast < char *>(&b),sizeof(b));
                        flag=b.signin(email,pass);
                        if (flag==1)
                        {
                            break;
                        }

                    }
                }
                in.close();
                if (flag==0)
                {
                    throw "Not found";

                }
            }
            catch(...)
            {
                system("cls");
                l.signup();
            }

            Student s(&l);
            Admission admit(&s);
            system("cls");
            cout<<"\t\t\t\t-------------------------------------"<<endl;
            cout<<"\t\t\t\t        ENTER STUDENT DETAILS        "<<endl;
            cout<<"\t\t\t\t-------------------------------------"<<endl;
            admit.stud->read();
            admit.stud->percentage();
            system("cls");
            cout<<"\t\t\t\t------------MARK SHEET---------------"<<endl;
            cout<<"\n\n"<<endl;
            admit.stud->displayMarkSheet();
            cout<<"\n\n"<<endl;
            cout<<"COURSES AVAILABLE FOR YOUR CUTOFF:"<<endl;
            admit.stud->studentEligibility();
            cout<<"\n\n"<<endl;
            admit.stud->course.readCourse();
            cout<<"Do you want to change the course(1-yes/0-no)  :";
            cin>>f;
            if(f==1)
            {
                admit.stud->studentChangeCourse();
            }

            cout<<"\n\n"<<endl;
            system("cls");
            cout<<"----------------------------------------"<<endl;
            admit.displaystudDetail();
            cout<<"-----------------------------------------"<<endl;

            cout<<"Continuing to payment........\n"<<endl;
            admit.makeAdmission();
            cout<<"------------------------------------------"<<endl;

            cout<<"\n\n";
            cout<<"PAYMENT MADE........"<<endl;
            if(admit.stud->course.getCourseName()=="Software Systems")
            {
                string line;
                int val;
                ifstream in("SS.txt");
                getline(in,line);
                stringstream(line)>>val;

                cout<<"no of seats : "<<val<<endl;
                try
                {
                    if(val==0 || val<0)
                    {
                        throw "invalid";
                    }
                }
                catch(...)
                {
                    cout<<"seats not available"<<endl;
                }
            }

            else if(admit.stud->course.getCourseName()=="Theoretical Computer Science")
            {
                string line;
                int val;
                ifstream in("TCS.txt");
                getline(in,line);
                stringstream(line)>>val;
                cout<<"no of seats : "<<val<<endl;
                try
                {
                    if(val==0 || val<0)
                    {
                        throw "invalid";
                    }
                }
                catch(...)
                {
                    cout<<"seats not available"<<endl;
                }
            }

            else if(admit.stud->course.getCourseName()=="Data Science")
            {
                string line;
                int val;
                ifstream in("DS.txt");
                getline(in,line);
                stringstream(line)>>val;

                cout<<"no of seats : "<<val<<endl;

                try
                {
                    if(val==0 || val<0)
                    {
                        throw "invalid";
                    }
                }
                catch(...)
                {
                    cout<<"seats not available"<<endl;
                }
            }

            else if(admit.stud->course.getCourseName()=="Cyber Security")
            {
                string line;
                int val;
                ifstream in("CS.txt");
                getline(in,line);
                stringstream(line)>>val;

                cout<<"no of seats : "<<val<<endl;
                try
                {
                    if(val==0 || val<0)
                    {
                        throw "invalid";
                    }
                }
                catch(...)
                {
                    cout<<"seats not available"<<endl;
                }
            }

            else if(admit.stud->course.getCourseName()=="Applied Science")
            {
                string line;
                int val;
                ifstream in("AS.txt");
                getline(in,line);
                stringstream(line)>>val;

                cout<<"no of seats : "<<val<<endl;
                try
                {
                    if(val==0 || val<0)
                    {
                        throw "invalid";
                    }
                }
                catch(...)
                {
                    cout<<"seats not available"<<endl;
                }
            }

            else if(admit.stud->course.getCourseName()=="Applied Mathematics")
            {
                string line;
                int val;
                ifstream in("AM.txt");
                getline(in,line);
                stringstream(line)>>val;

                cout<<"no of seats : "<<val<<endl;
                try
                {
                    if(val==0 || val<0)
                    {
                        throw "invalid";
                    }
                }
                catch(...)
                {
                    cout<<"seats not available"<<endl;
                }
            }

            else if(admit.stud->course.getCourseName()=="Computer System and Design")
            {
                string line;
                int val;
                ifstream in("CSD.txt");
                getline(in,line);
                stringstream(line)>>val;

                cout<<"no of seats : "<<val<<endl;
                try
                {
                    if(val==0 || val<0)
                    {
                        throw "invalid";
                    }
                }
                catch(...)
                {
                    cout<<"seats not available"<<endl;
                }
            }

            cout<<"Terminating program"<<endl;
        }
        else if (ch==2)
        {
            system("cls");
            cout<<"\t\t\t\t--------------------------------------"<<endl;
            cout<<"\t\t\t\t         COURSE DETAILS               "<<endl;
            cout<<"\t\t\t\t--------------------------------------"<<endl;
            Course c;
            c.displayCourse();
        }
}
