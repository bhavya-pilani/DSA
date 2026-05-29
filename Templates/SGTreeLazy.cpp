#include<bits/stdc++.h>
using namespace std;

class SGTree {
public:
    vector<int>seg,lazy;

    SGTree(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int idx,int low,int high,vector<int>&arr){
        if(low==high){
            seg[idx]=arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    void update(int idx,int low,int high,int l,int r,int val){
        // update the previous remaining updates 
		// and propogate downwards 

        if(lazy[idx]!=0){
            seg[idx] += (high-low+1)*lazy[idx];

            // propagate
            if(low != high) {
				lazy[2*idx+1] += lazy[idx]; 
				lazy[2*idx+2] += lazy[idx]; 
			}

            lazy[idx]=0;
            
        }


        // no overlap
        if(high<l || r<low ) return;

        // full overlap
        if(l<=low && high<=r){
            seg[idx] += (high-low+1)*val;

            // propagate
            if(low != high) {
				lazy[2*idx+1] += val; 
				lazy[2*idx+2] += val; 
			}
			return;

        }

        // partial overlap
        int mid = (low + high) >> 1;
        update(2*idx+1,low,mid,l,r,val);
        update(2*idx+2,mid+1,high,l,r,val);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];

    }

    int query(int idx,int low,int high,int l,int r){
        // update if any updates are remaining 
		// as the node will stay fresh and updated 
		if(lazy[idx] != 0) {
			seg[idx] += (high - low + 1) * lazy[idx]; 

			// propogate the lazy update downwards
			if(low != high) {
				lazy[2*idx+1] += lazy[idx]; 
				lazy[2*idx+2] += lazy[idx]; 
			}
 
			lazy[idx] = 0; 
		}
 
		// no overlap  
		if(high < l or r < low) {
			return 0; 
		}
 
		// complete overlap 
		if(low>=l && high <= r) return seg[idx]; 
 
		int mid = (low + high) >> 1; 
		int left = query(2*idx+1, low, mid, l, r);
		int right = query(2*idx+2, mid+1, high, l, r);
		return left + right; 
    }

};