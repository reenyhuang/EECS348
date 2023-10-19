#include <stdio.h>
#include <stdlib.h>

void hightolow(double data[], char *months[]);
void min(double data[], char *months[]);
void max(double data[], char *months[]);
void average(double data[]);
void moving_average(double data[], char *months[]);

int main(){
    char file[] = "test.txt";
    double data[11];
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Enter the name of the sales report file: ");
    scanf("%s", file);

    FILE *in = fopen(file, "r");
    if (in == NULL){
        printf("file dne\n");
    }
    int i = 0;
    char linech[100];

    while(fgets(linech, 100, in) && i <12) {
        sscanf(linech, "%lf", &data[i]);
        i++;
    }
    fclose(in);

// the following code is intended to print the sales report in a tabular form
    printf("\nMonthly Sales Report for 2022:\n\n");
    printf("%-15s%-10s\n\n", "Months", "Sales");
    for (int i = 0; i < 12; i++){
        printf("%-15s%-10.2f\n", months[i], data[i]);
    }
// this prints the 6 months moving average
    printf("----------------------------------------------");
     moving_average( data,  months);
//the following code prints the sales summary including min, max and average
    printf("----------------------------------------------");
    printf("\nSales Summary:\n\n");
     min( data,  months);
     max( data,  months);
     average(data);
//this prints the sales report highest to lowest
    printf("----------------------------------------------");
    printf("\nSales Report (Highest to Lowest)\n\n");
    printf("%-15s%-10s\n\n", "Months", "Sales");
     hightolow(data, months);
    for (int i = 11; i > -1 ; i--){
        printf("%-15s%-10.2f\n", months[i], data[i]);
    }
    return 0;
    }

void hightolow(double data[], char *months[]){
    int temp, i, j, k;
    char *tempm;
    for (j = 0; j < 12; ++j){
        for (k = j+1; k< 12; ++k){
            if (data[j] > data[k]){
                temp = data[j];
                tempm = months[j];
                data[j] = data[k];
                months[j] = months[k];
                data[k] = temp;
                months[k] = tempm;
            }
        }
    }
}

void min(double data[], char *months[]){
    hightolow(data, months);
    printf("%-17s%-10.2f", "Minimum Sales:", data[0]);
    printf("(");
    printf(months[0]);
    printf(")\n");
}

void max(double data[], char *months[]){
    hightolow(data, months);
    printf("%-17s%-10.2f", "Maximum Sales:", data[11]);
    printf("(");
    printf(months[11]);
    printf(")\n");
}

void average(double data[]){
    int total = 0;
    for (int i = 0; i <12; i++){
        total += data[i];
    }
    double ave = total/12;
    printf("%-17s%-10.2f\n\n", "Average Sales:", ave);
}

void moving_average(double data[], char *months[]){
    double mov_ave[6];
    for (int i = 0; i <=6; i++){
        int total = 0;
        for (int j = i; j < i+ 6; j++){
            total += data[j];
        }
        mov_ave[i] = (float)total/6;
    }
    printf("\nSix-Month Moving Average Report:\n\n");
    for (int l = 0; l<=6; l++){
        printf("%-10s%-2s%-10s%s%.2f\n", months[l], "-", months[l+5], "$", mov_ave[l]);
    }
}
