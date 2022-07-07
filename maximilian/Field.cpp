#include "Field.hpp"

int Field::xy2i(int x, int y) {
    if (x < -FIELD_RADIUS || x > FIELD_RADIUS) {
        cout << "out of x" << endl;
        return 0;
    }
    if (y < -FIELD_RADIUS || y > FIELD_RADIUS) {
        cout << "out of y" << endl;
        return 0;
    }

    return FIELD_SIZE * (x + FIELD_RADIUS) + (y + FIELD_RADIUS);
}

vector<int> Field::i2xy(int i) {
    if (i < 0 || i >= (FIELD_ARRAY_SIZE)) {
        cout << "out of i" << endl;
        return { 0, 0 };
    }

    return {
        (i / FIELD_SIZE) - FIELD_RADIUS ,
        (i % FIELD_SIZE) - FIELD_RADIUS };
}

Field::Field() : center({ 0, 0 }) {

}