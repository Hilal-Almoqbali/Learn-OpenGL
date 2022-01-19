
#define glEnableVertexAttribArray glad_glEnableVertexAttribArray

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>
#include <string.h>
#include <stdlib.h>

int main()
{
    glfwInit();

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

    //glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
        }


    float positions[6] = {
        //
         -0.5f, -0.5f, 
          0.0f,  0.5f, 
          0.5f, -0.5f
    };

    //generate a Buffer
    unsigned int Buffer;
    glGenBuffers(1, &Buffer);

    glEnableVertexAttribArray(0/*the index*/);//Enable the index in the array
    glVertexAttribPointer(0/*the index*/, 2/*the components count*/, GL_FLOAT/*the type of the data*/, GL_FALSE/*normalise to flows*/, 2 * sizeof(float)/*the amount of data betwen each Vertex*/, (const void*)0);


    glBindBuffer(GL_ARRAY_BUFFER,Buffer);//select the Buffer to draws by the draw call
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions),positions,GL_STATIC_DRAW);

   
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0f, 0.3f, 0.2f, 9.0f);// to color the window
        glClear(GL_COLOR_BUFFER_BIT);
        
        /*the draw call*/
        glDrawArrays(GL_TRIANGLES,0/*the begining of the array*/,3/*the count*/);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}