//  A program to demonstrate solutions to the Project Euler problems.
//  (projecteuler.net)
//
//  Copyright 2013-2015 Brien Smith-Martinez
//
/*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 2 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdlib>
#include <iostream>
using namespace std;

int one();
int two();
int three();
int four();
long long int five();

int main()
{
    cout << "Problem #1:" << endl;
    cout << one() << endl;

    cout << "Problem #2:" << endl;
    cout << two() << endl;
    
    cout << "Problem #3:" << endl;
    cout << three() << endl;

    cout << "Problem #4:" << endl;
    cout << four() << endl;

    cout << "Problem #5: (Incomplete)" << endl;
    cout << five() << endl;


    return EXIT_SUCCESS;
}

int one()
{
    int sum = 0;
	for(int i = 0; i < 10; i++)
	{
		if(i%3==0)
		{
			sum+=i;
		}
		else if (i%5==0)
		{
			sum+=i;
		}
	}
	return(sum); 
}

int two()
{
	int prev = 1;
	int current = 2;
	int temp = 0;
	int sum = 2;

	while( current < 4000000 )
	{
		temp = current;
		current = prev + current;
		prev = temp;
		if ( current % 2 == 0)
		{
			sum += current;
		}
	}
	return(sum); 
}

int three()
{
    long long int target = 600851475143;
    long long j = 2;
    long long prime = 1;

    while( target != 1 )
    {
        while(target % j == 0 )
        {
           if( prime < j )
           {
               prime = j;
           } 
           target /= j;
        }
        j++;
    }
    return( prime );
}

bool IsPalindrome(unsigned int num)
{
	unsigned int reversed = 0;
	unsigned int original = num;
	if( num < 10 ) return 1;
	if( num % 10 == 0) return 0;

	while( num >= 1)
	{
		reversed = (reversed * 10) + (num % 10);
		num = num/10;
	}
	return( original == reversed );
}

int four()
{
	unsigned int highestPalindrome = 0;
	unsigned int x = 999;
	unsigned int y = 999;
	unsigned int product = 0;

	while( x > 99 )
	{
		y = 999;
		while( y  >= 99 )
		{
			product = x * y;
			if (product > highestPalindrome && IsPalindrome( product ))
			{
				highestPalindrome = product;
			}
			y--;
		}
		x--;
	}
	return highestPalindrome;
}

long long int five()
{
	long long int num = 2520;
	for( int i = 11; i < 21; i++)
	{
		num *= i;
	}
	while (num > 1)
	{
		cout << num << endl;
		num--;
	}	
	return num;
}
