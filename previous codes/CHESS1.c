#include "raylib.h"
#include <math.h>

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
    Rectangle CurrRec = {100, 100, 100, 100};
    int piecesel = 0;
    Vector2 w[] = {{0, 700},{100, 700},{200, 700},{300, 700},{400, 700},{500, 700},{600, 700},{700, 700}};
    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(0))
        {
            if (!piecesel)
            {
                CurrRec.x = (GetMouseX() / 100) * 100;
                CurrRec.y = (GetMouseY() / 100) * 100;
                piecesel = 1;
            }
            else
            {
                if (CurrRec.x == w[0].x && CurrRec.y == w[0].y)
                {

                    if (w[0].x == (GetMouseX() / 100) * 100 || w[0].y == (GetMouseY() / 100) * 100)
                    {
                        for(int i=0;i<8;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }   
                        w[0].x = (GetMouseX() / 100) * 100;
                        w[0].y = (GetMouseY() / 100) * 100;                        
                    }
                }
                if (CurrRec.x == w[7].x && CurrRec.y == w[7].y)
                {
                    if (w[7].x == (GetMouseX() / 100) * 100 || w[7].y == (GetMouseY() / 100) * 100)
                    {
                        for(int i=0;i<8;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }    
                        w[7].x = (GetMouseX() / 100) * 100;
                        w[7].y = (GetMouseY() / 100) * 100;
                    }
                }
                if (CurrRec.x == w[1].x && CurrRec.y == w[1].y)
                {

                    if ((w[1].x != (GetMouseX() / 100) * 100) && (w[1].y != (GetMouseY() / 100) * 100) && abs(w[1].x - (GetMouseX() / 100) * 100) + abs(w[1].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=0;i<8;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        } 
                         w[1].x = (GetMouseX() / 100) * 100;
                         w[1].y = (GetMouseY() / 100) * 100;                        
                    }
                }
                if (CurrRec.x == w[6].x && CurrRec.y == w[6].y)
                {

                    if ((w[6].x != (GetMouseX() / 100) * 100) && (w[6].y != (GetMouseY() / 100) * 100) && abs(w[6].x - (GetMouseX() / 100) * 100) + abs(w[6].y - (GetMouseY() / 100) * 100) == 300)
                    {
                        for(int i=0;i<8;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }      
                                w[6].x = (GetMouseX() / 100) * 100;
                                w[6].y = (GetMouseY() / 100) * 100;                        
                    }
                }
                if (CurrRec.x == w[5].x && CurrRec.y == w[5].y)
                {
                    if (abs(w[5].x - (GetMouseX() / 100) * 100) == abs(w[5].y - (GetMouseY() / 100) * 100))
                    {
                        for(int i=0;i<8;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        }   
                                w[5].x = (GetMouseX() / 100) * 100;
                                w[5].y = (GetMouseY() / 100) * 100;                        
                    }
                }
                if (CurrRec.x == w[2].x && CurrRec.y == w[2].y)
                {
                    if (abs(w[2].x - (GetMouseX() / 100) * 100) == abs(w[2].y - (GetMouseY() / 100) * 100))
                    {
                        for(int i=0;i<8;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                                break;
                            }
                        } 
                                w[2].x = (GetMouseX() / 100) * 100;
                                w[2].y = (GetMouseY() / 100) * 100;                        
                    }
                }
                if (CurrRec.x == w[4].x && CurrRec.y == w[4].y)
                {

                    if ((w[4].x <= (GetMouseX() / 100) * 100 + 100) && w[4].x >= (GetMouseX() / 100) * 100 - 100 && (w[4].y <= (GetMouseY() / 100) * 100 + 100) && w[4].y >= (GetMouseY() / 100) * 100 - 100)
                    {
                        for(int i=0;i<8;i++)
                        {
                            if(((GetMouseX() /100)*100==w[i].x && (GetMouseY() /100)*100==w[i].y))
                            {
                                w[i].x=800;w[i].y=800;
                               break;
                            }
                        }  
                                w[4].x = (GetMouseX() / 100) * 100;
                                w[4].y = (GetMouseY() / 100) * 100;                        
                    }
                }
                piecesel = 0;
            }
        }
        BeginDrawing();
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
        DrawTextureEx(wrook1, w[0], 0, 1.5, WHITE);
        DrawTextureEx(wbishop1, w[2], 0, 1.5, WHITE);
        DrawTextureEx(wknight1, w[1], 0, 1.5, WHITE);
        DrawTextureEx(wrook2, w[7], 0, 1.5, WHITE);
        DrawTextureEx(wbishop2, w[5], 0, 1.5, WHITE);
        DrawTextureEx(wknight2, w[6], 0, 1.5, WHITE);
        DrawTextureEx(wking, w[4], 0, 1.5, WHITE);
        DrawRectangleLinesEx(CurrRec, 5, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
