#include <iostream>
#include <vector>

using namespace std;

vector<char> grid;
int idx, turn, win = 0;
char play;
bool game_over, fail;


void Setup()
{
    grid = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    game_over = 0;
    win = 0;
    fail = 0;
    turn = 0;
}

void Draw()
{
    system("cls");
    cout << "-------------" << endl;
    cout << "| " << grid[0] << " | " << grid[1] << " | " << grid[2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << grid[3] << " | " << grid[4] << " | " << grid[5] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << grid[6] << " | " << grid[7] << " | " << grid[8] << " |" << endl;
    cout << "-------------" << endl;

}

void Input()
{
    cout << "Player ";

    if(turn%2 == 0)
        cout << " X ";
    else
        cout << " O ";

    cout << "\n" << "Input a num form 1 to 9: " << endl;
    cin >> idx;
    turn++;
    
}

void Logic()
{
    if(49 <= (int)grid[idx-1] && 57 >= (int)grid[idx-1] && turn%2 == 0)
        grid[idx-1] = 'O';
    else if(49 <= (int)grid[idx-1] && 57 >= (int)grid[idx-1] && turn%2 == 1)
        grid[idx-1] = 'X';
    else
    {
        cout << "Place invalid" << endl;
        turn--;
    }

    fail = 1;
    for (int i = 0; i < 9; i++)
    {
        if(grid[i] >= 49 && grid[i] <= 57)
        fail = 0;
    }

    if ((grid[0] == 'X' && grid[1] == 'X' && grid[2] == 'X') || (grid[3] == 'X' && grid[4] == 'X' && grid[5] == 'X') || (grid[6] == 'X' && grid[7] == 'X' && grid[8] == 'X')|| 
        (grid[0] == 'X' && grid[3] == 'X' && grid[6] == 'X') || (grid[1] == 'X' && grid[4] == 'X' && grid[7] == 'X') || (grid[2] == 'X' && grid[5] == 'X' && grid[8] == 'X')|| 
        (grid[0] == 'X' && grid[4] == 'X' && grid[8] == 'X') || (grid[2] == 'X' && grid[4] == 'X' && grid[6] == 'X'))
            win = 1;
    else if((grid[0] == 'O' && grid[1] == 'O' && grid[2] == 'O') || (grid[3] == 'O' && grid[4] == 'O' && grid[5] == 'O') || (grid[6] == 'O' && grid[7] == 'O' && grid[8] == 'O')|| 
        (grid[0] == 'O' && grid[3] == 'O' && grid[6] == 'O') || (grid[1] == 'O' && grid[4] == 'O' && grid[7] == 'O') || (grid[2] == 'O' && grid[5] == 'O' && grid[8] == 'O')|| 
        (grid[0] == 'O' && grid[4] == 'O' && grid[8] == 'O') || (grid[2] == 'O' && grid[4] == 'O' && grid[6] == 'O'))
            win = 2;

    if(win == 1)
    {
        game_over = 1;
        cout << "Player 1 WINS!!!" << endl;
    }
    else if(win == 2)
    {
        game_over = 1;
        cout << "Player 2 WINS!!!" << endl;
    }
    else if(fail == 1)
    {
        game_over = 1;
        cout << "No one wins :(" << endl;
    }
}



int main()
{
    Setup();

    while(!game_over)
    {
        Draw();
        Input();
        Logic();
    }
    Draw();
}