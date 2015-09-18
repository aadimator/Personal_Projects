#include "BarChart.h"

using namespace std;

int main() {
    BarChart test ;
    test.setPath(); //or you can use setPath("filePath"), remember to use '\\'
    if (test.readFile()) {
        test.help();
        string chars = "";
        cout << ">>> ";
        while (getline(cin, chars)) {
            if (chars == "quit") break;
            if (chars == "help") {
                test.help();
                cout << ">>> ";
                continue;
            }
            if (chars != "") {
                test.compareCharacters(chars);
            }
            cout << ">>> ";
        }
        cout << "Total characters in the file : " << test.getNumOfCharacters() << endl;
    }

    return 0;
}