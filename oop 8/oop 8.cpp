#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cmath> 
#include <windows.h> 

using namespace std;

int main() {
    SetConsoleCP(1251); // українська/російська локаль
    SetConsoleOutputCP(1251);

    int n = 10;
    int a = 10, b = 30; // межі інтервалу [a, b]
    vector<int> v(n);

    // Заповнення випадковими числами
    generate(v.begin(), v.end(), []() { return rand() % 100 - 50; }); // [-50;49]

    cout << "Початковий масив:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // 1. Знаходження максимального елемента
    auto max_it = max_element(v.begin(), v.end());
    cout << "Максимальний елемент: " << *max_it << endl;

    // 2. Сума елементів до останнього додатного
    auto last_positive = find_if(v.rbegin(), v.rend(), [](int x) { return x > 0; });
    int sum = 0;
    if (last_positive != v.rend()) {
        auto end_it = last_positive.base(); // перетворення до прямого ітератора
        sum = accumulate(v.begin(), end_it, 0);
    }
    cout << "Сума до останнього додатного елемента: " << sum << endl;

    // 3. Видалення елементів з модулем в [a, b]
    auto new_end = remove_if(v.begin(), v.end(), [a, b](int x) {
        return abs(x) >= a && abs(x) <= b;
        });

    int removed = distance(new_end, v.end());

    // Заповнення звільнених елементів нулями
    fill(new_end, v.end(), 0);

    cout << "Масив після видалення елементів з модулем в [" << a << "," << b << "] і заповнення нулями:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    system("pause");
    return 0;
}
