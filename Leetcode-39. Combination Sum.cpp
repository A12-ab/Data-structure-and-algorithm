class Solution {
    public:
        set<vector<int>>st;
        void comSum(int idx, vector<int>&ar,vector<vector<int>>&ans,vector<int>&comb,int target){
            if(idx==ar.size() || target<0){
                return;
            }
    
            if(target==0){
                if(st.find(comb)==st.end()){
                    ans.push_back(comb);
                    st.insert(comb);
                }
                
                return;
            }
    
            comb.push_back(ar[idx]);
            comSum(idx+1,ar,ans,comb,target-ar[idx]);
            comSum(idx,ar,ans,comb,target-ar[idx]);
            comb.pop_back();
            comSum(idx+1,ar,ans,comb,target);
            
        }
        vector<vector<int>> combinationSum(vector<int>& ar, int target) {
            vector<vector<int>>ans;
            vector<int>comb;
            comSum(0,ar,ans,comb,target);
            return ans;
            
        }
    };