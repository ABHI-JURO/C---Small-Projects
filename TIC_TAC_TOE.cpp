#include<iostream>  //playable only on terminal!!
#include<ctime>
using namespace std;

void board(char *space)

{
    cout<<'\n';
    cout<<"     |     |     "<<'\n';
    cout<<"  "<< space[0] <<"  |  "<<space[1]<<"  |  "<<space[2]<<"  "<<'\n';
    cout<<"_____|_____|_____"<<'\n';
    cout<<"     |     |     "<<'\n';
    cout<<"  "<< space[3] <<"  |  "<<space[4]<<"  |  "<<space[5]<<"  "<<'\n';
    cout<<"_____|_____|_____"<<'\n';
    cout<<"     |     |     "<<'\n';
    cout<<"  "<< space[6] <<"  |  "<<space[7]<<"  |  "<<space[8]<<"  "<<'\n';
    cout<<"     |     |     "<<'\n';
    cout<<'\n';
}

void Player(char *space, char player)
{
    int num;

    do
    {
        cout<<"Enter the number between (1-9) : ";
        cin>>num;
        num--;        
        if(space[num]==' ')
        {
            space[num] = player;
            break;
        }

    }while(!num > 0 || !num < 8);
}

void Comp(char *space, char comp)
{
    int num;
    srand(time(NULL));
    while(true)
    {
        num = rand() % 9;
        if(space[num]==' ')
        {
            space[num] = comp;
            break;
        }
    }
}

bool Winner(char *space, char player, char comp)
{
   if(space[0] != ' ' && space[0] == space[1] && space[1] == space[2])
   {
     space[0] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else if(space[3] != ' ' && space[3] == space[4] && space[4] == space[5])
   {
     space[3] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else if(space[6] != ' ' && space[6] == space[7] && space[7] == space[8])
   {
     space[6] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else if(space[0] != ' ' && space[0] == space[3] && space[3] == space[6])
   {
     space[0] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else if(space[1] != ' ' && space[1] == space[4] && space[4] == space[7])
   {
     space[1] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else if(space[2] != ' ' && space[2] == space[5] && space[5] == space[8])
   {
     space[2] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else if(space[0] != ' ' && space[0] == space[4] && space[4] == space[8])
   {
     space[0] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else if(space[2] != ' ' && space[2] == space[4] && space[4] == space[6])
   {
     space[2] == player ? cout<<"YOU WIN!\n" : cout<<"YOU LOSE!\n";
   }

   else
   {
     return false;
   }

   return true;
}

bool Tie(char *space)   
{
    for(int i = 0;i<9;i++)
    {
        if(space[i]==' ')
        {
            return false;
        }
        
    }
    cout<<"IT'S A TIE!\n";
    return true;
}



int main()
{
    char space[9] ={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char comp = 'O';
    bool running = true;

    board(space); 

    while(running)
    {
        Player(space,player);
        board(space);
        if(Winner(space, player , comp))
        {
            running = false;
            break;
        }
        else if(Tie(space))
        {
          running = false;
          break;  
        }

        Comp(space,comp);
        board(space);
        if(Winner(space, player , comp))
        {
            running = false;
            break;
        }
        else if(Tie(space))
        {
          running = false;
          break;  
        }
    }
    cout<<"THANK'S FOR PLAYING!"<<endl;
    return 0;
}