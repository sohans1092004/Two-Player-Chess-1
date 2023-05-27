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
//---------------------------------------------------------------
// Module Function Declaration
//---------------------------------------------------------------
void UpdateGame();
void DrawBoard();
int checkmove(int i, int x, int y);
void move(int i, int x, int y);
void revert(int i, int x, int y);
bool check(Vector2 pos);
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
        if(check2 == 1){
            DrawRectangleLines(pieces[4].x,pieces[4].y,100,100,RED);
        }
        if(check1 == 1){
            DrawRectangleLines(pieces[20].x,pieces[20].y,100,100,RED);
        }
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
                    }
                    if(piecesel==-2){
                        Vector2 wkingpos = {pieces[4].x,pieces[4].y};
                        if(check(wkingpos))
                        {
                            revert(i,x,y);
                        }
                    }
                    else
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
    for (int i = 0; i < 32; i++)
    {
        if (x == pieces[i].x && y == pieces[i].y)
        {
            pieces[i].x = 1800;
            pieces[i].y = 1800;
            latestKill = i;
            break;
        }
    }
    positions[(int)CurrRec.y / 100][(int)CurrRec.x / 100] = 0;
    positions[y / 100][x / 100] = piecesel;
    piecesel *= -1;
    pieces[i].x = x;
    pieces[i].y = y;
}
void revert(int i, int x, int y)
{
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
            if ((pieces[j].x == (X / 100) * 100 && pieces[j].y == (i / 100) * 100) || (pieces[3 + j].x == (X / 100) * 100 && pieces[3 + j].y == (i / 100) * 100) || (pieces[7 + j].x == (i / 100) * 100 && pieces[7 + j].y == (Y / 100) * 100))
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
            if ((pieces[j].x == (X / 100) * 100 && pieces[j].y == (i / 100) * 100) || (pieces[3 + j].x == (X / 100) * 100 && pieces[3 + j].y == (i / 100) * 100) || (pieces[7 + j].x == (i / 100) * 100 && pieces[7 + j].y == (Y / 100) * 100))
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
