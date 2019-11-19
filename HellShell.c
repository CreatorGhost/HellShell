#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#define Size 255
#define MAXARGS 63
#define Quit "quit"
#define Clear "clr"
#define Envr "environ"
#define Help "help"
int main(void) {

printf("............Welcome To Shell Of the Hell..............\n");

for (;;) {
  char input[Size];
  char *ptr = input;
  char *args[MAXARGS + 1] = { NULL };
  printf("global@Hell > ");

  fgets(input, Size, stdin);

  for (int i = 0; i < sizeof(args) && *ptr; ptr++) {
         if (*ptr == ' ') continue;
         if (*ptr == '\n') break;
         for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
         *ptr = '\0';

     }
  if (strcmp(Quit, args[0]) == 0)
  {return 0;

  }
  if (strcmp(Clear, args[0]) == 0)
  {args[0]="clear";

  }
  if (strcmp(Envr, args[0]) == 0)
  {args[0]="env";

  }
  if (strcmp(Help, args[0]) == 0)
  {printf("cd - change directory\n clr - clear the screen \ndir - list the directory\nenviron - list enviroment variable \n" );

  }
  if (fork() == 0) exit(execvp(args[0], args));

  wait(NULL);
}
}
