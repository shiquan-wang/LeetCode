#include<iostream>
#include<vector>

using namespace std;

int a[200], n, sum, ans, vis[200];

int A(int x){
    int sum = 1;
    for(int i = 1; i <= x; ++i){
        sum *= i;
    }
    return sum;
}

void dfs(int x, int sum, int num){
    if(sum == 60){
        ans += A(num) * A(n - num);
        return;
    }
    if(sum > 60){
        return;
    }
    for(int i = x + 1; i <= n; ++i){
        if(vis[i] == 0){
            vis[i] = 1;
            dfs(i, sum + a[i], num + 1);
            vis[i] = 0;
        }
    }
}
int main(){
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        sum += a[i];
    }
    // memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++i){
        vis[i] = 0;
    }
    dfs(0, 0, 0);
    cout<<ans<<endl;
    return 0;
}