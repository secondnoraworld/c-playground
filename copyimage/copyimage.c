#include <stdio.h>

int main(void)
{
  FILE *fpr;
  FILE *fpw;
  char *fname_r = "logo.png";
  char *fname_w = "copy.png";
  unsigned char buf[1000000];
  int i, size;

  fpr = fopen( fname_r, "rb" );
  if( fpr == NULL ){
    printf( "読込用 %sファイルが開けません¥n", fname_r );
    return -1;
  }

  fpw = fopen( fname_w, "wb" );
  if( fpw == NULL ){
    printf( "書込用 %sファイルが開けません¥n", fname_w );
    return -1;
  }

  size = fread( buf, sizeof( unsigned char ), 1000000, fpr );
  fwrite( buf, sizeof( unsigned char ), size, fpw );

  fclose( fpr );
  fclose( fpw );

  printf( "%sファイルのコピーが終わりました¥n", fname_w );
  return 0;
}
