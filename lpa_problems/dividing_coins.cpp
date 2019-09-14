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

int N, S, S2, difference,i,j,n_coins,j_max;
int coins[MAX];
bool DP[MAX][MAX*500];
int main(){
    cin >> N;
	while(N>0){
        cin >> n_coins;
        S=0;
        for(i=0;i<n_coins;i++){
            cin >> coins[i+1];
            S+=coins[i+1];
            DP[i][0]=true;
        }
        S2=floor(S/2);
        for(j=1;j<=S2;j++){
            DP[0][j]=false;
        }
        for(i=1;i<=n_coins;i++){
            for(j=1;j<=S2;j++){
                if(j<coins[i]){
                    DP[i][j]=DP[i-1][j];
                }else{
                    DP[i][j]=(DP[i-1][j]||DP[i-1][j-coins[i]]);
                }
            }
        }
        j_max=0;
        for(j=1;j<=S2;j++){
            if(DP[n_coins][j]==true)
                j_max=j;
        }
        //cout << S << " " << S2 << " " << j_max << endl;
        difference=abs((S-j_max)-j_max);
	    cout << difference << endl;
	    N--;
	}
	return 0;
}

