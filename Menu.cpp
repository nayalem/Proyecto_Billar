
#include "Menu.h"

Menu::Menu(float width, float height) {
    fuente.loadFromFile("Fruits Delight.otf");
    // Carga la textura del fondo
    if (!textura_fondo.loadFromFile("fondo_menu.png")) {
        // Manejar error si no se puede cargar la textura
    }

    // Configura el sprite del fondo
    fondo.setTexture(textura_fondo);
    fondo.setScale(width / fondo.getGlobalBounds().width, height / fondo.getGlobalBounds().height);

    // Configura el t�tulo del juego
    
    titulo_del_juego.setFont(fuente);
    titulo_del_juego.setFillColor(sf::Color::White);
    titulo_del_juego.setCharacterSize(80); // Tama�o del t�tulo
    

    // Calcula la posici�n para centrar el t�tulo en la pantalla
    sf::FloatRect titleBounds = titulo_del_juego.getLocalBounds();
    titulo_del_juego.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    titulo_del_juego.setPosition(sf::Vector2f(width / 3.5f, height / 6.0f)); // Centra el t�tulo

    // Calcula la posici�n vertical para las opciones del men� debajo del t�tulo
    float menuY = titulo_del_juego.getPosition().y + titleBounds.height + 200.0f; // 50.0f es la separaci�n entre el t�tulo y las opciones

    
    // Configura las opciones del men� centradas en la pantalla y debajo del t�tulo
    std::string opciones[3]{ "jugar","Ajustes","Salir" };
    for (int i = 0; i < 3; ++i) {
        item_del_menu[i].setString(opciones[i]);
        item_del_menu[i].setFont(fuente);
        item_del_menu[i].setFillColor(sf::Color::White);
        item_del_menu[i].setCharacterSize(40); // Tama�o del texto del men�, ajusta seg�n sea necesario

        sf::FloatRect menuItemBounds = item_del_menu[i].getLocalBounds();
        item_del_menu[i].setOrigin(menuItemBounds.left + menuItemBounds.width / 2.0f, menuItemBounds.top + menuItemBounds.height / 2.0f);
        item_del_menu[i].setPosition(sf::Vector2f(width / 2.0f, menuY)); // Centra las opciones del men�
        menuY += menuItemBounds.height + 20.0f; // 20.0f es la separaci�n vertical entre las opciones del men�
    }

    indice_del_item = 0;
}

void Menu::Titulo(const std::string& title) {
    titulo_del_juego.setString(title);
}

void Menu::Grafico(sf::RenderWindow& window) {
    window.draw(fondo);
    window.draw(titulo_del_juego); // Dibuja el t�tulo del juego
    for (int i = 0; i < 3; ++i) {
        window.draw(item_del_menu[i]);
    }
}

void Menu::Arriba() {
    if (indice_del_item - 1 >= 0) {
        item_del_menu[indice_del_item].setFillColor(sf::Color::White);
        indice_del_item--;
        item_del_menu[indice_del_item].setFillColor(sf::Color::Red);
    }
}

void Menu::Abajo() {
    if (indice_del_item + 1 < 3) {
        item_del_menu[indice_del_item].setFillColor(sf::Color::White);
        indice_del_item++;
        item_del_menu[indice_del_item].setFillColor(sf::Color::Red);
    }
}