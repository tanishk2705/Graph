#include<bits/stdc++.h>
using namespace std;

class Solution{
        private:
        void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat){
                int n=mat.size();
                int m=mat[0].size();
                vis[row][col]=1;
                int delrow[]={-1,0,1,0};
                int delcol[]={0,1,0,-1};

                for(int i=0;i<4;i++){
                        int nrow=row+delrow[i];
                        int ncol=col+delcol[i];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='0'){
                               dfs(nrow,ncol,vis,mat);
                        }
                }
        }

        public:
        vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat){
            vector<vector<int>> vis(n,vector<int>(m,0));
        //     first row
              for (int i = 0; i < m ; i++)
              {
                    if(mat[0][i]=='0' && !vis[0][i])  {
                            dfs(0,i,vis,mat);
                    }
              }

              //     first col
              for (int i = 0; i < n ; i++)
              {
                    if(mat[i][0]=='0' && !vis[i][0])  {
                            dfs(i,0,vis,mat);
                    }
              }


              //     last row
              for (int i = 0; i < m ; i++)
              {
                    if(mat[n-1][i]=='0' && !vis[n-1][i])  {
                            dfs(n-1,i,vis,mat);
                    }
              }


              //     last col
              for (int i = 0; i < n ; i++)
              {
                    if(mat[i][m-1]=='0' && !vis[i][m-1])  {
                            dfs(i,m-1,vis,mat);
                    }
              }


              for (int i = 0; i < n; i++)
              {
                      for (int j = 0; j < m; j++)
                      {
                              if(mat[i][j]=='0' && !vis[i][j]){
                                      mat[i][j]='X';
                              }
                      }
                      
              }

              return mat;
              
              
    
    

    }
};

int main(){
        vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}