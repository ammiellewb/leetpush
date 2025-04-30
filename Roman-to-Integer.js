/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let result = 0;
    let curr, prev = 0;

    const roman_mapping = new Map([
        ["I", 1],
        ["V", 5],
        ["X", 10],
        ["L", 50],
        ["C", 100],
        ["D", 500],
        ["M", 1000]
    ]);

    for (const char of s.split("").reverse()) {
        curr = roman_mapping.get(char);
        if (curr >= prev) {
            result += curr;
        } else {
            result -= curr;
        }
        prev = curr;
    }

    return result;
};