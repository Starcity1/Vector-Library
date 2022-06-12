# ==== EZVector ====
Author Starcity1
Version 1.0.0

## ==== Description ====
Hello! This is my first library as I create various libraries and small projects to share!
EZVector is a library that supports 2D and 3D vector operations including adding, substractions, cross product, dot product,
and vector and scalar projections. This is a small project and I am hopeful to add various other functions as I practice more with CPP. Below is a description for each function.[^1]

[^1]: Please if anybody finds any bugs lmk, I bet that this code is full of them lol.

## ==== Functions ====
**namespace: EZVector**



**'vector3' Class :: **



`class vector3(float x = 0, flaot y = 0, float z = 0)`

**Vector3** is a representation of a 3D vector, the user can update its x, y, and z class attributes and can also call various functions contained in the class. It contains an x, y, z paramaters in the class constructor so the user can initialize a vector with specific float values.
```
// Creates a 3D vector object of form <1, 2, 3>
vector3 Vector(1, 2, 3);
```
`vector3 vector3::cross(T v)`[^2]
: This class method forms the cross product of the object being used and another (either vector3 or vector2) vector. It will return a vector3 class obejct.
The order of the cross product has the vector3 object being used as the first vector on the dot product and the vector used as parameter as the second vector being used.
```
vector3 V(1, 1, 1);
vector2 U(3, 2);

//This operation can be read as : 'V X U'
printv(V.cross(U));
```

`float vector3::dot(T v)`
: This class method calculates the dot product formed by the object being used and another (either vector3 or vector2) vector. It will return a float number.
```
vector3 V(1, 1, 1);
vector2 U(3, 2);

//This operation can be read as : 'V ⋅ U'
printf(V.dot(U));
```

`vector3 vector3::operator+(T V)`
: This class operator creates the sum of the vector3 object being used and the another (either vector3 or vector2) vector. It will return a vector3 object.
```
vector3 V(1, 1, 1);
vector2 U(3, 2);

//This operation can be read as : 'V + U'
printv(V + U);
```

`vector3 vector3::operator-(T V)`
: This class operator creates the difference of the vector3 object being used and the another (either vector3 or vector2) vector. It will return a vector3 object.
```
vector3 V(1, 1, 1);
vector2 U(3, 2);

//This operation can be read as : 'V - U'
printv(V - U);
```


**'vector2' Class :: **



`class vector2(float x = 0, flaot y = 0)`

**Vector3** is a representation of a 2D vector, the user can update its x, and y class attributes and can also call various functions contained in the class. It contains x, y paramaters in the class constructor so the user can initialize a vector with specific float values.
```
// Creates a 3D vector object of form <1, 3>
vector3 Vector(1, 3);
```

`T vector2::cross(T v)`
: This class method forms the cross product of the object being used and another (either vector3 or vector2) vector. It will return a vector3 class obejct.
The order of the cross product has the vector3 object being used as the first vector on the dot product and the vector used as parameter as the second vector being used.
```
vector2 V(1, 1);
vector3 U(3, 2, 0);

//This operation can be read as : 'V X U'
printv(V.cross(U));
```

`float vector2::dot(T v)`
: This class method calculates the dot product formed by the object being used and another (either vector3 or vector2) vector. It will return a float number.
```
vector3 V(1, 1);
vector2 U(3, 2, 0);

//This operation can be read as : 'V ⋅ U'
printf(V.dot(U));
```

`T vector2::operator+(T V)`
: This class operator creates the sum of the vector3 object being used and the another (either vector3 or vector2) vector. It will return either a vector3 or vector2 object.
```
vector2 V(1, 1);
vector3 U(3, 2, 0);

//This operation can be read as : 'V + U'
printv(V + U);
```

`T vector3::operator-(T V)`
: This class operator creates the difference of the vector3 object being used and the another (either vector3 or vector2) vector. It will return either a vector3 or vector2 object.
```
vector2 V(1, 1);
vector3 U(3, 2, 0);

//This operation can be read as : 'V - U'
printv(V - U);
```

`vector3 vector2::vector3(vector2 V)`
: This class operator allows the user to cast a vector2 class object into a vector3 class object. It will return a vector3 object.
```
vector2 V(1, 1);
vector3 U(3, 2, 0);

//The output of this printv value is <1, 1, 0> with a class type of vector3.
printv(vector3(V));
```



** Other Functions :: **



`printv(T vector)`

[^2]: Note: In every example a 'T' data type refers that the function can accept either vector3 or vector2 class objects.
