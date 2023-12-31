



////_______________________________Question no 01;_______________________________
//
//#include <stdio.h>
//#include <math.h>
//#include <stdbool.h>
//
//#define cost_per_portal  10000
//#define cost_per_ship 50000
//#define cost_per_distance 1000
//
//
//#include <stdio.h>
//#include <stdbool.h>
//
//bool canPlaceBox(char box1, char  box2) {
//    if (box2 == 'B') {
//        if (box1 == 'R') {
//            return true;
//        } else {
//            return false;
//        }
//    } else if (box2 == 'G') {
//        if (box1 == 'R') {
//            return true;
//        } else if (box1 == 'B') {
//            return true;
//        } else {
//            return false;
//        }
//    } else {
//        return false;
//    }
//}
//
//const double costOfTeleportationPortals(int num_portals) {
//    return num_portals * cost_per_portal;
//}
//
//const double costOfSpaceShips(int num_ships, double distance) {
//    return num_ships * cost_per_ship + distance * cost_per_distance;
//}
//
//double totalTransportationCost(int num_portals, int num_ships, double distance) {
//    double cost_portals = costOfTeleportationPortals(num_portals);
//    double cost_ships = costOfSpaceShips(num_ships, distance);
//    return cost_portals + cost_ships;
//}
//
//int main() {
//    int num_portals = 1000;
//    int num_ships = 2000;
//    double distance = 10000;
//    double total_cost = totalTransportationCost(num_portals, num_ships, distance);
//    printf("The total cost of transportation is: %f", total_cost);
//    return 0;
//}
//
////_______________________________Question no 02;_______________________________
//#include <stdio.h>
//
//int formulaOne(int a, int b) {
//    return a + b;
//}
//
//int formulaTwo(int c) {
//    return c * c;
//}
//
//int calc(int a, int b) {
//    return a + b;
//}
//
//int main() {
//    int result = calc(formulaOne(10, 20), formulaTwo(40)) + calc(formulaOne(30, 50), formulaTwo(60));
//    printf("Result: %d\n", result);
//    return 0;
//}
////_______________________________Question no 03s;_______________________________
//#include <stdio.h>
//
//float calculate_revenue(float revenue) {
//    return revenue;
//}
//
//float calculate_expenses(float expenses) {
//    return expenses;
//}
//
//float calculate_net_profit(float revenue, float expenses) {
//    return revenue - expenses;
//}
//
//float calculate_profit_margin(float revenue, float expenses) {
//    if (revenue == 0) {
//        printf("Error: Division by zero.\n");
//        return -1.0;
//    }
//    return calculate_net_profit(revenue, expenses) / revenue;
//}
//
//float calculate_roi(float revenue, float expenses) {
//    if (expenses == 0) {
//        printf("Error: Division by zero.\n");
//        return -1.0;
//    }
//    return calculate_net_profit(revenue, expenses) / expenses;
//}
//
//int main() {
//    float revenue, expenses;
//    printf("Enter the revenue: ");
//    scanf("%f", &revenue);
//    printf("Enter the expenses: ");
//    scanf("%f", &expenses);
//
//    printf("Total revenue: %.2f\n", calculate_revenue(revenue));
//    printf("Total expenses: %.2f\n", calculate_expenses(expenses));
//    printf("Net profit: %.2f\n", calculate_net_profit(revenue, expenses));
//    float profit_margin = calculate_profit_margin(revenue, expenses);
//    if (profit_margin == -1.0) {
//        printf("Error: Division by zero.\n");
//        return 1;
//    }
//    printf("Profit margin: %.2f\n", profit_margin);
//    float roi = calculate_roi(revenue, expenses);
//    if (roi == -1.0) {
//        printf("Error: Division by zero.\n");
//        return 1;
//    }
//    printf("ROI: %.2f\n", roi);
//
//    return 0;
//}
////_______________________________Question no 04s;_______________________________
//#include <stdio.h>
//#include <stdbool.h>
//
//bool canPlaceBoxes(char box1, char box2) {
//    // If both boxes are not the same color, they can be placed
//    if ((box1 == 'R' || box1 == 'r') && (box2 == 'B' || box2 == 'b')) {
//        return true;
//    } else if ((box1 == 'B' || box1 == 'b') && (box2 == 'R' || box2 == 'r')) {
//        return true;
//    } else {
//        return false;
//    }
//}
//
//int main() {
//    char box1, box2;
//
//    printf("Enter the color of the first box (r for red and b for blue) : ");
//    scanf("%c", &box1);
//    printf("Enter the color of the second box (r for red and b for blue) : ");
//    scanf("%c", &box2);
//
//    if (canPlaceBoxes(box1, box2)) {
//        printf("The boxes can be placed.\n");
//    } else {
//        printf("Invalid placement.\n");
//    }
//
//    return 0;
//}
//
