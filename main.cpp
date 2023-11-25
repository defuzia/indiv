#include <iostream>

class Vector {
private:
    int startX, startY; // координати початку вектора
    int endX, endY;     // координати кінця вектора

public:
    Vector(int startX, int startY, int endX, int endY) :
        startX(startX), startY(startY), endX(endX), endY(endY) {
    }

    void displayVector() {
        std::cout << "Vector: (" << startX << ", " << startY << ") -> (" << endX << ", " << endY << ")\n";
    }

    void getCoordinates(int &x, int &y) const {
        x = endX - startX;
        y = endY - startY;
    }

    bool isEqual(const Vector &other) const {
        return startX == other.startX && startY == other.startY && endX == other.endX && endY == other.endY;
    }

    Vector add(const Vector &other) const {
        return Vector(startX + other.startX, startY + other.startY, endX + other.endX, endY + other.endY);
    }

    int dotProduct(const Vector &other) const {
        int x1, y1, x2, y2;
        getCoordinates(x1, y1);
        other.getCoordinates(x2, y2);

        return x1 * x2 + y1 * y2;
    }
};

int main() {
    Vector v1(0, 0, 3, 4);
    Vector v2(1, 1, 4, 5);

    v1.displayVector();
    v2.displayVector();

    int x, y;
    v1.getCoordinates(x, y);
    std::cout << "Координати вектора v1: (" << x << ", " << y << ")\n";

    if (v1.isEqual(v2)) {
        std::cout << "Вектори одинакові.\n";
    } else {
        std::cout << "Вектори різні.\n";
    }

    Vector v3 = v1.add(v2);
    v3.displayVector();
    std::cout << "Векторний добуток: " << v1.dotProduct(v2) << "\n";

    return 0;
}
