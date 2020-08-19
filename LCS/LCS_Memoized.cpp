// Time Complexity : n*m

#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int LCS(string x, string y, int n, int m){
    if(n==0 || m==0)
        return t[n][m] = 0;

    if(t[n][m] != -1)
        return t[m][n];

    if(x[n-1] == y[m-1])
        return t[n][m] = 1 + LCS(x,y,n-1,m-1);
    else
        return t[n][m] = max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
}

int main(){
    string x;
    getline(cin,x);
    string y;
    getline(cin,y);
    memset(t,-1,sizeof(t));
    t[x.size()][y.size()] = LCS(x,y,x.size(),y.size());
    cout << t[x.size()][y.size()];

    return 0;
}
