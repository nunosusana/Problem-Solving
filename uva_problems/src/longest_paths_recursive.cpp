/*
 *
 * Longest Paths problem - p10000
 * (This solution dont achieve the result in time)
 */
 
#include <iostream>
#include <cstring>

#define SIZE 101

using namespace std;

short n,s,p,q,i;
short graph[SIZE][SIZE];
int used[SIZE];
int max_len, finish;

void longest(int len, short curr, short visited){
	if(len>max_len){
		max_len=len;
		finish=curr;
	}
	if(visited<n){
		for(short j = 1; j<=n; j++){
			if(graph[curr][j]){
				if(!used[j]){
					used[j]=1;
					longest(len+1,j,visited+1);
					used[j]=0;
				}
			}
		}
	}
}

int main(){
	i=1;
	cin >> n;
	while(n>0){
		finish=0;
		max_len=0;
		memset(graph,0,sizeof(short)*SIZE*SIZE);
		cin >> s;
		cin >> p >> q;
		while(p!=0 && q!=0){
			graph[p][q]=1;
			cin >> p >> q;
		}
		used[s]=1;
		longest(0,s,1);
		used[s]=0;
		cout<<"Case "<<i<<": The longest path from "<<s<<" has length "<<max_len<<", finishing at "<<finish<<".\n\n";
		i++;
		cin >> n;
	}
	return 0;
}


