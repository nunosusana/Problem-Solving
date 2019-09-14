/*********************************************
 *
 *	Chess game
 *
 ********************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define KNIGHTS 30
#define BOUNDS 500

int n_knight, total=0;
int knight[KNIGHTS][3];		// x, y, moves
bool map[BOUNDS][BOUNDS]={{false}};


void recursiva(int moves, int knix, int kniy){
	if(!map[knix][kniy]){
		map[knix][kniy]=true; 
		total++;
	}
	if(moves>0){
		recursiva(moves-1,knix-1,kniy+2);
		recursiva(moves-1,knix-2,kniy+1);
		recursiva(moves-1,knix-2,kniy-1);
		recursiva(moves-1,knix-1,kniy-2);
		recursiva(moves-1,knix+1,kniy-2);
		recursiva(moves-1,knix+2,kniy-1);
		recursiva(moves-1,knix+2,kniy+1);
		recursiva(moves-1,knix+1,kniy+2);
	}
}

int main(){
	
	cin >> n_knight;
	for(int i = 0; i < n_knight; i++){
		cin >> knight[i][0] >> knight[i][1] >> knight[i][2];
		knight[i][1]+=250;
		knight[i][0]+=250;
	}

	for(int i=0;i<n_knight;i++){
		recursiva(knight[i][2],knight[i][0],knight[i][1]);
	}

	cout << total << endl;
	return 0;
}


