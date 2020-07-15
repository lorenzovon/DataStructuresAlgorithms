#include <iostream>
using namespace std;

int longest(int A[],int B[],int n, int m);

int greatest(int a, int b);

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int m;
    cin >> m;
    int B[m];
    for(int i=0;i<m;i++){
        cin >> B[i];
    }    
    int k=longest(A,B,n,m);
    cout << k << endl;
    return 0;
}

int greatest(int a,int b){
    return (a>b)?a:b;
}

int longest(int A[],int B[],int n,int m){
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