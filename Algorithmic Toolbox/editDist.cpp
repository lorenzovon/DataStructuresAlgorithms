#include <iostream>
using namespace std;

int minDistance(string A,string B,int n, int m);

int greatest(int a, int b);

int main(){
    string A;
    cin >> A;
    string B;
    cin >> B;
    // cout << greatest(A.length(),B.length()) << endl;
    int k= greatest(A.length(),B.length())-minDistance(A,B,A.length(),B.length());
    // if(A[0]==B[0]){
    //     cout << k << endl;
    // }
    // else{
    //     cout << k+1 << endl;
    // }
    cout << k << endl;
    
    return 0;
}

int greatest(int a,int b){
    return (a>b)?a:b;
}

int minDistance(string A,string B,int n, int m){
    int all[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0 ){
                all[i][j]=0;
            }            
            else if(A[i-1]==B[j-1]){
                all[i][j]=all[i-1][j-1]+1;
            }
            else{
                all[i][j]=greatest(all[i-1][j],all[i][j-1]);
            }                
        }
    }
    return all[n][m];
}