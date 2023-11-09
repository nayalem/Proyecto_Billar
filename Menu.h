#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>


class Menu {
public:
    Menu(float width, float height);
    void Grafico(sf::RenderWindow& window);
    void Arriba();
    void Abajo();
    int Selecion() { return indice_del_item; }
    void Titulo(const std::string& title);

private:
    int indice_del_item;
    sf::Font fuente;
    sf::Text item_del_menu[3];
    sf::Text titulo_del_juego;
    sf::Texture textura_fondo;
    sf::Sprite fondo;
    
};

#endif MENU_H
