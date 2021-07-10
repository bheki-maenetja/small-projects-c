#include <iostream> 
 #include <ctime>
 #include <cstdlib>
using namespace std; 
 


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

 
 

