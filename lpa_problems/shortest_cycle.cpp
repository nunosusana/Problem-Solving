#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n,i,j;
int g[100][100];
int min_cycles = 100;
int mark[100];

int DFS(int v, int n_arcs){
    mark[v]=1;
    for(int u=0;u<n;u++){
        if(g[v][u]){
            if(!mark[u]){
                return DFS(u,n_arcs+1);
            }else{
                return n_arcs+1;
            }
        }
    }
    return 100;
}

int main(){
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    for(i=0;i<n;i++){
        memset(mark,0,100);
        j = DFS(i,0);
        min_cycles=j<min_cycles?j:min_cycles;
    }
    cout << min_cycles << endl;
    return 0;
}



