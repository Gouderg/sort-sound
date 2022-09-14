#include "../header/gui.hpp"

// Constructor.
Gui::Gui() {
    this->stick_w = (SIZE_W - NB_FREQ + 1) / static_cast<double>(NB_FREQ);
    this->stick_h = (SIZE_H - 20 - 20) / static_cast<double>(NB_FREQ);
    
    // Window.
    this->window = new sf::RenderWindow(sf::VideoMode(SIZE_W, SIZE_H), "Sort Sound");
    
    // FPS.
    this->window->setFramerateLimit(60);

}

void Gui::run() {
    // On fait tourner le programme jusqu'à ce que la fenêtre soit fermée.
    while (this->window->isOpen()) {
        
        // Watch for event.
        sf::Event event;
        while (this->window->pollEvent(event)) {

            // Close event.
            if (event.type == sf::Event::Closed) this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->window->close();
        }
    }
}

void Gui::update(Oscillo* os, const int mod_i, const int mod_j) {

    // Clear window.
    this->window->clear(sf::Color(25,25,100,80));
    
    // Cursor of stick position.
    double pos_w = 0.0;

    for (int i = 0; i < NB_FREQ; i++) {
        // Draw stick.
        sf::RectangleShape line(sf::Vector2f(this->stick_h * (os->getKey(i) + 1)+MIN_STICK_H, this->stick_w));
        line.rotate(-90);
        line.setPosition(sf::Vector2f(pos_w, SIZE_H));
        
        // Change the stick color if is moved.
        if (i == mod_i || i == mod_j) {
            line.setFillColor(sf::Color(255, 0, 0));
            std::vector<sf::Int16> samples= os->getWave(os->getKey(i)).getSamples();
            this->buffer.loadFromSamples(&samples[0], samples.size(), NB_CHANNEL, SAMPLING_RATE);
            this->sound.setBuffer(this->buffer);

            this->sound.setLoop(true);
            this->sound.play();
            delay_ms(10);
            this->sound.stop();
        }

        // Draw on window.
        this->window->draw(line);

        pos_w += (this->stick_w + 1.0);

    }

    // Show.
    this->window->display();
}

void Gui::animation(Oscillo* os) {

    // Clear window.
    this->window->clear(sf::Color(25,25,100,80));
    
    // Cursor of stick position.
    double pos_w = 0.0;

    for (int i = 0; i < NB_FREQ; i++) {
        // Draw stick.
        sf::RectangleShape line(sf::Vector2f(this->stick_h * (os->getKey(i) + 1)+MIN_STICK_H, this->stick_w));
        line.rotate(-90);
        line.setPosition(sf::Vector2f(pos_w, SIZE_H));
        
        

        // Draw on window.
        this->window->draw(line);

        pos_w += (this->stick_w + 1.0);

    }

    // Show.
    this->window->display();


    // Cursor of stick position.
    pos_w = 0.0;

    for (int i = 0; i < NB_FREQ; i++) {
        // Draw stick.
        sf::RectangleShape line(sf::Vector2f(this->stick_h * (os->getKey(i) + 1)+MIN_STICK_H, this->stick_w));
        line.rotate(-90);
        line.setPosition(sf::Vector2f(pos_w, SIZE_H));
        
        // Change the stick color if is moved.
        line.setFillColor(sf::Color(0, 255, 0));
        std::vector<sf::Int16> samples= os->getWave(os->getKey(i)).getSamples();
        this->buffer.loadFromSamples(&samples[0], samples.size(), NB_CHANNEL, SAMPLING_RATE);
        this->sound.setBuffer(this->buffer);

        this->sound.setLoop(true);
        this->sound.play();
        delay_ms(20);
        this->sound.stop();

        // Draw on window.
        this->window->draw(line);

        pos_w += (this->stick_w + 1.0);

        // Show.
        this->window->display();
    }
}

// Wait for ms milliseconds
void Gui::delay_ms(int ms) {
    sf::Clock Timer;
    while (Timer.getElapsedTime().asMilliseconds() < ms);
}

