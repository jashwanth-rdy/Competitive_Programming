// Author : Jashwanth Reddy

#include <bits/stdc++.h>

using namespace std;

#define ll             long long
#define vi              vector<int>
#define vvi             vector<vi>
#define vpii            vector<pair<int, int>>
#define pb              push_back
#define ppb             pop_back
#define read(a)         for(auto &x : a) cin >> x;
#define ump             unordered_map
#define pii             pair<int, int>
#define F               first
#define S               second
#define all(x)          (x).begin(), (x).end()
#define cyes            cout << "YES" << endl;
#define cno             cout << "NO" << endl;

int power(int a, int b, int m){ if(b == 0) return 1; int ans = power(a, b/2, m); ans = (ans * ans)%m; if(b&1) return (ans * a)%m; return ans;}
int inv(int a, int m){ a %= m; return power(a, m - 2, m);}
int add(int a, int b, int m){a %= m; b %= m; return (((a + b)%m) + m)%m;}
int sub(int a, int b, int m){a %= m; b %= m; return (((a - b)%m) + m)%m;}
int mul(int a, int b, int m){a %= m; b %= m; return (((a * b)%m) + m)%m;}
int div(int a, int b, int m){a %= m; b %= m; return (mul(a, inv(b, m), m) + m) %m;}
int nCr(int n, int r, int m, vector<int>& fact){return mul(fact[n], inv(mul(fact[r], fact[n - r], m), m), m);}

int mod = 1e9 + 7;

ll solve(int ind,char s,vector<ump<char,pair<ll,char>>> &dp1,vector<ump<char,ll>> &dp2){
    if(ind==dp1.size()){
        return 0;
    }
    if(dp2[ind].count(s)){
        return dp2[ind][s];
    }
    ll ans = solve(ind+1,s,dp1,dp2);
    ans = max(ans, dp1[ind][s].first + solve(ind+1,dp1[ind][s].second,dp1,dp2));
    return dp2[ind][s] = ans;
}
void solution()
{
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);
    read(arr);
    vector<ump<char,pair<ll,char>>> dp1(n);
    ump<char,char> next;
    next['n']='a';
    next['a']='r';
    next['r']='e';
    next['e']='k';
    next['k']='n';
    for(int i=0;i<n;i++){
        for(auto e : next){
            ll ans = 0;
            char sr = e.first;
            for(auto c : arr[i]){
                if(next.count(c)){
                    ans--;
                }
                if(c==sr){
                    sr = next[sr];
                    if(c=='k'){
                        ans += 10;
                    }
                }
            }
            dp1[i][e.first] = {ans,sr};
        }
    }
    vector<ump<char,ll>> dp2(n);
    cout << solve(0,'n',dp1,dp2) << endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
    return 0;
}