#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Car {
    string name;
    int year;
    double engineVolume;
    double price;

    Car(const string& n, int y, double ev, double p) :
        name(n), year(y), engineVolume(ev), price(p) {}

    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "Название: " << car.name << endl;
        os << "Год выпуска: " << car.year << endl;
        os << "Объем двигателя: " << car.engineVolume << " л" << endl;
        os << "Цена: " << car.price << " руб." << endl;
        return os;
    }
};

struct SortByName {
    bool operator()(const Car& car1, const Car& car2) {
        return car1.name < car2.name;
    }
};

struct SortByYear {
    bool operator()(const Car& car1, const Car& car2) {
        return car1.year < car2.year;
    }
};

struct SortByEngineVolume {
    bool operator()(const Car& car1, const Car& car2) {
        return car1.engineVolume < car2.engineVolume;
    }
};

struct SortByPrice {
    bool operator()(const Car& car1, const Car& car2) {
        return car1.price < car2.price;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    vector<Car> cars;

    while (true) {
        system("pause");
        system("cls");

        cout << "\tМеню:\t\n";
        cout << "1. Добавить автомобиль\n";
        cout << "2. Удалить автомобиль\n";
        cout << "3. Отобразить список автомобилей\n";
        cout << "4. Сортировка\n";
        cout << "5. Поиск\n";
        cout << "0. Выход\n";

        cout << "Введите ваш выбор: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            // Добавление автомобиля
            string name;
            int year;
            double engineVolume;
            double price;

            cout << "Введите название автомобиля: ";
            cin.ignore(); 
            getline(cin, name);

            cout << "Введите год выпуска: ";
            cin >> year;

            cout << "Введите объем двигателя (в литрах): ";
            cin >> engineVolume;

            cout << "Введите цену: ";
            cin >> price;

            cars.push_back(Car(name, year, engineVolume, price));
            cout << "Автомобиль добавлен.\n";
            break;
        }

        case 2: {
            // Удаление автомобиля из вектора
            if (cars.empty()) {
                cout << "Список автомобилей пуст.\n";
                break;
            }

            cout << "Введите название автомобиля для удаления: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cars.erase(remove_if(cars.begin(), cars.end(),
                [&name](const Car& car) { 
                    return car.name == name; 
                }), cars.end());

            cout << "Автомобиль удален.\n";
            break;
        }

        case 3: {
            // Вывод списка автомобилей
            if (cars.empty()) {
                cout << "Список автомобилей пуст.\n";
                break;
            }

            cout << "Список автомобилей:\n";
            for (const Car& car : cars) {
                cout << car << endl;
            }
            break;
        }

        case 4: {
            // Сортировка
            if (cars.empty()) {
                cout << "Список автомобилей пуст.\n";
                break;
            }

            cout << "Выберите параметр для сортировки:\n";
            cout << "1. Название\n";
            cout << "2. Год выпуска\n";
            cout << "3. Объем двигателя\n";
            cout << "4. Цена\n";
            cout << "Введите ваш выбор: ";

            int sortChoice;
            cin >> sortChoice;

            switch (sortChoice) {
            case 1:
                sort(cars.begin(), cars.end(), SortByName());
                break;
            case 2:
                sort(cars.begin(), cars.end(), SortByYear());
                break;
            case 3:
                sort(cars.begin(), cars.end(), SortByEngineVolume());
                break;
            case 4:
                sort(cars.begin(), cars.end(), SortByPrice());
                break;
            default:
                cout << "Неверный выбор.\n";
                break;
            }

            cout << "Список автомобилей отсортирован.\n";
            break;
        }

        case 5: {
            // Поиск
            if (cars.empty()) {
                cout << "Список автомобилей пуст.\n";
                break;
            }

            cout << "Выберите параметр для поиска:\n";
            cout << "1. Название\n";
            cout << "2. Год выпуска\n";
            cout << "3. Объем двигателя\n";
            cout << "4. Цена\n";
            cout << "Введите ваш выбор: ";

            int searchChoice;
            cin >> searchChoice;

            switch (searchChoice) {
            case 1: {
                cout << "Введите название автомобиля для поиска: ";
                string name;
                cin.ignore();
                getline(cin, name);

                auto it = find_if(cars.begin(), cars.end(),
                    [&name](const Car& car) { 
                        return car.name == name; 
                    });

                if (it != cars.end()) {
                    cout << "Найденный автомобиль:\n";
                    cout << *it << endl;
                }
                else {
                    cout << "Автомобиль не найден.\n";
                }
                break;
            }

            case 2: {
                cout << "Введите год выпуска для поиска: ";
                int year;
                cin >> year;

                auto it = find_if(cars.begin(), cars.end(),
                    [&year](const Car& car) { 
                        return car.year == year; 
                    });

                if (it != cars.end()) {
                    cout << "Найденный автомобиль:\n";
                    cout << *it << endl;
                }
                else {
                    cout << "Автомобиль не найден.\n";
                }
                break;
            }

            case 3: {
                cout << "Введите объем двигателя (в литрах) для поиска: ";
                double engineVolume;
                cin >> engineVolume;

                auto it = find_if(cars.begin(), cars.end(),
                    [&engineVolume](const Car& car) { 
                        return car.engineVolume == engineVolume; 
                    });

                if (it != cars.end()) {
                    cout << "Найденный автомобиль:\n";
                    cout << *it << endl;
                }
                else {
                    cout << "Автомобиль не найден.\n";
                }
                break;
            }

            case 4: {
                cout << "Введите цену для поиска: ";
                double price;
                cin >> price;

                auto it = find_if(cars.begin(), cars.end(),
                    [&price](const Car& car) { 
                        return car.price == price; 
                    });

                if (it != cars.end()) {
                    cout << "Найденный автомобиль:\n";
                    cout << *it << endl;
                }
                else {
                    cout << "Автомобиль не найден.\n";
                }
                break;
            }

            default:
                cout << "Неверный выбор.\n";
                break;
            }

            break;
        }

        case 0:
            cout << "До свидания!\n";
            return 0;

        default:
            cout << "Неверный выбор.\n";
            break;
        }
    }

    return 0;
}