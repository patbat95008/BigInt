#include <iostream>
#include <string>
#include "BigInt.h"

using namespace std;

//Prints the contents of the BigInt
//Pre: None
//Post: None
void BigInt::printNum(){
	//if(isNeg) cout << '-';
	for(char c : num)
		cout << c;
}

//Pushes a single digit int to the BigInt at front
//Pre: i must be 1 digit
//Post: num.length = num.length + 1
void BigInt::push(int i){
	this->num.insert(0, to_string(i));
}

//Puts the num from BigInt into a sstream
//Pre: None
//Post: returns ostream filled with BigInt characters
ostream& operator<<(ostream& os,const BigInt& bi){
	//if(bi.isNeg) os<<'-';
	for(int i = 0; i < bi.num.length(); i++){
		os<<bi.num.at(i);
	}
	return os;
}

//Adds 2 BigInt operators together, returns a new third operator
//Pre: none
//Post: Returns a new BigInt with the 2 numbers added together

//b_sum		=	*this	+	b
BigInt BigInt::operator+ (BigInt& b){
	BigInt *b_sum = new BigInt();
	
	if(b.isNeg && !this->isNeg)
		return *this-b;
	else if(!b.isNeg && this->isNeg)
		return b-*this;
	else if(b.isNeg && this->isNeg){}
		//b_sum->isNeg = true;
	
	int carry = 0;
	int i = this->length()-1, j = b.length()-1;
	//for(; i >=0 && j >=0;){
	while(i >= 0 && j >= 0){
		int miniSum = this->at(i) + b.at(j) + carry;
		//cout << "minisum = " << miniSum << '\n';
		carry = miniSum / 10;
		miniSum %= 10;
		
		b_sum->push(miniSum);
		j--; i--;
	}
	
	if(i >= 0){
		//cout << "i>0"<<endl;
		for(; i >=0; i--){
			b_sum->push(this->at(i) + carry);
			carry = 0;
		}
	}else if(j >= 0){
		//cout<<"j>0"<<endl;
		for(; j >= 0; j--){
			b_sum->push(b.at(j) + carry);
			carry = 0;
		}
	}else{
		cout << carry << endl;
		b_sum->push(carry);
	}
	
	return *b_sum;
}

//diff	=	*this	-	b
BigInt BigInt::operator-(BigInt& b){
	BigInt *diff = new BigInt();
	
	int i = this->length()-1, j = b.length()-1;
	
	if(j > i){
		*diff = b - *this;
		//diff->isNeg = true;
		return *diff;
	}
	
	int carry = 0;
	while(i >= 0 && j >= 0){
		int smallDiff = (this->at(i) - b.at(j) - carry);
		if(smallDiff < 0){
			carry = 1;
			diff->push(smallDiff+10);
		}else{
			diff->push(smallDiff);
			carry = 0;
		}
		i--; j--;
	}
	if(i > 0){
		for(; i >= 0; i--)
			diff->push(this->at(i));
	}
	
	return *diff;
}
