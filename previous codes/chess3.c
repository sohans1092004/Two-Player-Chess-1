#include "raylib.h"
#include <math.h>

void DrawBoard(){
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

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "CHESS");
    SetTargetFPS(60);
    Texture2D wbishop1 = LoadTexture("White_Bishop.png");
    Texture2D wbishop2 = LoadTexture("White_Bishop.png");
    Texture2D wknight1 = LoadTexture("White_Knight.png");
    Texture2D wknight2 = LoadTexture("White_Knight.png");
    Texture2D wrook1 = LoadTexture("White_Rook.png");
    Texture2D wrook2 = LoadTexture("White_Rook.png");
    Texture2D wking = LoadTexture("White_King.png");
    Texture2D wqueen = LoadTexture("White_Queen.png");
    Texture2D bbishop1 = LoadTexture("Black_Bishop.png");
    Texture2D bbishop2 = LoadTexture("Black_Bishop.png");
    Texture2D bknight1 = LoadTexture("Black_Knight.png");
    Texture2D bknight2 = LoadTexture("Black_Knight.png");
    Texture2D brook1 = LoadTexture("Black_Rook.png");
    Texture2D brook2 = LoadTexture("Black_Rook.png");
    Texture2D bking = LoadTexture("Black_King.png");
    Texture2D bqueen = LoadTexture("Black_Queen.png");
    Texture2D bpawn1 = LoadTexture("Black_Pawn.png");
    Texture2D bpawn2 = LoadTexture("Black_Pawn.png");
    Texture2D bpawn3 = LoadTexture("Black_Pawn.png");
    Texture2D bpawn5 = LoadTexture("Black_Pawn.png");
    Texture2D bpawn6 = LoadTexture("Black_Pawn.png");
    Texture2D bpawn7 = LoadTexture("Black_Pawn.png");
    Texture2D bpawn8 = LoadTexture("Black_Pawn.png");
    Texture2D bpawn4 = LoadTexture("Black_Pawn.png");
    Texture2D wpawn1 = LoadTexture("White_Pawn.png");
    Texture2D wpawn2 = LoadTexture("White_Pawn.png");
    Texture2D wpawn3 = LoadTexture("White_Pawn.png");
    Texture2D wpawn4 = LoadTexture("White_Pawn.png");
    Texture2D wpawn5 = LoadTexture("White_Pawn.png");
    Texture2D wpawn6 = LoadTexture("White_Pawn.png");
    Texture2D wpawn7 = LoadTexture("White_Pawn.png");
    Texture2D wpawn8 = LoadTexture("White_Pawn.png");
    Rectangle CurrRec = {100, 100, 100, 100};
    int piecesel = -1;
    Vector2 w[] = {{0, 700},{100, 700},{200, 700},{300, 700},{400, 700},{500, 700},{600, 700},{700, 700},
    {0, 600},{100, 600},{200, 600},{300, 600},{400, 600},{500, 600},{600, 600},{700, 600},
    {0, 0},{100, 0},{200, 0},{300, 0},{400, 0},{500, 0},{600, 0},{700, 0},
    {0, 100},{100, 100},{200, 100},{300, 100},{400, 100},{500, 100},{600, 100},{700, 100}};
    int positions[8][8] = {{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}};
    //1 -> black  2->white "I AM NO RACIST , IT IS JUST RANDOM"
    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(0))
        {
            if (piecesel <=0)
            {
                CurrRec.x = (GetMouseX() / 100) * 100;
                CurrRec.y = (GetMouseY() / 100) * 100;
                if(positions[GetMouseY()/100][GetMouseX()/100] == 1 && piecesel == -2)
                piecesel = 1;
                if(positions[GetMouseY()/100][GetMouseX()/100] == 2 && piecesel == -1)
                piecesel = 2;
            }
            else
            {
                int x = (GetMouseX() / 100) * 100;int y = (GetMouseY() / 100) * 100;
                if (CurrRec.x == w[0].x && CurrRec.y == w[0].y)
                {
                    if ((w[0].x ==  x|| w[0].y == y) && (positions[y/100][x/100]!=2))
                    {
                        int path=1;
                        if(y<w[0].y){
                            for(int i=(w[0].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>w[0].y){
                            for(int i=(w[0].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>w[0].x){
                            for(int i=(w[0].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<w[0].x){
                            for(int i=(w[0].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=16;i<32;i++)
                        {
                            if(x==w[i].x && y==w[i].y)
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        w[0].x = (GetMouseX() / 100) * 100;
                        w[0].y = (GetMouseY() / 100) * 100;  
                        positions[y/100][x/100] = 2;
                        piecesel = -2;
                        }
                    }
                }
                if (CurrRec.x == w[7].x && CurrRec.y == w[7].y)
                {
                    if (w[7].x == x || w[7].y == y)
                    {
                        int path=1;
                        if(y<w[7].y){
                            for(int i=(w[7].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>w[7].y){
                            for(int i=(w[7].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>w[7].x){
                            for(int i=(w[7].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<w[7].x){
                            for(int i=(w[7].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        } 
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        w[7].x = (GetMouseX() / 100) * 100;
                        w[7].y = (GetMouseY() / 100) * 100;
                        positions[y/100][x/100] = 2;
                                piecesel = -2;
                        }
                    }
                }
                if (CurrRec.x == w[1].x && CurrRec.y == w[1].y)
                {

                    if ((w[1].x != (GetMouseX() / 100) * 100) && (w[1].y != (GetMouseY() / 100) * 100) && abs(w[1].x - (GetMouseX() / 100) * 100) + abs(w[1].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }
                         positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                         w[1].x = (GetMouseX() / 100) * 100;
                         w[1].y = (GetMouseY() / 100) * 100;    
                            positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == w[6].x && CurrRec.y == w[6].y)
                {

                    if ((w[6].x != (GetMouseX() / 100) * 100) && (w[6].y != (GetMouseY() / 100) * 100) && abs(w[6].x - (GetMouseX() / 100) * 100) + abs(w[6].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }      
                                positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[6].x = (GetMouseX() / 100) * 100;
                                w[6].y = (GetMouseY() / 100) * 100;  
                                    positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == w[5].x && CurrRec.y == w[5].y)
                {
                    if (abs(w[5].x - (GetMouseX() / 100) * 100) == abs(w[5].y - (GetMouseY() / 100) * 100))
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }   
                                positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[5].x = (GetMouseX() / 100) * 100;
                                w[5].y = (GetMouseY() / 100) * 100;   
                                    positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == w[2].x && CurrRec.y == w[2].y)
                {
                    if (abs(w[2].x - (GetMouseX() / 100) * 100) == abs(w[2].y - (GetMouseY() / 100) * 100))
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        } 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[2].x = (GetMouseX() / 100) * 100;
                                w[2].y = (GetMouseY() / 100) * 100;
                                    positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == w[4].x && CurrRec.y == w[4].y)
                {

                    if ((w[4].x <= (GetMouseX() / 100) * 100 + 100) && w[4].x >= (GetMouseX() / 100) * 100 - 100 && (w[4].y <= (GetMouseY() / 100) * 100 + 100) && w[4].y >= (GetMouseY() / 100) * 100 - 100)
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                               break;
                            }
                        }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[4].x = (GetMouseX() / 100) * 100;
                                w[4].y = (GetMouseY() / 100) * 100;  
                                    positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if(CurrRec.x==w[3].x && CurrRec.y== w[3].y){
                    if(w[3].x==(GetMouseX()/100)*100 ||w[3].y==(GetMouseY()/100)*100 || abs(w[3].x-(GetMouseX()/100)*100)==abs(w[3].y-(GetMouseY()/100)*100)){
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                               break;
                            }
                        }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[3].x = (GetMouseX() / 100) * 100;
                                w[3].y = (GetMouseY() / 100) * 100;
                                    positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == w[16].x && CurrRec.y == w[16].y)
                {
                    if (w[16].x == (GetMouseX() / 100) * 100 || w[16].y == (GetMouseY() / 100) * 100)
                    {
                        int path=1;
                        if(y<w[16].y){
                            for(int i=(w[16].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>w[16].y){
                            for(int i=(w[16].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>w[16].x){
                            for(int i=(w[16].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<w[16].x){
                            for(int i=(w[16].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        w[16].x = (GetMouseX() / 100) * 100;
                        w[16].y = (GetMouseY() / 100) * 100; 
                        positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
                if (CurrRec.x == w[23].x && CurrRec.y == w[23].y)
                {
                    if (w[23].x == (GetMouseX() / 100) * 100 || w[23].y == (GetMouseY() / 100) * 100)
                    {
                        int path=1;
                        if(y<w[23].y){
                            for(int i=(w[23].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>w[23].y){
                            for(int i=(w[23].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>w[23].x){
                            for(int i=(w[23].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<w[23].x){
                            for(int i=(w[23].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }    
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        w[23].x = (GetMouseX() / 100) * 100;
                        w[23].y = (GetMouseY() / 100) * 100;
                        positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
                if (CurrRec.x == w[17].x && CurrRec.y == w[17].y)
                {

                    if ((w[17].x != (GetMouseX() / 100) * 100) && (w[17].y != (GetMouseY() / 100) * 100) && abs(w[17].x - (GetMouseX() / 100) * 100) + abs(w[17].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        } 
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                         w[17].x = (GetMouseX() / 100) * 100;
                         w[17].y = (GetMouseY() / 100) * 100; 
                            positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if (CurrRec.x == w[22].x && CurrRec.y == w[22].y)
                {

                    if ((w[22].x != x) && (w[22].y != y) && abs(w[22].x - x) + abs(w[22].y - y) == 300)
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }      
                                positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[22].x = (GetMouseX() / 100) * 100;
                                w[22].y = (GetMouseY() / 100) * 100; 
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if (CurrRec.x == w[21].x && CurrRec.y == w[21].y)
                {
                    if (abs(w[21].x - (GetMouseX() / 100) * 100) == abs(w[21].y - (GetMouseY() / 100) * 100))
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }   
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[21].x = (GetMouseX() / 100) * 100;
                                w[21].y = (GetMouseY() / 100) * 100; 
                                    positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if (CurrRec.x == w[18].x && CurrRec.y == w[18].y)
                {
                    if (abs(w[18].x - (GetMouseX() / 100) * 100) == abs(w[18].y - (GetMouseY() / 100) * 100))
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        } 
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[18].x = (GetMouseX() / 100) * 100;
                                w[18].y = (GetMouseY() / 100) * 100;  
                                    positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if (CurrRec.x == w[20].x && CurrRec.y == w[20].y)
                {

                    if ((w[20].x <= (GetMouseX() / 100) * 100 + 100) && w[20].x >= (GetMouseX() / 100) * 100 - 100 && (w[20].y <= (GetMouseY() / 100) * 100 + 100) && w[20].y >= (GetMouseY() / 100) * 100 - 100)
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                               break;
                            }
                        }  
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[20].x = (GetMouseX() / 100) * 100;
                                w[20].y = (GetMouseY() / 100) * 100;    
                                    positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if(CurrRec.x==w[19].x && CurrRec.y== w[19].y){
                    if(w[19].x==(GetMouseX()/100)*100 ||w[19].y==(GetMouseY()/100)*100 || abs(w[19].x-(GetMouseX()/100)*100)==abs(w[19].y-(GetMouseY()/100)*100)){
                        for(int i=0;i<16;i++){
                            if(x==w[i].x && y==w[i].y){
                                w[i].x=800;w[i].y=800;
                               break;
                            }
                        }  
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[19].x = (GetMouseX() / 100) * 100;
                                w[19].y = (GetMouseY() / 100) * 100;
                                    positions[y/100][x/100] = 1;   
                                piecesel = -1;
                    }
                }
                for(int j=8;j<16;j++){
                    if(CurrRec.x==w[j].x && CurrRec.y==w[j].y){
                        if(w[j].x==x && w[j].y == y+100 && positions[y/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[j].x = (GetMouseX() / 100) * 100;
                                w[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 2;
                                piecesel = -2;
                        }
                        else if(w[j].x == x && w[j].y == 600 && y ==400 && positions[y/100][x/100] == 0 && positions[(y-100)/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[j].x = (GetMouseX() / 100) * 100;
                                w[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 2;
                                piecesel = -2;
                        }
                        else if(w[j].y == y+100 && abs(w[j].x - x) == 100 && positions[y/100][x/100]==1){
                            for(int i=16;i<32;i++){
                                if(x==w[i].x && y==w[i].y){
                                    w[i].x=800;w[i].y=800;
                                    break;
                                }
                            }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[j].x = (GetMouseX() / 100) * 100;
                                w[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 2;
                                piecesel = -2;
                        }
                    }
                }
                for(int j=24;j<32;j++){
                    if(CurrRec.x==w[j].x && CurrRec.y==w[j].y){
                        if(w[j].x==x && w[j].y == y-100 && positions[y/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[j].x = (GetMouseX() / 100) * 100;
                                w[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                        else if(w[j].x == x && w[j].y == 100 && y ==300 && positions[y/100][x/100] == 0 && positions[(y+100)/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[j].x = (GetMouseX() / 100) * 100;
                                w[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                        else if(w[j].y == y-100 && abs(w[j].x - x) == 100 && positions[y/100][x/100]==2){
                            for(int i=0;i<16;i++){
                                if(x==w[i].x && y==w[i].y){
                                    w[i].x=800;w[i].y=800;
                                    break;
                                }
                            }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                w[j].x = (GetMouseX() / 100) * 100;
                                w[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
            }
        }
        BeginDrawing();
        DrawBoard();
        DrawTextureEx(wrook1, w[0], 0, 1.5, WHITE);
        DrawTextureEx(wbishop1, w[2], 0, 1.5, WHITE);
        DrawTextureEx(wknight1, w[1], 0, 1.5, WHITE);
        DrawTextureEx(wrook2, w[7], 0, 1.5, WHITE);
        DrawTextureEx(wbishop2, w[5], 0, 1.5, WHITE);
        DrawTextureEx(wknight2, w[6], 0, 1.5, WHITE);
        DrawTextureEx(wking, w[4], 0, 1.5, WHITE);
        DrawTextureEx(wqueen, w[3], 0, 1.5, WHITE);
        DrawTextureEx(brook1, w[16], 0, 1.5, WHITE);
        DrawTextureEx(brook2, w[23], 0, 1.5, WHITE);
        DrawTextureEx(bbishop1, w[18], 0, 1.5, WHITE);
        DrawTextureEx(bknight1, w[17], 0, 1.5, WHITE);
        DrawTextureEx(bknight2, w[22], 0, 1.5, WHITE);
        DrawTextureEx(bbishop2, w[21], 0, 1.5, WHITE);
        DrawTextureEx(bking, w[20], 0, 1.5, WHITE);
        DrawTextureEx(bqueen, w[19], 0, 1.5, WHITE);
        DrawTextureEx(wpawn2,w[9],0,1.5,WHITE);
        DrawTextureEx(wpawn1,w[8],0,1.5,WHITE);
        DrawTextureEx(wpawn3,w[10],0,1.5,WHITE);
        DrawTextureEx(wpawn4,w[11],0,1.5,WHITE);
        DrawTextureEx(wpawn5,w[12],0,1.5,WHITE);
        DrawTextureEx(wpawn6,w[13],0,1.5,WHITE);
        DrawTextureEx(wpawn7,w[14],0,1.5,WHITE);
        DrawTextureEx(wpawn8,w[15],0,1.5,WHITE);
        DrawTextureEx(bpawn1,w[24],0,1.5,WHITE);
        DrawTextureEx(bpawn2,w[25],0,1.5,WHITE);
        DrawTextureEx(bpawn3,w[26],0,1.5,WHITE);
        DrawTextureEx(bpawn4,w[27],0,1.5,WHITE);
        DrawTextureEx(bpawn5,w[28],0,1.5,WHITE);
        DrawTextureEx(bpawn6,w[29],0,1.5,WHITE);
        DrawTextureEx(bpawn7,w[30],0,1.5,WHITE);
        DrawTextureEx(bpawn8,w[31],0,1.5,WHITE);
        
        DrawRectangleLinesEx(CurrRec, 5, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
