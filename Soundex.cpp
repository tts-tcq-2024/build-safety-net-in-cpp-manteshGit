#include <iostream>
#include <string>
#include <unordered_map>

char retainFirstLetter(const std::string &name) {
    return toupper(name[0]);
}

std::string getSoundexCode(const std::string &name) {
    // Define the Soundex digit mapping
    const std::unordered_map<char, char> soundex_mapping = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    std::string encoded_name;
    for (size_t i = 1; i < name.length(); ++i) {
        char upper_char = toupper(name[i]);
        if (soundex_mapping.find(upper_char) != soundex_mapping.end()) {
            encoded_name += soundex_mapping.at(upper_char);
        }
    }
    return encoded_name;
}

std::string removeConsecutiveDuplicates(const std::string &encoded_name) {
    std::string result;
    result += encoded_name[0];
    for (size_t i = 1; i < encoded_name.length(); ++i) {
        if (encoded_name[i] != encoded_name[i - 1]) {
            result += encoded_name[i];
        }
    }
    return result;
}

std::string finalizeSoundex(const char first_letter, const std::string &encoded_name) {
    std::string result(1, first_letter);
    result += encoded_name;
    result = result.substr(0, 4);
    while (result.length() < 4) {
        result += '0';
    }
    return result;
}

std::string generateSoundex(const std::string &name) {
    if (name.empty()) return "";
    
    char first_letter = retainFirstLetter(name);
    std::string encoded_name = getSoundexCode(name);
    encoded_name = removeConsecutiveDuplicates(encoded_name);
    return finalizeSoundex(first_letter, encoded_name);
}
