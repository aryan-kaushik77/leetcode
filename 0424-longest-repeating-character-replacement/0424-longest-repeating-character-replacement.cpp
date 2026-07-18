class Solution {
public:
    int characterReplacement(string s, int k) {
    unordered_map<char,int>mp;
    int maxfreq=0;
    int left=0;
    int ans=0;
    for(int right=0;right<s.size();right++){
        mp[s[right]]++;
        maxfreq=max(maxfreq,mp[s[right]]);
        while(right-left+1>maxfreq+k){
            mp[s[left]]--;
            left++;
        }
        ans=max(right-left+1,ans);
    }
    return ans;    
    }
};