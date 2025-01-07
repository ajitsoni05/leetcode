/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    /* using reduce
    
    array.reduce takes in params as follows-

    array.reduce(callback(accumulator, currentValue, currentIndex, array), initialValue);
    if initial value is not provided first element of array is assumed as initial value
    
    */

    const cb = (acc,curVal)=> curVal(acc)

    return function(x){
       return functions.reduceRight(cb,x);
    }
    


    // return function(x) {
        
    //     // performing function composition
    //     for(const fn of functions.reverse()){
    //         x = fn(x);
    //     }
    //     return x
    // }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */