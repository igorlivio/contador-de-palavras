/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

/*  --- fazer depois essa merda olhar aqui: (https://stackoverflow.com/questions/1921539/using-boolean-values-in-c)
typedef int boolean;
#define true 1
#define false 0
*/

int main() {

  char c , boolean , boolean2;
  int i , j , i_palavras , operador;
  int frase[1000];
  int binfrase[1000];
  int seq_palavras[1000];
 
  c = 1;
  i = 0;
  j = 0;
  boolean = 0;
  boolean2 = 0;
  i_palavras = -1;

//substituir todos estes if por case

  while (c != '\n') {
    scanf("%c", &c);
    if ( c == 10) break ;
    frase[i] = c;
    i++;}
/*

    if ( c == 32 ) binfrase[i] = 1; // 1 - nao compoe palavra; 0 - compoe palvra 
    else if ( !c ) binfrase[i] = 1;
    else if ( c == 10 ) boolean = 1;
    //pontuacao
    // tabela ASCII: dec 33 a 47 somente pontuacao; dec 48 a 57 números
    
    daqui até dragões
    else if ( ( c >= 48 ) && ( c <= 57) ){
       binfrase[i] = 0;
       boolean2 = 1; 
     }
    else if ( ( c >= 33 ) && ( c <= 48)) {
       if ( (boolean2 == 1) ){
         binfrase[i] = 0;
         boolean2 = 0;
       }

       else binfrase[i] = 1;   
    }
   / //dragões
    else binfrase[i] = 0;

    if (!boolean) i++;
  } */

    
    for( j=0 ; j<=i ; j++){

    if ( frase[j] == 32 ) binfrase[j] = 1; // 1 - nao compoe palavra; 0 - compoe palvra
    else if ( frase[j] == 1 ) binfrase[j] = 1; 
    else if ( !frase[j] ) binfrase[j] = 1;
    //pontuacao
    // tabela ASCII: dec 33 a 47 somente pontuacao; dec 48 a 57 números
    
    
    else if ( ( frase[j] >= 48 ) && ( frase[j] <= 57) ){
       binfrase[j] = 0;
       boolean2 = 1; 
     }
    else if ( ( frase[j] >= 33 ) && ( frase[j] <= 47)) {
       
        
        if (boolean2 == 1) {
        // terminar depois  condicao para segundo ponto o qual não define o numero. Ex: 3.14.A casa branca
         binfrase[j] = 0;
         boolean2 = 0;
       }
       else binfrase[j] = 1;   
    }
    else binfrase[j] = 0;
    }

/* somente para dubugging
for( j=0 ; j<=i ; j++){
printf("caractere: %i  bin: %i\n" , frase[j] , binfrase[j]);  
}
*/
    seq_palavras[0] = 0; 
    boolean = 0;  
    
    for( j = 0 ; j <= i ; j++){
      operador = binfrase[j] * 1;
      if( operador == 0){
        if ( boolean == 0 ){
         i_palavras ++; // dominio index letras: 0->n sendo n + 1 = numero total de palavras, o qual é um vetor contendo cada indice o número de letras de cada palavra 
        seq_palavras[i_palavras] =  seq_palavras[i_palavras] + 1 ;
        // index não é acrescido por conta do "ponteiro" no meio da palavra
        }
        else seq_palavras[i_palavras] = seq_palavras[i_palavras] + 1; 
        boolean = 1;
      } 
      else boolean = 0;
         
    }
   
  printf( "%i\n" , (i_palavras + 1) );
  return 0;
}
