#ifndef _42RUN_GRAPHIC_CLASS_HPP_
#define _42RUN_GRAPHIC_CLASS_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <42run.hpp>

#include <Camera.class.hpp>

class Graphic {

public:
    static Graphic & instance(void);
    ~Graphic(void);


    void clear(void);
    void display(void);

    eKey processInput(Camera * camera);


private:
    Graphic(void);

    GLFWwindow* _window;


};


#endif //42RUN_GRAPHIC_CLASS_HPP
