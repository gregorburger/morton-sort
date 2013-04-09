#ifndef MORTON_H
#define MORTON_H

#include <vector>
struct vector {
    double x, y;
};

void morton_sort(std::vector<vector> &v);
void gen_random(std::vector<vector> &v);

#endif // MORTON_H
