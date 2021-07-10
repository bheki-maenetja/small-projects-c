 #include <iostream> 
 #include <ctime>
 #include <cstdlib>
 using namespace std; 
 


int main()  
{  
   
  // This variable keeps track of whose turn it is.  We can name it 
  // player1Turn, then when it's true, it's player 1's turn, when it's
  // false, it's player 2's turn
  bool player1Turn = true;  
 //declare a boolean variable for gameOver to determine when the game is done
  bool gameOver = false;    
 
  int chipsInPile = 0;  
  int chipsTaken = 0; 

   cout << "How many chips would you like in your starting pile? \n";
  
   cin >> chipsInPile;
   cout << "This round will start with " << chipsInPile << " chips in the pile\n";

  	
  
  return 0; 
} 

 
 

