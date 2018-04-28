#include <iostream>
#include <stdio.h>

using namespace std;

class CircularInt
{
    public:
    int minhour;
    int hour;
    int maxhour;

    CircularInt(int a, int b);


    int operator-();


    ostream& operator<<(CircularInt& c);


    CircularInt& operator=(const CircularInt& c);


    CircularInt& operator+=(int value);


    CircularInt& operator-=(int value);


    CircularInt& operator*=(int value);


    CircularInt& operator/=(int value);


    CircularInt& operator+=(const CircularInt& c);


    CircularInt& operator-=(const CircularInt& c);


    CircularInt& operator*=(const CircularInt& c);


    CircularInt& operator/=(const CircularInt& c);


    CircularInt& operator=(int value);


    int operator+(int value);


    int operator-(int value);


    CircularInt operator*(int value);


    int operator/(int value);


    int operator+(const CircularInt& c);


    int operator-(const CircularInt& c);


    CircularInt operator*(const CircularInt& c);

    
    int operator/(const CircularInt& c);


    CircularInt& operator++(int value);

    CircularInt& operator--(int value);

    int operator==(const CircularInt& c);

    int operator!=(const CircularInt& c);

    int operator>(const CircularInt& c);

    int operator<(const CircularInt& c);

    int operator<=(const CircularInt& c);

    int operator>=(const CircularInt& c);

    int operator==(int value);

    int operator!=(int value);

    int operator>(int value);

    int operator<(int value);

    int operator<=(int value);

    int operator>=(int value);
};

int operator==(int value,const CircularInt& c);


int operator!=(int value,const CircularInt& c);


int operator>(int value,const CircularInt& c);


int operator<(int value,const CircularInt& c);


int operator<=(int value,const CircularInt& c);


int operator>=(int value,const CircularInt& c);


int operator+(int value, const CircularInt& c);

int operator-(int value, const CircularInt& c);


CircularInt operator*(int value, const CircularInt& c);


int operator/(int value, const CircularInt& c);


ostream& operator<<(ostream& outs, const CircularInt& c);


istream& operator>>(istream& in, CircularInt& c);

int arrange(int hour, const CircularInt& c);

int divide(int hour, const CircularInt& c);

int divide(const CircularInt& c, int hour);

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