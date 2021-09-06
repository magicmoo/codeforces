#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int a[maxn],b;
vector<int> v[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    int A,B,ans;
    A = B = ans = 0;
    for(int i=0;i<n;i++){
        if(A == B){
            if(A != a[i]) ans++;
            A = a[i];
        }else if(A == a[i]){
            
        }else if(B == a[i]){
            
        }else{
            int num1,num2;
            num1 = num2 = INF;
            for(int j=0;j<v[A].size();j++){
                if(v[A][j] > i){
                    num1 = v[A][j];
                    break;
                }
            }
            for(int j=0;j<v[B].size();j++){
                if(v[B][j] > i){
                    num2 = v[B][j];
                    break;
                }
            }
            if(num1 < num2){
                B = a[i]; ans++;
            }else{
                A = a[i]; ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
