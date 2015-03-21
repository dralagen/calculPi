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
```
mpirun -H host1,host2,host3 -n 3 ./pi-mpi
```
