class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i, int j, int idx) {
          int n= board.size();
          int m= board[0].size();
          int s= word.length()-1;

          if(j<0||i<0||i>=n||j>=m||board[i][j]!=word[idx]){
            return false;
          }

          if(idx==s){
            return true;
          }
          
          char temp = board[i][j];
          board[i][j] = '#';

          bool found=dfs(board,word,i+1,j,idx+1)||
             dfs(board,word,i-1,j,idx+1)||
             dfs(board,word,i,j+1,idx+1)||
             dfs(board,word,i,j-1,idx+1);

             board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m= board[0].size();
        bool ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if( dfs(board,word,i, j,0)==true){
                return true;
               }
            }
        }
        return false;;
    }
};