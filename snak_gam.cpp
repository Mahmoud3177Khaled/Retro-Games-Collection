#include <iostream>
#include <conio.h>
#include <deque>

using namespace std;

bool game_over;
const int width = 25, height = 10;
int x, y, fx, fy, score;
enum eDirection {STOP = 0, UP, LEFT, DOWN, RIGHT};
eDirection dir;

deque<pair<int, int>> tail;
bool path = 0;

void setup()
{
    game_over = 0;
    dir = STOP;
    x = width*2/2;
    y = height/2;
    fx = rand()%width*2;
    fy = rand()%height;
    score = 0;
}

void draw()
{
    system("cls");
    tail.push_back(make_pair(x, y));

    cout << "                     SCORE " << score << "             " << endl;

    for (int i = 0; i < width*2-1; i++)
        cout << '-';
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width*2-1; j++)
        {
            for (int m = 0; m < tail.size()-1; m++)
            {
                if(j == tail[m].first && i == tail[m].second)
                {    
                    path = 1;
                    break;
                }
            }

            if (path)
                cout << 'o';
            else if(j == 0 || j == width*2-2)
                cout << '|';
            else if(i == y && j == x)
                cout << '8';
            else if(i == fy && j == fx)
                cout << 'A';
            else
                cout << ' ';

            path = 0;
        }
        cout << endl;
    }
    
    for (int i = 0; i < width*2-1; i++)
        cout << '-';
    cout << endl;
    
}

void input()
{
    char D;

    if(_kbhit())
    {
        D = _getch();
        if(D == 'w' && dir != DOWN)
            dir = UP;
        else if(D == 'a' && dir != RIGHT)
            dir = LEFT;
        else if(D == 's' && dir != UP)
            dir = DOWN;
        else if(D == 'd' && dir != LEFT)
            dir = RIGHT;
        else if(D == 'x')
            game_over = 1;
    }
}

void logic()
{
    switch (dir)
    {
    case UP:
        y--;
        break;
    case LEFT:
        x--;
        break;
    case DOWN:
        y++;
        break;
    case RIGHT:
        x++;
        break;
    }

    if(x < 0)  
        x = width*2 - 1;
    else if(x > width*2)  
        x = 1;
    else if(y < 0)  
        y = height - 1;
    else if(y > height)
        y = 0;
    
    if(x == fx && y == fy)
    {
        fx = rand()%width*2;
        fy = rand()%height;
        score++;
    }

    tail.pop_front();

    if(tail.size() < score+1)
        tail.push_back(make_pair(x, y));

    for (int m = 1; m < tail.size(); m++)
        {
            if(x == tail[m-1].first && y == tail[m-1].second)
                game_over = 1;
        }
}

int main()
{
    setup();
    while(!game_over)
    {
        draw();
        input();
        logic();
    }
}
