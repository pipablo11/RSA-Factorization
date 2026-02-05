# RSA-Factorization
Suit de algoritmos de factorización del problema RSA. Dado un entero, sacar sus primos.

# Requisitos
Libreria GMP para manejar números grandes.
```bash
sudo apt-get install libgmp-dev
```

# Ejecución
Compilar el algoritmo con GMP y ejecutar. 
Ejemplo para Fermat:

```bash
gcc fermat.c -o fermat -lgmp
./fermat <f_num> 
```
# Listado de algoritmos
Los algoritmos atacan vulnerabilidades en el número generado. Son muy eficaces en casos específicos, en casos generales llegan a romper números de hasta 100bits en caso de Pollard Rho y Pollard P-1 y de 80bits en caso de Fermat. 

* __fermat.c__: Algoritmo de Fermat.
* __rho.c__: Algoritmo Pollard Rho.
* __p1poll__.c__: Algoritmo P-1 de Pollard.
* __FMmod20Precomp.c__: Optimización del algoritmo de Fermat. 