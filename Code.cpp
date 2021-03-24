#include <iostream>
#include <cmath>
using namespace std ;
class Account {
    public :
    string c_name ;
    int acct_no ;
    float bal = 5000 ;            //Default account balance
    float min_bal = 1000.00 ;     //Minimum required balance for current account            
    string acct_type ;             
    void Deposit();               
    void Withdrawal() ;
    void SavAcct();
    void CurrAcct();
};
void Account::SavAcct(){
    float p_amt = bal;
    float amt;
    float rate = 0.08 ;
    int t = 1 ;                            //Compounded annually.....
    amt = p_amt*pow((1 + rate/100),t);
    bal = p_amt + amt ;
    cout<<"\nAvaliable balance after adding compound interest : Rs."<<bal<<"\n";
    cout<<"Cheque-Book facility is not available in Saving Account.\n\n";
}
void Account::CurrAcct(){
    cout<<"\nAvailable balance : Rs."<<bal<<"\n";
    cout<<"Interest facility not available in Current Account.\n";
    cout<<"Cheque-Book facility is available in Current Account.\n\n";
    float fine = 0.03 ;
    if (bal<min_bal){
        bal = bal - fine*bal ;
        cout<<"Availabe balance after fine : Rs."<<bal<<"\n\n";
    }
}
void Account::Deposit(){
    float dep;
    cout<<"\nEnter deposit amount : Rs.\n";
    cin>>dep;
    bal = bal + dep ;
    cout<<"Available balance : Rs."<<bal<<"\n\n";
}
void Account::Withdrawal(){
    float withD;
    cout<<"\nEnter withdrawal amount : Rs.\n";
    cin>>withD;
    if (withD>bal){
        cout<<"Insufficient amount\n\n";
    }
    else{
        bal = bal - withD ;
        cout<<"Available balance : Rs."<<bal<<"\n\n";
    }
}
int main(){
    Account c1 ;
    cout<<"Account holder name : ";
    getline(cin,c1.c_name);
    cout<<"Account number of "<<c1.c_name<<" : ";
    cin>>c1.acct_no;
    cin.ignore();
    cout<<"Account type : ";
    getline(cin,c1.acct_type);
    if (c1.acct_type == "Saving Account" || c1.acct_type == "saving account"){
        c1.SavAcct();
    }
    else if (c1.acct_type == "Current Account" || c1.acct_type == "current account"){
        c1.CurrAcct();
    }
    else {
        cout<<"INVALID INPUT.\n\n";
    }                           
    int option ;
    int n=0;
    do{
        cout<<"\t\t\t\tBanking System Program\n\n";
        cout<<"Available options : \n\n";
        cout<<"1) Deposit Money\n";
        cout<<"2) Withdraw Money\n";
        cout<<"3) Exit\n\n";
        cout<<"Select option : ";
        cin>>option;
        switch(option){
            case 1 : c1.Deposit();
            break ;
            case 2 : c1.Withdrawal();
            break;
            case 3 : cout<<"Thanks for coming.....\n";
            break ;
        }
        n = n + 1;
    }
    while(n<1);
}
