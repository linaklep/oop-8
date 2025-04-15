#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cmath> 
#include <windows.h> 

using namespace std;

int main() {
    SetConsoleCP(1251); // ���������/�������� ������
    SetConsoleOutputCP(1251);

    int n = 10;
    int a = 10, b = 30; // ��� ��������� [a, b]
    vector<int> v(n);

    // ���������� ����������� �������
    generate(v.begin(), v.end(), []() { return rand() % 100 - 50; }); // [-50;49]

    cout << "���������� �����:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // 1. ����������� ������������� ��������
    auto max_it = max_element(v.begin(), v.end());
    cout << "������������ �������: " << *max_it << endl;

    // 2. ���� �������� �� ���������� ���������
    auto last_positive = find_if(v.rbegin(), v.rend(), [](int x) { return x > 0; });
    int sum = 0;
    if (last_positive != v.rend()) {
        auto end_it = last_positive.base(); // ������������ �� ������� ���������
        sum = accumulate(v.begin(), end_it, 0);
    }
    cout << "���� �� ���������� ��������� ��������: " << sum << endl;

    // 3. ��������� �������� � ������� � [a, b]
    auto new_end = remove_if(v.begin(), v.end(), [a, b](int x) {
        return abs(x) >= a && abs(x) <= b;
        });

    int removed = distance(new_end, v.end());

    // ���������� ��������� �������� ������
    fill(new_end, v.end(), 0);

    cout << "����� ���� ��������� �������� � ������� � [" << a << "," << b << "] � ���������� ������:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    system("pause");
    return 0;
}
