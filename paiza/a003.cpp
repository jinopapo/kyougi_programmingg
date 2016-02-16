#include <iostream>

using namespace std;

int maskx[8] = {-1,0,1,-1,1,-1,0,1};
int masky[8] = {1,1,1,0,0,-1,-1,-1};

bool isInBoard(int x,int y){
  if(x >= 0 && y >= 0 && x < 8 && y < 8)
    return true;
  else
    return false;
}

bool isDiff(char board[8][8],int x,int y,char color){
  if(!isInBoard(x,y))
    return false;
  if(board[y][x] != '*' && board[y][x] != color)
    return true;
  else
    return false;
}

void Count(char board[8][8],int& white,int& black){
  for(int y=0;y<8;y++){
    for(int x=0;x<8;x++){
      if(board[y][x] == 'B')
        black++;
      if(board[y][x] == 'W')
        white++;
    }
  }
}

int main(){
  int log_size;
  char board[8][8];
  for(int i=0;i<8;i++)for(int j=0;j<8;j++)board[i][j] = '*';
  board[3][3] = 'W';
  board[4][4] = 'W';
  board[3][4] = 'B';
  board[4][3] = 'B';
  cin >> log_size;
  for(int i=0;i<log_size;i++){
    char color;
    int x,y;
    cin >> color >> x >> y;
    x--;
    y--;
    board[y][x] = color;
    for(int j=0;j<8;j++){
      int mx = x + maskx[j];
      int my = y + masky[j];
      int diff_count = 0;
      while(isDiff(board,mx,my,color)){
        mx += maskx[j];
        my += masky[j];
        diff_count++;
      }
      if(isInBoard(mx,my) && diff_count != 0){
        for(int k=0;k<diff_count;k++){
          mx -= maskx[j];
          my -= masky[j];
          board[my][mx] = color;
        }
      }
    }
  }
  int white = 0;
  int black = 0;
  Count(board,white,black);
  cout << black << "-" << white << " ";
  if(white > black)
    cout << "The white won!" << endl;
  else if(white < black)
    cout << "The black won!" << endl;
  else
    cout << "Draw!" << endl;;
  return 0;
}
