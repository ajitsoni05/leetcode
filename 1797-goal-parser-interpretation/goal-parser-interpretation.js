/**
 * @param {string} command
 * @return {string}
 */
var interpret = function(command) {
    
  

    let stack = []

    let finalAns = ""

    for(let i = 0; i < command.length; i++){
        let char = command[i];

        if(char === "("){
            stack.push(char);

        }else if(char === ")" ){
          
          if(stack.at(-1) === "(") {
            finalAns+="o" 
            stack.pop();
          }
            
        }else{
            
            finalAns += char
            stack.pop();
        }
    }

    return finalAns
};