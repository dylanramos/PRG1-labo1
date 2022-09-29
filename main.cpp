#include <iostream>
#include <string>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string convertNumberToBase(unsigned number, unsigned base) {
    string baseToDisplay = base < 10 ? "0" + to_string(base) : to_string(base);

    if (number == 0) {
        return "(0)" + baseToDisplay;
    }

    unsigned quotient, remainder;
    string result, remainderToDisplay;

    quotient = number;

    while (quotient > 0) {
        remainder = quotient % base;
        quotient /= base;

        if (remainder > 9) {
            for (unsigned i = 10; i < 36; ++i) {
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

string createSpaces(unsigned length) {
    string spaces;

    for (unsigned i = 0; i < length; i++) {
        spaces.insert(i, " ");
    }

    return spaces;
}

int main() {
    unsigned number;

    cout << "Entrez un nombre entier positif " << endl;
    cin >> number;
    cout << number;

    string firstResult = convertNumberToBase(number, 2);
    cout << " = " << firstResult << endl;

    for (unsigned i = 3; i < 37; ++i) {
        string result = convertNumberToBase(number, i);
        string spacesBeforeEqual = createSpaces(to_string(number).length());
        string spacesAfterEqual = createSpaces(firstResult.length() - result.length());

        cout << spacesBeforeEqual << " = " << spacesAfterEqual << result << endl;
    }

    return 0;
}
