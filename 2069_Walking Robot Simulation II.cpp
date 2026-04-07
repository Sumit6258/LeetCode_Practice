// https://leetcode.com/problems/walking-robot-simulation-ii/

class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0=East, 1=North, 2=West, 3=South
    
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int cycle;
    
    Robot(int width, int height) {
        w = width;
        h = height;
        cycle = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        num %= cycle;
        
        // Important edge case
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; // South
            return;
        }
        
        while (num--) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // If out of bounds → turn
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            
            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
