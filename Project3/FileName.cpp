#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}
double f_proizv(double x) {
    double term1 = -1 / sqrt(1 - x * x);
    double term2 = -0.45 * pow(x, 2) / (2 * sqrt(1 - 0.3 * pow(x, 3)));
    return term1 + term2;
}
double g(double x) {
    return cos(sqrt(1-0.3*x*x*x));
}
double newton_method(double tol = 1e-6, int max_iter = 100) {
    double x = 0.99;
    for (int i = 0; i < max_iter; ++i) {
        double fx = f(x);
        double fpr = f_proizv(x);
        double x_next = x - fx / fpr;
        
        if (fabs(x_next - x) < tol) {
            return x_next;
        }
        else {
            cout << "итерация " << i << ": x = " << x_next<<endl;
        }
        x = x_next;
    }
}

double iteration_method(double tol = 1e-6, int max_iter = 100) {
    double x = 0;
    for (int i = 0; i < max_iter; ++i) {
        double x_next = g(x);
        if (fabs(x_next - x) < tol) {
            return x_next;
        }
        else {
            cout << "итерация " << i << ": x = " << x_next << endl;
        }

        x = x_next;
    }
}

int main() {
    double root_newton = newton_method();
    cout << "Корень уравнения методом Ньютона: " << root_newton << endl;
    double root_iteration = iteration_method();
    cout << "Корень уравнения методом итераций: " << root_iteration << endl;
    system("pause");
    return 0;
}