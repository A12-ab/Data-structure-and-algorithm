class Solution {
    public:
        bool isPal(string s){
            string s2=s;
            reverse(s2.begin(),s2.end());
            return s2==s;
        }
        void getAllpart(string s, vector<string>&partitions, vector<vector<string>>&ans){
            if(s.size()==0){
                ans.push_back({partitions});
            }
            for(int i=0; i<s.size(); i++){
                string part=s.substr(0,i+1);
                if(isPal(part)){
                    partitions.push_back(part);
                    getAllpart(s.substr(i+1),partitions,ans);
                    partitions.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>>ans;
            vector<string>partitions;
            getAllpart(s,partitions,ans);
    
            return ans;
        }
        
    };