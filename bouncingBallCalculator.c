#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define REBOUNCE_LIMIT 1.0

double calculateNewHeight(double ratio, double height);
int countTheNumber(double ratio, double firstHeight);
double calculateTheVerticalDistance(double ratio, double height);
void report(double ratio, double height, FILE *resultFP);

int main(){
	srand(time(NULL));

	FILE *resultFP = fopen("Result_Table.txt", "w");

	double firstHeight = rand() % 30 + 10;
	double ratio = (rand() % 400 + 400.0) / 1000.0f;
	printf("firstHeight: %f\n", firstHeight);
	printf("ratio: %f\n", ratio);

	report(ratio, firstHeight, resultFP);

	return 0;
}



double calculateNewHeight(double ratio, double height){
	return ratio * height;
}

int countTheNumber(double ratio, double firstHeight){
	int i = 0;
	
	for (i = 0; firstHeight >= REBOUNCE_LIMIT; ++i)
	{
		firstHeight = calculateNewHeight(ratio, firstHeight);
	}
	
	return i;
}

double calculateTheVerticalDistance(double ratio, double height){
	double travelledDistance = height;

	for (int i = 0; height >= REBOUNCE_LIMIT; ++i)
	{
		height = calculateNewHeight(ratio, height);
		travelledDistance = travelledDistance + height * 2;
	}
	
	return travelledDistance;
}

void report(double ratio, double height, FILE *resultFP){
	int count = countTheNumber(ratio, height);
	double distance = calculateTheVerticalDistance(ratio, height);
	double travelledDistance = height;

	fprintf(resultFP, "No    The Rebouncing Height    The Total Vertical Distance\n");
	printf("No    The Rebouncing Height    The Total Vertical Distance\n");


	for (int i = 0; i < count; i++) {
		fprintf(resultFP, "%d\t%f\t%f\n", (i + 1), height, travelledDistance);
		printf("%d\t%f\t%f\n", (i + 1), height, travelledDistance);

		height = calculateNewHeight(ratio, height);
		travelledDistance = travelledDistance + height * 2;
	}

	fprintf(resultFP, "Total Vertical Distance is:%f\n", distance);
	printf("Total Vertical Distance is:%f\n", distance);

}

