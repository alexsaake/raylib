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

    Camera camera = { 0 };
    camera.position = (Vector3){ -125.0f, -125.0f, 125.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };              // Camera looking at point
    camera.up = (Vector3){ 0.0f, 0.0f, 1.0f };                  // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                        // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                     // Camera projection type

    Shader meshShader = LoadMeshShaderS("resources/shaders/glsl450/MeshShader.glsl", "resources/shaders/glsl450/FragmentShader.glsl");


    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginShaderMode(meshShader);
                BeginMode3D(camera);
                    rlEnableShader(meshShader.id);
                    DrawMeshTasks(0, 1);
                    rlDisableShader();
                EndMode3D();
            EndShaderMode();
        EndDrawing();
    }

    UnloadShader(meshShader);

    CloseWindow();

    return 0;
}