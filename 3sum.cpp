class Solution {
public:
  
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>res;
       std::sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++)
        {
            int target= -nums[i];
            int front=i+1;
            int end=nums.size()-1;
            while(front<end)
            {
                int sum=nums[front]+nums[end];
                if (sum<target)
                    front++;
                else if (sum>target)
                    end--;
                else{
                    vector<int>temp={nums[i],nums[front],nums[end]};
                    res.push_back(temp);
                    while(front<end && nums[front]==temp[1]) front++;
                    while(front<end && nums[end]==temp[2]) end--;
                }
            }
            
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
            
        }
        return res;
        
    }
};
