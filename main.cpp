//
//  main.cpp
//  happy
//
//  Created by Raja Patel on 2/15/14.
//
//

#include <iostream>
#include <map>
#include <set>
//////////////////////////
/* ACKNOWLEDGMENT:
 Happy numbers code was based on a code from http://rosettacode.org/wiki/Happy_numbers#C.2B.2B 
 The code was then analyzed and changed to limit output to 10,000 happy numbers and to format 10 happy numbers per line of displayed output. 
 */
///////////////////////////
using namespace std;

bool happy(int NUM)
{
    static map<int, bool> cache;
    set<int> index;
    
    while (NUM != 1 && !index.count(NUM))
    {
        if (cache.count(NUM))
        {
            NUM = cache[NUM] ? 1 : 0;
            break;
        }
        index.insert(NUM);
        int NUM2 = 0;
        while (NUM > 0)
        {
            int VAR2 = NUM % 10;
            NUM2 += VAR2 * VAR2;
            NUM /= 10;
        }
        NUM = NUM2;
    }
    bool happiness = NUM == 1;
    for (set<int>::const_iterator it = index.begin(); it != index.end(); it++)
    {
        cache[*it] = happiness;
    }
    return happiness;
}

int main()
{
    int adder = 0;
//limit total output and happy numbers per line
    while (adder < 10000)
    {
        for (int i = 1; i < 10000000; i++)
        {
            if (happy(i))
            {
                adder++;
                cout << i << " ";
                if (adder % 10 == 0)
                {
                    cout << endl;
                }
            }
        }
    }
    return 0;
}