#include<iostream>
#include<vector>
using namespace std;
int moves[9][5] = {
    {0, 1, 3, 4,-1},    // 操作1
    {0, 1, 2,-1},       // 操作2
    {1, 2, 4, 5,-1},    // 操作3
    {0, 3, 6,-1},       // 操作4
    {1, 3, 4, 5, 7}, // 操作5
    {2, 5, 8,-1},       // 操作6
    {3, 4, 6, 7,-1},    // 操作7
    {6, 7, 8,-1},       // 操作8
    {4, 5, 7, 8,-1}     // 操作9
};
vector<int> best_solution;

bool is_solved(vector<int>& clocks) {
    for (int pos : clocks) {
        if (pos != 0) return false;
    }
    return true;
}

void solve(vector<int>& clocks, vector<int>& current_solution, int step = 0) {
    if (step == 9) {
        if (is_solved(clocks)) {
            if (best_solution.empty() || current_solution.size() < best_solution.size()) {
                best_solution = current_solution;
            }
        }
        return;
    }
    
    vector<int> original_clocks = clocks;//存储没操作的clocks
    solve(clocks, current_solution, step + 1);
    for(int count =1;count<=3;count++){
    for (int i = 0; i<=4&&moves[step][i] != -1; i++) {
    int affected_clock = moves[step][i];
    clocks[affected_clock] = (clocks[affected_clock] + 1) % 4;
}

    current_solution.push_back(step + 1);
        
    solve(clocks, current_solution, step + 1);
    }// 还原时钟和解决方案状态
    clocks = original_clocks;
    while(!current_solution.empty()&&current_solution.back()==step+1)
        current_solution.pop_back();
    
}


int main(){
    vector<int> clocks(9);
    for(int i = 0; i < 9; i++) {
        cin >> clocks[i];
    }
    vector<int> current_solution;
    solve(clocks, current_solution); 
    for(int i = 0; i < best_solution.size(); i++) {
        if (i > 0) cout << " ";
        cout << best_solution[i];
    }
    cout<<"lll"<<endl;
    cout << endl;
    return 0;
}
