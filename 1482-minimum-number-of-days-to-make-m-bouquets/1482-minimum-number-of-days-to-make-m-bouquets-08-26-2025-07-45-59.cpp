class Solution {
public:
    bool canMake(vector<int>&flowers,int m, int day, int k) {
        int count = 0;
        int countofB = 0;
        for(auto flower: flowers) {
            if(flower <= day) {
                count++;
            }else{
                countofB+=(count/k);
                count = 0;
            }
        }
        countofB+=(count/k);
        return countofB >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minD = INT_MAX;
        int maxD = INT_MIN;
        
        for(auto day: bloomDay) {
            minD = min(minD,day);
            maxD = max(maxD, day);
        }

        int ans = INT_MAX;
        while(minD <= maxD) {
            int mid = (minD + maxD)/2;
            if(canMake(bloomDay,m,mid,k))   {
                ans = min(ans,mid);
                maxD = mid-1;

            }else{
                minD = mid+1;
            }
        }
        return ans == INT_MAX? -1 : ans;
    }
};