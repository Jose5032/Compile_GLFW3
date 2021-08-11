#include <GLFW/glfw3.h>

static void key_callback(GLFWwindow* window, int key, int scankey, int action, int mods) {
	if(key == GLFW_KEY_ESCAPE || action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

int main(void)
{
    GLFWwindow* window;
	double time = glfwGetTime();


    if (!glfwInit())
        return -1;

	window = glfwCreateWindow(640, 480, "Hola Mundo", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);

		glClearColor(0.6,0.2,0.6,1.0);

        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(0x1701);

        glLoadIdentity();
        glOrtho(-ratio,ratio,-1.f,1.f,1.f,-1.f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glRotatef((float) glfwGetTime() * 30.f, 0.f, 1.f, 0.f);
		glBegin(GL_POLYGON);
        glColor3f(-0.5f, -0.5f, 0.f);
        glVertex3f(0.f, 0.f, 0.f);
        glColor3f(1.5f, 1.5f, 0.4f);
        glVertex3f(1.f, 0.f, 0.f);
        glColor3f(0.f, 0.2f, 1.f);
        glVertex3f(0.f, 1.f, 0.f);
        glColor3f(0.7f, 0.7f, 0.f);
        glVertex3f(1.f, 1.f, 0.f);
        glColor3f(0.f, 0.5f, 0.6f);
        glVertex3f(0.5f, 1.f, -1.f);
        glEnd();
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

