#include <iostream>
#include "EZVector.h"

using namespace std;
using namespace EZVector;

int main() {
    vector2 U(1, 2);
    vector2 V(4, 3);

    vector3 W(10, 11);

    printv(U + V);
    printv(U + W);

}