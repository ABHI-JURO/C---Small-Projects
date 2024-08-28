#include<iostream>
#include<iomanip>

void showbalance(double a);
double deposit();
double withdraw(double b);


int main()
{    
    double balance = 1231.32; 
    int choice;
    do
    {

    std::cout<<"******************"<<'\n';
    std::cout<<"enter your choice"<<'\n';
    std::cout<<"******************"<<'\n';
    std::cout<<"1. SHOW BALANCE"<<'\n';
    std::cout<<"2. DEPOSIT"<<'\n';
    std::cout<<"3. WITHDRAW"<<'\n';
    std::cout<<"4. EXIT"<<'\n';
    std::cin>>choice;

    std::cin.clear();
    fflush(stdin);

    switch(choice)
    {
        case 1:showbalance(balance);
                break;
        
        case 2:balance+=deposit();
               showbalance(balance);
                break;
        
        case 3:balance-=withdraw(balance);
               showbalance(balance);
                break;
        
        case 4:std::cout<<"thank for visiting !"<<'\n';
                break;
        
        default:std::cout<<"invalid choice"<<'\n';
                break;        
    }
    } while (choice!=4 );
    
    return 0;
}

void showbalance(double a)
{
    std::cout<<"your balance is : $"<<std::setprecision(2)<<std::fixed<<a<<'\n';
}

double deposit()
{
    double amount;
    std::cout<<"please enter the amount : $";
    std::cin>>amount;
    if(amount>0)
    {
        return amount;
    }
    else
    {
        std::cout<<"please enter a valid amount"<<'\n';
    }
}

double withdraw(double b)
{   
    double amount;
    std::cout<<"please enter the amount : $";
    std::cin>>amount;

    if (amount>b)
    {
       std::cout<<"insufficient balance "<<'\n';
    }
    else if(amount>0)
    {
        return amount;
    }
    else
    {
        std::cout<<"please enter a valid amount"<<'\n';
    }
}