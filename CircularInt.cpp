#include <iostream>
#include <stdio.h>

using namespace std;

#include "CircularInt.hpp"

     CircularInt :: CircularInt(int a, int b)
    {
        if(a>=b||b<0)
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
        return arrange(-hour,*this);
    }

    ostream& CircularInt :: operator<<(CircularInt& c)
    {
        return cout<<c.hour;
    }

    CircularInt& CircularInt :: operator=(const CircularInt& c)
    {
        hour = arrange(c.hour, *this);
        return *this;
    }

    CircularInt& CircularInt :: operator+=(int value)
    {
        hour = arrange(hour+value,*this);
        return *this;
    }

    CircularInt& CircularInt :: operator-=(int value)
    {   
        hour = arrange(hour-value,*this);
        return *this;
    }

    CircularInt& CircularInt :: operator*=(int value)
    {
        hour = arrange(hour*value,*this);
        return *this;
    }
    //letaken lemata
    CircularInt& CircularInt :: operator/=(int value)
    {
        int d = divide(*this,value);
        if(d!=0)
            hour = d;
        else
            cout<<"There is no number x in {"<<minhour<<","<<maxhour<<"} such that x*"<<value<<"="<<hour<<endl;
        return *this;
    }

    CircularInt& CircularInt :: operator+=(const CircularInt& c)
    {
        hour = arrange(hour+c.hour,*this);
        return *this;
    }

    CircularInt& CircularInt :: operator-=(const CircularInt& c)
    {   
        hour = arrange(hour-c.hour,*this);
        return *this;
    }

    CircularInt& CircularInt :: operator*=(const CircularInt& c)
    {
        hour = arrange(hour*c.hour,*this);
        return *this;
    }
    //letaken lemata
    CircularInt& CircularInt :: operator/=(const CircularInt& c)
    {
        int d = divide(*this,c.hour);
        if(d!=0)
            hour = d;
        else
            cout<<"There is no number x in {"<<minhour<<","<<maxhour<<"} such that x*"<<c.hour<<"="<<hour<<endl;
        return *this;
    }

    CircularInt& CircularInt :: operator=(int value)
    {
        hour = arrange(value,*this);
    }

    int CircularInt :: operator+(int value)
    {
        return arrange(hour+value,*this);
    }

    int CircularInt :: operator-(int value)
    {
        return arrange(hour-value,*this);
    }

    int CircularInt :: operator*(int value)
    {
        return arrange(hour*value,*this);
    }
    //letaken lemata
    int CircularInt :: operator/(int value)
    {
        return divide(*this,value);
    }

    int CircularInt :: operator+(const CircularInt& c)
    {
        return arrange(hour+c.hour,*this);
    }

    int CircularInt :: operator-(const CircularInt& c)
    {
        return arrange(hour-c.hour,*this);
    }

    int CircularInt :: operator*(const CircularInt& c)
    {
        return arrange(hour*c.hour,*this);
    }

    int CircularInt :: operator/(const CircularInt& c)
    {
        return divide(*this,c.hour);
    }

    CircularInt& CircularInt :: operator++(int value)
    {
        hour = arrange(hour+1,*this);
        return *this;
    }

    CircularInt& CircularInt :: operator--(int value)
    {
        hour = arrange(hour-1,*this);
        return *this;
    }

    int CircularInt :: operator==(const CircularInt& c)
    {
        return hour==arrange(c.hour,*this);
    }

    int CircularInt :: operator!=(const CircularInt& c)
    {
        return hour!=arrange(c.hour,*this);
    }

    int CircularInt :: operator>(const CircularInt& c)
    {
        return hour>arrange(c.hour,*this);
    }

    int CircularInt :: operator<(const CircularInt& c)
    {
        return hour<arrange(c.hour,*this);
    }

    int CircularInt :: operator<=(const CircularInt& c)
    {
        return hour<=arrange(c.hour,*this);
    }

    int CircularInt :: operator>=(const CircularInt& c)
    {
        return hour>=arrange(c.hour,*this);
    }

    int CircularInt :: operator==(int value)
    {
        return hour==arrange(value,*this);
    }

    int CircularInt :: operator!=(int value)
    {
        return hour!=arrange(value,*this);
    }

    int CircularInt :: operator>(int value)
    {
        return hour>arrange(value,*this);
    }

    int CircularInt :: operator<(int value)
    {
        return hour<arrange(value,*this);
    }

    int CircularInt :: operator<=(int value)
    {
        return hour<=arrange(value,*this);
    }

    int CircularInt :: operator>=(int value)
    {
        return hour>=arrange(value,*this);
    }


int operator==(int value,const CircularInt& c)
{
    return arrange(value,c)==c.hour;
}

int operator!=(int value,const CircularInt& c)
{
    return arrange(value,c)!=c.hour;
}

int operator>(int value,const CircularInt& c)
{
    return arrange(value,c)>c.hour;
}

int operator<(int value,const CircularInt& c)
{
    return arrange(value,c)<c.hour;
}

int operator<=(int value,const CircularInt& c)
{
    return arrange(value,c)<=c.hour;
}

int operator>=(int value,const CircularInt& c)
{
    return arrange(value,c)>=c.hour;
}

int operator+(int value, const CircularInt& c)
{
    return arrange(value+c.hour,c);
}

int operator-(int value, const CircularInt& c)
{
    return arrange(value-c.hour,c);
}

int operator*(int value, const CircularInt& c)
{
    return arrange(value*c.hour,c);
}
//letaken lemata
int operator/(int value, const CircularInt& c)
{
    return divide(value,c);
}

ostream& operator<<(ostream& outs, const CircularInt& c) 
{
	return outs << c.hour;
}

istream& operator >> (istream& in, CircularInt& c) 
{
	in>>c.hour;
    c.hour=arrange(c.hour,c);
    return in;
}

int arrange(int hour, const CircularInt& c)
{
    if(c.minhour<=hour&&hour<=c.maxhour)
        return hour;

    else if(hour<c.minhour)
        return c.maxhour - (c.minhour - hour - 1)%(c.maxhour - c.minhour + 1);
        
    else
        return c.minhour + (hour - c.maxhour - 1)%(c.maxhour - c.minhour + 1);
}

int divide(int hour, const CircularInt& c)
{
    for(int i=c.minhour;i<=c.maxhour;i++)
        if(i*c.hour==hour)
            return i;
    return 0;
}

int divide(const CircularInt& c, int hour)
{
    for(int i=c.minhour;i<=c.maxhour;i++)
        if(i*hour==c.hour)
            return i;
    return 0;    
}

/*int main()
{
    CircularInt c {5, 7};
    cout<<arrange(11,c);
}*/
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