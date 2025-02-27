#include "myfunction.hpp"

int root(int x, int y) {
    int z = 0;
    while (power(z + 1, y) <= x) z++;
    return z;
}
