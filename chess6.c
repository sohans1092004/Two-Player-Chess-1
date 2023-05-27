#include "raylib.h"
#include<stdio.h>
#include <math.h>
//---------------------------------------------------------------
// Global Variable Declaration
//---------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 800;
Vector2 pieces[] = {{0, 700}, {100, 700}, {200, 700}, {300, 700}, {400, 700}, {500, 700}, {600, 700}, {700, 700}, {0, 600}, {100, 600}, {200, 600}, {300, 600}, {400, 600}, {500, 600}, {600, 600}, {700, 600}, {0, 0}, {100, 0}, {200, 0}, {300, 0}, {400, 0}, {500, 0}, {600, 0}, {700, 0}, {0, 100}, {100, 100}, {200, 100}, {300, 100}, {400, 100}, {500, 100}, {600, 100}, {700, 100}};
int positions[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {2, 2, 2, 2, 2, 2, 2, 2},
                       {2, 2, 2, 2, 2, 2, 2, 2}}; // Positions of all the chess pieces on the Chess Board
// 1 -> black  2->white
int piecesel = -1; // 1 for black piece selected , 2 for white piece selected , 
Rectangle CurrRec = {100, 100, 100, 100};
int check2 = 0;
int check1 = 0;
int wkingmove = 0, wrook2move = 0, wrook1move = 0, bkingmove = 0, brook1move = 0, brook2move = 0;
int checkmateOrNot =0;
//---------------------------------------------------------------
// Module Function Declaration
//---------------------------------------------------------------
void UpdateGame();
void DrawBoard();
int checkmove(int i, int x, int y);
void move(int i, int x, int y);
void revert(int i, int x, int y);
bool check(Vector2 pos);
int IsGameOver();
int main()
{
    InitWindow(screenWidth, screenHeight, "CHESS");
    SetTargetFPS(60);
    Texture2D wbishop = LoadTexture("White_Bishop.png");
    Texture2D wknight = LoadTexture("White_Knight.png");
    Texture2D wrook = LoadTexture("White_Rook.png");
    Texture2D wking = LoadTexture("White_King.png");
    Texture2D wqueen = LoadTexture("White_Queen.png");
    Texture2D bbishop = LoadTexture("Black_Bishop.png");
    Texture2D bknight = LoadTexture("Black_Knight.png");
    Texture2D brook = LoadTexture("Black_Rook.png");
    Texture2D bking = LoadTexture("Black_King.png");
    Texture2D bqueen = LoadTexture("Black_Queen.png");
    Texture2D bpawn = LoadTexture("Black_Pawn.png");
    Texture2D wpawn = LoadTexture("White_Pawn.png");
    while (!WindowShouldClose())
    {
        UpdateGame();
        
        BeginDrawing();
        DrawBoard();
        if(checkmateOrNot == 2){
            DrawText("CHECKMATE",250,375,50,RED);
        }
        else if(checkmateOrNot ==1){
            DrawText("STALEMATE",250,375,50,BLUE);
        }
        if(check2 == 1){
            Rectangle wkrec={pieces[4].x,pieces[4].y,100,100};
            DrawRectangleLinesEx(wkrec,5,RED);
        }
        if(check1 == 1){
            Rectangle bkrec={pieces[20].x,pieces[20].y,100,100};
            DrawRectangleLinesEx(bkrec,5,RED);
        }
        DrawTextureEx(wrook, pieces[0], 0, 1.5, WHITE);
        DrawTextureEx(wbishop, pieces[2], 0, 1.5, WHITE);
        DrawTextureEx(wknight, pieces[1], 0, 1.5, WHITE);
        DrawTextureEx(wrook, pieces[7], 0, 1.5, WHITE);
        DrawTextureEx(wbishop, pieces[5], 0, 1.5, WHITE);
        DrawTextureEx(wknight, pieces[6], 0, 1.5, WHITE);
        DrawTextureEx(wking, pieces[4], 0, 1.5, WHITE);
        DrawTextureEx(wqueen, pieces[3], 0, 1.5, WHITE);
        DrawTextureEx(brook, pieces[16], 0, 1.5, WHITE);
        DrawTextureEx(brook, pieces[23], 0, 1.5, WHITE);
        DrawTextureEx(bbishop, pieces[18], 0, 1.5, WHITE);
        DrawTextureEx(bknight, pieces[17], 0, 1.5, WHITE);
        DrawTextureEx(bknight, pieces[22], 0, 1.5, WHITE);
        DrawTextureEx(bbishop, pieces[21], 0, 1.5, WHITE);
        DrawTextureEx(bking, pieces[20], 0, 1.5, WHITE);
        DrawTextureEx(bqueen, pieces[19], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[9], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[8], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[10], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[11], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[12], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[13], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[14], 0, 1.5, WHITE);
        DrawTextureEx(wpawn, pieces[15], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[24], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[25], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[26], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[27], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[28], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[29], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[30], 0, 1.5, WHITE);
        DrawTextureEx(bpawn, pieces[31], 0, 1.5, WHITE);
        DrawRectangleLinesEx(CurrRec, 5, BLUE);
        
        EndDrawing();
        
    }
    CloseWindow();
}

void DrawBoard()
{
    ClearBackground(DARKGRAY);
    DrawRectangle(0, 0, 100, 100, RAYWHITE);
    DrawRectangle(0, 200, 100, 100, RAYWHITE);
    DrawRectangle(0, 400, 100, 100, RAYWHITE);
    DrawRectangle(0, 600, 100, 100, RAYWHITE);
    DrawRectangle(100, 100, 100, 100, RAYWHITE);
    DrawRectangle(100, 300, 100, 100, RAYWHITE);
    DrawRectangle(100, 500, 100, 100, RAYWHITE);
    DrawRectangle(100, 700, 100, 100, RAYWHITE);
    DrawRectangle(200, 0, 100, 100, RAYWHITE);
    DrawRectangle(200, 200, 100, 100, RAYWHITE);
    DrawRectangle(200, 400, 100, 100, RAYWHITE);
    DrawRectangle(200, 600, 100, 100, RAYWHITE);
    DrawRectangle(300, 100, 100, 100, RAYWHITE);
    DrawRectangle(300, 300, 100, 100, RAYWHITE);
    DrawRectangle(300, 500, 100, 100, RAYWHITE);
    DrawRectangle(300, 700, 100, 100, RAYWHITE);
    DrawRectangle(400, 0, 100, 100, RAYWHITE);
    DrawRectangle(400, 200, 100, 100, RAYWHITE);
    DrawRectangle(400, 400, 100, 100, RAYWHITE);
    DrawRectangle(400, 600, 100, 100, RAYWHITE);
    DrawRectangle(500, 100, 100, 100, RAYWHITE);
    DrawRectangle(500, 300, 100, 100, RAYWHITE);
    DrawRectangle(500, 500, 100, 100, RAYWHITE);
    DrawRectangle(500, 700, 100, 100, RAYWHITE);
    DrawRectangle(600, 0, 100, 100, RAYWHITE);
    DrawRectangle(600, 200, 100, 100, RAYWHITE);
    DrawRectangle(600, 400, 100, 100, RAYWHITE);
    DrawRectangle(600, 600, 100, 100, RAYWHITE);
    DrawRectangle(700, 100, 100, 100, RAYWHITE);
    DrawRectangle(700, 300, 100, 100, RAYWHITE);
    DrawRectangle(700, 500, 100, 100, RAYWHITE);
    DrawRectangle(700, 700, 100, 100, RAYWHITE);
}

void UpdateGame()
{
    if (IsMouseButtonPressed(0))
    {
        int x = (GetMouseX() / 100) * 100;
        int y = (GetMouseY() / 100) * 100;
        if (piecesel < 0)
        {
            CurrRec.x = x;
            CurrRec.y = y;
            if (positions[y / 100][x / 100] == 1 && piecesel == -2)
                piecesel = 1;
            if (positions[y / 100][x / 100] == 2 && piecesel == -1)
                piecesel = 2;
        }
        else
        {
            for (int i = 0; i < 32; i++)
            {
                if (CurrRec.x == pieces[i].x && CurrRec.y == pieces[i].y)
                {
                    if (checkmove(i, x, y))
                    {
                        move(i, x, y);
                        if (i == 0)
                        {
                            wrook1move++;
                        }
                        if (i == 4)
                        {
                            wkingmove++;
                        }
                        if (i == 7)
                        {
                            wrook2move++;
                        }
                        if (i == 16)
                        {
                            brook1move++;
                        }
                        if (i == 23)
                        {
                            brook2move++;
                        }
                        if (i == 20)
                        {
                            bkingmove++;
                        }
                    }
                    if(piecesel==-2){
                        Vector2 wkingpos = {pieces[4].x,pieces[4].y};
                        if(check(wkingpos))
                        {
                            revert(i,x,y);
                        }
                    }
                    else if(piecesel == -1)
                    {
                        Vector2 bkingpos = {pieces[20].x,pieces[20].y};
                        if(check(bkingpos))
                        {
                            revert(i,x,y);
                        }
                    }
                }
            }
        }
        if(piecesel<0){
            checkmateOrNot = IsGameOver();
        }
        Vector2 wkingpos={pieces[4].x,pieces[4].y};
        if(check(wkingpos)){
            check2=1;
        }
        else check2 = 0;
        Vector2 bkingpos={pieces[20].x,pieces[20].y};
        if(check(bkingpos)){
            check1=1;
        }
        else check1 = 0;
    }
}

int checkmove(int i, int x, int y)
{
    if (positions[y / 100][x / 100] == piecesel)
    {
        return 0;
    }
    if (i == 0 || i == 7 || i == 16 || i == 23)
    {
        if (pieces[i].x == x || pieces[i].y == y)
        {
            int path = 1;
            if (y < pieces[i].y)
            {
                for (int j = (pieces[i].y / 100) - 1; j > (y / 100); j--)
                {
                    if (positions[j][x / 100] != 0)
                        path = 0;
                }
            }
            else if (y > pieces[i].y)
            {
                for (int j = (pieces[i].y / 100) + 1; j < (y / 100); j++)
                {
                    if (positions[j][x / 100] != 0)
                        path = 0;
                }
            }
            else if (x > pieces[i].x)
            {
                for (int j = (pieces[i].x / 100) + 1; j < (x / 100); j++)
                {
                    if (positions[y / 100][j] != 0)
                        path = 0;
                }
            }
            else if (x < pieces[i].x)
            {
                for (int j = (pieces[i].x / 100) - 1; j > (x / 100); j--)
                {
                    if (positions[y / 100][j] != 0)
                        path = 0;
                }
            }
            return path;
        }
    }
    else if (i == 1 || i == 6 || i == 17 || i == 22)
    {
        if (pieces[i].x != x && pieces[i].y != y && abs(pieces[i].x - x) + abs(pieces[i].y - y) == 300)
        {
            return 1;
        }
    }
    else if (i == 2 || i == 5 || i == 18 || i == 21)
    {
        if (abs(pieces[i].x - x) == abs(pieces[i].y - y))
        {
            int path = 1;
            if (x > pieces[i].x && y > pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y - j) / 100][(x - j) / 100] != 0)
                        path = 0;
                }
            }
            else if (x > pieces[i].x && y < pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y + j) / 100][(x - j) / 100] != 0)
                        path = 0;
                }
            }
            else if (x < pieces[i].x && y > pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y - j) / 100][(x + j) / 100] != 0)
                        path = 0;
                }
            }
            else if (x < pieces[i].x && y < pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y + j) / 100][(x + j) / 100] != 0)
                        path = 0;
                }
            }
            return path;
        }
    }

    else if (i == 3 || i == 19)
    {
        if (pieces[i].x == x || pieces[i].y == y || abs(pieces[i].x - x) == abs(pieces[i].y - y))
        {
            int path = 1;
            if (x > pieces[i].x && y > pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y - j) / 100][(x - j) / 100] != 0)
                        path = 0;
                }
            }
            else if (x > pieces[i].x && y < pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y + j) / 100][(x - j) / 100] != 0)
                        path = 0;
                }
            }
            else if (x < pieces[i].x && y > pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y - j) / 100][(x + j) / 100] != 0)
                        path = 0;
                }
            }
            else if (x < pieces[i].x && y < pieces[i].y)
            {
                for (int j = 100; j < abs(pieces[i].x - x); j += 100)
                {
                    if (positions[(y + j) / 100][(x + j) / 100] != 0)
                        path = 0;
                }
            }
            else if (y < pieces[i].y)
            {
                for (int j = (pieces[i].y / 100) - 1; j > (y / 100); j--)
                {
                    if (positions[j][x / 100] != 0)
                        path = 0;
                }
            }
            else if (y > pieces[i].y)
            {
                for (int j = (pieces[i].y / 100) + 1; j < (y / 100); j++)
                {
                    if (positions[j][x / 100] != 0)
                        path = 0;
                }
            }
            else if (x > pieces[i].x)
            {
                for (int j = (pieces[i].x / 100) + 1; j < (x / 100); j++)
                {
                    if (positions[y / 100][j] != 0)
                        path = 0;
                }
            }
            else if (x < pieces[i].x)
            {
                for (int j = (pieces[i].x / 100) - 1; j > (x / 100); j--)
                {
                    if (positions[y / 100][j] != 0)
                        path = 0;
                }
            }
            return path;
        }
    }
    else if (i == 4 || i == 20)
    {
        if (pieces[i].x <= (x + 100) && pieces[i].x >= (x - 100) && (pieces[i].y <= y + 100) && pieces[i].y >= y - 100)
        {
            return 1;
        }
        if ((pieces[i].x == (x + 200) && pieces[i].y == y) || (pieces[i].y == y && pieces[i].x == x - 200))
        {
            castle(i, x, y);
            return 0;
        }
    }
    else if (i >= 8 && i < 16)
    {
        if (pieces[i].x == x && pieces[i].y == y + 100 && positions[y / 100][x / 100] == 0)
        {
            return 1;
        }
        else if (pieces[i].x == x && pieces[i].y == 600 && y == 400 && positions[y / 100][x / 100] == 0 && positions[(y + 100) / 100][x / 100] == 0)
        {
            return 1;
        }
        else if (pieces[i].y == y + 100 && abs(pieces[i].x - x) == 100 && positions[y / 100][x / 100] == 1)
        {
            return 1;
        }
    }
    else if(i>=24 && i <32)
    {
        if (pieces[i].x == x && pieces[i].y == y - 100 && positions[y / 100][x / 100] == 0)
        {
            return 1;
        }
        else if (pieces[i].x == x && pieces[i].y == 100 && y == 300 && positions[y / 100][x / 100] == 0 && positions[(y - 100) / 100][x / 100] == 0)
        {
            return 1;
        }
        else if (pieces[i].y == y - 100 && abs(pieces[i].x - x) == 100 && positions[y / 100][x / 100] == 2)
        {
            return 1;
        }
    }
    piecesel = -(piecesel^3);
    return 0;
}

int latestKill = 32;
void move(int i, int x, int y)
{
    for (int j = 0; j < 32; j++)
    {
        if (x == pieces[j].x && y == pieces[j].y)
        {
            pieces[j].x = 1800;
            pieces[j].y = 1800;
            latestKill = j;
            break;
        }
        else latestKill = 32;
    }
    positions[(int)CurrRec.y / 100][(int)CurrRec.x / 100] = 0;
    positions[y / 100][x / 100] = piecesel;
    piecesel *= -1;
    pieces[i].x = x;
    pieces[i].y = y;
    printf("\n---------------------------\n");
    
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                printf("%d ",positions[i][j]);
            }
            printf("\n");
        }
    printf("\n---------------------------\n");
}
void revert(int i, int x, int y)
{
    
    positions[y/100][x/100] = 0;
    pieces[i].x = CurrRec.x;
    pieces[i].y = CurrRec.y;
    piecesel *= -1;
    positions[(int)CurrRec.y / 100][(int)CurrRec.x / 100] = piecesel;
    if(latestKill != 32)
    {
    positions[y / 100][x / 100] = piecesel ^ 3;
    pieces[latestKill].x = x;
    pieces[latestKill].y = y;
    latestKill=32;
    }
    printf("\n----------------------\n");
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                printf("%d ",positions[i][j]);
            }
            printf("\n");
        }
    printf("\n-----------------\n");
}

bool check(Vector2 pos)
{
    int X = pos.x;
    int Y = pos.y;
    int j,k;
    if (positions[Y / 100][X / 100] == 1)
    {
        j = 0;
        k = 2;
    }
    if (positions[Y / 100][X / 100] == 2)
    {
        j = 16;
        k = 1;
    }
    if ((abs(pos.x - pieces[1 + j].x) + abs(pos.y - pieces[1 + j].y) == 300 )&&(( pos.x - pieces[1 + j].x != 0) &&( pos.y - pieces[1 + j].y != 0)))
    {
        return true;
    }
    if (abs(pos.x - pieces[6 + j].x) + abs(pos.y - pieces[6 + j].y) == 300 && pos.x - pieces[6 + j].x != 0 && pos.y - pieces[6 + j].y != 0)
    {
        return true;
    }
    for (int i = X-100; i >= 0; i = i - 100)
    {
        if (positions[Y / 100][i / 100] == k)
        {
            if ((pieces[j].x == (i / 100) * 100 && pieces[j].y == (Y / 100) * 100) || (pieces[3 + j].x == (i / 100) * 100 && pieces[3 + j].y == (Y / 100) * 100) || (pieces[7 + j].x == (i / 100) * 100 && pieces[7 + j].y == (Y / 100) * 100))
            {
                return true;
            }
            else
                break;
        }
        else if (positions[Y / 100][i / 100] == 0)
            continue;
        else
            break;
    }
    for (int i = X+100; i <= 700; i = i + 100)
    {
        if (positions[Y / 100][i / 100] == k)
        {
            if ((pieces[j].x == (i / 100) * 100 && pieces[j].y == (Y / 100) * 100) || (pieces[3 + j].x == (i / 100) * 100 && pieces[3 + j].y == (Y / 100) * 100) || (pieces[7 + j].x == (i / 100) * 100 && pieces[7 + j].y == (Y / 100) * 100))
            {
                return true;
            }
            else
                break;
        }
        else if (positions[Y / 100][i / 100] == 0)
            continue;
        else
            break;
    }
    for (int i = Y-100; i >= 0; i = i - 100)
    {
        if (positions[i / 100][X / 100] == k)
        {
            if ((pieces[j].x == (X / 100) * 100 && pieces[j].y == (i / 100) * 100) || (pieces[3 + j].x == (X / 100) * 100 && pieces[3 + j].y == (i / 100) * 100) || (pieces[7 + j].x == (X / 100) * 100 && pieces[7 + j].y == (i / 100) * 100))
            {
                return true;
            }
            else
                break;
        }
        else if (positions[i / 100][X / 100] == 0)
            continue;
        else
            break;
    }
    for (int i = Y+100; i <= 700; i = i + 100)
    {
        if (positions[i / 100][X / 100] == k)
        {
            if ((pieces[j].x == (X / 100) * 100 && pieces[j].y == (i / 100) * 100) || (pieces[3 + j].x == (X / 100) * 100 && pieces[3 + j].y == (i / 100) * 100) || (pieces[7 + j].x == (X / 100) * 100 && pieces[7 + j].y == (i / 100) * 100))
            {
                return true;
            }
            else
                break;
        }
        else if (positions[i / 100][X / 100] == 0)
            continue;
        else
            break;
    }
    for (int i = X-100, t = Y-100; i >= 0 && t >= 0; i = i - 100, t = t - 100)
    {
        if (positions[t / 100][i / 100] == (k^3))
            break;
        else if (positions[t / 100][i / 100] == 0)
            continue;
        else
        {
            if ((pieces[2 + j].x == (i / 100) * 100 && pieces[2 + j].y == (t / 100) * 100) || (pieces[3 + j].x == (i / 100) * 100 && pieces[3 + j].y == (t / 100) * 100) || (pieces[5 + j].x == (i / 100) * 100 && pieces[5 + j].y == (t / 100) * 100))
            {
                return true;
            }
        }
    }
    for (int i = X+100, t = Y+100; i <= 700 && t <= 700; i = i + 100, t = t + 100)
    {
        if (positions[t / 100][i / 100] == (k^3))
            break;
        else if (positions[t / 100][i / 100] == 0)
            continue;
        else
        {
            if ((pieces[2 + j].x == (i / 100) * 100 && pieces[2 + j].y == (t / 100) * 100) || (pieces[3 + j].x == (i / 100) * 100 && pieces[3 + j].y == (t / 100) * 100) || (pieces[5 + j].x == (i / 100) * 100 && pieces[5 + j].y == (t / 100) * 100))
            {
                return true;
            }
        }
    }
    for (int i = X+100, t = Y-100; i <= 700 && t >=0; i = i + 100, t = t - 100)
    {
        if (positions[t / 100][i / 100] == (k^3))
            break;
        else if (positions[t / 100][i / 100] == 0)
            continue;
        else
        {
            if ((pieces[2 + j].x == (i / 100) * 100 && pieces[2 + j].y == (t / 100) * 100) || (pieces[3 + j].x == (i / 100) * 100 && pieces[3 + j].y == (t / 100) * 100) || (pieces[5 + j].x == (i / 100) * 100 && pieces[5 + j].y == (t / 100) * 100))
            {
                return true;
            }
        }
    }
    for (int i = X-100, t = Y+100; i >=0 && t <= 700; i = i - 100, t = t + 100)
    {
        if (positions[t / 100][i / 100] == (k^3))
            break;
        else if (positions[t / 100][i / 100] == 0)
            continue;
        else
        {
            if ((pieces[2 + j].x == (i / 100) * 100 && pieces[2 + j].y == (t / 100) * 100) || (pieces[3 + j].x == (i / 100) * 100 && pieces[3 + j].y == (t / 100) * 100) || (pieces[5 + j].x == (i / 100) * 100 && pieces[5 + j].y == (t / 100) * 100))
            {
                return true;
            }
        }
    }
    if (positions[Y/100][X/100]==1)
    {
    for(int i=8;i<=15;i++)
       {
           if(((X-100)==pieces[i].x && (Y+100)==pieces[i].y) || ((X+100)==pieces[i].x && (Y+100)==pieces[i].y))
            {
                return true;
            }
       }
    }
    if (positions[Y/100][X/100]==2)
    {
        for(int i=24;i<=31;i++)
       {
           if(((X-100)==pieces[i].x && (Y-100)==pieces[i].y) || ((X+100)==pieces[i].x && (Y-100)==pieces[i].y))
            {
                return true;
            }
       }
    }
    return false;
}

int IsGameOver()
{
    int check3 =0;
    int hasValidMoves = 0;
    if(piecesel == -1)
    {
        Vector2 wkingpos = {pieces[4].x,pieces[4].y};
        if(check(wkingpos)) check3=1;
        piecesel = 2;
        for(int i=0;i<16;i++)
        {
            if(pieces[i].x!=1800)
            {
                CurrRec.x = pieces[i].x;
                CurrRec.y = pieces[i].y;
                if(i==0 || i==7)
                {
                for(int j=pieces[i].x +100;j<=700;j+=100)
                {
                    if(positions[(int)pieces[i].y][j/100] ==0)
                    {
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("1000 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y][j/100] ==1){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("2 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }      
                    else break;
                }
                for(int j=pieces[i].x -100;j>=0;j-=100)
                {
                    if(positions[(int)pieces[i].y][j/100] ==0){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("3 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y][j/100] ==1){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("4 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                    
                }
                for(int j=pieces[i].y +100;j<=700;j+=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("5 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 1){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("6 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].y -100;j>=0;j-=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("7");}
                    revert(i,pieces[i].x,j);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 1){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("8");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
                else if(i==2 || i==5)
                {
                for(int j=pieces[i].x -100, k=pieces[i].y - 100;j>=0&&k>=0;j-=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("9");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("10");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y + 100;j<=700&&k<=700;j+=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("11");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("12");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x -100, k=pieces[i].y + 100;j>=0&&k<=700;j-=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("13");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("14");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y - 100;j<=700&&k>=0;j+=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("15");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("16");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
            
                else if(i==3)
                {
                for(int j=pieces[i].x -100, k=pieces[i].y - 100;j>=0&&k>=0;j-=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("%d",j);}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("18");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y + 100;j<=700&&k<=700;j+=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("19");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("20");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x -100, k=pieces[i].y + 100;j>=0&&k<=700;j-=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("21");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("22");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y - 100;j<=700&&k>=0;j+=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("23");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 1){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("24 ");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100;j<=700;j+=100)
                {
                    if(positions[(int)pieces[i].y/100][j/100] ==0){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("25 ");}
                    revert(i,j,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y/100][j/100] ==1){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("26 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x -100;j>=0;j-=100)
                {
                    if(positions[(int)pieces[i].y/100][j/100] ==0){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("27 ");}
                    revert(i,j,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y/100][j/100] ==1){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("28 ");}
                    revert(i,j,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].y +100;j<=700;j+=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("29 ");}
                    revert(i,pieces[i].x,j);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 1){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("30 ");}
                    revert(i,pieces[i].x,j);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].y +100;j<=700;j+=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("31 ");}
                    revert(i,pieces[i].x,j);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 1){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("32 ");}
                    revert(i,pieces[i].x,j);
                    break;
                    }
                    else break;
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
            
                else if(i==4)
                {
                if(pieces[i].x<=600){
                if(checkmove(i,pieces[i].x+100,pieces[i].y))
                {
                    move(i,pieces[i].x+100,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("33 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x >=100){
                if(checkmove(i,pieces[i].x-100,pieces[i].y))
                {
                    move(i,pieces[i].x-100,pieces[i].y);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("34 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x <=600 && pieces[i].y <=600){
                if(checkmove(i,pieces[i].x+100,pieces[i].y+100))
                {
                    move(i,pieces[i].x+100,pieces[i].y+100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("35 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x <=600 && pieces[i].y >=100){
                if(checkmove(i,pieces[i].x+100,pieces[i].y-100))
                {
                    move(i,pieces[i].x+100,pieces[i].y-100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("36 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x >=100 && pieces[i].y >=100){
                if(checkmove(i,pieces[i].x-100,pieces[i].y-100))
                {
                    move(i,pieces[i].x-100,pieces[i].y-100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("37 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x >=100 && pieces[i].y <=600){
                if(checkmove(i,pieces[i].x-100,pieces[i].y+100))
                {
                    move(i,pieces[i].x-100,pieces[i].y+100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("38 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].y<=600){
                if(checkmove(i,pieces[i].x,pieces[i].y+100))
                {
                    move(i,pieces[i].x,pieces[i].y+100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("39 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].y>=100){
                if(checkmove(i,pieces[i].x,pieces[i].y-100))
                {
                    move(i,pieces[i].x,pieces[i].y-100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("40 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
            
                else if(i==1 || i==6)
                {
                if(pieces[i].x<=600 && pieces[i].y <=500){
                if(positions[(int)pieces[i].y+200][(int)pieces[i].x+100] !=2)
                {
                    move(i,pieces[i].x+100,pieces[i].y+200);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("a");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=100 && pieces[i].y >=200){
                if(positions[((int)pieces[i].y-200)/100][((int)pieces[i].x-100)/100] !=2)
                {
                    move(i,pieces[i].x-100,pieces[i].y-200);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("b");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x<=500 && pieces[i].y <=600){
                if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x+200)/100] !=2)
                {
                    move(i,pieces[i].x+200,pieces[i].y+100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("c");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x<=500 && pieces[i].y >=100){
                if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x+200)/100] !=2)
                {
                    move(i,pieces[i].x+200,pieces[i].y-100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("d");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=200 && pieces[i].y >=100){
                if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x-200)/100] !=2)
                {
                    move(i,pieces[i].x-200,pieces[i].y-100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("e");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=100 && pieces[i].y <=500){
                if(positions[((int)pieces[i].y+200)/100][((int)pieces[i].x-100)/100] !=2)
                {
                    move(i,pieces[i].x-100,pieces[i].y+200);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("r");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=200 && pieces[i].y <=600){
                if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x-200)/100] !=2)
                {
                    move(i,pieces[i].x-200,pieces[i].y+100);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("f");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x<=600 && pieces[i].y >=200){
                if(positions[((int)pieces[i].y-200)/100][((int)pieces[i].x+100)/100] !=2)
                {
                    move(i,pieces[i].x+100,pieces[i].y-200);
                    Vector2 wkingpos={pieces[4].x,pieces[4].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("g");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
                else{
                    if(pieces[i].y == 600)
                    {
                        if(positions[((int)pieces[i].y-100)/100][(int)pieces[i].x/100] == 0)
                        {
                            move(i,pieces[i].x,pieces[i].y-100);
                            Vector2 wkingpos={pieces[4].x,pieces[4].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("97 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        if(positions[((int)pieces[i].y-100)/100][(int)pieces[i].x/100] == 0 && positions[((int)pieces[i].y-200)/100][(int)pieces[i].x/100] == 0)
                        {
                            move(i,pieces[i].x,pieces[i].y-200);
                            Vector2 wkingpos={pieces[4].x,pieces[4].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("96 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        if(pieces[i].x<700){
                        if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x+100)/100] == 1)
                        {
                            move(i,pieces[i].x+100,pieces[i].y-100);
                            Vector2 wkingpos={pieces[4].x,pieces[4].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("95 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                        if(pieces[i].x>=100){
                        if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x-100)/100] == 1)
                        {
                            move(i,pieces[i].x-100,pieces[i].y-100);
                            Vector2 wkingpos={pieces[4].x,pieces[4].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("94 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                    }
                    else if(pieces[i].y<600)
                    {
                        if(positions[((int)pieces[i].y-100)/100][(int)pieces[i].x/100] == 0)
                        {
                            move(i,pieces[i].x,pieces[i].y-100);
                            Vector2 wkingpos={pieces[4].x,pieces[4].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("93 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        if(pieces[i].x<700){
                        if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x+100)/100] == 1)
                        {
                            move(i,pieces[i].x+100,pieces[i].y-100);
                            Vector2 wkingpos={pieces[4].x,pieces[4].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("92 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                        if(pieces[i].x>=100){
                        if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x-100)/100] == 1)
                        {
                            move(i,pieces[i].x-100,pieces[i].y-100);
                            Vector2 wkingpos={pieces[4].x,pieces[4].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("91 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                    }
                }
            
            }
        }
        piecesel=-1;
    }
    else if(piecesel == -2)
    {
        Vector2 bkingpos = {pieces[20].x,pieces[20].y};
        if(check(bkingpos)) check3=1;
        piecesel = 1;
        for(int i=16;i<32;i++)
        {
            if(pieces[i].x!=1800)
            {
                CurrRec.x = pieces[i].x;
                CurrRec.y = pieces[i].y;
                if(i==16 || i==23)
                {
                for(int j=pieces[i].x +100;j<=700;j+=100)
                {
                    if(positions[(int)pieces[i].y/100][j/100] ==0)
                    {
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("1000 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y/100][j/100] ==2){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("2 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }      
                    else break;
                }
                for(int j=pieces[i].x -100;j>=0;j-=100)
                {
                    if(positions[(int)pieces[i].y/100][j/100] ==0){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("3 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y/100][j/100] ==2){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("4 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                    
                }
                for(int j=pieces[i].y +100;j<=700;j+=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("5 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 2){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("6 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].y -100;j>=0;j-=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("7");}
                    revert(i,pieces[i].x,j);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 2){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("8");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
                else if(i==18 || i==21)
                {
                for(int j=pieces[i].x -100, k=pieces[i].y - 100;j>=0&&k>=0;j-=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("9");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("10");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y + 100;j<=700&&k<=700;j+=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("11");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("12");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x -100, k=pieces[i].y + 100;j>=0&&k<=700;j-=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("13");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("14");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y - 100;j<=700&&k>=0;j+=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("15");}
                    revert(i,pieces[i].x,pieces[i].y);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("16");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
            
                else if(i==19)
                {
                for(int j=pieces[i].x -100, k=pieces[i].y - 100;j>=0&&k>=0;j-=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("%d",j);}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("18");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y + 100;j<=700&&k<=700;j+=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("19");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("20");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x -100, k=pieces[i].y + 100;j>=0&&k<=700;j-=100,k+=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("21");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("22");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100, k=pieces[i].y - 100;j<=700&&k>=0;j+=100,k-=100)
                {
                    if(positions[k/100][j/100] == 0){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("23");}
                    revert(i,j,k);
                    }
                    else if(positions[k/100][j/100] == 2){
                    move(i,j,k);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("24 ");}
                    revert(i,j,k);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x +100;j<=700;j+=100)
                {
                    if(positions[(int)pieces[i].y/100][j/100] ==0){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("25 ");}
                    revert(i,j,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y/100][j/100] ==2){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("26 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].x -100;j>=0;j-=100)
                {
                    if(positions[(int)pieces[i].y/100][j/100] ==0){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("27 ");}
                    revert(i,j,pieces[i].y);
                    }
                    else if(positions[(int)pieces[i].y/100][j/100] ==2){
                    move(i,j,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("28 ");}
                    revert(i,j,pieces[i].y);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].y +100;j<=700;j+=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("29 ");}
                    revert(i,pieces[i].x,j);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 2){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("30 ");}
                    revert(i,pieces[i].x,j);
                    break;
                    }
                    else break;
                }
                for(int j=pieces[i].y +100;j<=700;j+=100)
                {
                    if(positions[j/100][(int)pieces[i].x/100] == 0){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("31 ");}
                    revert(i,pieces[i].x,j);
                    }
                    else if(positions[j/100][(int)pieces[i].x/100] == 2){
                    move(i,pieces[i].x,j);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("32 ");}
                    revert(i,pieces[i].x,j);
                    break;
                    }
                    else break;
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
            
                else if(i==20)
                {
                if(pieces[i].x<=600){
                if(checkmove(i,pieces[i].x+100,pieces[i].y))
                {
                    move(i,pieces[i].x+100,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("33 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x >=100){
                if(checkmove(i,pieces[i].x-100,pieces[i].y))
                {
                    move(i,pieces[i].x-100,pieces[i].y);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("34 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x <=600 && pieces[i].y <=600){
                if(checkmove(i,pieces[i].x+100,pieces[i].y+100))
                {
                    move(i,pieces[i].x+100,pieces[i].y+100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("35 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x <=600 && pieces[i].y >=100){
                if(checkmove(i,pieces[i].x+100,pieces[i].y-100))
                {
                    move(i,pieces[i].x+100,pieces[i].y-100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("36 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x >=100 && pieces[i].y >=100){
                if(checkmove(i,pieces[i].x-100,pieces[i].y-100))
                {
                    move(i,pieces[i].x-100,pieces[i].y-100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("37 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x >=100 && pieces[i].y <=600){
                if(checkmove(i,pieces[i].x-100,pieces[i].y+100))
                {
                    move(i,pieces[i].x-100,pieces[i].y+100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("38 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].y<=600){
                if(checkmove(i,pieces[i].x,pieces[i].y+100))
                {
                    move(i,pieces[i].x,pieces[i].y+100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("39 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].y>=100){
                if(checkmove(i,pieces[i].x,pieces[i].y-100))
                {
                    move(i,pieces[i].x,pieces[i].y-100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("40 ");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
            
                else if(i==17 || i==22)
                {
                if(pieces[i].x<=600 && pieces[i].y <=500){
                if(positions[(int)pieces[i].y+200][(int)pieces[i].x+100] !=1)
                {
                    move(i,pieces[i].x+100,pieces[i].y+200);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("a");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=100 && pieces[i].y >=200){
                if(positions[((int)pieces[i].y-200)/100][((int)pieces[i].x-100)/100] !=1)
                {
                    move(i,pieces[i].x-100,pieces[i].y-200);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("b");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x<=500 && pieces[i].y <=600){
                if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x+200)/100] !=1)
                {
                    move(i,pieces[i].x+200,pieces[i].y+100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("c");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x<=500 && pieces[i].y >=100){
                if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x+200)/100] !=1)
                {
                    move(i,pieces[i].x+200,pieces[i].y-100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("d");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=200 && pieces[i].y >=100){
                if(positions[((int)pieces[i].y-100)/100][((int)pieces[i].x-200)/100] !=1)
                {
                    move(i,pieces[i].x-200,pieces[i].y-100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("e");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=100 && pieces[i].y <=500){
                if(positions[((int)pieces[i].y+200)/100][((int)pieces[i].x-100)/100] !=1)
                {
                    move(i,pieces[i].x-100,pieces[i].y+200);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("r");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x>=200 && pieces[i].y <=600){
                if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x-200)/100] !=1)
                {
                    move(i,pieces[i].x-200,pieces[i].y+100);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("f");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                if(pieces[i].x<=600 && pieces[i].y >=200){
                if(positions[((int)pieces[i].y-200)/100][((int)pieces[i].x+100)/100] !=1)
                {
                    move(i,pieces[i].x+100,pieces[i].y-200);
                    Vector2 wkingpos={pieces[20].x,pieces[20].y};
                    if(!check(wkingpos)) {hasValidMoves =1;printf("g");}
                    revert(i,pieces[i].x,pieces[i].y);
                }
                }
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                    {
                        printf("%d ",positions[i][j]);
                    }
                    printf("\n");
                }
                }
                else{
                    if(pieces[i].y == 100)
                    {
                        if(positions[((int)pieces[i].y+100)/100][(int)pieces[i].x/100] ==0 )
                        {
                            move(i,pieces[i].x,pieces[i].y+100);
                            Vector2 wkingpos={pieces[20].x,pieces[20].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("97 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        if(positions[((int)pieces[i].y+100)/100][(int)pieces[i].x/100] == 0 && positions[((int)pieces[i].y+200)/100][(int)pieces[i].x/100] == 0)
                        {
                            move(i,pieces[i].x,pieces[i].y+200);
                            Vector2 wkingpos={pieces[20].x,pieces[20].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("96 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        if(pieces[i].x<700){
                        if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x+100)/100] == 2)
                        {
                            move(i,pieces[i].x+100,pieces[i].y+100);
                            Vector2 wkingpos={pieces[20].x,pieces[20].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("95 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                        if(pieces[i].x>=100){
                        if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x-100)/100] == 2)
                        {
                            move(i,pieces[i].x-100,pieces[i].y+100);
                            Vector2 wkingpos={pieces[20].x,pieces[20].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("94 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                    }
                    else if(pieces[i].y>100)
                    {
                        if(positions[((int)pieces[i].y+100)/100][(int)pieces[i].x/100] == 0)
                        {
                            move(i,pieces[i].x,pieces[i].y+100);
                            Vector2 wkingpos={pieces[20].x,pieces[20].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("93 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        if(pieces[i].x<700){
                        if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x+100)/100] == 2)
                        {
                            move(i,pieces[i].x+100,pieces[i].y+100);
                            Vector2 wkingpos={pieces[20].x,pieces[20].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("92 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                        if(pieces[i].x>=100){
                        if(positions[((int)pieces[i].y+100)/100][((int)pieces[i].x-100)/100] == 2)
                        {
                            move(i,pieces[i].x-100,pieces[i].y+100);
                            Vector2 wkingpos={pieces[20].x,pieces[20].y};
                            if(!check(wkingpos)) {hasValidMoves =1;printf("91 ");}
                            revert(i,pieces[i].x,pieces[i].y);
                        }
                        }
                    }
                }
            
            }
        }
        piecesel=-2;
    }
    CurrRec.x=1000;CurrRec.y=1000;
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    if(hasValidMoves == 0 && check3 == 1){ return 2;}
    else if(hasValidMoves == 0){ return 1;}
    else return 0;
}
void castle(int i, int x, int y)
{
    printf("%d %d",wrook2move,wkingmove);
    if (i == 4)
    {
        if (wrook2move == 0 && wkingmove == 0)
        {
            if (positions[7][5] == 0 && positions[7][6] == 0 && pieces[4].x == x - 200)
            {
                pieces[i].x += 100;
                positions[7][5] = 2;
                positions[7][4] = 0;
                Vector2 wkingpos = {pieces[4].x, pieces[4].y};
                if (!check(wkingpos))
                {
                    pieces[i].x += 100;
                    positions[7][6] = 2;
                    positions[7][5] = 0;
                    Vector2 wkingpos = {pieces[4].x, pieces[4].y};
                    if (!check(wkingpos))
                    {
                        pieces[7].x -=200;
                        positions[7][5] = 2;
                        positions[7][7] = 0;
                        piecesel = -2;
                    }
                    else
                    {
                        revert(i, pieces[i].x, pieces[i].y);
                    }
                }
                else
                {
                    revert(i, pieces[i].x, pieces[i].y);
                }
            }
        }
        if (wrook1move == 0 && wkingmove == 0)
        {
            if (positions[7][1] == 0 && positions[7][2] == 0 && positions[7][3] == 0 && pieces[4].x == x + 200)
            {
                move(i, pieces[i].x - 100, pieces[i].y);
                Vector2 wkingpos = {pieces[4].x, pieces[4].y};
                if (!check(wkingpos))
                {
                    move(i, pieces[i].x - 100, pieces[i].y);
                    Vector2 wkingpos = {pieces[4].x, pieces[4].y};
                    if (!check(wkingpos))
                    {
                        move(i, pieces[i].x - 100, pieces[i].y);
                        Vector2 wkingpos = {pieces[4].x, pieces[4].y};
                        if (!check(wkingpos))
                        {
                            move(i, pieces[i].x + 100, pieces[i].y);
                        }
                        else
                            revert(i, pieces[i].x, pieces[i].y);
                    }
                    else
                    {
                        revert(i, pieces[i].x, pieces[i].y);
                    }
                }
                else
                {
                    revert(i, pieces[i].x, pieces[i].y);
                }
            }
        }
    }
    if (i == 20)
    {
        if (bkingmove == 0 && brook2move == 0)
        {
            if (positions[0][5] == 0 && positions[0][6] == 0 && pieces[20].x == x - 200)
            {
                move(i, pieces[i].x + 100, pieces[i].y);
                Vector2 bkingpos = {pieces[20].x, pieces[20].y};
                if (!check(bkingpos))
                {
                    move(i, pieces[i].x + 100, pieces[i].y);
                    Vector2 bkingpos = {pieces[20].x, pieces[20].y};
                    if (!check(bkingpos))
                    {
                        move(23, x - 100, y);
                    }
                    else
                    {
                        revert(i, pieces[i].x, pieces[i].y);
                    }
                }
                else
                {
                    revert(i, pieces[i].x, pieces[i].y);
                }
            }
        }
        if (bkingmove == 0 && brook1move == 0)
        {
            if (positions[0][1] == 0 && positions[0][2] == 0 && positions[0][3] == 0 && pieces[20].x == x + 200)
            {
                move(i, pieces[i].x - 100, pieces[i].y);
                Vector2 bkingpos = {pieces[20].x, pieces[20].y};
                if (!check(bkingpos))
                {
                    pieces[i].x -=100;
                    positions[(int)pieces[i].y/100][(int)pieces[i].x/100] = 0;
                    positions[(int)pieces[i].y/100][(int)(pieces[i].x-100)/100] = 0;
                    Vector2 bkingpos = {pieces[20].x, pieces[20].y};
                    if (!check(bkingpos))
                    {
                        move(i, pieces[i].x - 100, pieces[i].y);
                        Vector2 bkingpos = {pieces[20].x, pieces[20].y};
                        if (!check(bkingpos))
                        {
                            move(i, pieces[i].x + 100, pieces[i].y);
                            move(16, x + 100, y);
                        }
                        else
                            revert(i, pieces[i].x, pieces[i].y);
                    }
                    else
                    {
                        revert(i, pieces[i].x, pieces[i].y);
                    }
                }
                else
                {
                    revert(i, pieces[i].x, pieces[i].y);
                }
            }
        }
    }
}
