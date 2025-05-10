#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <set>

class Observer {
public:
    virtual void updateRotation(float value) = 0;
    virtual void updateColor(float value) = 0;
    virtual ~Observer() = default;
};

class Subject {
public:
    virtual void addObserver(Observer* p) = 0;
    virtual void removeObserver(Observer* p) = 0;
    virtual void notifyRotation() = 0;
    virtual void notifyColor() = 0;
    virtual ~Subject() = default;
};

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Slider : public Subject, public Drawable {
protected:
    sf::RectangleShape mTrackShape;
    sf::RectangleShape mThumbShape;
    sf::RenderWindow& mRenderWindow;
    bool mIsPressed = false;
    std::set<Observer*> mObservers;
    bool mIsColorSlider;

public:
    Slider(sf::RenderWindow& window, sf::Vector2f centerPosition,
           sf::Vector2f trackSize, sf::Vector2f thumbSize, bool isColorSlider = false)
        : mRenderWindow(window), mIsColorSlider(isColorSlider)
    {
        mTrackShape.setSize(trackSize);
        mTrackShape.setOrigin(trackSize / 2.0f);
        mTrackShape.setPosition(centerPosition);
        mTrackShape.setFillColor({200, 200, 220});

        mThumbShape.setSize(thumbSize);
        mThumbShape.setOrigin(thumbSize / 2.0f);
        mThumbShape.setPosition(centerPosition);
        mThumbShape.setFillColor({150, 150, 240});
    }

    void draw() const {
        mRenderWindow.draw(mTrackShape);
        mRenderWindow.draw(mThumbShape);
    }

    void onMouseMove(const sf::Event& event) {
        if (!mIsPressed) return;

        sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        float min = mTrackShape.getPosition().x - mTrackShape.getSize().x / 2.0f;
        float max = mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;

        mThumbShape.setPosition({std::clamp(mousePosition.x, min, max), mThumbShape.getPosition().y});

        if (mIsColorSlider) notifyColor();
        else notifyRotation();
    }

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mThumbShape.getGlobalBounds().contains(mousePosition) || mTrackShape.getGlobalBounds().contains(mousePosition))
            {
                mIsPressed = true;
                mThumbShape.setPosition({mousePosition.x, mThumbShape.getPosition().y});
                notifyObservers();
            }
        }
    }

    void onMouseReleased(const sf::Event& event)
    {
        mIsPressed = false;
    }

    void handleEvent(const sf::Event& event)
    {
        if (event.type == sf::Event::MouseMoved)
            onMouseMove(event);

        else if (event.type == sf::Event::MouseButtonPressed)
            onMousePressed(event);

        else if (event.type == sf::Event::MouseButtonReleased)
            onMouseReleased(event);
    }

    float getValue() const
    {
        float part = mThumbShape.getPosition().x - mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
        return part / mTrackShape.getSize().x * 100.0f;
    }

    void addObserver(Observer* p)
    {
        mObservers.insert(p);
    }

    void removeObserver(Observer* p)
    {
        mObservers.erase(p);
    }

    void notifyObservers()
    {
        for (auto p : mObservers)
            p->update(getValue());
    }

    void notifyRotation() override {
        float value = getValue();
        for (auto p : mObservers) p->updateRotation(value);
    }

    void notifyColor() override {
        float value = getValue();
        for (auto p : mObservers) p->updateColor(value);
    }
};

class Circle : public Observer, public Drawable {
protected:
    sf::CircleShape mShape;
    sf::RenderWindow& mRenderWindow;

public:
    Circle(sf::RenderWindow& window, sf::Vector2f position, float radius)
        : mRenderWindow(window), mShape(radius) {
        mShape.setOrigin({radius, radius});
        mShape.setPosition(position);
        mShape.setFillColor(sf::Color::Green);
    }

    void draw() const {
        mRenderWindow.draw(mShape);
    }

    void updateRotation(float value) override {
        mShape.setRotation(value * 3.6f);
    }

    void updateColor(float value) override {
        mShape.setFillColor({
            static_cast<sf::Uint8>(value * 2.55f),
            100,
            static_cast<sf::Uint8>(255 - value * 2.55f)
        });
    }
};

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Dual Sliders", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    Slider rotationSlider(window, {200, 500}, {300, 20}, {20, 40}, false);
    Slider colorSlider(window, {600, 500}, {300, 20}, {20, 40}, true);

    std::vector<Observer*> observers {
        new Circle{window, {200, 200}, 50},
        new Circle{window, {400, 300}, 30},
        new Circle{window, {600, 200}, 40}
    };

    for (auto p : observers) {
        rotationSlider.addObserver(p);
        colorSlider.addObserver(p);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            rotationSlider.handleEvent(event);
            colorSlider.handleEvent(event);
        }

        window.clear(sf::Color::Black);
        rotationSlider.draw();
        colorSlider.draw();
        for (auto p : observers)
            (dynamic_cast<Drawable*>(p))->draw();
        window.display();
    }

    for (auto p : observers)
        delete p;
}
