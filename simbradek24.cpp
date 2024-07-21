#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Character {
    string name;
    int age;
    int health;
    int happiness;
    int wealth;
};

void displayCharacter(Character character) {
    cout << "Имя: " << character.name << endl;
    cout << "Восраст: " << character.age << endl;
    cout << "Жизн: " << character.health << endl;
    cout << "щасте: " << character.happiness << endl;
    cout << "багатства: " << character.wealth << endl;
}

void work(Character &character) {
    character.wealth += 100;
    character.happiness -= 10;
    cout << "Ти пашол на работу и зарапотал 100 брад коинаф твайо щасте вирасло на 10." << endl;
}

void exercise(Character &character) {
    character.health += 10;
    cout << "Ти памалилса и тваио здарове падналас на 10." << endl;
}

void relax(Character &character) {
    character.happiness += 10;
    cout << "Ти адахнул и твайо щасте вирасло на 10." << endl;
}

void eatHealthy(Character &character) {
    character.health += 10;
    character.wealth -= 20;
    cout << "Ти сьел стероиди и твой здарове падналас на 10 Ти патрател 20 брадкоинав." << endl;
}

void eatUnhealthy(Character &character) {
    character.health -= 10;
    character.wealth -= 10;
    cout << "Ти пакурил сигарети брадстон сери твайо здарове панизилас на 10. Ти патрател $10." << endl;
}

int main() {
    srand(time(0)); // seed for random number generation

    Character character;
    cout << "введи имя сваеи макаке: ";
    cin >> character.name;
    character.age = 20;
    character.health = 100;
    character.happiness = 50;
    character.wealth = 1000;

    while (true) {
        displayCharacter(character);
        cout << "щдо ти хочиш сделат?" << endl;
        cout << "1. рапотат на заводи" << endl;
        cout << "2. памалитса" << endl;
        cout << "3. адахнут" << endl;
        cout << "4. сьест стероид" << endl;
        cout << "5. пакурит" << endl;
        cout << "6. вити" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                work(character);
                break;
            case 2:
                exercise(character);
                break;
            case 3:
                relax(character);
                break;
            case 4:
                eatHealthy(character);
                break;
            case 5:
                eatUnhealthy(character);
                break;
            case 6:
                return 0;
            default:
                cout << "ниправилни выпар динаху." << endl;
        }

        // simulate the passage of time
        character.age++;
        character.health -= rand() % 5; // random health decrease
        character.happiness -= rand() % 5; // random happiness decrease
        character.wealth -= rand() % 50; // random wealth decrease

        // check for game over
        if (character.health <= 0 || character.happiness <= 0 || character.wealth <= 0) {
            cout << "иплан ти здох" << endl;
            return 0;
        }
    }

    return 0;
}