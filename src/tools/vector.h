#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>


typedef struct {
    int x;
    int y;
} Vector2Int;

typedef struct {
    double x;
    double y;
} Vector2;

// forward declarations
Vector2Int addVectorsInt (Vector2Int vector1, Vector2Int vector2);
Vector2 addVectors (Vector2 vector1, Vector2 vector2);
Vector2Int subtractVectorsInt (Vector2Int vector1, Vector2Int vector2);
Vector2 subtractVectors (Vector2 vector1, Vector2 vector2);
Vector2Int multiplyVectorsInt (Vector2Int vector1, Vector2Int vector2);
Vector2 multiplyVectors (Vector2 vector1, Vector2 vector2);
int magnitudeVectorInt (Vector2Int vector);
double magnitudeVector (Vector2 vector);
Vector2Int normalizeVectorInt (Vector2Int vector);
Vector2 normalizeVector (Vector2 vector);
Vector2Int scaleVectorInt (Vector2Int vector, int scalar);
Vector2 scaleVector (Vector2 vector, double scalar);
Vector2Int divideVectorInt (Vector2Int vector, int scalar);
Vector2 divideVector (Vector2 vector, double scalar);


Vector2Int addVectorsInt (Vector2Int vector1, Vector2Int vector2) {
    Vector2Int vector3;
    vector3.x = vector1.x + vector2.x;
    vector3.y = vector1.y + vector2.y;
    return vector3;
}

Vector2 addVectors (Vector2 vector1, Vector2 vector2) {
    Vector2 vector3;
    vector3.x = vector1.x + vector2.x;
    vector3.y = vector1.y + vector2.y;
    return vector3;
}

Vector2Int subtractVectorsInt (Vector2Int vector1, Vector2Int vector2) {
    Vector2Int vector3;
    vector3.x = vector1.x - vector2.x;
    vector3.y = vector1.y - vector2.y;
    return vector3;
}

Vector2 subtractVectors (Vector2 vector1, Vector2 vector2) {
    Vector2 vector3;
    vector3.x = vector1.x - vector2.x;
    vector3.y = vector1.y - vector2.y;
    return vector3;
}

Vector2Int multiplyVectorsInt (Vector2Int vector1, Vector2Int vector2) {
    Vector2Int vector3;
    vector3.x = vector1.x * vector2.x;
    vector3.y = vector1.y * vector2.y;
    return vector3;
}

Vector2 multiplyVectors (Vector2 vector1, Vector2 vector2) {
    Vector2 vector3;
    vector3.x = vector1.x * vector2.x;
    vector3.y = vector1.y * vector2.y;
    return vector3;
}

int magnitudeVectorInt (Vector2Int vector) {
    return sqrt(vector.x*vector.x + vector.y*vector.y);
}

double magnitudeVector (Vector2 vector) {
    return sqrt(vector.x*vector.x + vector.y*vector.y);
}

Vector2Int normalizeVectorInt (Vector2Int vector) {
    Vector2Int vector2;
    vector2.x = vector.x/magnitudeVectorInt(vector);
    vector2.y = vector.y/magnitudeVectorInt(vector);
    return vector2;
}

Vector2 normalizeVector (Vector2 vector) {
    Vector2 vector2;
    vector2.x = vector.x/magnitudeVector(vector);
    vector2.y = vector.y/magnitudeVector(vector);
    return vector2;
}

Vector2Int scaleVectorInt (Vector2Int vector, int scalar) {
    Vector2Int vector2;
    vector2.x = vector.x*scalar;
    vector2.y = vector.y*scalar;
    return vector2;
}

Vector2 scaleVector (Vector2 vector, double scalar) {
    Vector2 vector2;
    vector2.x = vector.x*scalar;
    vector2.y = vector.y*scalar;
    return vector2;
}

Vector2Int divideVectorInt (Vector2Int vector, int scalar) {
    Vector2Int vector2;
    vector2.x = vector.x/scalar;
    vector2.y = vector.y/scalar;
    return vector2;
}

Vector2 divideVector (Vector2 vector, double scalar) {
    Vector2 vector2;
    vector2.x = vector.x/scalar;
    vector2.y = vector.y/scalar;
    return vector2;
}

#endif