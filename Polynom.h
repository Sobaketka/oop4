#ifndef OOP4_POLYNOM_H
#define OOP4_POLYNOM_H

#include <iostream>

class Polynom {
private:
    int n;
    double* a;
    static int count;
    static double point;

public:
    Polynom();
    Polynom(double x, double f);
    Polynom(int size);
    Polynom(const double* coefs, int size);
    Polynom(const Polynom& p);
    ~Polynom();
    Polynom& operator=(const Polynom& p);
    void input();
    void output() const;

    static int getCount();
    static double getPoint();
    Polynom copy() const;
    double value() const;
    Polynom derivative() const;
    Polynom mulXminusB(double b) const;
    Polynom shift(double b) const;

    friend Polynom compose(const Polynom& p, const Polynom& q);
    friend void divide(const Polynom& p, const Polynom& d, Polynom& q, Polynom& r);
};

#endif