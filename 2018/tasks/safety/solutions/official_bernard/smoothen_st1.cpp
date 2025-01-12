#include <cstdlib>
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>
using namespace std;
int best=numeric_limits<int>::max();
int n,h;
int* arr;
int* test;
int minval,maxval;
void dfs(int index){
    if(index==n){
        for(int i=1;i<n;++i){
            if(abs(test[i]-test[i-1])>h)return;
        }
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=abs(arr[i]-test[i]);
        }
        best=min(best,sum);
        return;
    }
    for(int i=minval;i<=maxval;++i){
        test[index]=i;
        dfs(index+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>h;
    arr=new int[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    {
        auto pr=minmax_element(arr,arr+n);
        minval=*(pr.first);
        maxval=*(pr.second);
    }
    test=new int[n];
    dfs(0);
    delete[] test;
    delete[] arr;
    cout<<best<<endl;
}
