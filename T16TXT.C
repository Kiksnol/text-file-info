/* ND4 */
#include "TXT.h"

void main( void )
{
  char *txt, fn[200];
  int counts[26] = {0}, c;

  printf("Input file name: ");
  GetStr(fn, sizeof(fn)); 

  if ((txt = LoadTxt(fn)) == NULL)
  {
    printf("FILE HAS BEEN NOT FOUND"), getchar();
    return;
  }
  GetLetCnt(txt, counts);
  for (c = 0; c < 26; c++)
    if (counts[c] != 0)                                
      printf("%c occured %d time(s)\n", c + 'A', counts[c]);
  printf("Amount of words: %d\n", WordCounter(txt, WordCounterFunc));
  printf("Amount of pali words: %d\n", WordCounter(txt, WordSymCounterFunc));
  free(txt);
  getchar();
}