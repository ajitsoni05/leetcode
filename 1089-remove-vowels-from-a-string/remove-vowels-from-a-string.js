/**
 * @param {string} s
 * @return {string}
 */
var removeVowels = function(s) {
    let vowelMap = new Map([
        ["a",1],
        ["e",1],
        ["i",1],
        ["o",1],
        ["u",1]
    ])

    let result = "";

    [...s].forEach((ele)=>{
        result += vowelMap.get(ele) ? '':ele;
    })
    return result;
};