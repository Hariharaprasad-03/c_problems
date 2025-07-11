#include <stdio.h>
float sqrte(float num)
{
    float guess = num / 2;
    float epsilon = 0.0001;
    float diff;
    do
    {

        float new_guess = 0.5 * (guess + num / guess);
        diff = guess - new_guess;
        if (diff < 0)
            diff *= -1;
        guess = new_guess;

    } while (diff > epsilon);
      return guess;
}

int main()
{

    float num = 25;
    float result = sqrte(num);
    printf("%f\n", result);
    return 0;
}