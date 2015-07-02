class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return  (C - A) * (D - B) + (G - E) * (H - F) - 
                max(intersection(A, C, E, G), intersection(E, G, A, C)) 
                * 
                max(intersection(B, D, F, H), intersection(F, H, B, D));
    }
    
    int intersection(int x, int X, int y, int Y){
        if (y >= x && y <= X){
            if (Y > X) return X - y;
            else return Y - y;
        }
        return 0;
    }
    
};