#include <stdio.h>

int new_pizza_price(int avg_x, int avg_y, int avg_xy, int avg_x_squr, int avg_x_squr_last, int new_size_of_pizza);
double R_Squared_value(int m, int c, int pizza_size[], int pizza_price[], int avg_y);

int main(){
    int pizza_size[] = {6, 8, 12, 14, 18};
    int pizza_price[] = {350, 775, 1150, 1395, 1675};
    int new_size_of_pizza;
    int n = 5;  // number of data points

    printf("Enter your pizza size: ");
    scanf("%d", &new_size_of_pizza);

    int sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squ = 0;
    double avg_x, avg_y, avg_xy, avg_x_squ;

    for(int i = 0; i < n; i++){
        sum_x += pizza_size[i];
        sum_y += pizza_price[i];
        sum_xy += pizza_size[i] * pizza_price[i];
        sum_x_squ += pizza_size[i] * pizza_size[i];
    }

    avg_x = sum_x / (double)n;
    avg_y = sum_y / (double)n;
    avg_xy = sum_xy / (double)n;
    avg_x_squ = sum_x_squ / (double)n;

    int m = (avg_xy - avg_x * avg_y) / (avg_x_squ - avg_x * avg_x);
    int c = avg_y - m * avg_x;

    int new_price_of_pizza = m * new_size_of_pizza + c;

    printf("%d inch pizza price is %d.\n", new_size_of_pizza, new_price_of_pizza);

    double r_squared = R_Squared_value(m, c, pizza_size, pizza_price, avg_y);
    printf("R-Squared Value is %0.3lf.\n", r_squared);

    return 0;
}

double R_Squared_value(int m, int c, int pizza_size[], int pizza_price[], int avg_y){
    int n = 5;
    double ss_tot = 0, ss_res = 0;

    for(int i = 0; i < n; i++){
        double y_pred = m * pizza_size[i] + c;
        ss_res += (pizza_price[i] - y_pred) * (pizza_price[i] - y_pred);
        ss_tot += (pizza_price[i] - avg_y) * (pizza_price[i] - avg_y);
    }

    double r_squared = 1 - (ss_res / ss_tot);
    return r_squared;
}
