#include <bits/stdc++.h>
using namespace std;
class Solution{
        public:
        int orangesRotting(vector<vector<int>> &grid){
                int n=grid.size();
                int m=grid[0].size();
                int cntFresh=0;
                vector<vector<int>> vis(n,vector<int>(m,0)); 
                queue<pair<pair<int,int>,int>> q;
                for (int i = 0; i < n; i++)
                {
                        for(int j=0;j<m;j++){
                                if(grid[i][j]==2){
                                    q.push({{i,j},0});
                                    vis[i][j]=2;
                                }
                                if(grid[i][j]==1){
                                     cntFresh++;   
                                }

                        }

                        
                }


                int tm=0;
                int delRow[]={-1,0,1,0};
                int delCol[]={0,1,0,-1};
                int cnt=0;
                while(!q.empty()){
                        int row=q.front().first.first;
                        int col=q.front().first.second;
                        int t=q.front().second;
                        tm=max(t,tm);
                        q.pop();


                        for (int i = 0; i < 4; i++)
                        {
                                int nRow=row+delRow[i];
                                int nCol=col+delCol[i];
                                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && vis[nRow][nCol]!=2 && grid[nRow][nCol]==1 ){
                                        q.push({{nRow,nCol},t+1});
                                        vis[nRow][nCol]=2;
                                        cnt++;
                                }
                                
                        }                        


                        

                        
                }

                if(cnt!=cntFresh){
                        return -1;
                }

                /* for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if(vis[i][j]!=2 && grid[i][j]==1){
                                        return -1;
                                }
                        }
                        
                } */

                return tm;
                
                

        }
};

int main(){
     vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
     Solution obj;
     int ans=obj.orangesRotting(grid);
     cout<<ans;
//     You do not have to change grid[i][j]=1---->grid[i][j]=2 You just have to count time taken

}