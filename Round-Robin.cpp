#include<bits/stdc++.h>
using namespace std;
struct object
{
    char process[10];
    int burst_time;
    int rem_time;
    double l;
};
int main()
{
    object obj[100];
    int n,m,v,a,count_g=0,count_l=0,q_t,sum=0,tot_t=0,wait_t=0,g_c[100],t_t[100],w_t[100];
    double l;
    queue<string>mq;
    cout<<"Enter no. of processes:"<<endl;
    cin>>n;
    cout<<"Enter quantum time:"<<endl;
    cin>>q_t;
    cout<<"Enter process name and burst time:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>obj[i].process>>obj[i].burst_time;
        obj[i].rem_time=obj[i].burst_time;
        if(q_t<obj[i].burst_time)
        {
            l=double(obj[i].burst_time)/q_t;
            obj[i].l=ceil(l);
            count_g=count_g+obj[i].l;
        }
        else
        {
            count_l++;
        }
    }
    cout<<endl<<endl;
    g_c[0]=0;
    a=n;
    n=count_g+count_l;
    w_t[0]=0;
    for(int i=0; i<=n; i++)
    {
        for(int j=i;j<a;j++){
            if(q_t>obj[j].rem_time&&obj[j].rem_time!=0)
            {
                sum=sum+obj[j].burst_time;
                obj[j].rem_time=0;
                w_t[j]=sum;
                //g_c[i+1]=sum;
                mq.push(obj[j].process);
                goto label;
            }
            else if(q_t<obj[j].rem_time){
                obj[j].rem_time=obj[j].rem_time-q_t;
                sum=q_t+sum;
                v=j;
                mq.push(obj[j].process);
                goto label;
            }
        }
        if(i==a||i>a){
            obj[v].rem_time=obj[v].rem_time-q_t;
            sum=q_t+sum;
            if(obj[v].rem_time==0){
                w_t[v]=sum;
            }
            mq.push(obj[v].process);
        }
        label:
        g_c[i+1]=sum;

        cout<<g_c[i]<<"   ";

    }
    cout<<endl<<" ";
    while (!mq.empty()) {
        cout << mq.front()<<"  ";
        mq.pop();
    }

    cout<<endl<<endl;
    cout<<"Waiting Time:  "<<"Turnaround Time:"<<endl;
    for(int i=0; i<a; i++)
    {
        t_t[i]=w_t[i];
        w_t[i]=abs(w_t[i]-obj[i].burst_time);
        wait_t=wait_t+w_t[i];
        tot_t=tot_t+t_t[i];
        cout<<" "<<w_t[i]<<"                   "<<t_t[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Avg. waiting time: "<<float(wait_t)/a<<endl;
    cout<<"Avg. turnaround time: "<<float(tot_t)/a<<endl;
}
