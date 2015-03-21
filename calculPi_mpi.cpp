#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <mpi.h>

using namespace std;

int str2int(const char* str) {
    int value;

    istringstream(str) >> value;

    return value;
}

int main(int argc, char** argv) {

    cout.precision(15);

    int rank,numprocs;
    int n = 0;
    double gsum = 0.0;

    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    if (rank == 0) {
        if (argc == 2) {
            n = str2int(argv[1]);
        }
        else {
            cout << "number of slice : ";
            cin >> n;
        }
    }


    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    double lsum = 0.0;
    int startI = rank*n/numprocs;
    int finishI = (rank+1)*n/numprocs;

#pragma omp parallel for reduction(+:lsum) default(shared)
    for (int i = startI; i < finishI ; ++i) {
        double x = (double)i*(1.0/(double)n)+1.0/(double)n/2.0;
        lsum += 4.0/(1.0+x*x);
    }

    MPI_Reduce(&lsum, &gsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "pi = " << gsum/n << endl;
    }

    MPI_Finalize();

    return 0;
}

