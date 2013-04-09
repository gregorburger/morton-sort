#include "morton.h"
#include <boost/random.hpp>
#include <thrust/sort.h>
#include <stdint.h>
#include <thrust/system/omp/memory.h>
#include <thrust/iterator/retag.h>

static boost::random::mt19937 rng(time(NULL));
static boost::random::uniform_real_distribution<> gen(0, 1.0);


void gen_random(std::vector<vector> &v) {


    for (size_t i = 0; i < v.size(); ++i) {
        vector tmp = {gen(rng), gen(rng)};
        v[i] = tmp;
    }
}

/*
def less_msb(x, y):
    return x < y and x < (x ^ y)
*/

bool less_msb(int x, int y) {
    return x < y && x < (x ^ y);
}

/*
def cmp_zorder(a, b):
    j = 0
    k = 0
    x = 0
    for k in range(dim):
        y = a[k] ^ b[k]
        if less_msb(x, y):
            j = k
            x = y
    return a[j] - b[j]
 */

bool cmp_zorder(const vector &v, const vector &vv) {
    int a[2] = {(int)(v.x * INT_MAX), (int)(v.y * INT_MAX)};
    int b[2] = {(int)(vv.x * INT_MAX), (int)(vv.y * INT_MAX)};

    int j = 0;
    int x = 0;

    for (int k = 0; k < 2; k++) {
        int y = a[k] ^ b[k];
        if (less_msb(x, y)) {
            j = k;
            x = y;
        }
    }
    return (a[j] - b[j]) < 0;
}

void morton_sort(std::vector<vector> &v) {
    thrust::sort(thrust::retag<thrust::omp::tag>(v.begin()),
                 thrust::retag<thrust::omp::tag>(v.end()),
                 cmp_zorder);
}


