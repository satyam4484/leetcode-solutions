class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool f = 0;
        int i=0;
        while(i<word.size()) {
            if(word[i] == ch) {
                f=1;
                break;
            }
            i++;
        }
        if(f) {
            reverse(word.begin(),word.begin()+i+1);
        }
        return word;

    }
};