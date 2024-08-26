#include<iostream>       // For I/O
#include<vector>         // For Vector
#include<climits>        // For INT_MAX etc..
#include <iostream>      // For standard I/O operations (cin, cout)
#include <vector>        // For dynamic arrays
#include <deque>         // For double-ended queues
#include <list>          // For doubly-linked lists
#include <set>           // For set data structures (unique elements)
#include <map>           // For associative arrays (key-value pairs)
#include <unordered_set> // For hash sets (C++11)
#include <unordered_map> // For hash maps (C++11)
#include <algorithm>     // For algorithms like sort, find, etc.
#include <numeric>       // For numeric operations like accumulate
#include <string>        // For string class
#include <cmath>         // For mathematical functions like sqrt, pow
#include <cstdlib>       // For general utilities like rand, exit

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

ll solution(){
    ll n, k;
    cin >> n >> k;
    vector<pii> arr(n);
    for (ll i = 0; i < n;i++){
        cin >> arr[i].first;
    }
    for (ll i = 0; i < n;i++){
        cin >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    ll lo = 0, hi = 2e9, ans = arr[n - 1].first;
    while(lo<=hi){
        ll mid = lo + (hi - lo)/2;
        ll req = (n + 1) / 2 + 1;
        ll rem = k;
        for (ll i = n - 1; i >= 0;i--){
            if(arr[i].first>=mid)
                req--;
            else if(arr[i].second){
                if(mid-arr[i].first<=rem){
                    rem -= mid - arr[i].first;
                    req--;
                }
            }
        }
        if(req<=0){
            ans = max(ans, arr[n - 1].first + mid);
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    ll j = -1;
    for (ll i = n - 1; i >= 0;i--){
        if(arr[i].second){
            j = i;
            break;
        }
    }
    if(j!=-1){
        if(j<=n/2-1){
            ans = max(ans,arr[n / 2].first + arr[j].first + k);
        }else{
            ans = max(ans,arr[n / 2 - 1].first + arr[j].first + k);
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solution() << endl;
    }
    return 0;
}