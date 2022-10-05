#include<bits/stdc++.h>
using namespace std;
int b[100];
void merge(int arr[],int low,int mid,int high);

void mergesort(int arr[],int low,int high)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}
  void merge(int arr[],int low,int mid,int high)
  {
        int i=low,j=mid+1,k=low;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
            {b[k]=arr[i];
             i++;
             k++;
            }
            else{
                b[k]=arr[j];
                j++;
                k++;
            }
        }

        if(i<=mid)
        {while(i<=mid)
         {
            b[k]=arr[i];
            k++;
            i++;
         }
        }
        else{
            while(j<=high)
            {
                b[k]=arr[j];
                k++;
                j++;
            }
        }
        while(low<=high)
        {  
          arr[low]=b[low];
          low++;
        }

  }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int low=0,high=n-1;
    mergesort(arr,low,high);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}