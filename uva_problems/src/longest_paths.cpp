/*
 *
 * Longest Paths problem - p10000
 * 
 */
 
#include <iostream>
#include <cstring>

#define SIZE 101

using namespace std;

short n,s,p,q,i,j,k,ant,act;
short graph[SIZE][SIZE];
int used[SIZE];
int max_len, finish;

void longest(int lvl){
	if(lvl<n){
		for(i=1;i<=n;i++){
			if(used[i]==lvl){
				for(j=1;j<=n;j++){
					if(graph[i][j]){
						used[j]=lvl+1;
					}
				}
			}
		}
		longest(lvl+1);
	}else{
		max_len=0;
		finish=0;
		for(i=1;i<=n;i++){
			if(max_len<used[i]-1){
				finish=i;
				max_len=used[i]-1;
			}
		}
	}
}



int main(){
	k=1;
	cin >> n;
	while(n>0){
		finish=0;
		max_len=0;
		memset(used,0,sizeof(int)*SIZE);
		memset(graph,0,sizeof(short)*SIZE*SIZE);
		cin >> s;
		cin >> p >> q;
		while(p!=0 && q!=0){
			graph[p][q]=1;
			cin >> p >> q;
		}
		used[s]=1;
		longest(1);
		cout<<"Case "<<k<<": The longest path from "<<s<<" has length "<<max_len<<", finishing at "<<finish<<".\n\n";
		k++;
		cin >> n;
	}
	return 0;
}


