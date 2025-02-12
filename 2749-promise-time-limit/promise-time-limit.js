/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    return async function(...args) {
        // Promise race method

        // Time limit Promise
        const timeLimitPromise = new Promise((resolve,reject)=>{
            setTimeout(()=>{
                reject("Time Limit Exceeded")
            },t);
        })

        // fn Promise
        const fnPromise = fn(...args)

        // race the two promises
        return Promise.race([timeLimitPromise,fnPromise])
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */