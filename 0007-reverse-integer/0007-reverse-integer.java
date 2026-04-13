class Solution {
    public int reverse(int x) {
        String curr = String.valueOf(x);
        boolean isNegative = false;
        if(curr.charAt(0) == '-') {
            isNegative = true;
            curr = curr.substring(1);
        }
        String reversed = new StringBuilder(curr).reverse().toString();
        long value = Long.parseLong(reversed);
        if(isNegative) {
            value = -1 * value;
        }
        if(value > Integer.MAX_VALUE || value < Integer.MIN_VALUE) {
            return 0;
        }
        return (int)value;
    }
}