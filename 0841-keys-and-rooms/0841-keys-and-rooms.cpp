#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(); // number of rooms
        vector<bool> visited(n, false); // array to track visited rooms
        stack<int> s;
        s.push(0); // start with room 0
        visited[0] = true; // mark room 0 as visited
        while (!s.empty()) {
            int current_room = s.top();
            s.pop();
            // check all keys in the current room
            for (int key : rooms[current_room]) {
                if (!visited[key]) {
                    visited[key] = true; // mark the room with the key as visited
                    s.push(key); // push the room number with the key into the stack
                }
            }
        }
        // Check if all rooms are visited
        for (bool v : visited) {
            if (!v) // if any room is not visited, return false
                return false;
        }
        return true;
    }
};
