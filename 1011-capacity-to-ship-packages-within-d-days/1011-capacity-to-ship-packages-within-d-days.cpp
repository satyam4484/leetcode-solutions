class Solution {
public:
    bool loadItemsToShip(vector<int>&weights,int days, int currWeight) {
        int totalDays = 0;
        int totalWeights = 0;
        for(auto weight: weights) {
            if(weight > currWeight) return false;
            if(totalWeights + weight <= currWeight){
                totalWeights+=weight;
            }else{
                totalDays++;
                totalWeights = weight;
            }
        }
        if(totalWeights!=0 && totalWeights <= currWeight) totalDays++;
        return totalDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeights = 0;
        int minCapacity = 5001;
        for(auto weight:weights) {
            totalWeights+=weight;
            minCapacity=min(minCapacity,weight);
        }
        int minWeights = totalWeights;
        while(minCapacity <= totalWeights) {
            int currWeight = (minCapacity + totalWeights) / 2;
            cout<<minCapacity<<" "<<totalWeights<<"-->"<<currWeight<<endl;

            bool canAllWeightsLoaded = loadItemsToShip(weights,days,currWeight);
            cout<<canAllWeightsLoaded<<endl;
            if(canAllWeightsLoaded) {
                minWeights=min(minWeights,currWeight);
                totalWeights = currWeight-1;
            }else{
                minCapacity = currWeight+1;
            }
        }
        return minWeights;
    }
};