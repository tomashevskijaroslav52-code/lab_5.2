#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n);
double A(const double x, const int n, const double a);

int main()
{
    double x_p, x_k, dx, eps;

    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x"
        << " |" << setw(12) << "sin(x)/x"
        << " |" << setw(12) << "S"
        << " |" << setw(8) << "n" << " |" << endl;
    cout << "---------------------------------------------------" << endl;

    double x = x_p;
    while (x <= x_k)
    {
        int n = 0;
        double s = S(x, eps, n);


        double exact = sin(x) / x;

        cout << "|" << setw(10) << setprecision(2) << fixed << x
            << " |" << setw(12) << setprecision(5) << fixed << exact
            << " |" << setw(12) << setprecision(5) << fixed << s
            << " |" << setw(8) << n << " |" << endl;

        x += dx;
    }
    cout << "---------------------------------------------------" << endl;

    return 0;
}

double A(const double x, const int n, const double a)
{
    double R = -x * x / (2 * n * (2 * n + 1));
    return a * R;
}

double S(const double x, const double eps, int& n)
{
    double a = 1.0;
    double s = a;
    n = 0;

    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);

    return s;
}
