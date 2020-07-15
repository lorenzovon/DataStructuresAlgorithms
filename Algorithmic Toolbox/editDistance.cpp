#include <iostream>
#include <string>
using namespace std;

int minDistance(string A,string B,int n, int m);

int least(int a, int b);

int main(){
    
    string A;
    cin >> A;
    string B;
    cin >> B;
    int k=minDistance(A,B,A.length(),B.length());
    cout << k << endl;
    return 0;
}

int least(int a,int b,int c){
    int temp=(a<b)?a:b;    
    return (temp<c)?temp:c;
}

int minDistance(string A,string B,int n, int m){
    int all[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if( i==0 ){
                all[i][j] = j;
            }  
            else if( j==0 ){
                all[i][j] = i;
            }            
            else if( A[i-1] == B[j-1] ){                
                all[i][j] = all[i-1][j-1];                
            }
            else{
                all[i][j]=1+least(all[i][j-1],all[i-1][j],all[i-1][j-1]);
            }                
        }
    }

    return all[n][m];
}