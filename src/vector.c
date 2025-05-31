#include "vector.h"
#include "stdlib.h"
#include "stdio.h"

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

void set(Vector* v, int index, double value){
    if(!v || index < 0 || index >= v->dimension) return;
    v->data[index] = value;
}

double get(Vector* v, int index, int* success){
    if(!v || index < 0){
        if (success) *success = 0;
        return 0.0;
    };
    if(success) *success = 1;
    return v->data[index];
}

Vector* scale(Vector* v, double scalar){
    if(!v) return NULL;
    int dimension = v->dimension;
    for (int i = 0; i < dimension; i++)
    {
        v->data[i] = v->data[i] * scalar;
    }
    return v;
}

Vector* addition(Vector* v1, Vector* v2){
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

Vector* subtraction(Vector* v1, Vector* v2){
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
