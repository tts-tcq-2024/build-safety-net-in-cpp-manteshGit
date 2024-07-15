#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

char encodeDigit(char letter) {
    static const std::unordered_map<char, char> encoding {
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
        {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'},
        {'s', '2'}, {'x', '2'}, {'z', '2'},
        {'d', '3'}, {'t', '3'},
        {'l', '4'},
        {'m', '5'}, {'n', '5'},
        {'r', '6'}
    };

    auto it = encoding.find(letter);
    return (it == encoding.end()) ? '-' : it->second;
}

std::string generateSoundex(const std::string& word) {
    if (word.empty()) return "";

    std::string encoded = "";
    encoded += std::toupper(word.front()); // Step 1: Retain the first letter

    char lastDigit = '-';
    char prevEncodedDigit = '-';
    bool isFirstLetter = true;

    for (size_t i = 1; i < word.length() && encoded.length() < 4; ++i) {
        char currentLetter = std::tolower(word[i]);
        char encodedDigit = encodeDigit(currentLetter);

        if (encodedDigit == '-') {
            continue; // Skip vowels and unsupported characters
        }

        // Step 2: Encode consonants and handle adjacent letters rule
        if (isFirstLetter || encodedDigit != prevEncodedDigit) {
            encoded += encodedDigit;
        }

        isFirstLetter = false;
        prevEncodedDigit = encodedDigit;
    }

    // Step 3: Pad with zeros if necessary
    while (encoded.length() < 4) {
        encoded += '0';
    }

    return encoded;
}
