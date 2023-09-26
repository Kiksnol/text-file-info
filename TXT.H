/* ND4 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetStr( char *Str, int MaxLen );
char * LoadTxt( char *fn );
void GetLetCnt( char *txt, int *cnt );
int WordCounter( char *S, int (*f)( char *S, int B, int E ) );
int WordCounterFunc( char *S, int B, int E );
int WordSymCounterFunc( char *S, int b, int e );