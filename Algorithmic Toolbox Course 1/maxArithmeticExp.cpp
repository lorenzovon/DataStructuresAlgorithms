#include<iostream>
#include<string>
#include<vector>
#include<limits.h>

using namespace std;

long long evaluate(long long a,long long b,char op);
long long maxValue(string input);
long long least(long long a,long long b);
long long greatest(long long a,long long b);

int main(){
    string input;
    cin >> input;    
    long long p;
    p=maxValue(input);
    cout << p << endl;    
    return 0;
}

long long least(long long a,long long b){
    return (a<=b)?a:b;
}

long long greatest(long long a,long long b){
    return (a>=b)?a:b;
}

long long evaluate(long long a,long long b,char op){
    switch (op){
        case '*':
            return a*b;
            break;
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        default:
            return 0;
            break;
    }    
}

long long maxValue(string input){
    long long nos;   
    nos=(input.length()+1)/2;    
    
    vector<vector<long long>>minCond;
    minCond.resize(nos,vector<long long>(nos,0));

    vector<vector<long long>>maxCond;
    maxCond.resize(nos,vector<long long>(nos,0));    

    for(long long i=0;i<nos;i++){        
        minCond[i][i]= stoll(input.substr(2*i,1));
        maxCond[i][i]= stoll(input.substr(2*i,1));
    }

    for(int i=0;i<nos-1;i++){
        for(int j=0;j<nos-i-1;j++){

            int k=i+j+1;
            long long minVal=LLONG_MAX;
            long long maxVal=LLONG_MIN;

            for(int l=j;l<k;l++){
                
                long long alpha=evaluate(minCond[j][l],minCond[l+1][k],input[2*l + 1]);
                long long beta=evaluate(minCond[j][l],maxCond[l+1][k],input[2*l + 1]);
                long long gamma=evaluate(maxCond[j][l],minCond[l+1][k],input[2*l + 1]);
                long long delta=evaluate(maxCond[j][l],maxCond[l+1][k],input[2*l + 1]);  

                minVal=least(minVal,least(alpha,least(beta,least(gamma,delta))));
                maxVal=greatest(maxVal,greatest(alpha,greatest(beta,greatest(gamma,delta))));                
            }

            minCond[j][k]=minVal;
            maxCond[j][k]=maxVal;
        }
    }

    return maxCond[0][nos-1];
}



// https://github.com/taochenshh/Maximize-the-Value-of-an-Arithmetic-Expression-with-Dynamic-Programming/blob/master/placing_parentheses.cpp