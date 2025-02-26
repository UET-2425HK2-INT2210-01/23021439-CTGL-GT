
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for (int i = s.size();i >= 0;i--) {
        cout << (char)s[i];
    }
    return 0;
}

