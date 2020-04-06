#include "catch2/catch.hpp"

#include "floor.hpp"

TEST_CASE("giovanni: IsInXRange", "[giovanni]")
{
    {
        sf::RectangleShape square;
        square.setPosition({0, 0});
        square.setSize({100, 100});
        
        gio::Floor floor {};
        floor.GetShape().setPosition({0, 500});
        floor.GetShape().setSize({200, 50});
        
        REQUIRE(floor.IsInXRange(square) == true);
    }
    
    {
        sf::RectangleShape square;
        square.setPosition({300, 0});
        square.setSize({100, 100});
        
        gio::Floor floor {};
        floor.GetShape().setPosition({0, 500});
        floor.GetShape().setSize({200, 50});
        
        REQUIRE(floor.IsInXRange(square) == false);
    }
    
    {
        sf::RectangleShape square;
        square.setPosition({199,0});
        square.setSize({100, 100});
        
        gio::Floor floor {};
        floor.GetShape().setPosition({0, 500});
        floor.GetShape().setSize({200, 50});
        
        REQUIRE(floor.IsInXRange(square) == true);
    }
    
    {
        sf::RectangleShape square;
        square.setPosition({0, 0});
        square.setSize({100, 100});
        
        gio::Floor floor {};
        floor.GetShape().setPosition({99, 500});
        floor.GetShape().setSize({200, 50});
        
        REQUIRE(floor.IsInXRange(square) == true);
    }


}
