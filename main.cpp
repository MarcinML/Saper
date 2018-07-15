#include <iostream>
#include "board.h"
#include <cstdlib>
#include <ctime>



int main()
{
    srand(time(nullptr));
    Board board;
    board.getMines();
    board.show();


    while(true){

      board.userInput();
      system("clear");
      board.show();
      if(board.checkGame() == -1)
      {
          std::cout<<"You lose";
          break;
      }
      if(board.checkGame() == 1)
      {
          std::cout<<"You won!";
          break;
      }


}
    return 0;
}
