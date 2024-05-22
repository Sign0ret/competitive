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

    lli p1 = 0;
    lli p2 = 0;
    lli ans = 0;
    while(p1<n && p2<m){
        if (v1[p1] == v2[p2]){
            lli add1=1;
            while(p1<n-1 && v1[p1]==v1[p1+1]){
                p1++;
                add1++;
            }
            lli add2=1;
            while(p2<m-1 && v2[p2]==v2[p2+1]){
                p2++;
                add2++;
            }
            p1++;
            ans = ans + (add1*add2);    
        } else if (v1[p1]>v2[p2]){
            p2++;
        } else {
            p1++;
        }
    }
    while(p1<n) {
        if(v1[p1] == v2[m-1]){
            ans++;
        }
        p1++;
    }
    while(p2<m){
        if(v1[n-1] == v2[p2]){
            ans++;
        }
        p2++;
    }
    cout << ans << " ";

    return 0;
}