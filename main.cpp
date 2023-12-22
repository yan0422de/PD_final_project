#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cards.h"
#include "Diamonds.h"
#include "game.h"
using namespace std;

int main()
{
    Game myGame;
   

    // Set up windows
    sf::RenderWindow window(sf::VideoMode(1024, 800), "Splendor", sf::Style::Close | sf::Style::Resize, sf::ContextSettings{ 0, 0, 8 });

    // background(size、texture、position)
    sf::RectangleShape background(sf::Vector2f(1024.0f, 800.0f));
    sf::Texture backgroundTexture;
    background.setPosition(0.f, 0.0f);
    backgroundTexture.loadFromFile("background.png");
    background.setTexture(&backgroundTexture);

    // deck on board
    sf::RectangleShape deckVendor(sf::Vector2f(75.0f, 130.0f));
    sf::Texture deckVendorTexture;
    deckVendor.setPosition(200.f, 180.0f);
    deckVendorTexture.loadFromFile("vendor.png");
    deckVendor.setTexture(&deckVendorTexture);

    sf::RectangleShape deckTransport(sf::Vector2f(75.0f, 130.0f));
    sf::Texture deckTransportTexture;
    deckTransport.setPosition(200.f, 345.0f);
    deckTransportTexture.loadFromFile("transport.png");
    deckTransport.setTexture(&deckTransportTexture);

    sf::RectangleShape deckMine(sf::Vector2f(75.0f, 130.0f));
    sf::Texture deckMineTexture;
    deckMine.setPosition(200.f, 510.0f);
    deckMineTexture.loadFromFile("mine.png");
    deckMine.setTexture(&deckMineTexture);

    // Declare and load a font
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Create score board
    sf::Text ScoreBoard1("Score:", font);
    ScoreBoard1.setPosition(900.f, 700.f);
    ScoreBoard1.setCharacterSize(30);
    ScoreBoard1.setStyle(sf::Text::Bold);
    ScoreBoard1.setFillColor(sf::Color::White);

    sf::Text ScoreBoard2("Score:", font);
    ScoreBoard2.setPosition(900.f, 10.f);
    ScoreBoard2.setStyle(sf::Text::Bold);
    ScoreBoard2.setFillColor(sf::Color::White);

    // Create Discount board
    sf::Text Discount1("Discount:", font);
    Discount1.setPosition(430.f, 695.f);
    Discount1.setCharacterSize(20);
    Discount1.setStyle(sf::Text::Bold);
    Discount1.setFillColor(sf::Color::White);

    sf::Text Discount2("Discount:", font);
    Discount2.setPosition(430.f, 5.f);
    Discount2.setCharacterSize(20);
    Discount2.setStyle(sf::Text::Bold);
    Discount2.setFillColor(sf::Color::White);


    // Create diamond board
    sf::Text diamond1("Diamond:", font);
    diamond1.setPosition(430.f, 745.f);
    diamond1.setCharacterSize(20);
    diamond1.setStyle(sf::Text::Bold);
    diamond1.setFillColor(sf::Color::White);

    sf::Text diamond2("Diamond:", font);
    diamond2.setPosition(430.f, 55.f);
    diamond2.setCharacterSize(20);
    diamond2.setStyle(sf::Text::Bold);
    diamond2.setFillColor(sf::Color::White);


    // discount position
    vector<sf::Text> discountPlayer1(6, sf::Text("0", font));
    vector<sf::Text> discountPlayer2(6, sf::Text("0", font));
    for (int i = 0; i < 6; i++) {
        discountPlayer1[i].setPosition((i % 6) * 50.f + 545.f, 712.f);
        discountPlayer1[i].setCharacterSize(20);
        discountPlayer1[i].setStyle(sf::Text::Bold);

        discountPlayer2[i].setPosition((i % 6) * 50.f + 545.f, 18.f);
        discountPlayer2[i].setCharacterSize(20);
        discountPlayer2[i].setStyle(sf::Text::Bold);
    }

    // discount color
    discountPlayer1[0].setFillColor(sf::Color::White);
    discountPlayer1[1].setFillColor(sf::Color::Black);
    discountPlayer1[2].setFillColor(sf::Color::Red);
    discountPlayer1[3].setFillColor(sf::Color::Green);
    discountPlayer1[4].setFillColor(sf::Color::Blue);
    discountPlayer1[5].setFillColor(sf::Color::Yellow);

    discountPlayer2[0].setFillColor(sf::Color::White);
    discountPlayer2[1].setFillColor(sf::Color::Black);
    discountPlayer2[2].setFillColor(sf::Color::Red);
    discountPlayer2[3].setFillColor(sf::Color::Green);
    discountPlayer2[4].setFillColor(sf::Color::Blue);
    discountPlayer2[5].setFillColor(sf::Color::Yellow);

    // Diamond numbers
    vector<sf::Text> diamondNumBoard(6, sf::Text("4", font));
    vector<sf::Text> diamondNumPlayer1(6, sf::Text("0", font));
    vector<sf::Text> diamondNumPlayer2(6, sf::Text("0", font));

    // Diamond position
    vector<Diamond*> diamond(6);
    vector<Diamond*> diamondPlayer1(6);
    vector<Diamond*> diamondPlayer2(6);
    for (int i = 0; i < 6; i++) {
        diamond[i] = new Diamond(0, sf::CircleShape(20.f), sf::Color::White, sf::Vector2f(50.f, (i % 6) * 70.f + 200.f));
        diamondPlayer1[i] = new Diamond(0, sf::CircleShape(20.f), sf::Color::White, sf::Vector2f(550.f + (i % 6) * 50.f, 730.f));
        diamondPlayer2[i] = new Diamond(0, sf::CircleShape(20.f), sf::Color::White, sf::Vector2f(550.f + (i % 6) * 50.f, 35.f));
    }

    // Diamond color
    diamond[1]->getShape()->setFillColor(sf::Color::Black);
    diamond[2]->getShape()->setFillColor(sf::Color::Red);
    diamond[3]->getShape()->setFillColor(sf::Color::Green);
    diamond[4]->getShape()->setFillColor(sf::Color::Blue);
    diamond[5]->getShape()->setFillColor(sf::Color::Yellow);

    diamondPlayer1[1]->getShape()->setFillColor(sf::Color::Black);
    diamondPlayer1[2]->getShape()->setFillColor(sf::Color::Red);
    diamondPlayer1[3]->getShape()->setFillColor(sf::Color::Green);
    diamondPlayer1[4]->getShape()->setFillColor(sf::Color::Blue);
    diamondPlayer1[5]->getShape()->setFillColor(sf::Color::Yellow);

    diamondPlayer2[1]->getShape()->setFillColor(sf::Color::Black);
    diamondPlayer2[2]->getShape()->setFillColor(sf::Color::Red);
    diamondPlayer2[3]->getShape()->setFillColor(sf::Color::Green);
    diamondPlayer2[4]->getShape()->setFillColor(sf::Color::Blue);
    diamondPlayer2[5]->getShape()->setFillColor(sf::Color::Yellow);
    

    // Create position for board
    vector<sf::Vector2f> vendorsPosition(4);
    vector<sf::Vector2f> transportPosition(4);
    vector<sf::Vector2f> minesPosition(4);
    for (int i = 0; i < 4; i++) {
        float xPos = 350.0f + (i % 4) * 150.0f;
        float yPos = 180.0f;
        myGame.board[0][i]->setPosition(sf::Vector2f(xPos, yPos));
        myGame.board[0][i]->setTargetPosition(sf::Vector2f(xPos, yPos));
        vendorsPosition[i] = sf::Vector2f(xPos, yPos);
    }

    for (int i = 0; i < 4; i++) {
        float xPos = 350.0f + (i % 4) * 150.0f;
        float yPos = 345.0f;
        myGame.board[1][i]->setPosition(sf::Vector2f(xPos, yPos));
        myGame.board[1][i]->setTargetPosition(sf::Vector2f(xPos, yPos));
        transportPosition[i] = sf::Vector2f(xPos, yPos);
    }

    for (int i = 0; i < 4; i++) {
        float xPos = 350.0f + (i % 4) * 150.0f;
        float yPos = 510.0f;
        myGame.board[2][i]->setPosition(sf::Vector2f(xPos, yPos));
        myGame.board[2][i]->setTargetPosition(sf::Vector2f(xPos, yPos));
        minesPosition[i] = sf::Vector2f(xPos, yPos);
    }
    

    vector<Card*> handCards1(15);
    // Create position for bought cards for player1
    vector<sf::Vector2f> targetPosForCard1(15);
    for (int i = 0; i < targetPosForCard1.size(); i++) {
        targetPosForCard1[i] = sf::Vector2f(30.0f + i * 95.0f, 810.0f);
    }

    vector<Card*> reservedCards1(3, nullptr);
    // Create position for reserved cards for player1
    vector<sf::Vector2f> targetPosForReservedCards1(3);
    for (int i = 0; i < targetPosForReservedCards1.size(); i++) {
        targetPosForReservedCards1[i] = sf::Vector2f(25.0f + i * 120.0f, 660.0f);
    }

    vector<Card*> handCards2(15);
    // Create position for bought cards for player2
    vector<sf::Vector2f> targetPosForCard2(15);
    for (int i = 0; i < targetPosForCard2.size(); i++) {
        targetPosForCard2[i] = sf::Vector2f(30.0f + i * 95.0f, -200.0f);
    }

    vector<Card*> reservedCards2(3, nullptr);
    // Create position for reserved cards for player2
    vector<sf::Vector2f> targetPosForReservedCards2(3);
    for (int i = 0; i < targetPosForReservedCards2.size(); i++) {
        targetPosForReservedCards2[i] = sf::Vector2f(25.0f + i * 120.0f, 10.0f);
    }

    // document player's bought card and the number of the deck
    int cardnumOfplayer1 = 0;
    int cardnumOfplayer2 = 0;
    int reservedCardnumOfplayer1[3] = { 0, 0, 0 };
    int reservedCardnumOfplayer2[3] = { 0, 0, 0 };

    int minesNum = 4;
    int vendorsNum = 4;
    int transportNum = 4;

    // Diamond color
    int color = 0;

    // moving speed
    float moveSpeed = 5.0f;

    // 記document every player every round taken diamonds
    int diamondPerMove = 0;
    int diamondPerRound[3] = { -1, -1, -1 };

  

    while (window.isOpen()) {

        sf::Event evnt;
        if (window.pollEvent(evnt)) {
            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:

                std::cout << myGame.playerNum << '\n';
                if (myGame.playerNum == 1) {
                    if (evnt.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        // buy card
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (myGame.board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && myGame.taked_gems == 0) {
                                    // move from board to hand
                                    myGame.boughtcard = myGame.board[i][j];
                                    handCards1[cardnumOfplayer1] = myGame.board[i][j];
                                    handCards1[cardnumOfplayer1]->setTargetPosition(targetPosForCard1[cardnumOfplayer1]);
                                    cardnumOfplayer1++;
                                    myGame.board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        myGame.vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        myGame.board[i][j] = myGame.vendors[vendorsNum++];
                                    }
                                    else if (i == 1) {
                                        // move deck card to board
                                        myGame.transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        myGame.board[i][j] = myGame.transport[transportNum++];
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        myGame.mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        myGame.board[i][j] = myGame.mines[minesNum++];
                                    }
                                    /* update game command */
                                    myGame.cardpos[0] = i;
                                    myGame.cardpos[1] = j;
                                    myGame.command[0] = 1;      // buy
                                }
                            }
                        }

                        // buy reserved cards
                        for (int i = 0; i < 3; i++) {
                            if (reservedCards1[i] && reservedCards1[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && myGame.taked_gems == 0) {
                                myGame.reservedCard = reservedCards1[i];

                                handCards1[cardnumOfplayer1] = reservedCards1[i];
                                reservedCards1[i] = nullptr;
                                handCards1[cardnumOfplayer1]->setTargetPosition(targetPosForCard1[cardnumOfplayer1]);
                                cardnumOfplayer1++;

                                reservedCardnumOfplayer1[i] = 0;

                                /* update game command */
                                myGame.command[1] = 1;      // buy_reserve
                            }
                        }

                        // take diamonds
                        for (int i = 0; i < 6; i++) {
                            if (diamond[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                if (myGame.taked_gems == 0) {      // first gem
                                    myGame.dimondcolor[i] = 1;
                                    myGame.taked_gems++;
                                }
                                else if (myGame.taked_gems == 1) {
                                    if (myGame.dimondcolor[i] == 1) {
                                        myGame.dimondcolor[i] = 2;
                                        myGame.command[2] = 1;      // tak2gems
                                        myGame.taked_gems++;
                                    }
                                    else {
                                        myGame.dimondcolor[i] = 1;
                                        myGame.taked_gems++;
                                    }
                                }
                                else if (myGame.taked_gems == 2) {
                                    if (myGame.dimondcolor[i] == 0) {
                                        myGame.dimondcolor[i] = 1;
                                        myGame.command[3] = 1;      // tak3gems
                                        myGame.taked_gems++;
                                    }
                                }
                            }
                        }
                    }   // left end

                    // reserve card (clicked right)
                    if (evnt.mouseButton.button == sf::Mouse::Right) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        int spaceReserved;
                        for (spaceReserved = 0; spaceReserved < 3; spaceReserved++) {
                            if (reservedCardnumOfplayer1[spaceReserved] == 0) break;
                        }

                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (myGame.board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && myGame.taked_gems == 0 && spaceReserved < 3) {
                                    // move from board to hand
                                    myGame.reservedCard = myGame.board[i][j];

                                    reservedCards1[spaceReserved] = myGame.board[i][j];
                                    reservedCards1[spaceReserved]->setTargetPosition(targetPosForReservedCards1[spaceReserved]);
                                    reservedCardnumOfplayer1[spaceReserved] = 1;

                                    myGame.board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        myGame.vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        myGame.board[i][j] = myGame.vendors[vendorsNum++];
                                    }
                                    else if (i == 1) {
                                        // move deck card to board
                                        myGame.transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        myGame.board[i][j] = myGame.transport[transportNum++];
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        myGame.mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        myGame.board[i][j] = myGame.mines[minesNum++];
                                    }
                                    myGame.cardpos[0] = i;
                                    myGame.cardpos[1] = j;
                                    myGame.command[4] = 1;  // reserve_card
                                }
                            }
                        }
                    }
                }

                // 2nd player's turn
                else {
                    if (evnt.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        // buy card
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (myGame.board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && myGame.taked_gems == 0) {
                                    // move from board to hand
                                    myGame.boughtcard = myGame.board[i][j];
                                    handCards2[cardnumOfplayer2] = myGame.board[i][j];
                                    handCards2[cardnumOfplayer2]->setTargetPosition(targetPosForCard2[cardnumOfplayer2]);
                                    cardnumOfplayer2++;
                                    myGame.board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        myGame.vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        myGame.board[i][j] = myGame.vendors[vendorsNum++];
                                    }
                                    else if (i == 1) {
                                        // move deck card to board
                                        myGame.transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        myGame.board[i][j] = myGame.transport[transportNum++];
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        myGame.mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        myGame.board[i][j] = myGame.mines[minesNum++];
                                    }
                                    // command buy
                                    myGame.cardpos[0] = i;
                                    myGame.cardpos[1] = j;
                                    myGame.command[0] = 1;      // buy
                                }
                            }
                        }

                        // buy reserved cards
                        for (int i = 0; i < 3; i++) {
                            if (reservedCards2[i] && reservedCards2[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && myGame.taked_gems == 0 && reservedCardnumOfplayer2[i] > 0) {
                                myGame.reservedCard = reservedCards2[i];
                                // move from board to hand
                                handCards2[cardnumOfplayer2] = reservedCards2[i];
                                reservedCards2[i] = nullptr;
                                handCards2[cardnumOfplayer2]->setTargetPosition(targetPosForCard2[cardnumOfplayer2]);
                                cardnumOfplayer2++;

                                reservedCardnumOfplayer2[i] = 0;

                                // command buy reserved
                                myGame.command[1] = 1;      // buy_reserve
                            }
                        }

                        for (int i = 0; i < 6; i++) {
                            if (diamond[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {

                                if (myGame.taked_gems == 0) {      // first gem
                                    myGame.dimondcolor[i] = 1;
                                    myGame.taked_gems++;
                                }
                                else if (myGame.taked_gems == 1) {
                                    if (myGame.dimondcolor[i] == 1) {
                                        myGame.dimondcolor[i] = 2;
                                        myGame.command[2] = 1;      // tak2gems
                                        myGame.taked_gems++;
                                    }
                                    else {
                                        myGame.dimondcolor[i] = 1;
                                        myGame.taked_gems++;
                                    }
                                }
                                else if (myGame.taked_gems == 2) {
                                    if (myGame.dimondcolor[i] == 0) {
                                        myGame.dimondcolor[i] = 1;
                                        myGame.command[3] = 1;      // tak3gems
                                        myGame.taked_gems++;
                                    }
                                }
                            }
                        }
                    }

                    // reserve card (clicked right)
                    if (evnt.mouseButton.button == sf::Mouse::Right) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        int spaceReserved;
                        for (spaceReserved = 0; spaceReserved < 3; spaceReserved++) {
                            if (reservedCardnumOfplayer2[spaceReserved] == 0) break;
                        }

                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (myGame.board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && myGame.taked_gems == 0) {
                                    // move from board to hand
                                    myGame.reservedCard = myGame.board[i][j];

                                    reservedCards2[spaceReserved] = myGame.board[i][j];
                                    reservedCards2[spaceReserved]->setTargetPosition(targetPosForReservedCards2[spaceReserved]);
                                    reservedCardnumOfplayer2[spaceReserved] = 1;

                                    myGame.board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        myGame.vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        myGame.board[i][j] = myGame.vendors[vendorsNum++];
                                    }
                                    else if (i == 1) {
                                        // move deck card to board
                                        myGame.transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        myGame.board[i][j] = myGame.transport[transportNum++];
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        myGame.mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        myGame.board[i][j] = myGame.mines[minesNum++];
                                    }
                                    // command reserve
                                    myGame.cardpos[0] = i;
                                    myGame.cardpos[1] = j;
                                    myGame.command[4] = 1;  // reserve_card
                                }
                            }
                        }
                    }
                }

                // END OF EVENT

                std::cout << "Player:" << myGame.playerNum << " gems: " << myGame.dimondcolor[0] << myGame.dimondcolor[1] << myGame.dimondcolor[2] << myGame.dimondcolor[3] << myGame.dimondcolor[4] << myGame.dimondcolor[5] << '\n';
                std::cout << myGame.command[0] << myGame.command[1] << myGame.command[2] << myGame.command[3] << myGame.command[4] << '\n';
                /* get command if needed */
                for (int i = 0; i < 5; i++) {
                    if (myGame.command[i] == 1) {
                        myGame.player1_turn = !myGame.player1_turn;
                        std::cout << "Switched player \n";
                        myGame.get_command(myGame.playerNum);
                    }
                }

                // switch player if needed
                myGame.playerNum = myGame.player1_turn ? 1 : 2;

                /* cound 10 */
                // myGame.gem_cnt_over_10(myGame.playerNum); // not done


                /* win detection */
                int winner;
                if (winner = myGame.Player_Wins()) {
                    switch (winner) {
                    case 1:
                        std::cout << "Player 1 wins\n"; break;
                    case 2:
                        std::cout << "Player 2 wins\n"; break;
                    case 3:
                        std::cout << "tie\n"; break;
                    }
                    // myGame.clear_memory();
                }

            }
        }

        // move the board card to hands
        for (int i = 0; i < myGame.vendors.size(); i++) {
            myGame.vendors[i]->moveToTarget(moveSpeed);
        }

        for (int i = 0; i < myGame.transport.size(); i++) {
            myGame.transport[i]->moveToTarget(moveSpeed);
        }

        for (int i = 0; i < myGame.mines.size(); i++) {
            myGame.mines[i]->moveToTarget(moveSpeed);
        }

        window.clear();

        // draw background、deck
        window.draw(background);
        window.draw(deckVendor);
        window.draw(deckTransport);
        window.draw(deckMine);

        
        // document which player's turn
        if (myGame.playerNum == 1 && myGame.Player_Wins() == 0) {
            sf::ConvexShape arrow1(7);
            arrow1.setPoint(0, sf::Vector2f(0.f, 50.f));
            arrow1.setPoint(1, sf::Vector2f(20.f, 0.f));
            arrow1.setPoint(2, sf::Vector2f(10.f, 0.f));
            arrow1.setPoint(3, sf::Vector2f(10.f, -50.f));
            arrow1.setPoint(4, sf::Vector2f(-10.f, -50.f));
            arrow1.setPoint(5, sf::Vector2f(-10.f, 0.f));
            arrow1.setPoint(6, sf::Vector2f(-20.f, 0.f));

            arrow1.setFillColor(sf::Color::Red);
            arrow1.setPosition(sf::Vector2f(950.f, 640.f));

            window.draw(arrow1);
            
        }
        else if (myGame.playerNum == 2 && myGame.Player_Wins() == 0) {
            sf::ConvexShape arrow2(7);
            arrow2.setPoint(0, sf::Vector2f(0.f, -50.f));
            arrow2.setPoint(1, sf::Vector2f(20.f, 0.f));
            arrow2.setPoint(2, sf::Vector2f(10.f, 0.f));
            arrow2.setPoint(3, sf::Vector2f(10.f, 50.f));
            arrow2.setPoint(4, sf::Vector2f(-10.f, 50.f));
            arrow2.setPoint(5, sf::Vector2f(-10.f, 0.f));
            arrow2.setPoint(6, sf::Vector2f(-20.f, 0.f));

            arrow2.setFillColor(sf::Color::Red);
            arrow2.setPosition(sf::Vector2f(950.f, 145.f));

            window.draw(arrow2);
        }
        
        // draw diamonds
        for (int i = 0; i < 6; i++) {
            window.draw(*(diamond[i]->getShape()));
            window.draw(*(diamondPlayer1[i]->getShape()));
            window.draw(*(diamondPlayer2[i]->getShape()));
        }

        // show the number of diamonds
        // update
        for (int i = 0; i < 6; i++) {
            diamondNumBoard[i] = sf::Text(std::to_string(diamond_bank[i]), font);
            diamondNumBoard[i].setPosition(35.f, (i % 6) * 70.f + 215.f);
            diamondNumBoard[i].setCharacterSize(20);
            diamondNumBoard[i].setStyle(sf::Text::Bold);
            diamondNumBoard[i].setFillColor(sf::Color::White);
            diamondNumPlayer1[i] = sf::Text(std::to_string(myGame.players[0]->myDiamonds[i]), font);
            diamondNumPlayer1[i].setPosition((i % 6) * 50.f + 545.f, 760.f);
            diamondNumPlayer1[i].setCharacterSize(20);
            diamondNumPlayer1[i].setStyle(sf::Text::Bold);
            diamondNumPlayer1[i].setFillColor(sf::Color::White);
            diamondNumPlayer2[i] = sf::Text(std::to_string(myGame.players[1]->myDiamonds[i]), font);
            diamondNumPlayer2[i].setPosition((i % 6) * 50.f + 545.f, 66.f);
            diamondNumPlayer2[i].setCharacterSize(20);
            diamondNumPlayer2[i].setStyle(sf::Text::Bold);
            diamondNumPlayer2[i].setFillColor(sf::Color::White);
        }
        for (int i = 0; i < 6; i++) {
            window.draw(diamondNumBoard[i]);
            window.draw(diamondNumPlayer1[i]);
            window.draw(diamondNumPlayer2[i]);
        }

        // print out discount
        // update
        for (int i = 0; i < 6; i++) {
            discountPlayer1[i] = sf::Text(std::to_string(myGame.players[0]->discount[i]), font);
            discountPlayer1[i].setPosition((i % 6) * 50.f + 545.f, 712.f);
            discountPlayer1[i].setCharacterSize(20);
            discountPlayer1[i].setStyle(sf::Text::Bold);
            discountPlayer2[i] = sf::Text(std::to_string(myGame.players[1]->discount[i]), font);
            discountPlayer2[i].setPosition((i % 6) * 50.f + 545.f, 18.f);
            discountPlayer2[i].setCharacterSize(20);
            discountPlayer2[i].setStyle(sf::Text::Bold);
        }
        for (int i = 0; i < 6; i++) {
            window.draw(discountPlayer1[i]);
            window.draw(discountPlayer2[i]);
        }

        // draw card's position
        for (int i = 0; i < vendorsNum; i++) {
            window.draw(*(myGame.vendors[i]->getShape()));
        }

        for (int i = 0; i < transportNum; i++) {
            window.draw(*(myGame.transport[i]->getShape()));

        }

        for (int i = 0; i < minesNum; i++) {
            window.draw(*(myGame.mines[i]->getShape()));

        }

        // update score
        sf::Text player1Score(std::to_string(myGame.players[0]->point), font);
        player1Score.setPosition(940.f, 740.f);
        player1Score.setCharacterSize(30);
        player1Score.setStyle(sf::Text::Bold);
        player1Score.setFillColor(sf::Color::White);
        sf::Text player2Score(std::to_string(myGame.players[1]->point), font);
        player2Score.setPosition(940.f, 50.f);
        player2Score.setCharacterSize(30);
        player2Score.setStyle(sf::Text::Bold);
        player2Score.setFillColor(sf::Color::White);

        // score、discount、diamond
        window.draw(ScoreBoard1);
        window.draw(ScoreBoard2);
        window.draw(player1Score);
        window.draw(player2Score);
        window.draw(Discount1);
        window.draw(Discount2);
        window.draw(diamond1);
        window.draw(diamond2);

        // display which player win
        if (myGame.Player_Wins() == 1) {
            window.clear();
            window.draw(background);
            sf::Text win1("PLAYER 1 WIN !!!", font, 100);
            win1.setPosition(130, 300);
            win1.setFillColor(sf::Color::Black);
            window.draw(win1);
        }

        if (myGame.Player_Wins() == 2) {
            window.clear();
            window.draw(background);
            sf::Text win2("PLAYER 2 WIN !!!", font, 100);
            win2.setPosition(130, 300);
            win2.setFillColor(sf::Color::Black);
            window.draw(win2);
        }

        window.display();
    }

    return 0;
}