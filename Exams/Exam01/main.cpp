#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string Translate()
{
    string x, a[26];
    a[26] = {"ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO", "FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIETT", "KILO", "LIMA", "MIKE", "NOVEMBER", "OSCAR", "PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO", "UNIFORM", "VICTOR", "WHISKEY", "X-RAY", "YANKEE", "ZULU"};
    cout << "Provide 4 letters: ";
    cin >> x;

    for(int i = 0; i < 4; i += 1)
    {
        // Check every individual character of the string x.

        if(x = "a" || x = "A"){
            cout << a[0] << " ";
        }else if(x = "b" || x = "B"){
            cout << a[1] << " ";
        }else if(x = "c" || x = "C"){
            cout << a[2] << " ";
        }else if(x = "d" || x = "D"){
            cout << a[3] << " ";
        }else if(x = "e" || x = "E"){
            cout << a[4] << " ";
        }else if(x = "f" || x = "F"){
            cout << a[5] << " ";
        }else if(x = "g" || x = "G"){
            cout << a[6] << " ";
        }else if(x = "h" || x = "H"){
            cout << a[7] << " ";
        }else if(x = "i" || x = "I"){
            cout << a[8] << " ";
        }else if(x = "j" || x = "J"){
            cout << a[9] << " ";
        }else if(x = "k" || x = "K"){
            cout << a[10] << " ";
        }else if(x = "l" || x = "L"){
            cout << a[11] << " ";
        }else if(x = "m" || x = "M"){
            cout << a[12] << " ";
        }else if(x = "n" || x = "N"){
            cout << a[13] << " ";
        }else if(x = "o" || x = "O"){
            cout << a[14] << " ";
        }else if(x = "p" || x = "P"){
            cout << a[15] << " ";
        }else if(x = "q" || x = "Q"){
            cout << a[16] << " ";
        }else if(x = "r" || x = "R"){
            cout << a[17] << " ";
        }else if(x = "s" || x = "S"){
            cout << a[18] << " ";
        }else if(x = "t" || x = "T"){
            cout << a[19] << " ";
        }else if(x = "u" || x = "U"){
            cout << a[20] << " ";
        }else if(x = "v" || x = "V"){
            cout << a[21] << " ";
        }else if(x = "w" || x = "W"){
            cout << a[22] << " ";
        }else if(x = "x" || x = "X"){
            cout << a[23] << " ";
        }else if(x = "y" || x = "Y"){
            cout << a[24] << " ";
        }else if(x = "z" || x = "Z"){
            cout << a[25] << " ";
        }
    }
}

int main()
{

}