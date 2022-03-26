#include <stdio.h>

int drawVerDiagOfBb(int firstHeight, int feetHeight, char thePeakPoint, char theRoadPoint);
int drawDiagStep(int height, int feetHeight, char thePeakPoint, char theRoadPoint);
int finishDiag(int length);


int main(){

   int usedChar = drawVerDiagOfBb(6, 5, '*', '-');

   printf("%d char used\n", usedChar);

   return 0;
}

int drawVerDiagOfBb(int firstHeight, int feetHeight, char thePeakPoint, char theRoadPoint){
   int charUsed = 0;
   int lengthResponse;

   for (int i = firstHeight; i > 0; --i)
   {
      charUsed += drawDiagStep(i, feetHeight, thePeakPoint, theRoadPoint);
   }

   lengthResponse = finishDiag(firstHeight * feetHeight + 1);

   if(lengthResponse == 0){
      printf("finish diagram could not be drawn !!!");
   }

   return charUsed;
}

int drawDiagStep(int height, int feetHeight, char thePeakPoint, char theRoadPoint){
   int step;
   int charUsed;
   int i;
   for (int i; i < feetHeight; i++){
      if (i > 0){
         for (int j; j < feetHeight; j++){
         printf(" ");
         }
      }
      for (int a; a < feetHeight; a++){
         printf("%c", theRoadPoint);
      }
      i++;

   }
   

  
   printf("\n");
   return charUsed;
}


int finishDiag(int length){
   if(length <= 0){
      return 0;
   }

   printf("L");
   for (int i = 0; i < length; ++i)
   {
      printf("-");
   }
   printf(">\n");

   return 1;
}
