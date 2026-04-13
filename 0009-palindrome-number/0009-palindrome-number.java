class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 ) return false;
        // approach could b we can convert to string and then check reversed approach.
        // will cause some string space building.
        int newValue = 0;
        int preValue = x;
        while(x>0) {
            newValue = newValue*10 + x%10;
            x = x/10;
        }
        return newValue == preValue;
    }
}