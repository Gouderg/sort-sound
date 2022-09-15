#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <iostream>
#include <cmath>

#include "constante.hpp"
#include "oscillo.hpp"
#include "interfacebase.hpp"

class Gui: public InterfaceBase {

    public:
        Gui();

        void run();
        void update(Oscillo* os, const int mod_i, const int mod_j);
        void animation(Oscillo* os);
        void make_sound(std::vector<int16_t> samples, int delay);
        void delay_ms(int ms);

    private:
        sf::RenderWindow* window;

        sf::SoundBuffer buffer;
        sf::Sound sound;

        double stick_w, stick_h;
};