#include "ft_printf.h"

int main(void)
{
  char c = '9';
  char *str = "LEZZZ GOOO wuuu";
  int d = 420;
  int main_counter = 0;
 //funciona mas dá warning apenas pq n se deve meter null
  //printf("\n### (null) ###\n");
  //main_counter = printf("%s, ", NULL);
  //printf("%d\n", main_counter);
  //main_counter = ft_printf("%s, ", NULL);
  //printf("%d", main_counter);

  printf("\n\n### Sem %% ###\n");
  main_counter = printf("REAL: Welele, ");
  printf("%d\n", main_counter );
  main_counter = ft_printf("MEU:  Welele, ");
  ft_printf("%d", main_counter );

  printf("\n\n### %%%% ###\n");

    main_counter  = printf("REAL: %% %%%% %%%%%%, ");
  printf("%d\n", main_counter );
  main_counter = ft_printf("MEU:  %% %%%% %%%%%%, ");
  ft_printf("%d", main_counter );
  
  printf("\n\n### %%c ###\n");
  main_counter  = printf("REAL: %c, ", c);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %c, ", c);
  printf("%d\n", main_counter );

  printf("\n\n### %%d ###\n");
  main_counter  = printf("REAL: %d, ", d);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %d, ", d);
  printf("%d\n", main_counter );

  printf("\n\n### %%i ###\n");
  main_counter  = printf("REAL: %i, ", d);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %i, ", d);
  printf("%d\n", main_counter );

  printf("\n\n### %%s ###\n");
  main_counter  = printf("REAL: %s, ", str);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %s, ", str);
  printf("%d\n", main_counter );

  printf("\n\n### %%p ###\n");
  main_counter  = printf("REAL: %p, ", &d);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %p, ", &d);
  printf("%d\n", main_counter );

  printf("\n\n### %%u ###\n");
  main_counter = printf("REAL: %u, ", d);
  printf("%d\n", main_counter );
  main_counter = ft_printf("MEU:  %u, ", d);
  printf("%d\n", main_counter );
  
  printf("\n\n### %%x ###\n");
  ft_printf("\n%x\n", 16);
  main_counter = printf("REAL: %x, ", d);
  printf("%d\n", main_counter);
  main_counter = ft_printf("MEU:  %x, ", d);
  printf("%d\n", main_counter);

  printf("\n\n### %%X ###\n");
  main_counter = printf("REAL: %X, ", d);
  printf("%d\n", main_counter);
  main_counter = ft_printf("MEU:  %X, ", d);
  printf("%d\n", main_counter);

  printf("\n\n### Todos ###\n");
  main_counter = printf("REAL: %c %d %i %s %p %u %x %X", c, d, d, str, &str, d, d, d);
  printf("\ncounter: %d\n", main_counter);
  main_counter = ft_printf("MEU:  %c %d %i %s %p %u %x %X", c, d, d, str, &str, d, d, d);
  printf("\ncounter: %d\n", main_counter);

}
