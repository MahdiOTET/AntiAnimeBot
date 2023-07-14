#include <iostream>
#include <tgbot/tgbot.h>

int main() 
{
    TgBot::Bot bot("6351217913:AAEIptkNU78Zz2f9IyZlTIR2ZSm_S9eFVEg");

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) 
        {
        bot.getApi().sendMessage(message->chat->id, "Hello, world!");
        });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) 
        {
        std::cout << "User wrote " << message->text << std::endl;
        });

    try {
        std::cout << "Bot username: " << bot.getApi().getMe()->username << std::endl;
        TgBot::TgLongPoll longPoll(bot);
        while (true) 
        {
            std::cout << "Long poll started" << std::endl;
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) 
    {
        std::cerr << "error: " << e.what() << std::endl;
    }
    system("pause");
    return 0;
}