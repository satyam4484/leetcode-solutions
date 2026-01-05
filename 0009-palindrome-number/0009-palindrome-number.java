class Solution {
    public boolean isPalindrome(int x) {
        if(x< 0) return false;
        int prev =x;
        long curr = 0;
        while(x!=0) {
            curr = curr*10 + x%10;
            x/=10;
        }
        return curr == prev;
    }
}