#include <iostream>
using namespace std;

int longest(int A[],int B[],int C[],int n, int m,int p);

int greatest(int a, int b,int c);

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
    int p;
    cin >> p;
    int C[p];
    for(int i=0;i<p;i++){
        cin >> C[i];
    }   
    // cout << greatest(7,8,9);
    int k=longest(A,B,C,n,m,p);
    cout << k << endl;
    return 0;
}

int greatest(int a,int b,int c){
    int temp=(a>b)?a:b;
    return (temp>c)?temp:c;
}

int longest(int A[],int B[],int C[],int n,int m,int p){
    int all[n+1][m+1][p+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=p;k++){
                if(i==0 || j==0 || k==0 ){
                    all[i][j][k]=0;
                }            
                else if(A[i-1]==B[j-1] && B[j-1] ==C[k-1]){
                    all[i][j][k]=all[i-1][j-1][k-1]+1;
                }
                else{
                    all[i][j][k]=
                    greatest(
                        all[i-1][j][k],
                        all[i][j-1][k],
                        all[i][j][k-1]
                    );
                }     
            }                       
        }
    }
    
    return all[n][m][p];
}