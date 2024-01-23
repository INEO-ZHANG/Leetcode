#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            bool flag=0;\
            //按从小到大插入（插入比nums2[i]大的nums1[j]前面
            for(int j=0;j<nums1.size();j++){
                if(nums2[i]<nums1[j]){
                    flag=1;
                    nums1.insert(nums1.begin()+j,nums2[i]);
                    break;
                }
            }
            //若没有nums1[j]大于nums2[i]则插入尾部
            if(flag==0)nums1.push_back(nums2[i]);
        }
        double mid;
        if(nums1.size()%2==0){
            mid=(nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
        }
        else{
            mid=nums1[nums1.size()/2];
        }
        return mid;
    }   
};

int main(){
    vector<int> nums1={1,2},nums2={4};
    Solution s1;
    double mid=s1.findMedianSortedArrays(nums1,nums2);
    cout<<mid;
}