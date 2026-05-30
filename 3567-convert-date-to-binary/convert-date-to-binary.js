/**
 * @param {string} date
 * @return {string}
 */

 
var convertDateToBinary = function(date) {
    
     let splits = date.split('-')
     let finalAns =""

      splits.forEach((ele) => {
        let num = Number(ele)
        let bitStr = ""

        for (let i = 0; i < 32; i++) {
            let bit = num & (1<<i);
            if(bit)
            bitStr = "1" + bitStr
            else bitStr ="0" + bitStr
        }
        finalAns += bitStr.replace(/^0+/, '')  + "-"

    })

    
    return finalAns.substring(0,finalAns.length-1)
};