#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
# define PI           3.14159265358979323846

int status=0;
GLfloat position_train = 0.0f;
GLfloat position_wave = 0.0f;
GLfloat position_car_1 = 0.0f;
GLfloat speed=0.0f;
GLfloat speed_car=0.0f;
GLfloat position_ship = 0.0f;
GLfloat position_car_2 = 0.0f;
GLfloat position_bus = 0.0f;
GLfloat position_cloud = 0.0f;
GLfloat position_SeaSun = 0.0f;
GLfloat position_DaySun = 0.0f;
GLfloat position_boat = 0.0f;
GLfloat sun_position = -40;
GLfloat sun_position2 = -40;
GLfloat sun_position3;
GLfloat sun_speed = .07;

void day() //FUNC1
{
    speed= 0.1f;
    speed_car= 0.1f;

    if (position_ship< -120)
        position_ship = 180.0f;
    position_ship -=speed+.1;

    if (position_car_1< -280)
        position_car_1 = 370.0f;
    position_car_1 -=speed+0.15;

        if (position_bus< -280)
        position_bus = 370.0f;
    position_bus -=speed+0.15;

        if (position_cloud> 370)
        position_cloud = -380.0f;
    position_cloud +=speed;

    if (position_car_2> 370)
        position_car_2 = -130.0f;
    position_car_2 +=speed+0.1;

    if (position_boat> 160)
        position_boat = -180.0f;
    position_boat +=speed+.1;

    if (position_train< -500)
        position_train = 420.0f;
    position_train -=speed+.35;
    glutPostRedisplay();

    if(status==0)
    {
        sun_position += sun_speed;
        if(sun_position >= 100)
            sun_position = 100;
    }
}

void night_evening() //FUNC2
{
    speed= 0.1f;

       if (position_car_1< -280)
        position_car_1 = 370.0f;
    position_car_1 -=speed+0.15;

        if (position_bus< -280)
        position_bus = 370.0f;
    position_bus -=speed+0.05;

        if (position_cloud> 370)
        position_cloud = -380.0f;
    position_cloud +=speed;

    if (position_car_2> 370)
        position_car_2 = -130.0f;
    position_car_2 +=speed+0.1;

    if (position_train< -500)
        position_train = 420.0f;
    position_train -=speed+.35;


    glutPostRedisplay();

}

void scene_2() //FUNC3
{
    speed= 0.1f;
    speed_car= 0.1f;

    if (position_ship< -160)
        position_ship = 300.0f;
    position_ship -=speed+.1;

        if (position_cloud> 370)
        position_cloud = -380.0f;
    position_cloud +=speed;

    if (position_car_2> 370)
        position_car_2 = -130.0f;
    position_car_2 +=speed+0.1;

    if (position_boat> 330)
        position_boat = -150.0f;
    position_boat +=speed+.1;

    if(status==3)
    {
            if(sun_position2 >= -5)
                sun_position2 = -5;
            sun_position2 +=0.04;
    }

    if (position_wave> 5)
        position_wave = -15.0f;
    position_wave +=speed+0.05;

    if (position_train< -500)
        position_train = 420.0f;
    position_train -=speed+.35;

    glutPostRedisplay();

}

void drawQuad(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3) //FUNC4
{
    glBegin(GL_QUADS);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
}


void drawTriangle(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2) //FUNC5
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
void drawLine(GLint x0, GLint y0, GLint x1, GLint y1) //FUNC6
{
    glBegin(GL_LINES);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
    glEnd();
}
void DrawCircle(float cx, float cy, float r, int num_segments) //FUNC7
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get current angle
        float x = r * cosf(theta);//calculate x
        float y = r * sinf(theta);//calculate y
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}




//train_platform
void platform() //FUNC8
{
    //garden_under_platform
    glColor3ub(118,224,122);
    drawQuad(-100,-48,100,-48,100,-14,-100,-14);

    //small_garden_under_platform
    glColor3ub(89,198,89);
    drawQuad(-100,-41,100,-41,100,-24,-100,-24);

    //pillar_1
    glPushMatrix();
    glTranslatef(130.0f, 0.0f,0.0f);
    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_1_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_1_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();



    //pillar_2
    glPushMatrix();
    glTranslatef(15.0f, 0.0f,0.0f);

    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_2_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_2_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();

    //platform
    glColor3ub(169,169,169);
    drawQuad(-100,20,100,20,100,28,-100,28);

    //rail line
    glLineWidth(8);
    glColor3ub(73,73,73);
    drawLine(-100,24,100,24);

    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);


    //garden_under_platform
    glColor3ub(118,224,122);
    drawQuad(-100,-48,100,-48,100,-14,-100,-14);

    //small_garden_under_platform
    glColor3ub(89,198,89);
    drawQuad(-100,-41,100,-41,100,-24,-100,-24);

    //pillar_1
    glPushMatrix();
    glTranslatef(130.0f, 0.0f,0.0f);
    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_1_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_1_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();



    //pillar_2
    glPushMatrix();
    glTranslatef(15.0f, 0.0f,0.0f);

    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_2_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_2_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();

    //platform
    glColor3ub(169,169,169);
    drawQuad(-100,20,100,20,100,28,-100,28);

    //rail line
    glLineWidth(8);
    glColor3ub(73,73,73);
    drawLine(-100,24,100,24);

    glPopMatrix();
}

char dhaka[] = "DHAKA";
char metro[] = "METRO";
char rail[] = "RAIL";
char bangladesh[] = "BANGLADESH";

void textTrain( float x, float y, char *st) //FUNC9
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(1.0,0.0,0.0);
    glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

    }

}

//train
void train() //FUNC10
{
    glPushMatrix();
    glTranslatef(position_train, 0.0f,0.0f);
    //train_body_part1
    glColor3ub(255,255,255);
    drawQuad(-62,24,-15,24,-15,42,-62,42);
    drawQuad(-45,24,-15,24,-15,60,-45,60);
    //drawQuad(-58,24,-45,24,-45,32,-58,32);
    //drawTriangle(-55,24,-55,40,-60,40);

    //train_body_part2
    glColor3ub(255,255,255);
    drawQuad(-10,24,35,24,35,60,-10,60);

    //train_body_part3
    glColor3ub(255,255,255);
    drawQuad(40,24,85,24,85,60,40,60);

    //train_head
    glColor3ub(255,255,255);
    DrawCircle(-47,45,15,200);
    DrawCircle(-52,42,10,200);
    DrawCircle(-47,39,15,200);


    //body_lines
    glLineWidth(20);
    glColor3ub(73,73,73);
    drawLine(-55,31,-45,31);
    drawLine(-42,31,-32,31);
    drawLine(-29,31,-19,31);


    //windows_&_doors_part_1
    glColor3ub(81,181,250);
    drawQuad(-24,35,-19,35,-19,55,-24,55);
    drawQuad(-30,45,-26,45,-26,55,-30,55);
    drawQuad(-36,45,-32,45,-32,55,-36,55);
    //drawQuad(-42,48,-38,48,-38,58,-42,58);
    drawQuad(-50,45,-46,45,-46,55,-50,55);
    //drawQuad(-54,38,-51,38,-51,58,-54,58);


    //windows_&_doors_part_2
    glPushMatrix();
    glTranslatef(50.0f, 0.0f,0.0f);
    glColor3ub(81,181,250);
    drawQuad(-24,35,-19,35,-19,55,-24,55);
    drawQuad(-30,45,-26,45,-26,55,-30,55);
    drawQuad(-36,45,-32,45,-32,55,-36,55);
    drawQuad(-50,45,-46,45,-46,55,-50,55);
    drawQuad(-56,35,-51,35,-51,55,-56,55);

    //body_lines
    glLineWidth(20);
    glColor3ub(73,73,73);
    drawLine(-55,31,-45,31);
    drawLine(-42,31,-32,31);
    drawLine(-29,31,-19,31);

    glPopMatrix();


    //windows_&_doors_part_3
    glPushMatrix();
    glTranslatef(100.0f, 0.0f,0.0f);
    glColor3ub(81,181,250);
    drawQuad(-24,35,-19,35,-19,55,-24,55);
    drawQuad(-30,45,-26,45,-26,55,-30,55);
    drawQuad(-36,45,-32,45,-32,55,-36,55);
    drawQuad(-50,45,-46,45,-46,55,-50,55);
    drawQuad(-56,35,-51,35,-51,55,-56,55);

    //body_lines
    glLineWidth(20);
    glColor3ub(73,73,73);
    drawLine(-55,31,-45,31);
    drawLine(-42,31,-32,31);
    drawLine(-29,31,-19,31);

    glPopMatrix();

    //body_4
    glPushMatrix();
    glTranslatef(100.0f, 0.0f,0.0f);
    //body
    glColor3ub(255,255,255);
    drawQuad(-10,24,35,24,35,60,-10,60);
    glPopMatrix();

    //windows_&_doors_part_4
    glPushMatrix();
    glTranslatef(150.0f, 0.0f,0.0f);
    //body_5
    glColor3ub(255,255,255);
    drawQuad(-10,24,42,24,42,60,-10,60);
    glColor3ub(81,181,250);
    drawQuad(-24,35,-19,35,-19,55,-24,55);
    drawQuad(-30,45,-26,45,-26,55,-30,55);
    drawQuad(-36,45,-32,45,-32,55,-36,55);
    drawQuad(-50,45,-46,45,-46,55,-50,55);
    drawQuad(-56,35,-51,35,-51,55,-56,55);

    //body_lines
    glLineWidth(20);
    glColor3ub(73,73,73);
    drawLine(-55,31,-45,31);
    drawLine(-42,31,-32,31);
    drawLine(-29,31,-19,31);

    glPopMatrix();

    //windows_&_doors_part_5
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);
    glColor3ub(81,181,250);
    drawQuad(-10,27,-16,27,-16,55,-10,55);
    drawQuad(-24,35,-19,35,-19,55,-24,55);
    drawQuad(-30,45,-26,45,-26,55,-30,55);
    drawQuad(-36,45,-32,45,-32,55,-36,55);
    drawQuad(-50,45,-46,45,-46,55,-50,55);
    drawQuad(-56,35,-51,35,-51,55,-56,55);

    //body_lines
    glLineWidth(20);
    glColor3ub(73,73,73);
    drawLine(-55,31,-45,31);
    drawLine(-42,31,-32,31);
    drawLine(-29,31,-19,31);

    glPopMatrix();

    //body_red_line
    glLineWidth(2);
    glColor3ub(255,0,0);
    drawLine(-50,41,-25,41);
    drawLine(0,41,25,41);
    drawLine(50,41,75,41);
    drawLine(100,41,125,41);
    drawLine(150,41,175,41);

    //train_connection
    glColor3ub(62,73,75);
    drawQuad(-15,38,-12.5,38,-12.5,54,-15,54);
    drawQuad(-12.5,38,-10,38,-10,54,-12.5,54);

    glLineWidth(2);
    glColor3ub(0,0,0);
    drawLine(-12,38,-13,40);
    drawLine(-13,40,-12,42);
    drawLine(-12,42,-13,44);
    drawLine(-13,44,-12,46);
    drawLine(-12,46,-13,48);
    drawLine(-13,48,-12,50);
    drawLine(-12,50,-13,52);
    drawLine(-13,52,-12,54);


    //train_connection_2
    glPushMatrix();
    glTranslatef(50.0f, 0.0f,0.0f);
    glColor3ub(62,73,75);
    drawQuad(-15,38,-12.5,38,-12.5,54,-15,54);
    drawQuad(-12.5,38,-10,38,-10,54,-12.5,54);

    glLineWidth(2);
    glColor3ub(0,0,0);
    drawLine(-12,38,-13,40);
    drawLine(-13,40,-12,42);
    drawLine(-12,42,-13,44);
    drawLine(-13,44,-12,46);
    drawLine(-12,46,-13,48);
    drawLine(-13,48,-12,50);
    drawLine(-12,50,-13,52);
    drawLine(-13,52,-12,54);
    glPopMatrix();

    //train_connection_3
    glPushMatrix();
    glTranslatef(100.0f, 0.0f,0.0f);
    glColor3ub(62,73,75);
    drawQuad(-15,38,-12.5,38,-12.5,54,-15,54);
    drawQuad(-12.5,38,-10,38,-10,54,-12.5,54);

    glLineWidth(2);
    glColor3ub(0,0,0);
    drawLine(-12,38,-13,40);
    drawLine(-13,40,-12,42);
    drawLine(-12,42,-13,44);
    drawLine(-13,44,-12,46);
    drawLine(-12,46,-13,48);
    drawLine(-13,48,-12,50);
    drawLine(-12,50,-13,52);
    drawLine(-13,52,-12,54);
    glPopMatrix();

    //train_connection_4
    glPushMatrix();
    glTranslatef(150.0f, 0.0f,0.0f);
    glColor3ub(62,73,75);
    drawQuad(-15,38,-12.5,38,-12.5,54,-15,54);
    drawQuad(-12.5,38,-10,38,-10,54,-12.5,54);

    glLineWidth(2);
    glColor3ub(0,0,0);
    drawLine(-12,38,-13,40);
    drawLine(-13,40,-12,42);
    drawLine(-12,42,-13,44);
    drawLine(-13,44,-12,46);
    drawLine(-12,46,-13,48);
    drawLine(-13,48,-12,50);
    drawLine(-12,50,-13,52);
    drawLine(-13,52,-12,54);
    glPopMatrix();

    textTrain(12.5,36,dhaka);
    textTrain(62.5,36,metro);
    textTrain(112.5,36,rail);
    //textTrain(17.5,36,bangladesh);


    glPopMatrix();
}

//lamp
void lamp(GLfloat r,GLfloat g,GLfloat b) //FUNC11
{
    //lamp_1
    glColor3ub(102,1,0);
    drawQuad(-48,-53,-47,-53,-47,-5,-48,-5);

    glColor3ub(255,255,0);
    DrawCircle(-44.5,-6,1.5,200);

    glColor3ub(102,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-49.0f,-5.0f);
    glVertex2f(-42.0f,-5.0f);
    glVertex2f(-44.0f,-1.0f);
    glVertex2f(-49.0f,-3.0f);
    glEnd();

    //lamp_2
    glPushMatrix();
    glTranslatef(90.0f, 0.0f,0.0f);
    glColor3ub(102,1,0);
    drawQuad(-48,-53,-47,-53,-47,-5,-48,-5);


    glColor3ub(255,255,0);
    DrawCircle(-50.5,-6,1.5,200);

    glColor3ub(102,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-46.0f,-5.0f);
    glVertex2f(-53.0f,-5.0f);
    glVertex2f(-51.0f,-1.0f);
    glVertex2f(-46.0f,-3.0f);
    glEnd();

    glPopMatrix();

    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

        //lamp_1
    glColor3ub(102,1,0);
    drawQuad(-48,-53,-47,-53,-47,-5,-48,-5);

    glColor3ub(255,255,0);
    DrawCircle(-44.5,-6,1.5,200);

    glColor3ub(102,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-49.0f,-5.0f);
    glVertex2f(-42.0f,-5.0f);
    glVertex2f(-44.0f,-1.0f);
    glVertex2f(-49.0f,-3.0f);
    glEnd();

    //lamp_2
    glPushMatrix();
    glTranslatef(90.0f, 0.0f,0.0f);
    glColor3ub(102,1,0);
    drawQuad(-48,-53,-47,-53,-47,-5,-48,-5);


    glColor3ub(255,255,0);
    DrawCircle(-50.5,-6,1.5,200);

    glColor3ub(102,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-46.0f,-5.0f);
    glVertex2f(-53.0f,-5.0f);
    glVertex2f(-51.0f,-1.0f);
    glVertex2f(-46.0f,-3.0f);
    glEnd();

    glPopMatrix();

    glPopMatrix();
}

//lamp_night
void lamp_night()//FUNC12
{
    //lamp_1
    glBegin(GL_POLYGON);

    glColor3ub(232,211,133);
    glVertex2f(-46.0f,-6.0f);

    glColor3ub(235,240,136);
    glVertex2f(-43.0f,-6.0f);

    glColor3ub(248,250,207);
    glVertex2f(-38.0f,-52.0f);

    glColor3ub(255,255,191);
    glVertex2f(-47.0f,-52.0f);
    glEnd();


    //lamp_2
    glPushMatrix();
    glTranslatef(87.0f, 0.0f,0.0f);
    glBegin(GL_POLYGON);

    glColor3ub(232,211,133);
    glVertex2f(-46.0f,-6.0f);

    glColor3ub(235,240,136);
    glVertex2f(-49.0f,-6.0f);

    glColor3ub(248,250,207);
    glVertex2f(-54.0f,-52.0f);

    glColor3ub(255,255,191);
    glVertex2f(-45.0f,-52.0f);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();


    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

        //lamp_1
    glBegin(GL_POLYGON);

    glColor3ub(232,211,133);
    glVertex2f(-46.0f,-6.0f);

    glColor3ub(235,240,136);
    glVertex2f(-43.0f,-6.0f);

    glColor3ub(248,250,207);
    glVertex2f(-38.0f,-52.0f);

    glColor3ub(255,255,191);
    glVertex2f(-47.0f,-52.0f);
    glEnd();


    //lamp_2
    glPushMatrix();
    glTranslatef(87.0f, 0.0f,0.0f);
    glBegin(GL_POLYGON);

    glColor3ub(232,211,133);
    glVertex2f(-46.0f,-6.0f);

    glColor3ub(235,240,136);
    glVertex2f(-49.0f,-6.0f);

    glColor3ub(248,250,207);
    glVertex2f(-54.0f,-52.0f);

    glColor3ub(255,255,191);
    glVertex2f(-45.0f,-52.0f);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();

    glPopMatrix();
}

//chair
void chair() //FUNC13
{
    //chair_1
    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-40,-48,-40,-40);
    drawLine(-22,-48,-22,-40);

    glLineWidth(10);
    glColor3ub(93,38,12);
    drawLine(-42,-40,-20,-40);

    glLineWidth(7);
    glColor3ub(93,38,12);
    drawLine(-40,-35,-22,-35);
    drawLine(-40,-30,-22,-30);
    drawLine(-40,-25,-22,-25);
    //drawLine(-40,-20,-26,-20);

    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-38,-40,-38,-22);
    drawLine(-24,-40,-24,-22);


    //chair_2
    glPushMatrix();
    glTranslatef(56.0f, 0.0f,0.0f);
    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-40,-48,-40,-40);
    drawLine(-22,-48,-22,-40);

    glLineWidth(10);
    glColor3ub(93,38,12);
    drawLine(-42,-40,-20,-40);

    glLineWidth(7);
    glColor3ub(93,38,12);
    drawLine(-40,-35,-22,-35);
    drawLine(-40,-30,-22,-30);
    drawLine(-40,-25,-22,-25);
    //drawLine(-40,-20,-26,-20);

    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-38,-40,-38,-22);
    drawLine(-24,-40,-24,-22);

    glPopMatrix();

    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

    //chair_1
    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-40,-48,-40,-40);
    drawLine(-22,-48,-22,-40);

    glLineWidth(10);
    glColor3ub(93,38,12);
    drawLine(-42,-40,-20,-40);

    glLineWidth(7);
    glColor3ub(93,38,12);
    drawLine(-40,-35,-22,-35);
    drawLine(-40,-30,-22,-30);
    drawLine(-40,-25,-22,-25);
    //drawLine(-40,-20,-26,-20);

    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-38,-40,-38,-22);
    drawLine(-24,-40,-24,-22);


    //chair_2
    glPushMatrix();
    glTranslatef(56.0f, 0.0f,0.0f);
    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-40,-48,-40,-40);
    drawLine(-22,-48,-22,-40);

    glLineWidth(10);
    glColor3ub(93,38,12);
    drawLine(-42,-40,-20,-40);

    glLineWidth(7);
    glColor3ub(93,38,12);
    drawLine(-40,-35,-22,-35);
    drawLine(-40,-30,-22,-30);
    drawLine(-40,-25,-22,-25);
    //drawLine(-40,-20,-26,-20);

    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-38,-40,-38,-22);
    drawLine(-24,-40,-24,-22);

    glPopMatrix();

    glPopMatrix();
}

//sky_&_background
void sky(GLfloat r,GLfloat g,GLfloat b,GLfloat r1,GLfloat g1,GLfloat b1) //FUNC14
{
    //background_color
    glBegin(GL_QUADS);
    glColor3ub(r,g,b);
    glVertex2f(-100.0f, -14.0f);
    glVertex2f(100.0f, -14.0f);
        glColor3ub(r1,g1,b1);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(-100.0f, 50.0f);
    glEnd();

    //gradient
   /* glBegin(GL_QUADS);
    glColor3ub(r,g,b);
    glVertex2f(-100.0f, 40.0f);
    glVertex2f(100.0f, 40.0f);

    glColor3ub(r1,g1,b1);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(-100.0f, 50.0f);
    glEnd();*/

    //sky_color
    glBegin(GL_QUADS);
    glColor3ub(r1,g1,b1);
    glVertex2f(-100.0f, 50.0f);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(100.0f, 200.0f);
    glVertex2f(-100.0f, 200.0f);
    glEnd();


    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

        //background_color
    glBegin(GL_QUADS);
    glColor3ub(r,g,b);
    glVertex2f(-100.0f, -14.0f);
    glVertex2f(100.0f, -14.0f);
        glColor3ub(r1,g1,b1);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(-100.0f, 50.0f);
    glEnd();

    //sky_color
    glBegin(GL_QUADS);
    glColor3ub(r1,g1,b1);
    glVertex2f(-100.0f, 50.0f);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(100.0f, 200.0f);
    glVertex2f(-100.0f, 200.0f);
    glEnd();

    glPopMatrix();

}

//cloud
void cloud(GLfloat r,GLfloat g,GLfloat b) //FUNC15
{
    glPushMatrix();
    glTranslatef(position_cloud, 0.0f,0.0f);

    //small_clouds
    glPushMatrix();
    glTranslatef(70.0f, 20.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70.0f, 30.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    //big_clouds

    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-3,142,-3,145,-20,145);

    //cloud
    DrawCircle(-18,147,5,50);
    DrawCircle(-15,153,4,50);
    DrawCircle(-11,157,4,50);
    DrawCircle(-9,153,4,50);
    DrawCircle(-6,147,5,50);
    DrawCircle(-11,147,4,50);


    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

    glPushMatrix();
    glTranslatef(70.0f, 20.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70.0f, 30.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    //big_clouds

    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-3,142,-3,145,-20,145);

    //cloud
    DrawCircle(-18,147,5,50);
    DrawCircle(-15,153,4,50);
    DrawCircle(-11,157,4,50);
    DrawCircle(-9,153,4,50);
    DrawCircle(-6,147,5,50);
    DrawCircle(-11,147,4,50);


    glPopMatrix();


    //fourth
    glPushMatrix();
    glTranslatef(400.0f, 0.0f,0.0f);

    glPushMatrix();
    glTranslatef(70.0f, 20.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70.0f, 30.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    //big_clouds

    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-3,142,-3,145,-20,145);

    //cloud
    DrawCircle(-18,147,5,50);
    DrawCircle(-15,153,4,50);
    DrawCircle(-11,157,4,50);
    DrawCircle(-9,153,4,50);
    DrawCircle(-6,147,5,50);
    DrawCircle(-11,147,4,50);


    glPopMatrix();


    //third
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

    glPushMatrix();
    glTranslatef(70.0f, 20.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70.0f, 30.0f,0.0f);
    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-5,142,-5,145,-20,145);

    //cloud
    DrawCircle(-18,144.5,3,50);
    DrawCircle(-14,147,4,50);
    DrawCircle(-12,150,3,50);
    DrawCircle(-10,147,4,50);
    DrawCircle(-6,144.5,3,50);

    glPopMatrix();

    //big_clouds

    //cloud_base
    glColor3ub(r,g,b);
    drawQuad(-20,142,-3,142,-3,145,-20,145);

    //cloud
    DrawCircle(-18,147,5,50);
    DrawCircle(-15,153,4,50);
    DrawCircle(-11,157,4,50);
    DrawCircle(-9,153,4,50);
    DrawCircle(-6,147,5,50);
    DrawCircle(-11,147,4,50);


    glPopMatrix();


    glPopMatrix();

}

void sun() //FUNC16
{
    glPushMatrix();
    glTranslatef(0.0f, sun_position,0.0f);
    glColor3ub(248,161,21);
    DrawCircle(175,70,15,200);
    glPopMatrix();
}

//stars
void stars() //FUNC17
{
    //random_stars
    for(int i=0; i<10; i++)
    {
        int x = rand() % 400 - 100;
        int y = rand() % 300 + 70;
        glColor3ub(255,255,255);
        DrawCircle(x,y,0.5,200);
    }

    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);

    glPushMatrix();
    glTranslatef(60.0f,2.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(120.0f,-3.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150.0f,0.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);
    glPopMatrix();


// ...................................

    glPushMatrix();
    glTranslatef(180.0f,-2.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);

    glPushMatrix();
    glTranslatef(60.0f,2.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(120.0f,-3.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150.0f,0.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);
    glPopMatrix();

        glPushMatrix();
    glTranslatef(200.0f,0.0f,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(-100,75,0.5,200);
    DrawCircle(-90,90,0.5,200);
    DrawCircle(-97,110,0.5,200);
    DrawCircle(-80,104,0.5,200);
    DrawCircle(-83,131,0.5,200);
    DrawCircle(-78,114,0.5,200);
    DrawCircle(-79,156,0.5,200);
    DrawCircle(-69,143,0.5,200);
    DrawCircle(-67,132,0.5,200);
    DrawCircle(-60,90,0.5,200);
    DrawCircle(-57,108,0.5,200);
    DrawCircle(-59,124,0.5,200);
    DrawCircle(-98,170,0.5,200);
    DrawCircle(-94,153,0.5,200);
    DrawCircle(-100,134,0.5,200);
    DrawCircle(-99,187,0.5,200);
    glPopMatrix();


     glPopMatrix();



}

//car
void car1() //FUNC18
{
    glPushMatrix();
    glTranslatef(position_car_1, 0.0f,0.0f);
    //car1
    glPushMatrix();
    glTranslatef(130.0f, 30.0f,0.0f);
    //body
    glBegin(GL_POLYGON);
    glColor3ub(52,79,114);
    glVertex2f(55.0f,-95.0f);
    glVertex2f(10.0f,-95.0f);
    glVertex2f(8.0f,-93.0f);
    glVertex2f(8.0f,-80.0f);
    glVertex2f(10.0f,-78.0f);

    //glColor3ub(251,107,107);
    glVertex2f(25.0f,-75.0f);
    glVertex2f(30.0f,-65.0f);
    glVertex2f(50.0f,-65.0f);
    glVertex2f(55.0f,-75.0f);
    glVertex2f(65.0f,-78.0f);
    glVertex2f(67.0f,-80.0f);
    glVertex2f(67.0f,-93.0f);
    glVertex2f(65.0f,-95.0f);
    glEnd();


    //body
    glBegin(GL_POLYGON);
    glColor3ub(255,201,14);
    glVertex2f(12.0f,-77.5f);
    glVertex2f(12.0f,-80.0f);
    glVertex2f(8.0f,-80.0f);
    glVertex2f(10.0f,-78.0f);
    glVertex2f(12.0f,-77.5f);
    glEnd();



    //windows
    glColor3ub(44,174,236);
    glBegin(GL_POLYGON);
    glVertex2f(39.0f,-75.0f);
    glVertex2f(27.0f,-75.0f);
    glVertex2f(31.5f,-66.0f);
    glVertex2f(39.0f,-66.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(41.0f,-75.0f);
    glVertex2f(53.0f,-75.0f);
    glVertex2f(48.5f,-66.0f);
    glVertex2f(41.0f,-66.0f);
    glEnd();

    //window_lines
    glLineWidth(4);
    glColor3ub(0,0,0);
    drawLine(39,-75,27,-75);
    drawLine(27,-75,31.5,-66);
    drawLine(31.5,-66,39,-66);
    drawLine(39,-66,39,-75);

    drawLine(41,-75,53,-75);
    drawLine(53,-75,48.5,-66);
    drawLine(48.5,-66,41,-66);
    drawLine(41,-66,41,-75);

    //down_line
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(65,-95,10,-95);

    //tyre
    glColor3ub(14,12,12);
    DrawCircle(20,-93,6.5,200);
    DrawCircle(55,-93,6.5,200);

    glColor3ub(124,123,128);
    DrawCircle(20,-93,2.5,200);
    DrawCircle(55,-93,2.5,200);

    //handle
    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(53,-78,50,-78);
    drawLine(39,-78,36,-78);

    glPopMatrix();


    glPopMatrix();



}

void car2() //FUNC19
{

    glPushMatrix();
    glTranslatef(position_car_2, 0.0f,0.0f);


    glPushMatrix();
    glTranslatef(0.0f, 6.0f,0.0f);
    //body
    glBegin(GL_POLYGON);
    glColor3ub(216,50,63);
    glVertex2f(-55.0f,-95.0f);
    glVertex2f(-10.0f,-95.0f);
    glVertex2f(-8.0f,-93.0f);
    glVertex2f(-8.0f,-80.0f);
    glVertex2f(-10.0f,-78.0f);

    //glColor3ub(251,107,107);
    glVertex2f(-25.0f,-75.0f);
    glVertex2f(-30.0f,-65.0f);
    glVertex2f(-50.0f,-65.0f);
    glVertex2f(-55.0f,-75.0f);
    glVertex2f(-65.0f,-78.0f);
    glVertex2f(-67.0f,-80.0f);
    glVertex2f(-67.0f,-93.0f);
    glVertex2f(-65.0f,-95.0f);
    glEnd();


    //body
    glBegin(GL_POLYGON);
    glColor3ub(255,201,14);
    glVertex2f(-12.0f,-77.5f);
    glVertex2f(-12.0f,-80.0f);
    glVertex2f(-8.0f,-80.0f);
    glVertex2f(-10.0f,-78.0f);
    glVertex2f(-12.0f,-77.5f);
    glEnd();



    //windows
    glColor3ub(44,174,236);
    glBegin(GL_POLYGON);
    glVertex2f(-39.0f,-75.0f);
    glVertex2f(-27.0f,-75.0f);
    glVertex2f(-31.5f,-66.0f);
    glVertex2f(-39.0f,-66.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-41.0f,-75.0f);
    glVertex2f(-53.0f,-75.0f);
    glVertex2f(-48.5f,-66.0f);
    glVertex2f(-41.0f,-66.0f);
    glEnd();

    //window_lines
    glLineWidth(4);
    glColor3ub(0,0,0);
    drawLine(-39,-75,-27,-75);
    drawLine(-27,-75,-31.5,-66);
    drawLine(-31.5,-66,-39,-66);
    drawLine(-39,-66,-39,-75);

    drawLine(-41,-75,-53,-75);
    drawLine(-53,-75,-48.5,-66);
    drawLine(-48.5,-66,-41,-66);
    drawLine(-41,-66,-41,-75);

    //down_line
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(-65,-95,-10,-95);

    //tyre
    glColor3ub(14,12,12);
    DrawCircle(-20,-93,6.5,200);
    DrawCircle(-55,-93,6.5,200);

    glColor3ub(124,123,128);
    DrawCircle(-20,-93,2.5,200);
    DrawCircle(-55,-93,2.5,200);

    //handle
    glLineWidth(5);
    glColor3ub(93,38,12);
    drawLine(-53,-78,-50,-78);
    drawLine(-39,-78,-36,-78);

    glPopMatrix();

    glPopMatrix();

}

//****************** SCENE 2 ******************

//train_platform_mountain
void platform_mountain() //FUNC20
{
    //pillar_1
    glPushMatrix();
    glTranslatef(130.0f, 0.0f,0.0f);
    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_1_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_1_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();



    //pillar_2
    glPushMatrix();
    glTranslatef(15.0f, 0.0f,0.0f);

    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_2_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_2_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();

    //platform
    glColor3ub(169,169,169);
    drawQuad(-100,20,100,20,100,28,-100,28);

    //rail line
    glLineWidth(8);
    glColor3ub(73,73,73);
    drawLine(-100,24,100,24);


    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

    //pillar_1
    glPushMatrix();
    glTranslatef(130.0f, 0.0f,0.0f);
    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_1_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_1_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();



    //pillar_2
    glPushMatrix();
    glTranslatef(15.0f, 0.0f,0.0f);

    glColor3ub(73,73,73);
    drawQuad(-80,-30,-70,-30,-70,5,-80,5);

    //pillar_2_upper_portion
    glBegin(GL_POLYGON);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-55.0f,20.0f);
    glVertex2f(-95.0f,20.0f);
    glVertex2f(-80.0f,5.0f);
    glEnd();

    //pillar_2_interior
    glColor3ub(131,131,131);
    drawQuad(-80,-30,-77,-30,-77,0,-80,0);
    drawQuad(-70,-30,-73,-30,-73,0,-70,0);

    glBegin(GL_POLYGON);
    glVertex2f(-73.0f,5.0f);
    glVertex2f(-70.0f,5.0f);
    glVertex2f(-65.0f,10.0f);
    glVertex2f(-73.0f,10.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-77.0f,5.0f);
    glVertex2f(-80.0f,5.0f);
    glVertex2f(-85.0f,10.0f);
    glVertex2f(-77.0f,10.0f);
    glEnd();

    glPopMatrix();

    //platform
    glColor3ub(169,169,169);
    drawQuad(-100,20,100,20,100,28,-100,28);

    //rail line
    glLineWidth(8);
    glColor3ub(73,73,73);
    drawLine(-100,24,100,24);

    glPopMatrix();

}
//sun_mountain
void sun_mountain() //FUNC21
{
    glPushMatrix();
    glTranslatef(0.0f, sun_position2,0.0f);
    glColor3ub(248,161,21);
    DrawCircle(97,70,30,200);
    glPopMatrix();
}

void sun_evening() //FUNC22
{
    glPushMatrix();
    glTranslatef(0.0f, sun_position2,0.0f);
    glColor3ub(240,236,179);
    DrawCircle(97,70,30,200);
    glPopMatrix();
}

void mountains() //FUNC23
{

    glPushMatrix();
    glTranslatef(0.0f,32.0f,0.0f);
    //mountains_upper
    glColor3ub(146,79,81);
    glBegin(GL_POLYGON);
    glVertex2f(-100.0f, 15.0f); //8
    glVertex2f(-90.0f, 20.0f); //7
    glVertex2f(-76.0f, 38.0f); //6
    glVertex2f(-64.0f, 40.0f); //6
    glVertex2f(-48.0f, 60.0f); //5
    glVertex2f(-38.0f, 60.0f); //4
    glVertex2f(-32.0f, 62.0f); //3
    glVertex2f(-26.0f, 62.0f);

    glVertex2f(-8.0f, 78.0f); //6
    glVertex2f(2.0f, 78.0f); //6
    glVertex2f(20.0f, 60.0f); //5
    glVertex2f(30.0f, 56.0f); //4
    glVertex2f(40.0f, 60.0f); //3
    glVertex2f(48.0f, 60.0f);

    glVertex2f(74.0f, 32.0f); //6
    glVertex2f(100.0f, 15.0f); //6

    glEnd();

    glColor3ub(146,79,81);
    DrawCircle(-45,55,6,200);

    glColor3ub(146,79,81);
    DrawCircle(-3,72,8,200);

    glColor3ub(146,79,81);
    DrawCircle(44,55,6,200);



    //mountains_lower
    glColor3ub(45,151,98);
    glBegin(GL_POLYGON);
    glVertex2f(-100.0f, 15.0f); //8
    glVertex2f(-92.0f, 18.0f); //7
    glVertex2f(-76.0f, 24.0f); //6
    glVertex2f(-64.0f, 26.0f); //6
    glVertex2f(-48.0f, 44.0f); //5
    glVertex2f(-38.0f, 44.0f); //4
    glVertex2f(-32.0f, 46.0f); //3
    glVertex2f(-26.0f, 46.0f);

    glVertex2f(-8.0f, 55.0f); //6
    glVertex2f(2.0f, 55.0f); //6
    glVertex2f(20.0f, 44.0f); //5
    glVertex2f(30.0f, 35.0f); //4
    glVertex2f(40.0f, 44.0f); //3
    glVertex2f(48.0f, 44.0f);

    glVertex2f(74.0f, 22.0f); //6
    glVertex2f(100.0f, 15.0f); //6

    glEnd();

    glColor3ub(45,151,98);
    DrawCircle(-45,39,6,200);

    glColor3ub(45,151,98);
    DrawCircle(-3,49,8,200);

    glColor3ub(45,151,98);
    DrawCircle(44,39,6,200);

    glPopMatrix();



    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

    glPushMatrix();
    glTranslatef(0.0f,32.0f,0.0f);
    //mountains_upper
    glColor3ub(146,79,81);
    glBegin(GL_POLYGON);
    glVertex2f(-100.0f, 15.0f); //8
    glVertex2f(-90.0f, 20.0f); //7
    glVertex2f(-76.0f, 38.0f); //6
    glVertex2f(-64.0f, 40.0f); //6
    glVertex2f(-48.0f, 60.0f); //5
    glVertex2f(-38.0f, 60.0f); //4
    glVertex2f(-32.0f, 62.0f); //3
    glVertex2f(-26.0f, 62.0f);

    glVertex2f(-8.0f, 78.0f); //6
    glVertex2f(2.0f, 78.0f); //6
    glVertex2f(20.0f, 60.0f); //5
    glVertex2f(30.0f, 56.0f); //4
    glVertex2f(40.0f, 60.0f); //3
    glVertex2f(48.0f, 60.0f);

    glVertex2f(74.0f, 32.0f); //6
    glVertex2f(100.0f, 15.0f); //6

    glEnd();

    glColor3ub(146,79,81);
    DrawCircle(-45,55,6,200);

    glColor3ub(146,79,81);
    DrawCircle(-3,72,8,200);

    glColor3ub(146,79,81);
    DrawCircle(44,55,6,200);



    //mountains_lower
    glColor3ub(45,151,98);
    glBegin(GL_POLYGON);
    glVertex2f(-100.0f, 15.0f); //8
    glVertex2f(-92.0f, 18.0f); //7
    glVertex2f(-76.0f, 24.0f); //6
    glVertex2f(-64.0f, 26.0f); //6
    glVertex2f(-48.0f, 44.0f); //5
    glVertex2f(-38.0f, 44.0f); //4
    glVertex2f(-32.0f, 46.0f); //3
    glVertex2f(-26.0f, 46.0f);

    glVertex2f(-8.0f, 55.0f); //6
    glVertex2f(2.0f, 55.0f); //6
    glVertex2f(20.0f, 44.0f); //5
    glVertex2f(30.0f, 35.0f); //4
    glVertex2f(40.0f, 44.0f); //3
    glVertex2f(48.0f, 44.0f);

    glVertex2f(74.0f, 22.0f); //6
    glVertex2f(100.0f, 15.0f); //6

    glEnd();

    glColor3ub(45,151,98);
    DrawCircle(-45,39,6,200);

    glColor3ub(45,151,98);
    DrawCircle(-3,49,8,200);

    glColor3ub(45,151,98);
    DrawCircle(44,39,6,200);

    glPopMatrix();

    glPopMatrix();

}

//footpath
void footpath()//FUNC24
{


    //footpath_up
    glColor3ub(131,131,131);
    drawQuad(-100,-50,100,-50,100,-56,-100,-56);

    //gray_shade_up
    glColor3ub(131,129,129);
    drawQuad(-100,-48,100,-48,100,-50,-100,-50);

    //dark_up
    glLineWidth(2);
    glColor3ub(0,0,0);
    drawLine(-100,-50,100,-50);



    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);
    //footpath_up
    glColor3ub(131,131,131);
    drawQuad(-100,-50,100,-50,100,-56,-100,-56);

    //gray_shade_up
    glColor3ub(131,129,129);
    drawQuad(-100,-48,100,-48,100,-50,-100,-50);

    //dark_up
    glLineWidth(2);
    glColor3ub(0,0,0);
    drawLine(-100,-50,100,-50);
    glPopMatrix();

}

//road
void road()//FUNC25
{
    //road_up_down
    glColor3ub(47,47,47);
    drawQuad(-100,-100,100,-100,100,-48,-100,-48);

    //divider
    glLineWidth(5);
    glColor3ub(255, 255, 255);
    drawLine(-100,-79,-85,-79);
    drawLine(-77,-79,-55,-79);
    drawLine(-47,-79,-22,-79);
    drawLine(-14,-79,8,-79);
    drawLine(16,-79,38,-79);
    drawLine(46,-79,68,-79);
    drawLine(76,-79,100,-79);


    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);
    //road_up_down
    glColor3ub(47,47,47);
    drawQuad(-100,-100,100,-100,100,-48,-100,-48);

    //divider
    glLineWidth(5);
    glColor3ub(255, 255, 255);
    drawLine(-100,-79,-85,-79);
    drawLine(-77,-79,-55,-79);
    drawLine(-47,-79,-22,-79);
    drawLine(-14,-79,8,-79);
    drawLine(16,-79,38,-79);
    drawLine(46,-79,68,-79);
    drawLine(76,-79,100,-79);
    glPopMatrix();

}
char text1[] = "MEAT CART";
char text2[] = "AAM GHORR";


void text( float x, float y, char *st)//FUNC26
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,1.0,0.7);
    glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }

}

void moon()//FUNC27
{

    glPushMatrix();

    glTranslatef(20,85,0.0f);
    glColor3ub(255,255,255);
    DrawCircle(175,70,12,200);

    glColor3ub(20,45,86);

    DrawCircle(177,74,11,200);

    glPopMatrix();
}

void drawBuilding(GLint x1, GLint x2,GLint y2)//FUNC28
{
    glBegin(GL_QUADS);
    glVertex2f(x1,-14);
    glVertex2f(x2,-14);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    glEnd();
}

void drawBuildingWindows(float x, int y, int n, float point)//FUNC29
{

	for(int i=14; i<n;i+=9)
    {
        glPointSize(point);
        glBegin(GL_POINTS);

        glVertex2f(x,y);
        y+=10;
        glEnd();
    }
}

void buildingWindows(int r, int g,  int b)//FUNC30
{
            glColor3ub(r,g,b);

    drawBuildingWindows(-96,5,90,10);
    drawBuildingWindows(-92,5,90,10);



    drawBuildingWindows(-76,5,100,10);
    drawBuildingWindows(-71,5,100,10);

    drawBuildingWindows(-29,5,70,12);
    drawBuildingWindows(-21,5,70,12);



     drawBuildingWindows(1,5,80,15);
     drawBuildingWindows(9,5,80,15);


       glColor3ub(46, 57, 59);
      drawBuildingWindows(35,5,90,20);
     drawBuildingWindows(53,5,90,20);
      drawBuildingWindows(70,5,90,20);

           glColor3ub(r,g,b);
     drawBuildingWindows(35,5,90,18);
     drawBuildingWindows(53,5,90,18);
      drawBuildingWindows(70,5,90,18);

}

void buildings(GLfloat r,GLfloat g,GLfloat b)//FUNC31
{
    glColor3ub(r,g,b);
     drawBuilding(-100,-88,100);
     //drawBuilding(-90,-86,80);
     drawBuilding(-80,-67,120);
     drawBuilding(-35,-15,80);
    // drawBuilding(-20,-15,80);
     drawBuilding(-5,15,90);

    glColor3ub(r,g,b);
     drawBuilding(25,80,100);



     glColor3ub(73, 84, 89);
     drawQuad(22,107,83,107,83,135,22,135);
      drawQuad(28,100,30,100,30,107,28,107);
      drawQuad(75,100,77,100,77,107,75,107);


     glColor3ub(r,g,b);
     drawQuad(-60,-14,-40,-14,-48,150,-58,142);
}

//human
void human()//FUNC32
{
    //hair
    glPushMatrix();
    glTranslatef(0.0f, 2.0f,0.0f);
    glColor3ub(96,56,19);
    DrawCircle(-10,-16,5,50);
    glPopMatrix();

    //face
    glColor3ub(244,206,170);
    DrawCircle(-10,-16,5,50);

    //leg
    glColor3ub(42,61,75);
    drawQuad(-12,-33,-11,-33,-11,-45,-12,-45);
    drawQuad(-8,-33,-9,-33,-9,-45,-8,-45);

    //body
    glColor3ub(83,109,132);
    drawQuad(-13,-33,-7,-33,-7,-20,-13,-20);
    DrawCircle(-10,-32,3,50);

    //shoe
    glColor3ub(0,0,0);
    drawQuad(-11,-45,-13,-45,-13,-48,-11,-48);
    drawQuad(-9,-45,-7,-45,-7,-48,-9,-48);

    //hands
    glLineWidth(10);
    glColor3ub(83,109,132);
    drawLine(-8,-21,-5,-24);
    drawLine(-5,-24,-8,-27);

    drawLine(-12,-21,-15,-24);
    drawLine(-15,-24,-12,-27);

    //eyes
    glLineWidth(10);
    glColor3ub(0,0,0);
    drawLine(-12,-15,-11,-15);
    drawLine(-9,-15,-8,-15);
    drawLine(-11,-18,-9,-18);

}

//scene 2
void sea()//FUNC33
{

    //mountain_sea
    glBegin(GL_POLYGON);
    glColor3ub(44,159,206);
    glVertex2f(-100.0f, 40.0f); //8
    glVertex2f(100.0f, 40.0f); //7
    glColor3ub(45,151,98);
    glVertex2f(100.0f, 47.0f); //6
    glVertex2f(-100.0f, 47.0f); //6


    glEnd();


    //sea_upper
    glColor3ub(44,159,206);
    drawQuad(-100,-50,100,-50,100,40,-100,40);

    glPushMatrix();
    glTranslatef(0.0f,-15.0f,0.0f);

    //sea_lower
    glColor3ub(22,126,153);
    drawQuad(-100,-100,100,-100,100,-60,-100,-60);

    //sea_middle
    glColor3ub(38,141,174);
    drawQuad(-100,-60,100,-60,100,-35,-100,-35);

    glPushMatrix();
    glTranslatef(position_wave,0.0f,0.0f);

    //float_lower
    glColor3ub(22,126,153);
    DrawCircle(-92.5,-62.5,7.5,200);
    DrawCircle(-64.5,-62.5,7.5,200);
    DrawCircle(-36.5,-62.5,7.5,200);
    DrawCircle(-8.5,-62.5,7.5,200);
    DrawCircle(19.5,-62.5,7.5,200);
    DrawCircle(47.5,-62.5,7.5,200);
    DrawCircle(75.5,-62.5,7.5,200);
    DrawCircle(103.5,-62.5,7.5,200);

    glColor3ub(38,141,174);
    DrawCircle(-78.5,-57.5,7.5,200);
    DrawCircle(-50.5,-57.5,7.5,200);
    DrawCircle(-22.5,-57.5,7.5,200);
    DrawCircle(5.5,-57.5,7.5,200);
    DrawCircle(33.5,-57.5,7.5,200);
    DrawCircle(61.5,-57.5,7.5,200);
    DrawCircle(89.5,-57.5,7.5,200);


    //float_middle
    glColor3ub(38,141,174);
    DrawCircle(-107.5,-37.5,7.5,200);
    DrawCircle(-79.5,-37.5,7.5,200);
    DrawCircle(-51.5,-37.5,7.5,200);
    DrawCircle(-23.5,-37.5,7.5,200);
    DrawCircle(4.5,-37.5,7.5,200);
    DrawCircle(32.5,-37.5,7.5,200);
    DrawCircle(60.5,-37.5,7.5,200);
    DrawCircle(88.5,-37.5,7.5,200);

    glColor3ub(44,159,206);
    DrawCircle(-93.5,-32.5,7.5,200);
    DrawCircle(-65.5,-32.5,7.5,200);
    DrawCircle(-37.5,-32.5,7.5,200);
    DrawCircle(-9.5,-32.5,7.5,200);
    DrawCircle(18.5,-32.5,7.5,200);
    DrawCircle(46.5,-32.5,7.5,200);
    DrawCircle(74.5,-32.5,7.5,200);
    DrawCircle(102.5,-32.5,7.5,200);

    glPopMatrix();

    glPopMatrix();

    //second
    glPushMatrix();
    glTranslatef(200.0f, 0.0f,0.0f);

    //mountain_sea
    glBegin(GL_POLYGON);
    glColor3ub(44,159,206);
    glVertex2f(-100.0f, 40.0f); //8
    glVertex2f(100.0f, 40.0f); //7
    glColor3ub(45,151,98);
    glVertex2f(100.0f, 47.0f); //6
    glVertex2f(-100.0f, 47.0f); //6


    glEnd();


    //sea_upper
    glColor3ub(44,159,206);
    drawQuad(-100,-50,100,-50,100,40,-100,40);

    glPushMatrix();
    glTranslatef(0.0f,-15.0f,0.0f);

    //sea_lower
    glColor3ub(22,126,153);
    //drawQuad(-100,-100,100,-100,100,15,-100,15);
    drawQuad(-100,-100,100,-100,100,-60,-100,-60);

    //sea_middle
    glColor3ub(38,141,174);
    drawQuad(-100,-60,100,-60,100,-35,-100,-35);


    glPushMatrix();
    glTranslatef(position_wave,0.0f,0.0f);
    //float_lower
    glColor3ub(22,126,153);
    DrawCircle(-92.5,-62.5,7.5,200);
    DrawCircle(-64.5,-62.5,7.5,200);
    DrawCircle(-36.5,-62.5,7.5,200);
    DrawCircle(-8.5,-62.5,7.5,200);
    DrawCircle(19.5,-62.5,7.5,200);
    DrawCircle(47.5,-62.5,7.5,200);
    DrawCircle(75.5,-62.5,7.5,200);
    DrawCircle(103.5,-62.5,7.5,200);

    glColor3ub(38,141,174);
    DrawCircle(-78.5,-57.5,7.5,200);
    DrawCircle(-50.5,-57.5,7.5,200);
    DrawCircle(-22.5,-57.5,7.5,200);
    DrawCircle(5.5,-57.5,7.5,200);
    DrawCircle(33.5,-57.5,7.5,200);
    DrawCircle(61.5,-57.5,7.5,200);
    DrawCircle(89.5,-57.5,7.5,200);


    //float_middle
    glColor3ub(38,141,174);
    DrawCircle(-107.5,-37.5,7.5,200);
    DrawCircle(-79.5,-37.5,7.5,200);
    DrawCircle(-51.5,-37.5,7.5,200);
    DrawCircle(-23.5,-37.5,7.5,200);
    DrawCircle(4.5,-37.5,7.5,200);
    DrawCircle(32.5,-37.5,7.5,200);
    DrawCircle(60.5,-37.5,7.5,200);
    DrawCircle(88.5,-37.5,7.5,200);

    glColor3ub(44,159,206);
    DrawCircle(-93.5,-32.5,7.5,200);
    DrawCircle(-65.5,-32.5,7.5,200);
    DrawCircle(-37.5,-32.5,7.5,200);
    DrawCircle(-9.5,-32.5,7.5,200);
    DrawCircle(18.5,-32.5,7.5,200);
    DrawCircle(46.5,-32.5,7.5,200);
    DrawCircle(74.5,-32.5,7.5,200);
    DrawCircle(102.5,-32.5,7.5,200);

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

}

void largeShip()//FUNC34
{

    //chimney

    glColor3ub(181, 36, 14);
    drawQuad(10,-24,26,-24,26,10,10,10);

    glColor3ub(140, 28, 11);
    drawQuad(20,-24,26,-24,26,10,20,10);

    glColor3ub(133, 133, 133);
    drawQuad(10,-10,26,-10,26,-4,10,-4);

    glPushMatrix();
    glTranslatef(24, 0.0f,0.0f);

    glColor3ub(181, 36, 14);
    drawQuad(10,-24,26,-24,26,10,10,10);

    glColor3ub(140, 28, 11);
    drawQuad(20,-24,26,-24,26,10,20,10);

    glColor3ub(133, 133, 133);
    drawQuad(10,-10,26,-10,26,-4,10,-4);

    glPopMatrix();




    glColor3f(1.0f, 1.0f, 1.0f);
    drawQuad(-72,-47,68,-55,68,-16,-50,-14);

    drawQuad(68,-58,72,-58,72,-38,68,-36);

    //lower window
    glColor3ub(77, 198, 255);
    drawQuad(-69,-42,52,-48,60,-40,-63,-33);


    glColor3ub(77, 198, 255);
    drawQuad(-58,-26,50,-31,58,-22,-53,-18);

    glBegin(GL_POLYGON);
    glColor3ub(9, 12, 36);
    glVertex2f(-80,-80);
    glVertex2f(84,-80);
    glVertex2f(90,-66);
    glVertex2f(90,-55);
    glVertex2f(-98,-46);
    glVertex2f(-100,-48);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(-63,-65,5.5,200);

    glColor3ub(77, 198, 255);
    DrawCircle(-63,-65,4,200);

    glPushMatrix();
    glTranslatef(15, 0.0f,0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(-63,-65,5.5,200);

    glColor3ub(77, 198, 255);
    DrawCircle(-63,-65,4,200);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 0.0f,0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(-63,-65,5.5,200);

    glColor3ub(77, 198, 255);
    DrawCircle(-63,-65,4,200);

    glPopMatrix();

}



void tree1(){ //FUNC35
    glPushMatrix();
    glTranslatef(-132.0f,60.0f,0.0f);

glPointSize(1.0);

glLineWidth(1.0);//x,y shape
glBegin(GL_QUADS);
glColor3ub(165,42,42);


glVertex2f(40.0f,-100.0f);
glVertex2f(40.0f,-90.0f);
glVertex2f(42.0f,-90.0f);
glVertex2f(42.0f,-100.0f);

glEnd();

glPointSize(1.0);

glLineWidth(1.0);//x,y shape
glBegin(GL_TRIANGLES);
glColor3ub(51, 102, 0);


glVertex2f(31.0f,-90.0f);
glVertex2f(41.0f,-80.0f);
glVertex2f(50.0f,-90.0f);


glVertex2f(31.0f,-85.0f);
glVertex2f(41.0f,-70.0f);
glVertex2f(50.0f,-85.0f);

glVertex2f(31.0f,-80.0f);
glVertex2f(41.0f,-61.0f);
glVertex2f(50.0f,-80.0f);


glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-117.0f,55.0f,0.0f);

glPointSize(1.0);

glLineWidth(1.0);//x,y shape
glBegin(GL_QUADS);
glColor3ub(165,42,42);


glVertex2f(40.0f,-100.0f);
glVertex2f(40.0f,-90.0f);
glVertex2f(42.0f,-90.0f);
glVertex2f(42.0f,-100.0f);

glEnd();

glPointSize(1.0);

glLineWidth(1.0);//x,y shape
glBegin(GL_TRIANGLES);
glColor3ub(51, 102, 0);


glVertex2f(31.0f,-90.0f);
glVertex2f(41.0f,-80.0f);
glVertex2f(50.0f,-90.0f);


glVertex2f(31.0f,-85.0f);
glVertex2f(41.0f,-70.0f);
glVertex2f(50.0f,-85.0f);

glVertex2f(31.0f,-80.0f);
glVertex2f(41.0f,-61.0f);
glVertex2f(50.0f,-80.0f);


glEnd();

    glPopMatrix();
}

void Shape(){ //FUNC36

glPointSize(1.0);

glLineWidth(1.0);//x,y shape
glColor3ub(242, 230, 102);
glBegin(GL_POLYGON);
glVertex2f(07.0f,-55.0f);
glVertex2f(10.0f, -30.0f);
glVertex2f(49.0f, -30.0f);
glVertex2f(50.0f, -55.0f);

glEnd();


}

void window(){ //FUNC37

    glLineWidth(1.0);//x,y shape
glColor3ub(196, 255, 253);
glBegin(GL_POLYGON);
glVertex2f(10.0f,-38.0f);
glVertex2f(10.5f,-33.0f);
glVertex2f(15.0f,-33.0f);
glVertex2f(15.0f,-38.0f);


glEnd();

glBegin(GL_POLYGON);
glVertex2f(17.0f,-40.0f);
glVertex2f(17.0f,-35.0f);
glVertex2f(21.0f,-35.0f);
glVertex2f(21.0f,-40.0f);


glEnd();

glBegin(GL_POLYGON);
glVertex2f(23.0f,-40.0f);
glVertex2f(23.0f,-35.0f);
glVertex2f(27.0f,-35.0f);
glVertex2f(27.0f,-40.0f);


glEnd();

glBegin(GL_POLYGON);
glVertex2f(29.0f,-40.0f);
glVertex2f(29.0f,-35.0f);
glVertex2f(33.0f,-35.0f);
glVertex2f(33.0f,-40.0f);


glEnd();

glBegin(GL_POLYGON);
glVertex2f(35.0f,-40.0f);
glVertex2f(35.0f,-35.0f);
glVertex2f(39.0f,-35.0f);
glVertex2f(39.0f,-40.0f);


glEnd();

glBegin(GL_POLYGON);
glVertex2f(41.0f,-40.0f);
glVertex2f(41.0f,-35.0f);
glVertex2f(45.0f,-35.0f);
glVertex2f(45.0f,-40.0f);


glEnd();

glBegin(GL_POLYGON);
glVertex2f(41.0f,-40.0f);
glVertex2f(41.0f,-35.0f);
glVertex2f(45.0f,-35.0f);
glVertex2f(45.0f,-40.0f);


glEnd();
}

void door(){ //FUNC38


glColor3ub(84, 84, 84);
glBegin(GL_POLYGON);
glVertex2f(10.0f,-53.0f);
glVertex2f(10.5f,-41.0f);
glVertex2f(15.0f,-41.0f);
glVertex2f(15.0f,-53.0f);


glEnd();

}

void tire1(){ //FUNC39

    glColor3ub(0, 255, 0);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    int i;
    GLfloat x=19.0f; GLfloat y=-55.0f; GLfloat radius =-3.5f;
//    GLfloat x=50.0f; GLfloat y=-35.0f; GLfloat radius =-3.0f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0, 0);

		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void tire2(){ //FUNC40

    glColor3ub(0, 255, 0);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    int i;
    GLfloat x=38.0f; GLfloat y=-55.0f; GLfloat radius =-3.5f;
//    GLfloat x=50.0f; GLfloat y=-35.0f; GLfloat radius =-3.0f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0,0, 0);

		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void design(){ //FUNC41

    glLineWidth(3.0);//x,y shape
glColor3ub(0,0,0);
glBegin(GL_LINES);
glVertex2f(10.0f,-30.0f);
glVertex2f(40.0f,-30.0f);




glColor3ub(255, 246, 161);
glVertex2f(33.0f,-50.0f);
glVertex2f(50.0f,-50.0f);



glColor3ub(0,0,0);
glVertex2f(49.0f,-30.0f);
glVertex2f(49.5f,-40.0f);


glColor3ub(0,0,0);
glVertex2f(10.0f,-30.0f);
glVertex2f(09.0f,-40.0f);


glColor3ub(255,0,0);
glVertex2f(49.5f,-45.0f);
glVertex2f(49.6f,-47.0f);


glColor3ub(255,255,0);
glVertex2f(07.6f,-50.5f);
glVertex2f(07.8f,-49.0f);
glEnd();


}

void box(){ //FUNC42
glBegin(GL_POLYGON);
glColor3ub(0,0,0);

glVertex2f(23.6f,-46.5f);
glVertex2f(32.6f,-46.5f);
glVertex2f(32.6f,-46.5f);

glVertex2f(32.6f,-54.5f);

glVertex2f(23.6f,-54.5f);
glVertex2f(23.6f,-46.5f);

glEnd();

}

void line(){ //FUNC43

glBegin(GL_LINE);
glColor3ub(196, 255, 253);

glVertex2f(27.6f,-46.5f);
glVertex2f(35.6f,-46.5f);

glEnd();
}

void tire_design1(){ //FUNC44

    glColor3ub(213, 82, 9);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    int i;
    GLfloat x=38.0f; GLfloat y=-55.0f; GLfloat radius =-1.9f;
//    GLfloat x=50.0f; GLfloat y=-35.0f; GLfloat radius =-3.0f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(213, 82, 9);

		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void tire_design2(){ //FUNC45

    glColor3ub(0, 255, 0);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    int i;
    GLfloat x=19.0f; GLfloat y=-55.0f; GLfloat radius =-1.9f;
//    GLfloat x=50.0f; GLfloat y=-35.0f; GLfloat radius =-3.0f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(213, 82, 9);

		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void tire_design3(){ //FUNC46


    glLineWidth(7.5);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    int i;
    GLfloat x=19.0f; GLfloat y=-55.0f; GLfloat radius =-0.8f;
//    GLfloat x=50.0f; GLfloat y=-35.0f; GLfloat radius =-3.0f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 0, 0);

		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void tire_design4(){ //FUNC47


    glLineWidth(7.5);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    int i;
    GLfloat x=38.0f; GLfloat y=-55.0f; GLfloat radius =-0.8f;
//    GLfloat x=50.0f; GLfloat y=-35.0f; GLfloat radius =-3.0f;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 0, 0);

		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void bus(){ //FUNC48
    glPushMatrix();
       glScalef(1.5f, 1.5f, 0.0f);
    glTranslatef(0.0f, 11.0f,0.0f);

Shape();
window();
door();
tire1();
tire2();
design();
tire_design1();
tire_design2();
tire_design3();
tire_design4();
glEnd();

    glPopMatrix();
}

void frame(){ //FUNC49


glColor3ub(57,35,30);
glBegin(GL_POLYGON);
glVertex2f(-20.0f,-62.0f);
glVertex2f(10.0f,-62.0f);
glVertex2f(15.0f,-48.0f);
glVertex2f(-25.0f,-48.0f);


glEnd();

}

void bamboo(){ //FUNC50

glLineWidth(4.0);//x,y shape
glColor3ub(57,35,30);
glBegin(GL_LINES);
glVertex2f(-15.0f,-29.0f);//////1
glVertex2f(-15.0f,-49.5f);


glVertex2f(5.0f,-31.0f);///////3
glVertex2f(3.0f,-49.5f);


glVertex2f(-5.0f,-14.0f);
glVertex2f(-5.0f,-49.5f);///////2
glEnd();
}

void design2() //FUNC51
{

glLineWidth(3.0);//x,y shape
glColor3ub(57,35,30);
glBegin(GL_LINES);
glVertex2f(-15.0f,-32.0f);//////1
glVertex2f(-25.0f,-43.0f);

glVertex2f(-5.0f,-25.0f);
glVertex2f(-15.0f,-43.5f);///////2

glVertex2f(-5.0f,-25.0f);
glVertex2f(-15.0f,-33.0f);///////2

glVertex2f(4.8f,-33.0f);
glVertex2f(-3.0f,-47.5f);///////2

glVertex2f(5.0f,-31.0f);///////3
glVertex2f(15.0f,-43.5f);

glVertex2f(-25.0f,-43.0f);//////1
glVertex2f(-18.0f,-49.5f);

glVertex2f(-15.0f,-47.5f);
glVertex2f(-5.0f,-49.5f);///////2

glVertex2f(5.0f,-33.0f);///////3
glVertex2f(-5.0f,-24.0f);
glEnd();

}

void design3() //FUNC52
{

    glLineWidth(2.0);//x,y shape
glColor3ub(57,35,30);
glBegin(GL_LINES);
glVertex2f(-15.0f,-32.0f);
glVertex2f(-16.5f,-40.0f);
glVertex2f(-20.0f,-49.5f);

glVertex2f(-5.0f,-25.0f);
glVertex2f(-6.5f,-25.0f);
glVertex2f(-5.0f,-49.5f);///////2

glEnd();

}

void flag(){ //FUNC53

glPointSize(0.1);

glLineWidth(0.1);//x,y shape
glColor3ub(255,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(-5.0f,-14.0f);
glVertex2f(0.0f,-18.0f);///////2
glVertex2f(-5.0f,-22.0f);

glEnd();
}

void triangle() //FUNC54
{

glColor3ub(211,211,211);
glBegin(GL_TRIANGLES);
glVertex2f(-15.0f,-32.0f);//////1
glVertex2f(-25.0f,-43.0f);
glVertex2f(-15.0f,-47.6f);
glEnd();


glLineWidth(0.1);//x,y shape
glColor3ub(211,211,211);
glBegin(GL_POLYGON);
glVertex2f(-5.0f,-25.0f);
glVertex2f(-15.0f,-34.6f);
glVertex2f(-15.0f,-40.6f);
glVertex2f(-5.0f,-45.5f);





glVertex2f(-5.0f,-30.0f);
glVertex2f(5.0f,-34.0f);
glVertex2f(4.5f,-47.5f);
glVertex2f(-5.0f,-45.5f);

glEnd();

glColor3ub(192,192,192);
glBegin(GL_TRIANGLES);
glVertex2f(3.0f,-32.0f);//////1
glVertex2f(15.0f,-43.0f);
glVertex2f(3.0f,-47.6f);
glEnd();


}

void boat_A(){ //FUNC55

frame();
triangle();
flag();
bamboo();
design2();
design3();

}

void Poll(){ //FUNC56

glPointSize(1.0);


glLineWidth(1.0);//x,y shape
glBegin(GL_QUADS);
glColor3ub(227, 86,86);
glVertex2f(-80.0f,-79.0f);
glVertex2f(-80.0f,-70.0f);
glVertex2f(-83.0f,-70.0f);
glVertex2f(-83.0f,-79.0f);


glVertex2f(-75.0f,-79.0f);
glVertex2f(-75.0f,-68.0f);
glVertex2f(-78.0f,-68.0f);
glVertex2f(-78.0f,-79.0f);

glVertex2f(-70.0f,-79.0f);
glVertex2f(-70.0f,-65.0f);
glVertex2f(-73.0f,-65.0f);
glVertex2f(-73.0f,-79.0f);

glVertex2f(-65.0f,-79.0f);
glVertex2f(-65.0f,-62.0f);
glVertex2f(-68.0f,-62.0f);
glVertex2f(-68.0f,-79.0f);

glColor3ub(223,190,102);
glVertex2f(-35.0f,-75.5f);
glVertex2f(-35.0f,-70.0f);
glVertex2f(-41.0f,-71.0f);
glVertex2f(-41.0f,-76.0f);
glEnd();

}

void frame2(){ //FUNC57

glPointSize(1.0);


glLineWidth(1.0);//x,y shape
glBegin(GL_POLYGON);
glColor3ub(33, 53, 83);


glVertex2f(-90.0f,-80.0f);
glVertex2f(-55.0f,-80.0f);
glVertex2f(-30.0f,-75.0f);
glVertex2f(-40.0f,-95.0f);
glVertex2f(-90.0f,-95.0f);
glVertex2f(-80.0f,-80.0f);
glVertex2f(-90.0f,-80.0f);
	glEnd();

glLineWidth(1.0);//x,y shape
glBegin(GL_QUADS);
glColor3ub(248, 247, 217);
glVertex2f(-75.0f,-77.0f);
glVertex2f(-55.0f,-77.0f);
glVertex2f(-55.0f,-62.0f);
glVertex2f(-75.0f,-77.0f);


	glEnd();

}

void Window(){ //FUNC58

glLineWidth(1.0);//x,y shape
glBegin(GL_QUADS);
glColor3ub(185, 197, 188);
glVertex2f(-80.0f,-87.0f);
glVertex2f(-80.0f,-82.0f);
glVertex2f(-85.0f,-82.0f);
glVertex2f(-85.0f,-87.0f);

glVertex2f(-74.0f,-87.0f);
glVertex2f(-74.0f,-82.0f);
glVertex2f(-79.0f,-82.0f);
glVertex2f(-79.0f,-87.0f);


glVertex2f(-68.0f,-87.0f);
glVertex2f(-68.0f,-82.0f);
glVertex2f(-73.0f,-82.0f);
glVertex2f(-73.0f,-87.0f);

glVertex2f(-62.0f,-87.0f);
glVertex2f(-62.0f,-82.0f);
glVertex2f(-67.0f,-82.0f);
glVertex2f(-67.0f,-87.0f);

glVertex2f(-56.0f,-87.0f);
glVertex2f(-56.0f,-82.0f);
glVertex2f(-61.0f,-82.0f);
glVertex2f(-61.0f,-87.0f);

glVertex2f(-51.0f,-87.0f);
glVertex2f(-51.0f,-82.0f);
glVertex2f(-55.0f,-82.0f);
glVertex2f(-55.0f,-87.0f);

glVertex2f(-45.0f,-87.0f);
glVertex2f(-45.0f,-82.0f);
glVertex2f(-50.0f,-82.0f);
glVertex2f(-50.0f,-87.0f);
	glEnd();

}

void ship(){ //FUNC59

frame2();
Poll();
Window();

}

void display() //FUNC60
{
    if(status==0)
    {
        sky(106,192,205,197,247,254);
        sun();

        buildings(145,189,213);
        buildingWindows(255, 255, 255);

        text(35,116,text1);

        glPushMatrix();
        glTranslatef(200.0f, 0.0f,0.0f);
        buildings(145,189,213);
        buildingWindows(255, 255, 255);
        text(35,116,text2);
        glPopMatrix();

        cloud(255,255,255);
        road();
        footpath();
        platform();

        glPushMatrix();
        glTranslatef(0.0f, 3.0f,0.0f);
        glRotatef(180, 0, 1, 0);
        train();
        glPopMatrix();

        train();

        lamp(255,255,0);
        chair();
        human();
        tree1();
        car1();

        glPushMatrix();
        glTranslatef(position_bus, 0.0f,0.0f);
        bus();
        glPopMatrix();
        car2();

    }

    if(status==1)
    {
        sky(13,74,121,20,45,86);
        stars();

        moon();

        buildings(145,189,213);
        buildingWindows(242, 255, 145);
        text(35,116,text1);

        glPushMatrix();
        glTranslatef(200.0f, 0.0f,0.0f);
        buildings(145,189,213);
        buildingWindows(242, 255, 145);
        text(35,116,text2);
        glPopMatrix();

        cloud(255,255,255);

        road();

        footpath();
        platform();

        glPushMatrix();
        glTranslatef(0.0f, 3.0f,0.0f);
        glRotatef(180, 0, 1, 0);
        train();
        glPopMatrix();

        train();
        lamp(255,255,0);
        lamp_night();
        chair();
        tree1();
        car1();
        car2();

    }
    if(status==2)
    {
        sky(254,193,157,251,139,76);

        buildings(135,184,209);
        buildingWindows(255, 255, 255);

        text(35,116,text1);

        glPushMatrix();
        glTranslatef(200.0f, 0.0f,0.0f);
        buildings(135,184,209);
        buildingWindows(255, 255, 255);
        text(35,116,text2);
        glPopMatrix();

        cloud(240,236,179);
        road();
        footpath();
        platform();

        glPushMatrix();
        glTranslatef(0.0f, 3.0f,0.0f);
        glRotatef(180, 0, 1, 0);
        train();
        glPopMatrix();

        train();

        lamp(255,255,0);
        chair();
        human();
        tree1();
        car1();

        glPushMatrix();
        glTranslatef(position_bus, 0.0f,0.0f);
        bus();
        glPopMatrix();
        car2();

    }
    if(status==3)
    {
        sky(106,192,205,197,247,254);
        sun_mountain();
        mountains();

        cloud(255,255,255);
        sea();

        glPushMatrix();
        glTranslatef(position_boat, 80.0f,0.0f);
        ship();
        glPopMatrix();

        platform_mountain();
        train();

        glPushMatrix();
        glTranslatef(position_boat, 0.0f,0.0f);
        boat_A();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(position_ship, 0.0f,0.0f);
        largeShip();
        glPopMatrix();
    }
    if(status==4)
    {
        sky(13,74,121,20,45,86);
        stars();

        moon();
        mountains();

        cloud(255,255,255);
        sea();

        glPushMatrix();
        glTranslatef(position_boat, 80.0f,0.0f);
        ship();
        glPopMatrix();

        platform_mountain();
        train();

        glPushMatrix();
        glTranslatef(position_boat, 0.0f,0.0f);
        boat_A();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(position_ship, 0.0f,0.0f);
        largeShip();
        glPopMatrix();
    }
    if(status==5)
    {
        sky(254,193,157,251,139,76);
        sun_evening();
        mountains();
        cloud(240,236,179);
        sea();

        glPushMatrix();
        glTranslatef(position_boat, 80.0f,0.0f);
        ship();
        glPopMatrix();

        platform_mountain();
        train();

        glPushMatrix();
        glTranslatef(position_boat, 0.0f,0.0f);
        boat_A();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(position_ship, 0.0f,0.0f);
        largeShip();
        glPopMatrix();
    }

glFlush ();
}
void keyboard(unsigned char key, int x, int y) //FUNC61
{

if (key == 'D' || key == 'd')
{
status = 0;
glutIdleFunc(day);
}
if (key == 'N' || key == 'n')
{
status = 1;
glutIdleFunc(night_evening);
}
if (key == 'E' || key == 'e')
{
status = 2;
glutIdleFunc(night_evening);
}
if (key == 'S' || key == 's')
{
status = 3;
glutIdleFunc(scene_2);
}
if (key == 'C' || key == 'c')
{
status = 4;
glutIdleFunc(scene_2);
}
if (key == 'V' || key == 'v')
{
status = 5;
glutIdleFunc(scene_2);
}
glutPostRedisplay();
}

void myInit (void) //FUNC62
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
}

int main(int argc, char** argv) //FUNC63
{

glutInit(&argc, argv); // Initialize GLUT
glutCreateWindow("Metro Rail Project"); // Create a window with the given title
glutInitWindowSize(1920, 1080);
gluOrtho2D(-100,300,-100,200); // Set the window's initial width & height
glutIdleFunc(day);
glutDisplayFunc(display); // Register display callback handler for window re-paint
glutKeyboardFunc(keyboard);
glutMainLoop(); // Enter the event-processing loop
myInit ();
return 0;
}
