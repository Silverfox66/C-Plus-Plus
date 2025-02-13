/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2

There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc. */

#include <iostream>
#include <cmath>

using namespace std;

bool isPythagoreanTriple(const int &a, const int &b, const int &c)
{
    if(pow(a, 2) + pow(b, 2) == pow(c, 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    bool found = false;
    for(int a = 1; a <= 1000 && !found ; a++)
    {
        for(int b = 1; b <= 1000 && !found; b++)
        {
            for(int c = 1; c <= 1000 && !found; c++)
            {
                if(isPythagoreanTriple(a, b, c))
                {
                    if(a + b + c == 1000)
                    {
                        cout << a * b * c << endl;
                        found = true;
                    }
                }
            }
        }
    }
    return 0;
}