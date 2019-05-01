#ifndef __VECTOR__
#define __VECTOR_1__

#include <iostream>
#include <string>
#include <vector>

class Vector {
public:
    Vector(float a = 0, float b = 0)
     : _x(a), _y(b)
    { }
    
    float getX() const;
    float getY() const;
    void set(float x, float y);
    
    Vector operator- (const Vector& v) const {
    return Vector(getX() - v.getX(), getY() - v.getY());
    }

    Vector operator+ (const Vector& v) const {
        return Vector(getX() + v.getX(), getY() + v.getY());
    }

    Vector operator* (const float& k) const {
        return Vector(getX() * k, getY() * k);
    }

private:
    float _x, _y;

friend std::ostream& operator << (std::ostream& ostr, const Vector& v) {
    std::cout << '[' << v.getX() << ", " << v.getY() << ']';
    return ostr;
}

};

class Transformation {
public:
    virtual Vector transform(const Vector& v) = 0;
    virtual ~Transformation() {} ;
};

class Rotate : public Transformation {
public:
    Rotate(float num)
     : _num(num)
    { }

    Vector transform(const Vector& v);

private:
    float _num;
};

class Scale : public Transformation {
public:
    Scale(float num)
     : _num(num)
    { }

    Vector transform(const Vector& v);    

private:
    float _num;
};

class Composition : public Transformation {
public:
    Composition(Transformation* a, Transformation* b)
     : _a(a), _b(b)
    { }

    Vector transform(const Vector& v);    

private:
    Transformation *_a, *_b;
};

#endif
