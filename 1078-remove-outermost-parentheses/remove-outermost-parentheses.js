/**
 * @param {string} s
 * @return {string}
 */
var removeOuterParentheses = function (s) {

    let stack = []
    let final = ""

  Array.from(s).forEach((ele) => {

        if(ele === "(") {
            if(stack.length > 0) final += "("
            stack.push(ele);
        } else {
            stack.pop();
            if(stack.length > 0)
                final += ")"
            

        }
    })
    return final;
};