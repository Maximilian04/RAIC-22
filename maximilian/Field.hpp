#include <vector>
#include <iostream>

#include "model/Vec2.hpp"

using namespace std;

#define FIELD_RADIUS ((int)(60))
#define FIELD_SIZE (2*FIELD_RADIUS + 1)
#define FIELD_ARRAY_SIZE (FIELD_SIZE * FIELD_SIZE)

class Field {
public:
    static int xy2i(int x, int y);
    static vector<int> i2xy(int i);

    Field();
private:
    int points[FIELD_ARRAY_SIZE];
    vector<int> center;
};
