/**
 * File Name: proj4.cpp
 *
 * Academic Integrity Statement:
 * I certify that, while others may have assisted me in brainstorming, debugging,
 * and validating this program, the program itself is my own work. I understand that
 * submitting code which is the work of other individuals is a violation of the course
 * Academic Integrity Policy and may result in a zero credit for the assignment,
 * or course failure and a report to the Academic Dishonesty Board. I also understand
 * that if I knowingly give my original work to another individual it could also result
 * in a zero credit for the assignment, or course failure and a report to the
 * Academic Dishonesty Board.
 *
 * Assisted by and Assisted line numbers: N/A
 *
 * Your Name: Justin Hued
 * Your PSU user ID: jjh6734
 * Course title: CMPSC 465 Fall 2025
 * Due Time: 11:59 PM, Sunday, October 12, 2025
 * Time of Last Modification: 3:30 PM, Tuesday, October 7, 2025
 *
 * Description: This program solves the "Traveling Knight" problem
 * on a standard 8×8 chessboard. Given two squares from an input.txt
 * file (such as "a1" and "h8"), the program determines the minimum
 * number of knight moves required to travel from the starting square
 * to the destination square.
 */

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Position
{
    int x, y;
};

// All 8 possible knight moves
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

// Converts from chess notation (like "a1") to coordinates (0-7, 0-7)
Position toCoord(string square)
{
    Position p;
    p.x = square[0] - 'a';
    p.y = square[1] - '1';
    return p;
}

// BFS to find the shortest number of knight moves
int knightMoves(string start, string end)
{
    if (start == end)
        return 0;

    bool visited[8][8];
    memset(visited, false, sizeof(visited));

    queue<pair<Position, int>> q;
    Position s = toCoord(start);
    Position e = toCoord(end);
    q.push({s, 0});
    visited[s.x][s.y] = true;

    while (!q.empty())
    {
        auto [curr, dist] = q.front();
        q.pop();

        if (curr.x == e.x && curr.y == e.y)
            return dist;

        for (int i = 0; i < 8; i++)
        {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, dist + 1});
            }
        }
    }

    return -1; // Should never happen for valid chessboard positions
}

int main()
{
    ifstream infile("input.txt");
    if (!infile)
    {
        cerr << "Error: input.txt not found.\n";
        return 1;
    }

    string from, to;
    while (infile >> from >> to)
    {
        int moves = knightMoves(from, to);
        cout << "To get from " << from << " to " << to
             << " takes " << moves << " knight moves." << endl;
    }

    infile.close();
    return 0;
}

/*
From input.txt
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Output:
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/