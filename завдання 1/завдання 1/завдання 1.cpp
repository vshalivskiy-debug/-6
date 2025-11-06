#include <iostream>
#include <windows.h>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    void input() {
        cout << "Введіть координати точки (x y): ";
        cin >> x >> y;
    }

    void output() const {
        cout << "(" << x << ", " << y << ")";
    }

    int quadrant() const {
        if (x > 0 && y > 0) return 1;
        if (x < 0 && y > 0) return 2;
        if (x < 0 && y < 0) return 3;
        if (x > 0 && y < 0) return 4;
        return 0; // на осях
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
};

int main() {
    // Установка українського кодування для Windows-консолі
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "=== Демонстрація роботи з класом Точка ===\n\n";

    Point A, B;
    cout << "Введення першої точки:\n";
    A.input();

    cout << "Введення другої точки:\n";
    B.input();

    cout << "\n--- Введені точки ---\n";
    cout << "A = "; A.output(); cout << endl;
    cout << "B = "; B.output(); cout << endl;

    cout << "\n--- Квадранти ---\n";
    cout << "A знаходиться у ";
    switch (A.quadrant()) {
    case 1: cout << "I чверті"; break;
    case 2: cout << "II чверті"; break;
    case 3: cout << "III чверті"; break;
    case 4: cout << "IV чверті"; break;
    default: cout << "на осях координат"; break;
    }
    cout << endl;

    cout << "B знаходиться у ";
    switch (B.quadrant()) {
    case 1: cout << "I чверті"; break;
    case 2: cout << "II чверті"; break;
    case 3: cout << "III чверті"; break;
    case 4: cout << "IV чверті"; break;
    default: cout << "на осях координат"; break;
    }
    cout << endl;

    Point sum = A + B;
    Point diff = A - B;

    cout << "\n--- Операції з точками ---\n";
    cout << "A + B = "; sum.output(); cout << endl;
    cout << "A - B = "; diff.output(); cout << endl;

    cout << "\n=== Кінець роботи програми ===\n";

    return 0;
}