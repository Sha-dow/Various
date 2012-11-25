////////////////////////////////////////////////
////						
////	OpenGL Demo SFML			
////						
////	Hannu Ranta				
////						
////////////////////////////////////////////////

//Compile: g++ cube_test.cc -o cube -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <cstdlib>

//OpenGL:n alustusfunktiot
void initOpenGL()
{
	glClearDepth(1.f);
   	glClearColor(0.f, 0.f, 0.f, 0.f);
   	
   	glEnable(GL_DEPTH_TEST);
   	glDepthMask(GL_TRUE);
   	
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluPerspective(90.f, 1.f, 1.f, 500.f);
}

//Paaohjelma
int main()
{
	GLfloat light_diffuse[] = {0.5, 0.0, 0.0, 1.0};  
	GLfloat light_position[] = {0.0, 1.0, 1.0, 0.0};  
	sf::Window App(sf::VideoMode(800, 600, 32), "Cube Demo");
	sf::Clock Clock;
	
	initOpenGL();
	
	while (App.IsOpened())
	{
		sf::Event Event;
		while (App.GetEvent(Event))
		{
			if (Event.Type == sf::Event::Closed)
			{
				App.Close();
			}
			
			if (Event.Type == sf::Event::Resized)
			{
				glViewport(0, 0, Event.Size.Width, Event.Size.Height);
			}
		}
	
		App.SetActive();
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
      	        glLoadIdentity();
      	        
        	glTranslatef(0.f, 0.f, -20.f);
        	glRotatef(Clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
        	glRotatef(Clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
        	glRotatef(Clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  		glEnable(GL_LIGHT0);
  		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);


        	glBegin(GL_QUADS);
   			glVertex3f(-5.f, -5.f, -5.f);
    			glVertex3f(-5.f,  5.f, -5.f);
    			glVertex3f( 5.f,  5.f, -5.f);
    			glVertex3f( 5.f, -5.f, -5.f);

    			glVertex3f(-5.f, -5.f, 5.f);
   			glVertex3f(-5.f,  5.f, 5.f);
    			glVertex3f( 5.f,  5.f, 5.f);
    			glVertex3f( 5.f, -5.f, 5.f);

    			glVertex3f(-5.f, -5.f, -5.f);
    			glVertex3f(-5.f,  5.f, -5.f);
    			glVertex3f(-5.f,  5.f,  5.f);
    			glVertex3f(-5.f, -5.f,  5.f);

    			glVertex3f(5.f, -5.f, -5.f);
    			glVertex3f(5.f,  5.f, -5.f);
    			glVertex3f(5.f,  5.f,  5.f);
    			glVertex3f(5.f, -5.f,  5.f);

    			glVertex3f(-5.f, -5.f,  5.f);
    			glVertex3f(-5.f, -5.f, -5.f);
    			glVertex3f( 5.f, -5.f, -5.f);
    			glVertex3f( 5.f, -5.f,  5.f);

    			glVertex3f(-5.f, 5.f,  5.f);
    			glVertex3f(-5.f, 5.f, -5.f);
    			glVertex3f( 5.f, 5.f, -5.f);
    			glVertex3f( 5.f, 5.f,  5.f);
		glEnd();
        	
		App.Display();
	}
	
	return EXIT_SUCCESS;
}

