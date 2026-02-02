/* Copyright (c) 2026 Himansh Mewada */

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <algorithm>

using GameState = enum { Play, Menu, Restart };

float getSliderValue(const sf::RectangleShape& sliderKnob, const sf::RectangleShape& sliderRail) {
  return (sliderKnob.getPosition().x - sliderRail.getPosition().x) /
         (sliderRail.getSize().x - sliderKnob.getSize().x);
}

int main() {
  const sf::VideoMode windowVideoMode({800, 600});
  constexpr char windowTitle[] = "Bot-Arena";
  sf::RenderWindow window(windowVideoMode, windowTitle);

  constexpr unsigned frameRateLimit = 60;
  window.setFramerateLimit(frameRateLimit);

  sf::Image windowIcon("include/logo.png");
  window.setIcon(windowIcon);

  const sf::Font mainFont("include/JetBrainsMono-Bold.ttf");

  constexpr unsigned lineSpacing = 20u;
  constexpr char titleText[] = "Bot-Arena";
  constexpr unsigned titleFontSize = 60u;
  constexpr sf::Color titleColor(236, 240, 241, 255);

  sf::Text title(mainFont, titleText, titleFontSize);
  title.setFillColor(titleColor);
  title.setPosition(
      {static_cast<float>(window.getSize().x) / 2 - title.getLocalBounds().size.x / 2, 0});

  constexpr char subtitleText[] = "No time to think, just dodge and survive!";
  constexpr unsigned subtitleFontSize = titleFontSize / 2;
  constexpr sf::Color subtitleColor(168, 189, 160, 255);

  sf::Text subtitle(mainFont, subtitleText, subtitleFontSize);
  subtitle.setFillColor(subtitleColor);
  subtitle.setPosition(
      {static_cast<float>(window.getSize().x) / 2 - subtitle.getLocalBounds().size.x / 2,
       title.getLocalBounds().size.y + lineSpacing + title.getLocalBounds().position.y});

  constexpr char instructionText[] =
      "--> Use W A S D to move. You can also use the arrow keys to move.\n"
      "--> There is only one objective, don't get caught.\n"
      "--> Can you survive this utlimate game of tag.";
  constexpr unsigned instructionFontSize = subtitleFontSize / 2;
  constexpr sf::Color instructionColor(210, 123, 114, 255);

  sf::Text instructions(mainFont, instructionText, instructionFontSize);
  instructions.setFillColor(instructionColor);
  instructions.setPosition(
      {static_cast<float>(window.getSize().x) / 2 - instructions.getLocalBounds().size.x / 2,
       static_cast<float>(window.getSize().y) / 2});

  constexpr sf::Color backgroundColor(43, 52, 59, 255);

  GameState currentGameState = Menu;

  const sf::Color sliderRailColor(65, 76, 85, 255);
  const sf::Color sliderKnobColor(218, 191, 159, 255);
  const sf::Color sliderLabelColor(144, 155, 160, 255);
  const sf::Color sliderHeadingColor(133, 163, 178, 255);

  constexpr unsigned sliderAreaY = 450;
  constexpr unsigned labelSpacing = 10;

  sf::RectangleShape arenaSizeRail({300, 6});
  sf::RectangleShape botCountRail({300, 6});
  sf::RectangleShape arenaSizeKnob({12, 24});
  sf::RectangleShape botCountKnob({12, 24});

  arenaSizeRail.setFillColor(sliderRailColor);
  botCountRail.setFillColor(sliderRailColor);
  arenaSizeKnob.setFillColor(sliderKnobColor);
  botCountKnob.setFillColor(sliderKnobColor);

  arenaSizeRail.setPosition(
      {static_cast<float>(window.getSize().x) / 2 - arenaSizeRail.getSize().x / 2, sliderAreaY});
  botCountRail.setPosition(
      {static_cast<float>(window.getSize().x) / 2 - arenaSizeRail.getSize().x / 2,
       sliderAreaY + 90});

  arenaSizeKnob.setPosition({arenaSizeRail.getPosition().x + arenaSizeKnob.getSize().x / 2,
                             arenaSizeRail.getPosition().y - arenaSizeKnob.getSize().y / 2 + 2});
  botCountKnob.setPosition({botCountRail.getPosition().x + botCountKnob.getSize().x / 2,
                            botCountRail.getPosition().y - botCountKnob.getSize().y / 2 + 2});

  sf::Text arenaLowLabel(mainFont, "Low", instructionFontSize / 2.f + 2.5);
  sf::Text arenaHighLabel(mainFont, "High", instructionFontSize / 2.f + 2.5);
  sf::Text botLowLabel(mainFont, "Low", instructionFontSize / 2.f + 2.5);
  sf::Text botHighLabel(mainFont, "High", instructionFontSize / 2.f + 2.5);

  arenaLowLabel.setFillColor(sliderLabelColor);
  arenaHighLabel.setFillColor(sliderLabelColor);
  botLowLabel.setFillColor(sliderLabelColor);
  botHighLabel.setFillColor(sliderLabelColor);

  arenaLowLabel.setPosition(
      {arenaSizeRail.getPosition().x - arenaLowLabel.getLocalBounds().size.x - labelSpacing,
       arenaSizeRail.getPosition().y});
  arenaHighLabel.setPosition(
      {arenaSizeRail.getPosition().x + arenaSizeRail.getLocalBounds().size.x + labelSpacing,
       arenaSizeRail.getPosition().y});
  botLowLabel.setPosition(
      {botCountRail.getPosition().x - botLowLabel.getLocalBounds().size.x - labelSpacing,
       botCountRail.getPosition().y});
  botHighLabel.setPosition(
      {botCountRail.getPosition().x + botCountRail.getLocalBounds().size.x + labelSpacing,
       botCountRail.getPosition().y});

  constexpr unsigned sliderHeadingFontSize = instructionFontSize / 2 + 5;

  sf::Text arenaHeading(mainFont, "Arena Size", sliderHeadingFontSize);
  sf::Text botHeading(mainFont, "Number of Bots", sliderHeadingFontSize);

  arenaHeading.setFillColor(sliderHeadingColor);
  botHeading.setFillColor(sliderHeadingColor);

  arenaHeading.setPosition(
      {arenaLowLabel.getPosition().x,
       arenaSizeKnob.getPosition().y - arenaHeading.getLocalBounds().size.y - 10});
  botHeading.setPosition({botLowLabel.getPosition().x,
                          botCountKnob.getPosition().y - botHeading.getLocalBounds().size.y - 10});

  bool isArenaDragging = false;
  bool isBotDragging = false;

  unsigned short arenaSize =
      static_cast<unsigned short>(getSliderValue(arenaSizeKnob, arenaSizeRail) * 500);
  unsigned short botCount =
      static_cast<unsigned short>(getSliderValue(botCountKnob, botCountRail) * 50);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(backgroundColor);

    switch (currentGameState) {
      case Play:
        break;
      case Restart:
        break;
      case Menu:
        window.draw(title);
        window.draw(subtitle);
        window.draw(instructions);

        window.draw(arenaSizeRail);
        window.draw(botCountRail);
        window.draw(arenaLowLabel);
        window.draw(arenaHighLabel);
        window.draw(botLowLabel);
        window.draw(botHighLabel);
        window.draw(arenaHeading);
        window.draw(botHeading);

        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
          if (!isArenaDragging && !isBotDragging) {
            if (arenaSizeKnob.getGlobalBounds().contains(mousePosition)) {
              isArenaDragging = true;
            } else if (botCountKnob.getGlobalBounds().contains(mousePosition)) {
              isBotDragging = true;
            }
          }
        } else {
          isArenaDragging = false;
          isBotDragging = false;
        }

        if (isArenaDragging) {
          sf::FloatRect railBounds = arenaSizeRail.getGlobalBounds();
          float minX = railBounds.position.x;
          float maxX = railBounds.position.x + railBounds.size.x - arenaSizeKnob.getSize().x;
          float newX = mousePosition.x - arenaSizeKnob.getSize().x / 2.f;
          arenaSizeKnob.setPosition({std::clamp(newX, minX, maxX), arenaSizeKnob.getPosition().y});
        }

        if (isBotDragging) {
          sf::FloatRect railBounds = botCountRail.getGlobalBounds();
          float minX = railBounds.position.x;
          float maxX = railBounds.position.x + railBounds.size.x - botCountKnob.getSize().x;
          float newX = mousePosition.x - botCountKnob.getSize().x / 2.f;
          botCountKnob.setPosition({std::clamp(newX, minX, maxX), botCountKnob.getPosition().y});
        }

        window.draw(arenaSizeKnob);
        window.draw(botCountKnob);

        arenaSize = static_cast<unsigned short>(getSliderValue(arenaSizeKnob, arenaSizeRail) * 500);
        botCount = static_cast<unsigned short>(getSliderValue(botCountKnob, botCountRail) * 50);
        break;
    }

    window.display();
  }

  return 0;
}
