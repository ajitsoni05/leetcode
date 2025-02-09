/**
 * @param {Function} callback
 * @param {Object} context
 * @return {void}
 */
Array.prototype.forEach = function(callback, context) {
    let array=this;
    if(context["context"] !== false){
        for(let i=0;i<array.length;i++){
            callback.call(context,array[i],i,array);
        }
    }else{
        for(let i=0;i<array.length;i++){
            array[i]=context;
        }
    }
    return array;
}

/**
 *  const arr = [1,2,3];
 *  const callback = (val, i, arr) => arr[i] = val * 2;
 *  const context = {"context":true};
 *
 *  arr.forEach(callback, context)  
 *
 *  console.log(arr) // [2,4,6]
 */