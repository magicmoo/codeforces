#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
char a[maxn];
int calc(string& s){
    int A=0,B=0,C=0;
    rep(i,0,s.size()){
        if(s[i]=='a') A++;
        else if(s[i]=='b') B++;
        else C++;
    }
    if(A>B && A>C) return s.size();
    else return INF;
}
bool check(int now){
    string str1 = "abbacca",str2 = "accabba";
    bool flag1=1,flag2=1;
    Rep(i,0,6){
        if(a[i+now]!=str1[i]) flag1 = 0;
        if(a[i+now]!=str2[i]) flag2 = 0;
    }
    return flag1 || flag2;
}
int main(){
    // IOS;
    int n;
    CAS {
        scanf("%d %s",&n,a+1);
        string str = "a";
        int ans = INF,first = n;
        Rep(i,1,n){
            if(a[i]=='a'){
                first = i;
                break;
            }
        }
        Rep(i,first+1,n){
            str.push_back(a[i]);
            if(a[i]=='a'){
                ans = min(ans,calc(str));
                str = "a";
            }
        }
        Rep(i,1,n-6){
            if(check(i)){
                ans = min(ans,7);
            }
        }
        if(ans==INF) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
