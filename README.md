# calculPi
approximate pi value

## Requiere
  - gcc or a C++ compiler compatible openmp with good option
  - openmpi


## Compile
```
make
```

## launch with just openmp
```
./pi
```

## launch with mpi

Replace the value of `OMP_NUM_THREADS` by the number of cores on your processor.
Normally the option -x is optional 
```
export OMP_NUM_THREADS=4 
mpirun -H host1,host2,host3 -n 3 -x OMP_NUM_THREADS ./pi-mpi
```
