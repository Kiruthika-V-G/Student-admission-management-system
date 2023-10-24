#ifndef PAYMENT_H_INCLUDED
#define PAYMENT_H_INCLUDED
#include "Receipt.h"
class Payment
{
private:
    float pay;//if course id== something and community== something
    float book_fee;
    float tuition_fee;
    float computer_fee;
    string paid;
    Receipt recpt;
public:
    Payment()
    {
        pay=0;
        book_fee=10000;
        tuition_fee=0;
        computer_fee=3000;
        paid="n";
    }
    void determinePay(int duration,string comm)
    {
        if(duration==5)
        {
            tuition_fee=45000;
        }
        else
        {
            tuition_fee=30000;
        }
        if(comm=="bc" || comm=="BC")
        {
            tuition_fee-=1000;
        }
        else if(comm=="obc"|| comm=="OBC")
        {
            tuition_fee-=2500;
        }
        pay=book_fee+tuition_fee+computer_fee;
    }
    //book fees tutition library amenities
    void makePayment()
    {
        paid="yes";
        recpt.generateReceipt(book_fee,tuition_fee,computer_fee,pay);
    }
    ~Payment(){cout<<" "<<endl;}
};
#endif // PAYMENT_H_INCLUDED
