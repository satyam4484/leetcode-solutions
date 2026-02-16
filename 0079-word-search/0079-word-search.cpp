class Solution {
    vector<int>row{0,0,1,-1},col{1,-1,0,0};
public:
    bool valid(int r,int c,string word,int i,vector<vector<char>>&baord) {
        return (r>=0 and c>=0 and r<baord.size() and c<baord[0].size() and baord[r][c]!='@' and baord[r][c] == word[i]);
    }
    void solve(int r,int c,vector<vector<char>>&v,string word,int id,bool &ans) {
        if(id ==word.size()-1) {
            ans = true;
            return;
        }
        char ch = v[r][c];
        v[r][c]='@';
        for(int i=0;i<4;i++) {
            if(valid(r+row[i],c+col[i],word,id+1,v)) {
                solve(r+row[i],c+col[i],v,word,id+1,ans);
            }
        }
        v[r][c] = ch;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size(),m = board[0].size();
        bool ans = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == word[0]) {
                    solve(i,j,board,word,0,ans);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};