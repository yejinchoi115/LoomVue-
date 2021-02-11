#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    const int SIZE_ARRAY = 10;
    const int DECI_SIZE = 3;
    const int WIDTH_SIZE = 9;
    double hotPlate[SIZE_ARRAY][SIZE_ARRAY] = {0.0};
    double secondPlate[SIZE_ARRAY][SIZE_ARRAY] = {0.0};

    cout << "Hotplate simulator" << endl;
    cout << endl;

    //initial plate values
    cout << "Printing the initial plate values..." << endl;

    for (int i = 0; i < SIZE_ARRAY; ++i) {
        for (int j = 0; j < SIZE_ARRAY - 1; ++j) {
            if (((i == 0) || (i == 9)) && ((j > 0) && (j < 9))) {
                hotPlate[i][j] = 100.000;
            } else {
                hotPlate[i][j] = 0.000;
            }
            cout << fixed;
            cout << setprecision(DECI_SIZE) << setw(WIDTH_SIZE) << hotPlate[i][j] << ",";
        }
        cout << setw(WIDTH_SIZE) << hotPlate[i][9];
        cout << endl;
    }
    cout << endl;

    //secondPlate
    for (int i = 0; i < SIZE_ARRAY; ++i) {
        for (int j = 0; j < SIZE_ARRAY; ++j) {
            if (((i == 0) || (i == 9)) && ((j > 0) && (j < 9))) {
                secondPlate[i][j] = 100.000;
            } else {
                secondPlate[i][j] = 0.000;
            }
        }
    }

    //After one iteration
    cout << "Printing plate after one iteration..." << endl;

    for (int i = 0; i < SIZE_ARRAY; ++i) {
        for (int j = 0; j < SIZE_ARRAY - 1; ++j) {
            if (i > 0 && i < SIZE_ARRAY - 1 && j > 0 && j < SIZE_ARRAY - 1) {
                hotPlate[i][j] = (secondPlate[i - 1][j] + secondPlate[i][j - 1] + secondPlate[i + 1][j] +
                                  secondPlate[i][j + 1]) / 4;
            } else {
                hotPlate[i][j] = secondPlate[i][j];
            }
            cout << fixed;
            cout << setprecision(DECI_SIZE) << setw(WIDTH_SIZE) << hotPlate[i][j] << ",";
        }
        cout << setw(WIDTH_SIZE) << hotPlate[i][9];
        cout << endl;
    }
    cout << endl;


    //Final Plate
    cout << "Printing final plate..." << endl;
    cout << setprecision(DECI_SIZE);
    double maxVal;
    double changedPlate[SIZE_ARRAY][SIZE_ARRAY] = {0.000};

    do {
        maxVal = 0.000;

        for (int i = 0; i < SIZE_ARRAY; ++i) {
            for (int j = 0; j < SIZE_ARRAY; ++j) {
                changedPlate[i][j] = hotPlate[i][j];
            }
        }

        for (int i = 0; i < SIZE_ARRAY; ++i) {
            for (int j = 0; j < SIZE_ARRAY; ++j) {
                if (i > 0 && i < SIZE_ARRAY - 1 && j > 0 && j < SIZE_ARRAY - 1) {
                    hotPlate[i][j] = (changedPlate[i - 1][j] + changedPlate[i][j - 1] + changedPlate[i + 1][j] +
                            changedPlate[i][j + 1]) / 4;
                }
                else {
                    hotPlate[i][j] = secondPlate[i][j];
                }
            }
        }

        for (int i = 0; i < SIZE_ARRAY; ++i) {
            for (int j = 0; j < SIZE_ARRAY; ++j) {
                if (maxVal < hotPlate[i][j] - changedPlate[i][j]) {
                    maxVal = hotPlate[i][j] - changedPlate[i][j];
                }
            }
        }

    } while (maxVal >= 0.1);


    for (int i = 0; i < SIZE_ARRAY; ++i) {
        for (int j = 0; j < SIZE_ARRAY - 1; ++j) {
            cout << fixed;
            cout << setprecision(DECI_SIZE) << setw(WIDTH_SIZE) << hotPlate[i][j] << ",";
        }
        cout << setw(WIDTH_SIZE) << hotPlate[i][9];
        cout << endl;
    }
    cout << endl;

    cout << "Writing final plate to \"Hotplate.csv\"..." << endl;
    ofstream outFS;
    outFS.open("Hotplate.csv");

    for (int i = 0; i < SIZE_ARRAY; ++i) {
        for (int j = 0; j < SIZE_ARRAY; ++j) {
            outFS << fixed;
            outFS << setprecision(DECI_SIZE) << setw(WIDTH_SIZE) << hotPlate[i][j];
            if (j != SIZE_ARRAY - 1) {
                outFS << ",";
            }
        }
    }
    outFS.close();


    cout << endl;
    cout << "Printing input plate after 3 updates..." << endl;

    ifstream inFS;
    inFS.open("Inputplate.txt");
    double inputPlate[SIZE_ARRAY][SIZE_ARRAY];
    for (int i = 0; i < SIZE_ARRAY ; ++i) {
        for (int j = 0; j < SIZE_ARRAY; ++j) {
            inFS >> inputPlate[i][j];
        }

    }

    for (int k = 0; k < 3; ++k) {

        maxVal = 0.000;

        for (int i = 0; i < SIZE_ARRAY; ++i) {
            for (int j = 0; j < SIZE_ARRAY; ++j) {
                changedPlate[i][j] = inputPlate[i][j];
            }
        }

        for (int i = 0; i < SIZE_ARRAY; ++i) {
            for (int j = 0; j < SIZE_ARRAY; ++j) {
                if (i > 0 && i < SIZE_ARRAY - 1 && j > 0 && j < SIZE_ARRAY - 1) {
                    inputPlate[i][j] = (changedPlate[i - 1][j] + changedPlate[i][j - 1] + changedPlate[i + 1][j] +
                                        changedPlate[i][j + 1]) / 4;
                } else {
                    inputPlate[i][j] = secondPlate[i][j];
                }
            }
        }
    }

    for (int i = 0; i < SIZE_ARRAY; ++i) {
        for (int j = 0; j < SIZE_ARRAY - 1; ++j) {
            cout << fixed;
            cout << setprecision(DECI_SIZE) << setw(WIDTH_SIZE) << inputPlate[i][j] << ",";
        }
        cout << setw(WIDTH_SIZE) << inputPlate[i][9];
        cout << endl;
    }

    inFS.close();



    return 0;
}

/*Hi Yejin*/
/Wow this is so cool!!!/
