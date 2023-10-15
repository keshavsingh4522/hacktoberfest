/** There is a dungeon with unit cubes, if '.' then it is an empty cell
 * if '#' then it contains rock, we start at 'S' and exit is at 'E'
 * find if it contains a path from S to E, if it exits, find the shortest
 * distance from S to E, else print -1 **/

#include <bits/stdc++.h>
using namespace std;

/** To represent 4 directions in which we can go, we can make use of the 
 * direction vectors **/
// North, south, east, west
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

/** Instead of storing a pair of x,y co ordinates in a queue, we can make 2 queue
 * and store x and y in it separately **/
queue<int> qr, qc;

int moves = 0, nodes_left_in_current = 1, nodes_left_in_next = 0;

void exploreNeighbours(int r, int c, int R, int C, vector<vector<bool>> &visited,
                       vector<vector<char>> &grid)
{
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i], cc = c + dc[i];
        if (rr < 0 || cc < 0)
            continue;

        if (rr >= R || cc >= C)
            continue;

        if (visited[rr][cc])
            continue;

        if (grid[rr][cc] == '#')
            continue;

        qr.push(rr), qc.push(cc);
        visited[rr][cc] = true;
        nodes_left_in_next++;
    }
}

int solve(vector<vector<char>> &grid, vector<vector<bool>> &visited, int startX,
          int startY, int R, int C)
{
    qr.push(startX), qc.push(startY);
    visited[startX][startY] = true;
    bool reached = false;

    while (!qr.empty())
    {
        int r = qr.front(), c = qc.front();
        qr.pop(), qc.pop();

        if (grid[r][c] == 'E')
        {
            reached = true;
            break;
        }
        exploreNeighbours(r, c, R, C, visited, grid);
        nodes_left_in_current--; // since we already visited r and c

        /** to make sure we only count moves when we go to the next layer**/
        if (nodes_left_in_current == 0)
        {
            nodes_left_in_current = nodes_left_in_next;
            nodes_left_in_next = 0;
            moves++;
        }
    }

    if (reached)
        return moves;
    return -1;
}

int main()
{
    int R, C;
    cout << "Enter no. of rows and columns ";
    cin >> R >> C;

    vector<vector<char>> grid(R, vector<char>(C, '.'));
    int startX = 0, startY = 0;
    cout << "\nEnter the grid \n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char d;
            cin >> d;
            grid[i][j] = d;
            if (grid[i][j] == 'S')
                startX = i, startY = j;
        }
    }

    vector<vector<bool>> visited(R, vector<bool>(C, false));

    int x = solve(grid, visited, startX, startY, R, C);
    if (x != -1)
        cout << "\nNo. of shortest steps " << x << endl;

    else
        cout << "No path!\n";
}