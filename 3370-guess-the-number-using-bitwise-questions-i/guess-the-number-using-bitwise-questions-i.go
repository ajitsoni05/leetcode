/** 
 * Definition of commonSetBits API.
 * func commonSetBits(num int) int;
 */

func findNumber() int {
    
    /*
         n & num are 1 
    
    */
    ans := 0
    for ls:=32;ls>=0;ls--{

        num := 1<<ls
        one := commonSetBits(num)
        if one == 1 {
            ans = ans ^ (1<<ls)
        }
    }

    return ans
    
}