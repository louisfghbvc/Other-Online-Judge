// Simple check O(N).

vector<int> gradingStudents(vector<int> grades) {
    for(int &x: grades){
        if(x >= 38){
            int add = 5 - x % 5;
            if(add < 3) x += add; 
        }
    }
    return grades;
}
