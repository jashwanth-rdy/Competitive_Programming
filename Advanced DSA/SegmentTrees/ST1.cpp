#include<iostream>
#include<vector>
using namespace std;

class SegmentTree{
private:
    vector<int> seg;
    int n;
public:
    bool build(int ind,int low,int high,vector<int>& nums){
        if(low==high){
            seg[ind]=nums[low];
            return true;
        }
        int mid = low + (high-low)/2;
        //left child
        bool left = build(2*ind+1,low,mid,nums);
        //right child
        bool right = build(2*ind+2,mid+1,high,nums);
        
        if(left){
            seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        }else{
            seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
        }
        return !left;
    }
    // modify value of an index to new value in the array
    bool modifyIndex(int ind,int low,int high,int &val,int &idx){
        if(low==high){
            if(low==idx)
                seg[ind] = val;
            return true;
        }
        int mid = low + (high - low) / 2;
        bool op;
        if (idx <= mid)
        {
            op = modifyIndex(2*ind+1,low,mid,val,idx);
        }else{
            op = modifyIndex(2*ind+2,mid+1,high,val,idx);
        }
        if(op){
            seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        }else{
            seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
        }
        return !op;
    }
    int query(int index,int val){
        modifyIndex(0,0,n-1,val,index);
        return seg[0];
    }
    SegmentTree(vector<int> &nums){
        n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    int num = pow(2,n);
    vector<int> arr(num);
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    SegmentTree st(arr);
    for(int i=0;i<m;i++){
        int index,val;
        cin>>index>>val;
        cout << st.query(index-1,val) << endl;
    }
    return 0;
}