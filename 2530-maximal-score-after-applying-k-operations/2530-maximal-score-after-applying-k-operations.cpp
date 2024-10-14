class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Create a max-heap (priority queue) to store all elements of the array 'nums'.
        // This allows us to access the largest element efficiently.
        priority_queue<int> pq;
        for(auto i : nums) {
            pq.push(i);  // Push each element of the array into the priority queue.
        }

        long long ans = 0;  // Variable to store the final score.

        // Perform k operations to maximize the score.
        while(k--) {
            int val = pq.top();  // Extract the largest element from the heap.
            pq.pop();  // Remove the largest element from the heap.

            // If the value is 1, we can optimize by breaking early.
            // Since repeatedly choosing 1 will only add 1 to the score in remaining steps.
            if(val == 1) {
                ans += 1LL * (k + 1);  // Add 1 for each of the remaining operations.
                break;  // Break the loop early as further operations on 1 won't change the result.
            }

            ans += 1LL * val;  // Add the value of the largest element to the score.

            // Reduce the value by applying ceil(val / 3) and push it back into the heap.
            pq.push(ceil((double)val / 3));
        }

        return ans;  // Return the maximum possible score after k operations.
    }
};