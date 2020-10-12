#include<bits/stdc++.h>
using namespace std;

struct Allocation
{
    int A[100];
    int B[100];
    int C[100];
};

struct Max
{
    int A[100];
    int B[100];
    int C[100];
};

struct Need
{
    int A[100];
    int B[100];
    int C[100];
};
struct Available
{
    int A,B,C;
};

int main()
{
    struct Allocation Al;
    struct Max M ;
    struct Need N;
    struct Available avail;
    int n;
    string Process[100];
    string seq[100];
    cout<<"No. of processes:";
    cin>>n;
    cout<<"Enter Process names:"<<endl;
    for(int i=0; i<n; i++)
    {

        cin>>Process[i];
    }
    cout<<"Enter Allocated resource:\nA   B   C"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>Al.A[i];
        cin>>Al.B[i];
        cin>>Al.C[i];
    }
    cout<<"Enter maximum:"<<endl;
    for(int i=0; i<n; i++)
    {

        cin>>M.A[i];
        cin>>M.B[i];
        cin>>M.C[i];
    }
    cout<<"Enter available resourse:"<<endl;
    cin>>avail.A;
    cin>>avail.B;
    cin>>avail.C;

    for(int i=0; i<n; i++)
    {

        N.A[i]=    M.A[i]-Al.A[i];
        N.B[i]=    M.B[i]-Al.B[i];
        N.C[i]=    M.C[i]-Al.C[i];
    }

    for(int i=0; i<n; i++)
    {

        cout<<N.A[i]<<"  "<<N.B[i]<<"  "<<N.C[i]<<endl;
    }
    int j=0;
    while(1)
    {
        if(j>=n)
            break;


        for(int i=0; i<n; i++)
        {

            if(N.A[i]<=avail.A && N.B[i]<=avail.B && N.C[i]<=avail.C && Process[i]!="n")
            {
                seq[j]=Process[i];
                Process[i]="n";

                avail.A+=Al.A[i];
                avail.B+=Al.B[i];
                avail.C+=Al.C[i];
                j++;
            }

        }

    }

    for(int i=0;i<n; i++){
        cout<<seq[i]<<" ";
    }








    return 0;
}
