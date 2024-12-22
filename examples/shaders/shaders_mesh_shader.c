#include "raylib.h"

#include "rlgl.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION            450
#endif

int main(void)
{
    const int screenWidth = 2000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Mesh Shader Example");

    Shader meshShader = LoadMeshShaderS("resources/shaders/glsl450/MeshShader.glsl", "resources/shaders/glsl450/FragmentShader.glsl");

    rlEnableShader(meshShader.id);
    
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        rlDrawMeshTasks(0, 1);
        SwapScreenBuffer();
        PollInputEvents();
    }

    rlDisableShader();
    UnloadShader(meshShader);

    CloseWindow();

    return 0;
}