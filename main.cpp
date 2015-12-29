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
#include <string>
using namespace std;

int one();
int two();
int three();
int four();
long long int five();
long int six();
long int seven();
unsigned long long eight();
int nine();
unsigned long ten();

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

    	cout << "Problem #5:" << endl;
    	cout << five() << endl;

    	cout << "Problem #6:" << endl;
    	cout << six() << endl;
   
    	cout << "Problem #7:" << endl;
    	cout << seven() << endl;

    	cout << "Problem #8:" << endl;
    	cout << eight() << endl;

    	cout << "Problem #9:" << endl;
    	cout << nine() << endl;
   
	cout << "Problem #10: Incomplete" << endl;
    	cout << ten() << endl;


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
	long long int num = 20;
	while ( num %  2 != 0 || num %  3 != 0 || num %  4 != 0 || num %  5 != 0 ||
       		num %  6 != 0 || num %  7 != 0 || num %  8 != 0 || num %  9 != 0 ||
         	num % 10 != 0 || num % 11 != 0 || num % 12 != 0 || num % 13 != 0 ||
        	num % 14 != 0 || num % 15 != 0 || num % 16 != 0 || num % 17 != 0 ||
         	num % 18 != 0 || num % 19 != 0 || num % 20 != 0)
	{
		num+=20;
	}	

	return num;
}

long int six()
{
	long int sum = 0;
	long int squared = 0;
	long int result = 0;

	sum = 100 * (100 + 1)/2;
	squared = (100 * (100 + 1) * (2 * 100 + 1)) / 6;
	return (sum * sum) - squared;
}

bool isPrime(long int num)
{
	if(num <= 1)
	{
		return false;
	}

	if(num == 2)
	{
		return true;
	}
	
	if(num % 2 == 0)
	{
		return false;
	}
	int i = 3;
	while( (i * i) <= num)
	{
		if(num % i == 0)
		{
			return false;
		}
		else
		{
			i += 2;
		}
	}

	return true;
}

long int seven()
{
	int primecount = 1;
	int num = 1;
	while( primecount < 10001)
	{
		num = num + 2;
		if( isPrime(num) )
		{
			primecount++;
		}
	}
	return num;
}

unsigned long long  eight()
{

	const string p = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	unsigned long long num = 0;
	unsigned long long largest = 0;
	for( int i = 0; i < p.length() - 12; i++)
	{
		num  = atoi(p.substr(i,1).c_str());
		for( int j = i+1; j < i + 13; j++)
		{
			num = num * atoi(p.substr(j,1).c_str());
		}
		if( num > largest )
		{
			largest = num;
		}
	}
 
	return largest;
}

int nine()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int cir = 1000;
	int ret = 0;
	for( a = 1; a < cir / 3; a++)
	{
		for( b = a; b < cir / 2; b++)
		{
			c = cir - a - b;
			if( a * a + b * b == c * c)
			{
				ret = a*b*c;
				break;
			}
		}
	}
	return ret;
}

unsigned long ten()
{
	// Sieve of Eratosthenes
	//1. Create list of consecutive integers
	//2. Select p as the first prime number in the list
	//3. Remove all multiples of p from list
	//4. Set p equal to the next integer in the list which has not been reomved
	//5.Repeat #3 and 4 until p^2 > N.
	return 0;
}
