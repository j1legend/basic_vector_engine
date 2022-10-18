//
//  R4DVector.cpp
//  line_engine
//
//  Created by J1 on 2022/08/17.
//

#include "R4DVector.hpp"
#include<cmath>

namespace lEngine {

//constructors
R4DVector::R4DVector():x(0.0),y(0.0),z(0.0){};
R4DVector::R4DVector(float Ux,float Uy,float Uz):x(Ux),y(Uy),z(Uz){};

//deconstructors
R4DVector::~R4DVector(){};

//copy constructors
R4DVector::R4DVector(const R4DVector& v):x(v.x),y(v.y),z(v.z){};

//overloading of the = operator to work with vectors
R4DVector& R4DVector::operator=(const R4DVector& v){
   x=v.x;
   y=v.y;
   z=v.z;
   return *this;
}

//operations

//addition

R4DVector R4DVector::operator+(const R4DVector& v){
    return R4DVector(x+v.x,y+v.y,z+v.z);
}

void R4DVector::operator+=(const R4DVector& v){
    x+=v.x;
    y+=v.y;
    z+=v.z;
}

//subtraction

R4DVector R4DVector::operator-(const R4DVector& v){
    return R4DVector(x-v.x,y-v.y,z-v.z);
}

void R4DVector::operator-=(const R4DVector& v){
    x-=v.x;
    y-=v.y;
    z-=v.z;
}
//scalar multiplication

R4DVector operator*(R4DVector &v,const float& f){
    return R4DVector(v.x*f,v.y*f,v.z*f);
}

//commutative property
R4DVector operator*(const float& f,R4DVector &v){
    return v*f;
}

void R4DVector::operator*=(const float& f){
    x*=f;
    y*=f;
    z*=f;
}

//scalar division

R4DVector operator/(R4DVector &v ,const float& f){
    return R4DVector(v.x/f,v.y/f,v.z/f);
}

//commutative

R4DVector operator/(const float& f,R4DVector &v ){
    return v/f;
}

void R4DVector::operator/=(const float& f){
    x/=f;
    y/=f;
    z/=f;
}

//dot product

float R4DVector::dot (const R4DVector& v) {
    return x * v.x + y * v.y + z * v.z;
}
float dot(const R4DVector& v, const R4DVector& u){
    return v.x * u.x + v.y * u.y + v.z*u.z;
}

float R4DVector::operator * (const R4DVector&v){
    return x * v.x + y * v.y + z * v.z;
}

//cross product
R4DVector R4DVector::cross(const R4DVector& v){
    return R4DVector(y*v.z-z*v.y,
                       z*v.x-x*v.z,
                       x*v.y-y*v.x);
}
R4DVector R4DVector::operator % (const R4DVector &v){
    return R4DVector(y*v.z-z*v.y,
                       z*v.x-x*v.z,
                       x*v.y-y*v.x);
}
void R4DVector::operator %= (const R4DVector &v){
    *this=cross(v);
}

/* magnitude */
float R4DVector::magnitude(){
    return std::sqrt(x*x+y*y+z*z);
}

/* normalize */
void R4DVector::normalize(){
    float mag = sqrt(x*x+y*y+z*z);
    
    if(mag > 0.0f)
    {
        x/=mag;
        y/=mag;
        z/=mag;
    }
}

}
