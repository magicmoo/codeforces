#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 50;
int a[maxn],b[maxn];
bool check(int arr[],int n){
    int cnt = 0,num,num2;
    Rep(i,1,n){
        if(cnt == 0){
            num = arr[i];
            cnt++;
        }else{
            if(num == arr[i]) cnt++;
            else{
                cnt--;
                num2 = arr[i];
            }
        }
    }
    int cnt1 = 0,cnt2 = 0;
    Rep(i,1,n){
        if(arr[i]==num) cnt1++;
        if(arr[i]==num2) cnt2++;
    }
    return cnt1>=n/2 || cnt2>=n/2;
}
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n) a[i] += 1e6;
        int ans = 0;
        int cnt = 0;
        if(check(a,n)){
            cout<<"-1\n";
            continue;
        }
        Dep(num,2e6,1){
            Rep(i,1,n) b[i] = a[i]%num;
            if(check(b,n)){
                cout<<num<<"\n";
                break;
            }
        }
    }
    return 0;
}
