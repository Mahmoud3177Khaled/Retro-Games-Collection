#include <iostream>
#include <conio.h>
#include <deque>

using namespace std;

int one_start, one_end, two_start, two_end, ball_x, ball_y, scr1, scr2;
int width, height;
char d;
bool game_over, hold;
enum dir {STOPP = 0, UP, DOWN};
enum ball_dir {STOP = 0, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT};
dir dir_one, dir_two;
ball_dir ball;

void setup()
{
    width = 50, height = 20;
    scr1 = 0; scr2 = 0;

    one_start = 9, one_end = 13;
    two_start = 9, two_end = 13;

    ball_x = 24, ball_y = 9;
    game_over = 0; hold = 0;

    dir_one = STOPP; dir_two = STOPP; ball = UP_LEFT;
}

void draw()
{
    system("cls");

    cout << "SCORE                " << scr1 << " : " << scr2 << endl;

    for (int i = 0; i < width; i++)
    {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if((i >= one_start && j == 1 && i <= one_end) || (i >= two_start && j == width - 2 && i <= two_end))
                cout << "|";
            else if(j == ball_x && i == ball_y)
                cout << "O";
            else if(j == 0 || j == width - 1)
                cout << "|";
            else
                cout << " ";

        }

        cout << "\n";        
    }

    //cout << "\n";

    for (int i = 0; i < width; i++)
    {
        cout << "-";
    }
    
}

void input()
{
    if(_kbhit())
    {
        d = _getch();
        if(d == 'w')
            dir_one = UP;
        else if(d == 's')
            dir_one = DOWN;

        if(d == 'o')
            dir_two = UP;
        else if(d == 'l')
            dir_two = DOWN;

        hold = 1;
    }
    else
        hold = 0;
}

void logic()
{

    if(dir_one == UP && one_start > 0 && hold)
    {
        one_start--;
        one_end--;
    }
    else if(dir_one == DOWN && one_end < height - 1 && hold)
    {
        one_start++;
        one_end++;
    }

    if(dir_two == UP && two_start > 0 && hold)
    {
        two_start--;
        two_end--;
    }
    else if(dir_two == DOWN && two_end < height - 1 && hold)
    {
        two_start++;
        two_end++;
    }   


    if (ball == UP_RIGHT)
    {
        ball_x++;
        ball_y--;
    }
    if (ball == UP_LEFT)
    {
        ball_x--;
        ball_y--;
    }
    if (ball == DOWN_RIGHT)
    {
        ball_x++;
        ball_y++;
    }
    if (ball == DOWN_LEFT)
    {
        ball_x--;
        ball_y++;
    }



    if(ball_y == 0 && ball == UP_RIGHT)
        ball = DOWN_RIGHT;
    else if(ball_y == 0 && ball == UP_LEFT)
        ball = DOWN_LEFT;

    if(ball_y == height - 1 && ball == DOWN_RIGHT)
        ball = UP_RIGHT;
    else if(ball_y == height - 1 && ball == DOWN_LEFT)
        ball = UP_LEFT;


    if((ball_y <= two_end && ball_y >= two_start && ball_x == width - 3) && ball == UP_RIGHT)
        ball = UP_LEFT;
    else if((ball_y <= two_end && ball_y >= two_start && ball_x == width - 3) && ball == DOWN_RIGHT)
        ball = DOWN_LEFT;
    else if((ball_y <= one_end && ball_y >= one_start && ball_x == 2) && ball == UP_LEFT)
        ball = UP_RIGHT;
    else if((ball_y <= one_end && ball_y >= one_start && ball_x == 2) && ball == DOWN_LEFT)
        ball = DOWN_RIGHT;


    if(!(ball_y <= two_end && ball_y >= two_start) && ball_x == width - 3)
    {
        scr2++;
        ball_x = 24;
        ball_y = 9;
    }
    if(!(ball_y <= one_end && ball_y >= one_start) && ball_x == 2)
    {
        scr1++;
        ball_x = 24;
        ball_y = 9;
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