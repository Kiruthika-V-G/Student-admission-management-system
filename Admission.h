#ifndef ADMISSION_H_INCLUDED
#define ADMISSION_H_INCLUDED
#include "Student.h"
#include "Payment.h"
#include <fstream>
#include <sstream>
class Admission
{
public:
    Student * stud;
    Payment pay;
    int admitCount;
    /*int SSCount;
    int TCSCount;
    int CSCount;
    int DSCount;
    int CSDCount;
    int AMCount;
    int ASCount;*/

    Admission()
    {

        /*while(in.is_open())
        {
            getline(in,line);
            stringstream(line)>>admissionCount;
        }
        fstream out("Admission.txt",ios::out|ios::binary);*/

    }
    Admission(Student * s):stud(s){}

    void displaystudDetail()
    {
        stud->display();
        stud->course.ChosenCourse();
    }
    void makeAdmission()
    {
        string line;
        int val;
        if (stud->course.getCourseName()=="Software Systems")
        {
            ifstream in("SS.txt");
            getline(in,line);
            stringstream(line)>>val;
            val--;
            admitCount=val;
            ofstream out("SS.txt",ios::out);
            out<<admitCount;
        }
        else if(stud->course.getCourseName()=="Theoretical Computer Science")
        {
            ifstream in("TCS.txt");
            getline(in,line);
            stringstream(line)>>val;
            val--;
            admitCount=val;
            ofstream out("TCS.txt",ios::out);
            out<<admitCount;
        }
        else if(stud->course.getCourseName()=="Data Science")
        {
            ifstream in("DS.txt");
            getline(in,line);
            stringstream(line)>>val;
            val--;
            admitCount=val;
            ofstream out("DS.txt",ios::out);
            out<<admitCount;
        }
        else if(stud->course.getCourseName()=="Cyber Security")
        {
            ifstream in("CS.txt");
            getline(in,line);
            stringstream(line)>>val;
            val--;
            admitCount=val;
            ofstream out("CS.txt",ios::out);
            out<<admitCount;
        }
        else if(stud->course.getCourseName()=="Applied Mathematics")
        {
            ifstream in("AM.txt");
            getline(in,line);
            stringstream(line)>>val;
            val--;
            admitCount=val;
            ofstream out("AM.txt",ios::out);
            out<<admitCount;
        }
        else if(stud->course.getCourseName()=="Applied Science")
        {
            ifstream in("AS.txt");
            getline(in,line);
            stringstream(line)>>val;
            val--;
            admitCount=val;
            ofstream out("AS.txt",ios::out);
            out<<admitCount;
        }
        else if(stud->course.getCourseName()=="Computer System and Design")
        {
            ifstream in("CSD.txt");
            getline(in,line);
            stringstream(line)>>val;
            val--;
            admitCount=val;
            ofstream out("CSD.txt",ios::out);
            out<<admitCount;
        }

        if(admitCount>=0)
        {
            pay.determinePay(stud->course.getCourseYear(),stud->getCommunity());
            pay.makePayment();
            /*ofstream out("Admission.txt",ios::out);
            out<<admissionCount;*/

        }
        else
        {
            cout<<"NO SEATS AVAILABLE\n";
        }
    }

};


#endif // ADMISSION_H_INCLUDED
