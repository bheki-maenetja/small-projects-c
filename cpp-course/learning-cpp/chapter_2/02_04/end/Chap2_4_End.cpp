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
  //variable declarations
  bool player1Turn = true;  
  bool gameOver = false;    
  int chipsInPile = 0;  
  int chipsTaken = 0; 

  //seed the random number generator
   srand(time(0));
  
  
  //start the game with a random number of chips in the pile
  
	chipsInPile = (rand() % MAX_CHIPS) + 1;
  	cout << "This round will start with " << chipsInPile << " chips in the pile\n";
	cout << "You can take up to " << static_cast<int>(MAX_TURN * chipsInPile) << endl;
  			
  return 0; 
} 

 
 

