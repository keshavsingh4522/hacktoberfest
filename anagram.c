#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

    if (sLen != tLen) {
        return false;
    }

    int charCount[26] = {0};

    for (int i = 0; i < sLen; i++) {
        charCount[s[i] - 'a']++;
    }

    for (int i = 0; i < tLen; i++) {
        charCount[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (charCount[i] != 0) {
            return false;
        }
    }

    return true;
}
