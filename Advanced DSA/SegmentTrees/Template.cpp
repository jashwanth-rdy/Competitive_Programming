#include<iostream>
#include<vector>
using namespace std;

class SegmentTree{
private:
    vector<int> seg;
    vector<int> lazy;
    int n;
public:
    // build segment tree for sum queries 
    // can modify for max,min queries also
    void build(int ind,int low,int high,vector<int>& nums){
        if(low==high){
            seg[ind]=nums[low];
            return;
        }
        int mid = low + (high-low)/2;
        //left child
        build(2*ind+1,low,mid,nums);
        //right child
        build(2*ind+2,mid+1,high,nums);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    // modify value of an index to new value in the array
    void modifyIndex(int ind,int low,int high,int &val,int &idx){
        if(low==high){
            if(low==idx)
                seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (idx <= mid)
        {
            modifyIndex(2*ind+1,low,mid,val,idx);
        }else{
            modifyIndex(2*ind+2,mid+1,high,val,idx);
        }
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    // query to give sum of elements in the given range both includsive;
    int querySum(int ind, int low, int high, int l, int r)
    {
        // range completely lies
        if(low>=l && high<=r){
            return seg[ind];
        }
        // range outlies
        if(low>r || high<l) return 0;

        // range overlaps
        int mid = low + (high-low)/2;

        int left = querySum(2*ind+1,low,mid,l,r);
        int right = querySum(2*ind+2,mid+1,high,l,r);

        return left+right;
    }
    // l,r range to increase value by val
    void modifyRange(int ind,int low,int high,int l,int r,int val){
        // prev updates are pending
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            // not leaf node
            if(low!=high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // range lies completely outside
        if(low>r || high<l || low>high) return;

        // range completely lies inside
        if(low>=l && high<=r){
            seg[ind] += (high - low + 1) * val;
            if(low!=high){
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        //range overlaps
        int mid = low + (high - low)/2;
        modifyRange(2 * ind + 1, low, mid, l, r, val);
        modifyRange(2 * ind + 2, mid + 1,high, l, r, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    // query for sum of elements in given range lazy updates
    int querySumLazy(int ind,int low,int high,int l,int r){
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // range lies completely outside
        if(low>r || high<l || low>high) return 0;

        // range completely lies inside
        if(low>=l && high<=r){
            return seg[ind];
        }

        //range overlaps
        int mid = low + (high - low)/2;
        int leftsum = querySumLazy(2 * ind + 1, low, mid, l, r);
        int rightsum = querySumLazy(2 * ind + 2, mid + 1,high, l, r);

        return leftsum + rightsum;
    }
    SegmentTree(vector<int> &nums){
        n = nums.size();
        seg.resize(4 * n);
        lazy.resize(4 * n,0);
        build(0, 0, n - 1, nums);
    }
};
