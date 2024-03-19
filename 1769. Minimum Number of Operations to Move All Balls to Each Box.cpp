class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i=0;i<boxes.size();i++){
            int s=0;
            for(int j=0;j<boxes.size();j++){
                if(abs(i-j)>=1 && boxes[j]=='1'){
                    s=s+abs(j-i);
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};