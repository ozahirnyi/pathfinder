#include "pathfinder.h"

result_struct *mx_create_struct(void) {
    result_struct *pointer = (result_struct *)malloc(sizeof(result_struct));

    pointer->path = NULL;
    pointer->islands = NULL;
    return pointer;
}
