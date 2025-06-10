#include "vector.h"
#include "stdio.h"

int main() {
    Vector *v = createVector(3);
    if (!v) {
        printf("Failed to create vector.\n");
        return 1;
    }

    int success = 0;
    setVectorElement(v, 0, 2);
    setVectorElement(v, 1, 3);
    setVectorElement(v, 2, 5);

    double value = getVectorElement(v, 0, &success);
    if (success) {
        printf("Value at index 0: %f\n", value);
    } else {
        printf("Failed to get value at index 0.\n");
    }

    Vector* v2 = scalarMultiplication(v, 2);
    if (!v2) {
        printf("Scalar multiplication failed.\n");
        destroyVector(v);
        return 1;
    }

    Vector* v3 = vectorAddition(v, v2);
    if (!v3) {
        printf("vector addition failed.\n");
        destroyVector(v);
        destroyVector(v2);
        return 1;
    }

    Vector* v4 = vectorSubtraction(v3, v2);
    if (!v4) {
        printf("vector subtraction failed.\n");
        destroyVector(v);
        destroyVector(v2);
        destroyVector(v3);
        return 1;
    }

    double magnitudeValue = magnitude(v4, &success);
    if(!success){
        destroyVector(v);
        destroyVector(v2);
        destroyVector(v3);
        destroyVector(v4);
        return 1;
    }

    double dotProductValue = dotProduct(v3,v2,&success);
    if(!success){
        destroyVector(v);
        destroyVector(v2);
        destroyVector(v3);
        destroyVector(v4);
        return 1;
    }

    setVectorElement(v3, 0, 8);
    setVectorElement(v3, 0, 10);
    setVectorElement(v3, 0, 5);

    Vector* v5 = crossProduct(v3, v4);
    if(!v5){
        destroyVector(v);
        destroyVector(v2);
        destroyVector(v3);
        destroyVector(v4);
        return 1;
    }

    Vector* v6 = copyVector(*v3);
    if(!v6){
        destroyVector(v);
        destroyVector(v2);
        destroyVector(v3);
        destroyVector(v4);
        destroyVector(v5);
        return 1;
    }

    Vector* v7 = projectVector(v6, v5);
    if(!v7){
        destroyVector(v);
        destroyVector(v2);
        destroyVector(v3);
        destroyVector(v4);
        destroyVector(v5);
        destroyVector(v6);
        return 1;
    }

    printf("Original vector v:\n");
    printVector(v);

    printf("Scaled vector v2:\n");
    printVector(v2);

    printf("Vector addition of v and v2 result v3:\n");
    printVector(v3);

    printf("Vector subtraction of v3 and v2 result v4:\n");
    printVector(v4);

    printf("Magnitute of v4:\n");
    printf("%f\n", magnitudeValue);

    normalize(v4);

    printf("Normalized vector result v4:\n");
    printVector(v4);

    printf("dot product of v3 and v2:\n");
    printf("%f\n", dotProductValue);

    printf("v3 new value:\n");
    printVector(v3);
    printf("copy of v3 value v6:\n");
    printVector(v6);

    printf("Cross product of v3 and v4 vector result v5:\n");
    printVector(v5);

    printf("projection of v6 to v5 vector result v7:\n");
    printVector(v7);

    destroyVector(v);
    destroyVector(v2);  
    destroyVector(v3);
    destroyVector(v4);
    destroyVector(v5);
    destroyVector(v6);
    destroyVector(v7);
    return 0;
}
