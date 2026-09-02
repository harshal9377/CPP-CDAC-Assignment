#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:
    Entity& setName(const string& n)
    {
        this->name = n;
        return *this;
    }

    Entity& setHealth(int h)
    {
        this->health = h;
        return *this;
    }

    Entity& setLevel(int l)
    {
        this->level = l;
        return *this;
    }

    Entity& setType(const string& t)
    {
        this->type = t;
        return *this;
    }

    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }

    void displayInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
        cout << "Type: " << type << endl;
        cout << endl;
    }
};


namespace Physics
{
    double clamp(double value, double minimum, double maximum)
    {
        if(maximum < minimum)
            return 0;

        cout << "Physics Clamp called" << endl;

        if(value < minimum)
            return minimum;

        if(value > maximum)
            return maximum;

        return value;
    }

    double lerp(double first, double second, double t)
    {
        cout << "Physics Lerp called" << endl;
        return first + t * (second - first);
    }
}


namespace GameMath
{
    int clamp(int value, int minimum, int maximum)
    {
        if(maximum < minimum)
            return 0;

        cout << "GameMath Clamp called" << endl;

        if(value < minimum)
            return minimum;

        if(value > maximum)
            return maximum;

        return value;
    }

    double lerp(double first, double second, double t)
    {
        cout << "Gamemath Lerp called" << endl;
        return first + t * (second - first);
    }
}


void populateCount(int& grass, int& water, int& mountain,
                   int& forest, int& dungeon, int tile)
{
    if(tile == 0)
        grass++;
    else if(tile == 1)
        water++;
    else if(tile == 2)
        mountain++;
    else if(tile == 3)
        forest++;
    else
        dungeon++;
}


int level = 1;


namespace Engine
{
    namespace Audio
    {
        void playSound(string sound)
        {
            cout << "Playing: " << sound << endl;
        }
    }
}


int main()
{
    //--------------------------- PART A ---------------------------

    Entity player, enemy, item;

    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");

    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");

    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");


    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();


    //--------------------------- PART B ---------------------------

    cout << "Physics Clamp: ";
    cout << Physics::clamp(30, 50, 100) << endl;

    cout << "Physics Lerp: ";
    cout << Physics::lerp(3, 7, 64) << endl << endl;

    cout << "GameMath Clamp: ";
    cout << GameMath::clamp(-2, 50, 100) << endl;

    cout << "GameMath Lerp: ";
    cout << GameMath::lerp(3, 66, 64) << endl;


    {
        using namespace Physics;
        cout << clamp(10, 20, 3000);
    }

    cout << endl;

    {
        using namespace GameMath;
        cout << clamp(8000, 20, 590);
    }

    cout << endl;


    //--------------------------- PART C ---------------------------

    int R = 3;
    int C = 4;

    int** grid = new int*[R];

    for(int i = 0; i < R; i++)
    {
        grid[i] = new int[C];

        for(int j = 0; j < C; j++)
        {
            grid[i][j] = rand() % 5;
        }
    }


    cout << "===== GAME MAP " << R << " * " << C << " =====" << endl;

    int grass = 0;
    int water = 0;
    int mountain = 0;
    int forest = 0;
    int dungeon = 0;


    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            populateCount(grass, water, mountain,
                          forest, dungeon, grid[i][j]);

            cout << grid[i][j] << " ";
        }

        cout << endl;
    }


    cout << "Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon" << endl;
    cout << endl;

    cout << "Tile Count:" << endl;
    cout << "Grass : " << grass << endl;
    cout << "Water : " << water << endl;
    cout << "Mountain : " << mountain << endl;
    cout << "Forest : " << forest << endl;
    cout << "Dungeon : " << dungeon << endl;


    //--------------------------- BONUS ---------------------------

    int level = 10;

    cout << "Printing global value: " << ::level << endl;
    cout << "Printing local value: " << level << endl;

    cout << "Calling Nested Namespace: " << endl;
    cout << endl;

    Engine::Audio::playSound("sword_clash");


    // Free dynamic memory
    for(int i = 0; i < R; i++)
    {
        delete[] grid[i];
    }

    delete[] grid;


    return 0;
}