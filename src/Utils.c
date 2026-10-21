#include "Utils.h"
#include <stdlib.h>
#include <time.h>

int init = 0;

int get_random_number(int min, int max) {
    if (!init) {
        srand(time(NULL));
        init = 1;
    }
    return rand() % (max - min + 1) + min;
}