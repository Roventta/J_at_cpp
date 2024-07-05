#include <stdio.h>      /* printf, scanf, NULL */
#include <iostream>
#include <stdlib.h>     /* malloc, free, rand */
#include <cstdlib>
#include <cassert>
#include <string.h>

/*
    this program maintains a ascii-art-based game engine in terminal
*/
const char BORDERCHAR = '#';

int Width=0, Height=0;
char *Buffer = nullptr;

int indexBuffer(int i, int j){
    return i*Width + j;
}

void InitBuffer(){
    // read config from console 
    std::cout << "Set Width: ";
    std::cin >> Width;
    std::cout << "Set Height: ";
    std::cin >> Height;
    
    Buffer = (char*) malloc(Width * Height *sizeof(char));
    memset(Buffer, ' ',Width*Height);
}

void DrawFieldBorder(){
    assert((Buffer != nullptr) && "Buffer is not initialized");
    // write full at top and bottom of the buffer
    for(int i=0; i< Width; i++){
        Buffer[indexBuffer(0, i)] = BORDERCHAR;
        Buffer[indexBuffer(Height-1, i)] = BORDERCHAR;
    }
    
    for(int i=1; i<Height-1; i++){
        Buffer[indexBuffer(i, 0)] = BORDERCHAR;
        Buffer[indexBuffer(i, Width-1)] = BORDERCHAR;
    }
}

void RenderBuffer(){
    std::system("clear");
    char *LineBuffer = (char*)malloc(sizeof(char) * Width);
    for(int i=0; i<Height; i++){
        memcpy(LineBuffer, &Buffer[i*Width], Width);
        printf("%s\n", LineBuffer);
    }
    free(LineBuffer);
}

void CleanUp(){
    free(Buffer);
}

int main(){
    InitBuffer();
    DrawFieldBorder();
    RenderBuffer();

    CleanUp();
    return 1;
}