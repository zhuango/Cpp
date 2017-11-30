#include <iostream>

using namespace std;

int main(void)
{
    char *dynChars = new char[10];
    cin >> dynChars;
    cin.ignore();
    cout << dynChars;
    cout << endl;

    cout << "Input string length: ";
    size_t len;
    cin >> len;
    cin.ignore();

    char *ca = new char[len+ 1];
    cin.get(ca, len + 1);
    cout << "The input string is: \"" << ca << "\"" << endl;
    return 0;
}