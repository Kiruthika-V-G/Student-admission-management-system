#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "Course.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
    private:
        string name;
        string fatherName;
        int age;
        string phone;
        string schoolType;
        string school10;
        string school12;
        float marks10[5];
        float marks12[6];
        string address;
        string community;
        string change_course_name;
        string change_course_type;
        float percentage10;
        float percentage12;

    public:
        Course course;
        Login * l=NULL;
        Student()
        {
            name=" ";
            fatherName=" ";
            age=0;
            phone="XXXXXXXXXX";
            schoolType=" ";
            school10=" ";
            school12=" ";
            address=" ";
            community=" ";
        }
        Student(Login * log):l(log){}

        void read()
        {
            char dummy;
            cout<<"Enter name:";
            cin>>dummy;
            getline(cin,name);
            cout<<"Enter father's name:";
            getline(cin,fatherName);
            try
            {
                cout<<"Enter age:";
                cin>>age;
                if(age<0)
                    throw "age can't be negative\n";

            }
            catch(...)
            {
                cout<<"Age can't be negative"<<endl;
                cout<<"Enter age:";
                cin>>age;
            }
            try
            {
                cout<<"Enter phone number:";
                cin>>phone;
                if (phone.length()!=10)
                    throw "invalid phone number";

            }
            catch(...)
            {
                cout<<"Enter a 10 digit phone number:";
                cin>>phone;
            }
            cout<<"Enter address:";
            cin>>dummy;
            getline(cin,address);
            cout<<"Enter 12th school board(CBSE/ICSE/MATRIC/other):";
            cin>>schoolType;
            cout<<"Enter community(BC/MBC/Other):";
            cin>>community;
            cout<<"Enter 10th marks:\nEnter marks in the order of : math, science, social studies, english, language: ";
            cin>>marks10[0]>>marks10[1]>>marks10[2]>>marks10[3]>>marks10[4];
            if (schoolType=="matric" || schoolType=="MATRIC")
            {
                cout<<"Enter 12th marks:\nEnter marks in the order of : math, computer/biology, physics,chemistry,english,language: ";
                cin>>marks12[0]>>marks12[1]>>marks12[2]>>marks12[3]>>marks12[4]>>marks12[5];
            }
            else
            {
                cout<<"Enter 12th marks:\nEnter marks in the order of : math, computer/biology, physics,chemistry,english: ";
                cin>>marks12[0]>>marks12[1]>>marks12[2]>>marks12[3]>>marks12[4];
            }
            ofstream out(l->getEmail()+".txt",ios::app | ios::binary);
            out.write(reinterpret_cast <const char *>(this),sizeof(Student));
            out.close();

        }
        string getName()
        {
            return name;
        }
        string getFatherName()
        {
            return fatherName;
        }
        int getAge()
        {
            return age;
        }
        string getPhone()
        {
            return phone;
        }
        string getCommunity()
        {
            return community;
        }
        void display()//
        {
            cout<<"Name:"<<name<<endl;
            cout<<"Father's name:"<<fatherName<<endl;
            cout<<"Age:"<<age<<endl;
            cout<<"Phone:"<<phone<<endl;
            cout<<"Address:"<<address<<endl;
            this->percentage();
        }
        void displayMarkSheet()
        {
            cout<<"--------------------------------------------"<<endl;
            cout<<"             10th marksheet                 "<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"        SUBJECT       |        MARKS        "<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<" MATHEMATICS          |     "<<fixed<<setprecision(2)<<marks10[0]<<endl;
            cout<<" SCIENCE              |     "<<fixed<<setprecision(2)<<marks10[1]<<endl;
            cout<<" SOCIAL STUDIES       |     "<<fixed<<setprecision(2)<<marks10[2]<<endl;
            cout<<" ENGLISH              |     "<<fixed<<setprecision(2)<<marks10[3]<<endl;
            cout<<" LANGUAGE             |     "<<fixed<<setprecision(2)<<marks10[4]<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"PERCENTAGE OBTAINED IN 10TH:       "<<fixed<<setprecision(2)<<percentage10<<endl;
            cout<<"\n\n"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"             12th marksheet                 "<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"        SUBJECT       |        MARKS        "<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<" MATHEMATICS          |     "<<fixed<<setprecision(2)<<marks12[0]<<endl;
            cout<<" COMPUTER/BIOLOGY     |     "<<fixed<<setprecision(2)<<marks12[1]<<endl;
            cout<<" PHYSICS              |     "<<fixed<<setprecision(2)<<marks12[2]<<endl;
            cout<<" CHEMISTRY            |     "<<fixed<<setprecision(2)<<marks12[3]<<endl;
            cout<<" ENGLISH              |     "<<fixed<<setprecision(2)<<marks12[4]<<endl;
            if (schoolType=="matric" || schoolType=="MATRIC")
            {
                cout<<" LANGUAGE             |     "<<fixed<<setprecision(2)<<marks12[5]<<endl;
            }
            cout<<"--------------------------------------------"<<endl;
            cout<<"PERCENTAGE OBTAINED IN 12TH:       "<<fixed<<setprecision(2)<<percentage12<<endl;
            cout<<"\n\n"<<endl;

        }
        void percentage()//percentage display //eligibility //
        {
            percentage10=(marks10[0]+marks10[1]+marks10[2]+marks10[3]+marks10[4])/5;
            if (schoolType=="matric" || schoolType=="MATRIC")
            {
                percentage12=(marks12[0]+marks12[1]+marks12[2]+marks12[3]+marks12[4]+marks12[5])/6;
            }
            else
            {
                percentage12=(marks12[0]+marks12[1]+marks12[2]+marks12[3]+marks12[4])/5;
            }
            cout<<"10th standard mark percentage:"<<percentage10<<endl;
            cout<<"12th standard mark percentage:"<<percentage12<<endl;
        }
        void studentEligibility()
        {
            int n;
            if(percentage12>95)
                n=0;
            else if(percentage12>90)
                n=4;
            else if(percentage12>85)
                n=8;
            else if(percentage12>80)
                n=12;
            else if(percentage12>75)
                n=16;
            else
                n=20;
            course.displayEligibleCourse(n);
        }

        void studentChangeCourse()
        {
                cout<<"enter the type of course to change : ";
                cin>>change_course_type;
                cout<<"enter the course name to change : ";
                cin>>change_course_name;
                if(change_course_name=="Software Systems")
                {
                    course.changeCourse(change_course_name,percentage12,change_course_type);
                }
                else if(change_course_name=="Theoretical Computer Science")
                {
                    course.changeCourse(change_course_name,percentage12,change_course_type);
                }
                else if(change_course_name=="Data Science")
                {
                    course.changeCourse(change_course_name,percentage12,change_course_type);
                }
                else if(change_course_name=="Cyber Security")
                {
                    course.changeCourse(change_course_name,percentage12,change_course_type);
                }
                else if(change_course_name=="Applied Science")
                {
                    course.changeCourse(change_course_name,percentage12,change_course_type);
                }
                else if(change_course_name=="Applied Mathematics")
                {
                    course.changeCourse(change_course_name,percentage12,change_course_type);
                }
                else if(change_course_name=="Computer science and Design")
                {
                    course.changeCourse(change_course_name,percentage12,change_course_type);
                }



            }

};
#endif // STUDENT_H_INCLUDED
