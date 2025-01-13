/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let ans =[];
    let arraySize = arr.length
    if(arraySize==0)return ans;

    let idx=0;
    while(arraySize>0){
        let temp =[]
        for(let i=0;i<size;i++){
            if(arr[idx]!=null)
            temp.push(arr[idx++]);
            arraySize--;
        }
        ans.push(temp);

    }
    return ans;
};
