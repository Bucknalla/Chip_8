#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SCREEN_W 640
#define SCREEN_H 320

int main()
{
    unsigned int FPS = 120; // The desired FPS. (The number of updates each second).
    unsigned int redraw = 1;     
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfVector2f vect = {10,10};
    sfVector2f start = {25,25};
    sfClock * clk;
    sfTexture * texture;
    sfCircleShape* circle;
    sfSprite* sprite;
    sfImage* image;
    sfEvent event;
    sfBool resetRect = 0;
    sfUint8 * pixels[SCREEN_W*SCREEN_H*4];
    
    srand(time(NULL));   // should only be called once

    unsigned int rand_value;

    rand_value = rand()%256;

    unsigned char value = rand_value;


    // sfColor color; 
    // color = sfColor_fromRGB(rand()%256,rand()%256,rand()%256);

    
    texture = sfTexture_create(SCREEN_W,SCREEN_H);
    sprite = sfSprite_create();

    sfSprite_setTexture(sprite,texture,resetRect);

    window = sfRenderWindow_create(mode, "Chip 8 Emulator", sfResize | sfClose, NULL);
    if(!window) return 1;
    sfRenderWindow_setFramerateLimit(window, FPS);

    circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, 50);
    sfCircleShape_setOrigin(circle, start);
    sfCircleShape_setFillColor(circle, sfBlue);
    sfCircleShape_setPosition(circle, start);

    clk = sfClock_create();

    float time_int = (1 / FPS);


    while (sfRenderWindow_isOpen(window))
    {

        //Handle input
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed) 
                sfRenderWindow_close(window);
        }

        //Wait until 1/60th of a second has passed, then update everything.
        if (sfTime_asSeconds(sfClock_getElapsedTime(clk)) >= (time_int))
        {
            // printf("%f",sfTime_asSeconds(sfClock_getElapsedTime(clk)));
            // printf("%f,%f",vect.x,vect.y);
            redraw = 1; //We're ready to redraw everything
            // if((vect.x > SCREEN_H || vect.y > SCREEN_W ) ){
            //     vect.x = 0;
            //     vect.y = 0;
            // }
            // else{
            //     vect.x++;
            //     vect.y++;
            // }

            // sfCircleShape_setPosition(circle, vect);

            for(register int i = 0; i < SCREEN_W*SCREEN_H*4; i += 4) {
                pixels[i] = (&value); // obviously, assign the values you need here to form your color
                // pixels[i+1] = (&value);
                // pixels[i+2] = (&value);
                // pixels[i+3] = (&value);
            }
            sfClock_restart(clk);
        }

        //Draw stuff if ready
        if(redraw)
        {
            redraw = 0;
            sfRenderWindow_clear(window, sfWhite);
            
            sfImage_createFromPixels(800, 600, pixels);
            sfSprite_setTexture(sprite,image, NULL);
            // sfRenderWindow_drawCircleShape(window, circle, NULL);
            sfRenderWindow_display(window);
        }
    }
    sfRenderWindow_destroy(window);
    return 0;
}

// int main()
// {
//     sfVideoMode mode = {800, 600, 32};
//     sfRenderWindow* window;
//     sfTexture* texture;
//     sfSprite* sprite;
//     sfFont* font;
//     sfText* text;
//     sfCircleShape* circle;
//     sfEvent event;
//     sfVector2f vect = {10,10};

//     // create the window
//     window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
//     if (!window)
//         return 1;
//     // run the program as long as the window is open
//     while (sfRenderWindow_isOpen(window))
//     {
//         // check all the window's events that were triggered since the last iteration of the loop
//         while (sfRenderWindow_pollEvent(window, &event))
//         {
//             // "close requested" event: we close the window
//             if (event.type == sfEvtClosed)
//                 sfRenderWindow_close(window);
//         }

//         // clear the window with black color
//         sfRenderWindow_clear(window, sfWhite);

//         circle = sfCircleShape_create();
//         sfCircleShape_setPosition(circle, vect);
//         sfCircleShape_setRadius(circle, 50);
//         sfCircleShape_setFillColor(circle, sfBlue);

//         // define the position of the triangle's points
//         // draw everything here...
//         // window.draw(...);
//         sfRenderWindow_drawCircleShape(window, circle, NULL);

//         // end the current frame
//         sfRenderWindow_display(window);
        
//     }
//     sfText_destroy(text);
//     sfFont_destroy(font);
//     sfSprite_destroy(sprite);
//     sfTexture_destroy(texture);
//     sfRenderWindow_destroy(window);

//     return 0;
// }