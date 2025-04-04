#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно размером 800x600 с заголовком "SFML Window"
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Создаем круг с радиусом 50 пикселей
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Blue);
    // Устанавливаем позицию круга по центру окна
    circle.setPosition(375, 275);

    // Основной цикл приложения
    while (window.isOpen()) {
        sf::Event event;
        // Обработка событий окна
        while (window.pollEvent(event)) {
            // Если нажата кнопка закрытия окна, закрываем его
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Очищаем окно
        window.clear();
        // Рисуем круг
        window.draw(circle);
        // Отображаем содержимое окна на экране
        window.display();
    }

    return 0;
}
