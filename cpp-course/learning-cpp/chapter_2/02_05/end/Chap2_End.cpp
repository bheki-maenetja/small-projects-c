#include <iostream> 
 #include <ctime>
 #include <cstdlib>
using namespace std; 
 

//set the constant for MAX_TURN to the number of chips allowed per turn
// for example, .25 will only allow players to take up to 1/4th of the 
// total chips in the pile. Let's use 1/2, or .5 as our max. 
//Also need a constant for the maximum number of chips per pile. If too
// many game can go on forever, so we will use 100
const float MAX_TURN = .5;
const int MAX_CHIPS = 100;

int main()  
{  
   
  // This variable keeps track of whose turn it is.  We can name it 
  // player1Turn, then when it's true, it's player 1's turn, when it's
  // false, it's player 2's turn
  bool player1Turn = true;  
 //declare a boolean variable for gameOver to determine when the game is done
  bool gameOver = false;    
  //We need 3 integers, one for chips in pile, next for chips taken and last
  // we will keep a counter of how many moves it took. Initialize all to 0
  int chipsInPile = 0;  
  int chipsTaken = 0; 

  
  //We will put the names of the players into an array of strings with 2 playerNames
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

  	
  
  return 0; 
} 

 
 

