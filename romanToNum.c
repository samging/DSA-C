int romanToInt(char* s) {
    int roman_values[256] = {0}; 
    roman_values['I'] = 1;
    roman_values['V'] = 5;
    roman_values['X'] = 10;
    roman_values['L'] = 50;
    roman_values['C'] = 100;
    roman_values['D'] = 500;
    roman_values['M'] = 1000;

    int result = 0;
    int length = strlen(s);

    for (int i = 0; i < length - 1; i++) {
        if (roman_values[s[i]] < roman_values[s[i + 1]]) {
            result -= roman_values[s[i]];
        } else {
            result += roman_values[s[i]];
        }
    }

    result += roman_values[s[length - 1]];

    return result;
}
