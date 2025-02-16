class Solution {
    public:
        void getAllsubsets(vector<int>&nums, vector<int>&ans,vector<vector<int>>&allsubsets, int i){
            if(i==nums.size()){
                allsubsets.push_back(ans);
                return;
            }
            ans.push_back(nums[i]);
            getAllsubsets(nums,ans,allsubsets,i+1);
    
            ans.pop_back();
            int idx=i+1;
            while(idx<nums.size() && nums[idx]==nums[idx-1]){
                idx++;
            }
            getAllsubsets(nums,ans,allsubsets,idx);
    
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>>allsubsets;
            vector<int>ans;
            getAllsubsets(nums,ans,allsubsets,0);
            return allsubsets;
            
        }
    };