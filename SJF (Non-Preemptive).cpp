#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,arr1[10]={},arr2[10]={},arr3[10]={},arr4[10]={},sum=0,sum2=0,sum3=0;
    cout<<"Enter number of process"<<endl;
    cin>>n;
    cout<<"Enter burst time"<<endl;
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }
    m=n+1;
    sort(arr1,arr1+m);


    cout<<endl<<endl;
    for(int i=0;i<m;i++){
        sum=sum+arr1[i];//gantt-chart
        arr2[i]=sum;
        cout<<arr2[i]<<" ";
    }
    arr1[0]=arr2[1];
    for(int i=0;i<n;i++){
        sum3=sum3+arr2[i+1];
        arr1[i]=sum3;
        sum2=sum2+arr2[i];
        arr3[i]=sum2;
        }
    /*for(int i=0;i<m;i++){
        sum3=sum3+arr2[i+1];
        arr1[i]=sum3;
    }*/
    cout<<endl<<endl;
    cout<<"Avg. waiting time: "<<float(sum2)/n<<endl;
    cout<<"Avg. turnaround time: "<<float(sum3)/n<<endl;
}

