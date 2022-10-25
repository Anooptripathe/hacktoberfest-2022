class Solution {
public:
    vector<vector<int>> result;
    
    void dfs(vector<int> &nums, int n){
        
        if(n==nums.size()) {
            result.push_back(nums);
            return;
        }
        else{
            for(int i=n;i<nums.size();i++){
                swap(nums[i],nums[n]);
                dfs(nums,n+1);
                swap(nums[i],nums[n]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return result;
    }
};
