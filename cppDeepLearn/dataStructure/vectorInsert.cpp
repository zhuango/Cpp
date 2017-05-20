#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    string s = "";
    vector<char> c_vec(1, 'a');
    s.insert(s.begin(), c_vec.begin(), c_vec.end());
    // insert 5 ! at the end of 's'.
    s.insert(s.size(), 5, '!');
    cout << s << endl;

    // erase the last five characters from s.
    s.erase(s.size() - 5, 5);
    cout << s << endl;

    s = "";
    const char *cp = "Stately, plump Buck.";
    s.assign(cp, 7);
    cout << s << endl;
    // insert first seven chars of cp to s.
    s.insert(s.size(), cp + 7);
    cout << s << endl;

    s = "C++ Primer";
    string s2 = s;
    s.insert(s.size(), " 4th Ed.");
    s2.append(" 4th Ed.");
    cout << s << " " << s2 << endl;

    s.erase(11, 3);
    cout << s << endl;
    s.insert(11, "5th");
    cout << s << endl;

    s2.replace(11, 3, "5th eee");
    cout << s2 << endl;

    auto pos = s2.find("5th");
    if (pos != string::npos)
    {
        s2.replace(pos, 3, "Fifth");
    }
    {
		cout << "something's wrong, s2 is: " << s2 << endl;
    }
	cout << s << " " << s2 << endl;
    
    return 0;
}