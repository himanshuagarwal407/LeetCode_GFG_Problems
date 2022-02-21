class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> out;
        
        map.insert(std::make_pair(nums[0],0));
        int i=1;
        while(i<nums.size()){
            auto it = map.find(target-nums[i]);
            if( it != map.end()){
                out.push_back(i);
                out.push_back(it->second);
                return out;
            }
            map.insert(std::make_pair(nums[i],i));
            i++;
        }
        return out;
    }
};