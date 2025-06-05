#include "vector.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

Vector* createVector(int size){
    if (size <= 0) return NULL;
    Vector* v = malloc(sizeof(Vector));
    if(!v) return NULL;
    double* data = calloc(size , sizeof(double));
    v->dimension = size;
    v->data = data;
    if(!v->data){
        free(v);
        return NULL;
    } 
    return v;
}

void destroyVector(Vector* v){
    if(!v) return;
    free(v->data);
    free(v);
}

void printVector(Vector* v){
    if(!v) printf("NULL vector\n");
    printf("[");
    int dimension = v->dimension;
    for (int i = 0; i < dimension; i++)
    {
        printf("%f",v->data[i]);
        if(!(i==v->dimension-1)){
            printf(", ");
        }
    }
    printf("]\n");
}

void setVectorElement(Vector* v, int index, double value){
    if(!v || index < 0 || index >= v->dimension) return;
    v->data[index] = value;
}

double getVectorElement(Vector* v, int index, int* success){
    if(!v || index < 0){
        if (success) *success = 0;
        return 0.0;
    };
    if(success) *success = 1;
    return v->data[index];
}

Vector* scalarMultiplication(Vector* v, double scalar){
    if(!v) return NULL;
    int dimension = v->dimension;
    Vector* newV = createVector(dimension);
    if (!newV) return NULL;
    for (int i = 0; i < dimension; i++)
    {
        newV->data[i] = v->data[i] * scalar;
    }
    return newV;
}

Vector* vectorAddition(Vector* v1, Vector* v2){
    if(!v1 || !v2 || v1->dimension != v2->dimension) return NULL;
    Vector* result = createVector(v1->dimension);
    if(!result) return NULL;
    int dimension = result->dimension;
    for (int i = 0; i < dimension; i++)
    {
        result->data[i] = v1->data[i] + v2->data[i];
    }
    return result;
}

Vector* vectorSubtraction(Vector* v1, Vector* v2){
    if(!v1 || !v2 || v1->dimension != v2->dimension) return NULL;
    Vector* result = createVector(v1->dimension);
    if(!result) return NULL;
    int dimension = result->dimension;
    for (int i = 0; i < dimension; i++)
    {
        result->data[i] = v1->data[i] - v2->data[i];
    }
    return result;
}

double magnitude(Vector* v, int* success){
    if (!v){
        if(success) *success = 0;
        return 0.0;
    }
    double sum = 0.0;
    int dimension = v->dimension;
    for (int i = 0; i < dimension; i++)
    {
        sum += v->data[i] * v->data[i];
    }
    if(success) *success = 1;
    return sqrt(sum);
}

void normalize(Vector* v){
    if(!v) return;
    int success;
    double magnitudeValue = magnitude(v, &success);
    if(!success) return;
    int dimension = v->dimension;
    for (int i = 0; i < dimension; i++)
    {
        v->data[i] = v->data[i] / magnitudeValue;
    }
}

double dotProduct(Vector* v1, Vector* v2, int* success){
    if(!v1 || !v2 || v1->dimension != v2->dimension){
        if(success) *success = 0;
        return 0.0;
    }
    int dimension = v1->dimension;
    double value = 0.0;
    for (int i = 0; i < dimension; i++)
    {
        value += (v1->data[i] * v2->data[i]);
    }

    if (success) *success = 1;
    return value;
}

Vector* crossProduct(Vector* v1, Vector* v2){
    if(!v1 || !v2 || v1->dimension != 3 || v2->dimension != 3){
        return NULL;
    }
    Vector* v3 = createVector(3);
    if(!v3) return NULL;

    v3->data[0] = v1->data[1] * v2->data[2] - v1->data[2] * v2->data[1];
    v3->data[1] = v1->data[2] * v2->data[0] - v1->data[0] * v2->data[2];
    v3->data[2] = v1->data[0] * v2->data[1] - v1->data[1] * v2->data[0];

    return v3;
}