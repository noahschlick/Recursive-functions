
//
//  The purpose of this program is to test 4 recursive functions
//  that operate different task.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


/*                 AP
 Takes three  non-negative integer parameters star,
 diff, and n and returns the nth value in the arithmetic
 progression starting at star, with difference diff.
 */
int AP(int start, int diff, int n)
{
    
    if (n == 0)
        return start;
    else
    {
        start += diff;  // add the difference to the sum
        return AP(start, diff, n - 1);
    }
}



/*                averageArray(resurcise)
 Computes thhe average of a arrray of double values.
 take in a parameter of an array of double, the size of
 the array, a varriable to represent the index of the
 array, and a value to represent the average.
 The output of the function will be the average of the array.
 */
double averageArray(double array[], int n, int i, double avSum)
{
    if (i == n)
        return avSum;
    else
    {
        // add the current value diveded by total values
        avSum += array[i]/n;
        return averageArray(array, n, i+1, avSum);
    }
}

/*              averageArray(overload)
 Overload function the recusive average array function.
 The function makes it easier to call the average array
 by not having to include i and average sum parmeters.
 */
double averageArray(double array[], int n)
{
    return averageArray(array, n, 0, 0);
}

/*              stdDevArray
 Calculates the standard deviation of an array of numbers.
 */
double stdDevArray(double array[], int n, int i, double stDev)
{
    double average = averageArray(array, n);
    
    if (i == n)
    {
        // Divide by total and square root
        stDev = stDev/n;
        return sqrt(stDev);
    }
    else
    {
        // Accumulate values subtracted by values squared
        stDev += (array[i] - average) * (array[i] - average);
        return stdDevArray(array, n, i+1, stDev);
    }
}

/*          stdDevArray(Overload)
 Over load function of the standard deviation function.
 This function only takes in the arrray and size of the
 array to make the call more simple.
 */
double stdDevArray(double array[], int n)
{
    return stdDevArray(array, n, 0, 0);
}

/*              encrypt
This function takes in a string and encrypts the
string using a simple key. The function recures
until the index parameter, i is equal to the size.
The function only converst alphabet letters.
 */
string encrypt(string str, int i)
{
    
    string key = "XYZABCDEFGHIJKLMNOPQRSTUVW";
    if (i == str.size())
        return str;
    else if (!isalpha(str[i]))
        return encrypt(str, i+1);
    else
    {
        // Convert to uppercase
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        // Convert to apropriate key letter using ASCII
        str[i] = key[int(str[i]) - 65];
        return encrypt(str, i+1);
    }
}

string encrypt(string str)
{
    return encrypt(str, 0);
}




int main()
{
    double array[] = {8.1, 9.9, 5.6, 7.8};
    int n = 4;
    string str = "Noah!";
    
    cout << "Testing Arithmetic Process: ";
    cout << AP(5,2,1) << endl;
    
    cout << endl << "Testing average: ";
    cout << averageArray(array, n) << endl;
    
    cout << endl << "Testing standard D: ";
    cout << stdDevArray(array, n) << endl;
    
    cout << "Testing Encryption with string, " << str << ": ";
    str = encrypt(str);
    cout << str << endl;
    
    
}
