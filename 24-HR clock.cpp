//
//  main.cpp
//  CLOCK
//
//  Created by Shannen on 29/06/2021.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
    int hours;
    int minutes;
    int seconds;
    
    
    cout<<"Please enter the time"<<endl;
    cout<<"Please enter the seconds:";
    cin>>seconds;
    cout<<"Please enter the minutes:";
    cin>>minutes;
    cout<<"Please enter the hours:";
    cin>>hours;
    cout<<endl;
    
    
    while (1)
    {
        seconds++;
        if (seconds>59)
        {
            minutes++;
            seconds=0;
        }
        if (minutes>59) {
            minutes=0;
            hours++;
        }
        
        if (hours>23)
        {
            minutes=0;
            seconds=0;
            hours=0;
        }
        
        system("clear");
        cout<<"------------------"<<endl;
        cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
        cout<<"------------------"<<endl;
        sleep(1);
    }
    
}
    

