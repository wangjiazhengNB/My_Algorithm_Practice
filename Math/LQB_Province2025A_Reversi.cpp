#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    int y;
};
queue<node> q;
// 初始化迷宫数组为默认值'#'，避免随机值干扰判断
char migong[505][505]; 
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool vis[505][505] = {false};

int main() {
    // 1. 初始化迷宫数组为'#'（代表未标记）
    memset(migong, '#', sizeof(migong));
    
    int n, nowx = 205, nowy = 205;
    int sx = 1e9, sy = 1e9, ex = 0, ey = 0;
    string s;
    cin >> n >> s;

    // 标记起点为路径（空格），更新初始边界
    migong[nowx][nowy] = ' ';
    sx = min(sx, nowx);
    ex = max(ex, nowx);
    sy = min(sy, nowy);
    ey = max(ey, nowy);

    // 2. 模拟路径，标记所有走过的位置为空格，更新边界
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') nowx--;
        else if (s[i] == 'D') nowx++;
        else if (s[i] == 'L') nowy--;
        else nowy++;

        migong[nowx][nowy] = ' '; // 标记当前位置为路径
        // 更新边界
        sx = min(sx, nowx);
        ex = max(ex, nowx);
        sy = min(sy, nowy);
        ey = max(ey, nowy);
    }

    // 3. 扩展边界（向外扩1格，确保迷宫外围有墙）
    sx--;
    sy--;
    ex++;
    ey++;

    // 4. 给路径周围的未标记格子标记为墙（*）
    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            if (migong[i][j] == ' ') { // 只处理路径格子
                for (int d = 0; d < 4; d++) { // 四个方向
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    // 边界内、未标记的格子设为墙
                    if (nx >= sx && nx <= ex && ny >= sy && ny <= ey && migong[nx][ny] == '#') {
                        migong[nx][ny] = '*';
                    }
                }
            }
        }
    }

    // 5. BFS标记外部区域（从扩展边界的四个边出发，标记为'c'）
    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            // 只处理扩展边界的格子（外围）
            if (i == sx || i == ex || j == sy || j == ey) {
                // 不是墙、不是路径的格子，加入BFS队列
                if (migong[i][j] != '*' && migong[i][j] != ' ') {
                    node a;
                    a.x = i;
                    a.y = j;
                    q.push(a);
                    vis[i][j] = true;
                    migong[i][j] = 'c'; // 标记为外部
                }
            }
        }
    }

    // BFS扩展外部区域
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            // 条件：边界内、未访问、不是墙、不是路径
            if (nx >= sx && nx <= ex && ny >= sy && ny <= ey 
                && !vis[nx][ny] && migong[nx][ny] != '*' && migong[nx][ny] != ' ') {
                migong[nx][ny] = 'c'; // 标记为外部
                vis[nx][ny] = true;
                node e;
                e.x = nx;
                e.y = ny;
                q.push(e);
            }
        }
    }

    // 6. 内部未标记的格子（既不是路径/墙/外部）设为墙（*）
    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            if (migong[i][j] == '#') { // 未标记的内部格子
                migong[i][j] = '*';
            }
        }
    }

    // 7. 打印地图（核心修正：外部'c'要输出*，不是空格）
    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            if (migong[i][j] == ' ') { // 路径：输出空格
                cout << ' ';
            } else if (migong[i][j] == '*') { // 墙：输出*
                cout << '*';
            } else { // 外部'c'：输出*（迷宫外面显示为墙）
                cout << '*';
            }
        }
        cout << endl;
    }

    return 0;
}