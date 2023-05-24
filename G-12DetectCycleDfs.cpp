#include <bits/stdc++.h>
using namespace std;
 
 class Solution{
 public:
        private:
        bool detect(int node,int papa,vector<int> adj[],vector<int> &vis){
                vis[node]=1;

                for(auto it : adj[node]){
                        if(!vis[it]){
                               if(detect(it,node,adj,vis)==true){
                                       return true;
                               }
                        }
                        else if(it!=papa){
                              return true;
                        }
                }

                return false;

        }
        
        public:
        bool isCycle(int v,vector<int> adj[]){
             vector<int> vis(v,0);
             for (int i = 0; i < v; i++)
             {
                     if(detect(i,-1,adj,vis)==true){
                             return true;
                     }
             }
             return false;
             
        }
 };

int main(){
           // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
     Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}