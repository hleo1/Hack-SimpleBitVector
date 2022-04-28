#include <iostream>
#include <assert.h>

class BitVector {
public :
    int* bv;
    int size;
    BitVector(int initial_size, int initial[]) {
        bv = new int[initial_size]{};
        size = initial_size;
        for(int i = 0; i < initial_size; i++) {
            assert(("must be 0 or 1", (initial[i] == 0 || initial[i] == 1)));
            bv[i] = initial[i];
        }
    }
    int getlength() const;
    int access(int ind);
    int rank(int num, int ind);
    int select(int num, int position);

    ~BitVector() {
        delete[] bv;
    }
};

int BitVector::getlength() const {
    return size;
}

int BitVector::access(int ind) {
    assert(("index must be within range!", (ind >= 0 && ind < size)));
    return bv[ind];
}

int BitVector::rank(int num, int ind) {
    assert(("index must be greater than 0", (ind >= 0)));
    //count number of 'num' that exists to the indices left of ind
    int count = 0;
    for(int curr = 0; (curr < ind && curr < size); curr++) {
        if (bv[curr] == num) {
            count++;
        }
    }
    return count;
}

int BitVector::select(int num, int position) {
    assert(("position must be greater than or equal to 0", (position >= 0)));

    int count = -1;
    for(int curr = 0; curr < size; curr++) {
        if(bv[curr] == num) {
            count++;
        }
        if(count == position) {
            return curr;
        }
    }
    return size - 1;
}



int main() {
    int test1[] {1, 0, 1};

    BitVector new_bv(sizeof(test1) / sizeof(test1[0]), test1);
//    std::cout << new_bv.rank(1, -1) << std::endl;
    std::cout << new_bv.select(0, 0) << std::endl;
    std::cout << new_bv.select(1, 2) << std::endl;


    return 0;
}
