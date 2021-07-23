#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inStream;
	inStream.open("passphrase.txt");
	int userGuess = 0;
	string passPhrase;
	
	if (!inStream.fail())
    {
   		while(inStream >> passPhrase)
 		{
			cout << "The pass phrase is: " << passPhrase << endl;
			cout << "What is your answer?\n";
			cin >> userGuess;
			if (userGuess == passPhrase.length())
			{
				cout << "Congrats\n";
			}
			else
			{
				cout << "Sorry try again later\n";
			}
		}
	}
inStream.close();

}
