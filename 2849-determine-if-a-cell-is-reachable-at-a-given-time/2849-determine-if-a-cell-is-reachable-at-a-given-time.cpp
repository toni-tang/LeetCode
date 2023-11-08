class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(fx - sx), diffy = abs(fy - sy);
        if(diffx == 0 && diffy == 0 && t == 1) return false;
        return (min(diffx, diffy) + abs(diffx - diffy)) <= t;
    }
};