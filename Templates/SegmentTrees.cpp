#include<bits/stdc++.h>
using namespace std;

class SGTree{
public:
    vector<int>seg;

    SGTree(int n){
        seg.resize(4*n);
    }

    void build(int idx,int low,int high,vector<int>&arr){
        if(low==high){
            seg[idx]=arr[low];
            return;
        }

        int mid = (low+high)>>1;

        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    void update(int idx,int low,int high,int i,int val){

        if(low==high){
            seg[idx]=val;
            return;
        }

        int mid=(low+high)>>1;

        if(i>mid) update(2*idx+2,mid+1,high,i,val);
        else update(2*idx+1,low,mid,i,val);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    int query(int idx,int low,int high,int l,int r){
        if(high<l || r<low) return 0;

        if(l<=low && high<=r) return seg[idx];

        int mid = (low + high) >> 1;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);

        return left + right;
    }

};