#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<stdbool.h>

/*void init(int arr[9][9]){
	int i, j;
	for(i=0 ; i<9 ; i++){
		for (j=0 ; j<9 ; j++){
			arr[i][j]=0;
		}
	}
}*/

void initWithOtherBoard(int arr[9][9], int other[9][9]){// Ýki tane tahta aliyor ve birindeki bilgileri digerine kopyaliyor.
	int i, j;
	for(i=0 ; i<9 ; i++){
		for (j=0 ; j<9 ; j++){
			arr[i][j]= other[i][j];
		}
	}
}

void printBoard(int arr[9][9]){ // Olusan tahtayi ekrana bastiriyor.
	int i, j;
	for(i=0 ; i<9; i++){
		for (j=0 ;j<9 ; j++){
			if(arr[i][j] == 0){
				printf("  ");
			}
			else{
				printf("%d ", arr[i][j]);
			}

			if((j+1) % 3 == 0 && j!=8){
				printf("|");
			}
		}
		if ((i+1)%3==0){
			printf("\n-------------------");
		}
		printf("\n");
	}
}

void showBoards(int board1[9][9], int board2[9][9], int board3[9][9]){//Baslangýcta gözüken 3 tane tahtayi yan yana bastiriyor
	int i, j;
	for(i=0 ; i<9; i++){

        for (j=0 ;j<9 ; j++){
			if(board1[i][j] == 0){
				printf("  ");
			}
			else{
				printf("%d ", board1[i][j]);
			}

			if((j+1) % 3 == 0 && j!=8){
				printf("|");
			}
		}
		printf("\t");

        for (j=0 ;j<9 ; j++){
			if(board2[i][j] == 0){
				printf("  ");
			}
			else{
				printf("%d ", board2[i][j]);
			}

			if((j+1) % 3 == 0 && j!=8){
				printf("|");
			}
		}
		printf("\t");

        for (j=0 ;j<9 ; j++){
			if(board3[i][j] == 0){
				printf("  ");
			}
			else{
				printf("%d ", board3[i][j]);
			}

			if((j+1) % 3 == 0 && j!=8){
				printf("|");
			}
		}
		if ((i+1)%3==0 && i != 8){
			printf("\n-------------------");
			printf("\t-------------------");
			printf("\t-------------------");
		}

		printf("\n");
	}
}

bool isValidNumber(int arr[9][9], int row, int col, int number){//Girilen sayinin ayni satir, sutun, ve 3x3'lük karede gecerli olup olmadigini kontrol ediyor.

    if(number < 1 || number > 9 || row < 0 || row > 8 || col < 0 || col > 8) return false;

	int i ,j, row2, col2;


	row2 = row-((row)%3);
	col2 = col-((col)%3);

	for(i = 0; i < 9; i++){
        if(arr[i][col] == number){
            return false;
        }
	}

    for(j = 0; j < 9; j++){
        if(arr[row][j] == number){
            return false;
        }
	}


	for (i=row2; i<row2+3; i++){
		for(j=col2; j<col2+3 ; j++){
			if(arr[i][j] == number){
				return false;
			}
		}
	}
	return true;
}

bool isEnded(int arr[9][9]){// Oyunun sonunda bos hücre var mi yok mu onu kontrol ediyor.
    int i = 0;
    int j = 0;

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(arr[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}


int main() {

    int board[9][9];

    int board1[9][9] = {{2,0,9,0,0,0,6,0,0},
                        {0,4,0,8,7,0,0,1,2},
                        {8,0,0,0,1,9,0,4,0},
                        {0,3,0,7,0,0,8,0,1},
                        {0,6,5,0,0,8,0,3,0},
                        {1,0,0,0,3,0,0,0,7},
                        {0,0,0,6,5,0,7,0,9},
                        {6,0,4,0,0,0,0,2,0},
                        {0,8,0,3,0,1,4,5,0}
    };

    int board2[9][9] = {{5,4,0,0,2,0,8,0,6},
                        {0,1,9,0,0,7,0,0,3},
                        {0,0,0,3,0,0,2,1,0},
                        {9,0,0,4,0,5,0,2,0},
                        {0,0,1,0,0,0,6,0,4},
                        {6,0,4,0,3,2,0,8,0},
                        {0,6,0,0,0,0,1,9,0},
                        {4,0,2,0,0,9,0,0,5},
                        {0,9,0,0,7,0,4,0,2}
    };

    int board3[9][9] = {{3,0,8,0,0,1,0,6,0},
                        {0,6,0,8,9,0,0,0,2},
                        {0,0,1,0,0,3,9,0,8},
                        {6,0,4,2,3,0,0,0,0},
                        {0,8,0,1,0,6,4,0,0},
                        {0,1,2,0,4,0,0,3,0},
                        {0,3,0,6,0,2,0,8,0},
                        {2,0,0,0,8,4,0,0,6},
                        {8,0,0,0,0,0,2,7,0}
    };

	// init(board);
	// printBoard(board);


	setlocale(LC_ALL, "Turkish");
	int satir = 0, sutun = 0, sayi = 0;
	int secenek;


	while(true){
        printf("******************Oyuna Baþlayabilirsiniz******************\n\n\n");
        printf("Lütfen oynamak istediðiniz tahtayý seçiniz ve Enter'a basýnýz.\n\t 1 \t\t\t 2 \t\t\t 3 \n\n");

        showBoards(board1, board2, board3);
		printf("\n\n Çýkmak istiyorsanýz baþka bir rakama basýnýz.\n");
        scanf("%d",&secenek);
        
        switch(secenek){
            case 1:
                initWithOtherBoard(board, board1);
                break;
            case 2:
                initWithOtherBoard(board, board2);
                break;
            case 3:
                initWithOtherBoard(board, board3);
                break;
            default:
                return 0;
        };


        while(! isEnded(board)){
            printf("Sayý girmek istediðiniz satýrý giriniz\n");
            scanf("%d",&satir);
            printf("Sayý girmek istediðiniz sütunu giriniz\n");
            scanf("%d",&sutun);

            satir--;
            sutun--;

            if(satir<0 || satir>8 || sutun<0 || sutun>8){
                printf("Lütfen geçerli bir satýr ve sütun numarasý giriniz\n");
                continue;
            }
                sayi = 0;
                while(sayi<1 ||sayi>9){
                    printf("Lütfen girmek istediðiniz sayýyý tuþlayýnýz\n");
                    scanf("%d",&sayi);
                    if(sayi<1 || sayi>9)
                        printf("Lütfen geçerli bir sayý giriniz\n");
                }

                if(isValidNumber(board, satir, sutun, sayi)){
                    printf("Tebrikler girmek istediðiniz sayý uygundur\n\n");
                    board[satir][sutun] = sayi;
                    printBoard(board);

                }
                else{
                    printf("Girmek istediginiz sayý buraya uygun deðildir.\n\n");
                }

        }

        printf("Tebrikler oyunu baþarýlý bir þekilde bitirdiniz\n\n");
	}


	return 0;
}
