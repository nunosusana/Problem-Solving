/*
 *
 * Funny Encryption Method - p10019
 * 
 */
 

#include <iostream>
#include <string>
#include "string.h"
#include <bitset>

using namespace std;

int N,M,b1,b2,i;

void get_components(){
	b1 = bitset<16>(M).count();
	b2 = 0;
	string digits = to_string(M);
	for(i=0;i<digits.length();i++){
		b2 += bitset<4>((int)digits[i]).count();
	}
}

int main(){
	cin >> N;
	while(N>0){
		N--;
		cin >> M;
		get_components();
		cout << b1 << " " << b2 << endl;
	}
	return 0;
}

