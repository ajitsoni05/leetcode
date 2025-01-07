/**
 * @return {null|boolean|number|string|Array|Object}
 */

 /*
    Array prototype chain is a bunch of hidden methods on which 
    we can use to manipulate array

    the methods can be seen using below code

    const methods = Object.getOwnPropertyNames(Array.Prototype)
    console.logs(methods);
 */
Array.prototype.last = function() {
    if(this.length==0)return -1;
    else{
        return this[this.length-1];
    }
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */