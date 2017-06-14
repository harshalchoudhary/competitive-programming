#include <iostream>
#include <algorithm>

using namespace std;

//
//create a structure to store the time and a field representing whether it's entry or exit time.
//
typedef struct _TimeStruct
{
 unsigned long time;
 bool entry;
}_Time;

//
//Comparison function to sort the _Time struct based on the time values.
//
bool comp(const _Time& t1, const _Time& t2)
{
    if(t1.time < t2.time)
     return true;

    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t,N;
    cin>>t;
    
    
    _Time Time[256];
    
    
    while(t--)
    {
     cin>>N;
     
     for(int i=0, j=0; i<N; i++,j++)
     {
        scanf("%lu", &Time[j].time);
        Time[j].entry = true;
        scanf("%lu", &Time[++j].time);
        Time[j].entry = false;
     }
     
     //
     //Sort the Time array based on time values only. Number of entries in Time array will be 2*N as N entry times and N exit times are there.
     //
     sort(Time, Time+2*N, comp);
     
     
     //
     //Traverese throught the sorted Time array and increment the counter if entry found is "entry time" otherwise decrement the conter if enhtry found is "exit time".
     //
     int counter = 0;
     int max = 0;
     for(int i=0; i<2*N; i++)
     {
        Time[i].entry ? counter++: counter--;         
       
        if(max < counter)
           max = counter;
     }
     
     cout<<max<<endl;
     
    }

return 0;
}
