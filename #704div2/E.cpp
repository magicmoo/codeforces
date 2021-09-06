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
const int maxn = 3e5;

vector<int> v[maxn];
int a[maxn],b[maxn],c[maxn];
int n,m,num,mid;

bool check(int* p){
    for(int i=1;i<n;i++){
        int temp = 0;
        for(int j=0;j<m;j++){
            if(v[i][j] != p[j]) temp++;
        }
        if(temp > 2) return false;
    }
    return true;
}

int check1(int index,int *p){
    int temp = 0;
    for(int j=0;j<m;j++){
        if(v[index][j] != p[j]) temp++;
    }
    return temp;
}

void change(int* p,int index,int aa,int bb=-1){
    for(int i=0;i<m;i++) p[i] = b[i];
    p[aa] = v[index][aa];
    if(bb != -1) p[bb] = v[index][bb];
}
bool solve(int last){
    bool flag = true,flag1 = true;
    int Max = 0;
    for(int i=1;i<n;i++){
        num = check1(i,c);
        if(num > 2+last){
            flag = false;
            break;
        }else if(num>2){
            flag1 = false;
            Max = max(num,Max);
            if(Max == num) mid = i;
        }
    }
    if(!flag) return false;
    else if(!flag1){
        vector<int> dif;
        for(int j=0;j<m;j++){
            if(v[mid][j] != c[j]) dif.push_back(j);
        }
        for(int i=0;i<m;i++) b[i] = c[i];
        if(Max == 3){
            change(c,mid,dif[0]);
            if(solve(last-1)) return true;
            change(c,mid,dif[1]);
            if(solve(last-1)) return true;
            change(c,mid,dif[2]);
            if(solve(last-1)) return true;
        }else if(Max == 4){
            change(c,mid,dif[0],dif[1]);
            if(solve(last-2)) return true;
            change(c,mid,dif[0],dif[2]);
            if(solve(last-2)) return true;
            change(c,mid,dif[0],dif[3]);
            if(solve(last-2)) return true;
            change(c,mid,dif[1],dif[2]);
            if(solve(last-2)) return true;
            change(c,mid,dif[1],dif[3]);
            if(solve(last-2)) return true;
            change(c,mid,dif[2],dif[3]);
            if(solve(last-2)) return true;
        }
        for(int i=0;i<m;i++) b[i] = a[i];
        return false;
    }
    else{
        return true;
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>num;
            v[i].push_back(num);
        }
    }
    for(int i=0;i<m;i++) a[i] = v[0][i];
    for(int i=0;i<m;i++) c[i] = b[i] = a[i];
    if(solve(2)){
        cout<<"YES\n";
        for(int i=0;i<m;i++) cout<<c[i]<<" ";
        cout<<"\n";
    }else cout<<"NO\n";
    return 0;
}
