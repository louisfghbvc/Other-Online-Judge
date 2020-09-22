// Math, calculate the equal function.
// O(1).

string kangaroo(int x1, int v1, int x2, int v2) {
    int dx = x2-x1, dv = v1-v2;
    if(dx > 0 && dv > 0 && dx%dv == 0) return "YES";
    return "NO";
}
