#include<graphics pipeline/all.h>

int main()
{

window(800,600);

 // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //---------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}