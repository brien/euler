//  A program to demonstrate solutions to the Project Euler problems.
//  (projecteuler.net)
//
//  Copyright 2013 Brien Smith-Martinez
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

int main()
{
    cout << "Problem #1:" << endl;
    cout << one() << endl;

    cout << "Problem #2:" << endl;
    cout << two() << endl;
    
    cout << "Problem #3:" << endl;
    cout << three() << endl;

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
