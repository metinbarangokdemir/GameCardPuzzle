#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define c 8
#define r 6
int card[c][r];
int show[c][r];
int counter;
void board() {
	
	system("COLOR 2");
	system("cls");
int i, j;
printf("                                    Matching Cards=%d",counter);
printf("\n");

 printf("  | 1   2   3   4   5   6\n");
 printf("--+--------------------------\n");
 for (i=0;i<c;i++) {
 		printf("%c | ",'1'+i);
        for (j=0;j<r;j++) {
            if(show[i][j]==1){
            	printf("|%d| ",card[i][j]);
			}
            else {
                printf("|?| ");
            }
        }
        printf("\n");
    }
}


void random() {
    srand(time(NULL));
    int a;
    int i,j;
    int b=1;
    int s,sa;
      for (i=0;i<c;i++) {
        for (j=0;j<r;j++) {
        	 card[i][j]=b;
        	 if(j%2==1){
        	 	 b++;
 }
} } 
          for (i=0;i<c;i++) {
        for (j=0;j<r;j++) {
        	s=rand()%c;
        	sa=rand()%r;
        	 a=card[s][sa];
        	 card[s][sa]=card[i][j];
        	 card[i][j]=a;
			 }
}
        }
     

int giris(){
	int out;
	system("COLOR 4");
	   printf("#############################################\n \n");
printf("            MATCHING CARDS GAME             \n \n");
printf("#############################################\n");
printf("\n");
printf("Welcome to the Matching Cards game!\n");
printf("\n");
printf("Enter * to quit the game\n");
printf("Press Enter to start the game \n");

 out=getchar();

 	
 	 if (out == '*') {
        printf("GOODBYE...");
        exit(0);
 }

 
}


int main() {
    int row1, col1, row2, col2;

    random();
    giris();
    int i,j;
    for (i=0;i<c;i++) {
        for (j=0;j<r;j++) {
            show[i][j] = 0;
        }
    }

    while (counter<24) {
        if(counter>24){
            printf("GAME IS FINISHED");
        }
    
        board();

        printf("\nEnter the column and row of the first card: ");
        scanf("%d %d", &col1, &row1);
        if (row1 > 6 || row1 <= 0 || col1 > 8 || col1 <= 0) {
            printf("Please enter a column between 0 and 8 and a row between 0 and 6.\n");
            sleep(2);
            continue;
        }
          row1--;
        col1--;
        if (show[col1][row1] == 1) {
            printf("\nThis card has already been selected. Please choose a different card.\n");
            sleep(2);
            continue;
        }

        
        show[col1][row1]=1;
        board();

        printf("Enter the column and row of the second card: ");
        scanf("%d %d",&col2,&row2);


if (row2 > 6 || row2 <= 0 || col2 > 8 || col2 <= 0) {
    printf("Please enter a column between 0 and 8 and a row between 0 and 6\n");
    sleep(2);
    continue;
}
row2--;
col2--;


if (show[col2][row2] == 1) {
    printf("This card has already been selected. Please choose a different card\n");
    sleep(2);
    continue;
}
        
        show[col2][row2]=1;
        board();
        sleep(1);

         if (card[col1][row1] == card[col2][row2]) {
            printf("Match\n");
            counter++;
            sleep(1);
           
        }
 
else {
printf("Did not match \n");
   show[col1][row1]=0;
   show[col2][row2]=0;
   sleep(1);
}

}
return giris();
}
