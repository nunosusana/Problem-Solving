/*********************************************
 *
 *	 Knapsack
 *
 ********************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdlib.h>


using namespace std;

#define MAX_W 100000001
#define MAX_OBJ 21

short N, test_cases,i;
short ant,act;
long tmp,max_w,j;
long DP[2][MAX_W];
int val[MAX_OBJ];
long wei[MAX_OBJ];

int main(){

    cin >> test_cases;
	while(test_cases>0){
        cin >> N;
        max_w=0;
        for(i=1;i<=N;i++){
            cin >> val[i] >> wei[i];
            max_w+=wei[i];
        }
        for(j=0;j<=max_w;j++)
            DP[0][j]=DP[1][j]=0;
        ant=1;
        act=0;
        for(i=1;i<=N;i++){
            act=ant;
            ant=!ant;
            for(j=1;j<=max_w;j++){
                if(j<wei[i]){
                    DP[act][j]=DP[ant][j];
                }else{
                    DP[act][j]=max(DP[ant][j],DP[ant][j-wei[i]]+val[i]);
                }
            }
        }
        tmp=DP[act][max_w];
        for(j=0;j<=max_w;j++){
            if(tmp!=DP[act][j]){
	            cout << DP[act][j] << " " << j << endl;
	            tmp=DP[act][j];
	        }
	    }
	    test_cases--;
	}
	return 0;
}


