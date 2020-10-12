//============================================================================
// Name        : NoConversion.cpp
// Author      : Vikas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Number
{
protected:
	int value;

public:
	Number(int v)
	{
		value=v;
	}
	virtual int print_it()
	{
		return value;
	}
};

class Hex : public Number
{
public:
	Hex(int n)
	{
		Number(n);
	}

	int print_it()
		{
			int n= print_it();
			char hex[100];
			int i=0;
			while(n!=0)
			{
				//temp for remainder
				int temp = 0;

				temp = n % 16;

				if(temp < 10)
				{
					hex[i]= temp + 48;
					i++;
				}
				else
				{
					hex[i] = temp + 55;
					i++;
				}

				n=n/16;
			}

			//Printing in reverse order
			for(int j=i-1; j>=0;j--)
			{
				cout<<hex[j];
			}
		}

};

class Octal : public Number
{
public:
	int print_it()
	{
		int n = print_it();
		int oct[100];

		int i=0;
		while(n!=0)
		{
			oct[i]= n % 8;
			n= n/8;
			i++;
		}

		//print in reverse order
		for(int j=i-1; j>=0; j--)
		{
			cout<<oct[j];
		}

	}

};

int main() {
	int number;
	cout<<"Enter an Integer : ";
	cin>>number;

	Number *n1 =new  Hex(number);
	n1->print_it();
	return 0;
}
