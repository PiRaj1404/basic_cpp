#include <iostream>
#include <vector>

enum PizzaSize{
    Medium,
    Large,
    XLarge,
};

enum CheeseTypes{
    Mozarella,
    American,
    Goat,
    Gorgonzolla
};

enum Ingredients{
    Onion,
    Mushroom,
    Chicken,
    BellPaper,
    Tomato
};

class Pizza{
    private:
        int private_access; 
        void private_method(){}
        void CutPizza(){
        }
    
    protected:
        int protected_access; // also functions/methods
        void protected_method(){}

    public:

        //FunctionPointer *__vptr; 

        Pizza(){
            std::cout << "Constructor PIZZA" << std::endl;
        }

        virtual ~Pizza(){
            std::cout << "Destructor PIZZA" << std::endl;
        }

        void SelectBase(const PizzaSize& size){
            // some complicated is replaced with simple print statement
            std::cout << "Select Base called in Pizza class" << std::endl;
        }

        void ApplyCheese(std::vector<CheeseTypes>& types){
            std::cout << "ApplyCheese called in Pizza class" << std::endl;
        }

        virtual std::string GetPizzaName(){
            return "GetPizzaName in Pizza";
        }

        short GetPizzaPrice(){
            return 0;
        }

        void SelectIngredients(std::vector<Ingredients>& ingredients){
            std::cout << "Following Ingredients were selected:" << std::endl;
            for(auto& i: ingredients){
                std::cout << i << std::endl;
            }
        }
};

class BBQPizza: public Pizza{ // BBQ Pizza derives from Pizza
    private:
    public:

        BBQPizza(){
            std::cout << "Constructor BBQPizza" << std::endl;
        }

        ~BBQPizza(){
            std::cout << "Destructor BBQPizza" << std::endl;
        }

        std::string GetPizzaName(){
            protected_method();
            return "BBQPizza";
        }

        short GetPizzaPrice(){
            //private_method();
            return 750;
        }

        //void SelectIngredients(){
        //    std::cout << "SelectIngredients called in BBQPizza class" << std::endl;
       //}
};

class MushroomPizza: public Pizza{ // MP is a type of Pizza
    private:
        short price;
    public:

        MushroomPizza(){
            price = 600;
            std::cout << "Constructor MushroomPizza" << std::endl;
        }

        ~MushroomPizza(){
            std::cout << "Destructor MushroomPizza" << std::endl;
        }

        std::string GetPizzaName(){ // overriding of methods/functions
            return "MushroomPizza";
        }

        short GetPizzaPrice(){
            std::cout << "this: " << this << std::endl;
            return this->price;
            // this stands for THIS object
        }

        //void SelectIngredients(){
        //    std::cout << "SelectIngredients called in MushroomPizza class" << std::endl;
        //}
};

class TripleCheese: public Pizza{
    private:
    public:

         TripleCheese(){
            std::cout << "Constructor TripleCheese" << std::endl;
        }

        ~TripleCheese(){
            std::cout << "Destructor TripleCheese" << std::endl;
        }

        std::string GetPizzaName(){
            return "TripleCheese";
        }

        short GetPizzaPrice(){
            //private_access = 10;
            protected_access = 90;
            return 1000;
        }

        void dummyMethod(){

        }

        //void SelectIngredients(){
        //    std::cout << "SelectIngredients called in TripleCheese class" << std::endl;
        //}
};



int main(){
    
   /*MushroomPizza *m_pz = new MushroomPizza();
   std::cout << "m_pz: " << m_pz << std::endl;
   std::cout << m_pz->GetPizzaPrice() << std::endl;
   delete m_pz;
   m_pz = nullptr;
   */

   std::cout << "Enter 1 for BBQPizza. 2 for Triple Cheese. \
   3 for Mushroom Pizza";
   short option = 0;
   std::cin >> option;
   Pizza *pizza = nullptr;
   
   if (1 == option)
    pizza = new BBQPizza(); // dynamic polymorphism
   else if(2 == option)
    pizza = new TripleCheese();
   else if(3 == option)
    pizza = new MushroomPizza();

    std::cout << pizza->GetPizzaName() << std::endl;
    delete pizza;
    pizza = nullptr;

    Pizza *pizza2 = new Pizza();
    std::cout << pizza2->GetPizzaName() << std::endl;
    delete pizza2;

    return 0;
}