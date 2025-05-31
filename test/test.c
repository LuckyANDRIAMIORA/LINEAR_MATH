#include "vector.h"
#include "stdio.h"

int main(){
    Vector *v = createVector(5);
    if (!v) {
        printf("Failed to create vector.\n");
        return 1;
    }
    set(v, 0, 3);
    int success;
    double value = get(v, 0,&success);
    if(success) printf("%f\n", value);
    printVector(v);
    destroyVector(v);
    return 0;
}