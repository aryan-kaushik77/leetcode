class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()==1){
            return 1;
        }
        unordered_map<int,int>mp;
        int left=0;
        int ans=0;
        for(int right=0;right<fruits.size();right++){
            mp[fruits[right]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            
            if(mp.size()==2){
                ans=max(right-left+1,ans);
            }
        }
    if(mp.size()==1){
        return mp.begin()->second;
    }
    else{
        return ans;
    }
    }
};