class EventEmitter {

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    constructor() {
        this.subscribedEventsMap = new Map();
    }
    subscribe(eventName, callback) {
        if (this.subscribedEventsMap.has(eventName)) {
            const callbackArray = this.subscribedEventsMap.get(eventName)
            callbackArray.push(callback);
            this.subscribedEventsMap.set(eventName, callbackArray)
        } else {
            this.subscribedEventsMap.set(eventName, [callback])
        }
        return {
            unsubscribe: () => {
                let callBackArray = this.subscribedEventsMap.get(eventName)
               callBackArray= callBackArray.filter(callbackItem => callbackItem !== callback);
                if(callBackArray.length === 0){
                this.subscribedEventsMap.delete(eventName);
                }else{
                     this.subscribedEventsMap.set(eventName,callBackArray)
                }
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        const resultArray = []
        if (this.subscribedEventsMap.has(eventName)) {
            let callbackArray = this.subscribedEventsMap.get(eventName)
            for (let i = 0; i < callbackArray.length; i++) {
                resultArray.push(callbackArray[i](...args));
            }
        } else {
            return [];
        }
        return resultArray;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */