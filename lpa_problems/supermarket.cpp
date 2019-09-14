/*********************************************
 *
 *	 Dividing Coins
 *
 ********************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdlib.h>


using namespace std;

#define MAX 100
#define INF 999999

int N, minimo,i,j,n_coins,change, n_formas;
int coins[MAX];
int DP[MAX][MAX*500];
int main(){
    cin >> N;
	while(N>0){
	    cin >> change;
        cin >> n_coins;
        for(i=0;i<n_coins;i++){
            cin >> coins[i+1];
            DP[i][0]=0;
        }
        for(j=1;j<=change;j++){
            DP[0][j]=INF;
        }
        for(i=1;i<=n_coins;i++){
            for(j=1;j<=change;j++){
                if(j<coins[i]){
                    DP[i][j]=DP[i-1][j];
                }else{
                    DP[i][j]=min(DP[i-1][j],1+DP[i][j-coins[i]]);
                }
            }
        }
        n_formas=0;

	    cout << n_formas << endl;
	    N--;
	}
	return 0;
}

