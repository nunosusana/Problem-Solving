/*********************************************
 *
 *	 Check the parentheses
 *
 ********************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define VAL 128

using namespace std;

int n;
char str[VAL];


bool check(int idx, int open_r, int open_l){
	if(open_l < 0 || open_r < 0)
		return false;
	if(idx < strlen(str)){
		if(str[idx] == '('){
			return check(idx++, open_r, open_l++);
		}
		else if(str[idx] == '['){
			return check(idx++, open_r++, open_l);
		}
		else if(str[idx] == ')'){
			return check(idx++, open_r, open_l--);
		}
		else if(str[idx] == ']'){
			return check(idx++, open_r--, open_l);
		}
	}else{
		if(open_l != 0 || open_r != 0)
			return false;
	}
	return true;
}


int main(){

	cin >> n;
	while(n>0){
		n--;
		cin >> str;
		if(strlen(str) == 0)
			cout << "YES" << endl;
		else if(strlen(str)%2==1)
			cout << "NO" << endl;
		else
			if(check(0,0,0))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
	}

	return 0;
}

