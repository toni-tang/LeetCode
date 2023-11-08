class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(fx - sx), diffy = abs(fy - sy); // Get distance between points
        if(diffx == 0 && diffy == 0 && t == 1) return false; // Edge case
        return max(diffx, diffy) <= t; // You can go diagonal therefore you only need to worry about the bigger of the two distances.
    }
};