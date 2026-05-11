#include <iostream>
using namespace std;


class AbstractClass {
protected:
    string sender;
    string receiver;

public:
    AbstractClass() {
        sender = "";
        receiver = "";
    }

    AbstractClass(string sender, string receiver) {
        this->sender = sender;
        this->receiver = receiver;
    }

    virtual ~AbstractClass() {}

    string getSender() { return sender; }
    string getReceiver() { return receiver; }

    void setSender(string sender) { this->sender = sender; }
    void setReceiver(string receiver) { this->receiver = receiver; }

    virtual void printInfo() = 0;
};


class Message : public AbstractClass {
protected:
    string content;

public:
    Message() : AbstractClass() {
        content = "";
    }

    Message(string sender, string receiver, string content)
        : AbstractClass(sender, receiver) {
        this->content = content;
    }

    string getContent() { return content; }
    void setContent(string content) { this->content = content; }

    virtual void printInfo() {
        cout << "Message from " << sender << " to " << receiver
            << " | Content: " << content << endl;
    }
};




class Email : public Message {
protected:
    string subject;

public:
    Email() : Message() {
        subject = "";
    }

    Email(string sender, string receiver, string content, string subject)
        : Message(sender, receiver, content) {
        this->subject = subject;
    }

    void printInfo() {
        cout << "Email | Subject: " << subject << endl;
        Message::printInfo();
    }
};


class SMS : public Message {
protected:
    int length;

public:
    SMS() : Message() {
        length = 0;
    }

    SMS(string sender, string receiver, string content, int length)
        : Message(sender, receiver, content) {
        this->length = length;
    }

    void printInfo() {
        cout << "SMS | Length: " << length << endl;
        Message::printInfo();
    }
};



class PersonalEmail : public Email {
private:
    string nickname;

public:
    PersonalEmail(string sender, string receiver, string content,
        string subject, string nickname)
        : Email(sender, receiver, content, subject) {
        this->nickname = nickname;
    }

    void printInfo() {
        cout << "Personal Email | Nickname: " << nickname << endl;
        Email::printInfo();
    }
};


class MMS : public SMS {
private:
    string media;

public:
    MMS(string sender, string receiver, string content,
        int length, string media)
        : SMS(sender, receiver, content, length) {
        this->media = media;
    }

    void printInfo() {
        cout << "MMS | Media: " << media << endl;
        SMS::printInfo();
    }
};


int main() {
    AbstractClass* arr[2];

    arr[0] = new PersonalEmail("Ivan", "Petar", "Hello!", "Meeting", "Ivo");
    arr[1] = new MMS("Gosho", "Maria", "Picture message", 120, "image.jpg");

    for (int i = 0; i < 2; i++) {
        arr[i]->printInfo();
        cout << "---------------------" << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete arr[i];
    }

    return 0;
}