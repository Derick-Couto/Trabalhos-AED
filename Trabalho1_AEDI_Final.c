/*
===============================================================================
Você recebe dois arrays de strings que representam dois eventos que aconteceram no mesmo dia, evento1 e
                                                                                            evento2, onde:
 evento1 = [começo1, fim1] e evento2 = [começo2, fim2].
Os horários dos eventos são válidos no formato de 24 horas no formato HH:MM.
Um conflito ocorre quando dois eventos têm alguma interseção não vazia (ou seja, algum momento é comum
                                                                                    a ambos os eventos).
Faça a função que retorna verdadeiro se houver um conflito entre dois eventos. Caso contrário, retorne falso.
                bool haveConflict(char ** evento1, int evento1Tamanho, char ** evento2, int evento2Tamanho)
Restrições:
 evento1Tamanho == evento2Tamanho == 2.
 strlen(evento1[i]) == strlen(evento2[i]) == 5
 começo1 <= fim1
 começo2 <= fim2
 Todos os horários dos eventos seguem o formato HH:MM
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool _Bool
#define true 1;
#define false 0;


int comeco1 [ 5 ], fim1 [ 5 ], comeco2 [ 5 ], fim2 [ 5 ];
int tempmin1 = -1, tempmin2 = -1, tempmin3 = -1,tempmin4 = -1, tempcomeco;
int *c1 = &comeco1 [ 0 ], *f1 = &fim1 [ 0 ], *c2 = &comeco2 [ 0 ], *f2 = &fim2 [ 0 ];
int **evento1 [ 2 ] = { &c1, &f1 },**evento2 [ 2 ] = { &c2, &f2 };
bool haveconflict();


bool haveConflict()
{

tempmin1 = c1 [ 4 ] + c1 [ 3 ] * 10 + c1 [ 1 ] * 60 + c1 [ 0 ] * 600;
tempmin2 = f1 [ 4 ] + f1 [ 3 ] * 10 + f1 [ 1 ] * 60 + f1 [ 0 ] * 600;
tempmin3 = c2 [ 4 ] + c2 [ 3 ] * 10 + c2 [ 1 ] * 60 + c2 [ 0 ] * 600;
tempmin4 = f2 [ 4 ] + f2 [ 3 ] * 10 + f2 [ 1 ] * 60 + f2 [ 0 ] * 600;

if ( tempmin1 == tempmin3 ) 
{
    printf ( "Verdadeiro" );
    printf ( "Os dois eventos se cruzam no horario %d%d:%d%d", c1 [ 0 ], c1 [ 1 ], c1 [ 3 ], c1 [ 4 ] );
    return true;

} else

if ( tempmin2 == tempmin3 )
{
    printf ( "Verdadeiro" );
    printf ( "Os dois eventos se cruzam no horario %d%d:%d%d", f1 [ 0 ],f1 [ 1 ], f1 [ 3 ], f1 [ 4 ]);
    return true;

} else
if ( tempmin2 == tempmin4 ) 
{
    printf ( "Verdadeiro" );
    printf ( "Os dois eventos se cruzam no horario %d%d:%d%d", f1 [ 0 ], f1 [ 1 ], f1 [ 3 ], f1 [ 4 ]);
    return true;

} else
if ( tempmin2 > tempmin3 ) 
{
    printf ( "Verdadeiro" );
    printf ( "Os dois eventos se cruzam de %d%d:%d%d até %d%d:%d%d", f1 [ 0 ], f1 [ 1 ], f1 [ 3 ],f1 [ 4 ],
                                                                     c2 [ 0 ], c2[ 1 ], c2 [ 3 ],
                                                                     c2[4]);
    return true;

} else
if ( tempmin2 > tempmin4 )
{
    printf ( "Verdadeiro" );
    printf ( "Os dois eventos se cruzam de %d%d:%d%d até %d%d:%d%d", f1 [ 0 ], f1 [ 1 ], f1 [ 3 ], f1 [ 4 ],
                                                                    f2 [ 0 ], f2 [ 1 ], f2 [ 3 ], f2 [ 4 ]);
    return true;

} else
if ( tempmin1 > tempmin3 )  
{
    printf ( "Verdadeiro" );
    printf ( "Os dois eventos se cruzam de %d%d:%d%d até %d%d:%d%d", f1 [ 0 ], f1 [ 1 ], f1 [ 3 ], f1 [ 4 ],
                                                                     c2 [ 0 ], c2 [ 1 ], c2 [ 3 ], c2 [ 4 ]);
    return true;

} else
{
    printf ( "Nao tem conflito" );
    return false;
}
}

int main()
{

    while ( tempmin1 < 0 || tempmin1 > 59 || tempmin2 < 0 || tempmin1 > 1440 || tempmin3 > 1440 )
    {
        printf( "Qual o horario do começo do primeiro evento?:" );
        scanf( "%01d%01d:%01d%01d", &comeco1 [ 0 ], &comeco1 [ 1 ], &comeco1 [ 3 ], &comeco1 [ 4 ]);

        tempmin1 = comeco1 [ 4 ] + comeco1 [ 3 ] * 10;
        tempmin2 = comeco1 [ 1 ] * 60 + comeco1 [ 0 ] * 600;
        tempmin3 = tempmin1 + tempmin2;
        tempcomeco = tempmin3;
    } 
    tempmin1 = -1;
    tempmin2 = -1;
    tempmin3 = -1;

    while ( ( ( tempmin1 < 0 || tempmin1 > 59 ) || ( tempmin2 < 0 || tempmin1 > 1440) ) 
                                                            || tempmin3 > 1440 || tempmin3 <= tempcomeco )
    {
        printf( "Qual o horario final do primeiro evento?:" );
        scanf( "%01d%01d:%01d%01d", &fim1 [ 0 ], &fim1 [ 1 ], &fim1 [ 3 ], &fim1 [ 4 ] );
        tempmin1 = fim1 [ 4 ] + fim1 [ 3 ] * 10;
        tempmin2 = fim1 [ 1 ] * 60 + fim1 [ 0 ] * 600;
        tempmin3 = tempmin1 + tempmin2;     
    }
    tempmin1 = -1;
    tempmin2 = -1;
    tempmin3 = -1;

    printf( "Qual o horario do começo do segundo evento?:" );
    while ( ( ( tempmin1 < 0 || tempmin1 > 59 ) || ( tempmin2 < 0 || tempmin1 > 1440 ) ) || tempmin3 > 1440 )
    {
        scanf( "%01d%01d:%01d%01d", &comeco2 [ 0 ], &comeco2 [ 1 ], &comeco2 [ 3 ], &comeco2 [ 4 ] );
        tempmin1 = comeco2 [ 4 ] + comeco2 [ 3 ] * 10;
        tempmin2 = comeco2 [ 1 ] * 60 + comeco2 [ 0 ] * 600;
        tempmin3 = tempmin1 + tempmin2;
        tempcomeco = tempmin3;
    }
    tempmin1 = -1;
    tempmin2 = -1;
    tempmin3 = -1;

    
    while ( ( ( tempmin1 < 0 || tempmin1 > 59 ) || ( tempmin2 < 0 || tempmin1 > 1440 ) ) || tempmin3 > 1440
                                                                                || tempmin3 <= tempcomeco )
    {
        printf( "Qual o horario final do segundo evento?:" );
        scanf( "%01d%01d:%01d%01d", &fim2 [ 0 ], &fim2 [ 1 ], &fim2 [ 3 ], &fim2 [ 4 ] );
        tempmin1 = fim2 [ 4 ] + fim2 [ 3 ] * 10;
        tempmin2 = fim2 [ 1 ] * 60 + fim2 [ 0 ] * 600;
        tempmin3 = tempmin1 + tempmin2;
    }
    tempmin1 = -1;
    tempmin2 = -1;
    tempmin3 = -1;

haveConflict ();

}