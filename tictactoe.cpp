#include<iostream>

using namespace std;

//[item][item's item]
char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice, row,column;
char turn = 'X';
bool draw = false;
int isOver = 0;
int checkGameOver()
{
    //check for single row and column win
    for(int i = 0; i<3; i++)
    {     cout<<i<<endl;          //row                                                           column
        if((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
        {

            cout<<turn<<" WON."<<endl;
            return isOver = 1;
        }

    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
     
        cout<<turn<<" WON."<<endl;
        return isOver= 1;
    }
    
    //Check if the game can continue
    //run through each slot to see if there is still space to fill
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return isOver = 0;
            }       
        }
    }
  draw = true;
  return isOver = 1;
    
}
void displayBoard()
{
    //Draw the board
    cout<<"\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2]<<endl;
    cout<<"\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2]<<endl;
    cout<<"\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2]<<endl;
}

void play()
{
    while(isOver != 1)
    { 
        cout<<isOver<<endl;
    //player turn (assumming player go first)
    cout<<turn<<" Please enter choice(1-9): ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
            row = 0, column = 0; break;
        case 2:
            row = 0, column = 1; break;
        case 3:
            row = 0, column = 2; break;
        case 4:
            row = 1, column = 0; break;
        case 5:
            row = 1, column = 1; break;
        case 6:
            row = 1, column = 2; break;
        case 7:
            row = 2, column = 0; break;
        case 8:
            row = 2, column = 1; break;
        case 9:
            row = 2, column = 2; break;
        default:
            cout<<"Invalid";
            play();
    }
    if(draw == true)
    {
      cout<<"Game ended in draw."<<endl;
    }
    if(turn == 'X' && board[row][column]!= 'X' && board[row][column]!= 'O' )
    {
        board[row][column] = 'X';
        checkGameOver();
        turn = 'O';
        //displayBoard();
    }
    else if (turn == 'O' && board[row][column]!= 'X' && board[row][column]!= 'O' )
    {
        board[row][column] = 'O';
        checkGameOver();
        turn = 'X';
        //displayBoard();
    }
    else
    {
        cout<<"Location already taken. Pick another location."<<endl;
        play();
    }
      displayBoard();
    }
  
}

int main()
{
        displayBoard();
        play();
   
}
