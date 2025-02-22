#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&ar, int st, int mid, int end){
    vector<int>tmp;
    int i=st, j=mid+1;
    int invCount=0;
    while(i<=mid && j<=end){
        if(ar[i]<=ar[j]){
            tmp.push_back(ar[i]);
            i++;
        }else{
            tmp.push_back(ar[j]);
            j++;
            invCount+=(mid-i+1);
        }
    }

    while(i<=mid){
        tmp.push_back(ar[i]);
        i++;
    }
    while(j<=end){
        tmp.push_back(ar[j]);
        j++;
    }

    for(int idx=0; idx<tmp.size(); idx++){
        ar[idx+st]=tmp[idx];
    }
    return invCount;
}

int mergeSort(vector<int>& ar, int st, int end)
{
    if(st<end){
        int mid=st+(end-st)/2;
        int left=mergeSort(ar, st, mid);
        int right=mergeSort(ar, mid+1, end);

        int incCount=merge(ar, st, mid, end);
        return left+right+incCount;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>ar;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        ar.push_back(x);
    }
    int ans = mergeSort(ar, 0, n-1);
    cout<<ans;
}