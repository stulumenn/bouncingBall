#include <stdio.h>

int oneStepUp (char theRoadPoint, int feetHeight, int height);
int oneStepDown (char theRoadPoint, int feetHeight, int height);
int point (char thePeekPoint, int feetHeight, int height);
int printRoad(char theRoadPoint, int feetHeight);
void printSpace(int size);
int finishDiag(int length);

int main(){												
	const int feet = 3;
	int usedChar = 0;
	int height = 6;
	const int finishDiagLength = height * feet + 1;
	char thePeekPoint = 'o';
	char theRoadPoint = '-';

	for (; height > 0; --height){
		usedChar += oneStepUp (theRoadPoint, feet, height);
		usedChar += point (thePeekPoint, feet, height);
		usedChar += oneStepDown (theRoadPoint, feet, height - 1);		
	}
	finishDiag(finishDiagLength);
	printf("%d char used.\n", usedChar);
	return 0;
}
int point (char thePeekPoint, int feetHeight, int height){ //burada peek point yazılacak
	printf("l");
	printSpace(height * feetHeight);
	printf ("%c\n", thePeekPoint);
	return 1;
}
int printRoad(char theRoadPoint, int feetHeight){ //yukarı yol çizilecek
	int usedChar = 0;
	for (int i = 0; i < feetHeight; i++){
		printf ("%c", theRoadPoint);
		++usedChar;
	}
	return usedChar;
}
void printSpace(int size){ //yukarı yolun boşlukları belirlenecek
	for (int i = 0; i < size; i++)
		printf (" ");
}
int oneStepUp (char theRoadPoint, int feetHeight, int height){ //roadwayup ve spacewayup birleştirilecek
	// print spaces
	// print roadpoint
	int usedChar = 0;
	int spaceCounter = 0;

	for (int i = 0; i < height; i++){
		printf("l");
		printSpace(spaceCounter);
		usedChar += printRoad(theRoadPoint, feetHeight);
		spaceCounter = spaceCounter + feetHeight;
		printf("\n");
	}

	return usedChar;
}

int oneStepDown (char theRoadPoint, int feetHeight, int height){ //roadwaydown ve spacewaydown birleştirilecek
	
	int usedChar = 0;
	int spaceCounter = feetHeight * height;

	for (int i = 0; i <= height; i++){
		printf("l");
		printSpace(spaceCounter);
		usedChar += printRoad (theRoadPoint, feetHeight);
		spaceCounter -= feetHeight;
		printf("\n");
	}

	return usedChar;
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