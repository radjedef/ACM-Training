#include <bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
const int maxn = 100000+10;
int a[maxn];
int n,m;

bool check(int x) {
    int s = 0,cnt = 0;
    for(int i=1;i<=n;i++) {
        if(s+a[i]<=x) s += a[i];
        else s = a[i],cnt++;
    }
    cnt++;
    return cnt <= m;
}

int main() {
    cin>>n>>m;
    int s = 0;
    int mmin = 0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        s+=a[i];
        mmin = max(mmin,a[i]);
    }
    int l = mmin,r = s;
    int ans = -1;
    //和处在 [0,s]
    //if(check(6)) cout << "okokok"<<endl;
    while(l<=r) {
        int mid = (l+r)/2;
        //cout << l << " " << r << " " << mid << endl;
        if(check(mid)) ans = mid , r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n",ans);

    return 0;
}