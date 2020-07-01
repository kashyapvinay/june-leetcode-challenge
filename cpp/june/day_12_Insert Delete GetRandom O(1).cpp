class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> mp;
    vector<int> nums;

    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            mp[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = mp.find(val);
        if(it == mp.end()){
            return false;
        }
        if(val != nums[nums.size()-1]){
            int idx = it->second, val2 = nums[nums.size() - 1];
            swap(nums[nums.size()-1], nums[idx]);
            mp[val] = nums.size()-1;
            mp[val2] = idx;
        }
        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
