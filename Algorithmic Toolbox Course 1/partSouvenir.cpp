#include<iostream>
using namespace std;

bool partition(int n,int bought[]);

int main(){
    int n;
    cin >> n;
    int bought[n];
    for(int i=0;i<n;i++){
        cin >> bought[i];
    }

    bool k=partition(n,bought);
    cout<< k<< endl;
    return 0;
}

bool partition(int n,int bought[]){
    int added=0;
    for(int i=0;i<n;i++){
        added+=bought[i];
    }
    if(added%3!=0){
        return false;
    }

    bool allSolve[(added/3)+1][n+1];
    for(int i=0;i<=n;i++){
        allSolve[0][i]=true;
    }

    for(int i=1;i<=added/3;i++){
        allSolve[i][0]=false;
    }

    for(int i=1;i<=added/3;i++){
        for(int j=1;j<=n;j++){
            allSolve[i][j]=allSolve[i][j-1];
            if(i>=bought[j-1]){
                allSolve[i][j]=allSolve[i][j] || allSolve[i-bought[j-1]][j-1];
            }
        }
    }

    return allSolve[added/3][n];

}