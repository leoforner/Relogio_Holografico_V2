#include <Arduino.h>
#include "../include/sensor_control.h"
#include "../include/utilities.h"
#include "../include/config.h"

int baixo = 9;
int cima = 4;
int estado = 0;
int j = 0;
int green = 200, red = 0, blue = 0;

void ledloop(){
    if (currentMicros >= (tempo + t_arco)) {
        tempo += t_arco;
        
        for (int i = LED_COUNT - 1; i >= 0; i--) 
        {
            if (i > (LED_COUNT - cima - 1)) {
                strip.setPixelColor(i, strip.Color(75, 0, 130));
                
            } else if(i > baixo)
            {
                /*
                estado = j + (i - baixo) * largura;
                red = imagem1[estado][0];
                green = imagem1[estado][1];
                blue = imagem1[estado][2];
                
                if(green < 150){
                green = 0;
                }else {
                green = 250;
                }
                if(red < 125){
                red = 0;
                }else {
                red = 250;
                }
                if(blue <= 125){
                blue = 0;
                }else {
                blue = 250;
                }
                
                blue =50;
                green = 100;
                */
                if (blue && red && green == 255) {
                blue = 0;
                red = 0;
                green = 0;
                } //else {
                //red = 255;
                // green = 25;
                //blue = 0;
                //}
                strip.setPixelColor( i , strip.Color(red, green, blue));
            } else {
                strip.setPixelColor(i, strip.Color(255, 25, 0));
            }
        }
    }
}