#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>


void changeU(mpz_t u, int r) {
  mpz_t temp;
  mpz_init(temp);

  mpz_mod_ui(temp, u, 10);
  int ld = mpz_get_ui(temp);

  if(r == 1) {
    /*while LSG(X) is not 1,5, 9  x = x+1 --> least significant digit*/
    if(ld > 1 && ld < 5) 
      mpz_add_ui(u, u, 5-ld);
    else if(ld > 5 && ld < 9) 
      mpz_add_ui(u, u, 9-ld);
    else if(ld == 0)
      mpz_add_ui(u, u, 1);
  } else if(r == 3) {
    /*while LSG(X) is not 2,8  x = x+1*/
    if(ld > 2 && ld < 8) 
      mpz_add_ui(u, u, 8-ld);
    else if(ld > 8)
      mpz_add_ui(u, u, 3);
    else if(ld < 2)
      mpz_add_ui(u, u, 2-ld);
  }else if(r == 7) {
    /*while LSG(X) is not 4,6  x = x+1*/
    if(ld > 4 && ld < 6) 
      mpz_add_ui(u, u, 6-ld);
    else if(ld > 6) 
      mpz_add_ui(u, u, 14-ld);
    else if(ld < 4)
      mpz_add_ui(u, u, 4-ld);
  }else if(r == 9) {
    /*while LSG(X) is not 3, 5, 7  x = x+1*/
    if(ld > 3 && ld < 5)
      mpz_add_ui(u, u, 5-ld);
    else if(ld > 5 && ld < 7) 
      mpz_add_ui(u, u, 7-ld);
    else if(ld > 7) 
      mpz_add_ui(u, u, 13-ld);
    
    else if(ld < 3)
      mpz_add_ui(u, u, 3-ld);
  }else if(r == 11) {
    /*while LSG(X) is not 0,4,6  x = x+1*/
    if(ld > 0 && ld < 4) 
      mpz_add_ui(u, u, 4-ld);
    else if(ld > 4 && ld < 6) 
      mpz_add_ui(u, u, 6-ld);
    else if(ld > 6)
      mpz_add_ui(u, u, 10-ld);

  }else if(r == 13) {
    /*while LSG(X) is not 3, 7  x = x+1*/
    if(ld > 3 && ld < 7)
      mpz_add_ui(u, u, 7-ld);
    else if(ld > 7) 
      mpz_add_ui(u, u, 13-ld);
    else if(ld < 3)
      mpz_add_ui(u, u, 3-ld);
  }else if(r == 17) {
    /*while LSG(X) is not 1, 9  x = x+1*/  
    if(ld > 1 && ld < 9) 
      mpz_add_ui(u, u, 9-ld);
    else if(ld < 0)
      mpz_add_ui(u, u, 1);
  }else if(r == 19) {
    /*while LSG(X) is not 0,2,8  x = x+1*/
    if(ld > 0 && ld < 2)
      mpz_add_ui(u, u, 2-ld);
    else if(ld > 2 && ld < 8) 
      mpz_add_ui(u, u, 8-ld);
    else if(ld > 8) 
      mpz_add_ui(u, u, 10-ld);
  }
  mpz_clear(temp);

}

int main (int argc, char *argv[])
{   
    struct timeval t1, t2;
    double elapsed;

    gettimeofday(&t1, NULL);
                   
    mpz_t entrada,raiz,resto,u,temp1,temp2,temp3;
    mpz_t r;
    int r_d;
    
    mpz_init(entrada); //Usan memoria dinamica hay que inicializar siempre
    mpz_init(raiz);
    mpz_init(resto);
    mpz_init(u);
    mpz_init(temp1);
    mpz_init(temp2);
    mpz_init(temp3);
    mpz_init(r);
    mpz_set_str(entrada,argv[1],10);

    //Factorizacion de Fermat
    mpz_sqrtrem(raiz,resto,entrada);
    if(mpz_cmp_ui(resto,0)!=0){ //Entero superior
        mpz_add_ui(u,raiz,1);
    }   
    
    mpz_mod_ui(r,entrada,20);
    r_d = mpz_get_d(r);
    changeU(u, r_d);

    /*sqrt(u^2 - n) */
    while(1==1){        
        mpz_mul(temp1,u,u); //Cuadrado
        mpz_sub(temp2,temp1,entrada); //Resto -n
        mpz_sqrtrem(temp1,temp3,temp2); // raiz
        if(mpz_cmp_ui(temp3,0)==0){ //raiz exacta
            break;
        }
        else{
            mpz_add_ui(u,u,1); //= u++
            changeU(u, r_d);
        }
    }

    mpz_add(temp3,u,temp1);
    mpz_sub(temp2,u,temp1);
    gmp_printf("[Num]: %Zd\nPrimo1 %Zd Primo2 %Zd\n\n",entrada,temp3,temp2);
    
    mpz_clear(entrada); //Hay que liberar la memoria siempre
    mpz_clear(raiz);
    mpz_clear(resto);
    mpz_clear(u);
    mpz_clear(temp1);
    mpz_clear(temp2);
    mpz_clear(temp3);
    
    gettimeofday(&t2, NULL);
    elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    printf("Tiempo de ejecucion: %f ms\n", elapsed);
  return 0;
}

