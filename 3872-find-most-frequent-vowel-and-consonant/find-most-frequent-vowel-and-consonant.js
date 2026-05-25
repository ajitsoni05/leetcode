/**
 * @param {string} s
 * @return {number}
 */
var maxFreqSum = function(s) {
    let vMap = new Map([
        ['a',0],
        ['e',0],
        ['i',0],
        ['o',0],
        ['u',0],
        ])
    let cMap = new Map();

        [...s].forEach((ele) =>{
            if(vMap.has(ele)){
                vMap.set(ele,vMap.get(ele)+1);
            }else{
                if(cMap.has(ele)){
                    cMap.set(ele,cMap.get(ele)+1);
                }else{
                    cMap.set(ele,1);
                }
            }
        })

    let vM = 0, cM = 0;
    vMap.forEach((value,key)=>{
        vM = Math.max(vM,value);
    })
     cMap.forEach((value,key)=>{
        cM = Math.max(cM,value);
    })
    return vM + cM;

};