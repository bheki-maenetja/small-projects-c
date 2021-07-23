///////////////////////////
//calculate charge
/* By Erin Colvin 
   add tax to the order */
//////////////////////////
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const float TAX_RATE = .04;

int main()
{
	//declare variables
	string name;
	float price = 4.50;
	int qty = 0; 
	float charge = 0, taxCharge = 0;
	
	//get input from user
	cout << "Enter the number you wish to order: \n";
	cin >> qty; 
	
	//format output
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	//calculations
	charge = price * qty;
	taxCharge = charge * TAX_RATE;
	cout <<"The tax charged is: $ " << setprecision(2) << taxCharge << endl;
	charge = charge + taxCharge;
			
	//formated output
	cout << " Your total charge: $ " << setprecision(2) << charge << endl;

	return 0;
}
