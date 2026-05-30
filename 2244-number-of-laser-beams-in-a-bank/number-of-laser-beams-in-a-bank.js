/**
 * @param {string[]} bank
 * @return {number}
 */
var numberOfBeams = function(bank) {
    
    let arr = []

    for(let i = 0; i < bank.length; i++) {
        let count = 0;
        for(let l = 0; l < bank[i].length; l++){
            count += (bank[i][l] === "1");
        }
        if(count > 0)
        arr.push(count);
    }

    let total = 0;

    for(let i = 0; i < arr.length -1 ; i++){
        total += (arr[i] * arr[i+1]);
    }

    return total;


};