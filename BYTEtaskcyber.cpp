#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

map<char, int> base64_map;

void initBase64Map() {
    for (int i = 0; i < base64_chars.size(); i++) {
        base64_map[base64_chars[i]] = i;
    }
}

string hexToStr(const string& hexInput) {
    string result;
    for ( size_t i = 0; i < hexInput.length(); i += 2) {
        string byte = hexInput.substr(i, 2);
        char chr = static_cast<char>(stoi(byte, nullptr, 16));
        result.push_back(chr);
    }
    return result;
}

string reverseStr(const string& inputStr) {
    string reversed = inputStr;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

string shift(const string& inputStr, int amount) {
    string result;
    for (char c : inputStr) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char offset = (c - base + amount) % 26;
            if (offset < 0) offset += 26;
            result += base + offset;
        } else {
            result += c;
        }
    }
    return result;
}



int main() {
    string xoredHex = "3d305759306b474e65674663776233577955564c7845465974553361343831597734567a306b464c724147647972335967776c51";

    string asciiStr = hexToStr(xoredHex);
    cout << "ASCII String: " << asciiStr << endl;

    string reversedStr = reverseStr(asciiStr);
    cout << "Reversed String: " << reversedStr << endl;

    string shiftedStr = shift(reversedStr, 1);

    cout << "Shifted string: " << shiftedStr << endl;

    return 0;
}
