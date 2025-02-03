/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
  
   return !( obj.length || Object.keys(obj).length);
};