#include<bits/stdc++.h>

using namespace std;
class Solution {
    private:
     int atmost(vector<int>&nums,int k){
        int l=0,r=0,sum=0;
        int count=0;
        if(k<0) return 0;
        while(r<nums.size()){
             sum+=nums[r]%2;
             while(sum>k){
                sum-=nums[l++]%2;

             }
             count+=(r-l+1);
             r++;
        }
        return count;
     }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};
int main(){
    Solution s;
    vector<int> nums={1,1,2,2,2,100};
    int k=2;
    cout<<s.numberOfSubarrays(nums,k)<<endl;
    return 0;
    
}
