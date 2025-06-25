class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> indices;
        for (int i = 0; i < n; i++)
            indices[nums[i]] = i;
        
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (indices.find(complement) != indices.end() && indices[complement] != i)
                return vector<int>{i, indices[complement]};
        }

        return vector<int>();
    }
};