#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

const int WW = 800;
const int WH = 600;
const float MD = 20.0f;
const float FS = 100.0f;

struct Ball {
    sf::CircleShape s;
    float m;
    float c;
    sf::Vector2f v;

    Ball(float r, float m, float c, sf::Vector2f p) :
        m(m), c(c), v(0, 0) {
        s.setRadius(r);
        s.setOrigin(r, r);
        s.setPosition(p);
        if (c > 0) {
            s.setFillColor(sf::Color::Red);
        } else {
            s.setFillColor(sf::Color::Blue);
        }
    }
};

sf::Vector2f calcForce(const Ball& a, const Ball& b) {
    sf::Vector2f d = b.s.getPosition() - a.s.getPosition();
    float dist = std::max(std::hypot(d.x, d.y), MD);
    float fm = (a.c * b.c) / dist;
    return (d / dist) * fm * FS;
}

void handleBC(Ball& b) {
    sf::Vector2f p = b.s.getPosition();
    float r = b.s.getRadius();
    if (p.x - r < 0 || p.x + r > WW) b.v.x *= -1;
    if (p.y - r < 0 || p.y + r > WH) b.v.y *= -1;
}

int main() {
    sf::RenderWindow w(sf::VideoMode(WW, WH), "Electric Balls");
    w.setFramerateLimit(60);

    std::vector<Ball> b;
    b.emplace_back(15, 5, -3, sf::Vector2f(100, 100));
    b.emplace_back(20, 10, 5, sf::Vector2f(400, 300));
    b.emplace_back(10, 2, -2, sf::Vector2f(600, 200));
    b.emplace_back(25, 15, 8, sf::Vector2f(200, 500));

    while (w.isOpen()) {
        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) w.close();
            if (e.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f p = w.mapPixelToCoords(sf::Mouse::getPosition(w));
                if (e.mouseButton.button == sf::Mouse::Left) b.emplace_back(10, 1, -5, p);
                else if (e.mouseButton.button == sf::Mouse::Right) b.emplace_back(30, 100, 10, p);
            }
        }

        for (size_t i = 0; i < b.size(); ++i) {
            sf::Vector2f tf(0, 0);
            for (size_t j = 0; j < b.size(); ++j) {
                if (i != j) tf += calcForce(b[i], b[j]);
            }
            b[i].v += tf / b[i].m;
        }

        for (auto& ball : b) {
            ball.s.move(ball.v);
            handleBC(ball);
        }

        w.clear();
        for (const auto& ball : b)
            w.draw(ball.s);
        w.display();
    }

    return 0;
}
