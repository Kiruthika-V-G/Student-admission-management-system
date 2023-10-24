#ifndef RECEIPT_H_INCLUDED
#define RECEIPT_H_INCLUDED
#include <iomanip>
using namespace std;
//course details student details (age id) payment method system.cls()
class Receipt
{

    public:
        static int receipt_no;
        void generateReceipt(float bookFee,float tuition,float computer,float total)
        {
            cout<<"\t\t\t\t---------------RECEIPT-----------------"<<endl;
            cout<<"\t\t\t\tReceipt number:"<<receipt_no<<endl<<endl;
            cout<<"\t\t\t\tBOOK FEE                :"<<fixed<<setprecision(2)<<bookFee<<endl;
            cout<<"\t\t\t\tTUITION FEE             :"<<fixed<<setprecision(2)<<tuition<<endl;
            cout<<"\t\t\t\tCOMPUTER FEE            :"<<fixed<<setprecision(2)<<computer<<endl;
            cout<<"\t\t\t\t---------------------------------------"<<endl;
            cout<<"\t\t\t\tTOTAL FEES              :"<<fixed<<setprecision(2)<<bookFee+tuition+computer<<endl;
            cout<<"\t\t\t\t---------------------------------------"<<endl;
            receipt_no++;
        }
};

int Receipt::receipt_no=1;
#endif // RECEIPT_H_INCLUDED
