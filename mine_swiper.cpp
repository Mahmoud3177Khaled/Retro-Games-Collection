#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int grid[12][12];
int sgrid[12][12];
int x, y, n;
char d;
bool game_over, win;


void setup()
{
    game_over = 0;
    x = 1;
    y = 1;
    n = 0;
    win = 1;

    for (int i = 0; i < 11; i++)
    {
        grid[i][0] = 11;
        grid[0][i] = 11;
        grid[i][11] = 11;
        grid[11][i] = 11;
    }
    

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if(rand()%5 == 0)
                grid[i][j] = 9;
        }
        
    }

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            n = 0;

            if(grid[i][j] == 9) continue;
            if(grid[i+1][j] == 9) n++;
            if(grid[i][j+1] == 9) n++;
            if(grid[i-1][j] == 9) n++;
            if(grid[i][j-1] == 9) n++;
            if(grid[i+1][j+1] == 9) n++;
            if(grid[i+1][j-1] == 9) n++;
            if(grid[i-1][j+1] == 9) n++;
            if(grid[i-1][j-1] == 9) n++;
            
            grid[i][j] = n;
        }
        
    }

        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                if(sgrid[i][j] == grid[i][j] && sgrid[i][j] != 0)
                    continue;
                if((grid[i+1][j] == 0 || grid[i][j+1] == 0 || grid[i-1][j] == 0 || grid[i][j-1] == 0 || grid[i+1][j+1] == 0 || grid[i+1][j-1] == 0 || grid[i-1][j+1] == 0 || grid[i-1][j-1] == 0) && grid[i][j] != 9)
                    sgrid[i][j] = grid[i][j];
                else
                    sgrid[i][j] = '-';
                if(grid[i][j] == 0)
                    sgrid[i][j] = ' ';
            }
            
        }    


    
}

void draw()
{
    system("cls");

    for (int i = 0; i < 41; i++)
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 1; i < 11; i++)
    {
        cout << "|";
        for (int j = 1; j < 11; j++)
        {
            if(sgrid[i][j] == 9)
                cout << " x |";
            else if(x == j && y == i)
                cout << " _ |";
            else if(sgrid[i][j] == 0)
                cout << " - |";
            else if(sgrid[i][j] <= 10)
                cout << " " << sgrid[i][j] << " |";
            else
                cout << " " << (char)sgrid[i][j] << " |";
        }


        cout << endl;
        for (int i = 0; i < 41; i++)
        {
            cout << "-";
        }
        cout << endl;
        
        
    }

    /*for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
    

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
                cout << sgrid[i][j] << " ";
        }
        cout << endl;
    }*/
    
}

void input()
{
    if(_kbhit())
    {
        d = _getch();
        if(d == 'w')
            y--;
        else if(d == 's')
            y++;
        else if(d == 'a')
            x--;
        else if(d == 'd')
            x++;
        else if(d == 'l')
            sgrid[y][x] = grid[y][x];
        else if(d == 'k')
        {
            if(sgrid[y][x] != '.' && sgrid[y][x] == '-')
                sgrid[y][x] = '.';
            else if(sgrid[y][x] == '.' )
                sgrid[y][x] = '-';
            
        }
    }
    
}

void logic()
{

    win = 1;

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if(grid[i][j] == 9 && sgrid[i][j] != '.')
                win = 0;
            
        }
        
    }

    if(sgrid[y][x] == 9)
    {
        game_over = 1;
    }

    if (game_over)
    {
        draw();
        cout << "game_over\n";
        //_sleep(1000);
    }
    if (win)
    {
        draw();
        cout << "\nYou win!\n";
        //_sleep(1000);
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

        //if(game_over || win)
            //_sleep(10000);
    }
}