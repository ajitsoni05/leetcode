/**
 * @param {number[][]} points
 * @return {number}
 */
var maxWidthOfVerticalArea = function(points) {
    points.sort((a,b) => a[0] - b[0]);

    let widest = 0;

    for(let i = 0; i < points.length - 1; i++){
        widest = Math.max(widest, points[i+1][0] - points[i][0])
    }
    
    return widest;
};