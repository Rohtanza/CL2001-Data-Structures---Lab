#include <iostream>
#include <ctime>

#define row 3
#define col 3
char rand_Char[] = {'x', '-'};
using namespace std;

class Game {
    char *ptr_grid;
    char *curr;
public:
    void start() {
        curr = ptr_grid;
    }

    Game() {
        ptr_grid = new char[row * col];
        start();
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                *(curr + i * col + j) = rand_Char[rand() % 2];
        *(curr + 1 * col + 1) = 'o';
    }

    void print() {
        start();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                cout << *(curr + i * col + j) << " ";
            cout << endl;
        }

    }

    void play() {
        start();
        int option = 0;
        cout << "1. Move Up" << endl << "2. Move Down" << endl << "3. Move right" << endl << "4. Move left" << endl;
        cin >> option;
        switch (option) {
            case 1:
                if (*(curr + 0 * col + 1) == 'x')
                    cout << "You've won" << endl;
                else
                    cout << "You've lost" << endl;
                break;
            case 2:
                if (*(curr + 2 * col + 1) == 'x')
                    cout << "You've won" << endl;
                else
                    cout << "You've lost" << endl;
                break;
            case 3:
                if (*(curr + 1 * col + 2) == 'x')
                    cout << "You've won" << endl;
                else
                    cout << "You've lost" << endl;
                break;
            case 4:
                if (*(curr + 1 * col + 0) == 'x')
                    cout << "You've won" << endl;
                else
                    cout << "You've lost" << endl;
                break;
            default:
                cout << "try with valid entries" << endl;

        }


    }

    ~Game() {
        delete[]ptr_grid;
    }
};


int main() {
    srand(time(NULL));
    Game game1;
    game1.print();
    game1.play();

    return 0;
}
