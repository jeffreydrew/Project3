

#include <iostream>
#include <vector> 
#include <string>
#include <iomanip>
#include <sstream>
#include <tuple>
using namespace std;

int main()
{
    vector<string> encryptedPasswords = { "fksjfld", "kdsjfl", "@ioihdsio8", "ua8fdhvi!" };

    for (auto str : encryptedPasswords) {
        //summing all the characters
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            char x = str.at(i);
            sum += int(x);
        }
        cout << "Sum: " << sum << endl;
        //doing the 3 multiples
        string strSum = to_string(sum);
        string threeSum = "";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < strSum.length() - 1; j++) {
                threeSum += strSum.substr(j, j + 1);
            }
        }
        cout << "Three Sum: " << threeSum << endl;

        //convert the three sum to hexstring 

        //first convert string back to an integer
        int hexInt = stoi(threeSum);
        cout << "Is this right: " << hexInt << endl;

        //next convert integer to hexstring
        stringstream stream;
        stream << hex << hexInt;
        string hexResult(stream.str());
        cout << "Is this a string: " << hexResult << endl;

        //take the fist 6 characters and break it up into the 
        tuple<unsigned int, unsigned int, unsigned int> rgb;

        //red 
        unsigned int red = 0;
        istringstream r(hexResult.substr(0, 2));
        r >> hex >> red;
        cout << "This is red hex couple: " << hexResult.substr(0, 2) << endl;
        //green
        unsigned int green = 0;
        istringstream g(hexResult.substr(2, 2));
        g >> hex >> green;
        cout << "This is green hex couple: " << hexResult.substr(2, 2) << endl;
        //blue
        unsigned int blue = 0;
        istringstream b(hexResult.substr(4, 4).substr(0, 2));
        b >> hex >> blue;
        cout << "This is blue hex couple: " << hexResult.substr(4, 4).substr(0, 2) << endl;

        rgb = make_tuple(red, green, blue);
        cout << std::get<0>(rgb)
            << " " << std::get<1>(rgb)
            << " " << std::get<2>(rgb)
            << std::endl;
    }

}
