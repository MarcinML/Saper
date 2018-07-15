#include "board.h"

Board::Board()
{
    for(int i=0; i<10; i++)
    {
        for(int k=0; k<10; k++){
            board[i][k] = '0';
            userBoard[i][k] = '.' ;
        }
    }


}

int Board::checkGame()
{
    return 0;
}

void Board::show()
{
    char c='a';
    char d='a';
    std::cout<<"  ";
    for(int a=0; a<10; a++) {std::cout<<c++; }std::cout<<std::endl;
    for(int i=0; i<10; i++)
    {
        std::cout<<d++<<" ";
        for(int k=0; k<10; k++){
            if(userBoard[i][k] =='/' || userBoard[i][k] == 0){std::cout<<'.';}else
        std::cout<<userBoard[i][k];
    }std::cout<<std::endl;
}
}
void Board::userInput()
{
    std::string input;
    std::cin>>input;
    int x,y;
    x=input[0] - 97;
    y=input[1] - 97;
    checkInternal(x,y);
}

void Board::checkInternal(int x, int y)
{
    if(board[x][y] == 'b') std::cout<<"lose";
    if(board[x][y] == '0'){
        checkEmptyField(x, y);


    }
    if(board[x][y] != '0' && board[x][y] !='b') userBoard[x][y] = board[x][y];
}

void Board::getMines()
{
    int x,y;
    int mines =10;

    while(mines)
    {
        x=rand()% 10;
        y=rand()% 10;
       if(board[x][y] == 'b')continue;
       board[x][y] = 'b';
       mines--;
    }
    for(int i=0; i<10; i++)
        for(int k=0; k<10; k++)
        {
            if(board[i][k] == 'b')
            {
                if(board[i][k+1] != 'b' && k<9 && k>0 && i>0 && k<9) board[i][k+1] +=1;
                if(board[i-1][k] != 'b' && k<9 && k>0 && i>0 && k<9) board[i-1][k] +=1;
                if(board[i][k-1] != 'b' && k<9 && k>0 && i>0 && k<9) board[i][k-1] +=1;
                if(board[i+1][k] != 'b' && k<9 && k>0 && i>0 && k<9) board[i+1][k] +=1;
                if(board[i-1][k-1] != 'b' && k<9 && k>0 && i>0 && k<9) board[i-1][k-1] +=1;
                if(board[i+1][k+1] != 'b' && k<9 && k>0 && i>0 && k<9) board[i+1][k+1] +=1;
                if(board[i-1][k+1] != 'b' && k<9 && k>0 && i>0 && k<9) board[i-1][k+1] +=1;
                if(board[i+1][k-1] != 'b' && k<9 && k>0 && i>0 && k<9) board[i+1][k-1] +=1;
            }
}
}
void Board::checkEmptyField(int x, int y)
{
    if(x >= 0 && y >= 0 && x < 10 && y < 10)
    {
        if(board[x][y] == '0' && userBoard[x][y] == '.' && board[x][y] != 'b'){
            userBoard[x][y] = '0';
            checkEmptyField(x - 1, y - 1);
            checkEmptyField(x, y - 1);
            checkEmptyField(x + 1, y - 1);
            checkEmptyField(x - 1, y);
            checkEmptyField(x + 1, y);
            checkEmptyField(x -1, y + 1);
            checkEmptyField(x, y + 1);
            checkEmptyField(x + 1, y + 1);
        } else {
            moveTouserBoard(x, y);
        }
    }
}
void Board::moveTouserBoard(int x, int y)
{
    userBoard[x][y] = board[x][y];
}



