#include <iostream>
#include "Soundex.h"
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> 

using namespace std;

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexCodes = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    
    c = toupper(c); // Convert character to uppercase
    
    auto it = soundexCodes.find(c);
    if (it != soundexCodes.end()) {
        return it->second;
    } else {
        return '0'; // Default case for non-mapped characters
    }
}

std::string getSoundex(const std::string& name) {
    std::unordered_set<char> soundex;
    soundex.insert(toupper(name[0]));
    
    for (size_t i = 1; i < name.length() && soundex.size() < 4; ++i) {
        soundex.insert(getSoundexCode(name[i]));
    }
    soundex.erase(0);
    
    std::string result;
    for (char c : soundex) {
        result += c;
    }
    
    std::reverse(result.begin(), result.end());
    result.resize(4, '0'); // Resize to ensure the Soundex code is exactly 4 characters
    return result;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    
    return getSoundex(name);
}
