//Emmanuel Atanga
#include <iostream>
using namespace std;

#define USE_FLOATS
#define CONVERT_TO_CM(X) (((X)*(FEET_TO_CM)))
#define FEET_TO_CM 30.48
#ifdef USE_FLOATS
float a = 18.0f;
float b ;
#else
double a = 18.0;
double b;
#endif

int main(int argc, char* argv[]) {
    b = CONVERT_TO_CM(a);
    cout << b;
    return 0;
}
