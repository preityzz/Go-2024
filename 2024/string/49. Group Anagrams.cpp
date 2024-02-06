class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
   //tc=(n*klogk) sc=(nk)
        // vector<vector<string>>ans;
        // unordered_map<string,vector<string>>mp;

        // for(int i=0;i<strs.size();i++){
        //  //first stirng
        //     string s=strs[i];
        //     sort(s.begin(),s.end());
        //     mp[s].push_back(strs[i]);
        // }

        // for(auto it:mp){
        //     ans.push_back(it.second);
        // }
        // return ans;


        //just remove te sorting technique and ussli jgh frequemcy le lenge
          vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;

        for(int i=0;i<strs.size();i++){
         //only change
         string hashstring="";
         string s=strs[i];

         vector<int>freq(26,0);
         for(auto ch:s) freq[ch-'a']++;
         for(int i=0;i<26;i++){
           hashstring.push_back(freq[i]);
            hashstring.push_back('#');
         }
            mp[hashstring].push_back(strs[i]);
        }

        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};