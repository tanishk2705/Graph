#include <bits/stdc++.h>
using namespace std;

class Solution{
         private:
        void bfs(int row,int col,vector<vector<int>> &grid, vector<vector<int>> &vis){
                      vis[row][col]=1;
                      queue<pair<int,int>>q;
                      q.push({row,col});
                      int n=grid.size();
                      int m=grid[0].size();

                      while(!q.empty()){
                              int row=q.front().first;
                              int col=q.front().second;
                              q.pop();

                              for (int delRow = -1; delRow<=1; delRow++)
                              {
                                      for (int delCol = -1; delCol<=1; delCol++)
                                      {
                                             int nrow=row+delRow;
                                             int ncol=col+delCol;
                                              if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                                                      vis[nrow][ncol]=1;
                                                      q.push({nrow,ncol});
                                              }
                                      }
                                      
                              }
                              
                      }
                     
                      
        }
        public:
        int numIsland(vector<vector<int>> &grid){
              int n=grid.size();
              int m=grid[0].size();
              int cnt=0;

              vector<vector<int>> vis(n,vector<int>(m,0));
              for (int i = 0; i < n; i++)
              {
                      for (int j = 0; j < m; j++)
                      {
                              if(grid[i][j]==1 && !vis[i][j]){
                                      cnt++;
                                      bfs(i,j,grid,vis);

                              }
                      }
                      
              }
              return cnt;
              
        }
};

int main(){
        vector<vector<int>> grid={
             {0,1},{1,0},{1,1},{1,0}
        };
        
        Solution obj;
        int ans=obj.numIsland(grid);
        cout<<ans;

        
}