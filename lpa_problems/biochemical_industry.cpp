/*******************************************************************************
 *
 * Jocas in the biochemical industry
 *
 ******************************************************************************/
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define INF 10000

int m,n,i,j,k,s,t,q;
int g[401][401];
int delta[401][401];


void floyd_warshall(){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            delta[i][j]=g[i][j];
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                delta[i][j]=min(delta[i][j],delta[k][j]+delta[i][k]);
            }
        }
    }

}


int main(){
    cin>>n; //compounds
    cin>>m; //transformations
    for (i = 0; i <= n; i++){
        for (j = 0; j <= n; j++){
            g[i][j] = INF;
        }
    }
    while(m>0){
        cin >> i;
        cin >> j;
        cin >> g[i][j];
        m--;
    }
    memset(delta,0,401*401*sizeof(int));
    floyd_warshall();
    cin >> q;
    for(int f = 0; f<q; f++){
        cin >> s >> t;
        if(delta[s][t] != INF){
            cout << delta[s][t] << endl;
        }else{
            cout << "Impossible!" << endl;
        }
    }
    return 0;
}


