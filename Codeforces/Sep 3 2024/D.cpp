// Author : Jashwanth Reddy

#include <bits/stdc++.h>

using namespace std;

#define int             long long
#define vi              vector<int>
#define vvi             vector<vi>
#define vpi             vector<pair<int, int>>
#define pb              push_back
#define ppb             pop_back
#define read(a)         for(auto &x : a) cin >> x;
#define ump             unordered_map
#define pii             pair<int, int>
#define F               first
#define S               second
#define sqrt(x)         sqrtl(x)
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

void solution()
{
    int n;
    cin >> n;
    vi a1;
    vi a2;
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    for (int i = 0; i < n;i++){
        int x, y;
        cin >> x >> y;
        if(y==0){
            a1.push_back(x);
            mp1[x]++;
        }else{
            a2.push_back(x);
            mp2[x]++;
        }
    }
    sort(all(a1));
    sort(all(a2));
    int i = 0,
    j = 0;
    int ans = 0;
    int n1 = a1.size(),n2=a2.size();
    // cout << n1 << n2 << endl;
    while (i < a1.size() && j < a2.size())
    {
        if(a1[i]==a2[j]){
            // cout << i << " " << j << endl;
            ans += (i + j);
            ans += n1-i-1;
            ans += n2-j-1;
            // cout << n1-i-1 << endl;
            i++;
            j++;
        }
        else if(a1[i]<a2[j])
        {
            i++;
        }else{
            j++;
        }
    }
    
    for(auto v : a2){
        if(mp1.count(v-1) && mp1.count(v+1)){
            ans++;
        }
    }
    for(auto v : a1){
        if(mp2.count(v-1) && mp2.count(v+1)){
            ans++;
        }
    }
    
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
    return 0;
}