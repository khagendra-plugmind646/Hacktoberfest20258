class Solution {
public:
int dp[71][71][71];

    int solve( vector<vector<int>>& matrix,int row, int col1,int col2) {
         int n = matrix.size(), m = matrix[0].size();
         if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return 0;
    if (row == matrix.size() - 1) {
            if (col1 == col2) return matrix[row][col1];
            return matrix[row][col1] + matrix[row][col2];
        }
     if(dp[row][col1][col2]!=-1){
        return dp[row][col1][col2];
     }    
int cherry=matrix[row][col1];
if(col1!=col2){
    cherry+=matrix[row][col2];
}
int ans=0;
      for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int c1=col1+i;
            int c2=col2+j;
int r=row+1;
ans=max(ans,solve(matrix,r,c1,c2));

        }
      }
      return dp[row][col1][col2]=cherry+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {

memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
       return solve(grid,0,0,m-1);
    }
};
