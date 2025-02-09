/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var undefinedToNull = function(obj) {
    if(obj === undefined)return {};
    if(obj === null)return null;
    let objectKeys = Object.keys(obj);

    for(let i=0;i<objectKeys.length;i++){
        if(typeof obj[objectKeys[i]] === "object"){
            objectKeys[i] = undefinedToNull( obj[objectKeys[i]]);
        }else{
            if(obj[objectKeys[i]]=== undefined){
                obj[objectKeys[i]] = null;
            }
        }
    }
    return obj;

};

/**
 * undefinedToNull({"a": undefined, "b": 3}) // {"a": null, "b": 3}
 * undefinedToNull([undefined, undefined]) // [null, null] 
 */