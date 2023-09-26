/* ND4 */
#include "TXT.h"
#include <ctype.h>

void GetStr( char *Str, int MaxLen )
{
  int i = 0;
  char ch;

  while ((ch = getchar()) != '\n')
    if (Str != NULL && i < MaxLen - 1)
      Str[i++] = ch;
  if (Str != NULL && i < MaxLen)
    Str[i] = 0;
}                       
void GetLetCnt( char *txt, int *cnt )
{
  int c;
 
  for (c = 0; txt[c] != 0; c++)
  {
    if (txt[c] >= 'A' && txt[c] <= 'Z')
      cnt[txt[c] - 'A']++;
    if (txt[c] >= 'a' && txt[c] <= 'z')
      cnt[txt[c] - 'a']++;
  }
}                        

char * LoadTxt( char *fn )
{
  FILE *F;
  int c, cnt = 0;
  char *txt = NULL;
  
  F = fopen(fn, "r");

  if (F != NULL)                                
  {
    while ((c = fgetc(F)) != EOF)
      cnt++;
    if ((txt = malloc(cnt + 1)) != NULL)
    {
      rewind(F);
      cnt = 0;
      while ((c = fgetc(F)) != EOF)
        txt[cnt++] = c;
      txt[cnt] = 0;
    }
    fclose(F);
  }
  return txt;
}
                          
int WordCounter( char *S, int (*f)( char *S, int B, int E ) )
{
  int res = 0, b, e, i = 0;
  while (S[i] != 0)
  {
    while (!isspace((unsigned char)S[i]))
      i++;
    if (S[i] != 0)
    {
      b = i;
      while (isspace((unsigned char)S[i]) && S[i] != 0)
        i++;
    }
    e = i - 1;
    res += f(S, b, e);
  }
  return res;
}                           

int WordCounterFunc( char *S, int B, int E )
{
  return 1;
}

int WordSymCounterFunc( char *S, int b, int e )
{
  while (b < e)
    if (S[b++] != S[e--])
      return 0;
  return 1;
}