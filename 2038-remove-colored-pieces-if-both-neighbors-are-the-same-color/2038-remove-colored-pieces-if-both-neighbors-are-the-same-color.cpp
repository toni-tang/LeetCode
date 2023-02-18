class Solution {
public:
    bool winnerOfGame(string colors) {
        int A = 0, B = 0;
        int aMax = 0, bMax = 0;
        
        
        int L = 0, R = 0;
        for(int i = 0; i < colors.length(); i++)
        {
            if(colors[i] == 'A')
            {
                A++;
                if(B >= 3)
                {
                    bMax += B - 2;
                }
                B = 0;
            }
            else
            {
                B++;
                if(A >= 3)
                {
                    aMax += A - 2;
                }
                A = 0;
            }
        }
        
        if(A >= 3)
        {
            aMax += A - 2;
        }
        
        if(B >= 3)
        {
            bMax += B - 2;
        }
        
        return aMax > bMax;
    }
};