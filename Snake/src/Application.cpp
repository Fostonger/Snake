#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit())
        //GLFW не инициализировалс€
        return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "Snaky", NULL, NULL);
    if (!window)
    {
        // ќкно или OpenGL контекст не смогли создатьс€
        glfwTerminate();
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
        {
            std::cout << (char)key << " " << (char)scancode << " " << action << std::endl;
        });

    while (true)
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }



    glfwTerminate(); // ¬ысвобождаем всю пам€ть, используемую GLFW
    return 0;
}