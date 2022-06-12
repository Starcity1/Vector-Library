# ==== EZVector ====
Author Starcity1
Version 1.0.0

## ==== Description ====
Hello! This is my first library as I create various libraries and small projects to share!
EZVector is a library that supports 2D and 3D vector operations including adding, substractions, cross product, dot product,
and vector and scalar projections. This is a small project and I am hopeful to add various other functions as I practice more with CPP. Below is a description for each function.

## ==== Functions ====
**namespace: EZVector**

`class vector3(float x = 0, flaot y = 0, float z = 0)`

Vector3 is a representation of a 3D vector, the user can update its x, y, and z functions and can also call various functions contained in the class. It contains an x, y, z paramaters in the class constructor so the user can initialize a vector with specific float values.
`vector3 Vector(1, 2, 3)`

- `vector3 vector3::cross(T v)`
This class method forms the cross product of the object being used and another (either vector3 or vector2) vector, it will return a vector3 class obejct.