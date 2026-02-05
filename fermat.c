#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <sys/time.h>
#include <time.h>

int main (int argc, char *argv[])
{   
    struct timeval t1, t2;
    double elapsed;

    gettimeofday(&t1, NULL);
                   
    mpz_t entrada,raiz,resto,nAlto,temp1,temp2,temp3;
    
    mpz_init(entrada); //Usan memoria dinamica hay que inicializar siempre
    mpz_init(raiz);
    mpz_init(resto);
    mpz_init(nAlto);
    mpz_init(temp1);
    mpz_init(temp2);
    mpz_init(temp3);
    mpz_set_str(entrada,argv[1],10);

    //Factorizacion de Fermat
    mpz_sqrtrem(raiz,resto,entrada);
    if(mpz_cmp_ui(resto,0)!=0){ //Entero superior
        mpz_add_ui(nAlto,raiz,1);
    }   

    while(1==1){        
        mpz_mul(temp1,nAlto,nAlto); //Cuadrado
        mpz_sub(temp2,temp1,entrada); //Resto -n
        mpz_sqrtrem(temp1,temp3,temp2); // raiz
        if(mpz_cmp_ui(temp3,0)==0){ //raiz exacta
            break;
        }
        else{
            mpz_add_ui(nAlto,nAlto,1); //= nAlto++
        }
    }

    mpz_add(temp3,nAlto,temp1);
    mpz_sub(temp2,nAlto,temp1);
    gmp_printf("[Num]: %Zd\nPrimo1 %Zd Primo2 %Zd\n\n",entrada,temp3,temp2);
    
    mpz_clear(entrada); //Hay que liberar la memoria siempre
    mpz_clear(raiz);
    mpz_clear(resto);
    mpz_clear(nAlto);
    mpz_clear(temp1);
    mpz_clear(temp2);
    mpz_clear(temp3);
    
    gettimeofday(&t2, NULL);
    elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    printf("Tiempo de ejecucion: %f ms\n", elapsed);
  return 0;
}