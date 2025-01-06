/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    function callback(resolve,reject){
        setTimeout(resolve,millis)
    }
    const promise = new Promise(callback)
    return promise;

}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */