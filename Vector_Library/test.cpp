#include <iostream>
#include "EZVector.h"

using namespace std;
using namespace EZVector;

int main() {
    vector3 u(0, 4, -2);
    vector3 v(0, -3, -2);
    vector3 u_prime(0, -2, -4);
    vector3 v_prime(-3, -2, 2);

    printv(u.cross(v_prime));

    printv(v.cross(u_prime));

    printv(u.cross(v_prime) + u_prime.cross(v));
}