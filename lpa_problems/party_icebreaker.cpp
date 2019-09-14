/*********************************************
 *
 *	 Party icebreaker
 *
 ********************************************/

#include <iostream>
#include <algorithm>
#include <vector>

#define VAL 10000

using namespace std;

int p[VAL];
int cont = 0;

bool check(){
	vector<int> ps (p, p+cont);
	sort (ps.begin(), ps.end());
	int i,j,k,aux;
	for(i = 0; i < cont-2; i++){
		j=i+1; k=cont-1;
		while(j!=k){
			aux = ps[i]+ps[j]+ps[k];
			if(aux==0)
				return true;
			else if(aux>0)
				k--;
			else
				j++;
		}
	}
	return false;
}

int main(){
	cont = 0;
	while(cin >> p[cont]){
		if(p[cont]==0){
			if(check())
				cout << "Fair" << endl;
			else
				cout << "Rigged" <<endl;
			cont=-1;
		}
		cont++;
	}


	return 0;
}

