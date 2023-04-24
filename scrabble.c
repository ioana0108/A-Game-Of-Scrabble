#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util/print_board.h"
#include "util/scrabble.h"



int scorcuv( char cuv[100], int linie, int coloana, int directie, char sir1[100], char sir2[100] ) 
{
        int k, c, scor = 0, bonus_1 = 0, bonus_2 = 0, SCOR[26];

        char *p;

        SCOR[0] = SCOR[4] = SCOR[8] = SCOR[11] = SCOR[13] = SCOR[14] = SCOR[17] = SCOR[18] = SCOR[19] = SCOR[20] = 1; 
        SCOR[3] = SCOR[6] = 2;
        SCOR[1] = SCOR[2] = SCOR[12] = SCOR[15] = 3;
        SCOR[5] = SCOR[7] = SCOR[21] = SCOR[22] = SCOR[24] = 4;
        SCOR[10] = 5;
        SCOR[9] = SCOR[23] = 8;
        SCOR[16] = SCOR[25] = 10;

        p = cuv;

        for( c = 0 ; c < (int)strlen(p) ; c++ )
        {
                   
                scor += SCOR[*(p + c) - 'A'];       
                
        }  


        if( strstr( p , sir1) != 0 ) 
        {
                if(directie == 0) 
                {
                        for( k = coloana ; k < coloana + (int)strlen(p) ; k++ )
                        {
                                if(bonus_board[linie][k] == 1)
                                {
                                        bonus_1 += 1;
                                }
                                
                        }
                }
                else
                {
                        for( k = linie ; k < linie + (int)strlen(p) ; k++ )
                        {
                                if(bonus_board[k][coloana] == 1)
                                {
                                        bonus_1 += 1;
                                }
                                
                        }
                }

                
                
                for( k = 1 ; k <= bonus_1 ; k++ )
                {
                        scor = scor * 2;
                } 
                
                
        }


        if( strstr( (p + strlen(p) - 2) , sir2 ) != 0 )
        {
                if(directie == 0) 
                {
                        for( k = coloana ; k < coloana + (int)strlen(p) ; k++ )
                        {
                                if(bonus_board[linie][k] == 2)
                                {
                                        bonus_2 += 1;
                                }
                                
                        }
                }
                else
                {
                        for( k = linie ; k < linie + (int)strlen(p) ; k++ )
                        {
                                if(bonus_board[k][coloana] == 2)
                                {
                                        bonus_2 += 1;
                                }
                                
                        }
                }

  
                for( k = 1 ; k <= bonus_2 ; k++ )
                {
                        scor = scor * 3;
                } 

                
        }

        return scor; 

}



void asaza_pe_tabla( char tabla[BOARD_SIZE][BOARD_SIZE], char cuv[100], int lin, int col, int dir )
{
        
        int i;
        char *p;

        p = cuv;
        
        if( dir == 0)
        {

                for( i = 0 ; i < (int)strlen(p) ; i++ )
                {
                        tabla[lin][col + i] = *(p + i);
                }

        }
        else
        {
                for( i = 0 ; i < (int)strlen(p) ; i++ )
                {
                        tabla[lin + i][col] = *(p + i);
                }

        }

}



void gaseste_cuv(char tabla[BOARD_SIZE][BOARD_SIZE], int nr_cuv, char cuvinte[100][100], char sir1[100], char sir2[100], int *(SCOR_MAX) )
{

        int i, j, k, lin, col, dir, maxim;
        int linie, coloana, directie, lin_cuv, col_cuv, dir_cuv;
        int already_played, incape, gasit;
        char *q, *p;

        *(SCOR_MAX) = 0;

        for( i = 0 ; i < NUM_WORDS ; i++ )
        {
                
                already_played = 0;

                for( j = 0 ; j < nr_cuv ; j++ )
                {

                        if( strcmp( words[i] , cuvinte[j] ) == 0 )
                        {
                                already_played = 1;
                                break;   
                        }

                }

                if( already_played == 0 )
                {
                        p = words[i];

                        incape = 1; 
                        gasit = 0;

                        maxim = 0;

                        for( lin = 0 ; lin < BOARD_SIZE ; lin++ ) 
                        {
                                
                                for( col = 0 ; col < BOARD_SIZE ; col++ ) 
                                {

                                        incape = 1;

                                        if( tabla[lin][col] == *p ) 
                                        {
                                                
                                                for( k = 1 ; k < (int)strlen(p) ; k++ )
                                                {

                                                        if( ( tabla[lin][col + k] != '.' )  ||  ( col + strlen(p) > BOARD_SIZE ) )
                                                        {
                                                                incape = 0;
                                                                k = strlen(p); 
                                                        }
                                                              
                                                }

                                                if( incape == 1 )
                                                {
                                                        
                                                        dir = 0;

                                                        if( scorcuv(p, lin, col, dir, sir1, sir2) > maxim )
                                                        {

                                                                directie = 0;
                                                                linie = lin;
                                                                coloana = col; 

                                                                maxim = scorcuv(p, lin, col, dir, sir1, sir2);

                                                                gasit = 1;

                                                        }
                                                        
                                                }

                                                incape = 1; 

                                                for( k = 1 ; k < (int)strlen(p) ; k++ ) 
                                                {
                                                        
                                                        if( ( tabla[lin + k][col] != '.' ) || ( lin + (int)strlen(p) > BOARD_SIZE ) )
                                                        {
                                                                
                                                                incape = 0;
                                                                k = strlen(p); 

                                                        }
                                                        
                                                }

                                                if(incape == 1)
                                                {
                                                        
                                                        dir = 1;
                                                        
                                                        if( scorcuv(p, lin, col, dir, sir1, sir2) > maxim )
                                                        {
                                                                
                                                                directie = 1;
                                                                linie = lin;
                                                                coloana = col;

                                                                maxim =  scorcuv(p, lin, col, dir, sir1, sir2);

                                                                gasit = 1;

                                                        }
                                                        
                                                }
                                                
                                        }

                                }

                        }
                
                        if( gasit == 1)  
                        {

                                if( maxim > *(SCOR_MAX) )
                                {
                                        *(SCOR_MAX) = maxim; 

                                        q = words[i]; 

                                        lin_cuv = linie;
                                        col_cuv = coloana;
                                        dir_cuv = directie;
                                }
                                else
                                {
                                        if( maxim == *(SCOR_MAX) )
                                        {
                                                if( linie < lin_cuv )
                                                {
                                                        
                                                        lin_cuv = linie;

                                                        col_cuv = coloana;

                                                        dir_cuv = directie;

                                                        q = words[i];

                                                }
                                                else
                                                {

                                                        if( linie == lin_cuv )
                                                        {

                                                                if( coloana < col_cuv )
                                                                {

                                                                        lin_cuv = linie;

                                                                        col_cuv = coloana;

                                                                        dir_cuv = directie;

                                                                        q = words[i];

                                                                }
                                                                else
                                                                {
                                                                        if( coloana == col_cuv )
                                                                        {

                                                                                if( directie < dir_cuv )
                                                                                {
                                                                                        lin_cuv = linie;

                                                                                        col_cuv = coloana;

                                                                                        dir_cuv = directie;

                                                                                        q = words[i]; 
                                                                                }
                                                                                
                                                                        }

                                                                }
                                                                
                                                        }

                                                }
                                                
                                        }

                                }
                                
                        } 

                }
 
        }

        asaza_pe_tabla( tabla, q , lin_cuv , col_cuv , dir_cuv );

        strcpy( cuvinte[nr_cuv], q );

}



void task6(char matrice[BOARD_SIZE][BOARD_SIZE])
{

        int i, j, k, nrcuv, lin, col, dir, SCOR_PLAYER1, SCOR_PLAYER2;
        char *p, subsir1[100], subsir2[100], date_intrare[100][100], cuv_jucate[100][100];
        

        fgets(date_intrare[1], 100, stdin);
        p = strtok(date_intrare[1] , "\n"); 

        for( i = 0 ; i < (int)strlen(p) ; i++ )
        {
                subsir1[i] = *(p + i);  
        }

        fgets( date_intrare[2] , 100 , stdin );  

        p = strtok(date_intrare[2] , "\n");

        for( i = 0 ; i < (int)strlen(p) ; i++ )
        {
                subsir2[i] = *(p + i);
        }

        fgets(date_intrare[3], 100, stdin);

        nrcuv = atoi(date_intrare[3]);


        for( i = 0 ; i < BOARD_SIZE ; i++ )
                for( j = 0 ; j < BOARD_SIZE ; j++ )
                        matrice[i][j] = '.';



        int *adr_scor_cuv_gasit, nr = 0, scor_cuv_gasit = 0;;
        adr_scor_cuv_gasit = &scor_cuv_gasit;


        for( i = 4 ; i < nrcuv + 4 ; i++ )
        {
                
                fgets(date_intrare[i], 100, stdin);

                lin = 0;
                col = 0;
                
                p = strtok(date_intrare[i], " ");
                for ( k = 0 ; k < (int)strlen(p) ; k++ )
                {
                        lin = lin * 10 + ( *(p + k) - '0' );
                }

                p = strtok(NULL, " ");
                for ( k = 0 ; k < (int)strlen(p) ; k++ )
                {
                        col = col * 10 + ( *(p + k) - '0' );
                }

                p = strtok(NULL, " "); 
                dir = *p - '0';

                p = strtok(NULL, "\n");

                strcpy( cuv_jucate[nr] , p );

                nr++;

                asaza_pe_tabla(matrice, p, lin, col, dir);

                
                SCOR_PLAYER1 += scorcuv( p, lin, col, dir, subsir1, subsir2 );

                
                gaseste_cuv( matrice, nr, cuv_jucate , subsir1, subsir2, adr_scor_cuv_gasit );

                nr++;

                SCOR_PLAYER2 += scor_cuv_gasit;

        }

        print_board(matrice);

        if( SCOR_PLAYER1 > SCOR_PLAYER2 )
        {
                printf("Player %d Won!\n", 1);
        }
        else
        {
                printf("Player %d Won!\n", 2);
        } 
        
}



void task5(char matrice[BOARD_SIZE][BOARD_SIZE])
{
        
        int i, j, k, nrcuv, col, lin, dir, SCOR_PLAYER1 = 0, SCOR_PLAYER2 = 0;
        char date_intrare[100][100], subsir1[100], subsir2[100], cuv_jucate[100][100], *p;
        

        fgets(date_intrare[1], 100, stdin);
        p = strtok(date_intrare[1] , "\n"); 

        for( i = 0 ; i < (int)strlen(p) ; i++ )
        {
                subsir1[i] = *(p + i);  
        }

        fgets( date_intrare[2] , 100 , stdin );

        p = strtok(date_intrare[2] , "\n");

        for( i = 0 ; i < (int)strlen(p) ; i++ )
        {
                subsir2[i] = *(p + i);
        }

        fgets(date_intrare[3], 100, stdin);

        nrcuv = atoi(date_intrare[3]);


        for( i = 0 ; i < BOARD_SIZE ; i++ )
                for( j = 0 ; j < BOARD_SIZE ; j++ )
                        matrice[i][j] = '.';
        
        for( i = 4 ; i < nrcuv + 4 ; i++ )
        {

                fgets(date_intrare[i], 100, stdin);

                lin = 0;
                col = 0;

                p = strtok(date_intrare[i], " ");
                for ( k = 0 ; k < (int)strlen(p) ; k++ )
                {
                        lin = lin * 10 + ( *(p + k) - '0' );
                }

                p = strtok(NULL, " ");
                for ( k = 0 ; k < (int)strlen(p) ; k++ )
                {
                        col = col * 10 + ( *(p + k) - '0' );
                }

                p = strtok(NULL, " "); 
                dir = *p - '0';

                p = strtok(NULL, "\n");

                strcpy( cuv_jucate[i - 4] , p ); 

                asaza_pe_tabla(matrice, p, lin, col, dir);

                if( i % 2 == 0 )
                {

                        SCOR_PLAYER1 += scorcuv( p, lin, col, dir, subsir1, subsir2 );

                }
                else
                {

                        SCOR_PLAYER2 += scorcuv( p, lin, col, dir, subsir1, subsir2 );

                }
                
        }


        int scor_cuv_gasit = 0;

        int *adr_scor_cuv_gasit;

        adr_scor_cuv_gasit = &scor_cuv_gasit;


        gaseste_cuv( matrice, nrcuv, cuv_jucate, subsir1, subsir2, adr_scor_cuv_gasit);


        if( SCOR_PLAYER2 + scor_cuv_gasit >= SCOR_PLAYER1 )
        {
                
                print_board(matrice);
                
        }
        else
        {
                printf("Fail!\n");
        }

}



void task4(char matrice[BOARD_SIZE][BOARD_SIZE])
{

        char date_intrare[100][100], cuv_jucate[100][100], *p;
        int nrcuv, i, dir, col, lin, j, already_played = 0, k, incape_pe_lin, incape_pe_col, gasit = 0;


        fgets(date_intrare[1], 100, stdin);

        fgets(date_intrare[2], 100, stdin);

        fgets(date_intrare[3], 100, stdin);

        nrcuv = atoi(date_intrare[3]);


        for( i = 0 ; i < BOARD_SIZE ; i++ )
                for( j = 0 ; j < BOARD_SIZE ; j++ )
                        matrice[i][j] = '.';


        for( i = 4 ; i < nrcuv + 4 ; i++ )
        {

                fgets(date_intrare[i], 100, stdin);

                lin = 0;
                col = 0;

                p = strtok(date_intrare[i], " ");
                for ( k = 0 ; k < (int)strlen(p) ; k++ )
                {
                        lin = lin * 10 + ( *(p + k) - '0' );
                }

                p = strtok(NULL, " ");
                for ( k = 0 ; k < (int)strlen(p) ; k++ )
                {
                        col = col * 10 + ( *(p + k) - '0' );
                }

                p = strtok(NULL, " "); 
                dir = *p - '0';

                p = strtok(NULL, "\n");

                strcpy( cuv_jucate[i - 4] , p );  

                asaza_pe_tabla(matrice, p, lin, col, dir);

        }

        for( i = 0 ; i < NUM_WORDS && gasit == 0 ; i++ )
        {

                already_played = 0;

                for( j = 0 ; j < nrcuv ; j++ )
                {
                        if( strcmp( words[i] , cuv_jucate[j] ) == 0 )
                        {
                                already_played = 1;
                                break;   
                        }
                }
                if( already_played == 0 )
                {
                        p = words[i];

                        incape_pe_lin = 1; 
                        incape_pe_col = 1;
                        gasit = 0;

                        for( lin = 0 ; lin < BOARD_SIZE && gasit == 0 ; lin++ )
                        {
                                
                                for( col = 0 ; col < BOARD_SIZE && gasit == 0 ; col++ ) 
                                {
                                        
                                        incape_pe_lin = 1;
                                        
                                        if( matrice[lin][col] == *p ) 
                                        {
                                                
                                                for( k = 1 ; k < (int)strlen(p) ; k++ )
                                                {
                                                        if( ( matrice[lin][col + k] != '.' )  ||  ( col + (int)strlen(p) > 15 ) )
                                                        {
                                                                incape_pe_lin = 0;
                                                                k = strlen(p); 
                                                        }
                                                        
                                                        
                                                }
                                                if( incape_pe_lin == 1 )
                                                {
                                                        for( k = 0 ; k < (int)strlen(p) ; k++ )
                                                        {

                                                                matrice[lin][col + k] = *(p + k); 
                                                        }
                                                        
                                                        gasit = 1;

                                                        col = BOARD_SIZE; 
                                                }

                                                if(incape_pe_lin == 0)
                                                {

                                                        incape_pe_col = 1; 

                                                        for( k = 1 ; k < (int)strlen(p) ; k++ ) 
                                                        {
                                                                if( ( matrice[lin + k][col] != '.' ) || ( lin + strlen(p) > 15 ) )
                                                                {
                                                                        incape_pe_col = 0;
                                                                        k = strlen(p); 
                                                                }
                                                                
                                                        }
                                                        if(incape_pe_col == 1)
                                                        {
                                                                for( k = 0 ; k < (int)strlen(p) ; k++ ) 
                                                                {
                                                                        
                                                                        matrice[lin + k][col] = *(p + k); 
                                                
                                                                }
                
                                                                gasit = 1;
                                                        }

                                                }
                                                
                                        }

                                }

                        }

                }
                
        }

        print_board(matrice);

}



void task3() 
{
        
        char date_intrare[100][100], *p, subsir1[100], subsir2[100];
        int  i, j, lin = 0, col = 0, dir, nrcuv = 0, SCOR_PLAYER1 = 0 , SCOR_PLAYER2 = 0;


        fgets(date_intrare[1], 100, stdin);
        p = strtok(date_intrare[1] , "\n");

        for( i = 0 ; i < (int)strlen(p) ; i++ )
        {
                subsir1[i] = *(p + i);  
        }

        fgets( date_intrare[2] , 100 , stdin ); 

        p = strtok(date_intrare[2] , "\n");

        for( i = 0 ; i < (int)strlen(p) ; i++ )
        {
                subsir2[i] = *(p + i);
        }


        fgets(date_intrare[3], 100, stdin);

        nrcuv = atoi(date_intrare[3]); 

        for( i = 4 ; i <= nrcuv + 3 ; i++ )
        {
                fgets(date_intrare[i], 100, stdin);

                lin = 0;
                col = 0;

                p = strtok(date_intrare[i], " ");
                for ( j = 0 ; j < (int)strlen(p) ; j++ )
                {
                        lin = lin * 10 + ( *(p + j) - '0' );
                }

                p = strtok(NULL, " ");
                for ( j = 0 ; j < (int)strlen(p) ; j++ )
                {
                        col = col * 10 + ( *(p + j) - '0' );
                }

                p = strtok(NULL, " "); 
                dir = *p - '0';

                p = strtok(NULL, "\n");


                if( i % 2 == 0 )
                {

                        SCOR_PLAYER1 += scorcuv( p, lin, col, dir, subsir1, subsir2 );

                }
                else
                {

                        SCOR_PLAYER2 += scorcuv( p, lin, col, dir, subsir1, subsir2 );

                }

        }

        printf("Player 1: %d Points\nPlayer 2: %d Points\n", SCOR_PLAYER1, SCOR_PLAYER2);

}



void task2(int nrcuv)   
{

        char date_intrare[100][100], *p;
        int  i, j, lin = 0, col = 0, dir, scoruri[27], SCOR_PLAYER1 = 0, SCOR_PLAYER2 = 0;


        scoruri[0] = scoruri[4] = scoruri[8] = scoruri[11] = scoruri[13] = scoruri[14] = scoruri[17] = scoruri[18] = scoruri[19] = scoruri[20] = 1; 
        scoruri[3] = scoruri[6] = 2;
        scoruri[1] = scoruri[2] = scoruri[12] = scoruri[15] = 3;
        scoruri[5] = scoruri[7] = scoruri[21] = scoruri[22] = scoruri[24] = 4;
        scoruri[10] = 5;
        scoruri[9] = scoruri[23] = 8;
        scoruri[16] = scoruri[25] = 10;


        for( i = 2 ; i <= nrcuv + 1 ; i ++ )
        {
                
                fgets(date_intrare[i], 100, stdin);  
                        
                lin = 0;
                col = 0;

                p = strtok(date_intrare[i], " "); 
                for ( j = 0 ; j < (int)strlen(p) ; j++ )
                {
                        lin = lin * 10 + ( *(p + j) - '0' );
                }

                p = strtok(NULL, " ");
                for ( j = 0 ; j < (int)strlen(p) ; j++ )
                {
                        col = col * 10 + ( *(p + j) - '0' );
                }
                
                p = strtok(NULL, " "); 
                dir = *p - '0';

                p = strtok(NULL, "\n"); 

                
                for( j = 0 ; j < (int)strlen(p) ; j ++ ) 
                {

                        if( i % 2 == 0)
                        {
                                SCOR_PLAYER1 += scoruri[*(p + j) - 'A'];
                        }
                        else
                        {
                                SCOR_PLAYER2 += scoruri[*(p + j) - 'A'];
                        }
                        
                }

        }

        printf("Player 1: %d Points\nPlayer 2: %d Points", SCOR_PLAYER1, SCOR_PLAYER2);

}



void task1(char matrice[BOARD_SIZE][BOARD_SIZE], int nrcuv)
{

        char date_intrare[100][100], *p;
        int  i, j, lin = 0, col = 0, dir;

        for( i = 2 ; i <= nrcuv + 1 ; i++ )
        {
                fgets(date_intrare[i], 100, stdin);   

                lin = 0;
                col = 0;

                p = strtok(date_intrare[i], " "); 
                for ( j = 0 ; j < (int)strlen(p) ; j++ )
                {
                        lin = lin * 10 + ( *(p+j) - '0' );
                }

                p = strtok(NULL, " ");
                for ( j = 0 ; j < (int)strlen(p) ; j++ )
                {
                        col = col * 10 + ( *(p + j) - '0' );
                }
                
                p = strtok(NULL, " "); 
                dir = *p - '0';

                p = strtok(NULL, "\n"); 


                asaza_pe_tabla(matrice, p, lin, col, dir);

        }

        print_board(matrice);
        
}



void task0(char matrice[BOARD_SIZE][BOARD_SIZE])
{       
        int i, j;

        for( i = 0 ; i < BOARD_SIZE ; i++ )
                for( j = 0 ; j < BOARD_SIZE ; j++ )
                        matrice[i][j] = '.';


}



int main()
{

        char game_board[BOARD_SIZE][BOARD_SIZE], date_intrare[100][100];
        int nr_cuv_primite = 0;

        
        fgets(date_intrare[0], 100, stdin);


        if(date_intrare[0][0] == '1' || date_intrare[0][0] == '2')
        {

                fgets(date_intrare[1], 100, stdin); 
                nr_cuv_primite = atoi(date_intrare[1]);

        }


        if( date_intrare[0][0] == '0' )
        {

                task0(game_board);
                print_board(game_board);

        }


        if(date_intrare[0][0] == '1')
        {     

                task0(game_board);
                task1(game_board,nr_cuv_primite);

        } 


        if(date_intrare[0][0] == '2')
        {       

                task2(nr_cuv_primite);

        }


        if(date_intrare[0][0] == '3')   
        {
                
                task3();  

        }


        if(date_intrare[0][0] == '4')
        {       
                
                task4(game_board);;
                
        }


        if(date_intrare[0][0] == '5')
        {       
                
                task5(game_board);

        }


        if(date_intrare[0][0] == '6')
        {       
                
                task6(game_board);

        }

}
