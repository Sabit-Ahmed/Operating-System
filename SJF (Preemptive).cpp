#include<bits/stdc++.h>
using namespace std;
struct object
{
    char process[10];
    int burst_time;
    int rem_time;
    int a_time;
    int turn_time;
    double l;
};
bool comp(object a,object b){
    return a.rem_time<b.rem_time;
}
int main()
{
    object obj[100]={};
    int n,m,v,a,count_g=0,count_l=0,bt_sum=0,sum=0,tot_t=0,wait_t=0,g_c[100],t_t[100],w_t[100];
    double l;
    queue<string>mq;
    cout<<"Enter no. of processes:"<<endl;
    cin>>n;
    cout<<"Enter process name, arrival time and burst time:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>obj[i].process>>obj[i].a_time>>obj[i].burst_time;
        obj[i].rem_time=obj[i].burst_time;
        bt_sum=bt_sum+obj[i].burst_time;
    }
    cout<<endl<<endl;
    //g_c[0]=0;
    //m=n;
    //n=count_g+count_l;
    //w_t[0]=0;
    for(int i=0; i<bt_sum; i++)
    {
        for(int j=i;j>=0;j--){
            if(obj[j].rem_time!=0)
            {
                std::sort(obj,obj+j,comp);
                obj[j].rem_time=obj[j].rem_time-1;
                //w_t[j]=sum;
                //obj[j].turn_time=obj[j].rem_time;
                //g_c[i+1]=sum;
                //mq.push(obj[j].process);
                //goto label;

                if(obj[j].rem_time==0){
                    //obj[j].turn_time = m+1;
                    v=j;
                    //cout<<obj[j].turn_time<<" ";
                    //cout<<"in"<<i<<endl;
                    mq.push(obj[j].process);
                    goto label;
                }
                //m=i;
            }
            //m=i;
        }
        label:
        if(obj[v].rem_time==0)
            obj[v].turn_time=i+1;
    }
    for(int i=0;i<n;i++){
        cout<<obj[i].turn_time<<" ";
    }
    cout<<endl<<" ";
    while (!mq.empty()) {
        cout << mq.front()<<"  ";
        mq.pop();
    }

    cout<<endl<<endl;
    cout<<"Waiting Time:  "<<"Turnaround Time:"<<endl;
    /*for(int i=0; i<a; i++)
    {
        t_t[i]=w_t[i];
        w_t[i]=abs(w_t[i]-obj[i].burst_time);
        wait_t=wait_t+w_t[i];
        tot_t=tot_t+t_t[i];
        cout<<" "<<w_t[i]<<"                   "<<t_t[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Avg. waiting time: "<<float(wait_t)/a<<endl;
    cout<<"Avg. turnaround time: "<<float(tot_t)/a<<endl;*/
}
