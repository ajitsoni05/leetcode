class Solution {
public:
    double areaOfSquares(vector<vector<int>>& squares, double maxY) {

        double area = 0;

        for (int i = 0; i < squares.size(); i++) {
            if (squares[i][1] > maxY) {
                continue;
            } else {
                double topY = squares[i][1] + squares[i][2];
                double coveredHeight =
                    fmax(0.0, fmin(maxY, topY) - squares[i][1]);
                area += squares[i][2] * coveredHeight;
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        /*
            we are gonna apply binary search
            btw lowest and highest point among given squares
            such that lower area and upper area are same

        */
        // total area
        long double tot = 0;
        double low = 1e9;
        double high = 0;

        for (int i = 0; i < squares.size(); i++) {
            tot += (long double)(squares[i][2]) * squares[i][2];
            low = fmin(low, squares[i][1]);
            high = fmax(high, squares[i][1]+squares[i][2]);
        }

        cout << low << " " << high << tot << endl;
        double halfArea = (tot / 2.0);

        while (high-low >1e-5) {
            double mid = (low + high + 0.0) / 2.0;
            double currentArea = areaOfSquares(squares, mid);
            if (currentArea < halfArea) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};