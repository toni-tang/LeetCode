class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(abs(fx) - abs(sx));
        int y = abs(abs(fy) - abs(sy));
        
        if(sx == fx && sy == fy && t == 1) return false;
        if(sx == fx && sy == fy && t == 0) return true;
        if((sx != fx || sy != fy) && t == 0) return false;
        
        if(x == y) {
            t -= x;
            x = 0;
            y = 0;
        }
        else if(x != 0 && y != 0) {
            int w = max(x,y);
            int m = min(x,y);
            
            int z = m % w;
            cout << z << endl;
            t -= z;
            x -= z;
            y -= z;
        }
        
        if(x > 0)   {  
            t -= x;
        }

         if(y > 0)   {  
            t -= y;
        }
        
        
        return t >= 0;
    }
};