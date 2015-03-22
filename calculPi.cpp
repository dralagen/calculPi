#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    cout.precision(15);

    unsigned long long int n = 0;
    if (argc == 2) {
        n = std::stoll(argv[1]);
    }
    else {
        cout << "number of slice : ";
        cin >> n;
    }

    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (unsigned long long int i = 0; i < n ; ++i) {
        double x = (double)i*(1.0/(double)n)+1.0/(double)n/2.0;
        sum += 4.0/(1.0+x*x);
    }

    cout << "pi = " << sum/n << endl;

    return 0;
}

