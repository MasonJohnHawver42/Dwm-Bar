#include <raylib.h>

#include "bar.h"

int main(void)
{
	SetConfigFlags(FLAG_WINDOW_TRANSPARENT);

    InitWindow(3840, 30, "Polybar");
    SetWindowPosition(0, 0);

    Item t = Item("Test", 30, 1);

    bar test{30};
    test.add(&t);


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground((Color){0,0,0,127});
            render_bar(test, 0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}