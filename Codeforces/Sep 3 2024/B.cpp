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
    vector<string> arr(n);
    read(arr);
    for (int i = n - 1; i >= 0;i--){
        for (int j = 0; j < 4;j++)
        {
            if(arr[i][j]=='#'){
                cout << j + 1 << " ";
                break;
            }
        }
    }
    cout << endl;
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