#include <bits/stdc++.h> 
///opt/homebrew/Cellar/gcc/13.2.0/bin/g++-13 main.cpp && ./a.out < in.txt > out.txt
using namespace std;

typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;

#define f first
#define s second
#define endl '\n'
#define sz(s) lli(s.size())
#define all(s) s.begin(), s.end()
#define pb push_back
#define fore(i,a,b) for(lli i = (a), TT=(b);i<TT;++i)
#define _ ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

int main() {
    lli n,m;
    cin>>n>>m;
    vector<lli> v1;
    vector<lli> v2;
    fore(i,0,n){
        lli x;
        cin>>x;
        v1.pb(x);
    }
    fore(i,0,m){
        lli x;
        cin>>x;
        v2.pb(x);
    }
    lli p = 0;
    vector<lli> ans;
    fore(i,0,m){
        while(p<n && v2[i]>v1[p]){
            p++;
        }
        ans.pb(p);
    }
    fore(i,0,ans.size()){
        cout << ans[i] << " ";
    }

    return 0;
}