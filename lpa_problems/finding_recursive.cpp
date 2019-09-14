/*********************************************
 *
 *	 Finding Reursive Functions
 *
 ********************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;

#define DIM 999

int graph[DIM][DIM];
int n_funcs[DIM];
int visitado[DIM];
int n;

int DFS(int v,int f_init){
    visitado[v]=1;
    for(int u = 0; u < n; u++){
        if(graph[v][u]){
            if(!visitado[u]){
                 if(DFS(u,f_init))
                    return 1;
            }else{
                if(u==f_init)
                    return 1;
            }
        }
    }
    return 0;
}

int main(){
    memset(graph,0,(DIM*DIM)*sizeof(int));
    int tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> n_funcs[i];
        for(int j = 0; j < n_funcs[i]; j++){
            cin >> tmp;
            graph[i][tmp] = 1;
        }
	}

	for(int i=0;i<n;i++){
	    memset(visitado,0,DIM*sizeof(int));
	    if(DFS(i,i)==1)
	        cout << i << endl;
	}
	return 0;
}


