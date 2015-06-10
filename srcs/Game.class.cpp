#include <Game.class.hpp>
#include <Graphic.class.hpp>
#include <TimeManager.class.hpp>
#include <42run.hpp>
#include <Model.class.hpp>
#include <Camera.class.hpp>

Game::Game(void) {
    this->_gameLoop();
}

Game::~Game(void) {
    return ;
}

void Game::_gameLoop(void) {

    Graphic & g = Graphic::instance();
    eKey input;

    Shader s;
    s.initialize("shaders/Shader.vertex", "shaders/Shader.fragment");
    //Model m ("models/nanosuit/nanosuit.obj", &s);
    Model m ("models/cluster/cluster.obj", &s);
    //m.setScale(glm::vec3(0.2f));



    // Create the projection matrix from our camera
    //									 FOV		    Aspect Ratio			   Near / Far Planes
    this->_camera.setPerspective(glm::radians(45.0f), WIDTH / (float)HEIGHT, 0.01f, 100.0f);


    //					        Position	         Yaw	 Pitch
    this->_camera.positionCamera(0, 0, 3,		0,		0);




    while ((input = g.processInput(&this->_camera)) && input != KEYESC) {

        TimeManager::instance().calculateFrameRate(false);

        g.clear();


        switch ( input )
        {
            case KEYUP:
                this->_camera.moveCamera(this->_camera.getSpeed() * TimeManager::instance().deltaTime);
                break;
            case KEYDOWN:
                this->_camera.moveCamera(-1 * this->_camera.getSpeed() * TimeManager::instance().deltaTime);
                break;
            case KEYLEFT:
                this->_camera.strafe(-1 * this->_camera.getSpeed() * TimeManager::instance().deltaTime);
                break;
            case KEYRIGHT:
                this->_camera.strafe(this->_camera.getSpeed() * TimeManager::instance().deltaTime);
                break;
            default:
                break;
        }


        m.draw(&this->_camera);

        g.display();
    }

}
