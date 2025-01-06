/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    // // callback to be passed into Promise
    // function callback(resolve,reject){
    //     // needs to be executeed after a given time interval
    //     setTimeout(resolve,millis)
    // }
    // // declaring a promise
    // const promise = new Promise(callback)
    // // returning a promise
    // return promise;


    await new Promise((resolve,reject)=>{
        setTimeout(resolve,millis);
    })

}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */