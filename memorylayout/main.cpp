//Emmanuel Atanga
//Passing and Returning pointers
//10/12/2020
#include <iostream>

using namespace std;


int* getMinimum(int *a, int *b) {

    // TODO: return the pointer that points to a lowest value (not necessarily the smallest address)
    if (*a < *b)
       return a;
    else
        return b;
}

int main() {
    int clockA = 40;
    int clockB = 50;
    int alarm = 60;

    while (clockA < alarm && clockB < alarm) {
        (*getMinimum(&clockA, &clockB))++;
        cout << "The time in region A is " << clockA << " and in region B is "
             << clockB << endl;

    }


    return 0;

}
