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
    Texture2D wbishop = LoadTexture("White_Bishop.png");
    Texture2D wknight = LoadTexture("White_Knight.png");
    Texture2D wrook = LoadTexture("White_Rook.png");
    Texture2D wking = LoadTexture("White_King.png");
    Texture2D wqueen = LoadTexture("White_Queen.png");
    Texture2D bbishop = LoadTexture("Black/Black_Bishop.png");
    Texture2D bknight = LoadTexture("Black/Black_Knight.png");
    Texture2D brook = LoadTexture("Black/Black_Rook.png");
    Texture2D bking = LoadTexture("Black/Black_King.png");
    Texture2D bqueen = LoadTexture("Black/Black_Queen.png");
    Texture2D bpawn = LoadTexture("Black/Black_Pawn.png");
    Texture2D wpawn = LoadTexture("White_Pawn.png");
    Rectangle CurrRec = {400, 700, 100, 100};
    int piecesel = -2;
    Vector2 pieces[] = {{0, 700},{100, 700},{200, 700},{300, 700},{400, 700},{500, 700},{600, 700},{700, 700},
    {0, 600},{100, 600},{200, 600},{300, 600},{400, 600},{500, 600},{600, 600},{700, 600},
    {0, 0},{100, 0},{200, 0},{300, 0},{400, 0},{500, 0},{600, 0},{700, 0},
    {0, 100},{100, 100},{200, 100},{300, 100},{400, 100},{500, 100},{600, 100},{700, 100}};
    int positions[8][8] = {{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}};
    //1 -> black  2->white
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
                piecesel=-1;
                int x = (GetMouseX() / 100) * 100;int y = (GetMouseY() / 100) * 100;
                if (CurrRec.x == pieces[0].x && CurrRec.y == pieces[0].y)
                {
                    if ((pieces[0].x ==  x|| pieces[0].y == y) && (positions[y/100][x/100]!=2))
                    {
                        int path=1;
                        if(y<pieces[0].y){
                            for(int i=(pieces[0].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>pieces[0].y){
                            for(int i=(pieces[0].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>pieces[0].x){
                            for(int i=(pieces[0].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<pieces[0].x){
                            for(int i=(pieces[0].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=16;i<32;i++)
                        {
                            if(x==pieces[i].x && y==pieces[i].y)
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        pieces[0].x = (GetMouseX() / 100) * 100;
                        pieces[0].y = (GetMouseY() / 100) * 100;  
                        positions[y/100][x/100] = 1;
                        piecesel = -2;
                        }
                    }
                }
                if (CurrRec.x == pieces[7].x && CurrRec.y == pieces[7].y)
                {
                    if (pieces[7].x == x || pieces[7].y == y)
                    {
                        int path=1;
                        if(y<pieces[7].y){
                            for(int i=(pieces[7].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>pieces[7].y){
                            for(int i=(pieces[7].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>pieces[7].x){
                            for(int i=(pieces[7].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<pieces[7].x){
                            for(int i=(pieces[7].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        } 
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        pieces[7].x = (GetMouseX() / 100) * 100;
                        pieces[7].y = (GetMouseY() / 100) * 100;
                        positions[y/100][x/100] = 1;
                                piecesel = -2;
                        }
                    }
                }
                if (CurrRec.x == pieces[1].x && CurrRec.y == pieces[1].y)
                {

                    if ((pieces[1].x != (GetMouseX() / 100) * 100) && (pieces[1].y != (GetMouseY() / 100) * 100) && abs(pieces[1].x - (GetMouseX() / 100) * 100) + abs(pieces[1].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }
                         positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                         pieces[1].x = (GetMouseX() / 100) * 100;
                         pieces[1].y = (GetMouseY() / 100) * 100;    
                            positions[y/100][x/100] = 1;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == pieces[6].x && CurrRec.y == pieces[6].y)
                {

                    if ((pieces[6].x != (GetMouseX() / 100) * 100) && (pieces[6].y != (GetMouseY() / 100) * 100) && abs(pieces[6].x - (GetMouseX() / 100) * 100) + abs(pieces[6].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }      
                                positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[6].x = (GetMouseX() / 100) * 100;
                                pieces[6].y = (GetMouseY() / 100) * 100;  
                                    positions[y/100][x/100] = 1;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == pieces[5].x && CurrRec.y == pieces[5].y)
                {
                    if (abs(pieces[5].x - (GetMouseX() / 100) * 100) == abs(pieces[5].y - (GetMouseY() / 100) * 100))
                    {
                        int path=1;
                        Vector2 check;
                        int i,j;
                        if((GetMouseX()/100) * 100-pieces[5].x>0)
                        {check.x=pieces[5].x+100;i=100;}
                        if((GetMouseX()/100) * 100-pieces[5].x<0)
                        {check.x=pieces[5].x-100;i=-100;}
                        if((GetMouseY()/100) * 100-pieces[5].y>0)
                        {check.y=pieces[5].y+100;j=100;}
                        if((GetMouseY()/100) * 100-pieces[5].y<0)
                        {check.y=pieces[5].y-100;j=-100;}
                        while(abs(check.x-pieces[5].x)<=abs(pieces[5].x-(GetMouseX() / 100) * 100) && abs(check.y-pieces[5].y)<=abs(pieces[5].y-(GetMouseY() / 100) * 100) )
                        {
                           if(positions[(int)check.y/100][(int)check.x/100]!=0)
                           {
                               path=0;break;
                           }     
                           else
                           {  
                            check.x=check.x+i;
                            check.y=check.y+j;
                           }       
                        }
                        if(path)
                        {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }   
                                positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[5].x = (GetMouseX() / 100) * 100;
                                pieces[5].y = (GetMouseY() / 100) * 100;   
                                    positions[y/100][x/100] = 1;
                                piecesel = -2;
                        }
                    }
                }
                if (CurrRec.x == pieces[2].x && CurrRec.y == pieces[2].y)
                {
                    if (abs(pieces[2].x - (GetMouseX() / 100) * 100) == abs(pieces[2].y - (GetMouseY() / 100) * 100))
                    {
                        int path=1;
                        int i,j;
                        Vector2 check;
                        if((GetMouseX()/100) * 100-pieces[2].x>0)
                        {check.x=pieces[2].x+100;i=100;}
                        if((GetMouseX()/100) * 100-pieces[2].x<0)
                        {check.x=pieces[2].x-100;i=-100;}
                        if((GetMouseY()/100) * 100-pieces[2].y>0)
                        {check.y=pieces[2].y+100;j=100;}
                        if((GetMouseY()/100) * 100-pieces[2].y<0)
                        {check.y=pieces[2].y-100;j=-100;}
                        while(abs(check.x-pieces[2].x)<=abs(pieces[2].x-(GetMouseX() / 100) * 100) && abs(check.y-pieces[2].y)<=abs(pieces[2].y-(GetMouseY() / 100) * 100) )
                        {
                           if(positions[(int)check.y/100][(int)check.x/100]!=0)
                           {
                               path=0;break;
                           }     
                           else
                           {  
                            check.x=check.x+i;
                            check.y=check.y+j;
                           }       
                        }
                        if(path)
                        {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                positions[y/100][x/100] = 2;
                                break;
                            }
                        } 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[2].x = (GetMouseX() / 100) * 100;
                                pieces[2].y = (GetMouseY() / 100) * 100;
                                    positions[y/100][x/100] = 2;
                                    piecesel=-2;
                        }
                    }
                }
                if (CurrRec.x == pieces[4].x && CurrRec.y == pieces[4].y)
                {

                    if ((pieces[4].x <= (GetMouseX() / 100) * 100 + 100) && pieces[4].x >= (GetMouseX() / 100) * 100 - 100 && (pieces[4].y <= (GetMouseY() / 100) * 100 + 100) && pieces[4].y >= (GetMouseY() / 100) * 100 - 100)
                    {
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                               break;
                            }
                        }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[4].x = (GetMouseX() / 100) * 100;
                                pieces[4].y = (GetMouseY() / 100) * 100;  
                                    positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if(CurrRec.x==pieces[3].x && CurrRec.y== pieces[3].y){
                    if(pieces[3].x==(GetMouseX()/100)*100 ||pieces[3].y==(GetMouseY()/100)*100 || abs(pieces[3].x-(GetMouseX()/100)*100)==abs(pieces[3].y-(GetMouseY()/100)*100)){
                        for(int i=16;i<32;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                               break;
                            }
                        }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[3].x = (GetMouseX() / 100) * 100;
                                pieces[3].y = (GetMouseY() / 100) * 100;
                                    positions[y/100][x/100] = 2;
                                piecesel = -2;
                    }
                }
                if (CurrRec.x == pieces[16].x && CurrRec.y == pieces[16].y)
                {
                    if (pieces[16].x == (GetMouseX() / 100) * 100 || pieces[16].y == (GetMouseY() / 100) * 100)
                    {
                        int path=1;
                        if(y<pieces[16].y){
                            for(int i=(pieces[16].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>pieces[16].y){
                            for(int i=(pieces[16].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>pieces[16].x){
                            for(int i=(pieces[16].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<pieces[16].x){
                            for(int i=(pieces[16].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        pieces[16].x = (GetMouseX() / 100) * 100;
                        pieces[16].y = (GetMouseY() / 100) * 100; 
                        positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
                if (CurrRec.x == pieces[23].x && CurrRec.y == pieces[23].y)
                {
                    if (pieces[23].x == (GetMouseX() / 100) * 100 || pieces[23].y == (GetMouseY() / 100) * 100)
                    {
                        int path=1;
                        if(y<pieces[23].y){
                            for(int i=(pieces[23].y/100)-1;i>(y/100);i--){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(y>pieces[23].y){
                            for(int i=(pieces[23].y/100)+1;i<(y/100);i++){
                                if(positions[i][x/100] != 0) path=0;
                            }
                        }
                        if(x>pieces[23].x){
                            for(int i=(pieces[23].x/100)+1;i<(x/100);i++){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(x<pieces[23].x){
                            for(int i=(pieces[23].x/100)-1;i>(x/100);i--){
                                if(positions[y/100][i] !=0) path=0;
                            }
                        }
                        if(path){
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }    
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                        pieces[23].x = (GetMouseX() / 100) * 100;
                        pieces[23].y = (GetMouseY() / 100) * 100;
                        positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
                if (CurrRec.x == pieces[17].x && CurrRec.y == pieces[17].y)
                {

                    if ((pieces[17].x != (GetMouseX() / 100) * 100) && (pieces[17].y != (GetMouseY() / 100) * 100) && abs(pieces[17].x - (GetMouseX() / 100) * 100) + abs(pieces[17].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        } 
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                         pieces[17].x = (GetMouseX() / 100) * 100;
                         pieces[17].y = (GetMouseY() / 100) * 100; 
                            positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if (CurrRec.x == pieces[22].x && CurrRec.y == pieces[22].y)
                {

                    if ((pieces[22].x != x) && (pieces[22].y != y) && abs(pieces[22].x - x) + abs(pieces[22].y - y) == 300)
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }      
                                positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[22].x = (GetMouseX() / 100) * 100;
                                pieces[22].y = (GetMouseY() / 100) * 100; 
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if (CurrRec.x == pieces[21].x && CurrRec.y == pieces[21].y)
                {
                    if (abs(pieces[21].x - (GetMouseX() / 100) * 100) == abs(pieces[21].y - (GetMouseY() / 100) * 100))
                    {
                        int path=1;
                        Vector2 check;
                        int i,j;
                        if((GetMouseX()/100) * 100-pieces[21].x>0)
                        {check.x=pieces[21].x+100;i=100;}
                        if((GetMouseX()/100) * 100-pieces[21].x<0)
                        {check.x=pieces[21].x-100;i=-100;}
                        if((GetMouseY()/100) * 100-pieces[21].y>0)
                        {check.y=pieces[21].y+100;j=100;}
                        if((GetMouseY()/100) * 100-pieces[21].y<0)
                        {check.y=pieces[21].y-100;j=-100;}
                        while(abs(check.x-pieces[21].x)<=abs(pieces[21].x-(GetMouseX() / 100) * 100) && abs(check.y-pieces[21].y)<=abs(pieces[21].y-(GetMouseY() / 100) * 100) )
                        {
                           if(positions[(int)check.y/100][(int)check.x/100]!=0)
                           {
                               path=0;break;
                           }     
                           else
                           {  
                            check.x=check.x+i;
                            check.y=check.y+j;
                           }       
                        }
                        if(path)
                        {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        }   
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[21].x = (GetMouseX() / 100) * 100;
                                pieces[21].y = (GetMouseY() / 100) * 100; 
                                    positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
                if (CurrRec.x == pieces[18].x && CurrRec.y == pieces[18].y)
                {
                    if (abs(pieces[18].x - (GetMouseX() / 100) * 100) == abs(pieces[18].y - (GetMouseY() / 100) * 100))
                    {
                        int path=1;
                        Vector2 check;
                        int i,j;
                        if((GetMouseX()/100) * 100-pieces[18].x>0)
                        {check.x=pieces[18].x+100;i=100;}
                        if((GetMouseX()/100) * 100-pieces[18].x<0)
                        {check.x=pieces[18].x-100;i=-100;}
                        if((GetMouseY()/100) * 100-pieces[18].y>0)
                        {check.y=pieces[18].y+100;j=100;}
                        if((GetMouseY()/100) * 100-pieces[18].y<0)
                        {check.y=pieces[18].y-100;j=-100;}
                        while(abs(check.x-pieces[18].x)<=abs(pieces[18].x-(GetMouseX() / 100) * 100) && abs(check.y-pieces[18].y)<=abs(pieces[18].y-(GetMouseY() / 100) * 100) )
                        {
                           if(positions[(int)check.y/100][(int)check.x/100]!=0)
                           {
                               path=0;break;
                           }     
                           else
                           {  
                            check.x=check.x+i;
                            check.y=check.y+j;
                           }       
                        }
                        if(path)
                        {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                                break;
                            }
                        } 
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[18].x = (GetMouseX() / 100) * 100;
                                pieces[18].y = (GetMouseY() / 100) * 100;  
                                    positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
                    
                if (CurrRec.x == pieces[20].x && CurrRec.y == pieces[20].y)
                {

                    if ((pieces[20].x <= (GetMouseX() / 100) * 100 + 100) && pieces[20].x >= (GetMouseX() / 100) * 100 - 100 && (pieces[20].y <= (GetMouseY() / 100) * 100 + 100) && pieces[20].y >= (GetMouseY() / 100) * 100 - 100)
                    {
                        for(int i=0;i<16;i++)
                        {
                            if(((GetMouseX() /100)*100==pieces[i].x && (GetMouseY() /100)*100==pieces[i].y))
                            {
                                pieces[i].x=800;pieces[i].y=800;
                               break;
                            }
                        }  
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[20].x = (GetMouseX() / 100) * 100;
                                pieces[20].y = (GetMouseY() / 100) * 100;    
                                    positions[y/100][x/100] = 1;
                                piecesel = -1;
                    }
                }
                if(CurrRec.x==pieces[19].x && CurrRec.y== pieces[19].y){
                    if(pieces[19].x==(GetMouseX()/100)*100 ||pieces[19].y==(GetMouseY()/100)*100 || abs(pieces[19].x-(GetMouseX()/100)*100)==abs(pieces[19].y-(GetMouseY()/100)*100)){
                        for(int i=0;i<16;i++){
                            if(x==pieces[i].x && y==pieces[i].y){
                                pieces[i].x=800;pieces[i].y=800;
                               break;
                            }
                        }  
                        positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[19].x = (GetMouseX() / 100) * 100;
                                pieces[19].y = (GetMouseY() / 100) * 100;
                                    positions[y/100][x/100] = 1;   
                                piecesel = -1;
                    }
                }
                for(int j=8;j<16;j++){
                    if(CurrRec.x==pieces[j].x && CurrRec.y==pieces[j].y){
                        if(pieces[j].x==x && pieces[j].y == y+100 && positions[y/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[j].x = (GetMouseX() / 100) * 100;
                                pieces[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 2;
                                piecesel = -2;
                        }
                        else if(pieces[j].x == x && pieces[j].y == 600 && y ==400 && positions[y/100][x/100] == 0 && positions[(y+100)/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[j].x = (GetMouseX() / 100) * 100;
                                pieces[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 2;
                                piecesel = -2;
                        }
                        else if(pieces[j].y == y+100 && abs(pieces[j].x - x) == 100 && positions[y/100][x/100]==1){
                            for(int i=16;i<32;i++){
                                if(x==pieces[i].x && y==pieces[i].y){
                                    pieces[i].x=800;pieces[i].y=800;
                                    break;
                                }
                            }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[j].x = (GetMouseX() / 100) * 100;
                                pieces[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 2;
                                piecesel = -2;
                        }
                    }
                }
                for(int j=24;j<32;j++){
                    if(CurrRec.x==pieces[j].x && CurrRec.y==pieces[j].y){
                        if(pieces[j].x==x && pieces[j].y == y-100 && positions[y/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[j].x = (GetMouseX() / 100) * 100;
                                pieces[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                        else if(pieces[j].x == x && pieces[j].y == 100 && y ==300 && positions[y/100][x/100] == 0 && positions[(y-100)/100][x/100] == 0){ 
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[j].x = (GetMouseX() / 100) * 100;
                                pieces[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                        else if(pieces[j].y == y-100 && abs(pieces[j].x - x) == 100 && positions[y/100][x/100]==2){
                            for(int i=0;i<16;i++){
                                if(x==pieces[i].x && y==pieces[i].y){
                                    pieces[i].x=800;pieces[i].y=800;
                                    break;
                                }
                            }  
                            positions[(int)CurrRec.y/100][(int)CurrRec.x/100] = 0;
                                pieces[j].x = (GetMouseX() / 100) * 100;
                                pieces[j].y = (GetMouseY() / 100) * 100;
                                positions[y/100][x/100] = 1;
                                piecesel = -1;
                        }
                    }
                }
            }
        }
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
        DrawTextureEx(wpawn,pieces[9],0,1.5,WHITE);
        DrawTextureEx(wpawn,pieces[8],0,1.5,WHITE);
        DrawTextureEx(wpawn,pieces[10],0,1.5,WHITE);
        DrawTextureEx(wpawn,pieces[11],0,1.5,WHITE);
        DrawTextureEx(wpawn,pieces[12],0,1.5,WHITE);
        DrawTextureEx(wpawn,pieces[13],0,1.5,WHITE);
        DrawTextureEx(wpawn,pieces[14],0,1.5,WHITE);
        DrawTextureEx(wpawn,pieces[15],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[24],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[25],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[26],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[27],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[28],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[29],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[30],0,1.5,WHITE);
        DrawTextureEx(bpawn,pieces[31],0,1.5,WHITE);
        
        DrawRectangleLinesEx(CurrRec, 5, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
