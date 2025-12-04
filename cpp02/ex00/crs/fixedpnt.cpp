#include <cmath> // for roundf
#include <iostream>
#include <iomanip>

// 1. Setup your format
// Example: We are using a standard 'int' (32 bits width)
// We decide to use 8 bits for the fractional part.
const int FRACTIONAL_BITS = 8; 

// 2. Float -> Fixed (Encoding)
int floatToFixed(float number) {
    // 1 << 8 is the same as 2^8 (256)
    return roundf(number * (1 << FRACTIONAL_BITS));
}

// 3. Fixed -> Float (Decoding)
float fixedToFloat(int fixedPointNumber) {
    // We must cast one side to float to get a decimal result
    return (float)fixedPointNumber / (1 << FRACTIONAL_BITS);
}

int main(void)
{
	float N = 104.13757f;

    std::cout << std::fixed << std::setprecision(10); 

    std::cout << "Original Float (High Precision): " << N << std::endl;

    int F = floatToFixed(N);
    float decoded = fixedToFloat(F);

    std::cout << "Decoded Float  (High Precision): " << decoded << std::endl;

	return 0;
}

