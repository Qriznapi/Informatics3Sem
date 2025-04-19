#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>

class Individual {
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
    virtual int gett() const = 0;
};

class Alice : public Individual {
public:
    void speak() const override {
        std::cout << "Hi, I am Alice" << std::endl;
    }
    int gett() const override {
        return 0;
    }
};

class Bob : public Individual {
public:
    void speak() const override {
        std::cout << "Hi, I am Bob" << std::endl;
    }
    int gett() const override {
        return 1;
    }
};

class Casper : public Individual {
public:
    void speak() const override {
        std::cout << "Hi, I am Casper" << std::endl;
    }
    int gett() const override {
        return 2;
    }
};

std::vector<Individual*> createIndividuals() {
    std::vector<Individual*> individuals;
    for (int i = 0; i < 3; i++)
        individuals.push_back(new Alice());
    for (int i = 0; i < 2; i++)
        individuals.push_back(new Bob());
    for (int i = 0; i < 4; i++)
        individuals.push_back(new Casper());
    return individuals;
}

void letThemSpeak(std::vector<Individual*>& individuals) {
    for (auto& ind : individuals) {
        ind->speak();
    }
}

void deleteIndividuals(std::vector<Individual*>& individuals) {
    for (auto& ind : individuals)
        delete ind;
    individuals.clear();
}

int identification_a(Individual* p) {
    return p->gett();
}

int identification_b(Individual* p) {
    if (dynamic_cast<Alice*>(p))
        return 0;
    if (dynamic_cast<Bob*>(p))
        return 1;
    if (dynamic_cast<Casper*>(p))
        return 2;
    return -1;
}

int identification_c(Individual* p) {
    if (typeid(*p) == typeid(Alice)) return 0;
    if (typeid(*p) == typeid(Bob)) return 1;
    if (typeid(*p) == typeid(Casper)) return 2;
    return -1;
}

std::vector<std::unique_ptr<Individual>> createIndividualsUniq() {
    std::vector<std::unique_ptr<Individual>> individuals;
    for (int i = 0; i < 3; i++)
        individuals.push_back(std::unique_ptr<Individual>(new Alice()));
    for (int i = 0; i < 2; i++)
        individuals.push_back(std::unique_ptr<Individual>(new Bob()));
    for (int i = 0; i < 4; i++)
        individuals.push_back(std::unique_ptr<Individual>(new Casper()));
    return individuals;
}

void letThemSpeakUniq(const std::vector<std::unique_ptr<Individual>>& individuals) {
    for (const auto& ind : individuals) {
        ind->speak();
    }
}

int main62() {
    auto individuals = createIndividuals();
    letThemSpeak(individuals);
    deleteIndividuals(individuals);
    Bob a;
    std::cout << identification_a(&a) << std::endl;
    std::cout << identification_b(&a) << std::endl;
    std::cout << identification_c(&a) << std::endl;

    auto Individuals2 = createIndividualsUniq();
    letThemSpeakUniq(Individuals2);

    return 0;
}
