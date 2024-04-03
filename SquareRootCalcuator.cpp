#include <iostream>

using namespace std;

double squareRoot(double num)
{
    double guess = num / 2.0;
    double prevGuess;

    do
    {
        prevGuess = guess;
        guess = (guess + num / guess) / 2.0;
    } while (abs(guess - prevGuess) >= 0.001); // Change this epsilon value for desired precision

    return guess;
}

int main()
{
    double number;

    // Input
    cout << "Enter a number: ";
    cin >> number;

    // Calculating square root
    double result = squareRoot(number);

    // Output
    cout << "Square root of " << number << " = " << result << endl;

    return 0;
}
