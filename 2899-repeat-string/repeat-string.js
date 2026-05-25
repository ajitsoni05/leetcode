/**
 * @param {number} times
 * @return {string}
 */
String.prototype.replicate = function(times) {
    
    let str = this;
    let finalStr = "";
    for(let i = 0; i < times; i++){
        finalStr += str;
    }


    return finalStr;
}