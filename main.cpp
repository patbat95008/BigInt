#include <iostream>
#include "BigInt.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BigInt t1(10);
	BigInt t2(960);
	cout << t1 << '+' << t2 << '=' <<'\n';
	
	t1 = t1+t2;
	
	cout << t1;
	return 0;
}
