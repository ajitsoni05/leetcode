/**
 * @return {Object}
 */
var createInfiniteObject = function() {
   /*
    
    let targetObject = {
        attribute : "value"
    }

    let handler = {
        // getter
        get(target,prop,reciever){
            return "intercepted " + target[prop]
        }
    }
    let p1 = new proxy(targetObject, handler)

    console.log(p1.attribute)
   
   */

   let proxyObj = new Proxy({},{

    get({},prop,reciever){
        return function(){
            return prop;
        };
    }
   })

    return proxyObj
   
    

};

/**
 * const obj = createInfiniteObject();
 * obj['abc123'](); // "abc123"
 */