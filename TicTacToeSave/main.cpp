//Emmanuel Atanga
// 09/08/2020
// Saving Tic Tac Toe moves Assignment
#include <array>
#include <vector>
#include <iostream>
using namespace std;
struct S {
char board[9];
};

int main() {
// TODO: declare a vector
vector<S> vectorboard;
S s;
array<char, 2> mark = {'X','O'};
array<char, 9> board = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int move = 0;

for (int turn = 0; turn < 9; turn ++) {
// draw the board
cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
cout << " -----------" << endl;
cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
cout << " -----------" << endl;
cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
// get the next move
cout << endl << "Player " << (turn%2)+1 << " select a cell (1 - 9):" << endl;
cin >> move;
if (board[move-1] != ' ') {
cout << "That cell is taken, you lose!";
return 0;
}
board[move-1] = mark[turn%2];

// TODO: add move to vector
s.board[move-1]=mark[turn%2];
vectorboard.push_back(s);
// check if someone won
        // There are 8 winning posibilities
        if((board[0]=='X' && board[1]=='X' && board[2]=='X') ||
           (board[3]=='X' && board[4]=='X' && board[5]=='X') ||
           (board[6]=='X' && board[7]=='X' && board[8]=='X') ||
           (board[0]=='X' && board[3]=='X' && board[6]=='X') ||
           (board[1]=='X' && board[4]=='X' && board[7]=='X') ||
           (board[2]=='X' && board[5]=='X' && board[8]=='X') ||
           (board[0]=='X' && board[4]=='X' && board[8]=='X') ||
           (board[2]=='X' && board[4]=='X' && board[6]=='X')) {
                cout<<"Player 1 Wins\n";
                break;
           }
        else if((board[0]=='O' && board[1]=='O' && board[2]=='O') ||
           (board[3]=='O' && board[4]=='O' && board[5]=='O') ||
           (board[6]=='O' && board[7]=='O' && board[8]=='O') ||
           (board[0]=='O' && board[3]=='O' && board[6]=='O') ||
           (board[1]=='O' && board[4]=='O' && board[7]=='O') ||
           (board[2]=='O' && board[5]=='O' && board[8]=='O') ||
           (board[0]=='O' && board[4]=='O' && board[8]=='O') ||
           (board[2]=='O' && board[4]=='O' && board[6]=='O')) {
                cout<<"Player 2 Wins\n";
                break;
           }
}
cout << "Game Over" << endl;

cout << "Review of player 1 moves: " << endl;
// TODO: output all of the moves made by player 1 (and only 1)
for(int i=0;i<9;i++){
if(s.board[i]=='X')
cout<<i+1<<" ";
}
cout<<endl;

cout << "Review of player 2 moves: " << endl;
// TODO: output all of the moves made by player 2 (and only 2)
for(int i=0;i<9;i++){
if(s.board[i]=='O')
cout<<i+1<<" ";
}
return 0;
}
