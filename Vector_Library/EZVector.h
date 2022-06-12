
/*
C++ Vector Library
GitHub: StarCity1
Date: 6/10/2022
Description:
A simple library that performs cross product, magnitude, and other vector-related operations. To learn how to use this library read the README.md file!
*/

/*
TODO List:
TODO: Add basic operators (+, -) to the vectors;
TODO: Add a main function so if the user directly uses this library it can perform operations and choose what options to do.
TODO: Add to Git so I can further explore options.
*/

//EZVector.h
#pragma once

#include <iostream>
#include <cmath>

using namespace std;

//Class and functions of a 3-D vector.

namespace EZVector {
    class vector3
    {
    public:
        float x;
        float y;
        float z;
        vector3(float x1 = 0, float y1 = 0, float z1 = 0)
        {
            x = x1;
            y = y1;
            z = z1;
        }

        float magnitude();
        void print();

        // Adaptable functions.
        template <typename T>
        vector3 cross(T v1);
        template <typename T>
        float dot(T v1);

        // Operators.
        template <typename T>
        vector3 operator+(T v1);
        template <typename T>
        vector3 operator-(T v1);
    };

    // Class and functions of a 2-D vector.
    class vector2
    {
    public:
        float x;
        float y;
        vector2(float x1 = 0, float y1 = 0)
        {
            x = x1;
            y = y1;
        }

        void printv();
        float magnitude();
        void print();

        // Adaptable functions.
        template <typename T>
        vector3 cross(T v1);
        template <typename T>
        float dot(T v1);

        //Operators.
        operator vector3();
        vector3 operator+(vector3 v1);
        vector2 operator+(vector2 v1);

        vector3 operator-(vector3 v1);
        vector2 operator-(vector2 v1);

    protected:
        float z = 0;
    };
    //3D vector functions

    template <typename T>
    float vector3::dot(T v)
    {
        vector3 v1 = vector3(v);
        return (x * v1.x) + (y * v1.y) + (z * v1.z);
    }

    template <typename T>
    vector3 vector3::cross(T v)
    {
        // Creating a new vector becoming the cross product.
        vector3 cross;
        vector3 v1 = vector3(v);
        cross.x = (y * v1.z) - (z * v1.y);
        cross.y = -((x * v1.z) - (z * v1.x));
        cross.z = (x * v1.y) - (y * v1.x);
        return cross;
    }

    float vector3::magnitude() {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    void vector3::print() {
        cout << "<" << x << ", " << y << ", " << z << ">" << endl;
    }

    template <typename T>
    vector3 vector3::operator+(T v1) {
        vector3 V1 = vector3(v1);
        return vector3(x + V1.x, y + V1.y, z + V1.z);
    }

    template <typename T>
    vector3 vector3::operator-(T v1)
    {
        vector3 V1 = vector3(v1);
        return vector3(x - V1.x, y - V1.y, z - V1.z);
    }

    // 2D vector functions.

    // Creates dot product of a 2-D vector.

    template <typename T>
    float vector2::dot(T v1) {
        if (typeid(v1).name() == typeid(vector3).name())
        {
            return (x * v1.x) + (y * v1.y) + (z * v1.z);
        }
        return (x * v1.x) + (y * v1.y);
    }

    // Note, the cross product of a 2-D vector is a 3-D vector, thus we need to treat the two 2-D vectors given as <x, y, z=0>

    template <typename T>
    vector3 vector2::cross(T v)
    {
        // Creating two 3-D versions of the 2-D vectors given.
        if (typeid(v).name() == typeid(vector3).name()) {
            vector3 v0(x, y, 0);
            vector3 v1(v.x, v.y, v.z);
            return v0.cross(v1);
        }
        else {
            vector3 v0(x, y, 0);
            vector3 v1(v.x, v.y, 0);
            return v0.cross(v1);
        }

    // Using the 3-D cross product function to create the cross product.
    }

    float vector2::magnitude() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void vector2::print()
    {
        cout << "<" << x << ", " << y << ">" << endl;
    }

    vector2::operator vector3() {
        vector3 new_v(x, y, z);
        return new_v;
    }

    vector2 vector2::operator+(vector2 v) {
        vector2 sum (x + v.x, y + v.y);
        return sum;
    }

    vector3 vector2::operator+(vector3 v) {
        vector3 sum (x + v.x, y + v.y, z + v.z);
        return sum;
    }

    vector2 vector2::operator-(vector2 v) {
        vector2 sum (x - v.x, y - v.y);
        return sum;
    }

    vector3 vector2::operator-(vector3 v) {
        vector3 sum (x - v.x, y - v.y, z - v.z);
        return sum;
    }

    // Functions available.

    // The main function to print vectors.
    template <typename T>
    void printv(T vector)
    {
        if (typeid(T).name() == typeid(vector2).name())
        {
            cout << "<" << vector.x << ", " << vector.y << ">" << endl;
        }
        else if (typeid(T).name() == typeid(vector3).name())
        {
            vector3 v1 = vector3(vector);
            cout << "<" << v1.x << ", " << v1.y << ", " << v1.z << ">" << endl;
        } else {
            cout << "Error: Invalid type (exit_code 1)" << endl;
            exit(1);
        }
    }

    // Simple operators with vectors.

    // NOTE: For both proj and scal the operation can be read as "the projection of vector v onto u".
    template <typename T, typename U>
    vector3 proj(T u, U v) {
        vector2 proj;
        float magnitude_u = u.magnitude();
        float dot_prod = u.dot(v);

        float t = dot_prod / magnitude_u;

        if (typeid(T).name() == typeid(vector2).name()) {
            proj.x = t * (u.x / magnitude_u);
            proj.y = t * (u.y / magnitude_u);
        }
        else if (typeid(T).name() == typeid(vector3).name()) {
            vector3 proj3d = vector3(proj);
            vector3 u1 = vector3(u);
            proj3d.x = t * (u1.x / magnitude_u);
            proj3d.y = t * (u1.y / magnitude_u);
            proj3d.z = t * (u1.z / magnitude_u);
            return proj3d;
        }

        return proj;
    }

    template <typename T, typename U>
    float scal(T u, U v) {
        float magnitude_u = u.magnitude();
        float dot_prod = u.dot(v);

        return dot_prod / magnitude_u;
    }

}