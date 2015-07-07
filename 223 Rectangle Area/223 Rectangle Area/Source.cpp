class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int doubled = getLength(A, C, E, G) * getLength(B, D, F, H);
        int areaa = (D - B) * (C - A) - doubled;
        return areaa + (G - E) * (H - F);
    }
    int getLength(int A, int C, int E, int G) {
        if (A < E) {
            if (C < E) return 0;
            if (C < G) return C - E;
            else return G - E;
        }
        else {
            if (G < A) return 0;
            if (C < G) return C - A;
            else return G - A;
        }
    }
};