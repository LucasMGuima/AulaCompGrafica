#include <stdio.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

//Int do GL que leva em consideracao a int da placa, 128bit, 64bit, ...
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    if (!glfwInit()) {
        printf("Não funcionou o GLFW");
        return 1;
    }

    //Limita o programa a funcionar apenas com o OpenGL3, nem maior nem menor
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Escolhe o perfil de funcoes do OpenGL, nesse caso para o core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Habilita o modo de compatibilidade com funcoes antigas
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Computacao Grafica", NULL, NULL);
    if (!window) {
        printf("A janela nao pode ser criada");
        //Limpa a memoria da placa de video
        glfwTerminate();
        return 1;
    }

    int bufferWIDTH, bufferHEIGTH;
    glfwGetFramebufferSize(window, &bufferWIDTH, &bufferHEIGTH);
    //Mostra qual a janela que esta em contexto, que sera desenhado as coisas
    glfwMakeContextCurrent(window);

    //Libera as bibliotecas experimentas da plava de video
    glewExperimental = GL_TRUE;
    //Inia o Glew
    if (glewInit() != GLEW_OK) {
        printf("Glew nao foi iniciado");
        //Destroi a janela
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    //Cria a viewport indo de 0,0 até o tamanho atual da tela
    glViewport(0, 0, bufferWIDTH, bufferHEIGTH);
    //Mante o while até a que a janela deva fechar
    while (!glfwWindowShouldClose(window)) {
        //cria um evento
        glfwPollEvents();
        //Começa armazenar tudo oque deve ser feito

        //GLFW_OPENGL_CORE
        glClearColor(0.0f, 1.0f, 1.0f, 0.2f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Aplica as mudancas em buffer na tela
        glfwSwapBuffers(window);
    }
}
