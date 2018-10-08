#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

double ratio = 1;

 void gotoxy(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

int lastC = 0, b4x = 0, b4y = 0;

void squareAroundD(int x, int y){
    gotoxy(x+1,y+1);printf("|");
    gotoxy(x-1,y+1);printf("|");
    gotoxy(x,y);printf("-");
    gotoxy(x,y+2);printf("-");
}

void deSquareAroundD(int x, int y){
    gotoxy(x+1,y+1);printf(" ");
    gotoxy(x-1,y+1);printf(" ");
    gotoxy(x,y);printf(" ");
    gotoxy(x,y+2);printf(" ");
}

void lookIntoArrayD(int array[],int arrSize, int min_idx, int j){

    int c = 4, l = 4;
    for(int i = 0; i < arrSize; i++){
        gotoxy(c,l);printf("%d",array[i]);
        c +=2;
    }
    Sleep(700*ratio);
    deSquareAroundD(b4x,b4y);

    c = 4;

    for(int i = j; i < arrSize; i++){


        if(i == min_idx)
            {gotoxy(c+(i*2),l-1);printf("v");
            squareAroundD(c+(i*2),l-1);
            Sleep(1000*ratio);
            deSquareAroundD(c+(i*2),l-1);
            gotoxy(c+(i*2),l-1);printf(" ");break;}
        else{
            gotoxy(c+(i*2),l-1);printf("v");
            //lastC = c+(i*2);
            Sleep(300*ratio);
            gotoxy(c+(i*2),l-1);printf(" ");
        }

    }
}

void squareAround(int x, int y){
    gotoxy(x-1,y);printf("|");
    gotoxy(x+3,y);printf("|");
    gotoxy(x,y+1);printf("-");
    gotoxy(x+2,y+1);printf("-");
    gotoxy(x,y-1);printf("-");
    gotoxy(x+2,y-1);printf("-");
}

void deSquareAround(int x, int y){
    gotoxy(x-1,y);printf(" ");
    gotoxy(x+3,y);printf(" ");
    gotoxy(x,y+1);printf(" ");
    gotoxy(x+2,y+1);printf(" ");
    gotoxy(x,y-1);printf(" ");
    gotoxy(x+2,y-1);printf(" ");
}

void lookIntoArray(int array[],int arrSize, int marker, int cc, int d){

    int c = 4, l = 4;
    gotoxy(1,1);printf("%d", cc);
    gotoxy(1,2);printf("%d", d);


    for(int i = 0; i < arrSize; i++){
        gotoxy(c,l);printf("%d",array[i]);
        c +=2;
    }
    Sleep(700*ratio);
    deSquareAround(b4x,b4y);

    c = 4;

    for(int i = 0; i < arrSize; i++){
        if(array[i] == marker) {}
        else{
            gotoxy(c+2,l-1);printf("v");
            gotoxy(c+4,l-1);printf("v");
            lastC = c+2;
            Sleep(200*ratio);
        }
        if(array[i] == marker)
        {
            squareAround(c,l);
            Sleep(600*ratio);
            b4x = c;
            b4y = l;
            break;
        }
        gotoxy(lastC,l-1);printf(" ");
        gotoxy(lastC+2,l-1);printf(" ");
        c +=2;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[],int arrSize){

    int r = 6;
    gotoxy(4,2);printf("Bubble Sort:");
    for (int c = 0 ; c < arrSize - 1; c++)
    {
        //if(c > 10){printf("%d", c);}
        gotoxy(4,r++);printf("for (int c = 0; c < 10 - 1; c++ \t c = %d", c);
        for (int d = 0 ; d < arrSize - c - 1; d++)

        {
            gotoxy(4,r++);printf("for (int d = 0; c < 10 - %d - 1; d++ \t d = %d", c, d);
            if (array[d] > array[d+1])
            {
            lookIntoArray(array, arrSize, array[d], c ,d);
            swap(&array[d],&array[d+1]);
            }
        }
    }
}

void selectionSort(int array[], int arrSize)
{   int i, j, min_idx;
    gotoxy(4,2);printf("Selection Sort:");
    for (i = 0; i < arrSize-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < arrSize; j++)
          if (array[j] < array[min_idx])
            min_idx = j;
        lookIntoArrayD(array, arrSize, min_idx, i);
        swap(&array[min_idx], &array[i]);
    }
}

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main()
{
    int arrayInts[10] = {5,3,2,9,6,4,8,0,7,1};
    shuffle(arrayInts,(sizeof(arrayInts)/sizeof(*arrayInts)));
    int c = 4;
    //getch();
    ratio = 0.5;
   //printf("n elem -> %d", (sizeof(arrayInts)/sizeof(*arrayInts)));
    getch();
    bubbleSort(arrayInts,(sizeof(arrayInts)/sizeof(*arrayInts)));
    //selectionSort(arrayInts,(sizeof(arrayInts)/sizeof(*arrayInts)));

    for(int i = 0; i < sizeof(arrayInts)/sizeof(*arrayInts); i++){
        gotoxy(c,4);
        printf("%d ",arrayInts[i]);
        c +=2;
    }

    deSquareAroundD(b4x,b4y);
    printf("\n\n\n\n");
    gotoxy(4,200);system("pause");
    return 0;
}
