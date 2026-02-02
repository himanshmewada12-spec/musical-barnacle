/* Copyright Himansh Mewada 2026 */

// load the necessary libraries
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

// The different game states
using GameState = enum { Play, Menu, Restart };

int main() {
  // Launching a window with the game title
  const sf::VideoMode WindowSpecification({800, 600});
  constexpr char WindowTitle[] = "Bot-Arena";
  sf::RenderWindow Window(WindowSpecification, WindowTitle);

  // The Game Runs at 60 FPS
  constexpr unsigned FrameRateLimit = 60;
  Window.setFramerateLimit(FrameRateLimit);

  // Set the window icon.
  sf::Image WindowIcon("include/logo.png");
  Window.setIcon(WindowIcon);

  // Text used: /* An Excellent pain in the ass. */
  const sf::Font Font("include/JetBrainsMono-Bold.ttf");
  constexpr unsigned LineSeparationDistance = 20u;
  constexpr char TitleText[] = "Bot-Arena";
  constexpr unsigned TitleSize = 60u;
  constexpr sf::Color TitleColor(236, 240, 241, 255);
  sf::Text Title(Font, TitleText, TitleSize);
  Title.setFillColor(TitleColor);
  Title.setPosition({static_cast<float>(Window.getSize().x) / 2 -
                         Title.getLocalBounds().size.x / 2,
                     0});
  constexpr char SubTitleText[] = "No time to think, just dodge and survive!";
  constexpr unsigned SubTitleSize = TitleSize / 2;
  constexpr sf::Color SubTitleColor(168, 189, 160, 255);
  sf::Text SubTitle(Font, SubTitleText, SubTitleSize);
  SubTitle.setFillColor(SubTitleColor);
  SubTitle.setPosition({static_cast<float>(Window.getSize().x) / 2 -
                            SubTitle.getLocalBounds().size.x / 2,
                        Title.getLocalBounds().size.y + LineSeparationDistance +
                            Title.getLocalBounds().position.y});
  constexpr char GeneralInstructionText[] =
      "--> Use W A S D to move. You can also use the arrow keys to move.\n"
      "--> There is only one objective, don't get caught.\n"
      "--> Can you survive this utlimate game of tag.";
  constexpr unsigned GeneralInstructionSize = SubTitleSize / 2;
  constexpr sf::Color GeneralInstructionColor(210, 123, 114, 255);
  sf::Text GeneralInstruction(Font, GeneralInstructionText,
                              GeneralInstructionSize);
  GeneralInstruction.setFillColor(GeneralInstructionColor);
  GeneralInstruction.setPosition(
      {static_cast<float>(Window.getSize().x) / 2 -
           GeneralInstruction.getLocalBounds().size.x / 2,
       static_cast<float>(Window.getSize().y) / 2});

  // Background Color
  constexpr sf::Color BackgroundColor(43, 52, 59, 255);

  // Current game state
  GameState CurrentGameState = Menu;

  // Slider related colors
  sf::Color SliderRailColor(65, 76, 85, 255);
  sf::Color SliderKnobColor(218, 191, 159, 255);
  sf::Color EndLabelColor(144, 155, 160, 255);
  sf::Color SliderHeadingColor(133, 163, 178, 255);

  // Actual Sliders
  constexpr unsigned SliderAreaHeight = 450;
  sf::RectangleShape SliderRail1({300, 6});
  sf::RectangleShape SliderRail2({300, 6});
  sf::RectangleShape SliderKnob1({12, 24});
  sf::RectangleShape SliderKnob2({12, 24});
  sf::Text SliderRail1Text1(Font, "High", GeneralInstructionSize / 2.f + 2.5);
  sf::Text SliderRail1Text2(Font, "Low", GeneralInstructionSize / 2.f + 2.5);
  sf::Text SliderRail2Text1(Font, "High", GeneralInstructionSize / 2.f + 2.5);
  sf::Text SliderRail2Text2(Font, "Low", GeneralInstructionSize / 2.f + 2.5);
  SliderRail1Text1.setFillColor(EndLabelColor);
  SliderRail1Text2.setFillColor(EndLabelColor);
  SliderRail2Text1.setFillColor(EndLabelColor);
  SliderRail2Text2.setFillColor(EndLabelColor);
  SliderRail1.setFillColor(SliderRailColor);
  SliderRail2.setFillColor(SliderRailColor);
  SliderKnob1.setFillColor(SliderKnobColor);
  SliderKnob2.setFillColor(SliderKnobColor);
  SliderRail1.setPosition(
      {static_cast<float>(Window.getSize().x) / 2 - SliderRail1.getSize().x / 2,
       SliderAreaHeight + 0});
  SliderRail2.setPosition(
      {static_cast<float>(Window.getSize().x) / 2 - SliderRail1.getSize().x / 2,
       SliderAreaHeight + 90});
  SliderKnob1.setPosition(
      {SliderRail1.getPosition().x + SliderKnob1.getSize().x / 2,
       SliderRail1.getPosition().y - SliderKnob1.getSize().y / 2});
  SliderKnob2.setPosition(
      {SliderRail2.getPosition().x + SliderKnob2.getSize().x / 2,
       SliderRail2.getPosition().y - SliderKnob2.getSize().y / 2});
  constexpr unsigned SeparationDistance = 10;
  SliderRail1Text1.setPosition({SliderRail1.getPosition().x -
                                    SliderRail1Text1.getLocalBounds().size.x -
                                    SeparationDistance,
                                SliderRail1.getPosition().y});
  SliderRail1Text2.setPosition({SliderRail1.getPosition().x +
                                    SliderRail1.getLocalBounds().size.x +
                                    SeparationDistance,
                                SliderRail1.getPosition().y});
  SliderRail2Text1.setPosition({SliderRail2.getPosition().x -
                                    SliderRail2Text1.getLocalBounds().size.x -
                                    SeparationDistance,
                                SliderRail2.getPosition().y});
  SliderRail2Text2.setPosition({SliderRail2.getPosition().x +
                                    SliderRail2.getLocalBounds().size.x +
                                    SeparationDistance,
                                SliderRail2.getPosition().y});

  // The main game loop
  while (Window.isOpen()) {
    while (std::optional Event = Window.pollEvent()) {
      if (Event->is<sf::Event::Closed>()) {
        Window.close();
      }
    }

    // Set background
    Window.clear(BackgroundColor);

    // Input buffer
    switch (CurrentGameState) {
    case Play:
      break;
    case Restart:
      break;
    case Menu:
      Window.draw(Title);
      Window.draw(SubTitle);
      Window.draw(GeneralInstruction);
      Window.draw(SliderRail1);
      Window.draw(SliderRail2);
      Window.draw(SliderKnob1);
      Window.draw(SliderKnob2);
      Window.draw(SliderRail1Text1);
      Window.draw(SliderRail1Text2);
      Window.draw(SliderRail2Text1);
      Window.draw(SliderRail2Text2);
      break;
    }

    // Display input buffer onto the screen
    Window.display();
  }

  // Exit
  return 0;
}
