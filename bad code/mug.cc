
#define glEnableVertexAttribArray glad_glEnableVertexAttribArray

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <./sc.cc>

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

const char* vertexSource = R"glsl(
#version 150 core
in vec2 position;
void main()
{
    gl_Position = vec4(position,0.0,1.0);
}
)glsl";

const char* fragmentSource = R"glsl(
#version 150 core
in vec4 outColor;
void main()
{
    outColor = vec4(1.0,1.0,1.0.1,0);
}
)glsl";


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Mug", NULL, NULL);
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



    float positions[6] = 
    {
        //
         -0.5f, -0.5f, //Vertex 1 (x,y)
          0.0f,  0.5f, //Vertex 2 (x,y)
          0.5f, -0.5f  //Vertex 3 (x,y)
    };

    //generate a Vertex Buffer
    unsigned int vbo; // /*Or*/ Gluint Buffer;
    glGenBuffers(1, &vbo);

    //some buffers settings
    glEnableVertexAttribArray(0/*the index*/);//Enable the index in the array
    glVertexAttribPointer(0/*the index*/, 2/*the components count*/, GL_FLOAT/*the type of the data*/, GL_FALSE/*normalise to flows*/, 2 * sizeof(float)/*the amount of data betwen each Vertex*/, (const void*)0);

    //upload the buffers data 
    glBindBuffer(GL_ARRAY_BUFFER,vbo);//select the Buffer to draws by the draw call
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions),positions,GL_STATIC_DRAW);

    //load the vertex shader data
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexSource,NULL);
    //compile the vertex shader
    glCompileShader(vertexShader);

    //load the fragment shader data
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentSource,NULL);
    //compile the fragment shader
    glCompileShader(fragmentShader);


    

    //combining shaders into a program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    //link pro the program (allow to make changes to the program)
    glLinkProgram(shaderProgram);
    //start the program
    glUseProgram(shaderProgram);

    //link between vertex data and attributes(tell opengl that "position" is out vertex shadder's input)
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    //the data form
    glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,0,0);
    
    glEnableVertexAttribArray(0);

    //
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

 


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0f, 0.3f, 0.2f, 9.0f);// to color the window
        glClear(GL_COLOR_BUFFER_BIT);
        
        /*the draw call*/
        glDrawArrays(GL_TRIANGLES,0,3);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}