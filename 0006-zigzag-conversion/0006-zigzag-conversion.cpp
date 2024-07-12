class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows,"");
        bool dir = true;
        if(numRows <=1 ) return s;
        int row = 0;

        for(int i = 0 ; i < s.size() ; i++ ) {
          ans[row].push_back(s[i]);
          if(row == 0) {
            dir = true;
          } else if(row == numRows-1) {
            dir = false;
          }

          (dir) ? row++ : row--;
        }

        string S="";
        for(auto i:ans) {
          S+=i;
        }
        return S;
    }
};