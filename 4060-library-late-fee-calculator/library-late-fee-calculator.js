/**
 * @param {number[]} daysLate
 * @return {number}
 */
var lateFee = function(daysLate) {
    let total = 0;
    daysLate.forEach((element) => {
        total += element === 1 ? 1 : element <= 5 ? 2*element : 3*element;
    })
    return total;
};