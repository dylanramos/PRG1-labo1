#include <iostream>
#include <string>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string convertNumberToBase(int number, int base) {
    string baseToDisplay = base < 10 ? "0" + to_string(base) : to_string(base);

    if (number == 0) {
        return "(0)" + baseToDisplay;
    }

    int quotient, remainder;
    string result, remainderToDisplay;

    quotient = number;

    while (quotient > 0) {
        remainder = quotient % base;
        quotient /= base;

        if (remainder > 9) {
            for (int i = 10; i < 36; ++i) {
                if (remainder == i) {
                    remainderToDisplay = ALPHABET[i - 10];
                    break;
                }
            }
        } else {
            remainderToDisplay = to_string(remainder);
        }

        result.insert(0, remainderToDisplay);
    }

    result = "(" + result + ")" + baseToDisplay;

    return result;
}

string createSpaces(int length) {
    string spaces;

    for (int i = 0; i < length; i++) {
        spaces.insert(i, " ");
    }

    return spaces;
}

int main() {
    int number;

    cout << "Entrez un nombre entier positif " << endl;
    cin >> number;
    cout << number;

    string firstResult = convertNumberToBase(number, 2);
    cout << " = " << firstResult << endl;

    for (int i = 3; i < 37; ++i) {
        string result = convertNumberToBase(number, i);
        string spacesBeforeEqual = createSpaces(to_string(number).length());
        string spacesAfterEqual = createSpaces(firstResult.length() - result.length());

        cout << spacesBeforeEqual << " = " << spacesAfterEqual << result << endl;
    }

    return 0;
}
