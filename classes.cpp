#include <iostream>
#include <string>


using namespace std;

class Tail
{
    private:
        string color;
        float length;
        float weight;


    public:
        Tail()
        {
            ;
        }


    Tail(string c, float l, float w)
    {
        setColor(c);
        setLength(l);
        setWeight(w);
    }

    void setColor(string c)
    {
        color = c;
    }
    void setLength(float l)
    {
        length = l;
    }
    void setWeight(float w)
    {
        weight = w;
    }

    string getColor()
    {
        return color;
    }
    float getLength()
    {
        return length;
    }
    float getWeight()
    {
        return weight;
    }
};


class Dog
{
    private:
        string name;
        string breed;
        string color;
        int age;
        float weight;
        Tail dogTail;
    public:
        Dog(string n, string b, string c, int a, float w, string tc, float tl, float tw)
        {
            setName(n);
            setBreed(b);
            setColor(c);
            setAge(a);
            setWeight(w);
            dogTail = Tail(tc, tl, tw);
        }

        Dog()
        {
            ;
        }
        void setName(string n)
        {
            name = n;
        }
        void setBreed(string b)
        {
            breed = b;
        }
        void setColor(string c)
        {
            color = c;
        }
        void setAge(int a)
        {
            age = a;
        }
        void setWeight(float w)
        {
            weight = w;
        }
        void setTailColor(string tc)
        {
            dogTail.setColor(tc);
        }
        void setTailLength(float tl)
        {
            dogTail.setLength(tl);
        }        
        void setTailWeight(float tw)
        {
            float delta = tw - dogTail.getWeight();
            weight = weight + delta;
            dogTail.setWeight(tw);
        }        

        string getName()
        {
            return name;
        } 
        string getBreed()
        {
            return breed;
        }
        string getColor()
        {
            return color;
        }
        int getAge()
        {
            return age;
        }
        float getWeight()
        {
            return weight;
        }
        string getTailColor()
        {
            return dogTail.getColor();
        }
};

Dog dogFunction(Dog dog1, Dog dog2)
{
    if(dog1.getWeight() >= dog2.getWeight())
    {
        return dog1;
    }
    else
    {
        return dog2;
    }
}


string function(int x)
{
    return "hello";
}
string function(string x)
{
    return "world";
}
string function(int x, string y)
{
    return "hi";
}


int main()
{
    Dog dog1("Fido", "poodle", "black", 6, 45.2, "black", 1.0, 0.5);
    Dog dog2("Spot", "golden retriever", "yellow", 3, 55.2, "yellow", 1.0, 0.5);

    dog2.setName("Max");

     Dog dog3;

    int x = 5;
    cout << function(x) << endl;

    string y = "abc";
    cout << function(y) << endl;

    cout << function(x, y) << endl;


    Dog heavyDog = dogFunction(dog1, dog2);
    cout << heavyDog.getName() << endl;
    
    return 0;
}