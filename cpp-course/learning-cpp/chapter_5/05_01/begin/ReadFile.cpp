#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inStream;
	inStream.open("passphrase.txt");

	string passPhrase;
	
	if (!inStream.fail())
    {
    	inStream >> passPhrase;

    	cout << "The pass phrase is: " << passPhrase << endl;    	
	}
inStream.close();

}
