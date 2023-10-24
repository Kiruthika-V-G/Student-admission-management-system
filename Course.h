#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include <fstream>
#include "Student.h"
#include <iomanip>
class Course//keep courses in file and retrieve data from that and ask user to enter
{
    private://if percentage meets requirement display
        string course_type;
        string course_name;
        int course_year;

    public:
        Course()
        {
            course_type=" ";
            course_name=" ";
            course_year=0;
        }
        void displayCourse()
        {
            string line;
            ifstream in("CourseDetails.txt");
            if(in.is_open())
            {
                while(!in.eof())
                {
                    getline(in,line);
                    if(in.eof())
                    {
                        break;
                    }
                    cout<<line<<endl;
                }
            }
            in.close();
        }
        void displayEligibleCourse(int n)
        {
            string line;
            int count=0;
            ifstream in("CourseDetails.txt");
            for(int i=0;i<n;i++)
            {
                getline(in,line);
            }
            while(!in.eof())
            {
                getline(in,line);
                if(in.eof())
                {
                    break;
                }
                cout<<line<<endl;
            }
            in.close();
        }
        void readCourse()
        {
            char dummy;
            cout<<"WHICH COURSE WOULD YOU LIKE TO CHOOSE?:"<<endl;//if else check
            cout<<"Enter course type:";
            cin>>dummy;
            getline(cin,course_type);
            cout<<"Enter course name:";
            getline(cin,course_name);
            cout<<"Enter course duration:";
            cin>>course_year;
        }

        string getCourseType()
        {
            return course_type;
        }
        string getCourseName()
        {
            return course_name;
        }
        int getCourseYear()
        {
            return course_year;
        }
        void ChosenCourse()
        {
            cout<<"Chosen Course is:"<<uppercase<<course_name<<"("<<course_year<<"year"<<")"<<endl;
        }


        void changeCourse(string cname,float pct,string ccname)
        {
            try
            {
            int diff;
            int flag=0;
            if(ccname=="msc"||ccname=="MSC"||ccname=="MSc"||ccname=="Msc")
            {


            if(cname=="Software Systems")
            {
                diff=pct-90;
                if(diff>=0 && diff<=5)
                {
                    course_name=cname;
                    flag=1;
                }
                else
                {
                    cout<<"not eligible for "<<cname<<endl;
                }
            }
            else if(cname=="Theoretical Computer Science")
            {

                diff=pct-95;
                if(diff>=0 && diff<=5)
                {
                    course_name=cname;
                    flag=1;
                }
                else
                {
                    cout<<"not eligible for "<<cname<<endl;
                }
            }
            else if(cname=="Data Science")
            {

                diff=pct-85;
                if(diff>=0 && diff<=5)
                {
                    course_name=cname;
                    flag=1;
                }
                else
                {
                    cout<<"not eligible for "<<cname<<endl;
                }
            }
            else if(cname=="Cyber Security")
            {

                diff=pct-80;
                if(diff>=0 && diff<=5)
                {
                    course_name=cname;
                    flag=1;
                }
                else
                {
                    cout<<"not eligible for "<<cname<<endl;
                }
            }
            }

            else if(ccname=="bsc"||ccname=="BSC"||ccname=="BSc"||ccname=="Bsc")
            {


            if(cname=="Applied Science")
            {

                diff=pct-75;
                if(diff>=0 and diff<=5)
                {
                    course_name=cname;
                    flag=1;
                }
                else
                {
                    cout<<"not eligible for "<<cname<<endl;
                }
            }
            else if(cname=="Applied Mathematics")
            {

                diff=pct-70;
                if(diff>=0 && diff<=5)
                {
                    course_name=cname;
                    flag=1;
                }
                else
                {
                    cout<<"not eligible for "<<cname<<endl;
                }
            }
            else if(cname=="Computer system and Design")
            {

                diff=pct-65;
                if(diff>=0 && diff<=5)
                {
                    course_name=cname;
                    flag=1;
                }
                else
                {
                    cout<<"not eligible for "<<cname<<endl;
                }
            }
            }
            if (flag==0)
            {
                throw " not eligible";
            }

        }
        catch(...)
        {
            cout<<"Invalid Course"<<endl;
        }
        }
};
#endif // COURSE_H_INCLUDED
