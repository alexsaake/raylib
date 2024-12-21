#include "raylib.h"

#include "rlgl.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION            450
#endif
#include <config.h>

int main(void)
{
    const int screenWidth = 2000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Mesh Shader Example");

    char* meshShaderCode = LoadFileText("resources/shaders/glsl450/MeshShader.glsl");
    unsigned int meshShader = rlCompileShader(meshShaderCode, RL_MESH_SHADER);
    UnloadFileText(meshShaderCode);
    char* fragmentShaderCode = LoadFileText("resources/shaders/glsl450/FragmentShader.glsl");
    unsigned int fragmentShader = rlCompileShader(fragmentShaderCode, RL_FRAGMENT_SHADER);
    UnloadFileText(fragmentShaderCode);
    unsigned int program = rlLoadMeshShaderProgramS(meshShader, fragmentShader);

    rlEnableShader(program);

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);
        rlDrawMeshTasks(0, 1);
        SwapScreenBuffer();
        PollInputEvents();
    }

    rlDisableShader();
    rlUnloadShaderProgram(program);

    CloseWindow();

    return 0;
}