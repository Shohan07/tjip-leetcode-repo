// Sloved by Shohan
//TC : O(m * n * 4 * log(m * n)) considering constant API calling  
//SC : o(m * n)
class Solution {
public:
    map<pair<int, int>, int>visited;
    //static constexpr int dirs[5] = {-1, 0, 1, 0, -1};
    static constexpr int dX[4] = {-1, 0, 1, 0};
    static constexpr int dY[4] = {0, 1, 0, -1};
    
    void goBack(Robot &robot)
    {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    void floodfill(int x, int y, int d, Robot &robot)
    {
        visited[{x, y}] = 1;
        robot.clean();
        for(int i = 0; i < 4; i++)
        {
            int newD = (d + i) % 4;
            int newX = x + dX[newD];
            int newY = y + dY[newD];
            if(visited.count({newX, newY}) == 0 && robot.move())
            {
                floodfill(newX, newY, newD, robot);
                goBack(robot);
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        floodfill(0, 0, 0, robot);
    }
};