#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
struct Node{
    int data;
    int l,r;
}mp[1<<19+5];
char str[(1<<18)+1];
int k,q,p;
char c;
int build(int root,int l,int r){
    mp[root].l = l; mp[root].r = r;
    if(l==r) return mp[root].data = 1;
    int mid = (l+r)>>1;
    int index = (1<<k)-root;
    int temp1 = build(root<<1,l,mid),temp2 = build((root<<1)+1,mid+1,r);
    if(str[index]=='?') return mp[root].data = temp1+temp2;
    else if(str[index]=='1') return mp[root].data = temp1;  
    else return mp[root].data = temp2;
}
void update(int root){
    int index = (1<<k)-root;
    if(str[index]=='?') mp[root].data = mp[root*2].data+mp[root*2+1].data;
    else if(str[index]=='1') mp[root].data = mp[root*2].data;
    else mp[root].data = mp[root*2+1].data;
    if(root>1) update(root/2);
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    scanf("%d",&k);
    scanf("%s",str+1);
    scanf("%d",&q);
    build(1,1,1<<k);
    while(q--){
        cin>>p>>c;
        int index = (1<<k)-p;
        str[p] = c;
        update(index);
        cout<<mp[1].data<<"\n";
    }
    return 0;
}
