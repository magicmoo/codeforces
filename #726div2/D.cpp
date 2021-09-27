#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        if(n==1 || n==2 || n==3) cout<<"Bob\n";
        else if(n%2==1) cout<<"Bob\n";
        else{
            int sum = 0;
            while(n%2==0){
                n /= 2;
                sum++;
            }
            if(n != 1) cout<<"Alice\n";
            else if(sum%2==0) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
    }
    return 0;
}