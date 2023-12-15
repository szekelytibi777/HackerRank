
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <unistd.h>
#include <future>

using namespace std;

class Message{
    friend bool operator<(const Message&, const Message&);
    private:
        string text;
        int id;
    public:

        Message(const string &t = "")
        : text(t)
        {
            static int ID = 0;
            id = ID++;
        }

        int getID() const{
            return id;
        }

        const string& get_text(){
            return text;
        }

        void print() const{
            cout << text << endl;
        }
};

bool pComp(const Message& a, const Message& b);

class Recipient{
    private:
        vector<Message> messages;
    public:
        Recipient()
        {
        }

        void receive(const Message& message){
            messages.push_back(message);
        }

        void print_messages()
        {
            fix_order();
            for (auto& msg : messages)
            {
                cout << msg.get_text() << endl;
            }
            messages.clear();
        }

        void fix_order(){
            sort(messages.begin(), messages.end(), pComp);
        }
};

class Network{
    public:
        static void send_messages(vector<Message> messages, Recipient& recipient)
        {
            random_shuffle(messages.begin(), messages.end());
            for (auto msg : messages)
            {
                recipient.receive(msg);
            }
        }
};


bool operator<(const Message& lhs, const Message& rhs)
{
    return lhs.getID() < rhs.getID();
}

bool pComp(const Message& a, const Message& b) 
{ 
    return a < b; 
}

class MessageFactory{
    public:
        Message create_message(const string& text){
            return Message(text);
        }
};

  

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    MessageFactory message_factory;
    Network network;
    Recipient recipient;
    vector<Message>messages;
    string text;
    auto read_input = [&]() {
        string input;
        getline(cin, input);
        return input;
    };
    future<string> future_input;
    std::chrono::system_clock::time_point seconds_passed = std::chrono::system_clock::now() + std::chrono::seconds(1);
    while (1) {
        if (!future_input.valid())
            future_input = async(read_input);
        
        auto res = future_input.wait_until(seconds_passed);

        if (res == future_status::ready) {

            std::string s = future_input.get();
            messages.push_back(message_factory.create_message(s));
        }
        else if(res == future_status::timeout)
            break;
    }


    Network::send_messages(messages, recipient);
    recipient.print_messages();
    exit(0);
}
