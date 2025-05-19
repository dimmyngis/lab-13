#include <iostream>
#include <cmath>
using namespace std;

class Sphere {
private:
    double _radius;
    double _surfaceArea;
    double _volume;

    void setSurfaceArea();
    void setVolume();

public:
    Sphere(double r);

    void setRadius(double r);
    double getRadius() const;

    double getSurfaceArea() const;
    double getVolume() const;

    void getInfo() const;
};

Sphere::Sphere(double r) {
    if (r <= 0) {
        cout << "Error" << endl; // тк радиус должен быть положительным
        _radius = 1.0; // устанавливаю 1.0, так как радус неположительный
    }
    else {
        _radius = r;
    }
    setSurfaceArea();
    setVolume();
}

void Sphere::setSurfaceArea() {
    _surfaceArea = 4 * 3.14 * _radius * _radius;
}

void Sphere::setVolume() {
    _volume = (4.0 / 3.0) * 3.14 * _radius * _radius * _radius;
}

void Sphere::setRadius(double r) {
    if (r <= 0) {
        cout << "Error" << endl; // тк радиус должен быть положительным
        return; // не измен€ю радиус, если он некорректный
    }
    _radius = r;
    setSurfaceArea();
    setVolume();
}

double Sphere::getRadius() const {
    return _radius;
}

double Sphere::getSurfaceArea() const {
    return _surfaceArea;
}

double Sphere::getVolume() const {
    return _volume;
}

void Sphere::getInfo() const {
    std::cout << "Sphere with parameters:" << std::endl;
    std::cout << "Radius: " << _radius << std::endl;
    std::cout << "Surface Area: " << _surfaceArea << std::endl;
    std::cout << "Volume: " << _volume << std::endl;
}

int main() {
    Sphere mySphere(5.0);
    mySphere.getInfo();

    mySphere.setRadius(7.5);
    mySphere.getInfo();

    Sphere invalidSphere(-2.0);
    invalidSphere.getInfo();

    return 0;
}