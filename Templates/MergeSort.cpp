#include <bits/stdc++.h>
using namespace std;

void merge(int low,int high,int mid,vector<int>&nums){
    int left=low;
    int right=mid+1;

    vector<int>temp;

    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]) temp.push_back(nums[left++]);
        else temp.push_back(nums[right++]);
    }

    while(left<=mid) temp.push_back(nums[left++]);
    
    while(right<=high) temp.push_back(nums[right++]);
    
    for(int i=low;i<=high;i++){
        nums[i] = temp[i-low];
    }

}

void mergeSort(int low,int high,vector<int>&nums){
    if(low>=high) return;

    int mid=(low+high)/2;

    mergeSort(low,mid,nums);
    mergeSort(mid+1,high,nums);

    merge(low,high,mid,nums);

}

int main() {

    vector<int>nums={5,6,8,1,2,1,5};

    mergeSort(0,6,nums);

    for(int x:nums) cout<<x<<" ";
    
    return 0;
}