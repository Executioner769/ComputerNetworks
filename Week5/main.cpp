#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    int hosts,host,physicalnetworks;
    cout<<"Physical networks: ";
    cin>>physicalnetworks;
    cout<<"Hosts in physical network: ";
    cin>>host;
    hosts=host*physicalnetworks;
    long int classA=16777214;
    int classB=65534;
    int classC=254;
    int classAn=126;
    int classBn=16382;
    int classCn=2097150;
    string classtype="";
    int countOfClasses;
    int k=classC;
    int ta=0+rand() % static_cast<int>(127-0+1);
    int tb=128+rand()%static_cast<int>(191-128+1);
    int tc=192+rand()%static_cast<int>(222-191+1);
    int m=tc;
    int subnetnumber =10;
    if(physicalnetworks==1)
    {
        if(hosts>258*classC&&hosts<=256*classB)
        {
            classtype="Class B";
            int rem=hosts%classB;
            if(rem>0)
            {
                countOfClasses=(hosts/classB)+1;
            }
            else
            {
                countOfClasses=(hosts/classB);
            }   
            k=classB;
            m=tb;
        }
        else if(hosts<=258*classC)
        {
            classtype="Class C";
            int rem=hosts%classC;
            if(rem>0)
            {
                countOfClasses=(hosts/classC)+1;
            }
            else
            {
                countOfClasses=(hosts/classC);
            }
            k=classC;
            m=tc;
        }
        else if(hosts>256*classB)
        {
            classtype="Class A";
            int rem=hosts%classA;
            if(rem>0)
            {
                countOfClasses=(hosts/classA)+1;
            }
            else
            {
                countOfClasses=(hosts/classA);
            }
            k=classA;
            m=ta;
        }
        float t=countOfClasses*k;
        cout<<t<<endl;
        cout<<countOfClasses<<endl;
        cout<<k<<endl;
        cout<<"The class "<<classtype<<endl;
        cout<<"The number of classes required are "<<countOfClasses<<endl;
        cout<<"Throughput = "<<hosts/t<<"%"<<endl;
        int q=30;
        cout<<"The address is "<<m<<".0."<<q<<".0"<<endl;
        cout<<"Assigning :\n";
        for(int i=0;i<countOfClasses;i++)
        {
            cout<<m<<".0."<<q+i<<".0"<<endl;
        }
    }
    else
    {
        int z=host;
        for(int i=0;i<host;i++)
        {
            if(pow(2,i)>=host)
            {
                z=i;
                break;
            }
        }
        cout<<"The is "<<m<<".0.30.0"<<endl;
        if(hosts<classC)
        {
            classtype="Class C";
            k=classC;
            subnetnumber=pow(2,8-z-3);
            cout<<"Subnets: "<<subnetnumber<<endl;
            int c=pow(2,z)-2;
            cout<<"Hosts : "<<c<<endl;
            cout<<"Subnet mask: "<<m<<".0.30.0"<<endl;
            cout<<"Broadcast address : "<<m<<".0.30.255"<<endl;
            cout<<"First host id: "<<m<<".0.30.1"<<endl;
            cout<<"Last host id: "<<m<<".0.30.254"<<endl;
            m=tb;
        }
        else if(hosts<classB)
        {
            classtype="Class B";
            k=classB;
            m=tc;
            subnetnumber=pow(2,16-z-3);
            cout<<"Subnets: "<<subnetnumber<<endl;
            int c=pow(2,z)-2;
            cout<<"Hosts : "<<c<<endl;
            cout<<"Subnet mask: "<<m<<".0.0.0"<<endl;
            cout<<"Broadcast address : "<<m<<".0.255.255"<<endl;
            cout<<"First host id: "<<m<<".0.0.1"<<endl;
            cout<<"Last host id: "<<m<<".0.255.254"<<endl;
        }
        else if(hosts<classA)
        {
            classtype="Class A";
            subnetnumber=pow(2,24-z-3);
            cout<<"Subnets: "<<subnetnumber<<endl;
            int c=pow(2,z)-2;
            cout<<"Subnet mask: "<<m<<".0.0.0"<<endl;
            cout<<"Hosts : "<<c<<endl;
            cout<<"Broadcast address : "<<m<<".255.255.255"<<endl;
            cout<<"First host id: "<<m<<".0.0.1"<<endl;
            cout<<"Last host id: "<<m<<".255.255.254"<<endl;
            k=classA;
            m=ta;
        }
        cout<<"The class is "<<classtype<<endl;
        float throughput = (float)hosts/(float)k;
        cout<<"Throughput = "<<throughput<<"%"<<endl;
    }
    return 1;
}