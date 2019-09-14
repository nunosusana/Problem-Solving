/*********************************************
 *
 *	 Joint Vacation Problem
 *
 ********************************************/

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 201
#define INF 9999

using namespace std;

int n,finish,queue;
int matrix[MAX_N][MAX_N];
int distances[MAX_N][2];

int get_smallest_d(){
    int  smallest=INF;
    int idx = 0;
    for(int i = 1; i<=n; i++){
        if(distances[i][1]==0){
            if(smallest>distances[i][0]){
                idx=i;
                smallest=distances[i][0];
            }
        }
    }
    queue--;
    distances[idx][1]=1;
    return idx;
}

int dijkstra(){
    for(int i = 0; i <= n; i++){
        distances[i][0]=INF;
        distances[i][1]=0;
    }
    distances[1][0]=0;
    distances[1][1]=0;
    int u;
    queue=n;
    while(queue>0){
        u = get_smallest_d();
        //cout << "choosed: " << u <<endl;
        if (u == finish)
            break;
        for(int v = 1; v <= n; v++){
            //cout << "matrix["<<u<<"]["<<v<<"] = "<<matrix[u][v]<<"\n";
            if(matrix[u][v]>0)
                if(distances[v][0]>distances[u][0]+matrix[u][v])
                    distances[v][0]=distances[u][0]+matrix[u][v];
        }
    }
    return distances[finish][0];
}

int main(){
    cin >> n >> finish;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    cout << dijkstra() << endl;
	return 0;
}

