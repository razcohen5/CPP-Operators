#include <iostream>
#include <stdio.h>

using namespace std;

#include "CircularInt.hpp"


     CircularInt :: CircularInt(int a, int b)
    {
        if(a>b||a<0||b<0)
        {
            minhour=1;
            maxhour=12;
        }
        else
        {
            minhour = a;
            maxhour = b;
        }
        hour = minhour;
    }

    int CircularInt :: operator-()
    {
        int res = (-1*hour)%maxhour;
        if(res<=0)
            res += 12;
        return res;
    }

    ostream& CircularInt :: operator<<(CircularInt& c)
    {
        return cout<<c.hour;
    }

    CircularInt& CircularInt :: operator+=(int value)
    {
        hour = (hour + value)%maxhour;
        return *this;
    }

    CircularInt& CircularInt :: operator-=(int value)
    {   
        int res = (hour - value)%maxhour;
        if(res<=0)
            res += 12;
        hour = res;
        return *this;
    }

    CircularInt& CircularInt :: operator*=(int value)
    {
        hour = (hour * value)%maxhour;
        return *this;
    }

    CircularInt& CircularInt :: operator/=(int value)
    {
        if(hour%value==0)
        {
            hour = (hour / value)%maxhour;
            return *this;
        }
        else
        {
            cout<<"There is no number x in {"<<minhour<<","<<maxhour<<"} such that x*"<<value<<"="<<hour<<endl;
        }
    }

    CircularInt& CircularInt :: operator+=(const CircularInt& c)
    {
        hour = (hour + c.hour)%maxhour;
        return *this;
    }

    CircularInt& CircularInt :: operator-=(const CircularInt& c)
    {   
        int res = (hour - c.hour)%maxhour;
        if(res<=0)
            res += 12;
        hour = res;
        return *this;
    }

    CircularInt& CircularInt :: operator*=(const CircularInt& c)
    {
        hour = (hour * c.hour)%maxhour;
        return *this;
    }

    CircularInt& CircularInt :: operator/=(const CircularInt& c)
    {
        if(hour%c.hour==0)
        {
            hour = (hour / c.hour)%maxhour;
            return *this;
        }
        else
        {
            cout<<"There is no number x in {"<<minhour<<","<<maxhour<<"} such that x*"<<c.hour<<"="<<hour<<endl;
        }
    }

    int CircularInt :: operator=(int value)
    {
        if(minhour<=value&&value<=maxhour)
            hour = value%maxhour;
    }

    int CircularInt :: operator+(int value)
    {
        return (hour+value)%maxhour;
    }

    int CircularInt :: operator-(int value)
    {
        int res = (hour - value)%maxhour;
        if(res<=0)
            res += 12;
        return res;
    }

    int CircularInt :: operator*(int value)
    {
        return (hour*value)%maxhour;
    }

    int CircularInt :: operator/(int value)
    {
        if(hour%value==0)
           return (hour / value)%maxhour;
        else
        {
            cout<<"There is no number x in {"<<minhour<<","<<maxhour<<"} such that x*"<<value<<"="<<hour<<endl;
        }
    }

    int CircularInt :: operator+(const CircularInt& c)
    {
        if(maxhour==c.maxhour)
            return (hour+c.hour)%maxhour;
    }

    int CircularInt :: operator-(const CircularInt& c)
    {
        if(maxhour==c.maxhour)
            return (hour-c.hour)%maxhour;
    }

    int CircularInt :: operator*(const CircularInt& c)
    {
        return (hour*c.hour)%maxhour;
    }

    CircularInt& CircularInt :: operator++(int value)
    {
        hour = (hour + 1)%maxhour;
        return *this;
    }

    CircularInt& CircularInt :: operator--(int value)
    {
        int res = (hour - 1)%maxhour;
        if(res<=0)
            res += 12;
        hour = res;
        return *this;
    }

    int CircularInt :: operator==(const CircularInt& c)
    {
        return hour==c.hour;
    }

    int CircularInt :: operator!=(const CircularInt& c)
    {
        return hour!=c.hour;
    }

    int CircularInt :: operator>(const CircularInt& c)
    {
        return hour>c.hour;
    }

    int CircularInt :: operator<(const CircularInt& c)
    {
        return hour<c.hour;
    }

    int CircularInt :: operator<=(const CircularInt& c)
    {
        return hour<=c.hour;
    }

    int CircularInt :: operator>=(const CircularInt& c)
    {
        return hour>=c.hour;
    }

    int CircularInt :: operator==(int value)
    {
        return hour==value;
    }

    int CircularInt :: operator!=(int value)
    {
        return hour!=value;
    }

    int CircularInt :: operator>(int value)
    {
        return hour>value;
    }

    int CircularInt :: operator<(int value)
    {
        return hour<value;
    }

    int CircularInt :: operator<=(int value)
    {
        return hour<=value;
    }

    int CircularInt :: operator>=(int value)
    {
        return hour>=value;
    }


int operator==(int value,const CircularInt& c)
{
    return value==c.hour;
}

int operator!=(int value,const CircularInt& c)
{
    return value!=c.hour;
}

int operator>(int value,const CircularInt& c)
{
    return value>c.hour;
}

int operator<(int value,const CircularInt& c)
{
    return value<c.hour;
}

int operator<=(int value,const CircularInt& c)
{
    value<=c.hour;
}

int operator>=(int value,const CircularInt& c)
{
    return value>=c.hour;
}

int operator+(int value, const CircularInt& c)
{
    return (value + c.hour)%c.maxhour;
}

int operator-(int value, const CircularInt& c)
{
    int res = (value - c.hour)%c.maxhour;
    if(res<=0)
        res += 12;
    return res;
}

int operator*(int value, const CircularInt& c)
{
    return (value * c.hour)%c.maxhour;
}

int operator/(int value, const CircularInt& c)
{
    if(value%c.hour==0)
        return (value / c.hour)%c.maxhour;
    else
    {
        cout<<"There is no number x in {"<<c.minhour<<","<<c.maxhour<<"} such that x*"<<value<<"="<<c.hour<<endl;
    }
}

ostream& operator<<(ostream& outs, const CircularInt& c) 
{
	return outs << c.hour;
}

istream& operator>>(istream& in, CircularInt& c) 
{
	in >> c.hour;
    return in;
}

/*int main()
{
CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;     // 8
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	cout << hour+hour << endl;                // 10 (11 hours after 11)
	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
	cout << hour/3;
    return 0;
}*/