#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

int main() {
  // Launching a window with the game title
  const sf::VideoMode WindowSpecification({800, 600});
  constexpr char WindowTitle[] = "Bot-Arena";
  sf::RenderWindow Window(WindowSpecification, WindowTitle);

  while (Window.isOpen()) {
    while (std::optional Event = Window.pollEvent()) {
      if (Event->is<sf::Event::Closed>()) {
        Window.close();
      }
    }
    Window.clear(sf::Color::Magenta);

    Window.display();
  }

  return 0;
}
