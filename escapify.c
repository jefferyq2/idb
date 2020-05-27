#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  char c='\0';
  int i=0;
  int j=1;
/*  if(argc >= 2)*/
  if(argc < 2)
  {
    fprintf(stderr,"Error: Exactly one argument should be given: a string to shell-escape.\n");
    exit(1);
  }
  while(j<argc)
  {
    while(i<strlen(argv[j]))
    {
      c=argv[j][i];
      /* this switch has no breaks on purpose. */
      switch(c)
      {
      case ';':
      case '\'':
      case ' ':
      case '!':
      case '"':
      case '#':
      case '$':
      case '&':
      case '(':
      case ')':
      case '|':
      case '*':
      case ',':
      case '<':
      case '>':
      case '[':
      case ']':
      case '\\':
      case '^':
      case '`':
      case '{':
      case '}':
        putchar('\\');
      default:
        putchar(c);
      }
      i++;
    }
    putchar(' ');
    j++;
    i=0;
  }
  /* newline at end */
  putchar ('\n');
  return 0;
}
