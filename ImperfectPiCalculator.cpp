#include <iostream>
#include <iomanip>

using namespace std;

const long double NAN_VALUE = 0.0 / 0.0;

long double sqrt(long double x)
{
    if (x == 0)
        return 0;
    long double guess = x;
    while (true)
    {
        long double nextGuess = 0.5 * (guess + x / guess);
        if (nextGuess == guess)
            break;
        guess = nextGuess;
    }
    return guess;
}

long double log(long double x)
{
    if (x <= 0)
        return NAN_VALUE;
    long double result = 0;
    long double term = (x - 1) / (x + 1);
    long double termSquared = term * term;
    long double denom = 1;
    for (int i = 1; i <= 1000; i += 2)
    {
        result += term / denom;
        term *= termSquared;
        denom += 2;
    }
    return 2 * result;
}

int ceil(long double x)
{
    int intPart = static_cast<int>(x);
    if (static_cast<long double>(intPart) == x)
        return intPart;
    return intPart + 1;
}

long double calculatePi(int numIterations)
{
    long double a = 1.0;
    long double b = 1.0 / sqrt(2);
    long double t = 0.25;
    long double p = 1.0;

    for (int i = 0; i < numIterations; ++i)
    {
        long double a_next = (a + b) / 2.0;
        long double b_next = sqrt(a * b);
        long double t_next = t - p * (a - a_next) * (a - a_next);
        long double p_next = 2.0 * p;

        a = a_next;
        b = b_next;
        t = t_next;
        p = p_next;
    }

    return (a + b) * (a + b) / (4 * t);
}

int main()
{
    int numDigits;
    cout << "Enter the number of digits of pi you want to calculate: ";
    cin >> numDigits;

    int numIterations = ceil(numDigits * log(10) / log(2) + 1);

    cout << setprecision(numDigits + 1);
    cout << "Pi to " << numDigits << " digits: " << calculatePi(numIterations) << endl;

    return 0;
}
