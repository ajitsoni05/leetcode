/**
 * @param {string} s
 * @return {string}
 */
var removeOuterParentheses = function (s) {

    let stack = []
    let final = ""

    // Array.from(s).forEach((ele) => {

    //     if (ele === "(") {
    //         if (stack.length > 0) final += "("
    //         stack.push(ele);
    //     } else {
    //         stack.pop();
    //         if (stack.length > 0)
    //             final += ")"


    //     }
    // })

    // let's use for loop
    for(let i = 0; i < s.length; i++){
        if(s[i] === "("){
            final += stack.length >= 1 ? "(" : ""
            stack.push("(");

        }else{
            stack.pop();
            final += stack.length >= 1 ? ")" : ""

        }
    }
    return final;
};