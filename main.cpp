#include <SFML/Graphics.hpp>
#include "Menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Example");
    Menu menu(window.getSize().x, window.getSize().y);
    menu.Titulo("MI juego"); // Establece el nombre de tu juego

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    menu.Arriba();
                    break;
                case sf::Keyboard::Down:
                    menu.Abajo();
                    break;
                case sf::Keyboard::Return:
                    // Aquí maneja la opción seleccionada
                    switch (menu.Selecion()) {
                    case 0:
                        // Lógica para iniciar el juego
                        break;
                    case 1:
                        // Lógica para ir a la pantalla de ajustes
                        break;
                    case 2:
                        window.close();
                        break;
                    }
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();
        menu.Grafico(window);
        window.display();
    }

    return 0;
}




