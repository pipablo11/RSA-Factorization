#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <sys/time.h>
#include <time.h>


int main(int argc, char *argv[])
{
  struct timeval t1, t2;
  double elapsed;
  

  gettimeofday(&t1, NULL);
  mpz_t num, t, h, diff, gcd;
  long long int k = 2;
  mpz_init(num);
  mpz_init(t);
  mpz_init(h);
  mpz_init(diff);
  mpz_init(gcd);

  mpz_set_str(num, argv[1], 10);
  mpz_set_str(t, "2", 10);
  mpz_gcd(gcd, num, t);
  if(mpz_cmp_ui(gcd, 1) > 0)
  {
    gmp_printf("Num: %Zd\nPrimo1 %Zd \n",num, gcd);
    return 0;
  }

  while(1)
  {
    /*t = t^k mod n*/
    mpz_powm_ui(t, t, k, num);

    /*gcd = mcd(t - 1, n)*/
    mpz_sub_ui(diff, t, 1);
    mpz_gcd(gcd, diff, num);

    if(mpz_cmp_ui(gcd, 1) > 0)
    {
      gmp_printf("Num: %Zd\nPrimo1 %Zd \n",num, gcd);
      break;
    } 
    k++;
  }
  
  mpz_clear(num);
  mpz_clear(h);
  mpz_clear(t);
  gettimeofday(&t2, NULL);
  elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  printf("Tiempo de ejecucion: %f ms\n", elapsed);

  return 0;
}