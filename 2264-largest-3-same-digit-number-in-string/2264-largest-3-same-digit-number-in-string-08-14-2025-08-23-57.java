class Solution {
    public String largestGoodInteger(String num) {
        String ans = "";
        String curr = "" + num.charAt(0);

        for (int i = 1; i < num.length(); i++) {
            if (num.charAt(i) == num.charAt(i - 1)) {
                curr += num.charAt(i);
            } else {
                if (curr.length() >= 3) {
                    String sub = curr.substring(0, 3);
                    ans = sub.compareTo(ans) > 0 ? sub : ans;
                }
                curr = "" + num.charAt(i);
            }
        }

        // Final check after loop
        if (curr.length() >= 3) {
            String sub = curr.substring(0, 3);
                    ans = sub.compareTo(ans) > 0 ? sub : ans;
        }

        return ans;
    }
}
