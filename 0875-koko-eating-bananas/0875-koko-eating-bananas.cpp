class Solution {
public:
    bool canEat(vector<int>&piles, int h, int currLimit) {
        long long int totalhour = 0;
        for(auto i:piles){
            totalhour += 1LL *(i + currLimit - 1)/ currLimit;
        }
        return totalhour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEle = 0;
        for(int i=0;i<piles.size();i++) {
            maxEle = max(maxEle,piles[i]);
        }

        int low =1 , high = maxEle;
        int minAns = maxEle;
        while(low<=high) {
            int mid = low + (high - low) / 2;
            bool ans = canEat(piles,h,mid);
            if(ans) {
                minAns = min(minAns,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        return minAns;
    }
};