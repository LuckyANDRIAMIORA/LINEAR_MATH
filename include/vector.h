#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int dimension;
    double * data;
} Vector;

Vector* createVector(int dimension);
void destroyVector();
void printVector(Vector* v);
void set(Vector* v, int index, double value);
double get(Vector* v, int index, int* success);
Vector* scalarMultiplication(Vector* v, double scalar);
Vector* addition(Vector* v1, Vector* v2);
Vector* subtraction(Vector* v1, Vector* v2);

#endif