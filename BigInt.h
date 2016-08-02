#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BigInt{
	private:
		string num;
		bool isNeg;
		
	public:
		BigInt(){num = ""; isNeg = false;}
		//BigInt contstructor
		//Note: if negitive, use bool to mark rather than string.
		BigInt(int i){
			//(i < 0) ? (isNeg = false) : (isNeg = true);
			isNeg = false;
			if(isNeg) num = to_string(i);
			else num = to_string(i);
		}
		
		void printNum();
		BigInt operator+ (BigInt&);
		BigInt operator- (BigInt&);
		friend ostream& operator<<(ostream& os, const BigInt& bi);
		int at(int d){return (int)(num.at(d) -'0');}
		int length(){return num.length();}
		void push(int);
};


