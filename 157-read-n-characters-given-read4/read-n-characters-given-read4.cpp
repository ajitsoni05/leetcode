/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        /*
        
            leetcode
               |

        */ 

        int count = 0;
        while(n != 0){
            if(n >= 4){
                count += read4(buf);
                buf+=4;
                n-=4;
            }else{
                count += read4(buf);
                buf[n] = '\0';
                n = 0;
            }
        }
        return count;
    }
};