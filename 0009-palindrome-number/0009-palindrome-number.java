class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 ) return false;
        // approach could b we can convert to string and then check reversed approach.
        // will cause some string space building.
        String str = String.valueOf(x);
        int size = str.length();

        for (int i = 0; i < size / 2; i++) {
            if (str.charAt(i) != str.charAt(size - i - 1)) {
                return false;
            }
        }
        return true;
    }
}