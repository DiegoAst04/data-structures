#include <SFML/Graphics.hpp>
#include <string>

sf::Font globalFont("arial.ttf");

class Label {
    sf::Text text;

public:
    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }

    Label(int x, sf::Vector2f center) : text(globalFont) {
        text.setString(std::to_string(x));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(center);
    }
};

struct node {
    node* nodes[2] = { nullptr };
    int value;

    sf::CircleShape shape;
    std::optional<Label> text;

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        if (text.has_value()) text->draw(window);
    }

    node(int x, float px = 300, float py = 300) : value(x) {
        shape.setRadius(20.f);
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineThickness(2.f);
        shape.setPosition({ px, py });

        sf::Vector2f coords = shape.getPosition();
        text.emplace(x, sf::Vector2f(coords.x+6, coords.y+5) );
    }
};

class BST {
public:
    node* root = nullptr;

    bool find(int x, node**& p) {
        p = &root;
        while (*p && (*p)->value != x) {
            p = &((*p)->nodes[x > (*p)->value]);
        }
        return *p != 0;
    }
    void insert(int x) {
        node** p;
        if (find(x, p)) return;
        *p = new node(x);
    }
    void remove(int x);

    void InOrder(node* p);
    void PreOrder(node* p);
    void PostOrder(node* p);

    void Level(node* p);
    void ios(node* p);
    void drawChart();
};

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1600, 900 }), "SFML works!");
    window.setFramerateLimit(30);
    
    node n(10, 90, 80);
    node m(20);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    
        window.clear();

        n.draw(window);
        m.draw(window);
        
        window.display();
    }
}