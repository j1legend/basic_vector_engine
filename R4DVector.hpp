//
//  R4DVector.hpp
//  line_engine
//
//  Created by J1 on 2022/08/17.
//

#ifndef R4DVector_hpp
#define R4DVector_hpp

#include <stdio.h>

namespace lEngine {
class R4DVector{
private:
public:
    //x y z dimensions
    float x,y,z;
    
    //constructors
    R4DVector();
    R4DVector(float Ux,float Uy,float Uz);
    
    //deconstructors
    ~R4DVector();
    
    //copy constructors
    R4DVector(const R4DVector& v);
    R4DVector& operator=(const R4DVector& v);
    
    /* operations */
    
    //addition
    R4DVector operator + (const R4DVector& v);
    void operator += (const R4DVector& v);
    
    //subtraction
    R4DVector operator - (const R4DVector& v);
    void operator -= (const R4DVector& v);
    
    //scalar multiplication 
    void operator *= (const float& f);
    
    //scalar division
    void operator /= (const float& f);
    
    //dot product
    float dot(const R4DVector& v);
    float operator * (const R4DVector& v);
    
    //cross product
    R4DVector cross(const R4DVector& v);
    void operator %= (const R4DVector &v);
    R4DVector operator % (const R4DVector &v);
    
    /* magnitude */
    float magnitude();
    
    /* normalize */
    void normalize();
};

//non-member functions

//operators

//scalar
R4DVector operator * (R4DVector& v,const float& f);
R4DVector operator * (const float& f ,R4DVector& v);

R4DVector operator / (R4DVector& v,const float& f);
R4DVector operator / (const float& f,R4DVector& v);

//dot product
float dot(const R4DVector& v, const R4DVector& u);


}
#endif /* R4DVector_hpp */
