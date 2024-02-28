#include <stdio.h>

int main() {
int appleQuantity = 23;
double applePrice = 1.49;
float appleReview = 82.5;
int appleReviewDisplay = (float)appleReview;                                                     char APPLELOCATION = 'F';
printf("An apple costs: $%.2f, there are %d in inventory found in section: %c and your customers gave it an average review of %d%%!\n", applePrice, appleQuantity, APPLELOCATION, appleReviewDisplay);
}
