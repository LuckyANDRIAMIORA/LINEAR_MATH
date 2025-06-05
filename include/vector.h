#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int dimension;
    double * data;
} Vector;

Vector* createVector(int dimension);
void destroyVector();
void printVector(Vector* v);
void setVectorElement(Vector* v, int index, double value);
double getVectorElement(Vector* v, int index, int* success);
Vector* scalarMultiplication(Vector* v, double scalar);
Vector* vectorAddition(Vector* v1, Vector* v2);
Vector* vectorSubtraction(Vector* v1, Vector* v2);
double magnitude(Vector* v, int* success);
void normalize(Vector* v);
double dotProduct(Vector* v1, Vector* v2, int* success);
Vector* crossProduct(Vector* v1, Vector* v2);

#endif