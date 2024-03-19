class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //solving this using prefix sum 
        int sum = 0;
        unordered_map<int,int> mp;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum -=1;
            }
            if(nums[i]==1){
                sum+=1;
            }
            if(mp.find(sum)!=mp.end()){
                maxi = max(maxi,i-mp[sum]);
            }
            if(sum == 0){
                maxi = max(maxi,i+1);
            }
            else if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
        }
        return maxi;
    }
};