#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 2e18;
ll solve(ll num,ll Max,ll len){
    num -= len*9;
    if(num < 0) return -1;
    if(num<=Max){
        ll ans = 0;
        rep(i,0,len){
            ans *= 10;
            ans += 9;
        }
        return ans*10+num;
    }
    stack<ll> s;
    s.push(Max);
    num -= Max;
    Rep(i,1,len) s.push(9);
    while(num){
        if(num<=9){
            s.push(num);
            num = 0;
        }else{
            s.push(9);
            num -= 9;
        }
    }
    ll ans = 0;
    while(!s.empty()){
        ans *= 10;
        ans += s.top();
        s.pop();
    }
    return ans;
}
ll solve2(ll num,ll last,ll len){
    num -= 9*len;
    if(num<last) return -1;
    stack<ll> s;
    s.push(last);
    num -= last;
    Rep(i,1,len) s.push(9);
    if(num>0 && num<=8){
        s.push(num);
        num = 0;
    }else if(num>0){
        s.push(8);
        num -= 8;
    }
    while(num){
        if(num<=9){
            s.push(num);
            num = 0;
        }else{
            s.push(9);
            num -= 9;
        }
    }
    ll ans = 0;
    while(!s.empty()){
        ans *= 10;
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main(){
    IOS;
    ll n,k;
    CAS {
        cin>>n>>k;
        bool flag = 0;
        ll cnt = INF;
<<<<<<< HEAD
        ll now = 9;
        ll num = n-k*(k+1)/2;
        if(num>=0 && num%(k+1)==0){
            ll ans = num/(k+1);
            ans = solve(ans,9-k,0);
            if(ans!=-1){
                cnt = min(cnt,ans);
                flag = 1;
            }
        }
=======
        ll now = 99;
>>>>>>> cfddb953762c7216ccb8bf29c2fe869489363a85
        Rep(time,0,15){
            Rep(i,1,k){
                ll num = n-k*(k+1)/2+i*now;
                if(num<0) continue;
                if(num%(k+1)!=0) continue;
                ll ans = num/(k+1);
                if(ans>n) break;
<<<<<<< HEAD
                if((ans+k-i)<now) continue;
=======
                if(i!=0 && ans<now) continue;
>>>>>>> cfddb953762c7216ccb8bf29c2fe869489363a85
                if(i==0){
                    ans = solve(ans,9-k,time);
                    if(ans!=-1 && ans>=now){
                        cnt = min(cnt,ans);
                        flag = 1;
                    }
                }else{
                    ans = solve2(ans,9-k+i,time);
                    if(ans != -1){
                        cnt = min(cnt,ans);
                        flag = 1;
                    }
                }
            }
            now = now*10+9;
        }
        if(!flag) cout<<"-1\n";
        else cout<<cnt<<"\n";
    }
    return 0;
}
