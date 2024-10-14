class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto i:nums) {
            pq.push(i);
        }
        long long ans = 0;
        while(k--) {
            int val = pq.top();
            pq.pop();
            if(val == 1) {
                cout<<"k--"<<k<<" "<<ans<<endl;
                ans+=1LL*(k);
                break;
            }
            ans +=1LL*val;
            pq.push(ceil((double)val / 3));
        }
        return ans;
    }
};