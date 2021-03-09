//
// Created by eviat on 3/4/2021.
//
#include "doctest.h"
# include <iostream>
#include "snowman.hpp"
#include <cmath>
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Hat"){
    /*check all the types of the hats */

            CHECK(snowman(11114411) == string("\n_===_\n(.,.)\n( : )\n( : )"));
            //_===_

            CHECK(snowman(23414431) == string("\n___\n.....\n(-_.)\n(> <)\n( : )"));
            // ___
            //.....

            CHECK(snowman(32142412) == string("\n_\n/_\\\n\\(..-)\n( : )\n(\" \")"));
            //  _
            // /_\

            CHECK(snowman(44444444) == string("\n___\n(_*_)\n(- -)\n(   )\n(   )"));
            // ___
            //(_*_)
}

TEST_CASE("Face"){
    /*check all the combination of the faces of the snowman*/
            //left eye - 3 digit
            CHECK(snowman(11114411) == string("\n_===_\n(.,.)\n( : )\n( : )"));
            CHECK(snowman(12211313) == string("\n_===_\n(o..)\n<( : )\\\n(___)"));
            CHECK(snowman(44344444) == string("\n___\n(_*_)\n(O -)\n(   )\n(   )"));
            CHECK(snowman(11411442) == string("\n_===_\n(-,.)\n<(   )\n(\" \")"));

            //right eye- 4 digit
            CHECK(snowman(12211313) == string("\n_===_\n(o..)\n<( : )\\\n(___)"));
            CHECK(snowman(14122121) == string("\n_===_\n\\(. o)\n(] [)>\n( : )"));
            CHECK(snowman(41133114) == string("\n___\n(_*_)\n(.,O)\n/( : )>\n(   )"));
            CHECK(snowman(41444111) == string("\n___\n(_*_)\n(-,-)\n( : )>\n( : )"));

            //nose- 2 digit
            CHECK(snowman(11211313) == string("\n_===_\n(o,.)\n<( : )\\\n(___)"));
            CHECK(snowman(12132121) == string("\n_===_\n\\(..O)\n(] [)>\n( : )"));
            CHECK(snowman(43113114) == string("\n___\n(_*_)\n(._.)\n/( : )>\n(   )"));
            CHECK(snowman(44414111) == string("\n___\n(_*_)\n(- .)\n( : )>\n( : )"));

}

TEST_CASE("Torso"){ //7 digit
            CHECK(snowman(11114411) == string("\n_===_\n(.,.)\n( : )\n( : )"));
            CHECK(snowman(14131121) == string("\n_===_\n(. O)\n<(] [)>\n( : )"));
            CHECK(snowman(23414431) == string("\n___\n.....\n(-_.)\n(> <)\n( : )"));
            CHECK(snowman(44444444) == string("\n___\n(_*_)\n(- -)\n(   )\n(   )"));
}
TEST_CASE("Arms"){
            //left arms- 5 digit
            CHECK(snowman(11411442) == string("\n_===_\n(-,.)\n<(   )\n(\" \")"));
            CHECK(snowman(32142412) == string("\n_\n/_\\\n\\(..-)\n( : )\n(\" \")"));
            CHECK(snowman(12143313) == string("\n_===_\n(..-)\n/( : )\\\n(___)"));
            CHECK(snowman(11114411) == string("\n_===_\n(.,.)\n( : )\n( : )"));

            //right arms- 6 digit
            CHECK(snowman(14131121) == string("\n_===_\n(. O)\n<(] [)>\n( : )"));
            CHECK(snowman(12143213) == string("\n_===_\n(..-)/\n/( : )\n(___)"));
            CHECK(snowman(12143313) == string("\n_===_\n(..-)\n/( : )\\\n(___)"));
            CHECK(snowman(44444444) == string("\n___\n(_*_)\n(- -)\n(   )\n(   )"));
}
TEST_CASE("Base"){ //8 digit
            CHECK(snowman(11114411) == string("\n_===_\n(.,.)\n( : )\n( : )"));
            CHECK(snowman(11411442) == string("\n_===_\n(-,.)\n<(   )\n(\" \")"));
            CHECK(snowman(12143313) == string("\n_===_\n(..-)\n/( : )\\\n(___)"));
            CHECK(snowman(44444444) == string("\n___\n(_*_)\n(- -)\n(   )\n(   )"));
}
TEST_CASE("Good snowman code") {
    /* Compare the results of legal cases */

            CHECK(snowman(11114411) == string("\n_===_\n(.,.)\n( : )\n( : )"));
            CHECK(snowman(44444444) == string("\n___\n(_*_)\n(- -)\n(   )\n(   )"));
            CHECK(snowman(12143313) == string("\n_===_\n(..-)\n/( : )\\\n(___)"));
            CHECK(snowman(11411442) == string("\n_===_\n(-,.)\n<(   )\n(\" \")"));
            CHECK(snowman(23414431) == string("\n___\n.....\n(-_.)\n(> <)\n( : )"));
            CHECK(snowman(12211313) == string("\n_===_\n(o..)\n<( : )\\\n(___)"));
            CHECK(snowman(14131121) == string("\n_===_\n(. O)\n<(] [)>\n( : )"));
            CHECK(snowman(41111114) == string("\n___\n(_*_)\n(.,.)\n<( : )>\n(   )"));
            CHECK(snowman(41411111) == string("\n___\n(_*_)\n(-,.)\n<( : )>\n( : )"));
            CHECK(snowman(14134411) == string("\n_===_\n(. O)\n( : )\n( : )"));
            CHECK(snowman(32142412) == string("\n_\n/_\\\n\\(..-)\n( : )\n(\" \")"));

}

TEST_CASE("short length input") {
    /* check at randomly 10 option of evert decimals numbers */

    //check numbers between 0-10
    for(int i=0; i<10; i++){
        int random= rand()%10;
        CHECK_THROWS(snowman((random)));
    }

    //check numbers between 10 - 100
    for(int i=0; i< 10; i++){
        int random= rand()%90 +10;
        CHECK_THROWS(snowman(random));
    }

    //check numbers between 100-1000
    for(int i=0; i<10; i++){
        int random= rand()%900+100;
        CHECK_THROWS(snowman(random));
    }

    //check number between 1000- 10000
    for(int i=0 ; i<10; i++){
        int random = rand()%9000 +1000;
        CHECK_THROWS(snowman(random));
    }
}

TEST_CASE("long numbers") {
    /* numbers that bigger than 8 digits */

    for(int i=0; i<10; i++){
        int random = rand()+10000000;
        CHECK_THROWS(snowman(random));
    }

}

//legal length of input but illegal number - numbers between 5-9
TEST_CASE("illegal digits"){

    int number=0;
    for(int i=0; i< 8 ; i++){
        int power = pow(10,i);  //number between 1 digit to 8 digits
        int random= rand()%5+5;
        number += pow(random,power);
    }
    CHECK_THROWS(snowman(number));

    for(int i=0; i< 8 ; i++){
        int power = pow(10,i);  //number between 1 digit to 8 digits
        int random= rand()%5+5;
        number += pow(random,power);
    }
    CHECK_THROWS(snowman(number));

    for(int i=0; i< 8 ; i++){
        int power = pow(10,i);  //number between 1 digit to 8 digits
        int random= rand()%5+5;
        number += pow(random,power);
    }
    CHECK_THROWS(snowman(number));
}

TEST_CASE("illegal negative input") {
    /* check at randomly 10 option of evert decimals numbers negative numbers*/

    //check numbers between 0-10
    for(int i=0; i<10; i++){
        int random= -rand()%10;
                CHECK_THROWS(snowman((random)));
    }

    //check numbers between 10 - 100
    for(int i=0; i< 10; i++){
        int random= -rand()%90 +10;
                CHECK_THROWS(snowman(random));
    }

    //check numbers between 100-1000
    for(int i=0; i<10; i++){
        int random= -rand()%900+100;
                CHECK_THROWS(snowman(random));
    }

    //check number between 1000- 10000
    for(int i=0 ; i<10; i++){
        int random = -rand()%9000 +1000;
                CHECK_THROWS(snowman(random));
    }
            //numbers contain characters
            CHECK_THROWS(snowman('z'));
            CHECK_THROWS(snowman(555+ 't'));
            CHECK_THROWS(snowman('t'+12341239));
            CHECK_THROWS(snowman(1234432123+'x'));
            CHECK_THROWS(snowman(3402432+'H'));

}



