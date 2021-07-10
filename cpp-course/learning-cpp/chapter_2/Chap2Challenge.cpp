#include <iostream> 
 #include <ctime>
 #include <cstdlib>
using namespace std; 
 
const float MAX_TURN = .5;
const int MAX_CHIPS = 100;

int main()  
{  
   
  
  bool player1Turn = true;  
 
  bool gameOver = false;    
  
  int chipsInPile = 0;  
  int chipsTaken = 0; 

  string playerNames[2];
  
  //seed the random number generator
   srand(time(0));
  
  //ask the players for their names, then store in an array
  cout << "Player 1, please enter your name: ";
  cin >> playerNames[0];
  cout << "\nThanks and good luck!" << endl << "Player 2, please enter your name: ";
  cin >> playerNames[1];
  cout << "\nThanks and good luck! \n";
  
  //start the game with a random number of chips in the pile
  
	chipsInPile = (rand() % MAX_CHIPS) + 1;
  	cout << "This round will start with " << chipsInPile << " chips in the pile\n";
    cout << "You can take up to " << static_cast<int>(MAX_TURN * chipsInPile) << endl;
  	//create a variable to hold the integer value - static_cast<int>(MAX_TURN * chipsInPile) 
  	//Make sure you assign that at the right place, the compiler won't go back up and update
  	//Then knowing the max number that is allowed to be taken per turn, use that in the creation
  	//of a  add a random number to be inserted as the number taken. We will use this
  	//to play against the computer
  
  
  return 0; 
} 

 
 

