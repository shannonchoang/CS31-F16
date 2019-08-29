#include <iostream>
#include <string>

using namespace std;

class Pet
{
  public:
    Pet(string nm, int initialHealth);
    void eat(int amt);
    void play();
    string name() const;
    int health() const; //1. a non-member func is used on this, it can't be private
    bool alive() const;
  private:
    string m_name;
    int m_health;
};

  // Initialize the state of the pet
Pet::Pet(string nm, int initialHealth)
{
    m_name = nm;
    m_health = initialHealth;
}

//2. if you comment this out; probs when u try to use func later on
void Pet::eat(int amt)
{
    m_health += amt;
      // DONE: Increase the pet's health by the amount
}

void Pet::play()
{
    m_health --; 
      // DONE: Decrease pet's health by 1 for the energy consumed
}

string Pet::name() const
{
      // DONE: Return the pet's name.  Delete the following line and
      // replace it with the correct code.
    return m_name; // This implementation compiles, but is incorrect
}

int Pet::health() const
{
      //TODO: ASK TO CHECK
      // DONE: Return the pet's current health level.  Delete the
      // following line and replace it with the correct code.
    return m_health; // This implementation compiles, but is incorrect
}

bool Pet::alive() const //4.if const is commented out it doesn't match the declaration
{
      // TODO: Return whether pet is alive.  (A pet is alive if
      // its health is greater than zero.)  Delete the following
      // line and replace it with the correct code.
    return (m_health > 0); // This implementation compiles, but is incorrect
}

/////////
// Do not change any code below this point
/////////

void reportStatus(const Pet* p)
{
    cout << p->name() << " has health level " << p->health();
    if ( ! p->alive())
        cout << ", so has died";
    cout << endl;
}

void careFor(Pet* p, int d)
{
    if ( ! p->alive())
    {
        cout << p->name() << " is still dead" << endl;
        return;
    }

      // Every third day, you forget to feed your pet
    if (d % 3 == 0)
        cout << "You forgot to feed " << p->name() << endl;
    else
    {
        p->eat(1);  // Feed the pet one unit of food
        cout << "You fed " << p->name() << endl;
    }

    p->play();
    reportStatus(p);
}

int main()
{
    Pet* myPets[2];
    //trying to replace this with:
    //myPets[0] = new Pet("Fluffy");
    //doesn't work because the args don't match 
    myPets[0] = new Pet("Fluffy", 2);
    myPets[1] = new Pet("Frisky", 4);
    for (int day = 1; day <= 9; day++)
    {
        cout << "======= Day " << day << endl;
        for (int k = 0; k < 2; k++)
            careFor(myPets[k], day);
    }
    cout << "=======" << endl;
    for (int k = 0; k < 2; k++)
    {
        if (myPets[k]->alive())
            cout << "Animal Control has come to rescue "
                 << myPets[k]->name() << endl;
        delete myPets[k];
    }
}
