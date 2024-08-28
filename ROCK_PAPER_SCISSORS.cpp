#include<iostream>  //playable only on terminal!!
#include<ctime>
using namespace std;

char userchoice();
char compchoice();
void showchoice (char choice);
void winner(char player, char computer);

int main()
{
    char player;
    char computer;
    player = userchoice();
    computer = compchoice();
    cout<<"your choice : ";
     showchoice(player);
    cout<<"computers choice : ";
    showchoice(computer);
    winner(player,computer);
    return 0;
}

char userchoice()
{
    char player;
    cout<<"[ ROCK PAPER SCISSOR GAME! ]"<<'\n';
    do
    {
    cout<<"****************************"<<'\n';
    cout<<"'r' for ROCK"<<'\n';
    cout<<"'p' for PAPER"<<'\n';
    cout<<"'s' for SCISSOR"<<'\n';
    cout<<"choose one : ";
    cin>>player;
    } while (player!='r' && player!='p' && player!='s');

    return player;

}
char compchoice()
{ 
    int a ;
    srand(time(NULL));

    a = rand()% 3 + 1;

    switch(a)
    {
        case 1: return 'r';
                break;
        case 2: return 'p';
                break;
        case 3: return 's';
                break;
    }

}
void showchoice (char choice)
{
    switch(choice)
    {
        case 'r' : cout<<"ROCK"<<'\n';
                   break;
        case 'p' : cout<<"PAPER"<<'\n';
                   break;
        case 's' : cout<<"SCISSOR"<<'\n';
                   break;
    }
}
void winner(char player, char computer)
{
    switch(player)
    {
      case 'r' : if('r'== computer)
                {
                   cout<<"it's a tie! "<<'\n';
                }
                else if('s'== computer)
               {
                   cout<<"you win! "<<'\n';
               }
                else if('p'== computer)
               {
                   cout<<"you lose! "<<'\n';
               }

                   break;
      case 'p' : if('p'== computer)
                {
                   cout<<"it's a tie! "<<'\n';
                }
                else if('r'== computer)
               {
                   cout<<"you win! "<<'\n';
               }
                else if('s'== computer)
               {
                   cout<<"you lose! "<<'\n';
               }

                   break;
      case 's' : if('s'== computer)
                {
                   cout<<"it's a tie! "<<'\n';
                }
                else if('p'== computer)
               {
                   cout<<"you win! "<<'\n';
               }
                else if('r'== computer)
               {
                   cout<<"you lose! "<<'\n';
               }                  
                  break;
    }
}
