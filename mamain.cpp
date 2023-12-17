#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cards.h"
#include "Gem.h"

int main()
{
    // 建一個視窗畫面
    sf::RenderWindow window(sf::VideoMode(1024, 800), "SFML Tutorial", sf::Style::Close | sf::Style::Resize, sf::ContextSettings{ 0, 0, 8 });

    // 背景(大小、材質、位置)
    sf::RectangleShape background(sf::Vector2f(1024.0f, 800.0f)); 
    sf::Texture backgroundTexture;
    background.setPosition(0.f, 0.0f);
    backgroundTexture.loadFromFile("background.png");
    background.setTexture(&backgroundTexture);

    // 視窗用的牌堆
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


    // Create Gem board
    sf::Text Gem1("Gem:", font);
    Gem1.setPosition(430.f, 745.f);
    Gem1.setCharacterSize(20);
    Gem1.setStyle(sf::Text::Bold);
    Gem1.setFillColor(sf::Color::White);

    sf::Text Gem2("Gem:", font);
    Gem2.setPosition(430.f, 55.f);
    Gem2.setCharacterSize(20);
    Gem2.setStyle(sf::Text::Bold);
    Gem2.setFillColor(sf::Color::White);


    // discount position
    std::vector<sf::Text> discountPlayer1(6, sf::Text("0", font));
    std::vector<sf::Text> discountPlayer2(6, sf::Text("0", font));
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

    // 每位玩家的分數
    sf::Text player1Score("0", font);
    player1Score.setPosition(940.f, 740.f);
    player1Score.setCharacterSize(30);
    player1Score.setStyle(sf::Text::Bold);
    player1Score.setFillColor(sf::Color::White);

    sf::Text player2Score("0", font);
    player2Score.setPosition(940.f, 50.f);
    player2Score.setCharacterSize(30);
    player2Score.setStyle(sf::Text::Bold);
    player2Score.setFillColor(sf::Color::White);

    // 寶石數
    std::vector<sf::Text> GemNumBoard(6, sf::Text("4", font));
    std::vector<sf::Text> GemNumPlayer1(6, sf::Text("0", font));
    std::vector<sf::Text> GemNumPlayer2(6, sf::Text("0", font));
    for (int i = 0; i < 6; i++) {
        GemNumBoard[i].setPosition(35.f, (i % 6) * 70.f + 215.f);
        GemNumBoard[i].setCharacterSize(20);
        GemNumBoard[i].setStyle(sf::Text::Bold);
        GemNumBoard[i].setFillColor(sf::Color::White);

        GemNumPlayer1[i].setPosition((i % 6) * 50.f + 545.f, 760.f);
        GemNumPlayer1[i].setCharacterSize(20);
        GemNumPlayer1[i].setStyle(sf::Text::Bold);
        GemNumPlayer1[i].setFillColor(sf::Color::White);

        GemNumPlayer2[i].setPosition((i % 6) * 50.f + 545.f, 66.f);
        GemNumPlayer2[i].setCharacterSize(20);
        GemNumPlayer2[i].setStyle(sf::Text::Bold);
        GemNumPlayer2[i].setFillColor(sf::Color::White);
    }

    // 寶石的位置
    std::vector<Diamonds*> gem(6);
    std::vector<Diamonds*> gemPlayer1(6);
    std::vector<Diamonds*> gemPlayer2(6);
    for (int i = 0; i < 6; i++) {
        gem[i] = new Diamonds(sf::CircleShape(20.f), sf::Color::White, sf::Vector2f(50.f, (i % 6) * 70.f + 200.f));
        gemPlayer1[i] = new Diamonds(sf::CircleShape(20.f), sf::Color::White, sf::Vector2f(550.f + (i % 6) * 50.f, 730.f));
        gemPlayer2[i] = new Diamonds(sf::CircleShape(20.f), sf::Color::White, sf::Vector2f(550.f + (i % 6) * 50.f, 35.f));
    }

    // 寶石的顏色
    gem[1]->getShape()->setFillColor(sf::Color::Black);
    gem[2]->getShape()->setFillColor(sf::Color::Red);
    gem[3]->getShape()->setFillColor(sf::Color::Green);
    gem[4]->getShape()->setFillColor(sf::Color::Blue);
    gem[5]->getShape()->setFillColor(sf::Color::Yellow);

    gemPlayer1[1]->getShape()->setFillColor(sf::Color::Black);
    gemPlayer1[2]->getShape()->setFillColor(sf::Color::Red);
    gemPlayer1[3]->getShape()->setFillColor(sf::Color::Green);
    gemPlayer1[4]->getShape()->setFillColor(sf::Color::Blue);
    gemPlayer1[5]->getShape()->setFillColor(sf::Color::Yellow);

    gemPlayer2[1]->getShape()->setFillColor(sf::Color::Black);
    gemPlayer2[2]->getShape()->setFillColor(sf::Color::Red);
    gemPlayer2[3]->getShape()->setFillColor(sf::Color::Green);
    gemPlayer2[4]->getShape()->setFillColor(sf::Color::Blue);
    gemPlayer2[5]->getShape()->setFillColor(sf::Color::Yellow);
    

    // 初始化寶石
    std::vector<Cards*> vendors(20);
    std::vector<Cards*> transport(20);
    std::vector<Cards*> mines(20);
    for (int i = 0; i < 20; i++) {
        vendors[i] = new Cards(i, "vendors", sf::RectangleShape(sf::Vector2f(75.0f, 130.0f)), sf::Vector2f(200.f, 180.0f), sf::Vector2f(200.f, 180.0f));
    }

    for (int i = 0; i < 20; i++) {
        transport[i] = new Cards(i, "transport", sf::RectangleShape(sf::Vector2f(75.0f, 130.0f)), sf::Vector2f(200.f, 345.0f), sf::Vector2f(200.f, 345.0f));
    }

    for (int i = 0; i < 20; i++) {
        mines[i] = new Cards(i, "mines", sf::RectangleShape(sf::Vector2f(75.0f, 130.0f)), sf::Vector2f(200.f, 510.0f), sf::Vector2f(200.f, 510.0f));
    }

    // 記錄桌上的牌
    Cards* board[3][4];
    for (int j = 0; j < 4; j++) {
        board[0][j] = vendors[j];
        board[1][j] = transport[j];
        board[2][j] = mines[j];
    }

    // 牌桌上可以放牌的位置
    std::vector<sf::Vector2f> vendorsPosition(4);
    std::vector<sf::Vector2f> transportPosition(4);
    std::vector<sf::Vector2f> minesPosition(4);
    for (int i = 0; i < 4; i++) {
        float xPos = 350.0f + (i % 4) * 150.0f;
        float yPos = 180.0f;
        board[0][i]->setPosition(sf::Vector2f(xPos, yPos));
        board[0][i]->setTargetPosition(sf::Vector2f(xPos, yPos));
        vendorsPosition[i] = sf::Vector2f(xPos, yPos);
    }

    for (int i = 0; i < 4; i++) {
        float xPos = 350.0f + (i % 4) * 150.0f;
        float yPos = 345.0f;
        board[1][i]->setPosition(sf::Vector2f(xPos, yPos));
        board[1][i]->setTargetPosition(sf::Vector2f(xPos, yPos));
        transportPosition[i] = sf::Vector2f(xPos, yPos);
    }

    for (int i = 0; i < 4; i++) {
        float xPos = 350.0f + (i % 4) * 150.0f;
        float yPos = 510.0f;
        board[2][i]->setPosition(sf::Vector2f(xPos, yPos));
        board[2][i]->setTargetPosition(sf::Vector2f(xPos, yPos));
        minesPosition[i] = sf::Vector2f(xPos, yPos);
    }

    std::vector<Cards*> handCards1(15);
    // 玩家1手上可以放牌的位置
    std::vector<sf::Vector2f> targetPosForCard1(15);
    for (int i = 0; i < targetPosForCard1.size(); i++) {
        targetPosForCard1[i] = sf::Vector2f(30.0f + i * 95.0f, 810.0f);
    }

    std::vector<Cards*> reservedCards1(3);
    // 玩家1手上可以放預定牌的位置
    std::vector<sf::Vector2f> targetPosForReservedCards1(3);
    for (int i = 0; i < targetPosForReservedCards1.size(); i++) {
        targetPosForReservedCards1[i] = sf::Vector2f(30.0f + i * 95.0f, 660.0f);
    }

    std::vector<Cards*> handCards2(15);
    // 玩家2手上可以放牌的位置
    std::vector<sf::Vector2f> targetPosForCard2(15);
    for (int i = 0; i < targetPosForCard2.size(); i++) {
        targetPosForCard2[i] = sf::Vector2f(30.0f + i * 95.0f, -200.0f);
    }

    std::vector<Cards*> reservedCards2(3);
    // 玩家2手上可以放預定牌的位置
    std::vector<sf::Vector2f> targetPosForReservedCards2(3);
    for (int i = 0; i < targetPosForReservedCards2.size(); i++) {
        targetPosForReservedCards2[i] = sf::Vector2f(30.0f + i * 95.0f, 10.0f);
    }

    // 紀錄玩家手牌及整個牌組到第幾張
    int cardnumOfplayer1 = 0;
    int cardnumOfplayer2 = 0;
    int reservedCardnumOfplayer1 = 0;
    int reservedCardnumOfplayer2 = 0;

    int minesNum = 4;
    int vendorsNum = 4;
    int transportNum = 4;

    // 拿到甚麼顏色的寶石
    int color = 0;

    // 卡片及寶石移動速度
    float moveSpeed = 5.0f;

    // 換誰玩
    bool firstTurn = true;
    bool secondTurn = false;

    // 記錄一人一局中拿了哪幾個寶石
    int gemPerMove = 0;
    int gemPerRound[3] = {-1, -1, -1};

    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type){
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                
                while (firstTurn == true) {
                    if (evnt.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // buy card
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                    // move from board to hand
                                    handCards1[cardnumOfplayer1] = board[i][j];
                                    handCards1[cardnumOfplayer1]->setTargetPosition(targetPosForCard1[cardnumOfplayer1]);
                                    cardnumOfplayer1++;
                                    board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        board[i][j] = vendors[vendorsNum++];
                                        firstTurn = false;
                                        break;
                                    }

                                    else if (i == 1) {
                                        // move deck card to board
                                        transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        board[i][j] = transport[transportNum++];
                                        firstTurn = false;
                                        break;
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        board[i][j] = mines[minesNum++];
                                        firstTurn = false;
                                        break;
                                    }
                                }
                            }
                        }


                        if (firstTurn == false) {
                            break;
                        }

                        // buy reserved cards
                        for (int i = 0; i < reservedCardnumOfplayer1; i++) {
                            if (reservedCards1[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                handCards1[cardnumOfplayer1] = reservedCards1[i];
                                handCards1[cardnumOfplayer1]->setTargetPosition(targetPosForCard1[cardnumOfplayer1]);
                                cardnumOfplayer1++;
                                reservedCardnumOfplayer1--;
                                firstTurn = false;
                                break;
                            }
                        }

                        if (firstTurn == false) {
                            break;
                        }

                        // take gems
                        else {
                            if (gemPerMove < 3) {
                                for (int i = 0; i < 6; i++) {
                                    if (gem[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                        gemPerRound[gemPerMove++] = i;
                                        std::cout << 1 << std::endl;
                                    }
                                }
                            }

                            if (gemPerMove == 3) {
                                firstTurn = false;
                                for (int i = 0; i < 3; i++) {
                                    gemPerRound[i] = -1;
                                    gemPerMove = 0;
                                }
                            }
                            break;
                        }
                    }

                    if (firstTurn == false) {
                        break;
                    }

                    // reserve card
                    if (evnt.mouseButton.button == sf::Mouse::Right) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                    // move from board to hand
                                    reservedCards1[reservedCardnumOfplayer1] = board[i][j];
                                    reservedCards1[reservedCardnumOfplayer1]->setTargetPosition(targetPosForReservedCards1[reservedCardnumOfplayer1]);
                                    reservedCardnumOfplayer1++;
                                    board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        board[i][j] = vendors[vendorsNum++];
                                        firstTurn = false;
                                        break;
                                    }

                                    else if (i == 1) {
                                        // move deck card to board
                                        transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        board[i][j] = transport[transportNum++];
                                        firstTurn = false;
                                        break;
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        board[i][j] = mines[minesNum++];
                                        firstTurn = false;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    break;
                }

                while (firstTurn == false) {
                    if (evnt.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        // buy card
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                    // move from board to hand
                                    handCards2[cardnumOfplayer2] = board[i][j];
                                    handCards2[cardnumOfplayer2]->setTargetPosition(targetPosForCard2[cardnumOfplayer2]);
                                    cardnumOfplayer2++;
                                    board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        board[i][j] = vendors[vendorsNum++];
                                        firstTurn = true;
                                        break;
                                    }

                                    else if (i == 1) {
                                        // move deck card to board
                                        transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        board[i][j] = transport[transportNum++];
                                        firstTurn = true;
                                        break;
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        board[i][j] = mines[minesNum++];
                                        firstTurn = true;
                                        break;
                                    }
                                }
                            }
                        }

                        if (firstTurn == true) {
                            break;
                        }

                        // buy reserved cards
                        for (int i = 0; i < reservedCardnumOfplayer2; i++) {
                            if (reservedCards2[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                // move from board to hand
                                handCards2[cardnumOfplayer2] = reservedCards2[i];
                                handCards2[cardnumOfplayer2]->setTargetPosition(targetPosForCard2[cardnumOfplayer2]);
                                cardnumOfplayer2++;
                                reservedCardnumOfplayer2--;
                                firstTurn = true;
                                break;
                            }
                        }

                        if (firstTurn == true) {
                            break;
                        }
                        else {
                            if (gemPerMove < 3) {
                                for (int i = 0; i < 6; i++) {
                                    if (gem[i]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                        gemPerRound[gemPerMove++] = i;
                                        std::cout << 2 << std::endl;
                                    }
                                }
                            }

                            if (gemPerMove == 3) {
                                firstTurn = true;
                                for (int i = 0; i < 3; i++) {
                                    gemPerRound[i] = -1;
                                    gemPerMove = 0;
                                }
                            }
                            break;
                        }
                    }  

                    if (firstTurn == true) {
                        break;
                    }

                    // reserve card
                    if (evnt.mouseButton.button == sf::Mouse::Right) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (board[i][j]->getShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                                    // move from board to hand
                                    reservedCards2[reservedCardnumOfplayer2] = board[i][j];
                                    reservedCards2[reservedCardnumOfplayer2]->setTargetPosition(targetPosForReservedCards2[reservedCardnumOfplayer2]);
                                    reservedCardnumOfplayer2++;
                                    board[i][j] = NULL;

                                    if (i == 0) {
                                        // move deck card to board
                                        vendors[vendorsNum]->setTargetPosition(vendorsPosition[j]);
                                        board[i][j] = vendors[vendorsNum++];
                                        firstTurn = true;
                                        break;
                                    }

                                    else if (i == 1) {
                                        // move deck card to board
                                        transport[transportNum]->setTargetPosition(transportPosition[j]);
                                        board[i][j] = transport[transportNum++];
                                        firstTurn = true;
                                        break;
                                    }
                                    else if (i == 2) {
                                        // move deck card to board
                                        mines[minesNum]->setTargetPosition(minesPosition[j]);
                                        board[i][j] = mines[minesNum++];
                                        firstTurn = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    break;

                }
                break;
            }
        }

        // 把牌移到手上
        for (int i = 0; i < vendors.size(); i++) {
            vendors[i]->moveToTarget(moveSpeed);
        }

        for (int i = 0; i < transport.size(); i++) {
            transport[i]->moveToTarget(moveSpeed);
        }

        for (int i = 0; i < mines.size(); i++) {
            mines[i]->moveToTarget(moveSpeed);
        }

        window.clear();

        // 畫背景、牌堆
        window.draw(background);
        window.draw(deckVendor);
        window.draw(deckTransport);
        window.draw(deckMine);

        // 畫寶石
        for (int i = 0; i < 6; i++) {
            window.draw(*(gem[i]->getShape()));
            window.draw(*(gemPlayer1[i]->getShape()));
            window.draw(*(gemPlayer2[i]->getShape()));
        }
        
        // 寫出寶石個數
        for (int i = 0; i < 6; i++) {
            window.draw(GemNumBoard[i]);
            window.draw(GemNumPlayer1[i]);
            window.draw(GemNumPlayer2[i]);
        }

        // print out discount
        for (int i = 0; i < 6; i++) {
            window.draw(discountPlayer1[i]);
            window.draw(discountPlayer2[i]);
        }

        // 畫牌的位置
        for (int i = 0; i < vendorsNum; i++) {
            window.draw(*(vendors[i]->getShape()));
        }

        for (int i = 0; i < transportNum; i++) {
            window.draw(*(transport[i]->getShape()));
        }

        for (int i = 0; i < minesNum; i++) {
            window.draw(*(mines[i]->getShape()));
        }

        // 分數、discount、gem
        window.draw(ScoreBoard1);
        window.draw(ScoreBoard2);
        window.draw(player1Score);
        window.draw(player2Score);
        window.draw(Discount1);
        window.draw(Discount2);
        window.draw(Gem1);
        window.draw(Gem2);


        window.display();
    }

    return 0;
}