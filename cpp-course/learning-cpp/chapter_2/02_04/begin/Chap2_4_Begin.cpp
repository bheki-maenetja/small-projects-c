 #include <iostream> 
 #include <ctime>
 #include <cstdlib>
 using namespace std; 
 


int main()  
{  
   
  bool player1Turn = true;  
  bool gameOver = false;    
  
  int chipsInPile = 0;  
  int chipsTaken = 0; 

  //seed the random number generator
   srand(time(0));
  
  
	chipsInPile = (rand() % 100) + 1;
  	cout << "This round will start with " << chipsInPile << " chips in the pile\n";

  	
  
  return 0; 
} 

 
 

