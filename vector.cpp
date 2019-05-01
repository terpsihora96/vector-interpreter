#include "vector.hpp"
#include <cmath>

float Vector::getX() const {
    return _x;
}
float Vector::getY() const {
    return _y;
}

void Vector::set(float x, float y) {
    _x = x; _y = y;
}

Vector Rotate::transform(const Vector& v) {
    double cos_n = cos(_num);
    double sin_n = sin(_num);
    return Vector(cos_n * v.getX() - sin_n * v.getY(), sin_n * v.getX() + cos_n * v.getY());
}

Vector Scale::transform(const Vector& v) {
    return Vector(_num * v.getX(), _num * v.getY());
}

Vector Composition::transform(const Vector& v) {
    return _a->transform(_b->transform(v));
}
