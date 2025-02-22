#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&ar, int st, int end)
{
    int idx=st-1;
    int pivot=ar[end];
    for(int i=st; i<end; i++){
        if(ar[i]<=pivot){
            idx++;
            swap(ar[idx],ar[i]);
        }
    }
    idx++;
    swap(ar[end],ar[idx]);
    return idx;
}

void quickSort(vector<int>&ar, int st, int end)
{
    if(st<end){
        int pvtIndex=partition(ar,st,end);
        quickSort(ar,st,pvtIndex-1);
        quickSort(ar,pvtIndex+1,end);
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
        quickSort(ar,0,n-1);
        for(auto it:ar){
            cout<<it<<" ";
        }


}