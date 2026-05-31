/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    
    let mp = new Map()

    for(let i = 0; i < s.length; i++){
        if(mp.get(s[i]) && mp.get(s[i])!= t[i]){
            return false
        }else{
            mp.set(s[i],t[i]);
        }
    }



    let mp1 = new Map()

    for(let i = 0; i < t.length; i++){
        if(mp1.get(t[i]) && mp1.get(t[i])!= s[i]){
            return false
        }else{
            mp1.set(t[i],s[i]);
        }
    }

    return true
};