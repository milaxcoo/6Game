#include <iostream>

class Point2D {
private:
    int x;
    int y;
public:

    // Конструктор
    Point2D(int x = 0, int y = 0) : x(x), y(y) {  }

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }
    int getY() { return y; }

    bool operator==(const Point2D& point) {
        return x == point.x && y == point.y;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }

    friend class Arena1;
    friend class Characters1;
    friend class Prey;
    friend class Predator;
  
    
};