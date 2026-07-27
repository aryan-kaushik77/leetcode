class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> tailsval;
        vector<int> tailsidx;
        vector<int> parent(n, -1);
        for(int i=0;i<n;i++){
            int pos=lower_bound(tailsval.begin(), tailsval.end(), nums[i]) - tailsval.begin();  //importantttttt
            if(pos==tailsval.size()){
                tailsval.push_back(nums[i]);
                tailsidx.push_back(i);
            }
            else{
                tailsval[pos]=nums[i];
                tailsidx[pos]=i;
            }
            if(pos>0){
                parent[i]=tailsidx[pos-1];
            }
        }
        return tailsval.size();
}
};