class CustomStack {
public:
    vector<int>v;
    int mx;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        v.push_back(x);
        if(v.size() > mx) v.pop_back();
    }
    
    int pop() {
        if(v.size() == 0) return -1;
        int ele = v[v.size()-1];
        v.pop_back();
        return ele;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)v.size());i++) {
            v[i] = v[i] + val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */