
# OpenGL Notes
---- 
[2d draw](2D.md) </br>
[3d draw](3d.md)

----
- [Creating a Window](#creating-a-window)
- [Vertex Buffers and Drawing Polygons]()
- [Shaders]()
- [Textures]()

----
## 1. Creating a window:


[Example code for a window](https://www.glfw.org/documentation.html)

``` cpp
#include <GLFW/glfw3.h> // link your librarie
```

```cpp
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    //draw functions on this loop
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
```
For more details [GLFW](https://www.glfw.org/docs/latest/window_guide.html)


----
## 2. Vertex Buffers and Drawing Polygons:

Vertex Buffers are a string of data that saved on the vram and draws by a draw command.

![Vertex Buffers](https://learnopengl.com/img/getting-started/pipeline.png)



