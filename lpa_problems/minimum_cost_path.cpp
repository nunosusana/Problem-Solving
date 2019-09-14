#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n,i,j,s,t,queue,u,v;
int g[501][501];
int dist[501][2];

int smallest(){
    int idx=0;
    int small = 1000;
    for(i=1; i<=n; i++){
        if(dist[i][1]==0){
            if(dist[i][0]<small){
                small=dist[i][0];
                idx=i;
            }
        }
    }
    dist[idx][1]=1;
    queue--;
    return idx;
}

int dijkstra(){
    for(v = 1; v <= n; v++){
        dist[v][0]=1000*n;      //distância máxima
        dist[v][1]=0;           //não utilizado
    }
    dist[s][0]=0;
    dist[s][1]=0;
    queue=n;
    while(queue>0){
        u = smallest();
        if(u==t)
            break;
        for(v = 1; v <= n; v++){
            if(g[u][v]>0)
                if(dist[v][0]>dist[u][0]+g[u][v])
                    dist[v][0]=dist[u][0]+g[u][v];
        }
    }

    return dist[t][0];
}


int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }

    while(cin >> s){
        cin >> t;
        cout << dijkstra() << endl;
    }
    return 0;
}



