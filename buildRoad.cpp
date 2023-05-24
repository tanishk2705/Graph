#include<bits/stdc++.h>
using namespace std;





void addEdge(vector<int> adj[],int v,int u){
        adj[v].push_back(u);
        adj[u].push_back(v);
}

int main(){
        int n=4;
        vector<int> adj[n];
        addEdge(adj,1,2);
        addEdge(adj,2,1);
        addEdge(adj,3,4);
        addEdge(adj,4,3);

        solution obj;



    
}
