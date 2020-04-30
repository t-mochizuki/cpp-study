#include <iostream>

using namespace std;

int min(int X, int Y) {
    return X < Y ? X : Y;
}

struct meal_t {
    int cost;
    int satisfiable;
};

int solver(int cost, int N, int H, meal_t normal_meal, meal_t simple_meal, meal_t no_meal) {
    if (N == 0) {
        return cost;
    }

    if (H + no_meal.satisfiable <= 0) {
        int simple_meal_cost = solver(cost + simple_meal.cost, N - 1, H + simple_meal.satisfiable, normal_meal, simple_meal, no_meal);
        int normal_meal_cost = solver(cost + normal_meal.cost, N - 1, H + normal_meal.satisfiable, normal_meal, simple_meal, no_meal);
        return min(simple_meal_cost, normal_meal_cost);
    } else {
        return solver(cost, N - 1, H + no_meal.satisfiable, normal_meal, simple_meal, no_meal);
    }
}

int main() {
    int N, H; // 日数, 満腹度
    cin >> N >> H;

    int A, B, C, D, E;
    cin >> A >> B;
    meal_t normal_meal = {A, B};
    cin >> C >> D;
    meal_t simple_meal = {C, D};
    cin >> E;
    meal_t no_meal = {0, (-1) * E};

    int cost = solver(0, N, H, normal_meal, simple_meal, no_meal);

    cout << cost << endl;

    return 0;
}
