
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double amount;
int n,m,coordenadas[750][2],connections[1000][2];
int r[1000],set[1000];

typedef struct _s1{
    int x,y;
}vertex;

typedef struct _s2{
    int parent,son;
    double distance;
}edge;

edge edges[1000];

double euclidean_distance(int x1, int y1,int x2,int y2){
    return (double) sqrt( fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1 - y2) * fabs(y1 - y2));
}

int compare_distance (const void * a, const void * b){
    return( ((edge *)a)->distance - ((edge *)b)->distance );
}

//qsort(edges,m,sizeof(edge),compare_distance);

void link(int a, int b){
    if(r[a]>r[b]){
        set[b]=a;
    }else{
        set[a]=b;
        if(r[a]==r[b])
            r[b]++;
    }
}

int find(int a){
    if(set[a]!=a)
        set[a]=find(set[a]);
    return set[a];
}

void union_find(int a, int b){
	link(find(a), find(b));
}

void kruskal(){
    for(int i=0; i<n; i++){
        set[i]=i;
        r[i]=0;
    }
    double A = 0;
    //sort the edges of E into non-decreasing order by weight w
    qsort(edges,m,sizeof(edge),compare_distance);
    for(int i = 0; i<m; i++){
        cout<<edges[i].distance<<endl;
    }
    for(int i = 0; i<m; i++){
        if(find(edges[i].parent)!=find(edges[i].son))
            A = A + edges[i].distance;
        union_find(edges[i].parent,edges[i].son);
    }
    printf("%.2lf\n",A);
}

int main(){
    while(cin>>n){
        for(int i = 0; i<n; i++){
            cin>>coordenadas[i][0];
            cin>>coordenadas[i][1];
        }
        cin>>m;
        cout << "m = "<< m << endl;
        for(int i = 0; i<m; i++){
            cin>> connections[i][0];
            cin>> connections[i][1];
            edges[i].parent=connections[i][0];
            edges[i].son=connections[i][0];
            edges[i].distance=euclidean_distance(coordenadas[connections[i][0]][0],coordenadas[connections[i][0]][1],coordenadas[connections[i][1]][0],coordenadas[connections[i][1]][1]);
        }
        kruskal();
    }
    return 0;
}
