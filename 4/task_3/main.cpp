#include <iostream>


void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    if (actual_size == 0) {
        std::cout << " _";
    }
    else {
        for (int i = 0; i < actual_size; ++i) {
            if (i > logical_size - 1) {
                std::cout << " _";
            }
            else {
                std::cout << " " << arr[i];
            }
        }
    }
    std::cout << std::endl;
}


void fill_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < logical_size; ++i) {
        std::cout << "������� arr[" << i << "]: ";
        std::cin >> arr[i];
    }
}


void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
    if (logical_size - 1 <= actual_size / 3) {
        actual_size /= 3;
    }
    
    int* new_arr = new int[actual_size] {0};
    for (int i = 1; i < logical_size; ++i) {
        new_arr[i - 1] = arr[i];
    }
    --logical_size;
    delete[] arr;
    arr = new_arr;
}


int main() {
    system("chcp 1251");

    int actual_size{}, logical_size{};
    std::string answer{};

    while (true) {
        std::cout << "������� �������c��� ������ �������: ";
        std::cin >> actual_size;

        std::cout << "������� ���������� ������ �������: ";
        std::cin >> logical_size;

        if (logical_size > actual_size) {
            std::cout << "������! ���������� ������ ������� �� ����� ��������� �����������!"
                << std::endl;
            continue;
        }

        break;
    }

    int* arr = new int[actual_size] {0};

    fill_dynamic_array(arr, logical_size, actual_size);

    std::cout << "������������ ������:";
    print_dynamic_array(arr, logical_size, actual_size);

    while (true) {
        std::cout << "������� ������ �������? ";
        std::cin >> answer;

        if (answer == "��" || answer == "��") {
            if (actual_size > 0) {
                remove_dynamic_array_head(arr, logical_size, actual_size);
                std::cout << "������������ ������:";
                print_dynamic_array(arr, logical_size, actual_size);
            }
            else {
                std::cout << "���������� ������� ������ �������, ��� ��� ������ ������. �� ��������!"
                    << std::endl;
                return 0;
            }
        }
        else if (answer == "���" || answer == "���") {
            std::cout << "�������! ��� ������������ ������:";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
    }

    delete[] arr;

    return 0;
}