#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// function to decode the ciphertext. I utilized this after finding keys
string decode(string ciphertext, map<char, char> key) {
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += key[ciphertext[i]];
    }
    return plaintext;
}

int main() {
    
    // Key for the ciphertext. Change to bruteforce key as needed.
    map<char, char> key;
    key['A'] = 'E';
    key['B'] = 'A';
    key['C'] = 'J';
    key['D'] = 'Q';
    key['E'] = 'V';
    key['F'] = 'R';
    key['G'] = 'G';
    key['H'] = 'I';
    key['I'] = 'K';
    key['J'] = 'Z';
    key['K'] = 'F';
    key['L'] = 'P';
    key['M'] = 'C';
    key['N'] = 'H';
    key['O'] = 'N';
    key['P'] = 'S';
    key['Q'] = 'Y';
    key['R'] = 'W';
    key['S'] = 'D';
    key['T'] = 'U';
    key['U'] = 'X';
    key['V'] = 'B';
    key['W'] = 'M';
    key['X'] = 'L';
    key['Y'] = 'T';
    key['Z'] = 'O';

// Read the ciphertext from the file
string ciphertext = "";
ifstream file("Michael.txt");

if (file.is_open()) {
    string line;
    while (getline(file, line)) {
        ciphertext += line + '\n';
    }
    file.close();
}

// Decode the ciphertext
string plaintext = decode(ciphertext, key);

//Creating Decoded Text File
ofstream ItsDecoded;
ItsDecoded.open ("Decoded_Document.txt");
ItsDecoded << plaintext;
ItsDecoded.close();


// Frequency of each letter
map<char, int> frequency;
for (int i = 0; i < plaintext.length(); i++) {
    frequency[plaintext[i]]++;
}

// Print the frequency of each letter
cout << "Frequency of each letter:" << endl;
for (auto x : frequency) {
    cout << x.first << ": " << x.second << endl;
}

// Frequency of two letter combinations
map<string, int> combinations;
for (int i = 0; i < plaintext.length() - 1; i++) {
    combinations[plaintext.substr(i, 2)]++;
}

// Print the frequency of two letter combinations
cout << "\nFrequency of two letter combinations:" << endl;
for (auto x : combinations) {
    cout << x.first << ": " << x.second << endl;
}

return 0;

}
