#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

class SegmentTree
{
private:
    vector<ll> seg;
    vector<ll> lazy;
    int n;
public:
    // build segment tree for sum queries 
    // can modify for max,min queries also
    void build(int ind,int low,int high,vector<ll>& nums){
        if(low==high){
            seg[ind]=nums[low];
            return;
        }
        int mid = low + (high-low)/2;
        //left child
        build(2*ind+1,low,mid,nums);
        //right child
        build(2*ind+2,mid+1,high,nums);
        
        seg[ind] = min(seg[2*ind+1] , seg[2*ind+2]);
    }
    // l,r range to increase value by val
    void modifyRange(int ind,int low,int high,int l,int r,ll val){
        // prev updates are pending
        if(lazy[ind]!=0){
            seg[ind] += lazy[ind];
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
            seg[ind] += val;
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

        seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
    }
    // query for sum of elements in given range lazy updates
    ll queryMinLazy(int ind,int low,int high,int l,int r){
        if(lazy[ind]!=0){
            seg[ind] += lazy[ind];
            if(low!=high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // range lies completely outside
        if(low>r || high<l || low>high) return LLONG_MAX;

        // range completely lies inside
        if(low>=l && high<=r){
            return seg[ind];
        }

        //range overlaps
        int mid = low + (high - low)/2;
        ll leftmin = queryMinLazy(2 * ind + 1, low, mid, l, r);
        ll rightmin = queryMinLazy(2 * ind + 2, mid + 1,high, l, r);

        return min(leftmin ,rightmin);
    }
    ll queryMin(int l,int r){
        if(r<l){
            ll m1 = queryMinLazy(0, 0, n - 1, l, n-1);
            ll m2 = queryMinLazy(0, 0, n - 1, 0, r);
            return min(m1, m2);
        }
        return queryMinLazy(0, 0, n - 1, l, r);
    }
    void queryInc(int l,int r,int v){
        if(r<l){
            modifyRange(0, 0, n - 1, l, n-1, v);
            modifyRange(0, 0, n - 1, 0, r, v);
        }else{
            modifyRange(0, 0, n - 1, l, r, v);
        }
    }
    SegmentTree(vector<ll> &nums){
        n = nums.size();
        seg.resize(4 * n,LLONG_MAX);
        lazy.resize(4 * n,0);
        build(0, 0, n - 1, nums);
    }
};

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    SegmentTree st(arr);
    int m;
    cin >> m;
    while(m--){
        int l, r;
        ll v;
        cin >> l >> r;
        if (cin.peek() != '\n') { 
           cin >> v;
           st.queryInc(l, r, v);
        }
        else
        {
            cout << st.queryMin(l,r) << endl;
        }
    }
    return 0;
}
