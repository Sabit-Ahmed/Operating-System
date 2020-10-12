#include<bits/stdc++.h>
using namespace std;

struct object{
    char process[10];
    int burst_time;
    int priority;
};

bool comp(object a,object b){
    return a.priority<b.priority;
}

int main()
{
    object obj[100];
    int n,sum=0,tot_t=0,wait_t=0,g_c[100],t_t[100],w_t[100];
    cout<<"Enter no. of processes:"<<endl;
    cin>>n;
    cout<<"Enter process name, burst time and priority:"<<endl;
    for(int i=0;i<n;i++){
        cin>>obj[i].process>>obj[i].burst_time>>obj[i].priority;
    }
    std::sort(obj,obj+n,comp);
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        cout<<obj[i].process<<"  "<<obj[i].burst_time<<"  "<<obj[i].priority<<endl;
    }
    cout<<endl<<endl;
    g_c[0]=0;
    //cout<<g_c[0]<<"   ";
    for(int i=0;i<=n;i++){
        sum=sum+obj[i].burst_time;
        g_c[i+1]=sum;
        cout<<g_c[i]<<"   ";
    }

    w_t[0]=0;
    t_t[0]=obj[0].burst_time;
    for(int i=1;i<n;i++){
        t_t[i]=t_t[i-1]+obj[i].burst_time;
        w_t[i]=t_t[i-1];
    }
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        tot_t=tot_t+t_t[i];
        wait_t=wait_t+w_t[i];
        cout<<w_t[i]<<"   "<<t_t[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Avg. waiting time: "<<float(wait_t)/n<<endl;
    cout<<"Avg. turnaround time: "<<float(tot_t)/n<<endl;
}
