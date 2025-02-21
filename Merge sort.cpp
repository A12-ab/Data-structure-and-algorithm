#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&ar, int st, int mid, int end){
    vector<int>tmp;
    int i=st, j=mid+1;

    while(i<=mid && j<=end){
        if(ar[i]<=ar[j]){
            tmp.push_back(ar[i]);
            i++;
        }
        else{
            tmp.push_back(ar[j]);
            j++;
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
}

void mergeSort(vector<int>&ar, int st, int end){
    if(st<end){
        int mid=st+(end-st)/2;

        mergeSort(ar,st,mid);
        mergeSort(ar,mid+1,end);

        merge(ar,st,mid,end);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int>ar;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        ar.push_back(x);
    }
    mergeSort(ar,0,n-1);
    for(auto val:ar){
        cout<<val<<" ";
    }

}