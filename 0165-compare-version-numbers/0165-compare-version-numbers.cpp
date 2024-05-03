class Solution {
public:
    
    int compareVersion(string v1, string v2) {
        int n1=v1.size(),n2=v2.size();
        int x1 = 0,x2=0;
        for(int i=0,j=0;i<n1 or j<n2;i++,j++) {
            while(i<n1 and v1[i]!='.'){
                x1 = x1*10+(v1[i++]-'0');
            }

            while(j<n2 and v2[j]!='.'){
                x2 = x2*10+(v2[j++]-'0');
            }
            if(x1 < x2) return -1;
            else if(x1 > x2) return 1;
            x1=0,x2=0;
        }
        return 0;
    }
};