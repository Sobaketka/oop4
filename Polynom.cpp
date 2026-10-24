#include "Polynom.h"
using namespace std;

int Polynom::count = 0;
double Polynom::point = 2;


Polynom::Polynom() {
    n = 1;
    a = new double[n];
    a[0] = 0;
    count++;
    cout << "Default constructor" << endl;
}

Polynom::Polynom(int size) {
    n = size;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    count++;
    cout << "Size constructor" << endl;
}

Polynom::Polynom(const double* coefs, int size) {
    n = size;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        a[i] = coefs[i];
    }
    count++;
    cout << "Constructor of massive" << endl;
}

Polynom::Polynom(double x, double f) {
    n = 2;
    a = new double[n];
    a[0] = x;
    a[1] = f;
    count++;
    cout << "Constructor of odn" << endl;
}

Polynom::Polynom(const Polynom& other) {
    n = other.n;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        a[i] = other.a[i];
    }
    count++;
    cout << "Copy constructor" << endl;
}

Polynom::~Polynom() {
    delete[] a;
    count--;
    cout << "Destructor" << endl;
}

Polynom& Polynom::operator=(const Polynom& other) {
    cout << "Assignment operator" << endl;
    if (this != &other) {
        delete[] a;
        n = other.n;
        a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = other.a[i];
        }
    }
    return *this;
}

void Polynom::input() {
    cout << "Enter n: ";
    cin >> n;
    delete[] a;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "a" << i << " = ";
        cin >> a[i];
    }
}

void Polynom::output() const {
    cout << a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < 0) {
            cout << " - " << -a[i];
        } else {
            cout << " + " << a[i];
        }
        cout << "*x^" << i;
    }
    cout << endl;
}

int Polynom::getCount() {
    return count;
}

double Polynom::getPoint() {
    return point;
}

Polynom Polynom::copy() const {
    return Polynom(*this);
}

double Polynom::value() const {
    double sum = 0;
    double st = 1;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i] * st;
        st = st * point;
    }
    return sum;
}

Polynom Polynom::derivative() const {
    if (n == 1) {
        return Polynom(1);
    }
    Polynom d(n - 1);
    for (int i = 1; i < n; i++) {
        d.a[i - 1] = i * a[i];
    }
    return d;
}

Polynom Polynom::mulXminusB(double b) const {
    Polynom r(n + 1);
    for (int i = 0; i < n; i++) {
        r.a[i + 1] += a[i];
        r.a[i] -= b * a[i];
    }
    return r;
}

Polynom Polynom::shift(double b) const {
    Polynom r(a, n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 2; j >= i; j--) {
            r.a[j] += b * r.a[j + 1];
        }
    }

    return r;
}

Polynom compose(const Polynom& p, const Polynom& q) {
    Polynom res(1);
    for (int i = p.n - 1; i >= 0; i--) {
        Polynom t(res.n + q.n - 1);
        for (int j = 0; j < res.n; j++) {
            for (int k = 0; k < q.n; k++) {
                t.a[j + k] += res.a[j] * q.a[k];
            }
        }
        t.a[0] += p.a[i];
        res = t;
    }
    return res;
}

void divide(const Polynom& p, const Polynom& d, Polynom& q, Polynom& r) {
    r = p;
    q = Polynom(p.n - d.n + 1);
    for (int k = p.n - d.n; k >= 0; k--) {
        double c = r.a[k + d.n - 1] / d.a[d.n - 1];
        q.a[k] = c;
        for (int j = 0; j < d.n; j++) {
            r.a[k + j] -= c * d.a[j];
        }
    }
}

